#!/bin/bash

CURDIR=$(readlink -f `pwd`)

### BUILD LIBRARY ###
cd $HOME/local/src/libmystring
bash build_libmystrtok.sh

if [ $? != 0 ]
then
  echo
  echo "Abort build and test"
  exit
fi

echo

DIRS=("memcpy" "memset" "strcmp" "strtok" "chk_gcc_flags")

FAULTS=0

for DIR in ${DIRS[*]}
do
  cd $CURDIR/$DIR

  ### CHECK DIRECTORY ###
  if [ ! -s main.c ]
  then
    echo "There is not main.c file in $DIR, skipping test"
    echo
    continue
  fi
  
  ### WITH STANDARD LIBRARY ###

  ### BUILD TEST PROGRAM ###
  echo "Building $DIR w/ standard library"

  [ -s a.out ] && rm a.out
  CMD="gcc-4.4 -Wall -static -O2 main.c"
  echo $CMD
  eval $CMD

  if [ $? != 0 ]
  then
    echo "Failure, skipping test"
    FAULTS=$((FAULTS + 1))
    continue
  else
    echo "OK"
  fi
  echo

  ### RUN TEST PROGRAM ###
  echo "Running $DIR w/ standard library"
  echo "==="

  ./a.out
  RES=$?

  echo "==="
  if [ $RES != 0 ]
  then
    echo "TEST FAILURE"
    FAULTS=$((FAULTS + 1))
  else
    echo "TEST OK"
  fi
  echo

  ### WITH MYSTRING LIBRARY ###

  ### BUILD TEST PROGRAM ###
  echo "Building $DIR w/ mystring library"

  [ -s a.out ] && rm a.out
  CMD="gcc-4.4 -Wall -I$HOME/local/src/libmystring -L$HOME/local/src/libmystring -static -O2 main.c -lmystrtok"
  echo $CMD
  eval $CMD

  if [ $? != 0 ]
  then
    echo "Failure, skipping test"
    FAULTS=$((FAULTS + 1))
    continue
  else
    echo "OK"
  fi
  echo

  ### RUN TEST PROGRAM ###
  echo "Running $DIR w/ mystring library"
  echo "==="

  ./a.out
  RES=$?

  echo "==="
  if [ $RES != 0 ]
  then
    echo "TEST FAILURE"
    FAULTS=$((FAULTS + 1))
  else
    echo "TEST OK"
  fi
  echo
done

if [ $FAULTS = 0 ]
then
  echo "Test succeeded."
elif [ $FAULTS = 1 ]
then
  echo "There is 1 failure."
else
  echo "There are $FAULTS failures"
fi

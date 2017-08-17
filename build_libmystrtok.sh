#!/bin/bash

echo "Building libmystring"

echo -n "Compiling mystring.c ..."

gcc-4.4 -O2 -c mystring.c -o mystring.o

if [ $? != 0 ]
then
  echo "NG"
  exit 1
else
  echo "OK"
fi

echo -n "Creating library..."
ar rcs libmystring.a mystring.o

if [ $? != 0 ]
then
  echo "NG"
  exit
else
  echo "OK"
fi


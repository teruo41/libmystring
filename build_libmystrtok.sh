#!/bin/bash

echo "Building libmystrtok"

echo -n "Compiling mystrtok.c ..."

gcc-4.4 -O2 -c mystrtok.c -o mystrtok.o

if [ $? != 0 ]
then
  echo "NG"
  exit 1
else
  echo "OK"
fi

echo -n "Creating library..."
ar rcs libmystrtok.a mystrtok.o

if [ $? != 0 ]
then
  echo "NG"
  exit
else
  echo "OK"
fi


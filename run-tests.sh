#!/bin/bash

for f in test/*; do
  echo "Running tests for $f"
  g++ "$f" -l gtest -o ./run-test.out -lm -I headers/  -pthread || exit 1
  ./run-test.out || exit 1
done
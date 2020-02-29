#!/bin/bash

TOTAL_MS=0
for f in test/*; do
  echo "Running tests for $f"
  g++ "$f" -l gtest -o ./run-test.out -lm -I headers/  -pthread || exit 1
  TEST_RESULT=$(./run-test.out || exit 1)
  echo "$TEST_RESULT"
  MS=$(echo "$TEST_RESULT" | grep "case ran." | awk '{print $9}')
  MS="${MS:1}"
  TOTAL_MS=$((TOTAL_MS + MS))
done

echo "TOTAL_MS=$TOTAL_MS ms"
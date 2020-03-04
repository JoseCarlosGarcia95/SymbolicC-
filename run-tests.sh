#!/bin/bash

TOTAL_MS=0
for f in test/*; do
  echo "Running tests for $f"
  g++ "$f" -l gtest -o ./run-test.out -lm -I include/  -pthread -lgmpxx -lgmp || exit 1
  TEST_RESULT=$(./run-test.out || exit 1)
  MS=$(echo "$TEST_RESULT" | grep "case ran." | awk '{print $9}')
  MS="${MS:1}"
  TOTAL_MS=$((TOTAL_MS + MS))

  valgrind --error-exitcode=1 --leak-check=full ./run-test.out || exit 1
done

echo "TOTAL_MS=$TOTAL_MS ms"
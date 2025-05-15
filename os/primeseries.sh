#!/bin/bash
n=2
while ((n <= 100)); do
  flag=0
  for ((i = 2; i * i <= n; i++)); do
    if ((n % i == 0)); then
      flag=1
      break
    fi
  done
  if ((flag == 0)); then
    echo -n "$n "
  fi
  n=$((n + 1))
done

# Print a newline for better output
echo

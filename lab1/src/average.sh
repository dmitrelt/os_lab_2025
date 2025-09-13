#!/bin/bash

count=0
sum=0

for number in "$@"; do
    sum=$((sum + number))
    count=$((count + 1))
done

average=$($sum / $count" | bc)

echo "Количество чисел: $count"
echo "Сумма чисел: $sum"
echo "Среднее арифметическое: $average"
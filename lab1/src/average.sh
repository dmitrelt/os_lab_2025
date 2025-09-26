#!/bin/bash

if [ $# -eq 0 ]; then
    echo "Укажите аргументы!"
    exit 1
fi

count=$#
sum=0

for number in "$@"; do
    sum=$((sum + number))
done

average=$(echo "scale=2; $sum / $count" | bc)

echo "Количество чисел: $count"
echo "Сумма чисел: $sum"
echo "Среднее арифметическое: $average"
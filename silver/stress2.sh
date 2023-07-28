#!/usr/bin/env sh

for ((i = 1; i <= 1000; i++)); do
	echo $i
	./gen $i > test.in
	diff -w <(./A < test.in) <(./B < test.in) || break
done

#!/usr/bin/env sh

for ((i = 1; i <= 1000; i++)); do
	echo $i
	./gen $i > art.in
	./A
	./B
	diff -w art.out art2.out || break
done

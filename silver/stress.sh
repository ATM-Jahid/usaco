#!/usr/bin/env sh

for ((i = 1; i <= 1000; i++)); do
	echo $i
	./gen $i > paintbarn.in
	./A
	./B
	diff -w paintbarn.out paintbarn2.out || break
done

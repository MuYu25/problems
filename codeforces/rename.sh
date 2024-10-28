#!/bin/bash

for file in cf*.cpp
do
	mv "$file" "${file#cf}"
done

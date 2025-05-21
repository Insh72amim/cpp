#!/bin/bash

echo 'Enter file name : '

read -r filename

echo "------------------"

g++ -std=c++11 -o out/"$filename".out "$filename".cpp && out/"$filename".out

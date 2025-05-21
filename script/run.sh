#!/bin/bash

#read -r location
read -r filename

g++ -std=c++11 -o out/"$filename".out "now"/"$filename".cpp && out/"$filename".out

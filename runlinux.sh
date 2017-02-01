#!/bin/bash
python mapgen.py
g++ generator.cpp -o generator.out -std=c++11
./generator.out
#!/bin/bash
#format:
#first is the number of iterations (00-99)
#followed by number is num of gates (00-99)
#followed by the number of wires(00-99)
#followed by the gate definitions (inwrie1 inwire2 type outwire)
# type is 1 and 2 not 3 or 4 xor (note that inwire2 is ignored for not)
#after this is the initial state of all 10 wires
cc -lm g.c -o g && echo "06 01 10 0140 1100000000" | ./g

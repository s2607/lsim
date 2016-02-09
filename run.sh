#!/bin/bash
#format:
#first number is num of gates (0-9)
#followed by the gate definitions (inwrie1 inwire2 type outwire)
# type is 1 and 2 not 3 or 4 xor (note that inwire2 is ignored for not)
#after this is the initial state of all 10 wires
cc g.c -o g && echo "101401100000000" | ./g

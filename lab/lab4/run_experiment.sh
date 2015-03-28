#!/bin/bash

# Lab4: LOSS=0, CORRUPT=0
SPEED=4
DELAY=125
LOSS=0
CORRUPT=0
#BDP - to be modified when implementing sliding window
BDP=500

killall link 2> /dev/null
killall recv 2> /dev/null
killall send 2> /dev/null

./link_emulator/link speed=$SPEED delay=$DELAY loss=$LOSS corrupt=$CORRUPT &> /dev/null &
sleep 1
./recv &
sleep 1

./send $BDP

#!/bin/bash

gcc ./src/board/list.c ./src/board/room.c ./src/main.c -o gamefile

chmod +x gamefile

./gamefile

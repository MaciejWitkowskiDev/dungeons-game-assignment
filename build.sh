#!/bin/bash

gcc ./src/board/list.c ./src/board/room.c ./src/board/board.c ./src/board/traverser.c ./src/main.c -o gamefile

chmod +x gamefile

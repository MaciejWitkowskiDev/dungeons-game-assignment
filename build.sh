#!/bin/bash

gcc ./src/board/list.c ./src/board/room.c ./src/board/board.c ./src/board/traverser.c ./src/player/player.c ./src/storyteller/storyteller.c ./src/storyteller/textheaders.c ./src/utils/clear.c ./src/utils/prettyprint.c ./src/utils/ui.c ./src/utils/filehandler.c ./src/game/game.c  ./src/main.c -o gamefile

chmod +x gamefile

#include <stdio.h>
#include <stdlib.h>  // for system()
#include <conio.h>   // for getch()

#define ROWS 9
#define COLS 15

char maze[ROWS][COLS + 1] = {
    "##############",
    "#P   #       E",
    "# ## # ##### #",
    "#    #     # #",
    "#### ### # # #",
    "#        #   #",
    "# #### # #####",
    "#      #     #",
    "##############"
};

int playerRow = 1;
int playerCol = 1;

void printMaze() {
    system("cls");  // clear screen on Windows
    for (int i = 0; i < ROWS; i++) {
        printf("%s\n", maze[i]);
    }
}

int main() {
    printMaze();

    while (1) {
        char move = getch();
        int newR = playerRow;
        int newC = playerCol;

        if (move == 'w' || move == 'W') newR--;
        if (move == 's' || move == 'S') newR++;
        if (move == 'a' || move == 'A') newC--;
        if (move == 'd' || move == 'D') newC++;

        // Check if move is inside maze and not a wall
        if (newR >= 0 && newR < ROWS && newC >= 0 && newC < COLS
            && maze[newR][newC] != '#') {

            // If next position is the exit 'E'
            if (maze[newR][newC] == 'E') {
                // Move player there and win
                maze[playerRow][playerCol] = ' ';
                playerRow = newR;
                playerCol = newC;
                maze[playerRow][playerCol] = 'P';

                printMaze();
                printf("\n🎉 You reached the exit! Congrats!\n");
                break;
            }

            // Otherwise, a normal open space — update player position
            maze[playerRow][playerCol] = ' ';
            playerRow = newR;
            playerCol = newC;
            maze[playerRow][playerCol] = 'P';
        }

        printMaze();
    }

    return 0;
}

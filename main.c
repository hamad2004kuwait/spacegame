#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define SIZE 18
#define MAX_ITEMS 3
#define MAX_FUEL 15
// Player info
struct Player {
    int row;
    int col;
    int fuel;
    int items;
};

char map[SIZE][SIZE];
struct Player player;

// Set all map cells to empty
void clearMap() {
    for (int r = 0; r < SIZE; r++)
        for (int c = 0; c < SIZE; c++)
            map[r][c] = '.';
}
// Place random asteroids
void placeAsteroids(int count) {
    int placed = 0;
    while (placed < count) {
        int r = rand() % SIZE;
        int c = rand() % SIZE;
        if (map[r][c] == '.') {
            map[r][c] = 'X';
            placed++;
        }
    }
}
// Place fixed resources
void placeResources() {
    map[3][4] = 'R';
    map[5][6] = 'R';
    map[7][8] = 'R';
}
// Setup game
void setup() {
    srand(time(NULL)); // random seed

    clearMap();

    placeAsteroids(3);
    placeResources();
    player.row = 0;
    player.col = 0;
    player.fuel = MAX_FUEL;
    player.items = 0;
    map[player.row][player.col] = 'P';
}
// Print the map
void printMap() {
    for (int r = 0; r < SIZE; r++) {
        for (int c = 0; c < SIZE; c++)
            printf("%c ", map[r][c]);
        printf("\n");
    }
    printf("Fuel: %d | Items: %d\n", player.fuel, player.items);
    if (player.fuel <= 3) printf("Low fuel!\n");
}
// Move player based on input
void movePlayer(char move) {
    int r = player.row;
    int c = player.col;

    if (move == 'w') r--;
    if (move == 's') r++;
    if (move == 'a') c--;
    if (move == 'd') c++;

    if (r < 0 || r >= SIZE || c < 0 || c >= SIZE) {
        printf("Can't move there!!!!!!!!\n");
        return;
    }
    if (map[r][c] == 'X') {
        printf("You hit an asteroid gg!.\n");
        exit(0);
    }
    if (map[r][c] == 'R') {
        player.items++;
        player.fuel++;
        printf("You got a resource!\n");
    }

    map[player.row][player.col] = '.';
    player.row = r;
    player.col = c;
    map[r][c] = 'P';
    player.fuel--;
}
// Main loop
int main() {
    setup();
    while (1) {
        printMap();
        if (player.fuel <= 0) {
            printf("You're out of fuel gg!\n");
            break;
        }
        if (player.items >= MAX_ITEMS) {
            printf("Collected All Resources!\n");
            break;
        }
        printf("Move (W/A/S/D): ");
        char input;
        scanf(" %c", &input);
        movePlayer(input);
    }

    return 0;
}
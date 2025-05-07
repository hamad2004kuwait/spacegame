#ifndef GAME_H
#define GAME_H

// Define game constants
#define SIZE 18
#define MAX_ITEMS 3
#define MAX_FUEL 15

// Creating player
typedef struct {
    int row;
    int col;
    int fuel;
    int items;
} Player;

// Define map and player
extern char map[SIZE][SIZE];
extern Player player;

// Define functions
void clearMap();
void placeAsteroids(int count);
void placeResources();
void setup();
void printMap();
void movePlayer(char move);

#endif // GAME_H
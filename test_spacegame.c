#include <assert.h>
#include <stdio.h>
#include "game.h"

void test_clearMap() {
    clearMap();
    for (int r = 0; r < SIZE; r++) {
        for (int c = 0; c < SIZE; c++) {
            assert(map[r][c] == '.');
        }
    }
    printf("clearMap() test passed.\n");
}

void test_placeAsteroids() {
    clearMap();
    placeAsteroids(5);
    int asteroidCount = 0;
    for (int r = 0; r < SIZE; r++)
        for (int c = 0; c < SIZE; c++)
            if (map[r][c] == 'X') asteroidCount++;

    assert(asteroidCount == 5); // may fail if same spot used more than once
    printf("placeAsteroids() test passed.\n");
}

void test_movePlayer_valid() {
    clearMap();
    player.row = 5;
    player.col = 5;
    player.fuel = 10;
    map[player.row][player.col] = 'P';

    movePlayer('d'); // move right

    assert(player.col == 6);
    assert(player.fuel == 9);
    printf("movePlayer('d') test passed.\n");
}

void test_movePlayer_invalid() {
    clearMap();
    player.row = 0;
    player.col = 0;
    player.fuel = 5;
    map[player.row][player.col] = 'P';

    movePlayer('a'); // invalid: out of bounds

    assert(player.col == 0); // position unchanged
    assert(player.fuel == 5); // fuel unchanged
    printf("movePlayer('a') invalid test passed.\n");
}

int main() {
    test_clearMap();
    test_placeAsteroids();
    test_movePlayer_valid();
    test_movePlayer_invalid();
    printf("All unit tests completed.\n");
    return 0;
}


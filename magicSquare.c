#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

#define SIZE 3

// Function to print the generated square
void printMagicSquare(int square[SIZE][SIZE]) {
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            printf("[%d] ", square[i][j]);
        }
        printf("\n");
    }
}

// Function to check if the square is a Lo Shu Magic Square
bool isMagicSquare(int square[SIZE][SIZE]) {
    int sums[SIZE * 2 + 2] = {0};

    // Calculate row and column sums
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            sums[i] += square[i][j];
            sums[j + SIZE] += square[i][j];
        }
    }

    // Calculate diagonal sums
    for (int i = 0; i < SIZE; i++) {
        sums[2 * SIZE] += square[i][i];
        sums[2 * SIZE + 1] += square[i][SIZE - i - 1];
    }

    // Check if all sums are equal to 15
    for (int i = 0; i < SIZE * 2 + 2; i++) {
        if (sums[i] != 15) {
            return false;
        }
    }

    return true;
}

int main() {
    int square[SIZE][SIZE];
    int count = 0;


    // Keep generating squares until a Lo Shu Magic Square is found
    do {
        int numbers[SIZE * SIZE] = {0};

        // Populate the array with random non-repeating numbers from 1 to 9
        for (int i = 0; i < SIZE * SIZE; i++) {
            int num;
            do {
                num = rand() % 9 + 1;
            } while (numbers[num - 1] != 0);
            numbers[num - 1] = 1;
            square[i / SIZE][i % SIZE] = num;
        }

        count++;

    } while (!isMagicSquare(square));

    
    printf("Lo Shu Magic Square found after %d attempts:\n", count);
    printMagicSquare(square);


    int square2[SIZE][SIZE] = {{4, 9, 2}, {3, 5, 7}, {8, 1, 6}};

    printf("The square:\n");
    printMagicSquare(square2);

    if (isMagicSquare(square2)) {
        printf("The square is a Lo Shu Magic Square.\n");
    } else {
        printf("The square is not a Lo Shu Magic Square.\n");
    }

    return 0;

    srand(time(NULL));
}
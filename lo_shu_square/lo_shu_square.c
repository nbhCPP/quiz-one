#include <stdio.h>
#include <stdbool.h>
#include <time.h>

bool is_magic(int square[3][3]) {
    int magic = true;
    
    for (int i = 0; i < 3; i++) {
        int row_sum = 0;
        int column_sum = 0;
        for (int j = 0; j < 3; j++) {
            row_sum += square[i][j];
            column_sum += square[j][i];
        }
        int diag_sum1 = square[0][0] + square[1][1] + square[2][2];
        int diag_sum2 = square[0][2] + square[1][1] + square[2][0];

        if (row_sum != 15 || column_sum != 15 || diag_sum1 != 15 || diag_sum2 != 15) {
            magic = false;
        }
    }

    return magic;
}

void print_array(int square[3][3]) {
    for (int i = 0; i < 3; i++) {
        printf("[");
        for (int j = 0; j < 3; j++) {
            printf("%d", square[i][j]);
            if (j != 2) 
                printf(" ");
        }
        printf("]\n");
        
    }
}

int main() {
    srand(time(NULL));
    int test[3][3] = {{0, 0, 0}, {0, 0, 0}, {0, 0, 0}};
    int numbers[9] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    int num_squares = 0;
    while (is_magic(test) == false) {
        num_squares++;
        int nums_left = 9;
        for (int i = 0; i < 9; i++) {
            numbers[i] = i + 1;
        }
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                int rand_index = rand() % nums_left;
                int rand_num = numbers[rand_index];
                numbers[rand_index] = numbers[nums_left - 1];
                nums_left--;
                test[i][j] = rand_num;
            }
        }
    }
    print_array(test);
    printf("It took ");
    printf("%d", num_squares);
    printf(" tries to get this successful square.");
    return 0;
}
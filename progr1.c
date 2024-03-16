#include <stdio.h>
#include <stdbool.h>

// Function to calculate the power given a base and an exponent
int power(int base, int exponent) {
    int result = 1;
    for (int i = 0; i < exponent; i++) {
        result *= base;
    }
    return result;
}

// Function to convert a character representing a digit to its corresponding numerical value
int charToDigit(char c) {
    return c - '0';
}

// Function to determine if a given matrix is an Embedia Power Matrix
bool isEmbediaPowerMatrix(char matrix[3][3]) {
    for (int i = 1; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            int base = charToDigit(matrix[i - 1][j]);
            int exponent = charToDigit(matrix[i][j]);
            if (power(base, exponent) != charToDigit(matrix[i][j])) {
                return false;
            }
        }
    }
    return true;
}

// Main function to test the functionalities
int main() {
    // Test Case 1
    char matrix1[3][3] = {
        {'3', '2', '2'},
        {'8', '9', '25'},
        {'2', '3', '5'}
    };
    printf("Test Case 1: %s\n", isEmbediaPowerMatrix(matrix1) ? "Embedia Power Matrix" : "Not an Embedia Power Matrix");

    // Test Case 2
    char matrix2[3][3] = {
        {'1', '3', '5'},
        {'3', '7', '11'},
        {'5', '11', '17'}
    };
    printf("Test Case 2: %s\n", isEmbediaPowerMatrix(matrix2) ? "Embedia Power Matrix" : "Not an Embedia Power Matrix");

    // Test Case 3
    char matrix3[3][3] = {
        {'3', '4', '2'},
        {'5', '3', '7'},
        {'8', '4', '7'}
    };
    printf("Test Case 3: %s\n", isEmbediaPowerMatrix(matrix3) ? "Embedia Power Matrix" : "Not an Embedia Power Matrix");

    return 0;
}

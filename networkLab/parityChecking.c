#include <stdio.h>
#include <string.h>

int main() {
    char data[100];
    int i, count = 0;
    char parityType;

    // Input binary data
    printf("Enter the binary data (e.g., 1010101): ");
    scanf("%s", data);

    // Ask for parity type
    printf("Enter parity type (E for Even / O for Odd): ");
    scanf(" %c", &parityType);

    // Count number of 1s
    for (i = 0; i < strlen(data); i++) {
        if (data[i] == '1')
            count++;
    }

    // Calculate and display parity bit
    if (parityType == 'E' || parityType == 'e') {
        if (count % 2 == 0)
            printf("Even parity bit: 0 (Already even)\n");
        else
            printf("Even parity bit: 1 (To make even)\n");
    }
    else if (parityType == 'O' || parityType == 'o') {
        if (count % 2 == 0)
            printf("Odd parity bit: 1 (To make odd)\n");
        else
            printf("Odd parity bit: 0 (Already odd)\n");
    }
    else {
        printf("Invalid parity type entered!\n");
    }

    return 0;
}
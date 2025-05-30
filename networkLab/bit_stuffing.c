#include <stdio.h>
#include <string.h>

#define MAX 100

void bitStuffing(char input[], char output[]) {
    int i, j = 0, count = 0;

    for (i = 0; input[i] != '\0'; i++) {
        output[j++] = input[i];

        if (input[i] == '1') {
            count++;
            if (count == 5) {
                output[j++] = '0';  // Stuff a 0
                count = 0;
            }
        } else {
            count = 0;
        }
    }
    output[j] = '\0';  // Null terminate the output
}

int main() {
    char input[MAX], output[MAX * 2];

    printf("Enter the binary data stream (e.g., 01111110111110): ");
    scanf("%s", input);

    bitStuffing(input, output);

    printf("After Bit Stuffing: %s\n", output);

    return 0;
}
#include <stdio.h>

void reverseString(char str[]) {
    int length = 0, i;
    char temp;

    // Calculate the length of the string
    while (str[length] != '\0') {
        length++;
    }

    // Reverse the string by swapping characters
    for (i = 0; i < length / 2; i++) {
        temp = str[i];
        str[i] = str[length - i - 1];
        str[length - i - 1] = temp;
    }
}

int main() {
    char str[100];

    // Input the string
    printf("Enter a string: ");
    scanf("%s", str);

    // Reverse the string
    reverseString(str);

    // Print the reversed string
    printf("Reversed string: %s\n", str);

    return 0;
}

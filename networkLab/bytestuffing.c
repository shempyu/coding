#include <stdio.h>
#include <string.h>

#define MAX 100

int main() {
    char data[MAX], stuffed[MAX];
    char flag[] = "F";       // Frame delimiter
    char esc[] = "E";        // Escape character
    int i, j = 0;

    printf("Enter the data to send (no spaces): ");
    scanf("%s", data);

    // Add starting flag
    strcpy(stuffed, flag);
    j = strlen(stuffed);

    for (i = 0; i < strlen(data); i++) {
        if (data[i] == 'F' || data[i] == 'E') {
            // If data contains flag or escape character, stuff with escape
            stuffed[j++] = 'E';
        }
        stuffed[j++] = data[i];
    }

    // Add ending flag
    stuffed[j++] = 'F';
    stuffed[j] = '\0';

    printf("Stuffed data to be sent: %s\n", stuffed);

    return 0;
}
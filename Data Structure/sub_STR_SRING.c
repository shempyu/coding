#include <stdio.h>
#include <string.h>

// Function to find a substring in a string
int findSubstring(const char *string, const char *substring) {
    int stringLen = strlen(string);
    int substringLen = strlen(substring);

    // Loop through the main string
    for (int i = 0; i <= stringLen - substringLen; i++) {
        int j;

        // Check for substring match
        for (j = 0; j < substringLen; j++) {
            if (string[i+j] != substring[j]) {
                break;
            }
        }

        // If all characters matched, return the starting index
        if (j == substringLen) {
            return i;
        }
    }

    // If no match found, return -1
    return -1;
}

int main() {
    char string[100], substring[50];

    // Input the main string
    printf("Enter the main string: ");
    fgets(string, sizeof(string), stdin);
    string[strcspn(string, "\n")] = '\0'; // Remove newline character

    // Input the substring
    printf("Enter the substring: ");
    fgets(substring, sizeof(substring), stdin);
    substring[strcspn(substring, "\n")] = '\0'; // Remove newline character

    // Find the substring
    int index = findSubstring(string, substring);

    if (index != -1) {
        printf("Substring found at index: %d\n", index);
    } else {
        printf("Substring not found.\n");
    }

    return 0;
}

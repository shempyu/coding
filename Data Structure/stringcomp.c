#include <stdio.h>
#include <string.h>

int compare_char_arrays(const char *arr1, const char *arr2) {
    int len1 = strlen(arr1);
    int len2 = strlen(arr2);
    int diff_count = 0;

    // Find the minimum length between the two arrays
    int min_len = len1 < len2 ? len1 : len2;
    int max_len = len1 > len2 ? len1 : len2;

    // Compare character by character up to the minimum length
    for (int i = 0; i < min_len; i++) {
        if (arr1[i] != arr2[i]) {
            diff_count++;
        }
    }

    // Add remaining characters from the longer array to the difference count
    diff_count = diff_count + max_len - min_len;

    return diff_count;
}

int main() {
    char arr1[100], arr2[100];

    printf("Enter the first character array: ");
    scanf("%s", arr1);

    printf("Enter the second character array: ");
    scanf("%s", arr2);

    int result = compare_char_arrays(arr1, arr2);

    if (result == 0) {
        printf("0\n"); // Arrays are equivalent
    } else {
        printf("Differing characters count: %d\n", result); // Arrays are not equivalent
    }

    return 0;
}

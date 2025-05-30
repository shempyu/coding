#include <stdio.h>
#include <string.h>
#define MAX 50

void rev(char *s) {
    for (int i = 0, j = strlen(s)-1; i < j; i++, j--)
        s[i] ^= s[j] ^= s[i] ^= s[j];
}

int redBits(int m) {
    int r = 0;
    while ((1 << r) < m + r + 1) r++;
    return r;
}

int main() {
    char d[MAX], h[MAX] = {0};
    printf("Enter binary data: ");
    scanf("%s", d);
    rev(d);

    int m = strlen(d), r = redBits(m), t = m + r, j = 0;
    for (int i = 1; i <= t; i++)
        h[i] = ((i & (i - 1)) == 0) ? '0' : d[j++];

    for (int i = 0; i < r; i++) {
        int p = 1 << i, c = 0;
        for (int k = 1; k <= t; k++) if (k & p && h[k] == '1') c++;
        h[p] = (c % 2) + '0';
    }

    printf("Hamming Code: ");
    for (int i = t; i >= 1; i--) putchar(h[i]);
    printf("\n");
    return 0;
}
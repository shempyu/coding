#include <stdio.h>
#include <string.h>

#define MAX 100

void xorOperation(char *dividend, char *divisor, int n) {
    for (int i = 1; i < strlen(divisor); i++) {
        dividend[i] = (dividend[i] == divisor[i]) ? '0' : '1';
    }
}

void crc(char data[], char generator[], char codeword[]) {
    int dataLen = strlen(data);
    int genLen = strlen(generator);

    // Append n-1 zeros to data (where n = length of generator)
    char temp[MAX], remainder[MAX];
    strcpy(temp, data);
    for (int i = 0; i < genLen - 1; i++) {
        strcat(temp, "0");
    }

    strncpy(remainder, temp, genLen);

    for (int i = 0; i < dataLen; i++) {
        if (remainder[0] == '1')
            xorOperation(remainder, generator, genLen);

        // Shift left and add next bit
        for (int j = 0; j < genLen - 1; j++) {
            remainder[j] = remainder[j + 1];
        }
        remainder[genLen - 1] = temp[i + genLen];
    }

    // Final remainder is the CRC
    remainder[genLen - 1] = '\0';

    // Append CRC to original data
    strcpy(codeword, data);
    strcat(codeword, remainder);
}

int main() {
    char data[MAX], generator[MAX], codeword[MAX];

    printf("Enter data bits: ");
    scanf("%s", data);

    printf("Enter generator polynomial: ");
    scanf("%s", generator);

    crc(data, generator, codeword);

    printf("Transmitted Codeword (Data + CRC): %s\n", codeword);

    return 0;
}
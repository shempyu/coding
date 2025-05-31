#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX 20

char productions[MAX][MAX];
char nonTerminals[MAX], terminals[MAX];
char first[MAX][MAX], follow[MAX][MAX], table[MAX][MAX][MAX];
int prodCount = 0, ntCount = 0, tCount = 0;

int isTerminal(char c) {
    return !isupper(c) && c != '#';
}

int indexOf(char c, char arr[], int count) {
    for (int i = 0; i < count; i++)
        if (arr[i] == c)
            return i;
    return -1;
}

void addToSet(char set[], char val) {
    if (!strchr(set, val)) {
        int len = strlen(set);
        set[len] = val;
        set[len + 1] = '\0';
    }
}

void computeFirst(char symbol, char result[]) {
    for (int i = 0; i < prodCount; i++) {
        if (productions[i][0] == symbol) {
            int k = 3;
            if (productions[i][k] == '#') {
                addToSet(result, '#');
            } else {
                while (productions[i][k]) {
                    if (isTerminal(productions[i][k])) {
                        addToSet(result, productions[i][k]);
                        break;
                    } else {
                        char temp[20] = "";
                        computeFirst(productions[i][k], temp);
                        for (int j = 0; temp[j]; j++)
                            addToSet(result, temp[j]);

                        if (!strchr(temp, '#')) break;
                        else k++;
                    }
                }
            }
        }
    }
}

void computeFollow(char symbol, char result[]) {
    if (symbol == nonTerminals[0]) addToSet(result, '$');

    for (int i = 0; i < prodCount; i++) {
        for (int j = 3; productions[i][j]; j++) {
            if (productions[i][j] == symbol) {
                if (productions[i][j + 1]) {
                    if (isTerminal(productions[i][j + 1])) {
                        addToSet(result, productions[i][j + 1]);
                    } else {
                        char temp[20] = "";
                        computeFirst(productions[i][j + 1], temp);
                        for (int k = 0; temp[k]; k++)
                            if (temp[k] != '#')
                                addToSet(result, temp[k]);

                        if (strchr(temp, '#'))
                            computeFollow(productions[i][0], result);
                    }
                } else {
                    if (productions[i][0] != symbol)
                        computeFollow(productions[i][0], result);
                }
            }
        }
    }
}

void buildParsingTable() {
    for (int i = 0; i < prodCount; i++) {
        char temp[20] = "";
        computeFirst(productions[i][0], temp);

        int row = indexOf(productions[i][0], nonTerminals, ntCount);

        if (productions[i][3] == '#') {
            for (int j = 0; follow[row][j]; j++) {
                int col = indexOf(follow[row][j], terminals, tCount);
                strcpy(table[row][col], productions[i]);
            }
        } else {
            for (int j = 3; productions[i][j]; j++) {
                if (isTerminal(productions[i][j])) {
                    int col = indexOf(productions[i][j], terminals, tCount);
                    strcpy(table[row][col], productions[i]);
                    break;
                } else {
                    char f[20] = "";
                    computeFirst(productions[i][j], f);
                    for (int k = 0; f[k]; k++) {
                        if (f[k] != '#') {
                            int col = indexOf(f[k], terminals, tCount);
                            strcpy(table[row][col], productions[i]);
                        }
                    }
                    if (!strchr(f, '#')) break;
                }
            }
        }
    }
}

void displayTable() {
    printf("\nPredictive Parsing Table:\n\n");
    printf("%10s", "");
    for (int i = 0; i < tCount; i++)
        printf("%10c", terminals[i]);
    printf("\n-----------------------------------------------------------\n");

    for (int i = 0; i < ntCount; i++) {
        printf("%10c", nonTerminals[i]);
        for (int j = 0; j < tCount; j++) {
            if (strlen(table[i][j]) == 0)
                printf("%10s", "-");
            else
                printf("%10s", table[i][j]);
        }
        printf("\n");
    }
}

int main() {
    int n;
    printf("Enter number of non-terminals: ");
    scanf("%d", &n);
    getchar();

    for (int i = 0; i < n; i++) {
        char line[100];
        printf("Enter productions for non-terminal %d (e.g. E->TR|e): ", i + 1);
        fgets(line, sizeof(line), stdin);
        line[strcspn(line, "\n")] = '\0';

        nonTerminals[ntCount++] = line[0];

        char* token = strtok(strchr(line, '>') + 1, "|");
        while (token) {
            sprintf(productions[prodCount], "%c->%s", line[0], token);
            for (int k = 0; token[k]; k++) {
                if (isTerminal(token[k]) && token[k] != '#' && indexOf(token[k], terminals, tCount) == -1) {
                    terminals[tCount++] = token[k];
                }
            }
            prodCount++;
            token = strtok(NULL, "|");
        }
    }

    terminals[tCount++] = '$'; // Add end marker

    // Compute FIRST
    for (int i = 0; i < ntCount; i++)
        computeFirst(nonTerminals[i], first[i]);

    // Compute FOLLOW
    for (int i = 0; i < ntCount; i++)
        computeFollow(nonTerminals[i], follow[i]);

    printf("\nFIRST sets:\n");
    for (int i = 0; i < ntCount; i++)
        printf("FIRST(%c) = {%s}\n", nonTerminals[i], first[i]);

    printf("\nFOLLOW sets:\n");
    for (int i = 0; i < ntCount; i++)
        printf("FOLLOW(%c) = {%s}\n", nonTerminals[i], follow[i]);

    // Build and show table
    buildParsingTable();
    displayTable();

    return 0;
}
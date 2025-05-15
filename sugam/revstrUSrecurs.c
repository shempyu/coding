#include <stdio.h>
#include <string.h>
//rev String using recusrion
void reverse(char *s, int x, int y)
{
    if (x >= y)
    {
        return;
    }
    char temp = s[x];
    s[x] = s[y];
    s[y] = temp;
    reverse(s, x + 1, y - 1);
}

int main()
{
    char str[100];
    printf("enetr the string: ");
    fgets(str, sizeof(str), stdin);  // Reads input including spaces
     str[strcspn(str, "\n")] = '\0';  // Removes the trailing newline character, if any
    printf("Reverse string: %s \n", str);
    // char str[] = "GOOD WORK";
    int length = strlen(str);
    reverse(str, 0, length - 1);

    printf("Reverse string: %s \n", str);
   return 0;
}
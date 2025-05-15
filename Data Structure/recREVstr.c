#include <stdio.h>
#include<string.h>
int i = 0;
void revstr(char str[],int size){
    if(i<size/2){
        char temp = str[i];
        str[i] = str[size-i-1];
        str[size-1-i] = temp;
        i++;
        return revstr(str,size);
    }
    else{
        return;
    }
}
int main()
{
    char str[100];

    // Input the string
    printf("Enter a string: ");
    fgets(str,sizeof(str),stdin);
    str[strcspn(str,"\n")] ='\0' ;
    // scanf("%s", str);
    fgets(str, sizeof(str), stdin);  // Reads input including spaces
     str[strcspn(str, "\n")] = '\0';
    int i = 0;
    int len = strlen(str);
    // while (str[i++] != '\0')
    // {
    //     len++;
    // }

    // Reverse the string
revstr(str,len);
    // Print the reversed string
    printf("Reversed string: %s\n", str);

    return 0;
}

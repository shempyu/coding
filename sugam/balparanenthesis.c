#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define size 10
char arr[size];
int top = -1;

int isEmpty(){
    return top == -1;
}

void push(char val){
        arr[++top] = val;
}

int pop(){
    if(isEmpty())
        printf("Stack is Empty\n");
    else
        top--;
}

char topEle(){
    if (top == -1)
      return -1;
    else 
    return arr[top] ;
}

char map(char ch){
    if(ch == ')')   return '(';
    if(ch == ']')   return '[';
    if(ch == '}')   return '{';
    return '\0';
}

void checkExp(char* exp){
    int flag = 1;
    for (int i = 0; exp[i] != '\0'; i++)
    {
        if(exp[i] == '(' || exp[i] == '[' || exp[i] == '{'){
            push(exp[i]);
        }
        else if(exp[i] == ')' || exp[i] == ']' || exp[i] == '}')
        {
            if(isEmpty() || topEle() != map(exp[i])){
                flag = 0;
                break;
            }
            else{
                pop();
            }
        }
    }
    if(flag && isEmpty())
        printf("Parenthesis is Balanced\n");
    else    
         printf("Parenthesis is Not Balanced\n");
    
}

int main(){
    
    char exp[200] = "";
    printf("Enter the Expression:");
    scanf("%s",exp);
    checkExp(exp);
    
  return 0;
}
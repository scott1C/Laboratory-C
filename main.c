#include <stdio.h>
#include <string.h>
#include <conio.h>

void isRotation(char firstString[], char secondString[])
{
    int firstNumber = 0, secondNumber = 0;
    for (int i = 0; i < strlen(firstString); i++)
        firstNumber += firstString[i];
    for (int i = 0; i < strlen(secondString); i++)
        secondNumber += secondString[i];

    if (firstNumber == secondNumber)
    {
        printf("It is possible\n");
    }
    else
    {
        printf("It is not possible\n");
    }
}

int isPalindrome(char string[])
{
    for (int i = 0; i < strlen(string) / 2; i++)
        if (string[i] != string[strlen(string) - i - 1])
            return 0;
    return 1;
}

int main()
{
    char text[100], symbol;
    printf("Enter your text: ");
    fgets(text, 100, stdin);
    text[strlen(text) - 1] = '\0';

    printf("Enter the symbol which you want to find: ");
    scanf("%c", &symbol);
    int count = 0;
    for (int i = 0; i < strlen(text); i++)
        if (text[i] == symbol)
            count++;
    printf("%d\n", count);

    char one[100], two[200];
    printf("Enter the first string: ");
    scanf("%s", one);

    printf("Enter the second string: ");
    scanf("%s", two);
    isRotation(one, two);

    char palindromicText[100];
    printf("Enter the string which you want to check if it is palindromic: ");
    scanf("%s", text);

    int palindrome = isPalindrome(palindromicText);

    if (palindrome)
    {
        printf("It is palindrome\n");
    }
    else
    {
        printf("It is not palindrome\n");
    }

    getch();
    return 0;
}
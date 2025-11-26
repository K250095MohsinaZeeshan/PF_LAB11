#include <stdio.h>
#include <string.h>

void reverseString(char str[], int start, int end) {
    if(start >= end) return;
    char temp = str[start];
    str[start] = str[end];
    str[end] = temp;
    reverseString(str, start + 1, end - 1);
}

int isPalindrome(char str[], int start, int end) {
    if(start >= end) return 1;
    if(str[start] != str[end]) return 0;
    return isPalindrome(str, start + 1, end - 1);
}

int main() {
    char word[100];
    int length;
    printf("WORD GAME\n");
    printf("_________\n");
    printf("\nEnter a word: ");
    scanf("%s", word);
    length = strlen(word);

    printf("\nOriginal word: %s\n", word);

    reverseString(word, 0, length - 1);
    printf("\nReversed word: %s\n", word);
    printf("____________________\n");
    if(isPalindrome(word, 0, length - 1))
        printf("\nIt is a palindrome.\n");
    else
        printf("\nIt is not a palindrome.\n");

    return 0;
}


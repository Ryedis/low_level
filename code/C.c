#include <stdio.h>
#include <string.h>

#define MAX_LEN 255
#define SHIFT 3

const char ALPHABET[] = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz[]()+-*/=&?!\\\"’:;@.,";
const int ALPHABET_SIZE = sizeof(ALPHABET) - 1;

int find_char_in_alphabet(char ch) {
    for (int i = 0; i < ALPHABET_SIZE; i++) {
        if (ALPHABET[i] == ch) {
            return i;
        }
    }
    return -1;
}

void caesar_cipher(char str[]) {
    int i = 0;
    while (str[i] != '\0') {
        int pos = find_char_in_alphabet(str[i]);
        if (pos != -1) {
            str[i] = ALPHABET[(pos + SHIFT) % ALPHABET_SIZE];
        }
        i++;
    }
}

int main() {
    char str[MAX_LEN];
    
    printf("Enter a string: ");
    fgets(str, MAX_LEN, stdin);
    
    str[strcspn(str, "\n")] = 0;
    
    caesar_cipher(str);
    printf("Encrypted string: %s\n", str);

    char exitKey;
    printf("Press 'q' to exit...\n");
    while ((exitKey = getchar()) != 'q');
    return 0;
}
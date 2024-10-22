#include <stdio.h>
#include <string.h>

#define MAX_LEN 255
#define SHIFT 3

const char ALPHABET[] = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz[]()+-*/=&?!\\\"’:;@.,";
const int ALPHABET_SIZE = sizeof(ALPHABET) - 1;

int find_char_in_alphabet(char ch) {
    int i;
    i = 0;
    
find_loop_start:
    if (i >= ALPHABET_SIZE) goto not_found;
    if (ALPHABET[i] == ch) goto found;
    
    i = i + 1;
    goto find_loop_start;

found:
    return i;

not_found:
    return -1;
}

void caesar_cipher(char str[]) {
    int i, pos;
    i = 0;

cipher_loop_start:
    if (str[i] == '\0') goto cipher_done;

    pos = find_char_in_alphabet(str[i]);

    if (pos == -1) goto skip_char;

    pos = pos + SHIFT;
    pos = pos % ALPHABET_SIZE;

    str[i] = ALPHABET[pos];

skip_char:
    i = i + 1;
    goto cipher_loop_start;

cipher_done:
    return;
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
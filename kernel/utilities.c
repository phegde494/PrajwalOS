#include <stdint.h>
#include <stdbool.h>

// Compute length of a string
int string_length(char s[]) {
    int i = 0;
    while (s[i] != '\0') ++i;
    return i;
}

// Reverse a string
void reverse(char s[]) {
    int c, i, j;
    for (i = 0, j = string_length(s)-1; i < j; i++, j--) {
        c = s[i];
        s[i] = s[j];
        s[j] = c;
    }
}

// Stores string representation of n within str
void int_to_string(int n, char str[]) {
    int i, sign;
    if ((sign = n) < 0) n = -n;
    i = 0;
    do {
        str[i++] = n % 10 + '0';
    } while ((n /= 10) > 0);

    if (sign < 0) str[i++] = '-';
    str[i] = '\0';

    reverse(str);
}

// Appends the given character to the given string
void append(char s[], char n) {
    int len = string_length(s);
    s[len] = n;
    s[len+1] = '\0';
}

// Removes the last character from the given string
bool backspace(char s[]) {
    int len = string_length(s);
    if (len > 0) {
        s[len - 1] = '\0';
        return true;
    } else {
        return false;
    }
}

// Returns negative val if s1 < s2
// Returns 0 if s1 == s2
// Returns positive val if s1 > s2
int compare_string(char s1[], char s2[]) {
    int i;
    for (i = 0; s1[i] == s2[i]; i++) {
        if (s1[i] == '\0') return 0;
    }
    return s1[i] - s2[i];
}


int starts_with_key(char input[], char key[]) {
    int len_input = string_length(input);
    int len_key = string_length(key);

    // Check if key is longer than input or if input is empty
    if (len_input == 0 || len_key > len_input) {
        return -1;
    }

    for (int i = 0; i < len_key; ++i) {
        if (input[i] != key[i]) {
            return -1;
        }
    }

    // Check if there's a space after key in input
    if (input[len_key] == ' ') {
        return len_key + 1;
    }

    return -1;
}
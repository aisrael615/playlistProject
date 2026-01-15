#include<stdlib.h>
#include<string.h>
#include<stdio.h>
#include<ctype.h>
#include "utils.h"

char *lowercase(const char *string) { // Creates new, lowercase version of string
    size_t len = strlen(string);
    char *lcString = malloc(len + 1);
    if (!lcString) return NULL;

    for (size_t i = 0; i < len; i++) {
        lcString[i] = tolower((unsigned char)string[i]);
    }
    lcString[len] = '\0';
    return lcString;
}

// Fisher–Yates in-place array shuffle
void shuffle_array(void **arr, int len) {
    for (int i = len - 1; i > 0; i--) { // Move backwards
        // select one of remaining non-shuffled elements and swap it with current element
        int j = rand() % (i + 1);
        void *tmp = arr[i];
        arr[i] = arr[j];
        arr[j] = tmp;
    }
}

// Compares two strings case-insensitively in place 
// Note: Avoids using lowercase so not allocating each comparison
int str_case_cmp(const char *s1, const char *s2) {
    while (*s1 && *s2) {
        char c1 = tolower((unsigned char)*s1);
        char c2 = tolower((unsigned char)*s2);
        if (c1 != c2) return c1 - c2;
        s1++;
        s2++;
    }
    return tolower((unsigned char)*s1) - tolower((unsigned char)*s2);
}

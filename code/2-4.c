#include <stdio.h>

int main(int argc, const char *argv[]) {
    if (argc < 2) {
        return 0;
    }

    FILE *fp = fopen(argv[1], "r");
    if (fp == NULL) {
        return 0;
    }

    int count[26] = {0};
    int c;

    while ((c = fgetc(fp)) != EOF) {
        if ('a' <= c && c <= 'z') {
            count[c - 'a']++;
        }
    }

    for (int i = 0; i < 26; i++) {
        printf("%c: %d\n", 'a' + i, count[i]);
    }

    fclose(fp);

    return 0;
}

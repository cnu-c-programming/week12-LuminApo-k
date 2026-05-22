#include <stdio.h>

void cat(const char *filename) {
    FILE *fp = fopen(filename, "r");
    if (fp == NULL) {
        return;
    }

    int c;
    while ((c = fgetc(fp)) != EOF) {
        putchar(c);
    }

    fclose(fp);
}

int main(int argc, const char *argv[]) {
    if (argc < 2) {
        return 0;
    }

    cat(argv[1]);
    return 0;
}

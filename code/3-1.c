#include <stdio.h>

int main(int argc, const char *argv[]) {
    if (argc < 2) {
        return 0;
    }

    FILE *fp = fopen(argv[1], "r");

    if (fp == NULL) {
        perror("file dose not exists");
        return 1;
    }

    fclose(fp);

    return 0;
}

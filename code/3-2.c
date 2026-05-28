#include <stdio.h>

int main(int argc, const char *argv[]) {
    if (argc < 2) {
        return 0;
    }

    const char *filename = argv[1];

    FILE *fp = fopen(filename, "r");
    if (fp == NULL) {
        return 0;
    }

    char buffer[10];

    fgets(buffer, sizeof(buffer), fp);
    fclose(fp);

    printf("%s", buffer);

    return 0;
}

#include <stdio.h>

int main(int argc, const char *argv[]) {
    if (argc < 2) {
        return 0;
    }

    for (int i = 1; i < argc; i++) {
        const char *filename = argv[i];
        char buffer[256] = {0};

        FILE *fp = fopen(filename, "r");
        if (fp == NULL) {
            return 0;
        }

        fgets(buffer, sizeof(buffer), fp);
        fclose(fp);

        printf("%s\n", buffer);
    }

    return 0;
}

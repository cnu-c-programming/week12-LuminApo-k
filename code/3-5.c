#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int main(int argc, const char *argv[]) {
    const char *filename = "numbers.txt";

    FILE *fp = fopen(filename, "r");
    if (fp == NULL) {
        return 0;
    }

    char line[256];
    int sum = 0;

    while (fgets(line, sizeof(line), fp) != NULL) {
        line[strcspn(line, "\n")] = '\0';

        char *endptr;
        long value = strtol(line, &endptr, 10);

        while (isspace((unsigned char)*endptr)) {
            endptr++;
        }

        if (line[0] == '\0' || *endptr != '\0') {
            fprintf(stderr, "invalid input %s\n", line);
        } else {
            sum += value;
        }
    }

    printf("sum: %d\n", sum);

    fclose(fp);

    return 0;
}

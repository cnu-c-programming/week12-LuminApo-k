#include <stdio.h>
#include <string.h>

int main(int argc, const char *argv[]) {
    if (argc < 3) {
        return 0;
    }

    FILE *fp = fopen(argv[1], "r");
    const char *target_str = argv[2];

    char buffer[256];

    while (fgets(buffer, sizeof(buffer), fp) != NULL) {
        if (strstr(buffer, target_str) != NULL) {
            printf("%s", buffer);
        }
    }

    fclose(fp);

    return 0;
}

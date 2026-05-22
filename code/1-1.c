#include <stdio.h>

int main(int argc, char const *argv[])
{
    if (argc < 2)
        return 0;

        const char* filename = argv[1];
        char buffer[256] = {0};

        FILE* fp = fopen(filename, "r");
        if (fp == NULL)
        return 0;

        fgets(buffer, sizeof(buffer), fp);
        fclose(fp);

        printf("%s\n", buffer);

        return 0;
}

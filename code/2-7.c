#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

typedef struct config {
    char InputFileName[64];
    int Options;
    char SectionName[64];
    unsigned long long Address;
} Config;

void trim(char *str) {
    int len = strlen(str);

    while (len > 0 && isspace((unsigned char)str[len - 1])) {
        str[len - 1] = '\0';
        len--;
    }

    int start = 0;
    while (str[start] != '\0' && isspace((unsigned char)str[start])) {
        start++;
    }

    if (start > 0) {
        memmove(str, str + start, strlen(str + start) + 1);
    }
}

void config_parser(Config *config) {
    FILE *fp = fopen("config.txt", "r");
    char line[256];

    config->InputFileName[0] = '\0';
    config->Options = 0;
    config->SectionName[0] = '\0';
    config->Address = 0;

    while (fgets(line, sizeof(line), fp) != NULL) {
        char *equal = strchr(line, '=');

        if (equal == NULL) {
            continue;
        }

        *equal = '\0';

        char key[64];
        char value[128];

        strcpy(key, line);
        strcpy(value, equal + 1);

        trim(key);
        trim(value);

        if (strcmp(key, "InputFileName") == 0 || strcmp(key, "InputFilename") == 0) {
            strcpy(config->InputFileName, value);
        } else if (strcmp(key, "Options") == 0) {
            config->Options = atoi(value);
        } else if (strcmp(key, "SectionName") == 0) {
            strcpy(config->SectionName, value);
        } else if (strcmp(key, "Address") == 0) {
            config->Address = strtoull(value, NULL, 0);
        }
    }

    fclose(fp);
}

int main(int argc, const char *argv[]) {
    Config config;

    config_parser(&config);

    printf("config: %s %d %s %llu\n",
           config.InputFileName,
           config.Options,
           config.SectionName,
           config.Address);

    return 0;
}

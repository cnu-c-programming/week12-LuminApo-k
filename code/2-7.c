#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct config {
    char InputFilename[64];
    int Options;
    char SectionName[64];
    unsigned long long Address;
} Config;

void config_parser(Config *config) {
    FILE *fp = fopen("config.txt", "r");
    if (fp == NULL) {
        return;
    }

    char line[256];

    while (fgets(line, sizeof(line), fp) != NULL) {
        char key[64];
        char value[128];

        if (sscanf(line, "%63[^=]=%127s", key, value) != 2) {
            continue;
        }

        if (strcmp(key, "InputFilename") == 0) {
            strcpy(config->InputFilename, value);
        } else if (strcmp(key, "Options") == 0) {
            config->Options = atoi(value);
        } else if (strcmp(key, "SectionName") == 0) {
            strcpy(config->SectionName, value);
        } else if (strcmp(key, "Address") == 0) {
            config->Address = strtoull(value, NULL, 10);
        }
    }

    fclose(fp);
}

int main(int argc, const char *argv[]) {
    Config config;

    config_parser(&config);

    printf("config: %s %d %s %llu\n",
           config.InputFilename,
           config.Options,
           config.SectionName,
           config.Address);

    return 0;
}

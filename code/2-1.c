#include <stdio.h>
#include <string.h>

int main(int argc, const char *argv[], const char *envp[]) {
    FILE *fp = fopen("student.txt", "w");

    while (1) {
        char name[10] = {'\0'};
        int score = 0;

        scanf("%9s", name);

        if (strcmp(name, "quit") == 0) {
            break;
        }

        scanf("%d", &score);

        fprintf(fp, "%s %d\n", name, score);
    }

    fclose(fp);

    return 0;
}

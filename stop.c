#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define N 1000
#define L 100

typedef struct {
    char w[L];
    int c;
} Word;

int same(char *a, char *b) {
    return strcmp(a, b) == 0;
}

void chop(char *s) {
    int n = strlen(s);
    if (s[n - 1] == '\n') s[n - 1] = '\0';
}

int main() {
    FILE *src = fopen("source.txt", "r");
    FILE *del = fopen("drop.txt", "r");
    FILE *out = fopen("output.txt", "w");
    FILE *rep = fopen("report.txt", "w");

    if (!src || !del || !out || !rep) {
        printf("File error.\n");
        return 1;
    }

    Word d[N];
    int dc = 0;

    while (fgets(d[dc].w, L, del)) {
        chop(d[dc].w);
        d[dc].c = 0;
        dc++;
    }

    char w[L];
    while (fscanf(src, "%s", w) == 1) {
        int found = 0;
        for (int i = 0; i < dc; i++) {
            if (same(w, d[i].w)) {
                d[i].c++;
                found = 1;
                break;
            }
        }
        if (!found) fprintf(out, "%s ", w);
    }

    for (int i = 0; i < dc; i++)
        fprintf(rep, "%s: %d\n", d[i].w, d[i].c);

    fclose(src);
    fclose(del);
    fclose(out);
    fclose(rep);

    printf("Done. Check output.txt and report.txt\n");
    return 0;
}

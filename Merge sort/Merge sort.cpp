#include <iostream>
#include <string>
#pragma warning(disable : 4996)
using namespace std;

void SimpleMergeSort() {
    char name[9] = "C:\\f.txt";

    int a1, a2, k, i, j, count, tmp;
    FILE* f, * f1, * f2;
    count = 0;

    if ((f = fopen(name, "r+")) == NULL)
        printf("\nCan't open file...");
    else {
        while (!feof(f)) {
            fscanf(f, "%d", &a1);
            count++;
        }
        fclose(f);
    }

    k = 1;

    while (k < count) {
        f = fopen(name, "r");
        f1 = fopen("f1", "w");
        f2 = fopen("f2", "w");

        if (!feof(f)) 
            fscanf(f, "%d", &a1);

        while (!feof(f)) {
            for (i = 0; i < k && !feof(f); i++) {
                fprintf(f1, "%d ", a1);
                fscanf(f, "%d", &a1);
            }
            for (j = 0; j < k && !feof(f); j++) {
                fprintf(f2, "%d ", a1);
                fscanf(f, "%d", &a1);
            }
        }

        fclose(f2);
        fclose(f1);
        fclose(f);

        f = fopen(name, "w");
        f1 = fopen("f1", "r");
        f2 = fopen("f2", "r");

        if (!feof(f1))
            fscanf(f1, "%d", &a1);

        if (!feof(f2))
            fscanf(f2, "%d", &a2);

        while (!feof(f1) && !feof(f2)) {
            i = 0;
            j = 0;

            while (i < k && j < k && !feof(f1) && !feof(f2)) {
                if (a1 < a2) {
                    fprintf(f, "%d ", a1);
                    fscanf(f1, "%d", &a1);
                    i++;
                }
                else {
                    fprintf(f, "%d ", a2);
                    fscanf(f2, "%d", &a2);
                    j++;
                }
            }
            while (i < k && !feof(f1)) {
                fprintf(f, "%d ", a1);
                fscanf(f1, "%d", &a1);
                i++;
            }
            while (j < k && !feof(f2)) {
                fprintf(f, "%d ", a2);
                fscanf(f2, "%d", &a2);
                j++;
            }
        }
        while (!feof(f1)) {
            fprintf(f, "%d ", a1);
            fscanf(f1, "%d", &a1);
        }
        while (!feof(f2)) {
            fprintf(f, "%d ", a2);
            fscanf(f2, "%d", &a2);
        }

        fclose(f2);
        fclose(f1);
        fclose(f);
        k *= 2;
    }

    remove("f1");
    remove("f2");
}

int main() {
    SimpleMergeSort();

    system("pause");
    return 0;
}
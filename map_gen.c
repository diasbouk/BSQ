#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(int argc, char *argv[]) {
    if (argc != 4) {
        fprintf(stderr, "Usage: %s x y density\n", argv[0]);
        return 1;
    }

    int x = atoi(argv[1]);
    int y = atoi(argv[2]);
    int density = atoi(argv[3]);

    // Seed the random number generator
    srand(time(NULL));

    printf("%d.ox\n", y);

    for (int i = 0; i < y; i++) {
        for (int j = 0; j < x; j++) {
            if ((int)(((double)rand() / RAND_MAX) * y * 2) < density) {
                printf("o");
            } else {
                printf(".");
            }
        }
        printf("\n");
    }

    return 0;
}


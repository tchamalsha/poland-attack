#include <stdio.h>

int main() {
    int T;
    int N;
    int V;

    //taking the test cases
    printf("test cases: ");
    scanf("%d",&T);
    printf("First attack was done by Hitland.\n");
    for (int q=0;q<T;q++) {
        printf("Enter number of cities and voco city ID: ");
        scanf("%d %d", &N, &V);
        int roads[N - 1][2];
        struct cities {
            int NCR;
        };
        struct cities cts[N];
        for (int j = 0; j < N - 1; j++) {
            printf("roads: ");
            scanf("%d %d", &roads[j][0], &roads[j][1]);
        }

        //finding number of connected roads
        for (int r = 0; r < N - 1; r++) {
            cts[r].NCR = 0;
            for (int q = 0; q < N - 1; q++) {

                if (roads[q][0] == r + 1)
                    cts[r].NCR = cts[r].NCR + 1;
                if (roads[q][1] == r + 1)
                    cts[r].NCR = cts[r].NCR + 1;
            }
        }

        int x = 1;
        if (cts[V - 1].NCR < 2) {
            if (x % 2 == 0)
                printf("Stalind\n");
            else
                printf("Hitland\n");
        } else {
            x = 0;
            while (cts[V - 1].NCR >= 2) {

                for (int r = 0; r < N; r++) {
                    if (cts[r].NCR == 1) {
                        x = x + 1;
                        for (int i = 0; i < N - 1; i++) {

                            if (roads[i][0] == r + 1 && roads[i][1] == V || roads[i][0] == V && roads[i][1] == r + 1) {
                                cts[V - 1].NCR = cts[V - 1].NCR - 1;
                                if (cts[V - 1].NCR < 2) {
                                    x = x + 1;
                                    if (x % 2 == 0)
                                        printf("Stalind\n");
                                    else
                                        printf("Hitland\n");
                                }
                            } else
                                continue;

                        }

                    }
                }
            }
        }


    }
    system("pause");
    return 0;

}

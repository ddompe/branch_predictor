
#include <math.h>
#include <stdio.h>
#include <stdlib.h>

#include "sim.h"



void bimodal_simulation(int s, struct results *results) {
    int size = (int)pow(2, s);
    char *bht = calloc(size, sizeof(char));
    int i = 0;
    char *line = NULL;
    size_t len = 0;

    printf("Running a bimodal simulation, table size = %d\n", size);

    // Check our initialization
    for (i = 0; i < size; i++) {
        if (bht[i] != STRONGLY_NOT_TAKEN) {
            printf("Invalid initialization at location %d!\n",i);
            return;
        }
    }
    printf("BHT predictor properly initialized!\n");

    printf("\nProcessing entries (wait)... ");
    fflush(stdout);

    long long int address = 0;
    char t_or_n = ' ';
    i = 0;
    while(scanf("%lld %c", &address, &t_or_n) != EOF)
    {
        results->number_branches++;
        i++;
        //printf("At %d read %lld %c\n", i, address, t_or_n);

        if (!((t_or_n == 'N') || (t_or_n == 'T'))) {
            printf("\nInvalid input processed at line %d! \n", i);
            return;
        }

        int counter_idx =  address & (size - 1);
        char prediction = bht[counter_idx];

        if (t_or_n == 'T') {
            if ((prediction == WEAKLY_TAKEN) || (prediction == STRONGLY_TAKEN)) {
                results->predicted_branch_right++;
            } else if ((prediction == WEAKLY_NOT_TAKEN) || (prediction == STRONGLY_NOT_TAKEN)) {
                results->predicted_miss_wrong++;
            } else {
                printf("Invalid state machine at line %d!\n",i);
                return;
            }

            // Adjust the prediction
            if (bht[counter_idx] < 3) {
                bht[counter_idx]++;
            }
        } else if (t_or_n == 'N') {
            if ((prediction == WEAKLY_TAKEN) || (prediction == STRONGLY_TAKEN)) {
                results->predicted_branch_wrong++;
            } else if ((prediction == WEAKLY_NOT_TAKEN) || (prediction == STRONGLY_NOT_TAKEN)) {
                results->predicted_miss_right++;
            } else {
                printf("Invalid state machine at line %d!\n",i);
                return;
            }

            // Adjust the prediction
            if (bht[counter_idx] > 0) {
                bht[counter_idx]--;
            }
        } else {
            printf("Invalid result at line %d!\n",i);
            return;
        }
    }
    printf("done!\n");

    free(bht);
}
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <getopt.h>
#include "sim.h"

static struct option long_options[] = {
    {"s",  required_argument, 0,  's' },
    {"bp", required_argument, 0,  'b' },
    {"gh", required_argument, 0,  'g' },
    {"ph", required_argument, 0,  'p' },
    { 0, 0, 0, 0 }
};


void print_usage() {
    printf("Usage: branch -s # -bp # -gh # -ph #\n");
}

int main(int argc, char **argv) {
    int opt;
    int s;
    int bp;
    int gh;
    int ph;
    struct results results;

    printf("Cache Predictor\n");
    int long_index =0;

    while ((opt = getopt_long_only(argc, argv, "", 
                   long_options, &long_index )) != -1) {
        switch (opt) {
             case 's' : s = atoi(optarg);
                 break;
             case 'b' : bp = atoi(optarg);
                 break;
             case 'g' : gh = atoi(optarg);
                 break;
             case 'p' : ph = atoi(optarg);
                 break;
             default: print_usage(); 
                 exit(EXIT_FAILURE);
        }
    }

    printf("Parameters: s %d, bp %d, gh %d, ph %d\n", s, bp, gh, ph);

    switch (bp) {
        case 0:
            bimodal_simulation(s, &results);
            break;
        default:
            printf("Unsupported simulation mode!\n\n");
            break;
    }

    printf("Number of branches: %d\n", results.number_branches);
    printf("Correct prediction of taken: %d\n", results.predicted_branch_right);
    printf("Incorrect prediction of taken: %d\n", results.predicted_branch_wrong);
    printf("Correct prediction of NOT taken: %d\n", results.predicted_miss_right);
    printf("Incorrect prediction of NOT taken: %d\n", results.predicted_miss_wrong);
    int good_predictions = results.predicted_branch_right + results.predicted_miss_right;
    double percentage = good_predictions * 100.0 / results.number_branches;
    printf("Percenage of correct predictions %f\n", percentage);

    printf("\n");

    return 0;
}
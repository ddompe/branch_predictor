#ifndef __SIM_H
#define __SIM_H 1

struct results {
    int number_branches;
    int predicted_branch_right;
    int predicted_branch_wrong;
    int predicted_miss_right;
    int predicted_miss_wrong;
};

enum bimodal_values {
    STRONGLY_NOT_TAKEN = 0,
    WEAKLY_NOT_TAKEN = 1,
    WEAKLY_TAKEN = 2,
    STRONGLY_TAKEN = 3
};

void bimodal_simulation(int s, struct results *results);

#endif
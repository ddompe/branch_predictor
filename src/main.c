#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <getopt.h>

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

    return 0;
}
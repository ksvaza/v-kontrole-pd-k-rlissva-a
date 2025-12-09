#include <stdio.h>
#include <stdlib.h>

#define ull unsigned long long

int largest_n = -1;
int capacity = 0;
ull *memo = NULL;

ull fibonacci(int n) {
    if (n < 0) {
        return 0;
    }

    /* initialize memo if needed */
    if (memo == NULL) {
        capacity = (100 > (n + 1)) ? 100 : (n + 1);
        memo = (ull *)malloc(capacity * sizeof(ull));
        if (memo == NULL) {
            fprintf(stderr, "malloc failed\n");
            exit(EXIT_FAILURE);
        }
        memo[0] = 0;
        if (capacity > 1) memo[1] = 1;
        largest_n = 1;
    }

    /* grow buffer if required */
    if (n >= capacity) {
        int newcap = n + 1;
        ull *tmp = (ull *)realloc(memo, newcap * sizeof(ull));
        if (tmp == NULL) {
            fprintf(stderr, "realloc failed\n");
            free(memo);
            exit(EXIT_FAILURE);
        }
        memo = tmp;
        capacity = newcap;
    }

    /* if already computed, return cached value */
    if (n <= largest_n) {
        return memo[n];
    }

    /* compute missing Fibonacci values up to n */
    for (int i = largest_n + 1; i <= n; i++) {
        if (i == 0) {
            memo[i] = 0;
        } else if (i == 1) {
            memo[i] = 1;
        } else {
            memo[i] = memo[i - 1] + memo[i - 2];
        }
    }
    largest_n = n;
    return memo[n];
}

int main(void) {
    const int start = 93;
    printf("Spiediet Enter, lai redzētu iepriekšējo fibonači skaitli (vai spiediet 'q', lai izbeigtu))\n");
    for (int i = start; i >= 0; --i) {
        printf("F(%d) = %llu\n", i, fibonacci(i));
        if (i == 0) break;
        fflush(stdout);

        int c = getchar();
        if (c == 'q' || c == 'Q') break;
        /* consume rest of the line if user typed other chars before Enter */
        while (c != '\n' && c != EOF) c = getchar();
    }
    free(memo);
    return 0;
}
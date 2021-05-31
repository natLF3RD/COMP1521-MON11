#include <stdio.h>

int main(void)
{
    int nums[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    for (int i = 0; i < 10; i++) {
        printf("%d\n", nums[i]);
    }
    return 0;
}

int recurse (int i, int *nums) {
    // exit condition 
    if (i>=10) {
        return 1;
    }

    // code 
    printf("%d\n", nums[i]);

    // change of state
    i++;

    // recursion
    recurse(i, nums);
}



int aaa () {
    int i=0;

    while (i<10) {
        // do ur thing.
        i++;
    }
    int i;

    for (intialise; check/ condition ; incrememnt) {

    }
}
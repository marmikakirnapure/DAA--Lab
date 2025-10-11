#include <stdio.h>

void maxSubarraySum(int resources[], int n, int constraint) {
    int left = 0, right = 0, currentSum = 0, maxSum = 0;
    int bestLeft = 0, bestRight = 0;

    while (right < n) {
        currentSum += resources[right];

        while (currentSum > constraint && left <= right) {
            currentSum -= resources[left++];
        }

        if (currentSum <= constraint) {
            if (currentSum > maxSum) {
                maxSum = currentSum;
                bestLeft = left;
                bestRight = right;
            }
        }
        right++;
    }

    if (maxSum > 0) {
        printf("Max Subarray Sum: %d\n", maxSum);
        printf("Best Subarray: ");
        for (int i = bestLeft; i <= bestRight; i++) {
            printf(" %d ", resources[i]);
        }
        printf("\n");
    } else {
        printf("No valid subarray\n");
    }
}

int main() {
    int resource1[] = {2, 1, 3, 4};
    int n1 = sizeof(resource1) / sizeof(resource1[0]);
    int constraint1 = 5;
    maxSubarraySum(resource1, n1, constraint1);

    int resource2[] = {2,2,2,2};
    int n2 = sizeof(resource2) / sizeof(resource2[0]);
    int constraint2 = 4;
    maxSubarraySum(resource2, n2, constraint2);

    int resource3[] = {1,5,2,3};
    int n3 = sizeof(resource3) / sizeof(resource3[0]);
    int constraint3 = 5;
    maxSubarraySum(resource3, n3, constraint3);

    int resource4[] = {6,7,8};
    int n4 = sizeof(resource4) / sizeof(resource4[0]);
    int constraint4 = 5;
    maxSubarraySum(resource4, n4, constraint4);

    int resource5[] = {1,2,3,2,1};
    int n5 = sizeof(resource5) / sizeof(resource5[0]);
    int constraint5 = 5;
    maxSubarraySum(resource5, n5, constraint5);

    int resource6[] = {1,1,1,1,1};
    int n6 = sizeof(resource6) / sizeof(resource6[0]);
    int constraint6 = 4;
    maxSubarraySum(resource6, n6, constraint6);

    int resource7[] = {};
    int n7 = sizeof(resource7) / sizeof(resource7[0]);
    int constraint7 = 4;
    maxSubarraySum(resource7, n7, constraint7);


    return 0;
}
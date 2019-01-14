/*Part II : Program 9
Find the total internal fragmentation and external fragmentation using: First-t,
 Best-t, Worst-t
*/

#include <stdio.h>
#include <string.h>

void bestFit(int blockSize[], int m, int processSize[], int n) {
    int allocation[n];
    memset(allocation, -1, sizeof(allocation));
    for (int i = 0; i < n; i++) {
        int bestFitBlockIdx = -1;
        for (int j = 0; j < m; j++) {
            if (blockSize[j] >= processSize[i]) {
                if (bestFitBlockIdx == -1)
                    bestFitBlockIdx = j;
                else if (blockSize[bestFitBlockIdx] > blockSize[j])
                    bestFitBlockIdx = j;
            }
        }
        if (bestFitBlockIdx != -1) {
            allocation[i] = bestFitBlockIdx;
            blockSize[bestFitBlockIdx] -= processSize[i];
        }
    }
    printf("\nProcess No.  Process Size  Block number   Fragmentation\n");
    for (int i = 0; i < n; i++) {
        printf("%-12d  %-12d ", i + 1, processSize[i]);
        if (allocation[i] != -1) {
            printf("%-14d\t", allocation[i] + 1);
            printf("%-12d\n", blockSize[allocation[i]]);
        } else {
            printf("%-14s", "Not Allocated");
            printf("   ---------\n");
        }
    }
}

void worstFit(int blockSize[], int m, int processSize[], int n) {
    int allocation[n];
    memset(allocation, -1, sizeof(allocation));
    for (int i = 0; i < n; i++) {
        int worstFitBlockIdx = -1;
        for (int j = 0; j < m; j++) {
            if (blockSize[j] >= processSize[i]) {
                if (worstFitBlockIdx == -1)
                    worstFitBlockIdx = j;
                else if (blockSize[worstFitBlockIdx] < blockSize[j])
                    worstFitBlockIdx = j;
            }
        }
        if (worstFitBlockIdx != -1) {
            allocation[i] = worstFitBlockIdx;
            blockSize[worstFitBlockIdx] -= processSize[i];
        }
    }
    printf("\nProcess No.  Process Size  Block number   Fragmentation\n");
    for (int i = 0; i < n; i++) {
        printf("%-12d  %-12d ", i + 1, processSize[i]);
        if (allocation[i] != -1) {
            printf("%-14d\t", allocation[i] + 1);
            printf("%-12d\n", blockSize[allocation[i]]);
        } else {
            printf("%-14s", "Not Allocated");
            printf("   ---------\n");
        }
    }
}

void firstFit(int blockSize[], int m, int processSize[], int n) {
    int allocation[n];
    memset(allocation, -1, sizeof(allocation));
    for (int i = 0; i < n; i++) {
        int firstFitBlockIdx = -1;
        for (int j = 0; j < m; j++) {
            if (blockSize[j] >= processSize[i]) {
                firstFitBlockIdx = j;
                break;
            }
        }
        if (firstFitBlockIdx != -1) {
            allocation[i] = firstFitBlockIdx;
            blockSize[firstFitBlockIdx] -= processSize[i];
        }
    }
    printf("\nProcess No.  Process Size  Block number   Fragmentation\n");
    for (int i = 0; i < n; i++) {
        printf("%-12d  %-12d ", i + 1, processSize[i]);
        if (allocation[i] != -1) {
            printf("%-14d\t", allocation[i] + 1);
            printf("%-12d\n", blockSize[allocation[i]]);
        } else {
            printf("%-14s", "Not Allocated");
  option, n, m;
    printf("Enter the number of blocks: ");
    scanf("%d", &m);
    printf("Enter the number of process: ");
    scanf("%d", &n);
    int blockSize[m], processSize[n];
    for (int i = 0; i < m; i++) {
        printf("Enter the size of block %d: ", i + 1);
        scanf("%d", &blockSize[i]);
    }
    for (int i = 0; i < n; i++) {
        printf("Enter the size of process %d: ", i + 1);
        scanf("%d", &processSize[i]);
    }
    printf("1. First fit\n2. Best fit\n3. Worst fit\n");
    printf("Enter your choice: ");
    scanf("%d", &option);
    switch (option) {
        case 1:
            firstFit(blockSize, m, processSize, n);
            break;
        case 2:
            bestFit(blockSize, m, processSize, n);
            break;
        case 3:
            worstFit(blockSize, m, processSize, n);
            break;
    }
    int externalFragmentation = 0;
    for (int i = 0; i < m; i++) externalFragmentation += blockSize[i];
    printf("The total external fragmentation is: %d\n", externalFragmentation);
    return 0;
}

/*
Enter the number of blocks: 3
Enter the number of process: 2
Enter the size of block 1: 100
Enter the size of block 2: 200
Enter the size of block 3: 300
Enter the size of process 1: 123
Enter the size of process 2: 123
1. First fit
2. Best fit
3. Worst fit
Enter your choice: 1

Process No.  Process Size  Block number   Fragmentation
1             123          2             	77
2             123          3             	177
The total external fragmentation is: 354
*/


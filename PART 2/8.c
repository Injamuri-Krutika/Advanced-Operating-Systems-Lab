/*Part II : Program 8
Create 'n' number of virtual memory partitions where n is the total number of
processes. Each partition is of random size between minimum process size to 20%
more than the maximum process size.
*/
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#define NUMBER_OF_FRAMES 2097152  // 8 GB / 4 KB(2^21)
#define MIN_FRAMES 20
/*
Assumptions:
RAM: 8 GB
Page/Frame Size: 4 KB
*/

int main(int argc, char const *argv[]) {
    int numberOfProcesses, totalProcessSize = 0;
    printf("Enter the number of processes: ");
    scanf("%d", &numberOfProcesses);
    int processSizes[numberOfProcesses], minProcessSize;
    for (int i = 0; i < numberOfProcesses; i++) {
        printf(
            "Enter the minimun recommended process size for process %d in MB: ",
            i + 1);
        scanf("%d", &minProcessSize);
        processSizes[i] =
            (rand() % (int)((minProcessSize * 0.2 + 1)) + minProcessSize);
        totalProcessSize += processSizes[i];
    }
    // Allocation
    int remainingFrames = NUMBER_OF_FRAMES;
    for (int i = 0; i < numberOfProcesses; i++) {
        int allocatedFrames = (processSizes[i] * 256);
        remainingFrames -= allocatedFrames;
        printf(
            "Process %d was allocated %d frames and has process size of %d "
            "MB\n",
            i + 1, allocatedFrames, processSizes[i]);
    }
    printf("Remaining frames: %d\n", remainingFrames);
    return 0;
}

/*
*******************************************************************
Output:
*******************************************************************
Enter the number of processes: 5
Enter the minimun recommended process size for process 1 in MB: 100
Enter the minimun recommended process size for process 2 in MB: 200
Enter the minimun recommended process size for process 3 in MB: 300
Enter the minimun recommended process size for process 4 in MB: 400
Enter the minimun recommended process size for process 5 in MB: 500
Process 1 was allocated 27392 frames and has process size of 107 MB
Process 2 was allocated 53504 frames and has process size of 209 MB
Process 3 was allocated 90368 frames and has process size of 353 MB
Process 4 was allocated 107520 frames and has process size of 420 MB
Process 5 was allocated 132864 frames and has process size of 519 MB
Remaining frames: 1685504
*/


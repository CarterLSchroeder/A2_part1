// convert sequential sums to parallel

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

#define NUM_PROCESSES 4 //nun of child processes

int main(int argc, char *argv[]) 
{
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <N>\n", argv[0]);
        return 1;
    }

    int N = atoi(argv[1]);
    int *arr = malloc(N * sizeof(int));
    if (!arr) {
        perror("malloc");
        return 1;

    }

    for (int i = 0; i < N; i++) {  //fill/initizalize  the array
        arr[i] = i + 1;

    }
    int segment_size = N / NUM_PROCESSES;
    int pipes[NUM_PROCESSES][2];
    pid_t pids[NUM_PROCESSES]; //store process ids

    for (int i = 0; i < NUM_PROCESSES; i++) {
        if (pipe(pipes[i]) == -1) {
            perror("pipe errors");
            free(arr);
            return 1;
        }

        pids[i] = fork(); //creates process
        if (pids[i] < 0) {
            perror("fork failure");
            free(arr);
            return 1;

        } else if (pids[i] == 0) { //child process

            close(pipes[i][0]); 

            int start = i * segment_size;
            int end = (i == NUM_PROCESSES - 1) ? N : start + segment_size;
            long long local_sum = 0;

            for (int j = start; j < end; j++) {  //calculates local sum
                local_sum += arr[j];

            }

            write(pipes[i][1], &local_sum, sizeof(local_sum)); //sends results to parent
            close(pipes[i][1]); 

            free(arr);
            exit(0);

        } else {
            //parent process
            close(pipes[i][1]); 
        }
    }

    printf("Parent;  Waiting for child process to complete...\n");

    long long total_sum = 0;  //the final sum 
    for (int i = 0; i < NUM_PROCESSES; i++) {
        long long local_sum;
        read(pipes[i][0], &local_sum, sizeof(local_sum));
        close(pipes[i][0]); 

        total_sum += local_sum; //add total
        waitpid(pids[i], NULL, 0); // waits for child process to complete
        printf("Parent: Received local sum %d from child %d\n", local_sum, pids[i]);
    }

    printf("Parent: Total sum from 1 to %d is %d\n", N, total_sum); // final print of total sum
    free(arr);
    return 0;

}

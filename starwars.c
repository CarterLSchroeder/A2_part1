#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <stdlib.h>

// Starting shield power level
int shield_power = 50;  

int main() {
    pid_t pid;

    printf("Millennium Falcon: Initial shield power level: %d%%\n\n", shield_power);
    printf("May the forks be with you!\n\n");

    // Create 4 child processes - 4 different characters adjusting shield power
    for (int i = 0; i < 4; i++) {
        pid = fork();
        if (pid < 0) {
            // Handle fork failure
            perror("Fork failed");
            return 1;
        } else if (pid == 0) {
            // Child process
            switch (i) {
                case 0:
                printf("Luke: Adjusting Sheilds...\n");
                    shield_power += 25;
                    printf("Luke: Shield power level now at %d%%\n", shield_power);
                    break;
                case 1:
                    printf("Han: Adjusting Sheilds...\n");
                    shield_power += 20;
                    printf("Han: Shield power level now at %d%%\n", shield_power);
                    break;
                case 2:
                    printf("Chewbacca: Adjusting Sheilds...\n");
                    shield_power += 30;
                    printf("Chewbacca: Shield power level now at %d%%\n", shield_power);
                    break;
                case 3:
                    printf("Leia: Adjusting Sheilds...\n");
                    shield_power += 15;
                    printf("Leia: Shield power level now at %d%%\n", shield_power);
                    break;
            }
            return 0; // Child process exits after adjusting shield power
        }
            // Parent process continues to create next child process
            // Each character adjusts the shield power as follows:

            // Luke increases the shield power by 25
            // Han increases the shield power by 20
            // Chewbacca increases the shield power by 30
            // Leia increases the shield power by 15
            // -----> Write you code here
            
               

    // Check if process creation failed
        // -----> Write you code here 

    // Make parent process wait for all child processes to complete
        // -----> Write you code here 
    for (int j = 0; j < 4; j++) {
        wait(NULL);
    }


    // Parent process reports final state
    printf("\nFinal shield power level on the Millennium Falcon: %d%%\n", shield_power);
    printf("\nMay the forks be with you!\n");
    return 0;
}

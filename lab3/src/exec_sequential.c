#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int main(int argc, char *argv[]) {
    if (argc != 3) {
        printf("Usage: %s <seed> <array_size>\n", argv[0]);
        printf("Example: %s 42 1000\n", argv[0]);
        return 1;
    }

    pid_t pid = fork();
    
    if (pid == -1) {
        perror("fork failed");
        return 1;
    }
    else if (pid == 0) {
        printf("Child process: Starting sequential_min_max...\n");
        
        execl("./sequential_min_max", "sequential_min_max", argv[1], argv[2], NULL);
        
        perror("execl failed");
        return 1;
    }
    else {
        printf("Parent process: PID = %d, Child PID = %d\n", getpid(), pid);
        printf("Waiting for child process to complete...\n");
        
        int status;
        waitpid(pid, &status, 0);
        
        if (WIFEXITED(status)) {
            printf("Child process exited with status: %d\n", WEXITSTATUS(status));
        } else {
            printf("Child process terminated abnormally\n");
        }
        
        printf("Parent process: Done!\n");
    }
    
    return 0;
}
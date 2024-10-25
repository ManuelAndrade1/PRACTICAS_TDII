#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <fcntl.h>
#include <assert.h>
#include <sys/wait.h>
#include <sys/stat.h>

int p1();
int p2();
int p3();
int p4();
int main() {
    p1();
    p2();
    p3();
    p4();
    return 0;
}

int p1() {
    printf("hello world (pid:%d)\n", (int)getpid());
    int rc = fork();
    if (rc < 0) {
        // fork failed, exit
        fprintf(stderr, "fork failed\n");
        exit(1);
    }
    else if (rc == 0) {
        // child (new process)
        printf("hello . I am child (pid:%d)\n", (int)getpid());
    }
    else {
        // parent goes down this path (original process)
        printf("hello. I am parent of %d (pid:%d)\n", rc, (int)getpid());
    }
    return 0;
}

int p2() {
    printf("hello world (pid:%d)\n", (int)getpid());
    int rc = fork();
    if (rc < 0) {
        // fork failed, exit
        fprintf(stderr, "fork failed\n");
        exit(1);
    }
    else if (rc == 0) {
        // child (new process)
        printf("hello . I am child (pid:%d)\n", (int)getpid());
        sleep(1);
    }
    else {
        // parent goes down this path (original process)
        int wc = wait(NULL);
        printf("hello. I am parent of %d (wc:%d) (pid:%d)\n", rc, wc, (int)getpid());
    }
    return 0;    
}

int p3() {
    printf("hello world (pid:%d)\n", (int)getpid());
    int rc = fork();
    if (rc < 0) {
        // fork failed, exit
        fprintf(stderr, "fork failed\n");
        exit(1);
    }
    else if (rc == 0) {
        // child (new process)
        printf("hello . I am child (pid:%d)\n", (int)getpid());
        char* myargs[3];
        myargs[0] = strdup("wc"); // program: "wc" (word count)
        myargs[1] = strdup("p3.c"); // argument: file to count
        myargs[2] = NULL; // marks end of array
        execvp(myargs[0], myargs);
        printf("this shouln't print out.");
    }
    else {
        // parent goes down this path (original process)
        int wc = wait(NULL);
        printf("hello. I am parent of %d (wc:%d) (pid:%d)\n", rc, wc, (int)getpid());
    }
    return 0;
}

int p4(int argc, char* argv[]) {
    int rc = fork();
    if (rc < 0) {
        // fork failed, exit
        fprintf(stderr, "fork failed\n");
        exit(1);
    }
    else if (rc == 0) {
        // chil: redirect standard output to a file
        close(STDOUT_FILENO);
        open ("./p4.output", O_CREAT|O_WRONLY|O_TRUNC,  S_IRWXU);


        // new exec "wc..."
        char* myargs[3];
        myargs[0] = strdup("wc"); // program: "wc" (word count)
        myargs[1] = strdup("p4.c"); // argument: file to count
        myargs[2] = NULL; // marks end of array
        execvp(myargs[0], myargs); // runs word count
    }
    else {
        // parent goes down this path (original process)
        int wc = wait(NULL);
        assert(wc >= 0);
    }
    return 0;
}
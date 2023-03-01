#include <unistd.h>
#include <signal.h>
#include <stdlib.h>
#include <stdio.h>

void sighandler(int sig) {
    printf("receievd : %d\n", sig);

    sleep(3); //3 secs
}

int main() {
    struct sigaction sa;
    sigemptyset(&sa.sa_mask);
    sigaddset(&sa.sa_mask, SIGQUIT); //Block SIGQUIT signal when handler working on.

    sa.sa_flags = 0;
    sa.sa_handler = sighandler;

    if(sigaction(SIGINT, &sa, (struct sigaction*)NULL) < 0) {
        perror("sa <0");
        exit(1);
    }

    pause(); //wait for some signal
    
    //if signal sent this process that is SIGINT -> handler works

    //Block my SIGQUIT signal when 'sleep()'

    //After function completed, blocked signals sent.
    //program goes on.

    return 0;
}
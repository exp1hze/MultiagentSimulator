#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main(int argc, char **argv)  
   {
      char cmd[100];
      sprintf(cmd, "sed -i 's/^%s .*$/%s   %s/' params", argv[1], argv[1], argv[2]);
      printf("cmd: %s\n", cmd);
      system(cmd);
      return 0;
   }
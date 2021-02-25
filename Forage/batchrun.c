#include <stdio.h>
#include <stdlib.h>

int main()
   {
   FILE *fp;
   char filename[200];
   char command[500];
   int i;
   double response_prob;
   int error;

   response_prob = 1.0;

   sprintf(filename, "params");

   for (i=100; i>1; i-=5)
      {
      fp = fopen(filename, "w");
      fprintf(fp, "Response_prob  %lf", response_prob);
      fclose(fp);
      response_prob -= 0.05;
      sprintf(command, "source go100");
      //sprintf(command, "echo hello" );
      error = system(command);
      }

   return 0;
   }

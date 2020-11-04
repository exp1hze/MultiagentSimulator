#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main(void)
   {
   int i, j, k;
   char cmd[50];

   // Constant parameters
   int pop_size = 50;
   int num_steps = 500;
   int max_thresh_range = 10;
   double thresh_decrease = 0.1;
   double thresh_increase = .033;

   // Dynamic Thresholds
   int num_thresh = 4;
   int thresh[4] = {0, 1, 2, 3};
   int cur_thresh;

   // Experiment parameters
   int num_step_ratio = 7;
   double step_ratio[] = {0.8, 1.0, 1.2, 1.4, 1.6, 1.8, 2.0};
   double cur_step_ratio;
   
   // Target variations
   int num_sub = 4;
   char sub_directory[4][25];
   
   sprintf(sub_directory[0], "random-zigzag");
   sprintf(sub_directory[1], "random-scurve");
   sprintf(sub_directory[2], "urgent-zigzag");
   sprintf(sub_directory[3], "urgent-scurve"); 

   // Create directories
   for (i=0; i<num_step_ratio; i++)
      {
         cur_step_ratio = step_ratio[i];
         sprintf(cmd, "mkdir Output/%.1lf", cur_step_ratio);
         system(cmd);
         for (j=0;j<num_thresh; j++)
            {
            cur_thresh = thresh[j];
            sprintf(cmd, "mkdir Output/%.1lf/%d", cur_step_ratio, cur_thresh);
            system(cmd);
            for (k=0; k<num_sub; k++)
               {
               sprintf(cmd, "mkdir Output/%.1lf/%d/%s", cur_step_ratio, 
                                       cur_thresh, sub_directory[k]);
               system(cmd);
               }
            }
      } 

      // Compile regex generator
      sprintf(cmd, "gcc regex.c -o replace");
      system(cmd);

      // Secure constant parameters
      sprintf(cmd, "./replace Pop_size %d", pop_size);
      system(cmd);
      sprintf(cmd, "./replace Max_steps %d", num_steps);
      system(cmd);
      sprintf(cmd, "./replace Range %d", max_thresh_range);
      system(cmd);
      sprintf(cmd, "./replace Thresh_increase %.3lf", thresh_increase);
      system(cmd);
      sprintf(cmd, "./replace Thresh_decrease %.1lf", thresh_decrease);
      system(cmd);

      // Run experiments
      for (i=0; i<num_step_ratio; i++)
         {
         // Set expt parameters
         sprintf(cmd, "./replace Step_ratio %.1lf", step_ratio[i]);
         system(cmd);

         for (j=0; j<num_thresh; j++)
            {
            // Set threshold
            sprintf(cmd, "./replace Thresh_dynamic %d", thresh[j]);
            system(cmd);
            for (k=0; k<num_sub; k++)
               {
               if (!strcmp(sub_directory[k], "random-zigzag"))
                  {
                  sprintf(cmd, "./replace Target_path zigzag");
                  system(cmd);
                  sprintf(cmd, "./replace Task_selection random");
                  system(cmd);
                  }
               else if (!strcmp(sub_directory[k], "random-scurve"))
                  {
                  sprintf(cmd, "./replace Target_path scurve");
                  system(cmd);
                  sprintf(cmd, "./replace Task_selection random");
                  system(cmd);
                  }
               else if (!strcmp(sub_directory[k], "urgent-zigzag"))
                  {
                  sprintf(cmd, "./replace Target_path zigzag");
                  system(cmd);
                  sprintf(cmd, "./replace Task_selection urgent");
                  system(cmd);
                  }
               else if (!strcmp(sub_directory[k], "urgent-scurve"))
                  {
                  sprintf(cmd, "./replace Target_path scurve");
                  system(cmd);
                  sprintf(cmd, "./replace Task_selection urgent");
                  system(cmd);
                  }
           
               system("./run10.sh");
               //system("cat run.num.0 > run.num");
               
               // Move to results directory
               sprintf(cmd, "mv Output/run* Output/%.1lf/%d/%s",
                              step_ratio[i], thresh[j], sub_directory[k]);
               system(cmd);
               } 
            }
         }
   return 0;
   }
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define ERROR 0
#define OK 1

void set_run_num(int start_num);
void print_params_file(char *expt_directory, char *target_path,
                       int thresh_dynamic, double step_ratio, int popsize);
void do_runs(int number_of_runs);
void process_data(int index, int num_runs, char *expt_dir);
void print_gnuplot_file(int num_runs, char *expt_dir);

int main(int argc, char **argv)
   {
   int start_run_num;
   int number_of_runs;
   char expt_directory[200];  // where data+gnuplot files generated get put.
                              // assumes non-existent, program makes directory
   char cmd[300];
   int thresh_dynamic;
   double step_ratio;
   char target_path[100];
   int index;
   int popsize;

   if (argc < 9)
      {
      printf(" Usage: %s <start_run_num> <number of runs per expt> <expt directory> <thresh dynamic> <step ratio> <target path> <index> <popsize>\n",
		argv[0]);
      return ERROR;
      }  /* if */
   sscanf(argv[1], "%d", &start_run_num);
   sscanf(argv[2], "%d", &number_of_runs);
   sscanf(argv[3], "%s", expt_directory);
   sscanf(argv[4], "%d", &thresh_dynamic);
   sscanf(argv[5], "%lf", &step_ratio);
   sscanf(argv[6], "%s", target_path);
   sscanf(argv[7], "%d", &index);
   sscanf(argv[8], "%d", &popsize);
   printf(" Start run_num:  %s  %d\n", argv[1], start_run_num);
   printf(" Number of runs per experiment:  %s  %d\n", argv[2], number_of_runs);
   printf(" Experiment directory:  %s  %s\n", argv[3], expt_directory);
   printf(" Thresh dynamic setting:  %s  %d\n", argv[4], thresh_dynamic);
   printf(" Step ratio:  %s  %lf\n", argv[5], step_ratio);
   printf(" Target path:  %s  %s\n", argv[6], target_path);
   printf(" Index:  %s  %d\n", argv[7], index);
   printf(" Population size:  %s  %d\n", argv[8], popsize);

   // set up run.num file
   set_run_num(start_run_num);

   // print params file
   print_params_file(expt_directory, target_path, thresh_dynamic, step_ratio,
		popsize);

   // make directory in which to put the data and the gnuplot files
   sprintf(cmd, "mkdir %s", expt_directory);
   printf(" Executing system command:  %s\n", cmd);
   system(cmd);

   // do runs
   do_runs(number_of_runs);

   // process data for gnuplot
   process_data(index, number_of_runs, expt_directory);

   // print gnuplot file
   print_gnuplot_file(number_of_runs, expt_directory);

   return OK;
   }

void set_run_num(int start_num)
   {
   FILE *fp;
   fp = fopen("run.num", "w");
   fprintf(fp, "%d\n", start_num);
   fclose(fp);
   }

void print_params_file(char *expt_directory, char *target_path,
                       int thresh_dynamic, double step_ratio, int popsize)
   {
   FILE *fp;
   fp = fopen("params", "w");
   fprintf(fp, "Rerun           -1\n");
   fprintf(fp, "Output_path     %s\n", expt_directory);
   fprintf(fp, "Max_steps       500\n");
   fprintf(fp, "Pop_size        %d\n", popsize);
   fprintf(fp, "Thresh_dynamic  %d\n", thresh_dynamic);
   fprintf(fp, "Target_path     %s\n", target_path);
   fprintf(fp, "Path_amplitude  40\n");
   fprintf(fp, "Path_period     80\n");
   fprintf(fp, "Step_ratio      %lf\n", step_ratio);
   fprintf(fp, "Gnuplot_plots   0\n");
   fclose(fp);
   }

void do_runs(int number_of_runs)
   {
   int i;

   for (i=0; i<number_of_runs; i++)
      {
      system("./sim params opfiles");
      }
   }

void process_data(int index, int number_of_runs, char *expt_dir)
   {
   char cmd[500];
   char datafile[100];
   char tempstring[200];
   FILE *fp;
   FILE *fpout;
   int i;      // counts runs
   double *avg_diff;
   double *max_diff;
   double *min_diff;
   double *avg_switch;
   double *max_switch;
   double *min_switch;
   double *tracker_path;
   double sum_avg_diff;
   double sum_max_diff;
   double sum_min_diff;
   double sum_avg_switch;
   double sum_max_switch;
   double sum_min_switch;
   double sum_tracker_path;
   double sd_avg_diff;
   double sd_max_diff;
   double sd_min_diff;
   double sd_avg_switch;
   double sd_max_switch;
   double sd_min_switch;
   double sd_tracker_path;
   double ci_avg_diff;
   double ci_max_diff;
   double ci_min_diff;
   double ci_avg_switch;
   double ci_max_switch;
   double ci_min_switch;
   double ci_tracker_path;

   // allocate space
   avg_diff = (double *)malloc(number_of_runs * sizeof(double));
   max_diff = (double *)malloc(number_of_runs * sizeof(double));
   min_diff = (double *)malloc(number_of_runs * sizeof(double));
   avg_switch = (double *)malloc(number_of_runs * sizeof(double));
   max_switch = (double *)malloc(number_of_runs * sizeof(double));
   min_switch = (double *)malloc(number_of_runs * sizeof(double));
   tracker_path = (double *)malloc(number_of_runs * sizeof(double));

   // init sum, stdev, ci
   sum_avg_diff = sd_avg_diff = ci_avg_diff = 0;
   sum_max_diff = sd_max_diff = ci_max_diff = 0;
   sum_min_diff = sd_min_diff = ci_min_diff = 0;
   sum_avg_switch = sd_avg_switch = ci_avg_switch = 0;
   sum_max_switch = sd_max_switch = ci_max_switch = 0;
   sum_min_switch = sd_min_switch = ci_min_switch = 0;
   sum_tracker_path = sd_tracker_path = ci_tracker_path = 0;

   // concatenate finalstats data into single file
   sprintf(datafile, "%s/finalstats.txt", expt_dir);
   sprintf(cmd, "cat %s/run.*/*.finalstats > %s\n", expt_dir, datafile);
   printf(" Executing system command:  %s\n", cmd);
   system(cmd);

   // open file to read
   fp = fopen(datafile, "r");

   // read in values and calculate average
   // loop thru number_of_runs rows of data and saves in arrays
   for (i=0; i<number_of_runs; i++)
      {
         fscanf(fp, "%s %s %s %s %s", 
                tempstring, tempstring, tempstring, tempstring, tempstring);
      fscanf(fp, "%lf", &tracker_path[i]);
      sum_tracker_path += tracker_path[i];
         fscanf(fp, "%s %s", tempstring, tempstring);
      fscanf(fp, "%lf", &avg_diff[i]);
      sum_avg_diff += avg_diff[i];
         fscanf(fp, "%s", tempstring);
      fscanf(fp, "%lf", &max_diff[i]);
      sum_max_diff += max_diff[i];
         fscanf(fp, "%s", tempstring);
      fscanf(fp, "%lf", &min_diff[i]);
      sum_min_diff += min_diff[i];
         fscanf(fp, "%s %s", tempstring, tempstring);
      fscanf(fp, "%lf", &avg_switch[i]);
      sum_avg_switch += avg_switch[i];
         fscanf(fp, "%s", tempstring);
      fscanf(fp, "%lf", &max_switch[i]);
      sum_max_switch += max_switch[i];
         fscanf(fp, "%s", tempstring);
      fscanf(fp, "%lf", &min_switch[i]);
      sum_min_switch += min_switch[i];

      printf(" %lf %lf %lf %lf %lf %lf %lf\n",
             tracker_path[i], avg_diff[i], max_diff[i], min_diff[i],
             avg_switch[i], max_switch[i], min_switch[i]);
      }  /* for i */

      sum_tracker_path = sum_tracker_path/number_of_runs;
      sum_avg_diff = sum_avg_diff/number_of_runs;
      sum_max_diff = sum_max_diff/number_of_runs;
      sum_min_diff = sum_min_diff/number_of_runs;
      sum_avg_switch = sum_avg_switch/number_of_runs;
      sum_max_switch = sum_max_switch/number_of_runs;
      sum_min_switch = sum_min_switch/number_of_runs;

   printf(" Avg:  %lf %lf %lf %lf %lf %lf %lf\n",
          sum_tracker_path, sum_avg_diff, sum_max_diff, sum_min_diff,
          sum_avg_switch, sum_max_switch, sum_min_switch);

   // Calculate stdev and 95% confidence interval
   for (i=0; i<number_of_runs; i++)
      {
      sd_tracker_path += (tracker_path[i] - sum_tracker_path) *
                          (tracker_path[i] - sum_tracker_path);
      sd_avg_diff += (avg_diff[i]-sum_avg_diff) * (avg_diff[i]-sum_avg_diff); 
      sd_max_diff += (max_diff[i]-sum_max_diff) * (max_diff[i]-sum_max_diff);
      sd_min_diff += (min_diff[i]-sum_min_diff) * (min_diff[i]-sum_min_diff);
      sd_avg_switch += (avg_switch[i] - sum_avg_switch) *
                       (avg_switch[i] - sum_avg_switch);
      sd_max_switch += (max_switch[i] - sum_max_switch) *
                       (max_switch[i] - sum_max_switch);
      sd_min_switch += (min_switch[i] - sum_min_switch) *
                       (min_switch[i] - sum_min_switch);

      sd_tracker_path = sd_tracker_path/(double)(number_of_runs - 1);
      sd_avg_diff = sqrt( sd_avg_diff/(double)(number_of_runs - 1) );
      sd_max_diff = sqrt( sd_max_diff/(double)(number_of_runs - 1) );
      sd_min_diff = sqrt( sd_min_diff/(double)(number_of_runs - 1) );
      sd_avg_switch = sqrt( sd_avg_switch/(double)(number_of_runs - 1) );
      sd_max_switch = sqrt( sd_max_switch/(double)(number_of_runs - 1) );
      sd_min_switch = sqrt( sd_min_switch/(double)(number_of_runs - 1) );

      // calculate 95% confidence interval, z = 1.96 for 95%
      ci_tracker_path = 1.96 * sd_tracker_path / sqrt((double)number_of_runs);
      ci_avg_diff = 1.96 * sd_avg_diff / sqrt((double)number_of_runs);
      ci_max_diff = 1.96 * sd_max_diff / sqrt((double)number_of_runs);
      ci_min_diff = 1.96 * sd_min_diff / sqrt((double)number_of_runs);
      ci_avg_switch = 1.96 * sd_avg_switch / sqrt((double)number_of_runs);
      ci_max_switch = 1.96 * sd_max_switch / sqrt((double)number_of_runs);
      ci_min_switch = 1.96 * sd_min_switch / sqrt((double)number_of_runs);
      }   /* for i */

   printf(" SD:   %lf %lf %lf %lf %lf %lf %lf\n",
          sd_tracker_path, sd_avg_diff, sd_max_diff, sd_min_diff,
          sd_avg_switch, sd_max_switch, sd_min_switch);
   printf(" CI:   %lf %lf %lf %lf %lf %lf %lf\n",
          ci_tracker_path, ci_avg_diff, ci_max_diff, ci_min_diff,
          ci_avg_switch, ci_max_switch, ci_min_switch);

   // print to file for plotting
   sprintf(cmd, "%s/tracker_path", expt_dir);
   fpout = fopen(cmd, "w");
   fprintf(fpout, " %d %s avg %lf sd %lf ci %lf\n", 
          index, expt_dir,
          sum_tracker_path, sd_tracker_path, ci_tracker_path);
   fclose(fpout);
   sprintf(cmd, "%s/diff", expt_dir);
   fpout = fopen(cmd, "w");
   fprintf(fpout, " %d %s avg_diff avg %lf sd %lf ci %lf", 
          index, expt_dir,
          sum_avg_diff, sd_avg_diff, ci_avg_diff);
   fprintf(fpout, " max_diff avg %lf sd %lf ci %lf",
          sum_max_diff, sd_max_diff, ci_max_diff);
   fprintf(fpout, " min_diff avg %lf sd %lf ci %lf\n",
          sum_min_diff, sd_min_diff, ci_min_diff);
   fclose(fpout);
   sprintf(cmd, "%s/switch", expt_dir);
   fpout = fopen(cmd, "w");
   fprintf(fpout, " %d %s avg_switch avg %lf sd %lf ci %lf", 
          index, expt_dir,
          sum_avg_switch, sd_avg_switch, ci_avg_switch);
   fprintf(fpout, " max_switch avg %lf sd %lf ci %lf",
          sum_max_switch, sd_max_switch, ci_max_switch);
   fprintf(fpout, " min_switch avg %lf sd %lf ci %lf\n",
          sum_min_switch, sd_min_switch, ci_min_switch);
   fclose(fpout);

   // free space and close buffers
   free(avg_diff);
   free(max_diff);
   free(min_diff);
   free(avg_switch);
   free(max_switch);
   free(min_switch);
   free(tracker_path);
   fclose(fp);
   }

void print_gnuplot_file(int num_runs, char *expt_dir)
   {
   }

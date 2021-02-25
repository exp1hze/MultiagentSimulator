/* Created:	10.03.03.AW
   Actions:	print gnuplot files for plotting multiple run data. 
*/
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define DROP125

void get_stepnest_averages(int start_run, int end_run, int max_steps, 
                           char prefi[]);
void get_agent_averages(int start_run, int end_run, int pop_size,
                        char prefix[]);
void get_nest_averages(int start_run, int end_run, int max_steps, 
			int pop_size, char prefix[]);
void get_avg_actors_per_step(int run_num, int max_steps, int pop_size);

int main(int argc, char **argv)
   {
   FILE *fp;
   int start_run, end_run;
   int pop_size, max_steps;
   int i;
   char prefix[200];

   if (argc < 6)
      {
      printf(" Usage: %s <start run> <end run> <pop_size> <max_steps> <outfile prefix>\n",
                argv[0]);
      printf(" Check that hard coded Need value is correct (for calculating need met per step).\n");
      return 0;
      }  /* if */

   sscanf(argv[1], "%d", &start_run);
   sscanf(argv[2], "%d", &end_run);
   sscanf(argv[3], "%d", &pop_size);
   sscanf(argv[4], "%d", &max_steps);
   sscanf(argv[5], "%s", prefix);
   printf(" start run: %s %d\n", argv[1], start_run);
   printf(" end run: %s %d\n", argv[2], end_run);
   printf(" pop size: %s %d\n", argv[3], pop_size);
   printf(" max steps: %s %d\n", argv[4], max_steps);
   printf(" prefix: %s %s\n", argv[5], prefix);

   fp = fopen("plot.gnu", "w");

   fprintf(fp, "set term post eps color\n");
   fprintf(fp, "set xlabel \"Agent\"\n");
   fprintf(fp, "unset key\n");

   ///////// x axis is Agent

   // plot number of trials that each agent got
   fprintf(fp, "\n");
   fprintf(fp, "set output \"%s_numtrials.eps\"\n", prefix);
   fprintf(fp, "set ylabel \"Number of learning trials\"\n");
   fprintf(fp, "plot [][-5:]\\\n");
   for (i=start_run; i<end_run; i++)
      {
      fprintf(fp, "   \"../Output/run.%d/run.%d.path\" using 1:2 w line,\\\n",
                i, i);
      }
   fprintf(fp, "   \"../Output/run.%d/run.%d.path\" using 1:2 w line\n",
        end_run, end_run);

   // plot average path length for each agent
   fprintf(fp, "\n");
   fprintf(fp, "set output \"%s_pathlen.eps\"\n", prefix);
   fprintf(fp, "set ylabel \"Avg path length\"\n");
   fprintf(fp, "plot [][0:]\\\n");
   for (i=start_run; i<end_run; i++)
      {
      fprintf(fp, "   \"../Output/run.%d/run.%d.path\" using 1:3 w line,\\\n",
		i, i);
      }
   fprintf(fp, "   \"../Output/run.%d/run.%d.path\" using 1:3 w line\n",
	end_run, end_run);

   // plot average successful path length for each agent
   fprintf(fp, "\n");
   fprintf(fp, "set output \"%s_successfulpathlen.eps\"\n", prefix);
   fprintf(fp, "set ylabel \"Avg successful path length\"\n");
   fprintf(fp, "plot [][0:]\\\n");
   for (i=start_run; i<end_run; i++)
      {
      fprintf(fp, "   \"../Output/run.%d/run.%d.path\" using 1:4 w line,\\\n",
                i, i);
      }
   fprintf(fp, "   \"../Output/run.%d/run.%d.path\" using 1:4 w line\n",
        end_run, end_run);

   // plot average success rate for each agent (trials found food/total trials)
   fprintf(fp, "\n");
   fprintf(fp, "set output \"%s_numsuccesses.eps\"\n", prefix);
   fprintf(fp, "set ylabel \"Number of  successes\"\n");
   fprintf(fp, "plot [][:]\\\n");
   for (i=start_run; i<end_run; i++)
      {
      fprintf(fp, "   \"../Output/run.%d/run.%d.path\" using 1:5 w line,\\\n",
                i, i);
      }
   fprintf(fp, "   \"../Output/run.%d/run.%d.path\" using 1:5 w line\n",
        end_run, end_run);



   // calculate the average of all of the values and print to a file called
   // "data_agent_average.dat".
   get_agent_averages(start_run, end_run, pop_size, prefix);

   // print gnuplot commands to plot this average data.
   // numtrials
   fprintf(fp, "\n");
   fprintf(fp, "set output \"%s_average_numtrials.eps\"\n", prefix);
   fprintf(fp, "set ylabel \"Number of learning trials\"\n");
   fprintf(fp, "plot [:%d][-5:] \"%s_data_agent_average.dat\" using 1:2:3 w yerr,\\\n", pop_size, prefix);
   fprintf(fp, "   \"%s_data_agent_average.dat\" using 1:2 w line lt 1\n",
           prefix);
   // pathlen
   fprintf(fp, "\n");
   fprintf(fp, "set output \"%s_average_pathlen.eps\"\n", prefix);
   fprintf(fp, "set ylabel \"Avg path length\"\n");
   fprintf(fp, "plot [:%d][0:] \"%s_data_agent_average.dat\" using 1:4:5 w yerr,\\\n", pop_size, prefix);
   fprintf(fp, "   \"%s_data_agent_average.dat\" using 1:4 w line lt 1\n",
           prefix);
   // successful path length 
   fprintf(fp, "\n");
   fprintf(fp, "set output \"%s_average_successfulpathlen.eps\"\n", prefix);
   fprintf(fp, "set ylabel \"Avg successful path length\"\n");
   fprintf(fp, "plot [:%d][0:] \"%s_data_agent_average.dat\" using 1:6:7 w yerr,\\\n", pop_size, prefix);
   fprintf(fp, "   \"%s_data_agent_average.dat\" using 1:6 w line lt 1\n",
           prefix);
   // success rate 
   fprintf(fp, "\n");
   fprintf(fp, "set output \"%s_average_numsuccesses.eps\"\n", prefix);
   fprintf(fp, "set ylabel \"Avg num successes\"\n");
   fprintf(fp, "plot [:%d][] \"%s_data_agent_average.dat\" using 1:8:9 w yerr,\\\n", pop_size, prefix);
   fprintf(fp, "   \"%s_data_agent_average.dat\" using 1:8 w line lt 1\n",
           prefix);

   // calculate single average values for nest data
   get_nest_averages(start_run, end_run, max_steps, pop_size, prefix);



   ///////// x axis is Step

   // calculate the average of step nest data and print to a file called
   // "data_nest_average.dat".
   get_stepnest_averages(start_run, end_run, max_steps, prefix);
 
   // print gnuplot commands to plot step nest data from "data_nest_average.dat".
   fprintf(fp, "\n");
   fprintf(fp, "set output \"%s_average_stepnest.eps\"\n", prefix);
   fprintf(fp, "set ylabel \"Avg food income\"\n");
   fprintf(fp, "set xlabel \"Step\"\n");
   fprintf(fp, "plot [][0:20] \"%s_data_nest_average.dat\" using 1:4:6 w yerr,\\\n",
           prefix);
   fprintf(fp, "   \"%s_data_nest_average.dat\" using 1:4 w line lt 1 lc 3\n",
           prefix);

   // plot food income per step for all runs.
   fprintf(fp, "\n");
   fprintf(fp, "set output \"%s_stepnest.eps\"\n", prefix);
   fprintf(fp, "set ylabel \"Food income\"\n");
   fprintf(fp, "set xlabel \"Step\"\n");
   fprintf(fp, "plot [][:]\\\n");
   for (i=start_run; i<end_run; i++)
      {
      fprintf(fp, "   \"../Output/run.%d/run.%d.stepnest\" using 1:3 w line,\\\n",
                i, i);
      }
   fprintf(fp, "   \"../Output/run.%d/run.%d.stepnest\" using 1:3 w line\n",
        end_run, end_run);

   }

// calculate the average of step nest data and print to a file called
// "data_nest_average.dat".
void get_stepnest_averages(int start_run, int end_run, int max_steps, char prefix[])
   {
   FILE *fp;
   char filename[200];
   char tempstring[200];
   int t; 		// count steps/cycles
   int r;		// count runs
   int num_runs, index;
   double z;		// for calculating CI
   double **data;
   double *average;
   double *stdev;
   double *ci;
#ifdef DROP125
   // variables for calculating drop and time to recover, hard coded
   double drop;
   double before_drop, after_drop;
   int time_to_recover;
   int i;
   double avg_total_food;
   // variables to read in existing file data to reprint back to file with
   // newly calculated data
   double sd_total_food;
   double avg_closest_food;
   double sd_closest_food;
   char string_total_food[100];
   char string_closest_food[100];
   double avg_avg_actors_per_step;
   double stdev_avg_actors_per_step;
   double avg_steps_need_met;
   double stdev_steps_need_met;
 //  int need_met;
   char string_actors[100];
   char string_need[100];
#endif

   num_runs = end_run - start_run + 1;

   data = (double **)malloc(num_runs * sizeof(double *) );
   for (r=0; r<num_runs; r++)
      {
      data[r] = (double *)malloc(max_steps * sizeof(double) );
      }
   average = (double *)malloc(max_steps * sizeof(double) );
   stdev = (double *)malloc(max_steps * sizeof(double) );
   ci = (double *)malloc(max_steps * sizeof(double) );

   for (t=0; t<max_steps; t++)
      {
      average[t] = 0;
      stdev[t] = 0;
      ci[t] = 0;
      }

   for (r=0; r<num_runs; r++)
      {
      sprintf(filename, "../Output/run.%d/run.%d.stepnest", 
		r+start_run, r+start_run);
      fp = fopen(filename, "r");

      for (t=0; t<max_steps; t++)
         {
         fscanf(fp, "%d %s %lf %s %s", &index, tempstring, &data[r][t],
		tempstring, tempstring);
         average[t] += data[r][t];
         }

      fclose(fp);
      }

   // calculate average
   for (t=0; t<max_steps; t++)
      {
      average[t] /= num_runs;
      }

   // calculate standard deviation and confidence interval
   z = 1.96;		// 1.96 for 95% CI, 2.57 for 99% CI
   for (t=0; t<max_steps; t++)
      {
      for (r=0; r<num_runs; r++)
         {
         stdev[t] += (data[r][t] - average[t]) * (data[r][t] - average[t]) ;
         }
      stdev[t] = sqrt(stdev[t]/(double)num_runs);
      ci[t] = z * stdev[t]/sqrt( (double)num_runs );
      }

   sprintf(filename, "%s_data_nest_average.dat", prefix);
   fp = fopen(filename, "w");
   for (t=0; t<max_steps; t++)
      {
      fprintf(fp, " %4d food_income avg %lf ci %lf stdev %lf\n", 
		t,
		average[t],
		ci[t],
		stdev[t]);
      }
   fclose(fp);

   //get_avg_actors_per_step(run_num, max_steps, pop_size);

#ifdef DROP125
   // calculate drop and time to recover
   // hard coded to drop happening between step 249 and 250
   before_drop = average[249];
   after_drop = average[250];
   drop = before_drop - after_drop;
printf(" before %lf after %lf drop %lf\n", before_drop, after_drop, drop);
   i = 250;
   while (average[i] < before_drop)  i++;
   time_to_recover = i - 250;
   printf(" Drop %lf, time to recover %d (from 250 to %d)\n",
          drop, time_to_recover, i);
   printf(" 249 - %lf\n", average[249]);
   printf(" 250 - %lf\n", average[250]);
   printf(" %d - %lf\n", i-1, average[i-1]);
   printf(" %d - %lf\n", i, average[i]);
   printf(" %d - %lf\n", i+1, average[i+1]);

   // print to file
   sprintf(filename, "%s_printed_results.txt", prefix);
   fp = fopen(filename, "a");
   fprintf(fp, " Drop %lf, time to recover %d (from 125 to %d)\n",
          drop, time_to_recover, i);
   fclose(fp);

   // print to file for gnuplot
   sprintf(filename, "%s_plot_results.txt", prefix);
   // first, read avg_total_food value from file
   fp = fopen(filename, "r");
   fscanf(fp, "%s %lf %lf %s %lf %lf %s %lf %lf %s %lf %lf",
	string_closest_food, &avg_closest_food, &sd_closest_food, 
	string_total_food, &avg_total_food, &sd_total_food,
	string_actors, &avg_avg_actors_per_step, &stdev_avg_actors_per_step,
	string_need, &avg_steps_need_met, &stdev_steps_need_met);
   fclose(fp);
   // then print
   fp = fopen(filename, "w");
   fprintf(fp, " %s ", prefix);
   fprintf(fp, " %s %lf %lf %s %lf %lf",
	string_closest_food, avg_closest_food, sd_closest_food, 
	string_total_food, avg_total_food, sd_total_food);
   fprintf(fp, " %s %lf %lf %s %lf %lf",
	string_actors, avg_avg_actors_per_step, stdev_avg_actors_per_step,
	string_need, avg_steps_need_met, stdev_steps_need_met);
   fprintf(fp, " drop %lf ttrecover %d", drop, time_to_recover);
   fprintf(fp, " avg_total_food/drop %lf", avg_total_food/drop);
   fprintf(fp, " avg_total_food/ttrecover %lf",
           avg_total_food/(double)time_to_recover );
   fprintf(fp, " after_drop %lf\n", after_drop);

   fclose(fp);
#endif
   }  /* get_stepnest_averages */

/* get average number of actors per step for entire run:
   count number of actors in each step and average over all steps */
void get_avg_actors_per_step(int run_num, int max_steps, int pop_size)
   {
   double avg_actors;	// avg number of actors per step over all steps
   double stdev_actors;
   int p;		// counts population members
   int t;		// counts steps
   int *count;		// save number of actors in each step
   int step_num, agent_num, acted;
   char tempstring[100];
   char filename[100];
   FILE *fp;
   int need_met;	// number of steps in which needed num actors met
   int need = 20;	// hard coded!!  May need to add as variable

   count = (int *)malloc(max_steps * sizeof(int));

   sprintf(filename, "../Output/run.%d/run.%d.stepdistance", run_num, run_num);
   fp = fopen(filename, "r");
   avg_actors = 0;
   stdev_actors = 0;
   need_met = 0;
   // calculate average and count number of steps where need is met
   for (t=0; t<max_steps; t++)
      {
      // count number of actors
      count[t] = 0;
      fscanf(fp, "%d", &step_num);	// read in step number
      for (p=0; p<pop_size; p++)
         {
         fscanf(fp, "%s %d %d", tempstring, &agent_num, &acted);
         if (acted > 0)  count[t]++;
         }
      if (count[t] >= need)  need_met++;
      avg_actors += count[t];
      }
   fclose(fp);
   avg_actors = avg_actors/max_steps;

   // calculate stdev
   for (t=0; t<max_steps; t++)
      {
      stdev_actors = (count[t] - avg_actors) * (count[t] - avg_actors);
      }
   stdev_actors = sqrt(stdev_actors/(double)max_steps);

   fp = fopen("tempfile", "w");
   fprintf(fp, " actors_per_step_avg_sd %lf %lf steps_with_need_met %d\n", 
		avg_actors, stdev_actors, need_met);
   fclose(fp);
   }  /* get_avg_actors_per_step */

void get_agent_averages(int start_run, int end_run, int pop_size, char prefix[])
   {
   FILE *fp;
   char filename[200];
   int r;		// count runs
   int n;		// count agents
   int index;
   int num_runs;
   double z;		// for confidence interval calculation
   // store data read in (row = run_num, col = agent_num
   double **data_num_times_acted;
   double **data_avg_path_len;
   double **data_avg_successful_path_len;
   double **data_num_successes;
   // count how many runs to average for each agents for their
   // path_len and successful_path_len data
   int *avg_path_len_count;		// # runs in whch agent tried paths 
   int *avg_successful_path_len_count;	// # runs agent had successful paths 
   // sum up values for calculating stdev
   double *sum_num_times_acted;
   double *sum_avg_path_len;
   double *sum_avg_successful_path_len;
   double *sum_num_successes;
   // sum values for calculating averages and store averages
   double *avg_num_times_acted;
   double *avg_avg_path_len;
   double *avg_avg_successful_path_len;
   double *avg_num_successes;
   // stdev calculated
   double *stdev_num_times_acted;
   double *stdev_avg_path_len;
   double *stdev_avg_successful_path_len;
   double *stdev_num_successes;
   // confidence interval calculated
   double *ci_num_times_acted;
   double *ci_avg_path_len;
   double *ci_avg_successful_path_len;
   double *ci_num_successes;

   // calculate number of runs of data to average
   num_runs = end_run - start_run + 1;

   // allocate space
   avg_path_len_count = (int *)malloc(pop_size * sizeof(int) );
   avg_successful_path_len_count = (int *)malloc(pop_size * sizeof(int) );
   sum_num_times_acted = (double *)malloc(pop_size * sizeof(double) );
   sum_avg_path_len = (double *)malloc(pop_size * sizeof(double) );
   sum_avg_successful_path_len = (double *)malloc(pop_size * sizeof(double) );
   sum_num_successes = (double *)malloc(pop_size * sizeof(double) );
   avg_num_times_acted = (double *)malloc(pop_size * sizeof(double) );
   avg_avg_path_len = (double *)malloc(pop_size * sizeof(double) );
   avg_avg_successful_path_len = (double *)malloc(pop_size * sizeof(double) );
   avg_num_successes = (double *)malloc(pop_size * sizeof(double) );
   stdev_num_times_acted = (double *)malloc(pop_size * sizeof(double) );
   stdev_avg_path_len = (double *)malloc(pop_size * sizeof(double) );
   stdev_avg_successful_path_len = (double *)malloc(pop_size * sizeof(double) );
   stdev_num_successes = (double *)malloc(pop_size * sizeof(double) );
   ci_num_times_acted = (double *)malloc(pop_size * sizeof(double) );
   ci_avg_path_len = (double *)malloc(pop_size * sizeof(double) );
   ci_avg_successful_path_len = (double *)malloc(pop_size * sizeof(double) );
   ci_num_successes = (double *)malloc(pop_size * sizeof(double) );

   data_num_times_acted = (double **)malloc(num_runs * sizeof(double *) );
   data_avg_path_len = (double **)malloc(num_runs * sizeof(double *) );
   data_avg_successful_path_len = (double **)malloc(num_runs*sizeof(double *) );
   data_num_successes = (double **)malloc(num_runs * sizeof(double *) );
   for (r=0; r<num_runs; r++)
      {
      data_num_times_acted[r] = (double *)malloc(pop_size * sizeof(double) );
      data_avg_path_len[r] = (double *)malloc(pop_size * sizeof(double) );
      data_avg_successful_path_len[r]=(double *)malloc(pop_size*sizeof(double));
      data_num_successes[r] = (double *)malloc(pop_size * sizeof(double) );
      }

   // initialize to zero
   for (n=0; n<pop_size; n++)
      {
      avg_path_len_count[n] = 0;
      avg_successful_path_len_count[n] = 0;
      sum_num_times_acted[n] = 0;
      sum_avg_path_len[n] = 0;
      sum_avg_successful_path_len[n] = 0;
      sum_num_successes[n] = 0;
      avg_num_times_acted[n] = 0;
      avg_avg_path_len[n] = 0;
      avg_avg_successful_path_len[n] = 0;
      avg_num_successes[n] = 0;
      }

   // read in data, sum values in prep for calculating average
   for (r=0; r<num_runs; r++)
      {
      sprintf(filename, "../Output/run.%d/run.%d.path", 
		r+start_run, r+start_run);
      fp = fopen(filename, "r");

      for (n=0; n<pop_size; n++)
         {
         fscanf(fp, "%d %lf %lf %lf %lf",
		&index,
		&data_num_times_acted[r][n],
		&data_avg_path_len[r][n],
		&data_avg_successful_path_len[r][n],
		&data_num_successes[r][n]);

         avg_num_times_acted[n] += data_num_times_acted[r][n];
         if (data_avg_path_len[r][n] >= 0)
            {
            avg_avg_path_len[n] += data_avg_path_len[r][n];
            avg_path_len_count[n]++;
            }
         if (data_avg_successful_path_len[r][n] >= 0)
            {
            avg_avg_successful_path_len[n] += data_avg_successful_path_len[r][n];
            avg_successful_path_len_count[n]++;
            }
         avg_num_successes[n] += data_num_successes[r][n];
         }
      fclose(fp);
      }  /* for r */

   // calculate average
   for (n=0; n<pop_size; n++)
      {
      avg_num_times_acted[n] /= (double)num_runs;
      avg_avg_path_len[n] /= (double)avg_path_len_count[n];
      avg_avg_successful_path_len[n]/=(double)avg_successful_path_len_count[n];
      avg_num_successes[n] /= (double)num_runs;
      }

   // calculate stdev
   for (r=0; r<num_runs; r++)
      {
      for (n=0; n<pop_size; n++)
         {
         sum_num_times_acted[n] += 
		(data_num_times_acted[r][n] - avg_num_times_acted[n]) *
		(data_num_times_acted[r][n] - avg_num_times_acted[n]);
         sum_avg_path_len[n] += 
		(data_avg_path_len[r][n] - avg_avg_path_len[n]) *
		(data_avg_path_len[r][n] - avg_avg_path_len[n]);
         sum_avg_successful_path_len[n] += 
		(data_avg_successful_path_len[r][n] - avg_avg_successful_path_len[n]) *
		(data_avg_successful_path_len[r][n] - avg_avg_successful_path_len[n]);
         sum_num_successes[n] += 
		(data_num_successes[r][n] - avg_num_successes[n]) *
		(data_num_successes[r][n] - avg_num_successes[n]);
         }
      }
   for (n=0; n<pop_size; n++)
      {
      stdev_num_times_acted[n] = sqrt(sum_num_times_acted[n]/(double)num_runs);
      stdev_avg_path_len[n] = 
		sqrt(sum_avg_path_len[n]/(double)avg_path_len_count[n]);
      stdev_avg_successful_path_len[n] =
		sqrt(sum_avg_successful_path_len[n]/
		(double)avg_successful_path_len_count[n]);
      stdev_num_successes[n] = sqrt(sum_num_successes[n]/(double)num_runs);
      }

   // calculate confidence interval
   z = 1.96;		// 1.96 for 95% CI, 2.57 for 99% CI
   for (n=0; n<pop_size; n++)
      {
      ci_num_times_acted[n] = z * stdev_num_times_acted[n]/
				sqrt((double)num_runs);
      ci_avg_path_len[n] = z * stdev_avg_path_len[n]/
				sqrt((double)avg_path_len_count[n]);
      ci_avg_successful_path_len[n] =  z * stdev_avg_successful_path_len[n]/
				sqrt((double)avg_successful_path_len_count[n]);
      ci_num_successes[n] = z * stdev_num_successes[n]/sqrt((double)num_runs); 
      }

   // print to file
   sprintf(filename, "%s_data_agent_average.dat", prefix);
   fp = fopen(filename, "w");
   for (n=0; n<pop_size; n++)
      {
      fprintf(fp, " %d %lf %lf %lf %lf %lf %lf %lf %lf\n", n,
		avg_num_times_acted[n],
		ci_num_times_acted[n],
		avg_avg_path_len[n],
		ci_avg_path_len[n],
		avg_avg_successful_path_len[n],
		ci_avg_successful_path_len[n],
		avg_num_successes[n],
		ci_num_successes[n]);
      }
   fclose(fp);

   }  /* get_agent_averages */

void get_nest_averages(int start_run, int end_run, int max_steps, int pop_size, char prefix[])
   {
   FILE *fp;
   char filename[200];
   char tempstring[200];
   int r;               // count runs
   int index;
   int num_runs;
   double *data_closest_food;
   double *data_total_food;
   double *data_last_actor;
   double *data_avg_last_actor;
   double *data_avg_actors_per_step;
   double *data_steps_need_met;
   double avg_closest_food;
   double avg_total_food;
   double avg_last_actor;
   double avg_avg_last_actor;
   double avg_avg_actors_per_step;
   double avg_steps_need_met;
   double stdev_closest_food;
   double stdev_total_food;
   double stdev_last_actor;
   double stdev_avg_last_actor;
   double stdev_avg_actors_per_step;
   double stdev_steps_need_met;
   double ci_closest_food;
   double ci_total_food;
   double ci_last_actor;
   double ci_avg_last_actor;
   double ci_avg_actors_per_step;
   double ci_steps_need_met;

   num_runs = end_run - start_run + 1;

   // allocate space
   data_closest_food = (double *)malloc(num_runs * sizeof(double) );
   data_total_food = (double *)malloc(num_runs * sizeof(double) );
   data_last_actor = (double *)malloc(num_runs * sizeof(double) );
   data_avg_last_actor = (double *)malloc(num_runs * sizeof(double) );
   data_avg_actors_per_step = (double *)malloc(num_runs * sizeof(double) );
   data_steps_need_met = (double *)malloc(num_runs * sizeof(double) );

   // initialize
   avg_closest_food = 0;
   avg_total_food = 0;
   avg_last_actor = 0;
   avg_avg_last_actor = 0;
   avg_avg_actors_per_step = 0;
   avg_steps_need_met = 0;
   stdev_closest_food = 0;
   stdev_total_food = 0;
   stdev_last_actor = 0;
   stdev_avg_last_actor = 0;
   stdev_avg_actors_per_step = 0;
   stdev_steps_need_met = 0;

   for (r=0; r<num_runs; r++)
      {
      sprintf(filename, "../Output/run.%d/run.%d.finalneststats", 
		r+start_run, r+start_run);
      fp = fopen(filename, "r");

      fscanf(fp, "%d %s %lf %s %lf %s %lf %s %lf %s %lf %s %lf", &index,
		tempstring,
		&data_closest_food[r],
		tempstring,
		&data_total_food[r],
		tempstring,
		&data_last_actor[r],
		tempstring,
		&data_avg_last_actor[r],
		tempstring,
		&data_avg_actors_per_step[r],
		tempstring,
		&data_steps_need_met[r]
		);
      avg_closest_food += data_closest_food[r];
      avg_total_food += data_total_food[r];
      avg_last_actor += data_last_actor[r];
      avg_avg_last_actor += data_avg_last_actor[r];
      avg_avg_actors_per_step += data_avg_actors_per_step[r];
      avg_steps_need_met += data_steps_need_met[r]/(double)max_steps;

      fclose(fp);
      }

   // calculate average
   avg_closest_food /= (double)num_runs;
   avg_total_food /= (double)num_runs;
   avg_last_actor /= (double)num_runs;
   avg_avg_last_actor /= (double)num_runs;
   avg_avg_actors_per_step /= (double)num_runs;
   avg_steps_need_met /= (double)num_runs;

   // calculate standard deviation
   for (r=0; r<num_runs; r++)
      {
      stdev_closest_food = (data_closest_food[r] - avg_closest_food) *
			(data_closest_food[r] - avg_closest_food) ;
      stdev_total_food = (data_total_food[r] - avg_total_food) *
			(data_total_food[r] - avg_total_food) ;
      stdev_last_actor = (data_last_actor[r] - avg_last_actor) *
			(data_last_actor[r] - avg_last_actor) ;
      stdev_avg_last_actor = (data_avg_last_actor[r] - avg_avg_last_actor) *
			(data_avg_last_actor[r] - avg_avg_last_actor) ;
      stdev_avg_actors_per_step = 
		(data_avg_actors_per_step[r] - avg_avg_actors_per_step) *
		(data_avg_actors_per_step[r] - avg_avg_actors_per_step) ;
      stdev_steps_need_met = 
	(data_steps_need_met[r]/(double)max_steps - avg_steps_need_met) *
	(data_steps_need_met[r]/(double)max_steps - avg_steps_need_met) ;
      }
   stdev_closest_food = sqrt(stdev_closest_food/(double)num_runs);
   stdev_total_food = sqrt(stdev_total_food/(double)num_runs);
   stdev_last_actor = sqrt(stdev_last_actor/(double)num_runs);
   stdev_avg_last_actor = sqrt(stdev_avg_last_actor/(double)num_runs);
   stdev_avg_actors_per_step = sqrt(stdev_avg_actors_per_step/(double)num_runs);
   stdev_steps_need_met = sqrt(stdev_steps_need_met/(double)num_runs);

   // print data
   printf(" Closest food:   avg %lf stdev %lf\n", 
		avg_closest_food, stdev_closest_food);
   printf(" Total food:     avg %lf stdev %lf\n", 
		avg_total_food, stdev_total_food);
   printf(" Last actor:     avg %lf stdev %lf\n", 
		avg_last_actor, stdev_last_actor);
   printf(" Avg last actor: avg %lf stdev %lf\n", 
		avg_avg_last_actor, stdev_avg_last_actor);
   printf(" Avg actors per step: avg %lf stdev %lf\n", 
		avg_avg_actors_per_step, stdev_avg_actors_per_step);
   printf(" Pct steps need met: avg %lf stdev %lf\n", 
		avg_steps_need_met, stdev_steps_need_met);

   // print data to file
   sprintf(filename, "%s_printed_results.txt", prefix);
   fp = fopen(filename, "w");
   fprintf(fp, " Closest food:   avg %lf stdev %lf\n", 
		avg_closest_food, stdev_closest_food);
   fprintf(fp, " Total food:     avg %lf stdev %lf\n", 
		avg_total_food, stdev_total_food);
   fprintf(fp, " Last actor:     avg %lf stdev %lf\n", 
		avg_last_actor, stdev_last_actor);
   fprintf(fp, " Avg last actor: avg %lf stdev %lf\n", 
		avg_avg_last_actor, stdev_avg_last_actor);
   fprintf(fp, " Avg actors per step: avg %lf stdev %lf\n", 
		avg_avg_actors_per_step, stdev_avg_actors_per_step);
   fprintf(fp, " Pct steps need met: avg %lf stdev %lf\n", 
		avg_steps_need_met, stdev_steps_need_met);
   fclose(fp);
   // print to file plottable by gnuplot
   sprintf(filename, "%s_plot_results.txt", prefix);
   fp = fopen(filename, "w");
   fprintf(fp, " closest_food_av_sd %lf %lf",
		avg_closest_food, stdev_closest_food);
   fprintf(fp, " total_food_av_sd %lf %lf", avg_total_food, stdev_total_food);
   fprintf(fp, " actors_p_step_av_sd %lf %lf",
		avg_avg_actors_per_step, stdev_avg_actors_per_step);
   fprintf(fp, " pct_steps_need_met_av_sd %lf %lf\n",
		avg_steps_need_met, stdev_steps_need_met);
   fclose(fp);

   }  /* get_nest_averages */

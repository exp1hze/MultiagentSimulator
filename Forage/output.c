/* output.c
   08.05.26.AW	Created.  
		Contains routines that output to screen or file.
		General routines, not problem specific.

   Routines:	print_params()		06.21.98.AW
		print_opfiles()		07.08.98.AW
		gen_output()		07.29.98.AW
		run_output()		07.29.98.AW
*/

//#define DEBUG 1

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "types.h"
#include "extern.h"
#include "output.h"
#include "params.h"
#include "environ.h"
#include "nest.h"
#include "agent.h"
#include "map.h"
#include "gnu.h"

/********** print_params **********/
/* parameters:	fp	where to print, includes stdout (screen)
			Assume that fp has already been fopened.
   called by:	read_params(), params.c
		ga_init(), ga.c
   actions:	prints out the values of the parameters for a particular
		run.  Values to be printed (currently) must be defined in
		global.h.
*/
void print_params(FILE *fp)
   {
  /* things that were read in */
   fprintf(fp, " Run_num = %d\n", Run_num);
   fprintf(fp, " Seed = %ld\n", Seed);
   fprintf(fp, " Run_num_file = %s\n", Run_num_file);
   fprintf(fp, " Rerun = %d\n", Rerun);
   fprintf(fp, " Output_path = %s\n", Output_path);
   fprintf(fp, " Max_steps = %d\n", Max_steps);
   fprintf(fp, " Print_params = %d\n", Print_params);
   fprintf(fp, " Pop_size = %d\n", Pop_size);
   fprintf(fp, " Init_thresh = %lf\n", Init_thresh);
   fprintf(fp, " Max_thresh = %lf\n", Max_thresh);
   fprintf(fp, " Min_thresh = %lf\n", Min_thresh);
   fprintf(fp, " Prob_check = %lf\n", Prob_check);
   fprintf(fp, " Envr.width = %d\n", Envr.width);
   fprintf(fp, " Envr.height = %d\n", Envr.height);
   fprintf(fp, " Envr.num_food = %d\n", Envr.num_food);
   fprintf(fp, " Envr.init_food = %s\n", Envr.init_food);
   fprintf(fp, " Nest.need = %d\n", Nest.need);
   fprintf(fp, " Response_prob = %lf\n", Response_prob);
   fprintf(fp, " Max_sim_time = %d\n", Max_sim_time);
   fprintf(fp, " Print_agent_paths = %d\n", Print_agent_paths);
   fprintf(fp, " Print_agent_memory = %d\n", Print_agent_memory);
   fprintf(fp, " Print_agent_final_memory = %d\n", Print_agent_final_memory);
   fprintf(fp, " Positive_reinforcement = %lf\n", Positive_reinforcement);
   fprintf(fp, " Negative_reinforcement = %lf\n", Negative_reinforcement);
   }  /* print_params */

/********** print_opfiles **********/
/* parameters:	fp	where to print, includes stdout (screen)
			Assume that fp has already been fopened.
   called by:	read_default_opfiles, read_opfiles, params.c
   actions:	print out status of output files -- which ones are
		to be printed and which ones are not.
*/
void print_opfiles(FILE *fp)
   {
   int i;

   fprintf(fp, " Max_num_output_files = %d\n", Max_num_output_files);

   for (i=0; i<Max_num_output_files; i++)
      {
      fprintf(fp, "     %d: %s %d", i, Output_file[i].extension,
			Output_file[i].on);

/*
      if (Output_file[i].on)  fprintf(fp, " %s\n", Output_file[i].filename);
      else  fprintf(fp, "\n");
*/
      fprintf(fp, "\n");
      }  /* for i */
   }  /* print_opfiles */

/********** start_output **********/
/* parameters:
   called by:   init_fxn(), fxn.c
   actions:     prints everything that needs to be printed at the start
                of a run.
*/
void start_output()
   {
   int array_ptr;
#ifdef DEBUG
   printf(" ---in start_output---\n");
#endif

  /* output to files */
   if (file_on("initpop"))
      {
      array_ptr = get_file_pointer("initpop");
      Output_file[array_ptr].fp = fopen(Output_file[array_ptr].filename, "a");
      fprint_pop(Output_file[array_ptr].fp);
      fclose(Output_file[array_ptr].fp);
      }  /* if initpop */

#ifdef DEBUG
   printf(" ---end start_output---\n");
#endif
   }  /* start_output */

/********** step_output **********/
/* parameters:
   called by:
   actions:     prints everything that needs to be printed at the end
                of an step.
   parameters:  t = current step
*/
void step_output(int t)
   {
   int ptr;
   char filename[100];
   FILE *fp;
   int n;

#ifdef DEBUG
   printf(" ---in step_output---\n");
#endif

  /* output to files */
   if (file_on("stepdistance"))
      {
      ptr = get_file_pointer("stepdistance");
      Output_file[ptr].fp = fopen(Output_file[ptr].filename, "a");
      fprint_stepdistance(Output_file[ptr].fp, t);
      fclose(Output_file[ptr].fp);
      }  /* if */
   if (file_on("stepnest"))
      {
      ptr = get_file_pointer("stepnest");
      Output_file[ptr].fp = fopen(Output_file[ptr].filename, "a");
      fprint_stepnest(Output_file[ptr].fp, t);
      fclose(Output_file[ptr].fp);
      }  /* if */

  /* print the memory of every agent into a separate file */
   if (Print_agent_memory)
      {
      for (n=0; n<Pop_size; n++)
         {
         sprintf(filename, "%s/run.%d/run.%d.agent%d.step%d.memory",
                Output_path, Run_num, Run_num, n, t);
         fp = fopen(filename, "w");
         fprint_memory_map(fp, n);
         fclose(fp);
         }
      }

#ifdef DEBUG
   printf(" ---end step_output---\n");
#endif
   }  /* step_output */

/********** run_output **********/
/* parameters:
   called by:   gen_end(), stats.c
   actions:     prints everything that needs to be printed at the end
                of a run.
*/
void run_output()
   {
   int array_ptr;
   int n;
   FILE *fp;
   char filename[100];

#ifdef DEBUG
   printf(" ---in run_output---\n");
#endif

  /* output to files */
   if (file_on("finalagentstats"))
      {
      array_ptr = get_file_pointer("finalagentstats");
      Output_file[array_ptr].fp = fopen(Output_file[array_ptr].filename, "a");
      fprint_finalagentstats(Output_file[array_ptr].fp);
      fclose(Output_file[array_ptr].fp);
      }
   if (file_on("finalneststats"))
      {
      array_ptr = get_file_pointer("finalneststats");
      Output_file[array_ptr].fp = fopen(Output_file[array_ptr].filename, "a");
      fprint_finalneststats(Output_file[array_ptr].fp);
      fclose(Output_file[array_ptr].fp);
      }
   if (file_on("foodlocations"))
      {
      array_ptr = get_file_pointer("foodlocations");
      Output_file[array_ptr].fp = fopen(Output_file[array_ptr].filename, "a");
      fprint_foodlocations(Output_file[array_ptr].fp);
      fclose(Output_file[array_ptr].fp);
      }
   if (file_on("finalavgmemory"))
      {
      array_ptr = get_file_pointer("finalavgmemory");
      Output_file[array_ptr].fp = fopen(Output_file[array_ptr].filename, "a");
      fprint_finalavgmemory(Output_file[array_ptr].fp);
      fclose(Output_file[array_ptr].fp);
      }
   if (file_on("path"))
      {
      array_ptr = get_file_pointer("path");
      Output_file[array_ptr].fp = fopen(Output_file[array_ptr].filename, "a");
      fprint_path(Output_file[array_ptr].fp);
      fclose(Output_file[array_ptr].fp);
      }
   if (file_on("gnu"))
      {
      array_ptr = get_file_pointer("gnu");
      Output_file[array_ptr].fp = fopen(Output_file[array_ptr].filename, "a");
      fprint_gnu(Output_file[array_ptr].fp);
      fclose(Output_file[array_ptr].fp);
      }
   if (file_on("finalagentacted"))
      {
      array_ptr = get_file_pointer("finalagentacted");
      Output_file[array_ptr].fp = fopen(Output_file[array_ptr].filename, "a");
      fprint_finalagentacted(Output_file[array_ptr].fp);
      fclose(Output_file[array_ptr].fp);
      }
   if (file_on("finalagentavgpathlen"))
      {
      array_ptr = get_file_pointer("finalagentavgpathlen");
      Output_file[array_ptr].fp = fopen(Output_file[array_ptr].filename, "a");
      fprint_finalagentavgpathlen(Output_file[array_ptr].fp);
      fclose(Output_file[array_ptr].fp);
      }
   if (file_on("finalagentsuccesses"))
      {
      array_ptr = get_file_pointer("finalagentsuccesses");
      Output_file[array_ptr].fp = fopen(Output_file[array_ptr].filename, "a");
      fprint_finalagentsuccesses(Output_file[array_ptr].fp);
      fclose(Output_file[array_ptr].fp);
      }

   if (Print_agent_memory)
      {
      fprint_agentstepmemory_gnu();
      }

  /* print the final step memory of every agent into a separate file */
   if (Print_agent_final_memory)
      {
      for (n=0; n<Pop_size; n++)
         {
         sprintf(filename, "%s/run.%d/run.%d.agent%d.finalmemory",
                Output_path, Run_num, Run_num, n);
         fp = fopen(filename, "w");
         fprint_memory_map(fp, n);
         fclose(fp);
         }
      fprint_agentfinalmemory_gnu();
      }

  /* output on screen */
   printf("\n");
   printf(" Pop_size = %d\n", Pop_size);
   printf(" Max_steps = %d\n", Max_steps);
   printf("\n");

#ifdef DEBUG
   printf(" ---end run_output---\n");
#endif
   }  /* run_output */

/********** fprint_finalagentstats **********/
/* called by:	run_output(), output.c
   actions:     Prints path stats for each agent
                One line of data:
     Run_num ag0 <#times acted> <avgpathlen> ... agn <#times acted> <avgpathlen>
*/

void fprint_finalagentstats(FILE *fp)
   {
   int i;
   int sum_times;
   double avg_len;

#ifdef DEBUG
printf("---in fprint_finalagentstats()---\n");
#endif

   fprintf(fp, " %4d", Run_num);

   agent_stats();
   sum_times = 0;
   avg_len = 0;
   for (i=0; i<Pop_size; i++)
      {
      fprintf(fp, " ag%d %4d %lf %lf %4d", i,
		Agent[i].num_times_acted,
		Agent[i].avg_path_len,
		Agent[i].avg_successful_path_len,
		Agent[i].num_successes );
      sum_times += Agent[i].num_times_acted;
      avg_len += Agent[i].avg_path_len;
      }
   if (sum_times > 0)  avg_len = avg_len/(double)sum_times;
   fprintf(fp, " All %4d %lf\n", sum_times, avg_len);

#ifdef DEBUG
printf("---end fprint_finalagentstats()---\n");
#endif
   }  /* fprint_finalagentstats */

/********** fprint_finalneststats **********/
/* called by:   run_output(), output.c
   actions:     Prints final run stats for nest
                One line of data:
                Run_num 
*/

void fprint_finalneststats(FILE *fp)
   {
   int i;
   int sum_times;
   double avg_len;

#ifdef DEBUG
printf("---in fprint_finalneststats()---\n");
#endif

   fprintf(fp, " %4d", Run_num);

   fprintf(fp, " closest_food %lf total_food %lf",
	get_closest_food_distance(), Nest.total_food);
   fprintf(fp, " last_actor %d avg_last_actor %lf",
	Nest.run_last_actor,
	Nest.avg_last_actor/(double)Max_steps);
   fprintf(fp, " avg_actors_per_step %lf steps_need_met %d\n",
	Nest.total_num_actors/(double)Max_steps, Nest.num_steps_need_met); 

#ifdef DEBUG
printf("---end fprint_finalneststats()---\n");
#endif
   }  /* fprint_finalneststats */

/********** fprint_pop **********/
void fprint_pop(FILE *fp)
   {
   int i;
   int j;

#ifdef DEBUG
printf("---in fprint_pop()---\n");
#endif

   for (i=0; i<Pop_size; i++)
      {
      fprintf(fp, " agent %d thresh %lf resprob %lf",
         Agent[i].index, Agent[i].thresh[0], Agent[i].response_prob[0]);
      fprintf(fp, "\n");
      }  /* for r */

#ifdef DEBUG
printf("---end fprint_pop()---\n");
#endif
   }  /* fprint_pop */

/********** fprint_stepdistance ***********/
/* Called by:		step_output(), output.c
   Parameters:		t	current timestep
   Actions:		Called once per step.  Print distance (tt value)
			each agent travelled in that step.
*/
void fprint_stepdistance(FILE *fp, int t)
   {
   int i;

#ifdef DEBUG
printf("---in fprint_stepdistance()---\n");
#endif

   fprintf(fp, " %4d ", t);
   for (i=0; i<Pop_size; i++)
      {
      fprintf(fp, " ag %3d %3d ", i, Agent[i].distance_travelled);
      }
   fprintf(fp, "\n");

#ifdef DEBUG
printf("---end fprint_stepdistance()---\n");
#endif
   }  /* fprint_stepdistance */

/********** fprint_stepnest ***********/
/* Called by:           step_output(), output.c
   Parameters:          t       current timestep
   Actions:             Called once per step.  Print nest data per step.
*/
void fprint_stepnest(FILE *fp, int t)
   {
   int i;

#ifdef DEBUG
printf("---in fprint_stepnest()---\n");
#endif

   // these two values may be different because not all agents that
   // act manage to find food
   //fprintf(fp, " %4d food_in %lf\n", t, Nest.step_income);
   fprintf(fp, " %4d food_in %lf num_actors %d\n", 
	t, Nest.step_income, Nest.step_num_actors);

#ifdef DEBUG
printf("---end fprint_stepnest()---\n");
#endif
   }  /* fprint_stepnest */

/********** fprint_foodlocations ***********/
/* Called by:           run_output(), output.c
   Parameters:  
   Actions:             Print food locations and start locations.
*/
void fprint_foodlocations(FILE *fp)
   {
   int r, c;

#ifdef DEBUG
printf("---in fprint_foodlocations()---\n");
#endif

   for (r=0; r<Envr.height; r++)
      {
      for (c=0; c<Envr.width; c++)
         {
         if (Envr.start_row == r && Envr.start_col == c 
		&& Envr.grid[r][c] == 0)
            fprintf(fp, " 0.5");
         else
            fprintf(fp, " %3d", (int)Envr.grid[r][c]);

         //if (Envr.grid[r][c] == 1)  fprintf(fp, "  @");
         //else                       fprintf(fp, "  -");
         }
      fprintf(fp, "\n");
      }

#ifdef DEBUG
printf("---end fprint_foodlocations()---\n");
#endif
   }  /* fprint_foodlocations */

/********** fprint_finalavgmemory ***********/
/* Called by:           run_output(), output.c
   Parameters:
   Actions:             Print how much time each agent spent on each task.
*/
void fprint_finalavgmemory(FILE *fp)
   {
   int r, c;

#ifdef DEBUG
printf("---in fprint_finalavgmemory()---\n");
#endif

   average_memory_maps();

   for (r=0; r<Envr.height; r++)
      {
      for (c=0; c<Envr.width; c++)
         {
         fprintf(fp, " %10.4lf ", Nest.master_memory_map[r][c] );
         }
      fprintf(fp, "\n");
      }

#ifdef DEBUG
printf("---end fprint_finalavgmemory()---\n");
#endif
   }  /* fprint_finalavgmemory */

/********** fprint_path ***********/
/* Called by:           run_output(), output.c
   Parameters:
   Actions:             Print num times acted and avg path length for each
			agent.
*/
void fprint_path(FILE *fp)
   {
   int n;

#ifdef DEBUG
printf("---in fprint_path()---\n");
#endif

   for (n=0; n<Pop_size; n++)
      {
      fprintf(fp, " %4d %4d %lf %lf %4d\n", n, 
		Agent[n].num_times_acted,
		Agent[n].avg_path_len,
		Agent[n].avg_successful_path_len,
		Agent[n].num_successes);
      }

#ifdef DEBUG
printf("---end fprint_path()---\n");
#endif
   }  /* fprint_path */

/********** fprint_finalagentacted **********/
/* called by:   run_output(), output.c
   actions:     Prints number of times each agent acts in each run.
                One line of data:
		<ag0 #times acted> ... <agn #times acted>
*/

void fprint_finalagentacted(FILE *fp)
   {
   int i;

#ifdef DEBUG
printf("---in fprint_finalagentacted()---\n");
#endif

   //fprintf(fp, " %4d", Run_num);

   agent_stats();
   for (i=0; i<Pop_size; i++)
      {
      //fprintf(fp, " ag%d %4d ", i, Agent[i].num_times_acted);
      fprintf(fp, " %4d ", Agent[i].num_times_acted);
      }
   fprintf(fp, "\n");

#ifdef DEBUG
printf("---end fprint_finalagentacted()---\n");
#endif
   }  /* fprint_finalagentacted */

/********** fprint_finalagentavgpathlen **********/
/* called by:   run_output(), output.c
   actions:     Prints avg path length for each agent
                One line of data:
		<ag0 avgpathlen> ... <agn avgpathlen>
*/

void fprint_finalagentavgpathlen(FILE *fp)
   {
   int i;

#ifdef DEBUG
printf("---in fprint_finalagentavgpathlen()---\n");
#endif

   //fprintf(fp, " %4d", Run_num);

   agent_stats();
   for (i=0; i<Pop_size; i++)
      {
      //fprintf(fp, " ag%d %lf ", i, Agent[i].avg_path_len);
      fprintf(fp, " %lf", Agent[i].avg_path_len);
      }
   fprintf(fp, "\n");

#ifdef DEBUG
printf("---end fprint_finalagentavgpathlen()---\n");
#endif
   }  /* fprint_finalagentavgpathlen */

/********** fprint_finalagentsuccesses **********/
/* called by:   run_output(), output.c
   actions:     Prints success rate for each agent
                One line of data:
		<ag0 success rate> ... <agn success rate>
*/

void fprint_finalagentsuccesses(FILE *fp)
   {
   int i;

#ifdef DEBUG
printf("---in fprint_finalagentsuccesses()---\n");
#endif

   //fprintf(fp, " %4d", Run_num);

   agent_stats();
   for (i=0; i<Pop_size; i++)
      {
      // fprintf(fp, " ag%d %lf ", i, Agent[i].success_rate );
      fprintf(fp, " %4d", Agent[i].num_successes );
      }
   fprintf(fp, "\n");

#ifdef DEBUG
printf("---end fprint_finalagentsuccesses()---\n");
#endif
   }  /* fprint_finalagentsuccesses */

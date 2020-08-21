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
#include "gnu.h"
#include "fxn.h"

#define HISTOGRAM_SIZE ((Intensity_aging_max - Intensity_aging_min) * 10)

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
   fprintf(fp, " Print_step = %d\n", Print_step);
   fprintf(fp, " Pop_size = %d\n", Pop_size);
   fprintf(fp, " Thresh_init = %lf\n", Thresh_init);
   fprintf(fp, " Thresh_dynamic = %d\n", Thresh_dynamic);
   fprintf(fp, " Thresh_increase = %lf\n", Thresh_increase);
   fprintf(fp, " Thresh_decrease = %lf\n", Thresh_decrease);
   fprintf(fp, " Prob_check = %lf\n", Prob_check);
   fprintf(fp, " Task_selection = %s\n", Task_selection);
   fprintf(fp, " Target_path = %s\n", Target_path);
   fprintf(fp, " Target.amplitude = %lf\n", Target.amplitude);
   fprintf(fp, " Target.period = %lf\n", Target.period);
   fprintf(fp, " Target.step_len = %lf\n", Target.step_len);
   fprintf(fp, " Range = %lf\n", Range);
   fprintf(fp, " Step_ratio = %lf\n", Tracker.step_ratio);
   /* HDM; intensity variation; 2019.09.12 */
   fprintf(fp, " Intensity_variation = %d\n", Intensity_variation);
   /* HDM; intensity variation; 2019.09.19 */
   fprintf(fp, " Intensity_aging = %d\n", Intensity_aging);
   fprintf(fp, " Intensity_aging_min = %lf\n", Intensity_aging_min);
   fprintf(fp, " Intensity_aging_max = %lf\n", Intensity_aging_max);
   fprintf(fp, " Intensity_aging_up = %lf\n", Intensity_aging_up);
   fprintf(fp, " Intensity_aging_down = %lf\n", Intensity_aging_down);
   fprintf(fp, " Intensity_distribution = %d\n", Intensity_distribution);
   /* LR; heterogeneous intensity ranges; 2020.02.08 */
   fprintf(fp, " Hetero_center_distr = %d\n", Hetero_center_distr);
   fprintf(fp, " Hetero_radius_distr = %d\n", Hetero_radius_distr);
   /* LR; heterogeneous intensity ranges; 2020.02.27 */
   fprintf(fp, " Hetero_range_max = %lf\n", Hetero_range_max);
   fprintf(fp, " Hetero_range_min = %lf\n", Hetero_range_min);
   fprintf(fp, " Hetero_radius_max = %lf\n", Hetero_radius_max);
   fprintf(fp, " Hetero_radius_min = %lf\n", Hetero_radius_min);
   /* LR; heterogeneous intensity ranges; 2020.02.15 */
   fprintf(fp, " Hetero_center_mu = %lf\n", Hetero_center_mu);
   fprintf(fp, " Hetero_center_std = %lf\n", Hetero_center_std);
   fprintf(fp, " Hetero_radius_mu = %lf\n", Hetero_radius_mu);
   fprintf(fp, " Hetero_radius_std = %lf\n", Hetero_radius_std);
   /* HDM; response variation probability; 2019.10.24 */
   fprintf(fp, " Response_prob = %lf\n", Response_prob);
   fprintf(fp, " Kill_number = %d\n", Kill_number);
   fprintf(fp, " First_extinction = %d\n", First_extinction);
   fprintf(fp, " Extinction_period = %d\n", Extinction_period);
   fprintf(fp, " Gnuplot_plots = %d\n", Gnuplot_plots);
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
   if (file_on("params"))
      {
      array_ptr = get_file_pointer("params");
      Output_file[array_ptr].fp = fopen(Output_file[array_ptr].filename, "a");
      print_fxn_params(Output_file[array_ptr].fp);
      fclose(Output_file[array_ptr].fp);
      }  /* if */
   if (file_on("threshrange"))
      {
      array_ptr = get_file_pointer("threshrange");
      Output_file[array_ptr].fp = fopen(Output_file[array_ptr].filename, "a");
      fprint_threshrange(Output_file[array_ptr].fp);
      fclose(Output_file[array_ptr].fp);
      }  /* if */

  /* print initial position of target and tracker */
   if (file_on("stepsummary"))
      {
      array_ptr = get_file_pointer("stepsummary");
      Output_file[array_ptr].fp = fopen(Output_file[array_ptr].filename, "a");
      fprint_stepsummary(Output_file[array_ptr].fp, -1);
      fclose(Output_file[array_ptr].fp);
      }  /* if */
   if (file_on("steptargetpath"))
      {
      array_ptr = get_file_pointer("steptargetpath");
      Output_file[array_ptr].fp = fopen(Output_file[array_ptr].filename, "a");
      fprint_steptargetpath(Output_file[array_ptr].fp, -1);
      fclose(Output_file[array_ptr].fp);
      }  /* if */
   if (file_on("steptrackerpath"))
      {
      array_ptr = get_file_pointer("steptrackerpath");
      Output_file[array_ptr].fp = fopen(Output_file[array_ptr].filename, "a");
      fprint_steptrackerpath(Output_file[array_ptr].fp, -1);
      fclose(Output_file[array_ptr].fp);
      }  /* if */
   if (file_on("stephistnorth") && Intensity_aging)
      {
      array_ptr = get_file_pointer("stephistnorth");
      Output_file[array_ptr].fp = fopen(Output_file[array_ptr].filename, "a");
      fprint_stephistnorth(Output_file[array_ptr].fp, -1);
      fclose(Output_file[array_ptr].fp);
      }  /* if */
   if (file_on("stephistsouth") && Intensity_aging)
      {
      array_ptr = get_file_pointer("stephistsouth");
      Output_file[array_ptr].fp = fopen(Output_file[array_ptr].filename, "a");
      fprint_stephistsouth(Output_file[array_ptr].fp, -1);
      fclose(Output_file[array_ptr].fp);
      }  /* if */
   if (file_on("stephisteast") && Intensity_aging)
      {
      array_ptr = get_file_pointer("stephisteast");
      Output_file[array_ptr].fp = fopen(Output_file[array_ptr].filename, "a");
      fprint_stephisteast(Output_file[array_ptr].fp, -1);
      fclose(Output_file[array_ptr].fp);
      }  /* if */
   if (file_on("stephistwest") && Intensity_aging)
      {
      array_ptr = get_file_pointer("stephistwest");
      Output_file[array_ptr].fp = fopen(Output_file[array_ptr].filename, "a");
      fprint_stephistwest(Output_file[array_ptr].fp, -1);
      fclose(Output_file[array_ptr].fp);
      }  /* if */

   /* print the initialized aging ranges for each agent */
   if (file_on("intensityranges") && Intensity_aging && Intensity_variation == 2)
      {
      array_ptr = get_file_pointer("intensityranges");
      Output_file[array_ptr].fp = fopen(Output_file[array_ptr].filename, "a");
      fprint_intensityranges(Output_file[array_ptr].fp);
      fclose(Output_file[array_ptr].fp);
      }  /* if */

#ifdef DEBUG
   printf(" ---end start_output---\n");
#endif
   }  /* start_output */

/********** step_output **********/
/* parameters:
   called by:
   actions:     prints everything that needs to be printed at the end
                of an step.
   parameters:  t = current timestep
*/
void step_output(int t)
   {
   int ptr;

#ifdef DEBUG
   printf(" ---in step_output---\n");
#endif

  /* output to files */
   if (file_on("stepthresh"))
      {
      ptr = get_file_pointer("stepthresh");
      Output_file[ptr].fp = fopen(Output_file[ptr].filename, "a");
      fprint_stepthresh(Output_file[ptr].fp, t);
      fclose(Output_file[ptr].fp);
      }  /* if */
   if (file_on("stepsummary"))
      {
      ptr = get_file_pointer("stepsummary");
      Output_file[ptr].fp = fopen(Output_file[ptr].filename, "a");
      fprint_stepsummary(Output_file[ptr].fp, t);
      fclose(Output_file[ptr].fp);
      }  /* if */
   if (file_on("stepdemand"))
      {
      ptr = get_file_pointer("stepdemand");
      Output_file[ptr].fp = fopen(Output_file[ptr].filename, "a");
      fprint_stepdemand(Output_file[ptr].fp, t);
      fclose(Output_file[ptr].fp);
      }  /* if */
   if (file_on("steptargetpath"))
      {
      ptr = get_file_pointer("steptargetpath");
      Output_file[ptr].fp = fopen(Output_file[ptr].filename, "a");
      fprint_steptargetpath(Output_file[ptr].fp, t);
      fclose(Output_file[ptr].fp);
      }  /* if */
   if (file_on("steptrackerpath"))
      {
      ptr = get_file_pointer("steptrackerpath");
      Output_file[ptr].fp = fopen(Output_file[ptr].filename, "a");
      fprint_steptrackerpath(Output_file[ptr].fp, t);
      fclose(Output_file[ptr].fp);
      }  /* if */
   if (file_on("stepnorthsouth"))
      {
      ptr = get_file_pointer("stepnorthsouth");
      Output_file[ptr].fp = fopen(Output_file[ptr].filename, "a");
      fprint_stepnorthsouth(Output_file[ptr].fp, t);
      fclose(Output_file[ptr].fp);
      }  /* if */
   if (file_on("stepeastwest"))
      {
      ptr = get_file_pointer("stepeastwest");
      Output_file[ptr].fp = fopen(Output_file[ptr].filename, "a");
      fprint_stepeastwest(Output_file[ptr].fp, t);
      fclose(Output_file[ptr].fp);
      }  /* if */
   if (file_on("stepagentaction"))
      {
      ptr = get_file_pointer("stepagentaction");
      Output_file[ptr].fp = fopen(Output_file[ptr].filename, "a");
      fprint_stepagentaction(Output_file[ptr].fp, t);
      fclose(Output_file[ptr].fp);
      }  /* if */
   if (file_on("stepagentactionwtime"))
      {
      ptr = get_file_pointer("stepagentactionwtime");
      Output_file[ptr].fp = fopen(Output_file[ptr].filename, "a");
      fprint_stepagentactionwtime(Output_file[ptr].fp, t);
      fclose(Output_file[ptr].fp);
      }  /* if */
   if (file_on("stepagentactionxyz"))
      {
      ptr = get_file_pointer("stepagentactionxyz");
      Output_file[ptr].fp = fopen(Output_file[ptr].filename, "a");
      fprint_stepagentactionxyz(Output_file[ptr].fp, t);
      fclose(Output_file[ptr].fp);
      }  /* if */
   if (file_on("stephistnorth") && Intensity_aging)
      {
      ptr = get_file_pointer("stephistnorth");
      Output_file[ptr].fp = fopen(Output_file[ptr].filename, "a");
      fprint_stephistnorth(Output_file[ptr].fp, t);
      fclose(Output_file[ptr].fp);
      }  /* if */
   if (file_on("stephistsouth") && Intensity_aging)
      {
      ptr = get_file_pointer("stephistsouth");
      Output_file[ptr].fp = fopen(Output_file[ptr].filename, "a");
      fprint_stephistsouth(Output_file[ptr].fp, t);
      fclose(Output_file[ptr].fp);
      }  /* if */
   if (file_on("stephisteast") && Intensity_aging)
      {
      ptr = get_file_pointer("stephisteast");
      Output_file[ptr].fp = fopen(Output_file[ptr].filename, "a");
      fprint_stephisteast(Output_file[ptr].fp, t);
      fclose(Output_file[ptr].fp);
      }  /* if */
   if (file_on("stephistwest") && Intensity_aging)
      {
      ptr = get_file_pointer("stephistwest");
      Output_file[ptr].fp = fopen(Output_file[ptr].filename, "a");
      fprint_stephistwest(Output_file[ptr].fp, t);
      fclose(Output_file[ptr].fp);
      }  /* if */
   if (file_on("stepthreshnorth"))
      {
      ptr = get_file_pointer("stepthreshnorth");
      Output_file[ptr].fp = fopen(Output_file[ptr].filename, "a");
      fprint_stepthreshnorth(Output_file[ptr].fp, t);
      fclose(Output_file[ptr].fp);
      }  /* if */
   if (file_on("stepthreshsouth"))
      {
      ptr = get_file_pointer("stepthreshsouth");
      Output_file[ptr].fp = fopen(Output_file[ptr].filename, "a");
      fprint_stepthreshsouth(Output_file[ptr].fp, t);
      fclose(Output_file[ptr].fp);
      }  /* if */
   if (file_on("stepthresheast"))
      {
      ptr = get_file_pointer("stepthresheast");
      Output_file[ptr].fp = fopen(Output_file[ptr].filename, "a");
      fprint_stepthresheast(Output_file[ptr].fp, t);
      fclose(Output_file[ptr].fp);
      }  /* if */
   if (file_on("stepthreshwest"))
      {
      ptr = get_file_pointer("stepthreshwest");
      Output_file[ptr].fp = fopen(Output_file[ptr].filename, "a");
      fprint_stepthreshwest(Output_file[ptr].fp, t);
      fclose(Output_file[ptr].fp);
      }  /* if */

#ifdef DEBUG
   printf(" ---end step_output---\n");
#endif
   }  /* step_output */

/********** run_output **********/
/* parameters:
   called by:   end_sim(), sim.c
   actions:     prints everything that needs to be printed at the end
                of a run.
*/
void run_output()
   {
   int array_ptr;
   int i;
   double sum;

#ifdef DEBUG
   printf(" ---in run_output---\n");
#endif

  /* output to files */
   if (file_on("finalstats"))
      {
      array_ptr = get_file_pointer("finalstats");
      Output_file[array_ptr].fp = fopen(Output_file[array_ptr].filename, "a");
      fprint_finalstats(Output_file[array_ptr].fp);
      fclose(Output_file[array_ptr].fp);
      }
   if (file_on("finalagent"))
      {
      array_ptr = get_file_pointer("finalagent");
      Output_file[array_ptr].fp = fopen(Output_file[array_ptr].filename, "a");
      fprint_finalagent(Output_file[array_ptr].fp);
      fclose(Output_file[array_ptr].fp);
      }
   if (file_on("gnu"))
      {
      array_ptr = get_file_pointer("gnu");
      Output_file[array_ptr].fp = fopen(Output_file[array_ptr].filename, "a");
      fprint_gnu(Output_file[array_ptr].fp);
      fclose(Output_file[array_ptr].fp);
      }
    // HDM; 2019.09.19
    if (file_on("finalintensity"))
        {
        array_ptr = get_file_pointer("finalintensity");
        Output_file[array_ptr].fp = fopen(Output_file[array_ptr].filename, "a");
        fprint_intensities(Output_file[array_ptr].fp);
        fclose(Output_file[array_ptr].fp);
        }
   // 20.04.18.ASW
   if (file_on("finalpop"))
      {
      array_ptr = get_file_pointer("finalpop");
      Output_file[array_ptr].fp = fopen(Output_file[array_ptr].filename, "a");
      fprint_pop(Output_file[array_ptr].fp);
      fclose(Output_file[array_ptr].fp);
      }  /* if initpop */


#ifdef DEBUG
   printf(" ---end run_output---\n");
#endif
   }  /* run_output */

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
      // print info for one agent on each line
      fprintf(fp, " agent %d raw_thresh t-n %lf t-s %lf t-e %lf t-w %lf",
         Agent[i].index,
         Agent[i].raw_thresh_north,
         Agent[i].raw_thresh_south,
         Agent[i].raw_thresh_east,
         Agent[i].raw_thresh_west);
      fprintf(fp, " prob_check %lf", Agent[i].prob_check);
      fprintf(fp, " thresh t-n %lf t-s %lf t-e %lf t-w %lf",
         Agent[i].thresh_north,
         Agent[i].thresh_south,
         Agent[i].thresh_east,
         Agent[i].thresh_west);
      // for plotting the thresholds
      fprintf(fp, " 1 2 3 4");
      // print max and min thresh
      fprintf(fp, " raw_thresh_max %lf raw_thresh_min %lf",
         Agent[i].raw_thresh_max,
         Agent[i].raw_thresh_min);
      if (Thresh_dynamic == 1 || Thresh_dynamic == 2)
         {
         // max and min of each direction
         fprintf(fp, " north_range max %lf min %lf",
            Agent[i].thresh_max_north,
            Agent[i].thresh_min_north);
         fprintf(fp, " south_range max %lf min %lf",
            Agent[i].thresh_max_south,
            Agent[i].thresh_min_south);
         fprintf(fp, " east_range max %lf min %lf",
            Agent[i].thresh_max_east,
            Agent[i].thresh_min_east);
         fprintf(fp, " west_range max %lf min %lf",
            Agent[i].thresh_max_west,
            Agent[i].thresh_min_west);
         }
      // end of line
      fprintf(fp, "\n");
      }  /* for r */

#ifdef DEBUG
printf("---end fprint_pop()---\n");
#endif
   }  /* fprint_pop */

/********** fprint_threshrange ***********/
/* Called by:           step_output(), output.c
   Parameters:          t       current timestep
   Actions:             Called at start of run.  Prints initial threshold and
			threshold range (max and min) for each agent.  
			One agent per line.
*/
void fprint_threshrange(FILE *fp)
   {
   int i, j;

#ifdef DEBUG
printf("---in fprint_threshrange()---\n");
#endif

   for (i=0; i<Pop_size; i++)
      {
      fprintf(fp, " Agent %4d ", i);
      // for each direction print init, max, min threshold value
      fprintf(fp, " N %lf %lf %lf E %lf %lf %lf S %lf %lf %lf W %lf %lf %lf ",
      Agent[i].thresh_north,Agent[i].thresh_min_north,Agent[i].thresh_max_north,
      Agent[i].thresh_south,Agent[i].thresh_min_south,Agent[i].thresh_max_south,
      Agent[i].thresh_east,Agent[i].thresh_min_east,Agent[i].thresh_max_east,
      Agent[i].thresh_west,Agent[i].thresh_min_west,Agent[i].thresh_max_west);
      fprintf(fp, "\n");
      }

#ifdef DEBUG
printf("---end fprint_threshrange()---\n");
#endif

   }  /* fprint_threshrange */

/********** fprint_stepthresh ***********/
/* Called by:           step_output(), output.c
   Parameters:          t       current timestep
   Actions:             Called once per step to print thresh parameters.
*/
void fprint_stepthresh(FILE *fp, int t)
   {
   int i, j;

#ifdef DEBUG
printf("---in fprint_stepthresh()---\n");
#endif

   fprintf(fp, " T %4d ", t);
   for (i=0; i<Pop_size; i++)
      {
      fprintf(fp, " A %d ", i);
      fprintf(fp, " N %lf E %lf S %lf W %lf ",
		Agent[i].thresh_north, Agent[i].thresh_south,
		Agent[i].thresh_east, Agent[i].thresh_west);
      }
   fprintf(fp, "\n");

#ifdef DEBUG
printf("---end fprint_stepthresh()---\n");
#endif

   }  /* fprint_stepthresh */

/********** fprint_stepsummary ***********/
/* Called by:           step_output(), output.c
   Parameters:          t       current timestep
   Actions:             Called once per step to print target coordinates.
*/
void fprint_stepsummary(FILE *fp, int t)
   {
   int i, j;

#ifdef DEBUG
printf("---in fprint_stepsummary()---\n");
#endif

   fprintf(fp, " T %4d target %lf %lf tracker %lf %lf dist %lf",
           t, Target.x, Target.y, Tracker.x, Tracker.y, Tracker.difference);
   fprintf(fp, " pathlen tar %lf trk %lf", Target.length, Tracker.length);
   fprintf(fp, " step_len tar %lf trk %lf",
           Target.step_len, Tracker.current_step_len);
   fprintf(fp, " pushing n %d e %d s %d w %d",
           Tracker.push_north, Tracker.push_east, Tracker.push_south,
           Tracker.push_west);
   // replaced Pop_size with Num_alive due to killing agents
   fprintf(fp, " idle %d\n",
           Num_alive - Tracker.push_north - Tracker.push_east -
           Tracker.push_south - Tracker.push_west);

#ifdef DEBUG
printf("---end fprint_stepsummary()---\n");
#endif

   }  /* fprint_stepsummary */

/********** fprint_stepdemand ***********/
/* Called by:           step_output(), output.c
   Parameters:          t       current timestep
   Actions:             Called once per time step.
			Print demand (distance) in each direction and delivery
			(amount pushed) in each direction per timestep.
*/
void fprint_stepdemand(FILE *fp, int t)
   {
   int i;
   double diff_north, diff_east, diff_south, diff_west;
   double move_north, move_east, move_south, move_west;

#ifdef DEBUG
printf("---in fprint_stepdemand()---\n");
#endif

   diff_north = (Tracker.diff_to_north < 0) ? 0 : Tracker.diff_to_north;
   diff_south = (Tracker.diff_to_south < 0) ? 0 : Tracker.diff_to_south;
   diff_east = (Tracker.diff_to_east < 0) ? 0 : Tracker.diff_to_east;
   diff_west = (Tracker.diff_to_west < 0) ? 0 : Tracker.diff_to_west;

   move_north = (Intensity_variation) ?
    Tracker.intensity_push_north/Tracker.intensity_all_north * Tracker.max_step_len
    : (double)Tracker.push_north/(double)Num_alive*Tracker.max_step_len;
   move_south = (Intensity_variation) ?
    Tracker.intensity_push_south/Tracker.intensity_all_south * Tracker.max_step_len
    : (double)Tracker.push_south/(double)Num_alive*Tracker.max_step_len;
   move_east = (Intensity_variation) ?
    Tracker.intensity_push_east/Tracker.intensity_all_east * Tracker.max_step_len
    : (double)Tracker.push_east/(double)Num_alive*Tracker.max_step_len;
   move_west = (Intensity_variation) ?
    Tracker.intensity_push_west/Tracker.intensity_all_west * Tracker.max_step_len
    : (double)Tracker.push_west/(double)Num_alive*Tracker.max_step_len;

   fprintf(fp, " T %4d ", t);
   fprintf(fp, " demand N %lf E %lf S %lf W %lf ",
           diff_north, diff_east, diff_south, diff_west);
   fprintf(fp, " delivered N %lf E %lf S %lf W %lf\n",
           move_north, move_east, move_south, move_west);

#ifdef DEBUG
printf("---end fprint_stepdemand()---\n");
#endif

   }  /* fprint_stepdemand */

/********** fprint_steptargetpath ***********/
/* Called by:           step_output(), output.c
   Parameters:          t       current timestep
   Actions:             Called once per step to print target coordinates.
*/
void fprint_steptargetpath(FILE *fp, int t)
   {
   int i, j;

#ifdef DEBUG
printf("---in fprint_steptargetpath()---\n");
#endif

   fprintf(fp, " T %4d x %lf y %lf %s\n", t, Target.x, Target.y, Target.side);

#ifdef DEBUG
printf("---end fprint_steptargetpath()---\n");
#endif

   }  /* fprint_steptargetpath */

/********** fprint_steptrackerpath ***********/
/* Called by:           step_output(), output.c
   Parameters:          t       current timestep
   Actions:             Called once per step to print tracker coordinates.
*/
void fprint_steptrackerpath(FILE *fp, int t)
   {
   int i, j;

#ifdef DEBUG
printf("---in fprint_steptrackerpath()---\n");
#endif

   fprintf(fp, " T %4d x %lf y %lf\n", t, Tracker.x, Tracker.y);

#ifdef DEBUG
printf("---end fprint_steptrackerpath()---\n");
#endif

   }  /* fprint_steptrackerpath */

/********** fprint_stepnorthsouth ***********/
/* Called by:           step_output(), output.c
   Parameters:          t       current timestep
   Actions:             Called once per step to print tracker coordinates
			on y-axis.
*/
void fprint_stepnorthsouth(FILE *fp, int t)
   {
   int i, j;

#ifdef DEBUG
printf("---in fprint_stepnorthsouth()---\n");
#endif

   fprintf(fp, " T %4d target %lf tracker %lf y-diff %lf\n", t, Target.y, Tracker.y, Target.y-Tracker.y);

#ifdef DEBUG
printf("---end fprint_stepnorthsouth()---\n");
#endif

   }  /* fprint_stepnorthsouth */

/********** fprint_stepeastwest ***********/
/* Called by:           step_output(), output.c
   Parameters:          t       current timestep
   Actions:             Called once per step to print tracker coordinates
			on x-axis.
*/
void fprint_stepeastwest(FILE *fp, int t)
   {
   int i, j;

#ifdef DEBUG
printf("---in fprint_stepeastwest()---\n");
#endif

   fprintf(fp, " T %4d target %lf tracker %lf x-diff %lf\n", t, Target.x, Tracker.x, Target.x-Tracker.x);

#ifdef DEBUG
printf("---end fprint_stepeastwest()---\n");
#endif

   }  /* fprint_stepeastwest */

/********** fprint_finalstats ***********/
/* Called by:           run_output(), output.c
   Parameters:          fp	where to print
   Actions:             Called at end of run to print final distances
			travelled by target and tracker.
*/
void fprint_finalstats(FILE *fp)
   {
   int i;
   double sum;
   int max_switches, min_switches;

#ifdef DEBUG
printf("---in fprint_finalstats()---\n");
#endif

   fprintf(fp, " %4d", Run_num);
   fprintf(fp, " distance_trav target %lf tracker %lf",
           Target.length, Tracker.length);
   fprintf(fp, " diff avg %lf max %lf min %lf",
           Tracker.total_difference/(double)Max_steps,
           Tracker.max_difference,
           Tracker.min_difference);

   sum = 0.0;
   max_switches = -1;
   min_switches = 2 * Max_steps;
   for (i=0; i<Pop_size; i++)
      {
      sum += Agent[i].count_switch;
      if (Agent[i].count_switch > max_switches)
         max_switches = Agent[i].count_switch;
      if (Agent[i].count_switch < min_switches)
         min_switches = Agent[i].count_switch;
      }
   fprintf(fp, " switch avg %lf max %d min %d\n",
      sum/(double)Pop_size, max_switches, min_switches);

#ifdef DEBUG
printf("---end fprint_finalstats()---\n");
#endif
   }  /* fprint_finalstats */

/********** fprint_stepagentaction ***********/
/* Called by:           step_output(), output.c
   Parameters:          t       current timestep
   Actions:             Called once per step.  Print what task each agent was
			performing in that time step.
*/
void fprint_stepagentaction(FILE *fp, int t)
   {
   int i;

#ifdef DEBUG
printf("---in fprint_stepagentaction()---\n");
#endif

// timestep removed to allow plotting using "plot matrix" in gnuplot
//   fprintf(fp, " T %4d  ", t);
   for (i=0; i<Pop_size; i++)
      {
      //fprintf(fp, " a%d", i);
      if(!Agent[i].dead)
         fprintf(fp, " %d", Agent[i].current_task);
      else
         fprintf(fp, " -1");
      }
   fprintf(fp, "\n");

#ifdef DEBUG
printf("---end fprint_stepagentaction()---\n");
#endif
   }  /* fprint_stepagentaction */

/********** fprint_stepagentactionwtime ***********/
/* Called by:           step_output(), output.c
   Parameters:          t       current timestep
   Actions:             Called once per step.  Print what task each agent was
                        performing in that time step.
			Same as fprint_stepagentaction() except extra first
			column which lists timestep.
*/
void fprint_stepagentactionwtime(FILE *fp, int t)
   {
   int i;

#ifdef DEBUG
printf("---in fprint_stepagentactionwtime()---\n");
#endif

   fprintf(fp, " T %4d  ", t);
   for (i=0; i<Pop_size; i++)
      {
      //fprintf(fp, " a%d", i);
      if(!Agent[i].dead)
         fprintf(fp, " %d", Agent[i].current_task);
      else
         fprintf(fp, " -1");
      }
   fprintf(fp, "\n");

#ifdef DEBUG
printf("---end fprint_stepagentactionwtime()---\n");
#endif
   }  /* fprint_stepagentactionwtime */

/********** fprint_stepagentactionxyz ***********/
/* Called by:           step_output(), output.c
   Parameters:          t       current timestep
   Actions:             Called once per step.  Print what task each agent was
                        performing in that time step.
*/
void fprint_stepagentactionxyz(FILE *fp, int t)
   {
   int i;

#ifdef DEBUG
printf("---in fprint_stepagentactionxyz()---\n");
#endif

   for (i=0; i<Pop_size; i++)
      {
      if(!Agent[i].dead)
         fprintf(fp, " T %4d agent %4d current_task %d\n",
                 t, i, Agent[i].current_task);
      else
         fprintf(fp, " T %4d agent %4d current_task %d\n",
                t, i, -1);
      }
   fprintf(fp, "\n");

#ifdef DEBUG
printf("---end fprint_stepagentactionxyz()---\n");
#endif

   }  /* fprint_stepagentactionxyz */

/********** fprint_finalagent ***********/
/* Called by:           run_output(), output.c
   Parameters:
   Actions:             Print how many timesteps each agent spent on each task
			and their thresholds.
			Prints a single line of data for each agent.
			For each agent, prints:
			a<agent#> <idle> <north> <east> <south> <west>
*/
void fprint_finalagent(FILE *fp)
   {
   int i;

#ifdef DEBUG
printf("---in fprint_finalagent()---\n");
#endif

   for (i=0; i<Pop_size; i++)
      {
      fprintf(fp, " agent %4d count-inesw %4d %4d %4d %4d %4d",
              i,
              Agent[i].count_idle,
              Agent[i].count_north,
              Agent[i].count_east,
              Agent[i].count_south,
              Agent[i].count_west);
      fprintf(fp, " thresh-nesw %lf %lf %lf %lf",
              // Agent[i].raw_thresh_north,
              // Agent[i].raw_thresh_east,
              // Agent[i].raw_thresh_south,
              // Agent[i].raw_thresh_west);
              Agent[i].thresh_north,
              Agent[i].thresh_east,
              Agent[i].thresh_south,
              Agent[i].thresh_west);
      fprintf(fp, " switch %d", Agent[i].count_switch);
      fprintf(fp, " killed %d\n", Agent[i].time_killed);
      }

#ifdef DEBUG
printf("---end fprint_finalagent()---\n");
#endif
   }  /* fprint_finalagent */

/********** fprint_agentthresh ***********/
/* Called by:
   Parameters:		n	which agent
   Actions:             Print agent number and it's thresholds.
*/
void fprint_agentthresh(FILE *fp, int n)
   {
   int j;

#ifdef DEBUG
printf("---in fprint_agentthresh()---\n");
#endif

//  19.09.12.AW:  This function is not currently active right now.
//                Did not delete because we may want to print this out.

#ifdef OUT
   fprintf(fp, " Agent %d ", n);
   for (j=0; j<Nest.num_tasks; j++)
      {
      fprintf(fp, " %s %lf ", Nest.task[j].name, Agent[n].thresh[j]);
      }
      fprintf(fp, "\n");
#endif

#ifdef DEBUG
printf("---end fprint_agentthresh()---\n");
#endif
   }  /* fprint_agentthresh */

// HDM; 2019.09.19
/********** fprint_intensities **********/
/* Parameters:      fp  pointer to file
   Called by:       run_output
   Actions:         print the average intensity, by task, for each agent
*/
void fprint_intensities(FILE *fp)
    {
    for(int i = 0; i < Pop_size; i++)
        {
        double avg_n = Agent[i].int_no_act_n/Max_steps;
        double avg_e = Agent[i].int_no_act_e/Max_steps;
        double avg_s = Agent[i].int_no_act_s/Max_steps;
        double avg_w = Agent[i].int_no_act_w/Max_steps;

        if(Agent[i].count_north > 0)
            avg_n = Agent[i].int_tot_n/Agent[i].count_north;
        if(Agent[i].count_east > 0)
            avg_e = Agent[i].int_tot_e/Agent[i].count_east;
        if(Agent[i].count_south > 0)
            avg_s = Agent[i].int_tot_s/Agent[i].count_south;
        if(Agent[i].count_west > 0)
            avg_w = Agent[i].int_tot_w/Agent[i].count_west;

        fprintf(fp, " %5d  Avg N: %lf  Avg S: %lf  Avg E: %lf  Avg W: %lf ", i,  avg_n,  avg_s,  avg_e,  avg_w);
        fprintf(fp, "\n");
        fprintf(fp, "        Min N: %lf  Min S: %lf  Min E: %lf  Min W: %lf ", Agent[i].int_min_n,  Agent[i].int_min_s,  Agent[i].int_min_e,  Agent[i].int_min_w);
        fprintf(fp, "\n");
        fprintf(fp, "        Max N: %lf  Max S: %lf  Max E: %lf  Max W: %lf ", Agent[i].int_max_n,  Agent[i].int_max_s,  Agent[i].int_max_e,  Agent[i].int_max_w);
        fprintf(fp, "\n\n");
        }
    }  /* fprint_intensities */

// HDM; 2019.10.10
/********** fprint_stephistnorth **********/
/* Parameters:      fp  pointer to file
                    timestep  int representing current step of simulation
   Called by:       step_output
   Actions:         print intensity distribution data for current timestep
*/
void fprint_stephistnorth(FILE *fp, int timestep)
{
    for(int i = 0; i < HISTOGRAM_SIZE; i++)
    {
        fprintf(fp, " T %5d Bin %4d Count %4d \n", timestep, i, Tracker.intensity_north_dist[i]);
    }
}

// HDM; 2019.10.10
/********** fprint_stephistsouth **********/
/* Parameters:      fp  pointer to file
                    timestep  int representing current step of simulation
   Called by:       step_output
   Actions:         print intensity distribution data for current timestep
*/
void fprint_stephistsouth(FILE *fp, int timestep)
{
    for(int i = 0; i < HISTOGRAM_SIZE; i++)
    {
        fprintf(fp, " T %5d Bin %4d Count %4d \n", timestep, i, Tracker.intensity_south_dist[i]);
    }
} /* fprint_stephistsouth */

// HDM; 2019.10.10
/********** fprint_stephisteast **********/
/* Parameters:      fp  pointer to file
                    timestep  int representing current step of simulation
   Called by:       step_output
   Actions:         print intensity distribution data for current timestep
*/
void fprint_stephisteast(FILE *fp, int timestep)
{
    for(int i = 0; i < HISTOGRAM_SIZE; i++)
    {
        fprintf(fp, " T %5d Bin %4d Count %4d \n", timestep, i, Tracker.intensity_east_dist[i]);
    }
} /* fprint_stephisteast */

// HDM; 2019.10.10
/********** fprint_stephistwest **********/
/* Parameters:      fp  pointer to file
                    timestep  int representing current step of simulation
   Called by:       step_output
   Actions:         print intensity distribution data for current timestep
*/
void fprint_stephistwest(FILE *fp, int timestep)
{
    for(int i = 0; i < HISTOGRAM_SIZE; i++)
    {
        fprintf(fp, " T %5d Bin %4d Count %4d \n", timestep, i, Tracker.intensity_west_dist[i]);
    }
} /* fprint_stephistwest */

// LR; 2020.02.14
/********** fprint_intensityranges **********/
/* Parameters:      fp  pointer to file
   Actions:         Print the intensity aging ranges for each agent
			For each agent, prints:
			agent: <agent#>   intensity aging ranges: n=[min, max], s=[min, max], e=[min, max], w=[min, max]
*/
void fprint_intensityranges(FILE *fp)
   {
   int i;

#ifdef DEBUG
printf("---in fprint_intensityranges()---\n");
#endif

   for (i=0; i<Pop_size; i++)
      {
        fprintf(fp, "agent: %d   intensity aging ranges:\tn=[%f, %f], s=[%f, %f], e=[%f, %f], w=[%f, %f]\n",
          i,  Agent[i].int_aging_min_n, Agent[i].int_aging_max_n,
              Agent[i].int_aging_min_s, Agent[i].int_aging_max_s,
              Agent[i].int_aging_min_e, Agent[i].int_aging_max_e,
              Agent[i].int_aging_min_w, Agent[i].int_aging_max_w);
      }

#ifdef DEBUG
printf("---end fprint_intensityranges()---\n");
#endif
}  /* fprint_intensityranges */

/********** fprint_stepthreshnorth ***********/
/* Created:             20.04.17.ASW
   Called by:           step_output(), output.c
   Parameters:          t       current timestep
   Actions:             Called once per step.  Print threshold of each agent 
                        in that time step. 
                        Only called for variable thresholds.
*/
void fprint_stepthreshnorth(FILE *fp, int t)
   {
   int i;

#ifdef DEBUG
printf("---in fprint_stepthreshnorth()---\n");
#endif

// timestep removed to allow plotting using "plot matrix" in gnuplot
   for (i=0; i<Pop_size; i++)
      {
      if(!Agent[i].dead)
         fprintf(fp, " %lf", Agent[i].thresh_north);
      else
         fprintf(fp, " -1");
      }
   fprintf(fp, "\n");

#ifdef DEBUG
printf("---end fprint_stepthreshnorth()---\n");
#endif
   }  /* fprint_stepthreshnorth */

/********** fprint_stepthreshsouth ***********/
/* Created:             20.04.17.ASW
   Called by:           step_output(), output.c
   Parameters:          t       current timestep
   Actions:             Called once per step.  Print threshold of each agent
                        in that time step.
                        Only called for variable thresholds.
*/
void fprint_stepthreshsouth(FILE *fp, int t)
   {
   int i;

#ifdef DEBUG
printf("---in fprint_stepthreshsouth()---\n");
#endif

// timestep removed to allow plotting using "plot matrix" in gnuplot
   for (i=0; i<Pop_size; i++)
      {
      if(!Agent[i].dead)
         fprintf(fp, " %lf", Agent[i].thresh_south);
      else
         fprintf(fp, " -1");
      }
   fprintf(fp, "\n");

#ifdef DEBUG
printf("---end fprint_stepthreshsouth()---\n");
#endif
   }  /* fprint_stepthreshsouth */

/********** fprint_stepthresheast ***********/
/* Created:             20.04.17.ASW
   Called by:           step_output(), output.c
   Parameters:          t       current timestep
   Actions:             Called once per step.  Print threshold of each agent
                        in that time step.
                        Only called for variable thresholds.
*/
void fprint_stepthresheast(FILE *fp, int t)
   {
   int i;

#ifdef DEBUG
printf("---in fprint_stepthresheast()---\n");
#endif

// timestep removed to allow plotting using "plot matrix" in gnuplot
   for (i=0; i<Pop_size; i++)
      {
      if(!Agent[i].dead)
         fprintf(fp, " %lf", Agent[i].thresh_east);
      else
         fprintf(fp, " -1");
      }
   fprintf(fp, "\n");

#ifdef DEBUG
printf("---end fprint_stepthresheast()---\n");
#endif
   }  /* fprint_stepthresheast */

/********** fprint_stepthreshwest ***********/
/* Created:             20.04.17.ASW
   Called by:           step_output(), output.c
   Parameters:          t       current timestep
   Actions:             Called once per step.  Print threshold of each agent
                        in that time step.
                        Only called for variable thresholds.
*/
void fprint_stepthreshwest(FILE *fp, int t)
   {
   int i;

#ifdef DEBUG
printf("---in fprint_stepthreshwest()---\n");
#endif

// timestep removed to allow plotting using "plot matrix" in gnuplot
   for (i=0; i<Pop_size; i++)
      {
      if(!Agent[i].dead)
         fprintf(fp, " %lf", Agent[i].thresh_west);
      else
         fprintf(fp, " -1");
      }
   fprintf(fp, "\n");

#ifdef DEBUG
printf("---end fprint_stepthreshwest()---\n");
#endif
   }  /* fprint_stepthreshwest */

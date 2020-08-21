/* global.h
   19.07.11.AW	Created.
		File of global variables included in main.c.
		All other .c files should include extern.h instead.
*/

/********** run parameters read in **********/
int Rerun;
char *Run_num_file;
char *Output_path;
int Print_params;               /* if 1, print params at start of run */
int Print_step;                 /* if 1, print status each timestep */

int Max_steps;			/* max timesteps to run simulation */
int Pop_size;
double Thresh_init;		/* initialize thresholds */
int Thresh_dynamic;		/* turn on/off dynamic thresholds */
double Thresh_increase;
double Thresh_decrease;
double Prob_check;
char *Target_path;
double Range;			/* radius around zero of ok values */
   /* Range gives the range of the distribution of values */
int Gnuplot_plots;

/********** parameters read in from elsewhere **********/
int Run_num;                    /* read in from Run_num_file */
int Max_num_output_files;       /* read in from opfiles.default */
long Seed;                      /* random seed, read in or generated */

/********** array of output files **********/
OUTPUT_FILE *Output_file;

/********** simulation global variables **********/

AGENT *Agent;
TRACKER Tracker;
TARGET Target;
int Num_tasks;
int Num_alive;                  /* number of agents alive - initially Pop_size */

/* HDM; intensity variation; 2019.09.12 */
/*********** variations being used ***************/
int Intensity_variation;
int Intensity_aging;
double Intensity_aging_min;
double Intensity_aging_max;
double Intensity_aging_up;
double Intensity_aging_down;
int Intensity_distribution;
/* LR; heterogeneous intensity ranges; 2020.02.08 */
int Hetero_center_distr;
int Hetero_radius_distr;
/* 2020.02.15 */
double Hetero_center_mu;
double Hetero_center_std;
double Hetero_radius_mu;
double Hetero_radius_std;
/* 2020.02.27 */
double Hetero_range_max;
double Hetero_range_min;
double Hetero_radius_max;
double Hetero_radius_min;

/* HDM; intensity variation; 2019.10.24 */
double Response_prob;

/* HDM; related to response probability; 2020.03.19 */
int Kill_number;
int First_extinction;
int Extinction_period;

// not currently used
char *Task_selection;

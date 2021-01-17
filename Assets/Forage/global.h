/* global.h
   14.10.15.AW	Revised for FLAIRS paper simulation.
   08.05.26.AW	Created.
		File of global variables included in main.c.
		All other .c files should include extern.h instead.
*/

/********** run parameters read in **********/
int Rerun;
char *Run_num_file;
char *Output_path;
int Print_params;               /* if 1, print params at start of run */
int Print_agent_paths;		/* if 1, print paths of each active agent */
int Print_agent_memory;		/* if 1, print memory of each agent */
int Print_agent_final_memory;	/* if 1, print final memory of each agent */

int Max_steps;			/* timesteps per day active */
int Pop_size;			/* number of agents */
double Init_thresh;		/* how to initialize thresholds */
double Max_thresh;		/* maximum possible threshold */
double Min_thresh;		/* minimum possible threshold */
double Prob_check;		/* prob check tasks each timestep */

/********** parameters read in from elsewhere **********/
int Run_num;                    /* read in from Run_num_file */
int Max_num_output_files;       /* read in from opfiles.default */
long Seed;                      /* random seed, read in or generated */

/********** array of output files **********/
OUTPUT_FILE *Output_file;

/********** simulation global variables **********/
NEST Nest;
AGENT *Agent;
ENVIRONMENT Envr;
double Response_prob;
int Max_sim_time;
double Positive_reinforcement;
double Negative_reinforcement;

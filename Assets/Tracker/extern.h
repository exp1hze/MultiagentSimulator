/* extern.h
   91.07.11.AW	Created.
*/

extern int Rerun;
extern char *Run_num_file;
extern char *Output_path;
extern int Print_params;
extern int Print_step;
extern int Max_steps;
extern int Pop_size;
extern double Thresh_init;
extern int Thresh_dynamic;
extern double Thresh_increase;
extern double Thresh_decrease;
extern double Prob_check;
extern char *Target_path;
extern double Circle_radius;
extern double Range;
extern int Gnuplot_plots;
extern int Run_num;
extern int Max_num_output_files;
extern long Seed;
extern OUTPUT_FILE *Output_file;
extern AGENT *Agent;
extern TRACKER Tracker;
extern TARGET Target;
extern int Num_tasks;
extern char *Task_selection;
extern int Intensity_variation;     /* HDM; intensity variation; 2019.09.12 */
extern int Intensity_aging;         /* HDM; intensity variation; 2019.09.19 */
extern double Intensity_aging_min;  /* HDM; intensity variation; 2019.09.19 */
extern double Intensity_aging_max;  /* HDM; intensity variation; 2019.09.19 */
extern double Intensity_aging_up;   /* HDM; intensity variation; 2019.09.19 */
extern double Intensity_aging_down; /* HDM; intensity variation; 2019.09.19 */
extern int Intensity_distribution;  /* HDM; intensity variation; 2019.10.14 */
extern int Hetero_center_distr;     /* LR; heterogeneous intensity ranges; 2020.02.08 */
extern int Hetero_radius_distr;     /* LR; heterogeneous intensity ranges; 2020.02.08 */
extern double Hetero_center_mu;     /* LR; heterogeneous intensity ranges; 2020.02.15 */
extern double Hetero_center_std;    /* LR; heterogeneous intensity ranges; 2020.02.15 */
extern double Hetero_radius_mu;     /* LR; heterogeneous intensity ranges; 2020.02.15 */
extern double Hetero_radius_std;    /* LR; heterogeneous intensity ranges; 2020.02.15 */
extern double Hetero_range_max;     /* LR; heterogeneous intensity ranges; 2020.02.27 */
extern double Hetero_range_min;     /* LR; heterogeneous intensity ranges; 2020.02.27 */
extern double Hetero_radius_max;    /* LR; heterogeneous intensity ranges; 2020.02.27 */
extern double Hetero_radius_min;    /* LR; heterogeneous intensity ranges; 2020.02.27 */
extern double Response_prob;        /* HDM; variable response prob; 2019.10.24 */
extern int Kill_number;             /* HDM; related to response prob; 2020.03.19 */
extern int First_extinction;        /* HDM; time step at which agents are first killed */
extern int Extinction_period;       /* HDM; period at which extinctions occur */
extern int Num_alive;               /* HDM; number of agents still alive */
extern double Spontaneous_response_prob; /* NB; variable spontaneous response when response threshold not met; 2020.05.19; */
double SRP_gaussian_mu;             /* NB; Spontaneous_response_prob standard distribution; 2020.07.06 */
double SRP_gaussian_std; 
double RP_gaussian_mu;              /* NB; Response_prob standard distribution; 2020.07.06 */
double RP_gaussian_std; 
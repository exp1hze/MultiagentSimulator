/* fxn.c
   14.10.15.AW	Created.
   4.10.19.JG Updated distributions.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#include "types.h"
#include "extern.h"
#include "fxn.h"
#include "random.h"
#include "output.h"
#include "ftarget.h"
#include "ftracker.h"

//#define DEBUG 1
//#define DEBUG_AGENT 1

#define LAMBDA_P 5
#define LAMBDA_E 5
#define POISSON_K_RANGE 20
#define EXP_X_RANGE 5
#define LOG_K_RANGE 20
#define LOG_P .50
#define HISTOGRAM_SIZE ((Intensity_aging_max - Intensity_aging_min) * 10)

/*************** factorial *****************/
/* parameters: k
   called by: init_agent(), fxn.c
   actions: factorial for poisson calculation
*/
int factorial(double k)
   {
   int n = (int)k;
   return (n == 0) ? 1 : n * factorial(n - 1);
   }

/********** init_fxn **********/
/* paramters:
   called by:	run_sim(), sim.c
   actions:
*/
int init_fxn()
   {
   int error;
   int i;

#ifdef DEBUG
printf("---in init_fxn()---\n");
#endif

   Num_tasks = 2;

   /* initialize number of agents still alive */
   Num_alive = Pop_size;

   /* allocate space */
   Agent = (AGENT *)malloc(Pop_size * sizeof(AGENT) );
   if (Agent == NULL)
      {
      printf(" Error(init_fxn): cannot allocate space: Agent\n");
      return ERROR;
      }   /* if */

   if(Intensity_aging)
      {
         int histogram_size = (Intensity_aging_max - Intensity_aging_min) * 10;
         Tracker.intensity_north_dist = malloc(HISTOGRAM_SIZE * sizeof(int));
         Tracker.intensity_south_dist = malloc(HISTOGRAM_SIZE * sizeof(int));
         Tracker.intensity_east_dist = malloc(HISTOGRAM_SIZE * sizeof(int));
         Tracker.intensity_west_dist = malloc(HISTOGRAM_SIZE * sizeof(int));
      }

   /* initialize target */
   error = init_target();
   if (error == ERROR)  return ERROR;

   /* initialize agents */
   for (i=0; i<Pop_size; i++)
      {
      error = init_agent(i);
      if (error == ERROR)  return ERROR;
      }  /* for */
   if (Print_params)  fprint_pop(stdout);

   /* HDM; moved initialize tracker to after initialize agents; 2019.09.12 */
   /* initialize tracker */
   error = init_tracker();
   if (error == ERROR)  return ERROR;

   /* print anything that needs to be printed */
   start_output();

#ifdef DEBUG
printf("---end init_fxn()---\n");
#endif
   return OK;
   }  /* init_fxn */

/********** end_fxn **********/
/* paramters:
   called by:	run_sim(), sim.c
   actions:
*/
int end_fxn()
   {
   int r;
#ifdef DEBUG
printf("---in end_fxn()---\n");
#endif

   free(Agent);

#ifdef DEBUG
printf("---end end_fxn()---\n");
#endif
   return OK;
   }  /* end_fxn */

/********** run_fxn **********/
/* paramters:
   called by:   run_sim(), sim.c
   actions:
*/
int run_fxn()
   {
   int t;
   int error;
#ifdef DEBUG
printf("---in run_fxn()---\n");
#endif

   for (t=0; t<Max_steps; t++)
      {
      if (Print_step)
         {
         printf(" T %3d target %lf %lf tracker %lf %lf dist %lf",
             t, Target.x, Target.y, Tracker.x, Tracker.y, Tracker.difference);
         printf(" pathlen tar %lf trk %lf", Target.length, Tracker.length);
         printf(" step_len tar %lf trk %lf\n",
             Target.step_len, Tracker.current_step_len);
         }

      error = step_run(t);
      if (error == ERROR)  return ERROR;

      step_output(t);
      }  /* for h */

#ifdef DEBUG
printf("---end run_fxn()---\n");
#endif
   return OK;
   }  /* run_fxn */

/********** step_run **********/
/* paramters:   t       which timestep
   called by:   run_fxn(), fxn.c
   actions:
*/
int step_run(int t)
   {
   int error;
   int i, j;
   double rand, temp_prob_check;

#ifdef DEBUG
printf("---in step_run()---\n");
#endif
// fprintf(stderr, "before move_target\n");
   // move target
   error = move_target(t);
   if (error == ERROR)  return ERROR;
// fprintf(stderr, "after move_target\n");

   // move tracker
   error = move_tracker(t);
   if (error == ERROR)  return ERROR;
// fprintf(stderr, "after move_tracker\n");

   // Need to calculate the difference again here because the other time
   // it was calculated was before the tracker moved.  The value that we
   // want to print in the output files is the difference after the target
   // moved and after the tracker attempted to move to match the target.
   // So we need to re-calculate this difference after the tracker has
   // also moved.
   Tracker.difference = sqrt( (Target.x - Tracker.x) * (Target.x - Tracker.x) +
                    (Target.y - Tracker.y) * (Target.y - Tracker.y) );
   // sum so that average can be calculated
   Tracker.total_difference += Tracker.difference;
   // keep track of max and min differences
   if (Tracker.difference > Tracker.max_difference)
      Tracker.max_difference = Tracker.difference;
   if (Tracker.difference < Tracker.min_difference)
      Tracker.min_difference = Tracker.difference;

#ifdef DEBUG
printf("---end step_run()---\n");
#endif
   return OK;
   }  /* step_run */

// HDM; 2019.09.19
/********** rand_agent_intensity **********/
/* parameters:  none
   called by:   init_agent(), fxn.c
   actions: calculate random intensity value using Box Muller
*/
double rand_agent_intensity()
    {
#ifdef DEBUG
printf("---in rand_agent_intensity()---\n");
#endif

    double rand1, rand2, r, theta;	// box muller variables
    double intensity = 0.0;         // return value
    double divisor = 1.0;           // 1/divisor is std deviation

    // NOTE: r * cos(theta) and r * sin(theta) give values
    // approximately -3.0 -- 3.0
    if(Intensity_distribution == 1)
        {
        double range = Intensity_aging_max - Intensity_aging_min;       // size of the intensity range
        double st_dev = range/6.0;                                      // standard deviation of the distribution
        double mu = Intensity_aging_min + range/2.0;                    // mean of the distribution

        intensity = box_muller(mu, st_dev);
        }
    else if(Intensity_distribution == 2)
        {
        rand1 = funiform(Intensity_aging_max - Intensity_aging_min);
        intensity = rand1 + Intensity_aging_min;
        }

#ifdef DEBUG
printf("---end rand_agent_intensity()---\n");
#endif

    return intensity;

    }  /* rand_agent_intensity */


/********** init_agent **********/
/* paramters:	n	agent number
   called by:	init_fxn(), fxn.c
   actions:
*/
int init_agent(int n)
   {
   int i;
   int j;
   int error;

#ifdef DEBUG
printf("---in init_agent()---\n");
#endif

   Agent[n].index = n;

   // Initialize agent thresholds and (if applicable) threshold ranges.
   // If dynamic thresholds are turned on, initialize the threshold range for
   // each agent; else initialize static threshold w/value within range.
   // Thresh_dynamic = 0   dynamic thresholds off, static thresholds
   // Thresh_dynamic = 1   dynamic thresholds on w/range [0.0,1.0]
   // Thresh_dynamic = 2   dynamic thresholds on, range min/max uniformly 
   //                      distributed within bottom/top half of [0.0,1.0]
   // Thresh_dynamic = 3   dynamic thresholds on, range within two uniformly
   //                      random values within [0.0,1.0]
   if (Thresh_dynamic == 0)
      {
      // Static thresholds.  Thresholds expected to fall within [0.0,1.0].
      // initialize agent raw thresholds
      error = init_raw_thresholds(n);
      if (error == ERROR)  return ERROR;
      }
   else if (Thresh_dynamic == 1)
      {
      // Dynamic thresholds within the range [0.0,1.0].
      // initialize agent raw thresholds
      error = init_raw_thresholds(n);
      if (error == ERROR)  return ERROR;

      // Set range of [0.0,1.0] for all tasks
      Agent[n].raw_thresh_min_north = 0.0;
      Agent[n].raw_thresh_min_south = 0.0;
      Agent[n].raw_thresh_min_east = 0.0;
      Agent[n].raw_thresh_min_west = 0.0;
      Agent[n].raw_thresh_max_north = 1.0;
      Agent[n].raw_thresh_max_south = 1.0;
      Agent[n].raw_thresh_max_east = 1.0;
      Agent[n].raw_thresh_max_west = 1.0;
      }
   else if (Thresh_dynamic == 2)
      {
      // Dynamic thresholds.  Each agent has it's own unique thresh_min and
      // thresh_max for each task.  Minimum of range randomly initialized
      // within 0 and 0.49; maximum of range randomly initialized within
      // 0.51 and 1.0.
      error = init_dynamic_threshold_range_TD2(n);
      if (error == ERROR)  return ERROR;
      }
   else if (Thresh_dynamic == 3)
      {
      // Dynamic thresholds.  Each agent has it's own unique thresh_min and
      // thresh_max for each task.  Minimum and maximum of range are randomly
      // generated numbers within 0 and 1.0.  Lower value is set to minimum.
      error = init_dynamic_threshold_range_TD3(n);
      if (error == ERROR)  return ERROR;
      }
   else
      {
      printf(" Error(init_agent):  Invalid value for Thresh_dynamic: %d\n",
		Thresh_dynamic);
      return ERROR;
      }

   /* scale thresholds from [0.0,1.0] to [0.0,Range] */
   scale_thresholds(n);

   // set the response_prob value for each agent:
   // if Response_prob == 3, use normal distribution
   // if Response_prob == 2, each agent gets a random response_prob value
   // else if 0 <= Response_prob <= 1, set all agents' response_prob equal
   // to Response_prob
   if (Response_prob == 3.0)
      {
         do {
            Agent[n].response_prob = box_muller(RP_gaussian_mu, RP_gaussian_std);
         }
         while (Agent[n].response_prob > 1.0 || Agent[n].response_prob < 0.0);
      }
   else if (Response_prob == 2.0)
      {
      /* initialize to random value */
      Agent[n].response_prob = knuth_random();
      }  /* if */
   else if (Response_prob <=1.0)
      {
      Agent[n].response_prob = Response_prob;
      }  /* else if */
   else
      {
      printf(" Error(init_agent): Invalid value for Response_prob: %lf\n",
             Response_prob);
      return ERROR;
      }  /* else */

   // NB; 2020.06.23
   // set the spontaneous_response_prob value for each agent:
   // if Spontaneous_response_prob == 3, use normal distribution
   // if Spontaneous_response_prob == 2, each agent gets a random value
   // else if 0 <= Spontaneous_response_prob < 1, set all agents' equal to it
   // else if Spontaneous_response_prob == 1, set agent = 1-Agent[i].response_prob
   if (Spontaneous_response_prob == 3.0)
      {
         do {
            Agent[n].spontaneous_response_prob = box_muller(SRP_gaussian_mu, SRP_gaussian_std);
         }
         while (Agent[n].spontaneous_response_prob > 1.0 || Agent[n].spontaneous_response_prob < 0.0);
      }
   else if (Spontaneous_response_prob == 2.0)
      {
      /* initialize to random value */
      Agent[n].spontaneous_response_prob = knuth_random();
      }  /* if */
   else if (Spontaneous_response_prob == 1.0)
      {
      Agent[n].spontaneous_response_prob = 1-Agent[n].response_prob;
      }  /* else if */
   else if (Spontaneous_response_prob < 1.0)
      {
         Agent[n].spontaneous_response_prob = Spontaneous_response_prob;
      }  /* else if */
   else
      {
      printf(" Error(init_agent): Invalid value for Spontaneous_response_prob: %lf\n",
             Spontaneous_response_prob);
      return ERROR;
      }  /* else */

   // set the prob_check value for each agent:
   // if Prob_check == 0, each agent gets a random prob_check value
   // else if 0 < Prob_check <= 1, set all agents' prob_check to Prob_check
   if (Prob_check == 0.0)
      {
      /* initialize to random value */
      Agent[n].prob_check = knuth_random();
      }  /* if */
   else if (Prob_check <=1.0)
      {
      Agent[n].prob_check = Prob_check;
      }  /* else if */
   else
      {
      printf(" Error(init_agent): Invalid value for Prob_check: %lf\n",
             Prob_check);
      return ERROR;
      }  /* else */

   /* init agent activity to nothing */
   Agent[n].current_task = 0;
   Agent[n].previous_task = 0;

   /* init activity tracking to zero */
   Agent[n].count_north = 0;
   Agent[n].count_east = 0;
   Agent[n].count_south = 0;
   Agent[n].count_west = 0;
   Agent[n].count_idle = 0;
   Agent[n].count_switch = 0;
   Agent[n].count_switch_spontaneous = 0;

   // initialize agent intensities
   error = init_intensities(n);
   if (error == ERROR)  return ERROR;

   /* HDM; 2020.03.19 */
   Agent[n].dead = 0;
   Agent[n].time_killed = -1;

#ifdef DEBUG
printf("---end init_agent()---\n");
#endif
   return OK;
   }  /* init_agent */

/********** scale_thresholds **********/
/* created:	20.04.16.ASW
   parameters:	n	agent number
   called by:   init_agent(), fxn.c
   actions:	scale the raw thresholds which are relative to the range
		[0.0,1.0] to a range of [0.0,Range].
*/
void scale_thresholds(int n)
   {
#ifdef DEBUG
printf("---in scale_thresholds()---\n");
#endif

   // scale thresholds
   Agent[n].thresh_north = Agent[n].raw_thresh_north * Range;
   Agent[n].thresh_south = Agent[n].raw_thresh_south * Range;
   Agent[n].thresh_east = Agent[n].raw_thresh_east * Range;
   Agent[n].thresh_west = Agent[n].raw_thresh_west * Range;

   // scale threshold ranges
   if (Thresh_dynamic == 1 || Thresh_dynamic == 2 || Thresh_dynamic == 3)
      {
      Agent[n].thresh_min_north = Agent[n].raw_thresh_min_north * Range;
      Agent[n].thresh_min_south = Agent[n].raw_thresh_min_south * Range;
      Agent[n].thresh_min_east = Agent[n].raw_thresh_min_east * Range;
      Agent[n].thresh_min_west = Agent[n].raw_thresh_min_west * Range;
      Agent[n].thresh_max_north = Agent[n].raw_thresh_max_north * Range;
      Agent[n].thresh_max_south = Agent[n].raw_thresh_max_south * Range;
      Agent[n].thresh_max_east = Agent[n].raw_thresh_max_east * Range;
      Agent[n].thresh_max_west = Agent[n].raw_thresh_max_west * Range;
      }

#ifdef DEBUG
printf("---end scale_thresholds()---\n");
#endif
   }  /* scale_thresholds */


/********** init_target **********/
/* parameters:
   called by:   init_fxn(), fxn.c
   actions:	initialize target
*/
int init_target()
   {
   int i;

#ifdef DEBUG
printf("---in init_target()---\n");
#endif

   /* initialize working area and length of path travelled */
//   Target.width = 100;
//   Target.height = 100;
   /* initialize length of path travelled */
   Target.length = 0;
   /* angle is only use in random path right now, but init to zero
      so it can be printed as a parameter */
   Target.angle = 0;

   /* allocate space */
   Target.abbrev = (char *)malloc(INPUT_LINE_LEN * sizeof(char));

   /* initialize path details */
   if ( !strcmp(Target_path, "square") )
      {
      /* target travels a 60x60 square with corners at 20,20 and 80,80 */
      sprintf(Target.abbrev, "squ");
      /* set start location to bottom left, go clockwise */
      Target.x = 20;
      Target.y = 20;
      /* as a result, initial movement will be along left side */
      sprintf(Target.side, "left");
      }
   else if ( !strcmp(Target_path, "square10") )
      {
      /* target travels a 10x10 square with corners at 20,20 and 30,30 */
      sprintf(Target.abbrev, "s10");
      /* set start location to bottom left, go clockwise */
      Target.x = 20;
      Target.y = 20;
      /* as a result, initial movement will be along left side */
      sprintf(Target.side, "left");
      }
   else if ( !strcmp(Target_path, "circle") )
      {
      sprintf(Target.abbrev, "cir");
      /* set start location to top center, go clockwise, radius of 30 */
      /* center at 0, 0 */
      Target.x = 0;
      Target.y = Circle_radius;
      //Target.y = 30;
      }
   else if ( !strcmp(Target_path, "random") )
      {
      sprintf(Target.abbrev, "ran");
      /* set start location to 0,0 */
      Target.x = 0;
      Target.y = 0;
      /* randomly generate angle between 0 and 2*PI for init orientation */
      Target.angle = knuth_random() * 2 * M_PI;
      }
   else if ( !strcmp(Target_path, "random_manhattan") )
      {
      sprintf(Target.abbrev, "man");
      /* set start location to 0,0 */
      Target.x = 0;
      Target.y = 0;
      }
   else if ( !strcmp(Target_path, "west") )
      {
      sprintf(Target.abbrev, "wes");
      /* set start location to 0,0 */
      Target.x = 0;
      Target.y = 0;
      }
   else if ( !strcmp(Target_path, "northeast") )
      {
      sprintf(Target.abbrev, "noe");
      /* set start location to 0,0 */
      Target.x = 0;
      Target.y = 0;
      }
   else if ( !strcmp(Target_path, "northeast_accel") )
      {
      sprintf(Target.abbrev, "nea");
      /* set start location to 0,0 */
      Target.x = 0;
      Target.y = 0;
      Target.change = 1.0;
      }
   else if ( !strcmp(Target_path, "sharp") )
      {
      sprintf(Target.abbrev, "sharp");
      Target.x = 0;
      Target.y = 0;
      /* randomly generate angle between -PI and PI for init orientation */
      Target.angle = funiform(2 * M_PI) - M_PI;
      /* randomly generate a probability of changing directions
         between 10 and 50 percent */
      Target.change_probability = knuth_random() * 0.4 + 0.1;
      }
   else if ( !strcmp(Target_path, "random_steep") )
      {
      sprintf(Target.abbrev, "rand_steep");
      Target.x = 0;
      Target.y = 0;
      }
   else if ( !strcmp(Target_path, "zigzag") )
      {
      sprintf(Target.abbrev, "zigzag");
      Target.x = 0;
      Target.y = 0;
      Target.direction = 1;  // Start at one, moving up
      Target.angle = atan(Target.amplitude/(Target.period/4));
printf(" zigzag angle %lf %lf\n", Target.angle, Target.angle/M_PI*180);
      }
   else if ( !strcmp(Target_path, "scurve") )
      {
      sprintf(Target.abbrev, "scurve");
      Target.x = 0;
      Target.y = 0.01;
      Target.direction = 1;  // Start at one, add angle
      Target.angle = M_PI/2;
      Target.change = M_PI / (Target.period/Target.step_len);
                // Pi divided by min steps needed per period
printf(" sine_like angle %lf %lf angle change %lf %lf\n",
       Target.angle, Target.angle/M_PI*180,
       Target.change, Target.change/M_PI*180);
      }
   else if ( !strcmp(Target_path, "sine") )
      {
      sprintf(Target.abbrev, "sine");
      Target.x = 0;
      Target.y = 0;
      }
   else if ( !strcmp(Target_path, "sine2") )
      {
      sprintf(Target.abbrev, "sine2");
      Target.x = 0;
      Target.y = 0;
      }
   else if ( !strcmp(Target_path, "figure_8") )
      {
      sprintf(Target.abbrev, "figure_8");
      Target.x = 0;
      Target.y = 0;
      }
      else if ( !strcmp(Target_path, "cross_square") )
      {
         sprintf(Target.abbrev, "cross");
         Target.x = 20;
         Target.y = 20;
      }
   else if ( !strcmp(Target_path, "steep") )
      {
         sprintf(Target.abbrev, "steep");
         Target.x = 0;
         Target.y = 0;
      }
   else if ( !strcmp(Target_path, "random_steep") )
      {
         sprintf(Target.abbrev, "rand_steep");
         Target.x = 0;
         Target.y = 0;
      }
   else if ( !strcmp(Target_path, "zigzag") )
      {
         sprintf(Target.abbrev, "zigzag");
         Target.x = 0;
         Target.y = 0;
      }
   else if ( !strcmp(Target_path, "sine") )
      {
         sprintf(Target.abbrev, "sine");
         Target.x = 0;
         Target.y = 0;
      }
   else if ( !strcmp(Target_path, "figure_8") )
      {
      sprintf(Target.abbrev, "figure_8");
      Target.x = 0;
      Target.y = 0;
      }
   else
      {
      printf(" Error(init_target): invalid target path: %s\n", Target_path);
      return ERROR;
      }

#ifdef DEBUG
printf("---end init_target()---\n");
#endif
   return OK;
   }  /* init_target */

/********** init_tracker **********/
/* paramters:
   called by:   init_fxn(), fxn.c
   actions:     initialize tracker
*/
int init_tracker()
   {
   int i;

#ifdef DEBUG
printf("---in init_tracker()---\n");
#endif

   Tracker.max_step_len = Tracker.step_ratio * Target.step_len;
   Tracker.length = 0;
   Tracker.x = Target.x;
   Tracker.y = Target.y;
   Tracker.total_difference = 0;
   Tracker.max_difference = -1;
   Tracker.min_difference = 9999999999;

   /* HDM; sum intensities of all agents; 2019.09.12 */
   Tracker.intensity_all_north = 0.0;
   Tracker.intensity_all_south = 0.0;
   Tracker.intensity_all_east = 0.0;
   Tracker.intensity_all_west = 0.0;
   for (int i = 0; i < Pop_size; i++)
      {
      Tracker.intensity_all_north += Agent[i].intensity_north;
      Tracker.intensity_all_south += Agent[i].intensity_south;
      Tracker.intensity_all_east += Agent[i].intensity_east;
      Tracker.intensity_all_west += Agent[i].intensity_west;
      }
    // printf("total intensities north: %lf\n", Tracker.intensity_all_north);
    // printf("total intensities south: %lf\n", Tracker.intensity_all_south);
    // printf("total intensities east: %lf\n", Tracker.intensity_all_east);
    // printf("total intensities west: %lf\n", Tracker.intensity_all_west);

   // HDM; initialize histogram info for intensity aging
   if(Intensity_aging)
      {
      for (int i = 0; i < HISTOGRAM_SIZE; i++)
         {
         Tracker.intensity_north_dist[i] = 0;
         Tracker.intensity_south_dist[i] = 0;
         Tracker.intensity_east_dist[i] = 0;
         Tracker.intensity_west_dist[i] = 0;
         }
      }

#ifdef DEBUG
printf("---end init_tracker()---\n");
#endif
   return OK;
   }  /* init_tracker */

/********** print_fxn_params **********/
/* parameters:  fp      where to print, includes stdout (screen)
                        Assume that fp has already been fopened.
   called by:   start_output(), output.c
   actions:     prints out function related parameters.
*/
void print_fxn_params(FILE *fp)
   {
  /* things that were read in */
   fprintf(fp, "\n Target parameters:\n");
   fprintf(fp, " Target.abbrev =  %s\n", Target.abbrev);
   fprintf(fp, " Target.x =  %lf\n", Target.x);
   fprintf(fp, " Target.y =  %lf\n", Target.y);
   fprintf(fp, " Target.step_len =  %lf\n", Target.step_len);
   fprintf(fp, " Target.length =  %lf\n", Target.length);
   fprintf(fp, " Target.angle =  %lf\n", Target.angle);
   fprintf(fp, "\n Tracker parameters:\n");
   fprintf(fp, " Tracker.x =  %lf\n", Tracker.x);
   fprintf(fp, " Tracker.y =  %lf\n", Tracker.y);
   fprintf(fp, " Tracker.length =  %lf\n", Tracker.length);
   fprintf(fp, " Tracker.max_step_len =  %lf\n", Tracker.max_step_len);
   fprintf(fp, " Tracker.total_difference =  %lf\n", Tracker.total_difference);
   }  /* print_fxn_params */

/********** init_raw_thresholds **********/
/* created:     20.04.16.ASW moved from init_agent into this function
   parameters:	n	agent index number
   called by:   init_agent(), fxn.c
   actions:     initialize raw thresholds for each agent.
		Raw thresholds fall between 0.0 and 1.0.
		This function is used to set agent thresholds for static 
		thresholds (Thresh_dynamic = 0) and also used to set the 
		initial thresholds for dynamic thresholds with range [0,1]
		(Thresh_dynamic = 1).  It cannot be used for dynamic thresholds
		with variable ranges (Thresh_dynamic = 2) because we can't
		guarantee that the assigned threshold will be within the
		range if the range varies from agent to agent.
*/
int init_raw_thresholds(int n)
   {
   double rand1, rand2, r, theta;       // box muller variables
   double k_n, k_s, k_e, k_w; // discrete variables-poisson,log
   double x_n, x_s, x_e, x_w; // continuous variables-exponential
   double p_n, p_s, p_e, p_w; // poisson/exp result
   double l_n, l_s, l_e, l_w; // log result
   double range_width;  //difference between agent's thresh_max and thresh_min

#ifdef DEBUG
printf("---in init_raw_thresholds()---\n");
#endif

   Agent[n].raw_thresh_min = 0.0;
   Agent[n].raw_thresh_max = 1.0;

   // initialize raw thresholds
   if (Thresh_init <= 1.0 && Thresh_init >= 0.0)
      {
      /* make sure Thresh_init is within range */
      if (Thresh_init > Agent[n].raw_thresh_max)
         Thresh_init = Agent[n].raw_thresh_max;
      if (Thresh_init < Agent[n].raw_thresh_min)
         Thresh_init = Agent[n].raw_thresh_min;
      /* initialize all agents to same constant value */
      Agent[n].raw_thresh_north = Thresh_init;
      Agent[n].raw_thresh_south = Thresh_init;
      Agent[n].raw_thresh_east = Thresh_init;
      Agent[n].raw_thresh_west = Thresh_init;
      }  /* if */
   else if (Thresh_init == 2.0)
      {
      /* initialize randomly - uniform distribution */
      Agent[n].raw_thresh_north = funiform(1.0);
      Agent[n].raw_thresh_south = funiform(1.0);
      Agent[n].raw_thresh_east = funiform(1.0);
      Agent[n].raw_thresh_west = funiform(1.0);
      }  /* else if */
   else if (Thresh_init == 3.0)
      {
      /* initialize randomly - standard normal distribution */
      /* Use Box Muller equations.  Since sigma = 1, a range of 3 on */
      /* either side of zero should include most points.  Adding 0.5 moves */
      /* the range to 0.0 to 1.0 to match the uniform raw threshold range. */
      /* The divide by 6 is a range of 3 on either side of zero. */

      rand1 = knuth_random();
      rand2 = knuth_random();
      r = sqrt(-2 * log(rand1));
      theta = 2 * M_PI * rand2;

      Agent[n].raw_thresh_north = (r * cos(theta))/6+0.5;
      Agent[n].raw_thresh_south = (r * sin(theta))/6+0.5;
      rand1 = knuth_random();
      rand2 = knuth_random();
      r = sqrt(-2 * log(rand1));
      theta = 2 * M_PI * rand2;

      Agent[n].raw_thresh_east = (r * cos(theta))/6+0.5;
      Agent[n].raw_thresh_west = (r * sin(theta))/6+0.5;

/*
      printf("Raw threshold north: %lf\n", Agent[n].raw_thresh_north);
      printf("Raw threshold south: %lf\n", Agent[n].raw_thresh_south);
      printf("Raw threshold east: %lf\n", Agent[n].raw_thresh_east);
      printf("Raw threshold west: %lf\n", Agent[n].raw_thresh_west);
*/

      /* check to make sure all values are >= zero, in case any points */
      /* beyond 4 * sigma were generated. */
      if (Agent[n].raw_thresh_north < 0)  Agent[n].raw_thresh_north = 0;
      if (Agent[n].raw_thresh_south < 0)  Agent[n].raw_thresh_south = 0;
      if (Agent[n].raw_thresh_east < 0)  Agent[n].raw_thresh_east = 0;
      if (Agent[n].raw_thresh_west < 0)  Agent[n].raw_thresh_west = 0;
      }  /* else if */
   else if (Thresh_init == 4.0)
      {
      /* initialize randomly - poisson distribution */
      /* use the equation for Poisson probability dist by multiplying */
      /* our random floating pt value by a number of our choosing, we */
      /* can specify the range of 'k' values we can plug into formula.*/
      /* We arrive at our raw threshold values after scaling by lambda*/
      /* which is set as a constant for now. Change P_RANGE as needed.*/

      k_n = (int)(knuth_random() * (POISSON_K_RANGE + 1));
      k_s = (int)(knuth_random() * (POISSON_K_RANGE + 1));
      k_e = (int)(knuth_random() * (POISSON_K_RANGE + 1));
      k_w = (int)(knuth_random() * (POISSON_K_RANGE + 1));

      p_n = pow(LAMBDA_P, k_n) * exp(-1.0 * LAMBDA_P) / (double)factorial(k_n);
      p_s = pow(LAMBDA_P, k_s) * exp(-1.0 * LAMBDA_P) / (double)factorial(k_s);
      p_e = pow(LAMBDA_P, k_e) * exp(-1.0 * LAMBDA_P) / (double)factorial(k_e);
      p_w = pow(LAMBDA_P, k_w) * exp(-1.0 * LAMBDA_P) / (double)factorial(k_w);

      Agent[n].raw_thresh_north = p_n * LAMBDA_P;
      Agent[n].raw_thresh_south = p_s * LAMBDA_P;
      Agent[n].raw_thresh_east = p_e * LAMBDA_P;
      Agent[n].raw_thresh_west = p_w * LAMBDA_P;

      // check to make sure all values are >= zero
      if (Agent[n].raw_thresh_north < 0)  Agent[n].raw_thresh_north = 0;
      if (Agent[n].raw_thresh_south < 0)  Agent[n].raw_thresh_south = 0;
      if (Agent[n].raw_thresh_east < 0)  Agent[n].raw_thresh_east = 0;
      if (Agent[n].raw_thresh_west < 0)  Agent[n].raw_thresh_west = 0;
      }
   else if (Thresh_init == 5.0)
      {
      /* initialize randomly - exponential distribution use eqn.*/
      /* for exp dist. We generate random 'X' values  */
      /* on our range and evaluate with density function. */

      x_n = (knuth_random() * EXP_X_RANGE);
      x_s = (knuth_random() * EXP_X_RANGE);
      x_e = (knuth_random() * EXP_X_RANGE);
      x_w = (knuth_random() * EXP_X_RANGE);

      p_n = exp(-1.0 * LAMBDA_E * x_n);
      p_e = exp(-1.0 * LAMBDA_E * x_e);
      p_s = exp(-1.0 * LAMBDA_E * x_s);
      p_w = exp(-1.0 * LAMBDA_E * x_w);

      Agent[n].raw_thresh_north = p_n;
      Agent[n].raw_thresh_south = p_s;
      Agent[n].raw_thresh_east = p_e;
      Agent[n].raw_thresh_west = p_w;

      // check to make sure all values are >= zero
      if (Agent[n].raw_thresh_north < 0)  Agent[n].raw_thresh_north = 0;
      if (Agent[n].raw_thresh_south < 0)  Agent[n].raw_thresh_south = 0;
      if (Agent[n].raw_thresh_east < 0)  Agent[n].raw_thresh_east = 0;
      if (Agent[n].raw_thresh_west < 0)  Agent[n].raw_thresh_west = 0;
      }
   else if (Thresh_init == 6.0)
      {
      /* initialize randomly - logarithmic distribution */
      /* as with poisson distribution, we generate discrete random */
      /* variables on the desired range. Scaling by a factor of ~5 */
      /* seems to be effective as most results from the probability*/
      /* density function fall between [0,~.20].                   */

      k_n = (int)(knuth_random() * LOG_K_RANGE + 1);
      k_s = (int)(knuth_random() * LOG_K_RANGE + 1);
      k_e = (int)(knuth_random() * LOG_K_RANGE + 1);
      k_w = (int)(knuth_random() * LOG_K_RANGE + 1);

      l_n = (-1.0 / log(1.0 - LOG_P)) * (pow(LOG_P, k_n) / k_n);
      l_s = (-1.0 / log(1.0 - LOG_P)) * (pow(LOG_P, k_s) / k_s);
      l_e = (-1.0 / log(1.0 - LOG_P)) * (pow(LOG_P, k_e) / k_e);
      l_w = (-1.0 / log(1.0 - LOG_P)) * (pow(LOG_P, k_w) / k_w);

      Agent[n].raw_thresh_north = l_n * 5;
      Agent[n].raw_thresh_south = l_s * 5;
      Agent[n].raw_thresh_east = l_e * 5;
      Agent[n].raw_thresh_west = l_w * 5;

      // check to make sure all values are >= zero
      if (Agent[n].raw_thresh_north < 0)  Agent[n].raw_thresh_north = 0;
      if (Agent[n].raw_thresh_south < 0)  Agent[n].raw_thresh_south = 0;
      if (Agent[n].raw_thresh_east < 0)  Agent[n].raw_thresh_east = 0;
      if (Agent[n].raw_thresh_west < 0)  Agent[n].raw_thresh_west = 0;
      }
   else
      {
      printf(" Error(init_agent): Invalid value for Thresh_init: %lf\n",
		Thresh_init);
      return ERROR;
      }  /* else */

   // 20.04.17.ASW:  I don't think the following code segment is being
   // used any more since I set the max and min to 1.0 and 0.0 at the
   // start of this function, so I'm commenting it out for now.
//   // for all non-constant thresholds, scale the distribution to be
//   // within agent's raw_thresh_max and raw_thresh_min
//   if (Thresh_init > 1.0)
//      {
//      range_width = Agent[n].raw_thresh_max - Agent[n].raw_thresh_min;
//      Agent[n].raw_thresh_north = Agent[n].raw_thresh_north 
//                                * range_width + Agent[n].raw_thresh_min;
//      Agent[n].raw_thresh_south = Agent[n].raw_thresh_south 
//                                * range_width + Agent[n].raw_thresh_min;
//      Agent[n].raw_thresh_east = Agent[n].raw_thresh_east 
//                               * range_width + Agent[n].raw_thresh_min;
//      Agent[n].raw_thresh_west = Agent[n].raw_thresh_west 
//                               * range_width + Agent[n].raw_thresh_min;
//      }

#ifdef DEBUG
printf("---end init_raw_thresholds()---\n");
#endif
   return OK;
   }  /* init_raw_thresholds */

/********** init_dynamic_threshold_range_TD2 **********/
/* created:     20.04.16.ASW
   revised:     20.10.15.ASW   Removed code for TD3 and place in new function.
   parameters:  n       agent index number
   called by:   init_agent(), fxn.c
   actions:     if dynamic thresholds are set to (Thresh_dynamic = 2),
                initialize the threshold range for each agent.
                The minimum of the range is a uniform random value within 
                [0.0:0.49].  The maximum of the range is a uniform random 
                value within [0.51:1.0].
*/
int init_dynamic_threshold_range_TD2(int n)
   {
   double temp;
   double range;

#ifdef DEBUG
printf("---in init_dynamic_threshold_range_TD2()---\n");
#endif

   // initialize unique range for each agent by randomly generating a
   // min and max for the range
   Agent[n].raw_thresh_min_north = knuth_random() * 0.49;
   Agent[n].raw_thresh_min_south = knuth_random() * 0.49;
   Agent[n].raw_thresh_min_east = knuth_random() * 0.49;
   Agent[n].raw_thresh_min_west = knuth_random() * 0.49;
   Agent[n].raw_thresh_max_north = knuth_random() * 0.49 + 0.51;
   Agent[n].raw_thresh_max_south = knuth_random() * 0.49 + 0.51;
   Agent[n].raw_thresh_max_east = knuth_random() * 0.49 + 0.51;
   Agent[n].raw_thresh_max_west = knuth_random() * 0.49 + 0.51;

   // initialize threshold uniformly randomly within range
   range = Agent[n].raw_thresh_max_north - Agent[n].raw_thresh_min_north;
   Agent[n].raw_thresh_north = knuth_random() * range
                             + Agent[n].raw_thresh_min_north;
   range = Agent[n].raw_thresh_max_south - Agent[n].raw_thresh_min_south;
   Agent[n].raw_thresh_south = knuth_random() * range
                             + Agent[n].raw_thresh_min_south;
   range = Agent[n].raw_thresh_max_east - Agent[n].raw_thresh_min_east;
   Agent[n].raw_thresh_east = knuth_random() * range
                             + Agent[n].raw_thresh_min_east;
   range = Agent[n].raw_thresh_max_west - Agent[n].raw_thresh_min_west;
   Agent[n].raw_thresh_west = knuth_random() * range
                             + Agent[n].raw_thresh_min_west;

#ifdef DEBUG
printf("---end init_dynamic_threshold_range_TD2()---\n");
#endif
   return OK;
   }  /* init_dynamic_threshold_range_TD2 */

/********** init_dynamic_threshold_range_TD3 **********/
/* created:     20.04.16.ASW
   parameters:  n       agent index number
   called by:   init_agent(), fxn.c
   actions:     if dynamic thresholds are set to (Thresh_dynamic = 3), 
                initialize the threshold range for each agent.
		Max and min are both uniformly random values within 0 and 1.
                Lower value is the min; higher value is the max.
*/
int init_dynamic_threshold_range_TD3(int n)
   {
   double temp;
   double range;

#ifdef DEBUG
printf("---in init_dynamic_threshold_range_TD3()---\n");
#endif

   // initialize unique range for each agent by randomly generating a
   // min and max for the range
   Agent[n].raw_thresh_min_north = knuth_random();
   Agent[n].raw_thresh_min_south = knuth_random();
   Agent[n].raw_thresh_min_east = knuth_random();
   Agent[n].raw_thresh_min_west = knuth_random();
   Agent[n].raw_thresh_max_north = knuth_random();
   Agent[n].raw_thresh_max_south = knuth_random();
   Agent[n].raw_thresh_max_east = knuth_random();
   Agent[n].raw_thresh_max_west = knuth_random();

   // make sure that the min of the range is less than the max of the range
   if (Agent[n].raw_thresh_min_north > Agent[n].raw_thresh_max_north)
      {
      temp = Agent[n].raw_thresh_min_north;
      Agent[n].raw_thresh_min_north = Agent[n].raw_thresh_max_north;
      Agent[n].raw_thresh_max_north = temp;
      }
   if (Agent[n].raw_thresh_min_south > Agent[n].raw_thresh_max_south)
      {
      temp = Agent[n].raw_thresh_min_south;
      Agent[n].raw_thresh_min_south = Agent[n].raw_thresh_max_south;
      Agent[n].raw_thresh_max_south = temp;
      }
   if (Agent[n].raw_thresh_min_east > Agent[n].raw_thresh_max_east)
      {
      temp = Agent[n].raw_thresh_min_east;
      Agent[n].raw_thresh_min_east = Agent[n].raw_thresh_max_east;
      Agent[n].raw_thresh_max_east = temp;
      }
   if (Agent[n].raw_thresh_min_west > Agent[n].raw_thresh_max_west)
      {
      temp = Agent[n].raw_thresh_min_west;
      Agent[n].raw_thresh_min_west = Agent[n].raw_thresh_max_west;
      Agent[n].raw_thresh_max_west = temp;
      }

   // initialize threshold uniformly randomly within range
   range = Agent[n].raw_thresh_max_north - Agent[n].raw_thresh_min_north;
   Agent[n].raw_thresh_north = knuth_random() * range
                             + Agent[n].raw_thresh_min_north;
   range = Agent[n].raw_thresh_max_south - Agent[n].raw_thresh_min_south;
   Agent[n].raw_thresh_south = knuth_random() * range
                             + Agent[n].raw_thresh_min_south;
   range = Agent[n].raw_thresh_max_east - Agent[n].raw_thresh_min_east;
   Agent[n].raw_thresh_east = knuth_random() * range
                             + Agent[n].raw_thresh_min_east;
   range = Agent[n].raw_thresh_max_west - Agent[n].raw_thresh_min_west;
   Agent[n].raw_thresh_west = knuth_random() * range
                             + Agent[n].raw_thresh_min_west;

#ifdef DEBUG
printf("---end init_dynamic_threshold_range_TD3()---\n");
#endif
   return OK;
   }  /* init_dynamic_threshold_range_TD3 */

/********** init_intensities **********/
/* created:     20.04.16.ASW moved from init_agent into this function
   parameters:  n       agent index number
   called by:   init_agent(), fxn.c
   actions:     initialize intensities for each agent.
*/
int init_intensities(int n)
   {

#ifdef DEBUG
printf("---in init_intensities()---\n");
#endif

   /* HDM; intensity variation; 2019.09.12 */
   if (Intensity_variation == 1) // for homogeneous ranges
      {
      // generate initial intensity values
      Agent[n].intensity_north = rand_agent_intensity();
      Agent[n].intensity_south = rand_agent_intensity();
      Agent[n].intensity_east = rand_agent_intensity();
      Agent[n].intensity_west = rand_agent_intensity();
      // all range min and max are global values when Intensity_variation is 1
      Agent[n].int_aging_min_n = Intensity_aging_min;
      Agent[n].int_aging_max_n = Intensity_aging_max;
      Agent[n].int_aging_min_e = Intensity_aging_min;
      Agent[n].int_aging_max_e = Intensity_aging_max;
      Agent[n].int_aging_min_s = Intensity_aging_min;
      Agent[n].int_aging_max_s = Intensity_aging_max;
      Agent[n].int_aging_min_w = Intensity_aging_min;
      Agent[n].int_aging_max_w = Intensity_aging_max;
      }
   /* LR; intensity range variation; 2020.02.01 */
   else if (Intensity_variation == 2) //for heterogeneous ranges
     {
     /* LR; intensity range variation; 2020.02.01 */
     /* Randomly initialize the intensity range for each task of the agent.
      * It is essentially the same code for each task, but creating
      * functions would make the code more complex and less readable.*/
       double radius;
       double center;

       // north intensity range
       if (Hetero_radius_distr == 1) {//1 = normal/gaussian
           // Hetero_radius_mu is the mean of the normal distribution.
           // Hetero_radius_std is the standard deviation of the distribution.
           // box_muller is random number chosen from the described num distr.
           // fabs() takes the absolute value to prevent negative float values.
           radius = fabs(box_muller(Hetero_radius_mu, Hetero_radius_std));
       } else if (Hetero_radius_distr == 2) {// 2 = uniform
           // Hetero_radius_min offsets the range
           // knuth_random() is a random number chosen from range [0,1]
           // (Hetero_radius_max - Hetero_radius_min) scales the size of the range.
           radius = Hetero_radius_min + knuth_random()
               * (Hetero_radius_max - Hetero_radius_min);
       }

       if (Hetero_center_distr == 1) {//1 = normal/gaussian
           // Hetero_center_mu is the mean of the normal distribution.
           // Hetero_center_std is the standard deviation of the distribution.
           // box_muller is random number chosen from the described num distr.
           // fabs() takes the absolute value to prevent negative float values.
           center = box_muller(Hetero_center_mu, Hetero_center_std);
       } else if (Hetero_center_distr == 2) {// 2 = uniform
           // Hetero_center_min offsets the range
           // knuth_random() is a random number chosen from range [0,1]
           // (Hetero_range_max - Hetero_range_min) scales the size of the range.
           center = Hetero_range_min + radius + knuth_random()
           * ((Hetero_range_max-Hetero_range_min) - 2 * radius);
       }

       // However the center and radius of the range are chosen,
       // the max of the range = center + radius and the min = center - radius
       Agent[n].int_aging_max_n = center + radius;
       Agent[n].int_aging_min_n = center - radius;

       //correct if normal sends min or max out of allowed range
       if (Agent[n].int_aging_max_n > Hetero_range_max) {
         Agent[n].int_aging_max_n = Hetero_range_max;
         if (Agent[n].int_aging_min_n > Agent[n].int_aging_max_n) {
           Agent[n].int_aging_min_n = Agent[n].int_aging_max_n - radius;
         }
       }
       if (Agent[n].int_aging_min_n < Hetero_range_min) {
         Agent[n].int_aging_min_n = Hetero_range_min;
         if (Agent[n].int_aging_max_n < Agent[n].int_aging_min_n) {
           Agent[n].int_aging_max_n = Hetero_range_min + radius;
         }
       }

       // the ranges for the other tasks work the same so fewer comments are needed:

       // south intensity range
       if (Hetero_radius_distr == 1) {//1 = normal/gaussian
           radius = fabs(box_muller(Hetero_radius_mu, Hetero_radius_std));
       } else if (Hetero_radius_distr == 2) {// 2 = uniform
           radius = Hetero_radius_min + knuth_random()
               * (Hetero_radius_max - Hetero_radius_min);
       }

       if (Hetero_center_distr == 1) {//1 = normal/gaussian
           center = box_muller(Hetero_center_mu, Hetero_center_std);
       } else if (Hetero_center_distr == 2) {// 2 = uniform
           center = Hetero_range_min + radius + knuth_random()
           * ((Hetero_range_max-Hetero_range_min) - 2 * radius);
       }
       Agent[n].int_aging_max_s = center + radius;
       Agent[n].int_aging_min_s = center - radius;
       //correct if normal sends min or max out of allowed range
       if (Agent[n].int_aging_max_s > Hetero_range_max) {
         Agent[n].int_aging_max_s = Hetero_range_max;
         if (Agent[n].int_aging_min_s > Agent[n].int_aging_max_s) {
           Agent[n].int_aging_min_s = Agent[n].int_aging_max_s - radius;
         }
       }
       if (Agent[n].int_aging_min_s < Hetero_range_min) {
         Agent[n].int_aging_min_s = Hetero_range_min;
         if (Agent[n].int_aging_max_s < Agent[n].int_aging_min_s) {
           Agent[n].int_aging_max_s = Hetero_range_min + radius;
         }
       }

       // east intensity range
       if (Hetero_radius_distr == 1) {//1 = normal/gaussian
           radius = fabs(box_muller(Hetero_radius_mu, Hetero_radius_std));
       } else if (Hetero_radius_distr == 2) {// 2 = uniform
           radius = Hetero_radius_min + knuth_random()
               * (Hetero_radius_max - Hetero_radius_min);
       }

       if (Hetero_center_distr == 1) {//1 = normal/gaussian
           center = box_muller(Hetero_center_mu, Hetero_center_std);
       } else if (Hetero_center_distr == 2) {// 2 = uniform
           center = Hetero_range_min + radius + knuth_random()
           * ((Hetero_range_max-Hetero_range_min) - 2 * radius);
       }
       Agent[n].int_aging_max_e = center + radius;
       Agent[n].int_aging_min_e = center - radius;
       //correct if normal sends min or max out of allowed range
       if (Agent[n].int_aging_max_e > Hetero_range_max) {
         Agent[n].int_aging_max_e = Hetero_range_max;
         if (Agent[n].int_aging_min_e > Agent[n].int_aging_max_e) {
           Agent[n].int_aging_min_e = Agent[n].int_aging_max_e - radius;
         }
       }
       if (Agent[n].int_aging_min_e < Hetero_range_min) {
         Agent[n].int_aging_min_e = Hetero_range_min;
         if (Agent[n].int_aging_max_e < Agent[n].int_aging_min_e) {
           Agent[n].int_aging_max_e = Hetero_range_min + radius;
         }
       }

       // west intensity range
       if (Hetero_radius_distr == 1) {//1 = normal/gaussian
           radius = fabs(box_muller(Hetero_radius_mu, Hetero_radius_std));
       } else if (Hetero_radius_distr == 2) {// 2 = uniform
           radius = Hetero_radius_min + knuth_random()
               * (Hetero_radius_max - Hetero_radius_min);
       }

       if (Hetero_center_distr == 1) {//1 = normal/gaussian
           center = box_muller(Hetero_center_mu, Hetero_center_std);
       } else if (Hetero_center_distr == 2) {// 2 = uniform
           center = Hetero_range_min + radius + knuth_random()
           * ((Hetero_range_max-Hetero_range_min) - 2 * radius);
       }
       Agent[n].int_aging_max_w = center + radius;
       Agent[n].int_aging_min_w = center - radius;
       //correct if normal sends min or max out of allowed range
       if (Agent[n].int_aging_max_w > Hetero_range_max) {
         Agent[n].int_aging_max_w = Hetero_range_max;
         if (Agent[n].int_aging_min_w > Agent[n].int_aging_max_w) {
           Agent[n].int_aging_min_w = Agent[n].int_aging_max_w - radius;
         }
       }
       if (Agent[n].int_aging_min_w < Hetero_range_min) {
         Agent[n].int_aging_min_w = Hetero_range_min;
         if (Agent[n].int_aging_max_w < Agent[n].int_aging_min_w) {
           Agent[n].int_aging_max_w = Hetero_range_min + radius;
         }
       }

      // Select an intensity value within this range
      Agent[n].intensity_north = random_double(Agent[n].int_aging_min_n, Agent[n].int_aging_max_n);
      Agent[n].intensity_south = random_double(Agent[n].int_aging_min_s, Agent[n].int_aging_max_s);
      Agent[n].intensity_east  = random_double(Agent[n].int_aging_min_e, Agent[n].int_aging_max_e);
      Agent[n].intensity_west  = random_double(Agent[n].int_aging_min_w, Agent[n].int_aging_max_w);

      #ifdef DEBUG_PRINT
      printf("agent: %d   intensity aging ranges:\tn=[%f, %f], s=[%f, %f], e=[%f, %f], w=[%f, %f]\n",
        n,  Agent[n].int_aging_min_n, Agent[n].int_aging_max_n,
            Agent[n].int_aging_min_s, Agent[n].int_aging_max_s,
            Agent[n].int_aging_min_e, Agent[n].int_aging_max_e,
            Agent[n].int_aging_min_w, Agent[n].int_aging_max_w);
      }
      #endif
  } else   // Intensity_variation == 0
      {
      Agent[n].intensity_north = 1.0;
      Agent[n].intensity_south = 1.0;
      Agent[n].intensity_east = 1.0;
      Agent[n].intensity_west = 1.0;
      Agent[n].int_aging_min_n = 1.0;
      Agent[n].int_aging_max_n = 1.0;
      Agent[n].int_aging_min_e = 1.0;
      Agent[n].int_aging_max_e = 1.0;
      Agent[n].int_aging_min_s = 1.0;
      Agent[n].int_aging_max_s = 1.0;
      Agent[n].int_aging_min_w = 1.0;
      Agent[n].int_aging_max_w = 1.0;
      }

    /* HDM; 2019.09.19 */
    Agent[n].int_tot_n = 0.0;
    Agent[n].int_tot_s = 0.0;
    Agent[n].int_tot_e = 0.0;
    Agent[n].int_tot_w = 0.0;

    Agent[n].int_no_act_n = 0.0;
    Agent[n].int_no_act_s = 0.0;
    Agent[n].int_no_act_e = 0.0;
    Agent[n].int_no_act_w = 0.0;

    Agent[n].int_min_n = Agent[n].intensity_north;
    Agent[n].int_min_s = Agent[n].intensity_south;
    Agent[n].int_min_e = Agent[n].intensity_east;
    Agent[n].int_min_w = Agent[n].intensity_west;

    Agent[n].int_max_n = Agent[n].intensity_north;
    Agent[n].int_max_s = Agent[n].intensity_south;
    Agent[n].int_max_e = Agent[n].intensity_east;
    Agent[n].int_max_w = Agent[n].intensity_west;

    // printf("agent: %d   intensities[n s e w]: %lf  %lf  %lf  %lf\n", n, Agent[n].intensity_north,
    //                 Agent[n].intensity_south, Agent[n].intensity_east, Agent[n].intensity_west);

#ifdef DEBUG
printf("---end init_intensities()---\n");
#endif
   return OK;
   }  /* init_intensities */

/* agent.c
   19.02.24.AW  Created.
                Contains routines related to agents.

   Routines:
*/

#include <stdio.h>
#include <stdlib.h>
#include "types.h"
#include "extern.h"
#include "agent.h"
#include "random.h"
#include "map.h"

/********** init_agent **********/
/* paramters:   n       agent number
   called by:   init_fxn(), fxn.c
   actions:
*/
int init_agent(int n)
   {
   int i;
   int r, c;

#ifdef DEBUG
printf("---in init_agent()---\n");
#endif

   Agent[n].index = n;
   Agent[n].num_tasks = 1;
   Agent[n].current_row = Envr.start_row;
   Agent[n].current_col = Envr.start_col;
   Agent[n].distance_travelled = -1;
   Agent[n].alive = 1;

   // allocate space for list of thresholds
   Agent[n].thresh = (double *)malloc(Agent[n].num_tasks * sizeof(double));
   if (Agent[n].thresh == NULL)
      {
      printf(" Error(init_agent): cannot allocate space: Agent[%d].thresh\n",
                        n);
      return ERROR;
      }   /* if */
   // allocate space for list of response probabilities
   Agent[n].response_prob = (double *)malloc(Agent[n].num_tasks*sizeof(double));
   if (Agent[n].response_prob == NULL)
      {
      printf(" Error(init_agent): cannot allocate space: Agent[%d].response_prob\n",
                        n);
      return ERROR;
      }   /* if */
   // allocate space for memory map
   Agent[n].memory_map = (double **)malloc(Envr.height * sizeof(double *) );
   for (r=0; r<Envr.height; r++)
      {
      Agent[n].memory_map[r] = (double *)malloc(Envr.width * sizeof(double) );
      for (c=0; c<Envr.width; c++)
         {
         Agent[n].memory_map[r][c] = 1.0;
         }
      }
   // allocate space for current map
   Agent[n].current_map = (int **)malloc(Envr.height * sizeof(int *) );
   for (r=0; r<Envr.height; r++)
      {
      Agent[n].current_map[r] = (int *)malloc(Envr.width * sizeof(int) );
      }
   // allocate space for list of path lengths (one for each step/cycle)
   Agent[n].path_len = (int *)malloc(Max_steps * sizeof(int));
   if (Agent[n].path_len == NULL)
      {
      printf(" Error(init_agent): cannot allocate space: Agent[%d].path_len\n",
                        n);
      return ERROR;
      }   /* if */

   // initialize path_len array to -1
   // that way, agents that do not choose to act will be distinguished
   // by -1 path length.  Agent that acts can have 0 path length if
   // food is located at center.
   for (i=0; i<Max_steps; i++)
      {
      Agent[n].path_len[i] = -1;
      }

   // initialize threshold and increase/decrease values
   // 141111.AW initialize Prob_check values
   for (i=0; i<Agent[n].num_tasks; i++)
      {
      if (Init_thresh == 0.0)
         {
         /* initialize to random value */
         Agent[n].thresh[i] = funiform(1.0);
         }  /* if */
      else if (Init_thresh <=1.0)
         {
         Agent[n].thresh[i] = Init_thresh;
         }  /* else if */
      else
         {
         printf(" Error(init_agent): invalid threshold init value: %lf\n",
                Init_thresh);
         return ERROR;
         }  /* else */

//      if (Prob_check == 0.0)
//         {
//         /* initialize to random value */
//         Agent[n].prob_check = funiform(1.0);
//         }  /* if */
//      else if (Prob_check <=1.0)
//         {
//         Agent[n].prob_check = Prob_check;
//         }  /* else if */
//      else
//         {
//         printf(" Error(init_agent): invalid threshold init value: %lf\n",
//                Prob_check);
//         return ERROR;
//         }  /* else */

      Agent[n].response_prob[i] = Response_prob;
      }  /* for i */

#ifdef DEBUG
printf("---end init_agent()---\n");
#endif
   return OK;
   }  /* init_agent */

/********** agent_act **********/
/* paramaters:  n       which agent
   called by:   step_run(), fxn.c
   actions:	Routine called by agent actors (not candidates).
		Agent n runs thru map once, looking for food source.
		Fills in current_map -- cells traversed are set to one.
		Picks higher fitness cells with higher probability.
*/
int agent_act(int n, int step)
   {
   int error;
   int tt;
   FILE *fp;
   char filename[100];
   int found_food;

#ifdef DEBUG
printf("---in agent_act()---\n");
#endif

//   printf(" Agent %d acts, r%d c%d\n",
//          n, Agent[n].current_row, Agent[n].current_col);

   Nest.step_last_actor[step] = n;

   if (Print_agent_paths)
      {
      sprintf(filename, "%s/run.%d/run.%d.agent%d.step%d.path",
		Output_path, Run_num, Run_num, n, step);
      fp = fopen(filename, "w");

      fprintf(fp, "%d %d\n", 
              Agent[n].current_col, Envr.height-Agent[n].current_row);
      }

   // set agent's path in environment to all zero, no cells traversed.
   init_current_map(n);
   found_food = 0;

   // indicate agent's starting location in environment 
   update_current_map(n, step);

   for (tt=0; tt<Max_sim_time && found_food == 0; tt++)
      {
      Agent[n].distance_travelled = tt;

      // call move_agent to move agent one step
      found_food = move_agent(n);

      // update agent's new location in environment 
      update_current_map(n, step);

      if (Print_agent_paths) 
         {
         // row adjusted because simulation sets 0,0 at NW corner 
         // and most plots have 0,0 at SW corner
         fprintf(fp, "%d %d\n", 
                 Agent[n].current_col, Envr.height-Agent[n].current_row);
         }
      }

   // save path lenght into path_len array
   Agent[n].path_len[step] = Agent[n].distance_travelled;

   if (found_food == 1)  Nest.step_income++;

/*
   if (found_food == 1)  
      printf(" Found food at r%d c%d ad time %d\n", 
		Agent[n].current_row, Agent[n].current_col,
		Agent[n].distance_travelled);
   else
      printf(" No food found at time %d\n", Agent[n].distance_travelled);
*/

//   print_current_map(n);

   error = update_memory(n, found_food);
   if (error == 1)  return ERROR;

//   print_memory_map(n);

   if (Print_agent_paths)  fclose(fp);

#ifdef DEBUG
printf("---end agent_act()---\n");
#endif
   return OK;
   }  /* agent_act */

/********** sort_agents **********/
/* paramaters:  
   called by:   init_fxn(), fxn.c
   actions:	sorts the agents by threshold value, lowest to highest.
*/
void sort_agents()
   {
   int i, j;
   double temp;

#ifdef DEBUG
printf("---in sort_agents()---\n");
#endif

   for (i=0; i<Pop_size; i++)
      {
      for (j=i+1; j<Pop_size; j++)
         {
         if (Agent[j].thresh[0] < Agent[i].thresh[0])
            {
            temp = Agent[i].thresh[0];
            Agent[i].thresh[0] = Agent[j].thresh[0];
            Agent[j].thresh[0] = temp;
            }
         }
      }

#ifdef DEBUG
printf("---end sort_agents()---\n");
#endif
   return;
   }  /* sort_agents */

/********** print_agents **********/
/* paramaters:
   called by:   init_fxn(), fxn.c
   actions:     prints all agents.
*/
void print_agents()
   {
   int i, r, c;
   double temp;

#ifdef DEBUG
printf("---in print_agents()---\n");
#endif

   for (i=0; i<Pop_size; i++)
      {
      printf(" Agent %d, at r%d c%d, threshold %lf response_prob %lf\n", 
             Agent[i].index, 
             Agent[i].current_row, Agent[i].current_col,
             Agent[i].thresh[0], Agent[i].response_prob[0]);

      // print agent's map
/*
      for (r=0; r<Envr.height; r++)
         {
         for (c=0; c<Envr.width; c++)
            {
            printf(" %4.1lf", Agent[i].map[r][c]);
            }
         printf("\n");
         }
*/
      }

#ifdef DEBUG
printf("---end print_agents()---\n");
#endif
   return;
   }  /* print_agents */

/********** update_current_map **********/
/* paramaters:  n		which agent
   called by:   agent_act(), agent.c
   actions:     Updates agent n's current_map by incrementing its current
		location on the map by one.
*/
void update_current_map(int n, int step)
   {
#ifdef DEBUG
printf("---in update_current_map()---\n");
#endif

   //Agent[n].current_map[Agent[n].current_row][Agent[n].current_col]++;
   Agent[n].current_map[Agent[n].current_row][Agent[n].current_col] = step;

#ifdef DEBUG
printf("---end update_current_map()---\n");
#endif
   return;
   }  /* update_current_map */

/********** update_memory **********/
/* parameters:  n               which agent
                success         was agent successful in finding food
                                1 = yes, 0 = no
   called by:   agent_act(), agent.c
   actions:     After an agent has made a path thru the map, use current
                map to update memory map.  If agent found food, update
                memory map by increasing the values along the path travelled.
                If agent did not find food, update memory map by decreasing
                the values along the path travelled.

		Cell values decrease by 10% when a path does not lead to food.
		(Amount decrease is less for each subsequent decrease.)
		Increase by the same proportional amount when the path does
		lead to food (this is different from increasing by 10%
                because, in that case, the amount increase would go up for
		each subsequent increase -- want that amoung to decrease
		so that values stay between 0.0 and 2.0).
*/
int update_memory(int n, int success)
   {
   double x;
   int r, c;

#ifdef DEBUG
printf("---in update_memory()---\n");
#endif

//   printf(" UPDATE MEMORY agent %d success %d\n", n, success);

   for (r=0; r<Envr.height; r++)
      {
      for (c=0; c<Envr.width; c++)
         {
         if ( Agent[n].current_map[r][c] > 0 )
            {
            if (success == 1)
               {
               // reinforcement same at all parts of path
               x = (2.0 - Agent[n].memory_map[r][c]) * Positive_reinforcement;
               Agent[n].memory_map[r][c] += x;

               // later parts of path result in bigger reinforcement
               //x = (2.0 - Agent[n].memory_map[r][c]) * Positive_reinforcement
               //  * ( (double)Agent[n].current_map[r][c] /
               //      (double)Max_sim_time) ;
               //Agent[n].memory_map[r][c] += x;
               }
            else if (success == 0)
               {
               // reinforcement same at all parts of path
               //Agent[n].memory_map[r][c] *= (1.0 - Negative_reinforcement);

               // later parts of path result in bigger reinforcement
               x = Agent[n].memory_map[r][c] * Negative_reinforcement
                 * ( (double)Agent[n].current_map[r][c] /
                     (double)Max_sim_time) ;
               Agent[n].memory_map[r][c] -= x;
               }
            else
               {
               printf(
               " Error(update_memory): invalid success code: %d\n", success);
               return ERROR;
               }

            if (Agent[n].memory_map[r][c] < 0.0)
               Agent[n].memory_map[r][c] = 0.0;
            else if (Agent[n].memory_map[r][c] > 2.0)
               Agent[n].memory_map[r][c] = 2.0;
            }
         }
      }

#ifdef DEBUG
printf("---end update_memory()---\n");
#endif
   return OK;
   }  /* update_memory */

/********** agent_stats **********/
/* paramters:  
   called by:   fprint_finalstats(), output.c
   actions:	Calculate path stats for each agent
		num_times_acted = number of steps agents active
		avg_path_len = average the path lengths of all active steps
*/
void agent_stats()
   {
   int n, t;

#ifdef DEBUG
printf("---in agent_stats()---\n");
#endif
  
   for (n=0; n<Pop_size; n++)
      {
      Agent[n].num_times_acted = 0;
      Agent[n].num_successes = 0;
      Agent[n].avg_path_len = 0.0;
      Agent[n].avg_successful_path_len = 0.0;

      for (t=0; t<Max_steps; t++)
         {
         if (Agent[n].path_len[t] >= 0)
            {
            Agent[n].num_times_acted++;
            Agent[n].avg_path_len += Agent[n].path_len[t];
            if (Agent[n].path_len[t] < Max_sim_time-1)
               {
               Agent[n].avg_successful_path_len += Agent[n].path_len[t];
               Agent[n].num_successes++;
               }
            }
         }  /* for t */

      if (Agent[n].num_times_acted > 0)
         {
         Agent[n].avg_path_len = Agent[n].avg_path_len/
                              (double)Agent[n].num_times_acted;
         }
      else 
         Agent[n].avg_path_len = -1;

      // Calculate average successful path length.
      // Average path length of those trials where agent did find food.
      if (Agent[n].num_successes > 0)
         {
         Agent[n].avg_successful_path_len = Agent[n].avg_successful_path_len/
                              (double)Agent[n].num_successes;
         }
      else 
         Agent[n].avg_successful_path_len = -1;

      // Calculate success rate: percent trials agent found food
     // Agent[n].success_rate = Agent[n].success_rate/Agent[n].num_times_acted;

      }  /* for n */

#ifdef DEBUG
printf("---end agent_stats()---\n");
#endif
   }  /* agent_stats */

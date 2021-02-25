/* fxn.c 14.10.15.AW	Created.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "types.h"
#include "extern.h"
#include "fxn.h"
#include "random.h"
#include "output.h"
#include "environ.h"
#include "agent.h"
#include "nest.h"

//#define DEBUG 1
//#define DEBUG_AGENT 1

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

   /* allocate space */
   Agent = (AGENT *)malloc(Pop_size * sizeof(AGENT) );
   if (Agent == NULL)
      {
      printf(" Error(init_fxn): cannot allocate space: Agent\n");
      return ERROR;
      }   /* if */

   /* initialize environment */
   error = init_environment();
   if (error == ERROR)  return ERROR;
   print_food_locations();

   /* initialize nest */
   error = init_nest();
   if (error == ERROR)  return ERROR;
//   print_nest();

   /* initialize agents */
   for (i=0; i<Pop_size; i++)
      {
      error = init_agent(i);
      if (error == ERROR)  return ERROR;
      }  /* for */
   sort_agents();
//   print_agents();

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

   /* print run data */
   run_output();

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
   int t;		/* step counter */
   int a;		/* agent counter */
   int error;
#ifdef DEBUG
printf("---in run_fxn()---\n");
#endif

   for (t=0; t<Max_steps; t++)
      {
      error = step_start(t);
      if (error == ERROR)  return ERROR;

      error = step_run(t);
      if (error == ERROR)  return ERROR;

      error = step_end(t);
      if (error == ERROR)  return ERROR;

      step_output(t);
      }  /* for s */

#ifdef DEBUG
printf("---end run_fxn()---\n");
#endif
   return OK;
   }  /* run_fxn */

/********** step_start **********/
/* paramters:	t	step
   called by:	run_fxn(), fxn.c
   actions:
*/
int step_start(int t)
   {
   int i;
   double x;
   int start_kill;

#ifdef DEBUG
printf("---in step_start()---\n");
#endif

   for (i=0; i<Pop_size; i++)
      {
      Agent[i].current_row = Envr.height/2;
      Agent[i].current_col = Envr.width/2;
      Agent[i].distance_travelled = -1;
      }

   Nest.step_income = 0.0;
   Nest.step_num_actors = 0;

#ifdef KILL
   /////// kill off agents halfway thru, or periodically
   if (t % (int)(Max_steps/8) == 0 && (t > 0 && t < Max_steps*0.6) )
      {
      i = 0;
      start_kill = 0;
      while (Agent[i].alive == 0)
         {
         start_kill = i+1;
         i++;
         }

      printf(" Kill %d agents (%d-%d)\n", 
             Nest.need, start_kill, start_kill+Nest.need-1);
      for (i=start_kill; i<start_kill+Nest.need; i++)
         {
         Agent[i].alive = 0;
         }
      }
#endif

#ifdef DEBUG
printf("---end step_start()---\n");
#endif
   return OK;
   }  /* step_start */

/********** step_end **********/
/* paramters:   t       step
   called by:   run_fxn(), fxn.c
   actions:	Things to do at the end of a day.
*/
int step_end(int t)
   {
   int i;

#ifdef DEBUG
printf("---in step_end()---\n");
#endif

   Nest.total_food += Nest.step_income;

   // to calc avg last actor, need to sum up the last actor # for each step
   Nest.avg_last_actor += Nest.step_last_actor[t];

   if (Nest.step_last_actor[t] > Nest.run_last_actor)
      Nest.run_last_actor = Nest.step_last_actor[t];

#ifdef DEBUG
printf("---end step_end()---\n");
#endif
   return OK;
   }  /* step_end */

/********** step_run **********/
/* paramters:   t       which step
   called by:   run_fxn(), fxn.c
   actions:
*/
int step_run(int t)
   {
   int error;
   int i;
   int num_acted;
   double rand_num;

#ifdef DEBUG
printf("---in step_run()---\n");
#endif

   i = 0;
   num_acted = 0;

printf(" Step %d: \n", t);
   /* run until Nest.need number of agents act */
   while (num_acted < Nest.need && i < Pop_size)
      {
      rand_num = knuth_random();

      if (Agent[i].alive && rand_num < Agent[i].response_prob[0])
         {
         error = agent_act(i, t);
         if (error == 1)  return ERROR;

         num_acted++;
         //printf("  %d", i);
         }

      i++;
      }
//printf("\n");

   Nest.step_num_actors = num_acted;
   Nest.total_num_actors += num_acted;
   if (num_acted >= Nest.need)  Nest.num_steps_need_met++;

#ifdef DEBUG
printf("---end step_run()---\n");
#endif
   return OK;
   }  /* step_run */

/********** get_random_agent_order **********/
/* paramters:
   called by:   step_run(), fxn.c
   actions:     fills in Nest.agent_order[] array with a random ordering
                of the agents.
*/
//int get_random_agent_order()
//   {
//   int i, j;
//   int rand;
//   int stop;
//   int count;           /* counts the number of unchosen tasks */
//   int chosen;
//
//   int k;
//
//   // initialize task chosen markers to "not chosen"
 ////  for (i=0; i<Pop_size; i++)
 //     {
//      Agent[i].chosen = 0;
//      Nest.agent_order[i] = -1;
//      }
//
//   // randomly select a task from the as yet unselected tasks
//   // decrease the count of available tasks after each new one is selected
//   // i indicates number of available tasks to select from
//   for (i=Pop_size; i>0; i--)
//      {
//      rand = uniform(i);
//      count = 0;
//      j = 0;
//      stop = 0;
//      chosen = -1;
//
//      while (stop == 0)
//         {
//         if (Agent[j].chosen == 0)
//            {
//            if (count == rand)
//               {
//               stop = 1;
//               chosen = j;
//               }
//            count++;
//            }
//         j++;
//         }  /* while */
///*
//printf(" Avail %d, rand %d, chosen %d\n", i, rand, chosen);
//*/
//
//         if (chosen < 0 || chosen >= Pop_size)
//            {
//          printf(" Error(get_random_agent_order): invalid value: chosen = %d\n",
//                chosen);
//            return ERROR;
//            }
//
//         Agent[chosen].chosen = 1;
//         Nest.agent_order[Pop_size - i] = chosen;
//
///*
//printf("    Agent order in get_random_agent_order:  ");
//for (k=0; k<Pop_size; k++)  printf(" %2d", Nest.agent_order[k]);
//printf("\n");
//printf("    Agent.chosen in get_random_agent_order: ");
//for (k=0; k<Pop_size; k++)  printf(" %2d", Agent[k].chosen);
//printf("\n");
//*/
//      }  /* for i */
//
//   return OK;
//   }  /* get_random_agent_order */

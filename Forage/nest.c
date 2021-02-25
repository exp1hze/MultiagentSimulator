/* nest.c
   19.03.01.AW  Created.
                Contains routines for the nest.

   Routines:
*/

#include <stdio.h>
#include <stdlib.h>
#include "types.h"
#include "extern.h"
#include "nest.h"

/********** init_nest **********/
/* paramters:
   called by:   init_fxn(), fxn.c
   actions:     initialize nest
*/
int init_nest()
   {
   int r, c;

#ifdef DEBUG
printf("---in init_nest()---\n");
#endif

//   Nest.food_store = 0.0;
//   Nest.max_time_step = 3 * (Envr.height + Envr.width);

   Nest.total_food = 0;
   Nest.run_last_actor = -1;
   Nest.avg_last_actor = 0;
   Nest.total_num_actors = 0;
   Nest.num_steps_need_met = 0;

   // allocate space to store the last actor in each step/cycle
   Nest.step_last_actor = (int *)malloc(Max_steps * sizeof(int));
   if (Nest.step_last_actor == NULL)
      {
      printf(" Error(init_nest): cannot allocate space: Nest.step_last_actor\n");
      return ERROR;
      }   /* if */
   for (r=0; r<Max_steps; r++)  Nest.step_last_actor[r] = -1;

   // allocate space for master memory map
   Nest.master_memory_map = (double **)malloc(Envr.height * sizeof(double *) );
   for (r=0; r<Envr.height; r++)
      {
      Nest.master_memory_map[r] = (double *)malloc(Envr.width * sizeof(double));
      for (c=0; c<Envr.width; c++)
         {
         Nest.master_memory_map[r][c] = 0.0;
         }
      }

#ifdef DEBUG
printf("---end init_nest()---\n");
#endif
   return OK;
   }  /* init_nest */

/********** print_nest **********/
/* paramters:
   called by:   init_fxn(), fxn.c
   actions:     print nest
*/
void print_nest()
   {

#ifdef DEBUG
printf("---in print_nest()---\n");
#endif

   printf(" Print nest\n");
//, food store %lf, max_time %d\n", Nest.food_store, Nest.max_time_step);

#ifdef DEBUG
printf("---end print_nest()---\n");
#endif
   return;
   }  /* print_nest */

/********** average_memory_maps **********/
/* paramters:
   called by:   
   actions:     averages the memory maps of all of the agents in the
		population into the nest's master memory map.
*/
void average_memory_maps()
   {
   int i, r, c;

#ifdef DEBUG
printf("---in average_memory_maps()---\n");
#endif

   for (r=0; r<Envr.height; r++)
      {
      for (c=0; c<Envr.width; c++)
         {
         for (i=0; i<Pop_size; i++)
            {
            Nest.master_memory_map[r][c] += Agent[i].memory_map[r][c];
            }
         Nest.master_memory_map[r][c] /= (double)Pop_size;
         }
      }

#ifdef DEBUG
printf("---end average_memory_maps()---\n");
#endif
   return;
   }  /* average_memory_maps */

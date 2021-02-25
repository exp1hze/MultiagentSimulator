/* environ.c
   19.02.24.AW	Created.
		Contains routines related to environment.

   Routines:
		int init_environment();
		void print_environment();
		void print_grid();
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "types.h"
#include "extern.h"
#include "environ.h"
#include "random.h"

//#define DEBUG 1

/********** init_environment **********/
/* paramters:
   called by:   init_fxn(), fxn.c
   actions:     initialize environment
*/
int init_environment()
   {
   int i;
   int r, c;
   int rand_num;

#ifdef DEBUG
printf("---in init_environment()---\n");
#endif

   /* set location from which all agents start searching for food */
   Envr.start_row = Envr.height/2;
   Envr.start_col = Envr.width/2;

   /* allocate grid on which to save food locations */
   Envr.grid = (double **)malloc(Envr.height * sizeof(double *) );
   for (r=0; r<Envr.height; r++)
      {
      Envr.grid[r] = (double *)malloc(Envr.width * sizeof(double) );
      for (c=0; c<Envr.width; c++)
         {
         Envr.grid[r][c] = 0.0;
         }
      }

   if ( strcmp("random", Envr.init_food) == 0 )
      get_random_food_locations();
   else
      get_food_locations_from_file();

   //print_grid();

#ifdef DEBUG
printf("---end init_environment()---\n");
#endif
   return OK;
   }  /* init_environment */

/********** get_closest_food_distance **********/
/* paramters:
   called by:   fprint_finalneststats(), output.c
   actions:     returns distance to closest food source
*/
double get_closest_food_distance()
   {
   int i;
   double shortest_distance;
   double distance;

#ifdef DEBUG
printf("---in get_closest_food_distance()---\n");
#endif

   shortest_distance = Max_sim_time * Max_sim_time;

   /* init food amount to zero and randomly select food locations */
   for (i=0; i<Envr.num_food; i++)
      {
      distance = sqrt(
	(Envr.start_row - Envr.food[i].row)*(Envr.start_row - Envr.food[i].row)
	+
	(Envr.start_col - Envr.food[i].col)*(Envr.start_col - Envr.food[i].col)
	);
      if (distance < shortest_distance)  shortest_distance = distance;

//      printf(" food %d r,c %d,%d distance %lf\n", i, 
//		Envr.food[i].row, Envr.food[i].col, distance);
      }

#ifdef DEBUG
printf("---end get_closest_food_distance()---\n");
#endif
   return shortest_distance;
   }  /* get_closest_food_distance */

/********** get_food_locations_from_file **********/
/* paramters:
   called by:   init_environment(), environ.c
   actions:     print food locations
*/
void get_food_locations_from_file()
   {
   FILE *fp;
   int i;

#ifdef DEBUG
printf("---in get_food_locations_from_file()---\n");
#endif

   fp = fopen(Envr.init_food, "r");

   fscanf(fp, "%d", &Envr.num_food);

   /* allocate food array */
   Envr.food = (FOOD *)malloc(Envr.num_food * sizeof(FOOD) );

   /* init food amount to zero and randomly select food locations */
   for (i=0; i<Envr.num_food; i++)
      {
      Envr.food[i].amount = 0.0;
      Envr.food[i].type = 0;
      fscanf(fp, "%d %d", &Envr.food[i].row, &Envr.food[i].col);
      Envr.grid[Envr.food[i].row][Envr.food[i].col] = 1.0;
      }

#ifdef DEBUG
printf("---end get_food_locations_from_file()---\n");
#endif
   return;
   }  /* get_food_locations_from_file */

/********** get_random_food_locations **********/
/* paramters:
   called by:   init_environment(), environ.c
   actions:     print food locations
*/
void get_random_food_locations()
   {
   int i;

#ifdef DEBUG
printf("---in get_random_food_locations()---\n");
#endif

   /* allocate food array */
   Envr.food = (FOOD *)malloc(Envr.num_food * sizeof(FOOD) );

   /* init food amount to zero and randomly select food locations */
   for (i=0; i<Envr.num_food; i++)
      {
      Envr.food[i].amount = 0.0;
      Envr.food[i].type = 0;
      Envr.food[i].row = uniform(Envr.height);
      Envr.food[i].col = uniform(Envr.width);
      Envr.grid[Envr.food[i].row][Envr.food[i].col] = 1.0;
      }

#ifdef DEBUG
printf("---end get_random_food_locations()---\n");
#endif
   return;
   }  /* get_random_food_locations */

/********** print_food_locations **********/
/* paramters:
   called by:   init_fxn(), fxn.c
   actions:     print food locations
*/
void print_food_locations()
   {
   int i;
   int rand_num;

#ifdef DEBUG
printf("---in print_food_locations()---\n");
#endif

   /* init food amount to zero and randomly select food locations */
   for (i=0; i<Envr.num_food; i++)
      {
      printf(" Food location %d: %d,%d   amount %lf\n",
             i,
             Envr.food[i].row,
             Envr.food[i].col,
             Envr.food[i].amount);
      }

#ifdef DEBUG
printf("---end print_food_locations()---\n");
#endif
   return;
   }  /* print_food_locations */

/********** print_grid **********/
/* paramters:
   called by:   init_fxn(), fxn.c
   actions:     print grid
*/
void print_grid()
   {
   int r, c;

#ifdef DEBUG
printf("---in print_grid()---\n");
#endif

   printf(" Food locations:\n");
   for (r=0; r<Envr.height; r++)
      {
      for (c=0; c<Envr.width; c++)
         {
         //printf("  %2d", (int)Envr.grid[r][c]);
         if (Envr.grid[r][c] == 1)  printf("  @");
         else                       printf("  -");
         }
      printf("\n");
      }

#ifdef DEBUG
printf("---end print_grid()---\n");
#endif
   return;
   }  /* print_grid */

/********** print_agent_on_grid **********/
/* paramters:	n		which agent
   called by:   init_fxn(), fxn.c
   actions:     print specified agent's location on grid
*/
void print_agent_on_grid(int n)
   {
   int r, c;

#ifdef DEBUG
printf("---in print_agent_on_grid()---\n");
#endif

   printf(" Agent %d located at:\n", n);
   for (r=0; r<Envr.height; r++)
      {
      for (c=0; c<Envr.width; c++)
         {
         if (r == Agent[n].current_row && c == Agent[n].current_col)
            printf(" *");
         else
            printf(" -");
         }
      printf("\n");
      }

#ifdef DEBUG
printf("---end print_agent_on_grid()---\n");
#endif
   return;
   }  /* print_agent_on_grid */

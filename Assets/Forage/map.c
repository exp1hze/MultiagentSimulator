/* map.c
   19.02.27.AW  Created.
                Contains routines related to the agents' map.

   Routines:
*/

#include <stdio.h>
#include <stdlib.h>
#include "types.h"
#include "extern.h"
#include "map.h"
#include "random.h"
#include "environ.h"

#define DEBUG_TT 1
#undef DEBUG_TT

// structure item is used for rank selection routines
struct item
   {
   double value;
   int index;
   };

/********** move_agent **********/
/* parameters:  n       which agent
   called by:   agent_act(), agent.c
   actions:     Routine called by agent actors (not candidates).
		Gets next move.  Selects neighbor to move to with probability 
                proportional to the memory value of the cell.  More likely
		to move to cell with higher memory value.
   returns:	1 if food found, 0 if no food found
*/
int move_agent(int n)
   {

#ifdef DEBUG
printf("---in move_agent()---\n");
#endif

   if (Agent[n].current_row == 0 && Agent[n].current_col == 0) 
      {
      move_from_NW(n);
      }
   else if (Agent[n].current_row == 0 && Agent[n].current_col == Envr.width-1) 
      {
      move_from_NE(n);
      }
   else if (Agent[n].current_row == Envr.height-1 && Agent[n].current_col == Envr.width-1)
      {
      move_from_SE(n);
      }
   else if (Agent[n].current_row == Envr.height-1 && Agent[n].current_col == 0)
      {
      move_from_SW(n);
      }
   else if (Agent[n].current_row == 0)
      {
      move_from_north(n);
      }
   else if (Agent[n].current_row == Envr.height-1)
      {
      move_from_south(n);
      }
   else if (Agent[n].current_col == 0)
      {
      move_from_west(n);
      }
   else if (Agent[n].current_col == Envr.width-1)
      {
      move_from_east(n);
      }
   else
      {
      move_from_four(n);
      }

//   print_agent_on_grid(n);

   if ( Envr.grid[Agent[n].current_row][Agent[n].current_col] == 1.0)
      return 1;
   else
      return 0;

#ifdef DEBUG
printf("---end move_agent()---\n");
#endif

   }  /* move_agent */

/********** move_from_NW **********/
/* parameters:  n       which agent
   called by:   move_agent(), map.c
   actions:     Routine called when agent is at NW corner (r0, c0).
                Choices numbered from 0 to 1 starting from east clockwise.
*/
void move_from_NW(int n)
   {
   int rand_int;

#ifdef DEBUG
printf("---in move_from_NW()---\n");
#endif

//   rand_int = uniform(2);
   rand_int = choose_from_two(
	Agent[n].memory_map[Agent[n].current_row][Agent[n].current_col+1], 
	Agent[n].memory_map[Agent[n].current_row+1][Agent[n].current_col] );
//printf("               choose_two returns %d\n", rand_int);

   if (rand_int == 0)       Agent[n].current_col++;
   else if (rand_int == 1)  Agent[n].current_row++;
   else  printf(" Error(move_from_NW): invalid move\n");

#ifdef DEBUG_TT
   printf(" -- rand_int %d move to r%d c%d\n",
          rand_int, Agent[n].current_row, Agent[n].current_col);
#endif

#ifdef DEBUG
printf("---end move_from_NW()---\n");
#endif
   }  /* move_from_NW */

/********** move_from_NE **********/
/* parameters:  n       which agent
   called by:   move_agent(), map.c
   actions:     Routine called when agent is at NE corner (r0, c-width).
                Choices numbered from 0 to 1 starting from south clockwise.
*/
void move_from_NE(int n)
   {
   int rand_int;

#ifdef DEBUG
printf("---in move_from_NE()---\n");
#endif

   //rand_int = uniform(2);
   rand_int = choose_from_two(
	Agent[n].memory_map[Agent[n].current_row+1][Agent[n].current_col], 
	Agent[n].memory_map[Agent[n].current_row][Agent[n].current_col-1] );
//printf("               choose_two returns %d\n", rand_int);

   if (rand_int == 0)       Agent[n].current_row++;
   else if (rand_int == 1)  Agent[n].current_col--;
   else  printf(" Error(move_from_NE): invalid move\n");

#ifdef DEBUG_TT
   printf(" -- rand_int %d move to r%d c%d\n",
          rand_int, Agent[n].current_row, Agent[n].current_col);
#endif

#ifdef DEBUG
printf("---end move_from_NE()---\n");
#endif
   }  /* move_from_NE */

/********** move_from_SE **********/
/* parameters:  n       which agent
   called by:   move_agent(), map.c
   actions:     Routine called when agent is at SE corner (r=height, c=width).
                Choices numbered from 0 to 1 starting from west clockwise.
*/
void move_from_SE(int n)
   {
   int rand_int;

#ifdef DEBUG
printf("---in move_from_SE()---\n");
#endif

//   rand_int = uniform(2);
   rand_int = choose_from_two(
	Agent[n].memory_map[Agent[n].current_row][Agent[n].current_col-1], 
	Agent[n].memory_map[Agent[n].current_row-1][Agent[n].current_col] );
//printf("               choose_two returns %d\n", rand_int);

   if (rand_int == 0)       Agent[n].current_col--;
   else if (rand_int == 1)  Agent[n].current_row--;
   else  printf(" Error(move_from_SE): invalid move\n");

#ifdef DEBUG_TT
   printf(" -- rand_int %d move to r%d c%d\n",
          rand_int, Agent[n].current_row, Agent[n].current_col);
#endif

#ifdef DEBUG
printf("---end move_from_SE()---\n");
#endif
   }  /* move_from_SE */

/********** move_from_SW **********/
/* parameters:  n       which agent
   called by:   move_agent(), map.c
   actions:     Routine called when agent is at SW corner (r=height, c0).
                Choices numbered from 0 to 1 starting from north clockwise.
*/
void move_from_SW(int n)
   {
   int rand_int;

#ifdef DEBUG
printf("---in move_from_SW()---\n");
#endif

   //rand_int = uniform(2);
   rand_int = choose_from_two(
	Agent[n].memory_map[Agent[n].current_row-1][Agent[n].current_col], 
	Agent[n].memory_map[Agent[n].current_row][Agent[n].current_col+1] );
//printf("               choose_two returns %d\n", rand_int);

   if (rand_int == 0)       Agent[n].current_row--;
   else if (rand_int == 1)  Agent[n].current_col++;
   else  printf(" Error(move_from_SW): invalid move\n");

#ifdef DEBUG_TT
   printf(" -- rand_int %d move to r%d c%d\n",
          rand_int, Agent[n].current_row, Agent[n].current_col);
#endif

#ifdef DEBUG
printf("---end move_from_SW()---\n");
#endif
   }  /* move_from_SW */

/********** move_from_east **********/
/* parameters:  n       which agent
   called by:   move_agent(), map.c
   actions:     Routine called when agent is on eastern edge (c=width).
		Choices numbered from 0 to 2 starting from south clockwise.
*/
void move_from_east(int n)
   {
   int rand_int;

#ifdef DEBUG
printf("---in move_from_east()---\n");
#endif

   //rand_int = uniform(3);
   rand_int = choose_from_three(
	Agent[n].memory_map[Agent[n].current_row+1][Agent[n].current_col], 
	Agent[n].memory_map[Agent[n].current_row][Agent[n].current_col-1], 
	Agent[n].memory_map[Agent[n].current_row-1][Agent[n].current_col] );
//printf("               choose_three returns %d\n", rand_int);

   if (rand_int == 0)       Agent[n].current_row++;
   else if (rand_int == 1)  Agent[n].current_col--;
   else if (rand_int == 2)  Agent[n].current_row--;
   else  printf(" Error(move_from_east): invalid move\n");

#ifdef DEBUG_TT
   printf(" -- rand_int %d move to r%d c%d\n", 
          rand_int, Agent[n].current_row, Agent[n].current_col);
#endif

#ifdef DEBUG
printf("---end move_from_east()---\n");
#endif
   }  /* move_from_east */

/********** move_from_south **********/
/* parameters:  n       which agent
   called by:   move_agent(), map.c
   actions:     Routine called when agent is on southern edge (r=height).
                Choices numbered from 0 to 2 starting from west clockwise.
*/
void move_from_south(int n)
   {
   int rand_int;

#ifdef DEBUG
printf("---in move_from_south()---\n");
#endif

   // rand_int = uniform(3);
   rand_int = choose_from_three(
	Agent[n].memory_map[Agent[n].current_row][Agent[n].current_col-1], 
	Agent[n].memory_map[Agent[n].current_row-1][Agent[n].current_col], 
	Agent[n].memory_map[Agent[n].current_row][Agent[n].current_col+1] );
//printf("               choose_three returns %d\n", rand_int);

   if (rand_int == 0)       Agent[n].current_col--;
   else if (rand_int == 1)  Agent[n].current_row--;
   else if (rand_int == 2)  Agent[n].current_col++;
   else  printf(" Error(move_from_south): invalid move\n");

#ifdef DEBUG_TT
   printf(" -- rand_int %d move to r%d c%d\n", 
          rand_int, Agent[n].current_row, Agent[n].current_col);
#endif

#ifdef DEBUG
printf("---end move_from_south()---\n");
#endif
   }  /* move_from_south */

/********** move_from_west **********/
/* parameters:  n       which agent
   called by:   move_agent(), map.c
   actions:     Routine called when agent is on western edge (c0).
                Choices numbered from 0 to 2 starting from north clockwise.
*/
void move_from_west(int n)
   {
   int rand_int;

#ifdef DEBUG
printf("---in move_from_west()---\n");
#endif

   //rand_int = uniform(3);
   rand_int = choose_from_three(
	Agent[n].memory_map[Agent[n].current_row-1][Agent[n].current_col], 
	Agent[n].memory_map[Agent[n].current_row][Agent[n].current_col+1], 
	Agent[n].memory_map[Agent[n].current_row+1][Agent[n].current_col] );
//printf("               choose_three returns %d\n", rand_int);

   if (rand_int == 0)       Agent[n].current_row--;
   else if (rand_int == 1)  Agent[n].current_col++;
   else if (rand_int == 2)  Agent[n].current_row++;
   else  printf(" Error(move_from_west): invalid move\n");

#ifdef DEBUG_TT
   printf(" -- rand_int %d move to r%d c%d\n",
          rand_int, Agent[n].current_row, Agent[n].current_col);
#endif

#ifdef DEBUG
printf("---end move_from_west()---\n");
#endif
   }  /* move_from_west */

/********** move_from_north **********/
/* parameters:  n       which agent
   called by:   move_agent(), map.c
   actions:     Routine called when agent is on northern edge (r0).
                Choices numbered from 0 to 2 starting from east clockwise.
*/
void move_from_north(int n)
   {
   int rand_int;

#ifdef DEBUG
printf("---in move_from_north()---\n");
#endif

   // rand_int = uniform(3);
   rand_int = choose_from_three(
	Agent[n].memory_map[Agent[n].current_row][Agent[n].current_col+1], 
	Agent[n].memory_map[Agent[n].current_row+1][Agent[n].current_col], 
	Agent[n].memory_map[Agent[n].current_row][Agent[n].current_col-1] );
//printf("               choose_three returns %d\n", rand_int);

   if (rand_int == 0)       Agent[n].current_col++;
   else if (rand_int == 1)  Agent[n].current_row++;
   else if (rand_int == 2)  Agent[n].current_col--;
   else  printf(" Error(move_from_north): invalid move\n");

#ifdef DEBUG_TT
   printf(" -- rand_int %d move to r%d c%d\n",
          rand_int, Agent[n].current_row, Agent[n].current_col);
#endif

#ifdef DEBUG
printf("---end move_from_north()---\n");
#endif
   }  /* move_from_north */

/********** move_from_four **********/
/* parameters:  n       which agent
   called by:   move_agent(), map.c
   actions:     Routine called when agents choose from among four spots.
		Choices numbered from 0 to 3 starting from top clockwise.
*/
void move_from_four(int n)
   {
   int rand_int;

#ifdef DEBUG
printf("---in move_from_four()---\n");
#endif

   //rand_int = uniform(4);
   rand_int = choose_from_four(
	Agent[n].memory_map[Agent[n].current_row-1][Agent[n].current_col], 
	Agent[n].memory_map[Agent[n].current_row][Agent[n].current_col+1], 
	Agent[n].memory_map[Agent[n].current_row+1][Agent[n].current_col], 
	Agent[n].memory_map[Agent[n].current_row][Agent[n].current_col-1] );
//printf("               choose_three returns %d\n", rand_int);

   if (rand_int == 0)       Agent[n].current_row--;
   else if (rand_int == 1)  Agent[n].current_col++;
   else if (rand_int == 2)  Agent[n].current_row++;
   else if (rand_int == 3)  Agent[n].current_col--;
   else  printf(" Error(move_from_east): invalid move\n");

#ifdef DEBUG_TT
   printf(" -- rand_int %d move to r%d c%d\n", 
          rand_int, Agent[n].current_row, Agent[n].current_col);
#endif

#ifdef DEBUG
printf("---end move_from_four()---\n");
#endif

   }  /* move_from_four */

/********** choose_from_two **********/
/* parameters:  two floating point values
   called by:   move_from_**(), map.c
   actions:     Given two double values, choose one of them.
		If the two value are equal, choose randomly;
		otherwise, use either proportional or rank selection.
*/
int choose_from_two(double zero, double one)
   {
   int rand_int;

#ifdef DEBUG
printf("---in choose_from_two()---\n");
#endif

   if (zero == one)
      {
      return uniform(2);
      }
   else
      {
      return choose_rank_two(zero, one);
      }

#ifdef DEBUG
printf("---end choose_from_two()---\n");
#endif

   }  /* choose_from_two */

/********** choose_from_three **********/
/* parameters:  three floating point values
   called by:   move_from_**(), map.c
   actions:     Given three double values, choose one of them.
                If the three value are equal, choose randomly;
                otherwise, use either proportional or rank selection.
*/
int choose_from_three(double zero, double one, double two)
   {
   int rand_int;

#ifdef DEBUG
printf("---in choose_from_three()---\n");
#endif

   if (zero == one && one == two)
      {
      return uniform(3);
      }
   else
      {
      return choose_rank_three(zero, one, two);
      }

#ifdef DEBUG
printf("---end choose_from_three()---\n");
#endif

   }  /* choose_from_three */

/********** choose_from_four **********/
/* parameters:  four floating point values
   called by:   move_from_**(), map.c
   actions:     Given four double values, choose one of them.
                If the four value are equal, choose randomly;
                otherwise, use either proportional or rank selection.
*/
int choose_from_four(double zero, double one, double two, double three)
   {
   int rand_int;

#ifdef DEBUG
printf("---in choose_from_four()---\n");
#endif

   if (zero == one && one == two && two == three)
      {
      return uniform(4);
      }
   else
      {
      return choose_rank_four(zero, one, two, three);
      }

#ifdef DEBUG
printf("---end choose_from_four()---\n");
#endif

   }  /* choose_from_four */

/********** choose_proportional_two **********/
/* parameters:  two floating point values
   called by:   move_from_**(), map.c
   actions:     Given two double values, proportional selection.
*/
int choose_proportional_two(double zero, double one)
   {
   double sum;
   double rand_double;

#ifdef DEBUG
printf("---in choose_proportional_two()---\n");
#endif

   sum = zero + one;
   rand_double = knuth_random();
//printf("---in choose_proportional_two() %lf %lf rand %lf\n",
//one, two, rand_double);
   if (rand_double < one/sum)  return 0;
   else                        return 1;

#ifdef DEBUG
printf("---end choose_proportional_two()---\n");
#endif

   }  /* choose_proportional_two */

/********** choose_proportional_three **********/
/* parameters:  three floating point values
   called by:   move_from_**(), map.c
   actions:     Given three double values, proportional selection.
*/              
int choose_proportional_three(double zero, double one, double two)
   { 
   double sum;
   double rand_double;
   
#ifdef DEBUG
printf("---in choose_proportional_three()---\n");
#endif
 
   sum = zero + one + two;
   rand_double = knuth_random();
//printf("---in choose_proportional_three() %lf %lf %lf rand %lf\n",
//one, two, three, rand_double);
   if (rand_double < one/sum)             return 0;
   else if (rand_double < (one+two)/sum)  return 1;
   else                                   return 2;

#ifdef DEBUG
printf("---end choose_proportional_three()---\n");
#endif

   }  /* choose_proportional_three */

/********** choose_proportional_four **********/
/* parameters:  four floating point values
   called by:   move_from_**(), map.c 
   actions:     Given four double values, proportional selection.
*/                              
int choose_proportional_four(double zero, double one, double two, double three)
   { 
   double sum;  
   double rand_double; 
  
#ifdef DEBUG
printf("---in choose_proportional_four()---\n");
#endif

   sum = zero + one + two + three;
   rand_double = knuth_random();
//printf("---in choose_proportional_four() %lf %lf %lf %lf rand %lf\n",
//one, two, three, four, rand_double);
   if (rand_double < one/sum)                   return 0;
   else if (rand_double < (one+two)/sum)        return 1;
   else if (rand_double < (one+two+three)/sum)  return 2;
   else                                         return 3;

#ifdef DEBUG
printf("---end choose_proportional_four()---\n");
#endif

   }  /* choose_proportional_four */

/********** init_current_map **********/
/* paramaters:  n               agent number
   called by:   agent_act(), agent.c
   actions:     prints all agents.
*/
void init_current_map(int n)
   {
   int r, c;

#ifdef DEBUG
printf("---in init_current_map()---\n");
#endif

   for (r=0; r<Envr.height; r++)
      {
      for (c=0; c<Envr.width; c++)
         {
         Agent[n].current_map[r][c] = 0;
         }
      }

#ifdef DEBUG
printf("---end init_current_map()---\n");
#endif
   return;
   }  /* init_current_map */

/********** print_current_map **********/
/* paramaters:  n               agent number
   called by:   agent_act(), agent.c
   actions:     prints specified agent's current map.
*/
void print_current_map(int n)
   {
   int r, c;

#ifdef DEBUG
printf("---in print_current_map()---\n");
#endif

   for (r=0; r<Envr.height; r++)
      {
      for (c=0; c<Envr.width; c++)
         {
         printf(" %3d", Agent[n].current_map[r][c]);
         }
      printf("\n");
      }

#ifdef DEBUG
printf("---end print_current_map()---\n");
#endif
   return;
   }  /* print_current_map */

/********** print_memory_map **********/
/* paramater:  n               agent number
   called by:   agent_act(), agent.c
   actions:     prints specified agent's memory map.
*/
void print_memory_map(int n)
   {
   int r, c;

#ifdef DEBUG
printf("---in print_memory_map()---\n");
#endif

   for (r=0; r<Envr.height; r++)
      {
      for (c=0; c<Envr.width; c++)
         {
         printf(" %5.2lf", Agent[n].memory_map[r][c]);
         }
      printf("\n");
      }

#ifdef DEBUG
printf("---end print_memory_map()---\n");
#endif
   return;
   }  /* print_memory_map */

/********** fprint_memory_map **********/
/* paramater:	n		agent number
   called by:   agent_act(), agent.c
   actions:     prints specified agent's memory map.
*/
void fprint_memory_map(FILE *fp, int n)
   {
   int r, c;

#ifdef DEBUG
printf("---in fprint_memory_map()---\n");
#endif

   for (r=0; r<Envr.height; r++)
      {
      for (c=0; c<Envr.width; c++)
         {
         fprintf(fp, " %lf", Agent[n].memory_map[r][c]);
         }
      fprintf(fp, "\n");
      }

#ifdef DEBUG
printf("---end fprint_memory_map()---\n");
#endif
   return;
   }  /* fprint_memory_map */

/********** choose_rank_two **********/
/* parameters:  two floating point values
   called by:   move_from_**(), map.c
   actions:     Given two double values, rank selection.
*/
int choose_rank_two(double zero, double one)
   {
   double rand_double;

#ifdef DEBUG
printf("---in choose_rank_two()---\n");
#endif

   rand_double = knuth_random();
//printf("---in choose_rank_two() %lf %lf rand %lf\n",
//one, two, rand_double);

   if (zero > one)
      {
      if (rand_double < 2.0/3.0)  return 0;
      else                        return 1;
      }
   else 
      {
      if (rand_double < 2.0/3.0)  return 1;
      else                        return 0;
      }

#ifdef DEBUG
printf("---end choose_rank_two()---\n");
#endif
   }  /* choose_rank_two */

/********** choose_rank_three **********/
/* parameters:  three floating point values
   called by:   move_from_**(), map.c
   actions:     Given three double values, rank selection.
*/              
int choose_rank_three(double zero, double one, double two)
   { 
   double sum;
   double rand_double;
   int *order;
   
#ifdef DEBUG
printf("---in choose_rank_three()---\n");
#endif

   order = (int *)malloc(3 * sizeof(int));
   rand_double = knuth_random();
   get_order_three(zero, one, two, order);
   sum = 1 + 2 + 3;
//printf("---in choose_rank_three() %lf %lf %lf rand %lf\n",
//one, two, three, rand_double);
   if (rand_double < 3.0/sum)               return order[0];
   else if (rand_double < (3.0 + 2.0)/sum)  return order[1];
   else                                     return order[2];

#ifdef DEBUG
printf("---end choose_rank_three()---\n");
#endif
   }  /* choose_rank_three */

/********** get_order_three **********/
/* parameters:  three floating point values and an order array (int)
   called by:   choose_rank_three(), map.c
   actions:     Given three double values and an integer order array,
		fills in the order array with the indices of the double
		values, from largest value to smallest value.
*/
void get_order_three(double zero, double one, double two, int *order)
   {
   struct item choices[3];
   int i, j;
   double tempvalue;
   int tempindex;

   choices[0].value = zero;
   choices[1].value = one;
   choices[2].value = two;
   choices[0].index = 0;
   choices[1].index = 1;
   choices[2].index = 2;

   for (i=0; i<3; i++)  
      {
      for (j=i; j<3; j++)
         {
         if (choices[i].value < choices[j].value)
            {
            tempindex = choices[i].index;
            tempvalue = choices[i].value;
            choices[i].index = choices[j].index;
            choices[i].value = choices[j].value;
            choices[j].index = tempindex;
            choices[j].value = tempvalue;
            }

         }
      }

   for (i=0; i<3; i++)
      {
      order[i] = choices[i].index;
      }
   }  /* get_order_three */

/********** choose_rank_four **********/
/* parameters:  four floating point values
   called by:   move_from_**(), map.c
   actions:     Given four double values, rank selection.
*/
int choose_rank_four(double zero, double one, double two, double three)
   {
   double sum;
   double rand_double;
   int *order;
   int i;

#ifdef DEBUG
printf("---in choose_rank_four()---\n");
#endif

   order = (int *)malloc(3 * sizeof(int));
   rand_double = knuth_random();
   get_order_four(zero, one, two, three, order);
//for (i=0; i<4; i++) printf(" %d\n", order[i]);
   sum = 1 + 2 + 3 + 4;
//printf("---in choose_rank_four() %lf %lf %lf %lf rand %lf\n",
//zero, one, two, three, rand_double);
   if (rand_double < 4.0/sum)                     return order[0];
   else if (rand_double < (4.0 + 3.0)/sum)        return order[1];
   else if (rand_double < (4.0 + 3.0 + 2.0)/sum)  return order[2];
   else                                           return order[3];

#ifdef DEBUG
printf("---end choose_rank_four()---\n");
#endif

   }  /* choose_rank_four */

/********** get_order_four **********/
/* parameters:  four floating point values and an order array (int)
   called by:   choose_rank_four(), map.c
   actions:     Given four double values and an integer order array,
                fills in the order array with the indices of the double
                values, from largest value to smallest value.
*/
void get_order_four(double zero, double one, double two, double three, int *order)
   {
   struct item choices[4];
   int i, j;
   double tempvalue;
   int tempindex;

   choices[0].value = zero;
   choices[1].value = one;
   choices[2].value = two;
   choices[3].value = three;
   choices[0].index = 0;
   choices[1].index = 1;
   choices[2].index = 2;
   choices[3].index = 3;

   for (i=0; i<4; i++)
      {
      for (j=i; j<4; j++)
         {
         if (choices[i].value < choices[j].value)
            {
            tempindex = choices[i].index;
            tempvalue = choices[i].value;
            choices[i].index = choices[j].index;
            choices[i].value = choices[j].value;
            choices[j].index = tempindex;
            choices[j].value = tempvalue;
            }

         }
      }

   for (i=0; i<4; i++)
      {
      order[i] = choices[i].index;
      }
   }  /* get_order_four */

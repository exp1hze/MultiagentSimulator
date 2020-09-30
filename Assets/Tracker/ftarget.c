/* ftarget.c
   19.07.15.AW	Created.
		File containing target movement functions.
*/

#include <stdio.h>
#include <string.h>
#include "math.h"

#include "types.h"
#include "extern.h"
#include "ftarget.h"
#include "random.h"

/********** move_target **********/
/* parameters:	t	current timestep
   called by:   step_run(), fxn.c
   actions:
*/
int move_target(int t)
   {
#ifdef DEBUG
printf("---in move_target()---\n");
#endif

   if ( !strcmp(Target_path, "square") )
      {
      path_square(t);
      }
   else if ( !strcmp(Target_path, "square10") )
      {
      path_square10(t);
      }
   else if ( !strcmp(Target_path, "circle") )
      {
      path_circle(t);
      }
   else if ( !strcmp(Target_path, "random") )
      {
      path_random(t);
      }
   else if ( !strcmp(Target_path, "random_manhattan") )
      {
      path_random_manhattan(t);
      }
   else if ( !strcmp(Target_path, "west") )
      {
      path_west(t);
      }
   else if ( !strcmp(Target_path, "northeast") )
      {
      path_northeast(t);
      }
   else if ( !strcmp(Target_path, "northeast_accel") )
      {
      path_northeast_accel(t);
      }
   else if ( !strcmp(Target_path, "sharp") )
      {
      path_sharp(t);
      }
   else if ( !strcmp(Target_path, "random_steep") )
      {
      path_random_steep(t);
      }
   else if ( !strcmp(Target_path, "zigzag") )
      {
      path_zigzag(t);
      }
   else if ( !strcmp(Target_path, "scurve") )
      {
      path_scurve(t);
      }
   else if ( !strcmp(Target_path, "sine") )
      {
      path_sine(t);
      }
   else if ( !strcmp(Target_path, "sine2") )
      {
      path_sine2(t);
      }
   else if ( !strcmp(Target_path, "figure_8") )
      {
      path_figure8(t);
      }
   else
      {
      /* this code will never hit because it is checked in init_target */
      printf(" Error(move_target): invalid target path: %s\n", Target_path);
      return ERROR;
      }

#ifdef DEBUG
printf("---end move_target()---\n");
#endif

   return OK;
   }  /* move_target */

/********** path_square **********/
/* parameters:  t       current timestep
   called by:   move_target(), fxn.c
   actions:
*/
void path_square(int t)
   {
   char side[20];

#ifdef DEBUG
printf("---in path_square()---\n");
#endif

   // move one step
   if ( !strcmp(Target.side, "left") )
      {
      if (Target.y < 80)
         {
         Target.y = Target.y + Target.step_len;
         }
      else
         {
         sprintf(Target.side, "top");
         }
      }
   else if ( !strcmp(Target.side, "top") )
      {
      if (Target.x < 80)
         {
         Target.x = Target.x + Target.step_len;
         }
      else
         {
         sprintf(Target.side, "right");
         }
      }
   else if ( !strcmp(Target.side, "right") )
      {
      if (Target.y > 20)
         {
         Target.y = Target.y - Target.step_len;
         }
      else
         {
         sprintf(Target.side, "bottom");
         }
      }
   else if ( !strcmp(Target.side, "bottom") )
      {
      if (Target.x > 20)
         {
         Target.x = Target.x - Target.step_len;
         }
      else
         {
         sprintf(Target.side, "left");
         }
      }

   // update target length
   Target.length += Target.step_len;

#ifdef DEBUG
printf("---end path_square()---\n");
#endif
   }  /* path_square */

/********** path_square10 **********/
/* parameters:  t       current timestep
   called by:   move_target(), fxn.c
   actions:
*/
void path_square10(int t)
   {
   char side[20];

#ifdef DEBUG
printf("---in path_square10()---\n");
#endif

   // move one step
   if ( !strcmp(Target.side, "left") )
      {
      if (Target.y < 30)
         {
         Target.y = Target.y + Target.step_len;
         }
      else
         {
         sprintf(Target.side, "top");
         }
      }
   else if ( !strcmp(Target.side, "top") )
      {
      if (Target.x < 30)
         {
         Target.x = Target.x + Target.step_len;
         }
      else
         {
         sprintf(Target.side, "right");
         }
      }
   else if ( !strcmp(Target.side, "right") )
      {
      if (Target.y > 20)
         {
         Target.y = Target.y - Target.step_len;
         }
      else
         {
         sprintf(Target.side, "bottom");
         }
      }
   else if ( !strcmp(Target.side, "bottom") )
      {
      if (Target.x > 20)
         {
         Target.x = Target.x - Target.step_len;
         }
      else
         {
         sprintf(Target.side, "left");
         }
      }

   // update target length
   Target.length += Target.step_len;

#ifdef DEBUG
printf("---end path_square10()---\n");
#endif
   }  /* path_square10 */

/********** path_circle **********/
/* parameters:  t       current timestep
   called by:   move_target(), fxn.c
   actions:     Move target in a circle.  Each step is of length
		Target.step_len, which is an angle of 2 * arcsin(step_len/2R).
		This angle is called theta0.

		The trig functions, e.g. cos(x), assume that x is in radians.

		r is the radius of the circle.
		x1, y1 is the starting coordinates.
		x2, y2 is the ending coordinates after moving one step of
		length Target.step_len along the circle.
*/
void path_circle(int t)
   {
   double x1, y1, x2, y2;
   double theta0;
   double r;

#ifdef DEBUG
printf("---in path_circle()---\n");
#endif

   x1 = Target.x;
   y1 = Target.y;
   r = Circle_radius;
   //r = 30;
   theta0 = 2 * asin(Target.step_len / (2 * r) );

/*
printf(" x1 %lf y1 %lf r %lf theta0 %lf %lf\n", x1, y1, r, theta0,
theta0/(2*3.14159)*360);
*/

   if (x1 >= 0 && y1 >= 0)
      {
      // NE quadrant
      Target.y = y2 = r * sin( asin(y1/r) - theta0 );
      Target.x = x2 = r * cos( acos(x1/r) - theta0 );
      }
   else if (x1 >= 0 && y1 < 0)
      {
      // SE quadrant
      Target.y = y2 = r * sin( asin(y1/r) - theta0 );
      Target.x = x2 = r * cos( asin(y1/r) - theta0 );
      }
   else if (x1 < 0 && y1 < 0)
      {
      // SW quadrant
      //Target.y = y2 = (-1) * r * sin( 2 * M_PI - asin(y1/r) + theta0 );
      //Target.x = x2 = (-1) * r * cos( 2 * M_PI - acos(x1/r) + theta0 );
      Target.y = y2 = (-1) * r * sin( acos((-1)*x1/r) - theta0 );
      Target.x = x2 = (-1) * r * cos( asin((-1)*y1/r) - theta0 );
      }
   else if (x1 < 0 && y1 >= 0)
      {
      Target.y = y2 = r * sin( asin(y1/r) + theta0 );
      Target.x = x2 = (-1) * r * cos( acos((-1)*x1/r) + theta0 );
      }

   // update target length
   Target.length += sqrt( (x2-x1)*(x2-x1) + (y2-y1)*(y2-y1) );

#ifdef DEBUG
printf("---end path_circle()---\n");
#endif
   }  /* path_circle */

/********** path_random **********/
/* parameters:  t       current timestep
   called by:   move_target(), fxn.c
   actions:     Move target randomly with Gaussian shift in angle in each step.
                Each step is of length Target.step_len.
*/
void path_random(int t)
   {
   double rand1, rand2, r, theta;		// box muller variables
   double gaussian_rand;
   double x1, y1, x2, y2;

#ifdef DEBUG
printf("---in path_random()---\n");
#endif
   x1 = Target.x;
   y1 = Target.y;

   rand1 = knuth_random();
   while(rand1 == 0.0)
      rand1 = knuth_random();
   rand2 = knuth_random();
   r = sqrt( -2 * log(rand1) );
   theta = 2 * M_PI * rand2;
   if ( t%2 == 0)  gaussian_rand = r * cos(theta);
   else            gaussian_rand = r * sin(theta);

   Target.angle += gaussian_rand;
   if (Target.angle > 2 * M_PI)  Target.angle = Target.angle - (2 * M_PI);
   else if (Target.angle < 0)    Target.angle = (2 * M_PI) + Target.angle;

   x2 = cos(Target.angle) * Target.step_len + Target.x;
   y2 = sin(Target.angle) * Target.step_len + Target.y;

   Target.x = x2;
   Target.y = y2;

   // update target length
   Target.length += sqrt( (x2-x1)*(x2-x1) + (y2-y1)*(y2-y1) );

#ifdef DEBUG
printf("---end path_random()---\n");
#endif
   }  /* path_random */

/********** path_random_manhattan **********/
/* parameters:  t       current timestep
   called by:   move_target(), fxn.c
   actions:	Move target randomly.  At each cell, randomly chooses one of
		the four possible neighbors.
		Each step is of length Target.step_len.
*/
void path_random_manhattan(int t)
   {
   char side[20];
   int rand_num;

#ifdef DEBUG
printf("---in path_random_manhattan()---\n");
#endif

   rand_num = uniform(4);

   if (rand_num == 0)
      {
      // move north
      Target.y += Target.step_len;
      }
   else if (rand_num == 1)
      {
      // move east
      Target.x += Target.step_len;
      }
   else if (rand_num == 2)
      {
      // move south
      Target.y -= Target.step_len;
      }
   else if (rand_num == 3)
      {
      // move west
      Target.x -= Target.step_len;
      }

   // update target length
   Target.length += Target.step_len;

#ifdef DEBUG
printf("---end path_random_manhattan()---\n");
#endif
   }  /* path_random_manhattan */

/********** path_west **********/
/* parameters:  t       current timestep
   called by:   move_target(), fxn.c
   actions:     Move target due west in each step.
                Each step is of length Target.step_len.
*/
void path_west(int t)
   {

#ifdef DEBUG
printf("---in path_west()---\n");
#endif

   Target.x -= Target.step_len;

   // update target length
   Target.length += Target.step_len;

#ifdef DEBUG
printf("---end path_west()---\n");
#endif
   }  /* path_west */

/********** path_northeast **********/
/* parameters:  t       current timestep
   called by:   move_target(), fxn.c
   actions:     Move target northeast in each step.
                Each step is of length Target.step_len.
*/
void path_northeast(int t)
   {

#ifdef DEBUG
printf("---in path_northeast()---\n");
#endif

   Target.x += sqrt((Target.step_len * Target.step_len)/2.0);
   Target.y += sqrt((Target.step_len * Target.step_len)/2.0);

   // update target length
   Target.length += Target.step_len;

#ifdef DEBUG
printf("---end path_northeast()---\n");
#endif
   }  /* path_northeast */

/********** path_northeast_accel **********/
/* parameters:  t       current timestep
   called by:   move_target(), fxn.c
   actions:     Move target northeast in each step.
                Each step is of length Target.step_len.
*/
void path_northeast_accel(int t)
   {

#ifdef DEBUG
printf("---in path_northeast_accel()---\n");
#endif

   Target.change = Target.change * 0.9;

   Target.x += sqrt(((Target.step_len-Target.change) *
                     (Target.step_len-Target.change))/2.0);
   Target.y += sqrt(((Target.step_len-Target.change) *
                     (Target.step_len-Target.change))/2.0);

   // update target length
   Target.length += Target.step_len-Target.change;

#ifdef DEBUG
printf("---end path_northeast_accel()---\n");
#endif
   }  /* path_northeast_accel */

/********** path_sharp **********/
/* parameters:  t       current timestep
   called by:   move_target(), fxn.c
   actions:
*/
void path_sharp(int t)
   {
   double randnum;
   double x1, y1, x2, y2;

#ifdef DEBUG
printf("---in path_sharp()---\n");
#endif

   x1 = Target.x;
   y1 = Target.y;

   if (Target.angle >= 0 && Target.angle <= M_PI_2)  // NE quadrant
      {
      Target.x = x2 = Target.x + Target.step_len * sin(Target.angle);
      Target.y = y2 = Target.y + Target.step_len * cos(Target.angle);
      }
   else if (Target.angle >= 0 && Target.angle > M_PI_2)  // NW quadrant
      {
      Target.x = x2 = Target.x - Target.step_len * cos(Target.angle - M_PI_2);
      Target.y = y2 = Target.y + Target.step_len * sin(Target.angle - M_PI_2);
      }
   if (Target.angle < 0 && Target.angle <= M_PI_2)  // SE quadrant
      {
      Target.x = x2 = Target.x + Target.step_len * sin(Target.angle);
      Target.y = y2 = Target.y - Target.step_len * cos(Target.angle);
      }
   else if (Target.angle < 0 && Target.angle > M_PI_2)  // SW quadrant
      {
      Target.x = x2 = Target.x - Target.step_len * cos(Target.angle - M_PI_2);
      Target.y = y2 = Target.y - Target.step_len * sin(Target.angle - M_PI_2);
      }

   // update target length
   Target.length += sqrt( (x2-x1)*(x2-x1) + (y2-y1)*(y2-y1) );

   // should target change direction in next timestep?
   // if changing direction, also change the change_probability -- that way
   // the straight segments will vary in length
   randnum = knuth_random();
   if (randnum < Target.change_probability)
      {
      // randomly pick a direction to move in
      Target.angle += funiform(2 * M_PI);

//      // randomly pick a change percent between 20 and 30 percent
//      Target.change_probability = knuth_random() * 0.1 + 0.2;
      // randomly pick a change percent between 5 and 10 percent
      Target.change_probability = knuth_random() * 0.05 + 0.05;
      }

#ifdef DEBUG
printf("---end path_sharp()---\n");
#endif
   }  /* path_sharp */

/********** path_random_steep **********/
/* parameters:  t       current timestep
                r       previous random
   called by:   move_target(), fxn.c
   actions:
*/
void path_random_steep(int t)
   {
   char side[20];

#ifdef DEBUG
printf("---in path_random_steep()---\n");
#endif

   int rand_num_decision = uniform(4);
   int rand_chance = uniform(101); 
   float directions[] = {0, 180.0, 270.0, 360.0};
   double x1, y1, x2, y2;

   x1 = Target.x;
   y1 = Target.y;
   
   if (t % 50 == 0 || t == 0 || rand_chance >= 90)
   {  
      Target.angle = directions[rand_num_decision];
      printf("CHANGING DIRECTION. Target Angle is %f\n", Target.angle);
   }
   
   if (Target.angle == 0)
   {  
      Target.x += sqrt((Target.step_len * Target.step_len)/2.0);
      Target.y += sqrt((Target.step_len * Target.step_len)/2.0);
   }
   else if (Target.angle == 180)
   {  
      Target.x -=  sqrt((Target.step_len * Target.step_len)/2.0);
      Target.y +=  sqrt((Target.step_len * Target.step_len)/2.0);
   }
   else if (Target.angle == 270)
   {  
      Target.x -= sqrt((Target.step_len * Target.step_len)/2.0);
      Target.y -= sqrt((Target.step_len * Target.step_len)/2.0);
   }
   else if (Target.angle == 360)
   {  
      Target.x +=  sqrt((Target.step_len * Target.step_len)/2.0);
      Target.y -= sqrt((Target.step_len * Target.step_len)/2.0);
   }

   x2 = Target.x;
   y2 = Target.y;
   
   // update target length
   Target.length += sqrt( (x2-x1)*(x2-x1) + (y2-y1)*(y2-y1) );

#ifdef DEBUG
printf("---end path_random_steep()---\n");
#endif
   }  /* path_random_steep */

/********** path_zigzag **********/
/* parameters:  t       current timestep
   called by:   move_target(), fxn.c
   actions:	Start at 0, 0.  Move up by Target.amplitude for Target.period/4,
		then move down by Target.amplitude * 2 for Target.period/2,
		then move up by Target.amplitude for Target.period/4.  Repeat.
*/
void path_zigzag(int t)
   {
#ifdef DEBUG
printf("---in path_zigzag()---\n");
#endif

   double x1, y1, x2, y2;
   double direction_multiplier;

   if ( (Target.y >=0 && Target.y >= Target.amplitude) || 
        (Target.y < 0 && Target.y <= -Target.amplitude) )
      {
      // change directions
      Target.direction = Target.direction * -1;
      }

   x1 = Target.x;
   y1 = Target.y;

   Target.x = x2 = Target.x + 
                   Target.step_len * sin(M_PI/2 - Target.angle);
   Target.y = y2 = Target.y + 
                   Target.step_len * 
                   (Target.direction * cos(M_PI/2 - Target.angle) );

   // update target length
//   printf(" ---------- %lf --\n", sqrt( (x2-x1)*(x2-x1) + (y2-y1)*(y2-y1) ) );
   Target.length += sqrt( (x2-x1)*(x2-x1) + (y2-y1)*(y2-y1) );


#ifdef DEBUG
printf("---end path_zigzag()---\n");
#endif
   }  /* path_zigzag */

/********** path_scurve **********/
/* parameters:  t       current timestep
   called by:   move_target(), fxn.c
   actions:     Start at 0, 0.  Move up by Target.amplitude for Target.period/4,
                then move down by Target.amplitude * 2 for Target.period/2,
                then move up by Target.amplitude for Target.period/4.  Repeat.
		Curved like s-curve instead of straight zigzag.
*/
void path_scurve(int t)
   {
#ifdef DEBUG
printf("---in path_scurve()---\n");
#endif

   double x1, y1, x2, y2;
   double direction_multiplier;

   if (Target.y >=0)
      {
      Target.direction = -1;
      }
   else if (Target.y < 0) 
      {
      Target.direction = 1;
      }

   x1 = Target.x;
   y1 = Target.y;

   Target.x = x2 = Target.x +
                   Target.step_len * sin(M_PI/2 - Target.angle);
   Target.y = y2 = Target.y +
                   Target.step_len *
                   (cos(M_PI/2 - Target.angle) );

   // update target length
//   printf(" ---------- %lf --\n", sqrt( (x2-x1)*(x2-x1) + (y2-y1)*(y2-y1) ) );
   Target.length += sqrt( (x2-x1)*(x2-x1) + (y2-y1)*(y2-y1) );

   // update target angle
   if (y1 >= 0 && y2 < 0)
      Target.angle = -M_PI/2;
   else if (y1 < 0 && y2 >= 0)
      Target.angle = M_PI/2;
   else
      Target.angle = Target.angle + (Target.direction * Target.change);
//printf("** %lf angle\n", Target.angle/M_PI*180);

#ifdef DEBUG
printf("---end path_scurve()---\n");
#endif
   }  /* path_scurve */

/********** path_sine **********/
/* parameters:  t       current timestep
   called by:   move_target(), fxn.c
   actions:
*/
void path_sine(int t)
   {
   double x1, y1, x2, y2;
   double amplitude = 20;
   double phase_shift = 0;
   double x_modifier = 0.2; // The period is 2pi / x_modifier

#ifdef DEBUG
printf("---in path_sine()---\n");
#endif

   x1 = Target.x;
   y1 = Target.y;

   // y = asin(bx + c)
   Target.y = y2 = amplitude*sin((x_modifier * Target.x) + phase_shift);
   Target.x = x2 = Target.x + Target.step_len;

//   printf(" ---------- %lf --\n", sqrt( (x2-x1)*(x2-x1) + (y2-y1)*(y2-y1) ) );
   Target.length += sqrt( (x2-x1)*(x2-x1) + (y2-y1)*(y2-y1) );

#ifdef DEBUG
printf("---end path_sine()---\n");
#endif
   }  /* path_sine */

/********** path_sine2 **********/
/* parameters:  t       current timestep
   called by:   move_target(), fxn.c
   actions:
*/
void path_sine2(int t)
   {
   double x1, y1, x2, y2;
   double c;		// constant to adjust so that basic stepsize is ~1

#ifdef DEBUG
printf("---in path_sine2()---\n");
#endif

   x1 = Target.x;
   y1 = Target.y;

   Target.x = x2 = Target.x + fabs( sin( (t + M_PI)/Target.period ) );
   Target.y = y2 = Target.step_len * sin( t/(Target.amplitude) );

   // update target length
//   printf(" %lf --------------------\n",
//         sqrt( (x2-x1)*(x2-x1) + (y2-y1)*(y2-y1) ) );
   Target.length += sqrt( (x2-x1)*(x2-x1) + (y2-y1)*(y2-y1) );

#ifdef DEBUG
printf("---end path_sine2()---\n");
#endif
   }  /* path_sine2 */

/************ path_figure8 ***********/
/* parameters:  t       current timestep
   called by:   move_target(), fxn.c
   actions:     moves target along figure eight
                trajectory. Each step is of
                length Target.step_len
*/
void path_figure8(int t)
   {
   double x1, y1, x2, y2;

#ifdef DEBUG
printf("--in path_figure8()---\n");
#endif

   x1 = Target.x;
   y1 = Target.y;

   /* Gerono lemniscate given by the parametric
      equations: x = a*sin(t), y = a*sin(t)*cos(t)
   */
   int a = 5;
   Target.x = x2 = a * sin(t);
   Target.y = y2 = a * sin(t) * cos(t);

   Target.length += sqrt( (x2-x1)*(x2-x1) + (y2-y1)*(y2-y1) );

#ifdef DEBUG
printf("---end path_figure8()---\n");
#endif
   } /* path_figure8 */

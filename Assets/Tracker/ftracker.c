 /* ftracker.c
   19.07.16.AW	Created.
		File containing target movement functions.
*/

#include <stdio.h>
#include <string.h>
#include <math.h>

#include "types.h"
#include "extern.h"
#include "ftracker.h"
#include "random.h"

// for debugging -- the code within these defines can be deleted.
//#define TEMP
//#define TEMP2
//#define PUSH

// #define HISTOGRAM_SIZE (int)((Intensity_aging_max - Intensity_aging_min) * 10)
#define HISTOGRAM_SIZE 10

/********** move_tracker **********/
/* parameters:	t	current timestep
   called by:   step_run(), fxn.c
   actions:
*/
int move_tracker(int t)
   {

#ifdef DEBUG
printf("---in move_tracker()---\n");
#endif

   get_distances();
   if (select_tasks() == ERROR)  return ERROR;

   zero_pushes();
    
   // HDM; 2020.03.19
   // if killing agents enabled, check if should occur this time step
   if(Kill_number > 0)
      {
      if(First_extinction == t || 
         (Extinction_period && (t != 0) && (t - First_extinction) % Extinction_period == 0))
         kill_agents(t);
      }
    
   // HDM; 2019.09.19
   if(Intensity_aging && Intensity_variation)
       {
       update_intensities();
       }
   count_pushes();
#ifdef TEMP
   printf("   push north %d push east %d push south %d push west %d\n",
		Tracker.push_north, Tracker.push_east, Tracker.push_south,
		Tracker.push_west);
#endif
   push_tracker_one_step();

#ifdef DEBUG
printf("---end move_tracker()---\n");
#endif

   return OK;
   }  /* move_tracker */

/********** get_distances **********/
/* parameters:
   called by:   move_tracker()
   actions:	get distance between target and tracker,
		absolute, and in individual directions
*/
void get_distances()
   {

#ifdef DEBUG
printf("---in get_distances()---\n");
#endif

   Tracker.difference = sqrt( (Target.x - Tracker.x) * (Target.x - Tracker.x) +
                    (Target.y - Tracker.y) * (Target.y - Tracker.y) );
//  191004.AW  Moved this to step_run() in fxn.c
//   Tracker.total_difference += Tracker.difference;
//
//   if (Tracker.difference > Tracker.max_difference)
//      Tracker.max_difference = Tracker.difference;
//   if (Tracker.difference < Tracker.min_difference)
//      Tracker.min_difference = Tracker.difference;

   Tracker.diff_to_north = 0;
   Tracker.diff_to_south = 0;
   Tracker.diff_to_east = 0;
   Tracker.diff_to_west = 0;

   if (Target.y > Tracker.y)
      {
      Tracker.diff_to_north = Target.y - Tracker.y;
      }
   else if (Target.y < Tracker.y)
      {
      Tracker.diff_to_south = Tracker.y - Target.y;
      }

   if (Target.x > Tracker.x)
      {
      Tracker.diff_to_east = Target.x - Tracker.x;
      }
   else if (Target.x < Tracker.x)
      {
      Tracker.diff_to_west = Tracker.x - Target.x;
      }

#ifdef TEMP
   printf(" *** get_distances()\n");
   printf("      dist %lf target at %lf %lf tracker at %lf %lf\n",
          Tracker.difference, Target.x, Target.y, Tracker.x, Tracker.y);
   printf("      diff_to_north %lf diff_to_south %lf",
	Tracker.diff_to_north, Tracker.diff_to_south);
   printf(" diff_to_east %lf diff_to_west %lf\n",
	Tracker.diff_to_east, Tracker.diff_to_west);
#endif

#ifdef DEBUG
printf("---end get_distances()---\n");
#endif
   }  /* get_distances */

/********** select_tasks **********/
/* parameters:
   called by:   move_tracker()
   actions:     With probability specified by input parameter Prob_check, each
		agent in the population chooses an action for the next time
                step -- choose a direction in which to push or to be idle.

                If more than one direction has a non-zero distance,
                agent selects one randomly for now.  May try other strategies
                in the future.
                1 = N, 2 = E, 3 = S, 4 = W, 0 = not active.
*/
int select_tasks()
   {
   int i;
   double rand_num;

#ifdef DEBUG
printf("---in select_tasks()---\n");
#endif

   // all live agents get a chance (subject to making it thru Prob_check 
   // and Response_prob) to select a task to work on in next timestep
   //
   // 2020-06-09-AW:
   // Move Response_prob code from this function into agent_select_task()
   for (i=0; i<Pop_size; i++)
      {
      if(!Agent[i].dead)
         {
         // prepare for tracking statistics on agent task switching
         Agent[i].previous_task = Agent[i].current_task;

         // variable task duration
         // select task with probability p = agent.prob_check
         // remain on same task with probability 1 - p
         rand_num = knuth_random();
         if (rand_num <= Agent[i].prob_check)
            {
            if (agent_select_task(i) == ERROR)  return ERROR;
            // NB; Spontaneous_response_prob; 2020.06.23
            if (Agent[i].current_task == 0)  // If an agent has not already selected a task
               {
               if (agent_select_task_spontaneous(i) == ERROR) return ERROR;
               }
            }

         /* track agent activity statistics */
         /* check to see if agent switched tasks */
         if (Agent[i].current_task != Agent[i].previous_task)
            Agent[i].count_switch++;
         /* update count of how many times agents worked on each task */
         if (Agent[i].current_task == 1)  Agent[i].count_north++;
         else if (Agent[i].current_task == 2)  Agent[i].count_east++;
         else if (Agent[i].current_task == 3)  Agent[i].count_south++;
         else if (Agent[i].current_task == 4)  Agent[i].count_west++;
         else Agent[i].count_idle++;

         /* 200414AW Adjust agent thresholds here if dynamic thresholds? */
         if (Thresh_dynamic == 1 || Thresh_dynamic == 2)
            {
            adjust_agent_thresholds(i, Agent[i].current_task);
            }
         }
      }

#ifdef DEBUG
printf("---end select_tasks()---\n");
#endif
   return OK;
   }  /* select_tasks */

/********** agent_select_task **********/
/* parameters:	agent_num		index of agent
   called by:   select_tasks()
   actions:     A single agent chooses an action for the next time
		step -- choose a direction in which to push or to be idle.
		If more than one direction has a non-zero distance,
		agent selects one randomly for now.  May try other strategies
		in the future.
		1 = N, 2 = E, 3 = S, 4 = W, 0 = not active.
*/
int agent_select_task(int agent_num)
   {
   int j;
   int directions[5];
   int sum;		// count # tasks that need work
   int chosen_task;
   double rand_num;

#ifdef DEBUG
printf("---in agent_select_task()---\n");
#endif

#ifdef TEMP2
   printf(" *** agent_select_task()\n");
#endif

   sum = 0;

   /* zero out all directions */
   for (j=0; j<5; j++)  directions[j] = 0;

   /* check to see if direction needs work and agent threshold is less */
   if ((Tracker.diff_to_north > 0 &&
       Agent[agent_num].thresh_north < Tracker.diff_to_north))
      {
#ifdef TEMP2
printf("      agent[%d].thresh_north %lf, Tracker.diff_to_north %lf\n",
agent_num, Agent[agent_num].thresh_north, Tracker.diff_to_north);
#endif
      directions[1] = 1;
      sum++;
      }
   if (Tracker.diff_to_east > 0 &&
       Agent[agent_num].thresh_east < Tracker.diff_to_east)
      {
#ifdef TEMP2
printf("      agent[%d].thresh_east %lf, Tracker.diff_to_east %lf\n",
agent_num, Agent[agent_num].thresh_east, Tracker.diff_to_east);
#endif
      directions[2] = 1;
      sum++;
      }
   if (Tracker.diff_to_south > 0 &&
       Agent[agent_num].thresh_south < Tracker.diff_to_south)
      {
#ifdef TEMP2
printf("      agent[%d].thresh_south %lf, Tracker.diff_to_south %lf\n",
agent_num, Agent[agent_num].thresh_south, Tracker.diff_to_south);
#endif
      directions[3] = 1;
      sum++;
      }
   if (Tracker.diff_to_west > 0 &&
       Agent[agent_num].thresh_west < Tracker.diff_to_west)
      {
#ifdef TEMP2
printf("      agent[%d].thresh_west %lf, Tracker.diff_to_west %lf\n",
agent_num, Agent[agent_num].thresh_west, Tracker.diff_to_west);
#endif
      directions[4] = 1;
      sum++;
      }

   /* each agent chooses a direction in which to push */
   /* selects from among five tasks: 0=none, 1=N, 2=E, 3=S, 4=W */
   if ( strcmp(Task_selection, "random") == 0 )
      {
      chosen_task = choose_random(agent_num, sum, directions);
      }
   else if ( strcmp(Task_selection, "urgent") == 0 )
      {
      chosen_task = choose_urgent(agent_num, sum, directions);
      }
   else
      {
      printf(
      " Error(agent_select_task): Invalid value for Task_selection: %s\n",
		Task_selection);
      return ERROR;
      }

   // 2020-06-09.AW:  apply response probability:
   // Agent takes on chosen task with probability given by its own 
   // response_prob; otherwise agent chooses to become idle.
   rand_num = knuth_random();
   if (rand_num <= Agent[agent_num].response_prob)
      {
      Agent[agent_num].current_task = chosen_task;
      }
   else
      {
      Agent[agent_num].current_task = 0;
      }

#ifdef DEBUG
printf("---end agent_select_task()---\n");
#endif
   return OK;
   }  /* agent_select_task */

/********** agent_select_task_spontaneous **********/
/* parameters:	agent_num		index of agent
   called by:   select_tasks()
   actions:     A single agent chooses an action for the next time
		step -- choose a direction in which to push or to be idle.
		If more than one direction has a non-zero distance,
		agent selects one randomly for now.  May try other strategies
		in the future.
		1 = N, 2 = E, 3 = S, 4 = W, 0 = not active.

      Differs from agent_select_task! This function incorporates 
      Spontaneous_response_prob and therefore response thresholds
      do NOT need to be met for an agent to select a task. 
      Made this a separate function in case we want to add more 
      differing code for Spontaneous_response_prob specifically.    
*/
int agent_select_task_spontaneous(int agent_num)
   {
   int j;
   int directions[5];
   int sum;		// count # tasks that need work
   int chosen_task;

#ifdef DEBUG
printf("---in agent_select_task_spontaneous()---\n");
#endif

#ifdef TEMP2
   printf(" *** agent_select_task_spontaneous()\n");
#endif

   sum = 0;

   /* zero out all directions */
   for (j=0; j<5; j++)  directions[j] = 0;

   /* check to see if direction needs work and agent threshold is not met (threshold is higher than distance) */
   if ((Tracker.diff_to_north > 0 &&
       Agent[agent_num].thresh_north >= Tracker.diff_to_north))
      {
#ifdef TEMP2
printf("      agent[%d].thresh_north %lf, Tracker.diff_to_north %lf\n",
agent_num, Agent[agent_num].thresh_north, Tracker.diff_to_north);
#endif
      directions[1] = 1;
      sum++;
      }
   if (Tracker.diff_to_east > 0 &&
       Agent[agent_num].thresh_east >= Tracker.diff_to_east)
      {
#ifdef TEMP2
printf("      agent[%d].thresh_east %lf, Tracker.diff_to_east %lf\n",
agent_num, Agent[agent_num].thresh_east, Tracker.diff_to_east);
#endif
      directions[2] = 1;
      sum++;
      }
   if (Tracker.diff_to_south > 0 &&
       Agent[agent_num].thresh_south >= Tracker.diff_to_south)
      {
#ifdef TEMP2
printf("      agent[%d].thresh_south %lf, Tracker.diff_to_south %lf\n",
agent_num, Agent[agent_num].thresh_south, Tracker.diff_to_south);
#endif
      directions[3] = 1;
      sum++;
      }
   if (Tracker.diff_to_west > 0 &&
       Agent[agent_num].thresh_west >= Tracker.diff_to_west)
      {
#ifdef TEMP2
printf("      agent[%d].thresh_west %lf, Tracker.diff_to_west %lf\n",
agent_num, Agent[agent_num].thresh_west, Tracker.diff_to_west);
#endif
      directions[4] = 1;
      sum++;
      }

   /* each agent chooses a direction in which to push */
   if ( strcmp(Task_selection, "random") == 0 )
      {
      chosen_task = choose_random(agent_num, sum, directions);
      }
   else if ( strcmp(Task_selection, "urgent") == 0 )
      {
      chosen_task = choose_urgent(agent_num, sum, directions);
      }
   else
      {
      printf(
      " Error(agent_select_task): Invalid value for Task_selection: %s\n",
		Task_selection);
      return ERROR;
      }

   // NB; Spontaneous Response Prob; 2020.06.23
   double rand_num = knuth_random();
   if (rand_num < Agent[agent_num].spontaneous_response_prob){
      Agent[agent_num].current_task = chosen_task;
   }else{
      Agent[agent_num].current_task = 0;
   }

   // NB; Spontaneous Response Prob; 2020.06.03
   // Keep track of how many agents are acting due to Spontaneous_response_prob
   if (Agent[agent_num].current_task != 0)
      {
      Agent[agent_num].count_switch_spontaneous += 1;
      }

#ifdef DEBUG
printf("---end agent_select_task_spontaneous()---\n");
#endif
   return OK;
   }  /* agent_select_task_spontaneous */

/********** adjust_agent_thresholds **********/
/* created:	20.04.17.ASW
   parameters:	n		agent index
		tasknum		task that agent chose for current timestep
   called by:	select_tasks()
   actions:	For agent n, decrease the threshold of task #tasknum by
		Thresh_decrease and increase the thresholds of all other tasks
		by Thresh_increase.
		If the agent's new task is to be idle (=0), do nothing.
*/
void adjust_agent_thresholds(int n, int tasknum)
   {
#ifdef DEBUG
printf("---in adjust_agent_thresholds()---\n");
#endif

//printf(" Adjust: agent %d, current task %d\n", n, tasknum);
//printf("               before  N %lf S %lf E %lf W %lf\n",
//	Agent[n].thresh_north,
//	Agent[n].thresh_south,
//	Agent[n].thresh_east,
//	Agent[n].thresh_west);

   // adjust thresholds
   if (tasknum == 1)          // current task is north
      {
      Agent[n].thresh_north -= Thresh_decrease;
      Agent[n].thresh_south += Thresh_increase;
      Agent[n].thresh_east  += Thresh_increase;
      Agent[n].thresh_west  += Thresh_increase;
      }
   else if (tasknum == 2)     // current task is south
      {
      Agent[n].thresh_north += Thresh_increase;
      Agent[n].thresh_south -= Thresh_decrease;
      Agent[n].thresh_east  += Thresh_increase;
      Agent[n].thresh_west  += Thresh_increase;
      }
   else if (tasknum == 3)     // current task is east
      {
      Agent[n].thresh_north += Thresh_increase;
      Agent[n].thresh_south += Thresh_increase;
      Agent[n].thresh_east  -= Thresh_decrease;
      Agent[n].thresh_west  += Thresh_increase;
      }
   else if (tasknum == 4)     // current task is west
      {
      Agent[n].thresh_north += Thresh_increase;
      Agent[n].thresh_south += Thresh_increase;
      Agent[n].thresh_east  += Thresh_increase;
      Agent[n].thresh_west  -= Thresh_decrease;
      }

   // check to make sure they are still within the allowed range
   // north
   if (Agent[n].thresh_north > Agent[n].thresh_max_north)
      Agent[n].thresh_north = Agent[n].thresh_max_north;
   else if (Agent[n].thresh_north < Agent[n].thresh_min_north)
      Agent[n].thresh_north = Agent[n].thresh_min_north;
   // south
   if (Agent[n].thresh_south > Agent[n].thresh_max_south)
      Agent[n].thresh_south = Agent[n].thresh_max_south;
   else if (Agent[n].thresh_south < Agent[n].thresh_min_south)
      Agent[n].thresh_south = Agent[n].thresh_min_south;
   // east
   if (Agent[n].thresh_east > Agent[n].thresh_max_east)
      Agent[n].thresh_east = Agent[n].thresh_max_east;
   else if (Agent[n].thresh_east < Agent[n].thresh_min_east)
      Agent[n].thresh_east = Agent[n].thresh_min_east;
   // west
   if (Agent[n].thresh_west > Agent[n].thresh_max_west)
      Agent[n].thresh_west = Agent[n].thresh_max_west;
   else if (Agent[n].thresh_west < Agent[n].thresh_min_west)
      Agent[n].thresh_west = Agent[n].thresh_min_west;

//printf("               after   N %lf S %lf E %lf W %lf\n",
//	Agent[n].thresh_north,
//	Agent[n].thresh_south,
//	Agent[n].thresh_east,
//	Agent[n].thresh_west);

#ifdef DEBUG
printf("---end adjust_agent_thresholds()---\n");
#endif
   }  /* adjust_agent_thresholds */

/********** choose_random **********/
/* parameters:	agent-num	agent that is selecting task
		sum		# tasks below agent's corresponding thresholds
		directions	array showing which tasks are below agent's
				corresponding thresholds
   called by:   agent_select_task()
   actions:     the specified agent selects a task randomly from among the
		tasks that need work.  Chooses from N/E/S/W.
*/
int choose_random(int agent_num, int sum, int directions[])
   {
   int randnum;
   int count;
   int i;
   int choose_new_task;
   int current_task;		/* chosen task */

#ifdef DEBUG
printf("---in choose_random()---\n");
#endif

#ifdef TEMP2
   printf(" *** choose_random() sum = %d\n", sum);
#endif

//   Agent[agent_num].current_task = 0;
   current_task = 0;

   randnum = uniform(sum)+1;

   count = 0;
   choose_new_task = 0;
   for (i=1; i<5; i++)
      {
      if (directions[i] == 1)
         {
         count++;
         if (count == randnum)
            {
            choose_new_task = i;
            //Agent[agent_num].current_task = i;
            current_task = i;
            break;
            }
         }
      }

#ifdef TEMP2
   printf("      agent %d, sum %d, directions %d. %d %d %d %d choose %d current %d\n",
	agent_num, sum, directions[0],
	directions[1], directions[2], directions[3], directions[4],
	choose_new_task, current_task);
#endif

#ifdef DEBUG
printf("---end choose_random()---\n");
#endif
   return current_task;
   }  /* choose_random */

/********** choose_urgent **********/
/* parameters:	agent-num	agent that is selecting task
		sum		# tasks below agent's corresponding thresholds
		directions	array showing which tasks are below agent's
				corresponding thresholds
   called by:   agent_select_task()
   actions:     the specified agent selects the most urgent task that falls
		under the agent's corresponding threshold.
*/
int choose_urgent(int agent_num, int sum, int directions[])
   {
   int most_urgent_task;
   double most_urgent_stimulus;
   int current_task;

#ifdef DEBUG
printf("---in choose_urgent()---\n");
#endif

#ifdef TEMP2
   printf(" *** choose_urgent() sum %d\n", sum);
#endif

   //Agent[agent_num].current_task = 0;
   current_task = 0;

   if (sum == 1)
      {
#ifdef TEMP2
printf(" sum = 1\n");
#endif
      // if only one task stimulus falls under this agent's corresponding
      // threshold, that is this agent's most urgent task.
      //if (directions[1] == 1)       Agent[agent_num].current_task = 1;
      //else if (directions[2] == 1)  Agent[agent_num].current_task = 2;
      //else if (directions[3] == 1)  Agent[agent_num].current_task = 3;
      //else if (directions[4] == 1)  Agent[agent_num].current_task = 4;
      if (directions[1] == 1)       current_task = 1;
      else if (directions[2] == 1)  current_task = 2;
      else if (directions[3] == 1)  current_task = 3;
      else if (directions[4] == 1)  current_task = 4;
      }
   else
      {
#ifdef TEMP2
printf(" sum = %d\n", sum);
#endif
      // if sum is greater than one, find the most urgent task of the tasks
      // whose stimuli fall under the agent's corresponding threshold.
      most_urgent_task = 0;
      most_urgent_stimulus = -1.0;
      if (directions[1] == 1 && Tracker.diff_to_north > most_urgent_stimulus)
         {
         most_urgent_task = 1;
         most_urgent_stimulus = Tracker.diff_to_north;
#ifdef TEMP2
printf(" north mutask %d mustim %lf\n", most_urgent_task, most_urgent_stimulus);
#endif
         }
      if (directions[2] == 1 && Tracker.diff_to_east > most_urgent_stimulus)
         {
         most_urgent_task = 2;
         most_urgent_stimulus = Tracker.diff_to_east;
#ifdef TEMP2
printf(" east  mutask %d mustim %lf\n", most_urgent_task, most_urgent_stimulus);
#endif
         }
      if (directions[3] == 1 && Tracker.diff_to_south > most_urgent_stimulus)
         {
         most_urgent_task = 3;
         most_urgent_stimulus = Tracker.diff_to_south;
#ifdef TEMP2
printf(" south mutask %d mustim %lf\n", most_urgent_task, most_urgent_stimulus);
#endif
         }
      if (directions[4] == 1 && Tracker.diff_to_west > most_urgent_stimulus)
         {
         most_urgent_task = 4;
         most_urgent_stimulus = Tracker.diff_to_west;
#ifdef TEMP2
printf(" west  mutask %d mustim %lf\n", most_urgent_task, most_urgent_stimulus);
#endif
         }
      //Agent[agent_num].current_task = most_urgent_task;
      current_task = most_urgent_task;
      }

#ifdef TEMP2
printf("      agent %d, current task %d\n", agent_num, current_task);
#endif

#ifdef DEBUG
printf("---end choose_urgent()---\n");
#endif
   return current_task;
   }  /* choose_urgent */

// HDM; 2019.09.19
/********** update_intensities **********/
/* parameters:
   called by:   move_tracker()
   actions:     apply aging to agent intensities for all agents
                increases by Intensity_aging_step if selected
                decreases by Intensity_aging_step if not selected
*/
void update_intensities()
    {
#ifdef DEBUG
printf("---in update_intensities()---\n");
#endif
    if(Intensity_aging)
       zero_tracker_distribution();
    for(int i = 0; i < Pop_size; i++)
        {
        if(!Agent[i].dead)
           {
           age_one_agent(i);
           update_intensity_totals(i);
           }
        }
    if(Intensity_aging)
       update_tracker_distribution();

#ifdef DEBUG
printf("---end update_intensities()---\n");
#endif
    }   /* update_intensities */

// HDM; 2019.09.19
/********** age_one_agent **********/
/* parameters:  i  agent number
   called by:   age_intensities()
   actions:     apply intensity aging to Agent[i]
*/
void age_one_agent(int i)
    {
#ifdef DEBUG
printf("---in age_one_agent()---\n");
#endif
    if(Agent[i].current_task == 1)
        {
        Agent[i].intensity_north += Intensity_aging_up;
        Agent[i].intensity_south -= Intensity_aging_down;
        Agent[i].intensity_east -= Intensity_aging_down;
        Agent[i].intensity_west -= Intensity_aging_down;
        }
    else if(Agent[i].current_task == 2)
        {
        Agent[i].intensity_north -= Intensity_aging_down;
        Agent[i].intensity_south -= Intensity_aging_down;
        Agent[i].intensity_east += Intensity_aging_up;
        Agent[i].intensity_west -= Intensity_aging_down;
        }
    else if(Agent[i].current_task == 3)
        {
        Agent[i].intensity_north -= Intensity_aging_down;
        Agent[i].intensity_south += Intensity_aging_up;
        Agent[i].intensity_east -= Intensity_aging_down;
        Agent[i].intensity_west -= Intensity_aging_down;
        }
    else if(Agent[i].current_task == 4)
        {
        Agent[i].intensity_north -= Intensity_aging_down;
        Agent[i].intensity_south -= Intensity_aging_down;
        Agent[i].intensity_east -= Intensity_aging_down;
        Agent[i].intensity_west += Intensity_aging_up;
        }
    else if(Agent[i].current_task == 0)
        {
        Agent[i].intensity_north -= Intensity_aging_down;
        Agent[i].intensity_south -= Intensity_aging_down;
        Agent[i].intensity_east -= Intensity_aging_down;
        Agent[i].intensity_west -= Intensity_aging_down;
        }


    // adjust the intensity if after aging it is out of acceptable range
    if (Intensity_variation == 1)
    {
      if(Agent[i].intensity_north > Intensity_aging_max)
          Agent[i].intensity_north = Intensity_aging_max;
      else if(Agent[i].intensity_north < Intensity_aging_min)
          Agent[i].intensity_north = Intensity_aging_min;
      if(Agent[i].intensity_south > Intensity_aging_max)
          Agent[i].intensity_south = Intensity_aging_max;
      else if(Agent[i].intensity_south < Intensity_aging_min)
          Agent[i].intensity_south = Intensity_aging_min;
      if(Agent[i].intensity_east > Intensity_aging_max)
          Agent[i].intensity_east = Intensity_aging_max;
      else if(Agent[i].intensity_east < Intensity_aging_min)
          Agent[i].intensity_east = Intensity_aging_min;
      if(Agent[i].intensity_west > Intensity_aging_max)
          Agent[i].intensity_west = Intensity_aging_max;
      else if(Agent[i].intensity_west < Intensity_aging_min)
          Agent[i].intensity_west = Intensity_aging_min;
    }
    /* LR; intensity range variation; 2020.02.01 */
    else if (Intensity_variation == 2)
    {
      if(Agent[i].intensity_north > Agent[i].int_aging_max_n)
          Agent[i].intensity_north = Agent[i].int_aging_max_n;
      else if(Agent[i].intensity_north < Agent[i].int_aging_min_n)
          Agent[i].intensity_north = Agent[i].int_aging_min_n;
      if(Agent[i].intensity_south > Agent[i].int_aging_max_s)
          Agent[i].intensity_south = Agent[i].int_aging_max_s;
      else if(Agent[i].intensity_south < Agent[i].int_aging_min_s)
          Agent[i].intensity_south = Agent[i].int_aging_min_s;
      if(Agent[i].intensity_east > Agent[i].int_aging_max_e)
          Agent[i].intensity_east = Agent[i].int_aging_max_e;
      else if(Agent[i].intensity_east < Agent[i].int_aging_min_e)
          Agent[i].intensity_east = Agent[i].int_aging_min_e;
      if(Agent[i].intensity_west > Agent[i].int_aging_max_w)
          Agent[i].intensity_west = Agent[i].int_aging_max_w;
      else if(Agent[i].intensity_west < Agent[i].int_aging_min_w)
          Agent[i].intensity_west = Agent[i].int_aging_min_w;
    }

    // update min and max intensites for all directions
    if(Agent[i].intensity_north < Agent[i].int_min_n)
        Agent[i].int_min_n = Agent[i].intensity_north;
    if(Agent[i].intensity_south < Agent[i].int_min_s)
        Agent[i].int_min_s = Agent[i].intensity_south;
    if(Agent[i].intensity_east < Agent[i].int_min_e)
        Agent[i].int_min_e = Agent[i].intensity_east;
    if(Agent[i].intensity_west < Agent[i].int_min_w)
        Agent[i].int_min_w = Agent[i].intensity_west;

    if(Agent[i].intensity_north > Agent[i].int_max_n)
        Agent[i].int_max_n = Agent[i].intensity_north;
    if(Agent[i].intensity_south > Agent[i].int_max_s)
        Agent[i].int_max_s = Agent[i].intensity_south;
    if(Agent[i].intensity_east > Agent[i].int_max_e)
        Agent[i].int_max_e = Agent[i].intensity_east;
    if(Agent[i].intensity_west > Agent[i].int_max_w)
        Agent[i].int_max_w = Agent[i].intensity_west;
#ifdef DEBUG
printf("---end age_one_agent()---\n");
#endif

    }   /* age_one_agent */

// HDM; 2020.03.19
/*************** kill_agents *****************/
/* parameters:  int t -- current time step
   called by:   move_tracker()
   actions:     kill agents with lowest idle counts
                number killed = Kill_number
*/
void kill_agents(int t)
   {
   for(int i = 0; i < Kill_number; i++)
      {
      double min_idle = 1000000000.0;
      int index = -1;
      int j;
      for(j = 0; j < Pop_size; j++)
         {
         if(!Agent[j].dead && Agent[j].count_idle < min_idle)
            {
            min_idle = Agent[j].count_idle;
            index = j;
            }
         }
      Agent[index].dead = 1;
      Agent[index].time_killed = t;
      Num_alive--;
      }
#ifdef DEBUG
printf("---end kill_agents()---\n");
#endif
    
   }  /* kill_agents */
   
// HDM; 2019.09.26
/********** update_intensity_totals **********/
/* parameters:  i  agent number
   called by:   update_intensities()
   actions:     update intensity totals for Agent[i]
*/
void update_intensity_totals(int i)
   {
#ifdef DEBUG
printf("---in update_intensity_totals()---\n");
#endif
   Agent[i].int_no_act_n += Agent[i].intensity_north;
   Agent[i].int_no_act_e += Agent[i].intensity_east;
   Agent[i].int_no_act_s += Agent[i].intensity_south;
   Agent[i].int_no_act_w += Agent[i].intensity_west;

   if(Agent[i].current_task == 1)
      Agent[i].int_tot_n += Agent[i].intensity_north;
   else if(Agent[i].current_task == 2)
      Agent[i].int_tot_e += Agent[i].intensity_east;
   else if(Agent[i].current_task == 3)
      Agent[i].int_tot_s += Agent[i].intensity_south;
   else if(Agent[i].current_task == 4)
      Agent[i].int_tot_w += Agent[i].intensity_west;
    
#ifdef DEBUG
printf("---end update_intensity_totals()---\n");
#endif

   } /* update_intensity_totals */


// HDM; 2019.10.10
/********** zero_tracker_distribution **********/
/* parameters:
   called by:   update_intensities()
   actions:     zero tracker intensity counts used for histograms
*/
void zero_tracker_distribution()
   {
#ifdef DEBUG
printf("---in zero_tracker distribution()---\n");
#endif

      for(int i = 0; i < HISTOGRAM_SIZE; i++)
         {
            Tracker.intensity_north_dist[i] = 0;
            Tracker.intensity_south_dist[i] = 0;
            Tracker.intensity_east_dist[i] = 0;
            Tracker.intensity_west_dist[i] = 0;
         }
#ifdef DEBUG
printf("---end zero_tracker_distribution()---\n");
#endif

   } /* zero_tracker_distribution */


// HDM; 2019.10.10
/********** update_tracker_distribution **********/
/* parameters:
   called by:   update_intensities()
   actions:     update tracker intensity counts, used for histograms,
                for this timestep
*/
void update_tracker_distribution()
   {
#ifdef DEBUG
printf("---in update_tracker_distribution()---\n");
#endif

      int index;
      double min = Intensity_aging_min;
    
      for(int i = 0; i < Pop_size; i++)
         {
            if(!Agent[i].dead)
                {
                // TODO make this work for intensity range variation
                if(Intensity_variation == 2)
                   min = Agent[i].int_aging_min_n;
                index = (int)((Agent[i].intensity_north - min) * HISTOGRAM_SIZE);
                if(index >= HISTOGRAM_SIZE)
                   index = HISTOGRAM_SIZE - 1;
                else if(index < 0)
                   index = 0;
                Tracker.intensity_north_dist[index] += 1;

                if(Intensity_variation == 2)
                   min = Agent[i].int_aging_min_s;
                index = (int)((Agent[i].intensity_south - min) * HISTOGRAM_SIZE);
                if(index >= HISTOGRAM_SIZE)
                   index = HISTOGRAM_SIZE - 1;
                else if(index < 0)
                   index = 0;
                Tracker.intensity_south_dist[index] += 1;

                if(Intensity_variation == 2)
                   min = Agent[i].int_aging_min_e;
                index = (int)((Agent[i].intensity_east - min) * HISTOGRAM_SIZE);
                if(index >= HISTOGRAM_SIZE)
                   index = HISTOGRAM_SIZE - 1;
                else if(index < 0)
                   index = 0;
                Tracker.intensity_east_dist[index] += 1;

                if(Intensity_variation == 2)
                   min = Agent[i].int_aging_min_w;
                index = (int)((Agent[i].intensity_west - min) * HISTOGRAM_SIZE);
                if(index >= HISTOGRAM_SIZE)
                   index = HISTOGRAM_SIZE - 1;
                else if(index < 0)
                   index = 0;
                Tracker.intensity_west_dist[index] += 1;
                }  /* !Agent[i].dead */
         }
#ifdef DEBUG
printf("---end update_tracker_distribution()---\n");
#endif

   } /* update_tracker_distribution */


/********** zero_pushes **********/
/* parameters:
   called by:   move_tracker()
   actions:     zero out the push count so that we can
		count number of agents pushing in each direction.
                190727 -- just north/south for now.
*/
void zero_pushes()
   {
#ifdef DEBUG
printf("---in zero_pushes()---\n");
#endif

   Tracker.push_north = 0;
   Tracker.push_south = 0;
   Tracker.push_east = 0;
   Tracker.push_west = 0;
   if (Intensity_variation)
      {
      Tracker.intensity_push_north = 0.0;
      Tracker.intensity_push_south = 0.0;
      Tracker.intensity_push_east = 0.0;
      Tracker.intensity_push_west = 0.0;

      Tracker.intensity_all_north = 0.0;
      Tracker.intensity_all_south = 0.0;
      Tracker.intensity_all_east = 0.0;
      Tracker.intensity_all_west = 0.0;
      }

#ifdef DEBUG
printf("---end zero_pushes()---\n");
#endif
   }  /* zero_pushes */

/********** count_pushes **********/
/* parameters:
   called by:   move_tracker()
   actions:     count number of agents pushing in each direction.
		190727 -- just north/south for now.
*/
void count_pushes()
   {
   int i;

#ifdef DEBUG
printf("---in count_pushes()---\n");
#endif

#ifdef TEMP
   printf(" *** count_pushes()\n");
#endif

   for (i=0; i<Pop_size; i++)
      {
      if(!Agent[i].dead)
         {
          Tracker.intensity_all_north += Agent[i].intensity_north;
          Tracker.intensity_all_east += Agent[i].intensity_east;
          Tracker.intensity_all_south += Agent[i].intensity_south;
          Tracker.intensity_all_west += Agent[i].intensity_west;

          if (Agent[i].current_task == 1)
             {
             Tracker.push_north++;
             // HDM; intensity variation; 2019.09.12
             Tracker.intensity_push_north += Agent[i].intensity_north;
    #ifdef TEMP
             printf("                a %d %lf diff_north %lf\n",
            i, Agent[i].thresh_north, Tracker.diff_to_north);
    #endif
             }  /* agent pushing north */
          else if (Agent[i].current_task == 2)
             {
             Tracker.push_east++;
             // HDM; intensity variation; 2019.09.12
             Tracker.intensity_push_east += Agent[i].intensity_east;
    #ifdef TEMP
             printf("                a %d %lf diff_east %lf\n",
            i, Agent[i].thresh_east, Tracker.diff_to_east);
    #endif
             }  /* agent pushing east */
          else if (Agent[i].current_task == 3)
             {
             Tracker.push_south++;
             // HDM; intensity variation; 2019.09.12
             Tracker.intensity_push_south += Agent[i].intensity_south;
    #ifdef TEMP
             printf("                a %d %lf diff_south %lf\n",
            i, Agent[i].thresh_south, Tracker.diff_to_south);
    #endif
             }  /* agent pushing south */
          else if (Agent[i].current_task == 4)
             {
             Tracker.push_west++;
             // HDM; intensity variation; 2019.09.12
             Tracker.intensity_push_west += Agent[i].intensity_west;
    #ifdef TEMP
             printf("                a %d %lf diff_west %lf\n",
            i, Agent[i].thresh_west, Tracker.diff_to_west);
    #endif
             }  /* agent pushing west */
          }  /* !Agent[i].dead */
      }  /* for loop */

#ifdef DEBUG
printf("---end count_pushes()---\n");
#endif
   }  /* count_pushes */

/********** push_tracker_one_step **********/
/* parameters:
   called by:   move_tracker()
   actions:     push tracker by one step based on the number of agents
		pushing in each direction.
                190727 -- just north/south for now.
*/
void push_tracker_one_step()
   {
   double step_x = 0.0;
   double step_y = 0.0;

#ifdef DEBUG
printf("---in push_tracker_one_step()---\n");
#endif

   step_x = step_y = 0;

   if (Tracker.diff_to_north > 0)
      {
      /* HDM; intensity variation; 2019.09.12 */
      /* with intensity varation, push depends on intensities not counts.
         When intensity is off, all intensities are 1.0 so the change
         is equivalent to previous version. */
       
      /* HDM; 2020.04.21
         Changed calculation of step_x and step_y when Intensity_variation is on.
         New version divides by Num_alive rather than sum of intensities for all agents.
         Difference is small since intensities typically are centered on 1.0.  However,
         this version should work better when we want/need intensities centered on larger
         or smaller values. */
      if (Intensity_variation)
         {
         // step_y = Tracker.intensity_push_north/Tracker.intensity_all_north * Tracker.max_step_len;
         step_y = Tracker.intensity_push_north/(double)Num_alive * Tracker.max_step_len;
         }
      else
         step_y = (double)Tracker.push_north/(double)Num_alive*Tracker.max_step_len;
#ifdef PUSH
      printf("     move north by %lf maxstep %lf\n",
		step_y, Tracker.max_step_len);
#endif
      Tracker.y += step_y;
      }
   else if (Tracker.diff_to_south > 0)
      {
      if (Intensity_variation)
         {
         // step_y = Tracker.intensity_push_south/Tracker.intensity_all_south * Tracker.max_step_len;
         step_y = Tracker.intensity_push_south/(double)Num_alive * Tracker.max_step_len;
         }
      else
         step_y = (double)Tracker.push_south/(double)Num_alive*Tracker.max_step_len;
#ifdef PUSH
      printf("     move south by %lf maxstep %lf\n",
		step_y, Tracker.max_step_len);
#endif
      Tracker.y -= step_y;
      }

   if (Tracker.diff_to_east > 0)
      {
      if (Intensity_variation)
         {
         // step_x = Tracker.intensity_push_east/Tracker.intensity_all_east * Tracker.max_step_len;
         step_x = Tracker.intensity_push_east/(double)Num_alive * Tracker.max_step_len;
         }
      else
      {
         step_x = (double)Tracker.push_east/(double)Num_alive*Tracker.max_step_len;
      }
#ifdef PUSH
      printf("     move east by %lf maxstep %lf\n",
		step_x, Tracker.max_step_len);
#endif
      Tracker.x += step_x;
      }
   else if (Tracker.diff_to_west > 0)
      {
      if (Intensity_variation)
         {
         // step_x = Tracker.intensity_push_west/Tracker.intensity_all_west * Tracker.max_step_len;
         step_x = Tracker.intensity_push_west/(double)Num_alive * Tracker.max_step_len;
         }
      else
         step_x = (double)Tracker.push_west/(double)Num_alive*Tracker.max_step_len;
#ifdef PUSH
      printf("     move west by %lf maxstep %lf\n",
		step_x, Tracker.max_step_len);
#endif
      Tracker.x -= step_x;
      }

   Tracker.current_step_len = sqrt(step_x * step_x + step_y * step_y);
   Tracker.length += Tracker.current_step_len;
#ifdef PUSH
   printf("     move distance %lf\n", sqrt(step_x * step_x + step_y * step_y));
   printf("     total tracker move distance %lf\n", Tracker.length);
#endif

#ifdef DEBUG
printf("---end push_tracker_one_step()---\n");
#endif
   }  /* push_tracker_one_step */

/* File containing descriptions of types, typedefs, and structures
   used in this program.

   08.02.15.AW	Created.
*/

//#define DEBUG	1	/* notes when entering and exiting routines */
//#undef DEBUG
//#define DEBUG_STATUS	1  /* prints msgs as initialization events completed */
//#undef DEBUG_STATUS

/********** error codes **********/
#define OK	0
#define ERROR	-1

/********** other defines **********/
#define INPUT_LINE_LEN 200
#define ENDOFFILE 59
//#define MAX_VALUE 999999
//#define MIN_VALUE -999999

/********** typedefs **********/

/* structure for storing output file information.  Includes
   standard output files and additional ones that may be added
   at the start of a run.
*/
typedef struct
   {
   int on;              /* if on=1, print; if on=0, don't print */
   char *extension;
   char *filename;
   FILE *fp;
   }  OUTPUT_FILE;

/********** problem specific typedefs **********/


/* structure to store food source information */
typedef struct
   {
   double amount;		/* amount that can be gathered each time */
				/* allows possibility of adding rates */
   int type;			/* type of food */
   int row;			/* x location in grid */
   int col;			/* y location in grid */
   }  FOOD;

/* structure for storing environment information */
/* environment is a 2D space with food at random spots */
typedef struct
   {
   int width;
   int height;
   int num_food;
   char init_food[100];		/* random or filename to read locations */
   double **grid;
   FOOD *food;
   int start_row;		/* row and col from which agents start */
   int start_col;
   }  ENVIRONMENT;

/* structure for storing information on each agent */
typedef struct
   {
   int index;			/* name of agent */
   int chosen;			/* agent chosen for this timestep, 0=no 1=yes */
   int num_tasks;		/* number of tasks */
   double *thresh;		/* threshold for tasks [0.0: 1.0] */
   double *response_prob;	/* response probability for each task */
   double **memory_map;		/* agent's accumulated path data */
   int **current_map;		/* agent's map of current path */
   /* agent's current location, initialized to center west */
   int current_row;
   int current_col;
   int distance_travelled;	/* distance traveled in current step */
				/* -1 means no traveling activity */
   int *path_len;		/* save the path lengths travelled */
   // statistics
   int num_times_acted;		/* number of steps agent got to act */
   double avg_path_len;		/* avg path length of times acted */
   double avg_successful_path_len;	/* avg path len when food found */
   int num_successes;		/* number of runs where food is found */

   int alive;			/* is agent alive */
//   double prob_check;
   }  AGENT;

/* structure for storing information on nest */
typedef struct
   {
   int need;			/* number agents needed to be active */
   double **master_memory_map;	/* average of agent memory maps */
   double step_income;		/* amount of food collected each step */
   double total_food;		/* total food collected in a run */
   int step_num_actors;		/* number of actors in each step */
   int total_num_actors;	/* total num agents acted in a run */
   int *step_last_actor;	/* last agent to act in each step */
   int run_last_actor;		/* last actor in run */
   double avg_last_actor;	/* avg last actor in run, avged over steps */
   int num_steps_need_met;	/* #steps where #agents acting >= Need */

//   double food_store;		/* amount of each food type stored */
//   int max_time_step;		/* max time each agent can explore */
//   int *agent_order;            /* array for storing the order in which
//                                   agents act within a timestep. */
   }  NEST;


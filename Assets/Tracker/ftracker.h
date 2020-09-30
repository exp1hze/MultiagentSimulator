/* ftracker.h
   19.07.16.AW	Created.
*/

/* prototypes */
int move_tracker(int t);
void get_distances();
int select_tasks();
int agent_select_task(int agent_num);
void adjust_agent_thresholds(int n, int tasknum);
int choose_random(int agent_num, int sum, int directions[]);
int choose_urgent(int agent_num, int sum, int directions[]);
void update_intensities();                   // HDM; 2019.09.19
void age_one_agent(int i);                   // HDM; 2019.09.19
void update_intensity_totals(int i);         // HDM; 2019.09.26
void kill_agents();                          // HDM; 2020.03.19
void zero_pushes();
void count_pushes();
void push_tracker_one_step();
void zero_tracker_distribution();            // HDM; 2019.10.10
void update_tracker_distribution();          // HDM; 2019.10.10
int agent_select_task_spontaneous(int agent_num); // NB; 2020.05.29
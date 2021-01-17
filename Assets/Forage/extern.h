/* extern.h
   14.10.15.AW	Created.
*/

extern int Rerun;
extern char *Run_num_file;
extern char *Output_path;
extern int Print_params;
extern int Print_agent_paths;
extern int Print_agent_memory;
extern int Print_agent_final_memory;
extern int Max_steps;
extern int Pop_size;
extern double Init_thresh;
extern double Max_thresh;
extern double Min_thresh;
extern double Prob_check;
extern int Run_num;
extern int Max_num_output_files;
extern long Seed;
extern OUTPUT_FILE *Output_file;
extern NEST Nest;
extern AGENT *Agent;
extern ENVIRONMENT Envr;
extern double Response_prob;
extern int Max_sim_time;
extern double Positive_reinforcement;
extern double Negative_reinforcement;

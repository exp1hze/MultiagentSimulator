/* fxn.h
   14.10.15.AW	Created.
*/

/* prototypes */
int init_fxn();
void print_fxn_params(FILE *fp);
int end_fxn();
int run_fxn();
int step_run(int t);
double rand_agent_intensity();                          // HDM; 2019.09.19
int init_agent(int n);
void scale_thresholds(int n);
int init_target();
int init_tracker();
int init_raw_thresholds(int n);
int init_dynamic_threshold_range(int n);
int init_intensities(int n);

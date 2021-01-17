/* output.h */

void print_params(FILE *fp);
void print_opfiles(FILE *fp);
void start_output();
void step_output(int t);
void run_output();
void fprint_pop(FILE *fp);
void fprint_finalagentstats(FILE *fp);
void fprint_finalneststats(FILE *fp);
void fprint_stepdistance(FILE *fp, int t);
void fprint_stepnest(FILE *fp, int t);
void fprint_foodlocations(FILE *fp);
void fprint_finalavgmemory(FILE *fp);
void fprint_path(FILE *fp);
void fprint_finalagentacted(FILE *fp);
void fprint_finalagentavgpathlen(FILE *fp);
void fprint_finalagentsuccesses(FILE *fp);

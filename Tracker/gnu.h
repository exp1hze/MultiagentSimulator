/* gnu.h
   19.07.30.AW	Created.
*/

/* prototypes */
void plot_gnuplot_files();
void fprint_gnu(FILE *fp);
void gnu_stephistnorth(FILE *fp);
void gnu_stephistsouth(FILE *fp);
void gnu_stephisteast(FILE *fp);
void gnu_stephistwest(FILE *fp);
void gnu_stepdemand(FILE *fp);
void gnu_stepsummary(FILE *fp);
void gnu_steptargetpath(FILE *fp);
void gnu_steptrackerpath(FILE *fp);
void gnu_stepbothpaths(FILE *fp);
void gnu_initpop(FILE *fp);
void gnu_finalpop(FILE *fp);
void gnu_stepnorthsouth(FILE *fp);
void gnu_stepeastwest(FILE *fp);
void gnu_stepagentaction(FILE *fp);
void gnu_stepagentactionwtime(FILE *fp);
void gnu_stepthreshnorth(FILE *fp);
void gnu_stepthreshsouth(FILE *fp);
void gnu_stepthresheast(FILE *fp);
void gnu_stepthreshwest(FILE *fp);
void gnu_threshrange(FILE *fp);
void gnu_finalagent(FILE *fp);

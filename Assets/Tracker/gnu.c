/* gnu.c
   19.07.30.AW  Created.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "types.h"
#include "extern.h"
#include "gnu.h"
#include "params.h"

/********** plot_gnuplot_files ***********/
/* Called by:           end_sim(), sim.c
   Parameters:
   Actions:             Execute the gnuplot file for the current run.
*/
void plot_gnuplot_files()
   {
   char cmd[200];
#ifdef DEBUG
printf("---in plot_gnuplot_files()---\n");
#endif

   sprintf(cmd, "cd %s/run.%d && gnuplot run.%d.gnu", 
           Output_path, Run_num, Run_num);
   printf(" Executing: %s\n", cmd);
   system(cmd);

#ifdef DEBUG
printf("---end plot_gnuplot_files()---\n");
#endif
   }  /* plot_gnuplot_files */

/********** fprint_gnu ***********/
/* Called by:           run_output(), output.c
   Parameters:
   Actions:             Print gnuplot file.
*/
void fprint_gnu(FILE *fp)
   {
#ifdef DEBUG
printf("---in fprint_gnu()---\n");
#endif

   if (file_on("stephistnorth") && Intensity_aging)   gnu_stephistnorth(fp);
   if (file_on("stephistsouth") && Intensity_aging)   gnu_stephistsouth(fp);
   if (file_on("stephisteast") && Intensity_aging)    gnu_stephisteast(fp);
   if (file_on("stephistwest") && Intensity_aging)    gnu_stephistwest(fp);
   if (file_on("stepdemand"))                         gnu_stepdemand(fp);
   if (file_on("stepsummary"))                        gnu_stepsummary(fp);
   if (file_on("steptargetpath"))                     gnu_steptargetpath(fp);
   if (file_on("steptrackerpath"))                    gnu_steptrackerpath(fp);
   if (file_on("initpop"))                            gnu_initpop(fp);
   if (file_on("finalpop"))                           gnu_finalpop(fp);
   if (file_on("stepnorthsouth"))                     gnu_stepnorthsouth(fp);
   if (file_on("stepeastwest"))                       gnu_stepeastwest(fp);
   if (file_on("stepagentaction"))                    gnu_stepagentaction(fp);
   if (file_on("steptargetpath") && file_on("steptrackerpath"))
                                                      gnu_stepbothpaths(fp);
   if (file_on("stepthreshnorth") && Thresh_dynamic)  gnu_stepthreshnorth(fp);
   if (file_on("stepthreshsouth") && Thresh_dynamic)  gnu_stepthreshsouth(fp);
   if (file_on("stepthresheast") && Thresh_dynamic)   gnu_stepthresheast(fp);
   if (file_on("stepthreshwest") && Thresh_dynamic)   gnu_stepthreshwest(fp);
   if (file_on("threshrange") && Thresh_dynamic)      gnu_threshrange(fp);
   if (file_on("stepagentactionwtime"))          gnu_stepagentactionwtime(fp);
   if (file_on("finalagent"))                         gnu_finalagent(fp);

#ifdef DEBUG
printf("---end fprint_gnu()---\n");
#endif
   }  /* fprint_gnu */

/********** gnu_stephistnorth ***********/
/* Called by:           fprint_gnu(), gnu.c
   Parameters:
   Actions:             Plots a surface that shows the histogram of
			intensity values per timestep.
*/
void gnu_stephistnorth(FILE *fp)
   {
#ifdef DEBUG
printf("---in gnu_stephistnorth()---\n");
#endif

   fprintf(fp, "set term post eps\n");
   fprintf(fp, "set xlabel \"Timestep\"\n");
   fprintf(fp, "set ylabel \"Bins\"\n");
   fprintf(fp, "set zlabel \"Count\"\n");
   fprintf(fp, "set output \"run.%d.stephistnorth.eps\"\n", Run_num);
   fprintf(fp, "set title \"Histogram of intensity values, north\"\n");
   fprintf(fp, "set dgrid3d 50,50 qnorm 2\n");
   fprintf(fp, "splot \"run.%d.stephistnorth\" using 2:4:6 w lines\n", Run_num);
   fprintf(fp, "unset size\n");
   fprintf(fp, "unset title\n");
   fprintf(fp, "\n");

#ifdef DEBUG
printf("---end gnu_stephistnorth()---\n");
#endif
   }  /* gnu_stephistnorth */

/********** gnu_stephistsouth ***********/
/* Called by:           fprint_gnu(), gnu.c
   Parameters:
   Actions:             Plots a surface that shows the histogram of
			intensity values per timestep.
*/
void gnu_stephistsouth(FILE *fp)
   {
#ifdef DEBUG
printf("---in gnu_stephistsouth()---\n");
#endif

   fprintf(fp, "set term post eps\n");
   fprintf(fp, "set xlabel \"Timestep\"\n");
   fprintf(fp, "set ylabel \"Bins\"\n");
   fprintf(fp, "set zlabel \"Count\"\n");
   fprintf(fp, "set output \"run.%d.stephistsouth.eps\"\n", Run_num);
   fprintf(fp, "set title \"Histogram of intensity values, south\"\n");
   fprintf(fp, "set dgrid3d 50,50 qnorm 2\n");
   fprintf(fp, "splot \"run.%d.stephistsouth\" using 2:4:6 w lines\n", Run_num);
   fprintf(fp, "unset size\n");
   fprintf(fp, "unset title\n");
   fprintf(fp, "\n");

#ifdef DEBUG
printf("---end gnu_stephistsouth()---\n");
#endif
   }  /* gnu_stephistsouth */

/********** gnu_stephisteast ***********/
/* Called by:           fprint_gnu(), gnu.c
   Parameters:
   Actions:             Plots a surface that shows the histogram of
			intensity values per timestep.
*/
void gnu_stephisteast(FILE *fp)
   {
#ifdef DEBUG
printf("---in gnu_stephisteast()---\n");
#endif

   fprintf(fp, "set term post eps\n");
   fprintf(fp, "set xlabel \"Timestep\"\n");
   fprintf(fp, "set ylabel \"Bins\"\n");
   fprintf(fp, "set zlabel \"Count\"\n");
   fprintf(fp, "set output \"run.%d.stephisteast.eps\"\n", Run_num);
   fprintf(fp, "set title \"Histogram of intensity values, east\"\n");
   fprintf(fp, "set dgrid3d 50,50 qnorm 2\n");
   fprintf(fp, "splot \"run.%d.stephisteast\" using 2:4:6 w lines\n", Run_num);
   fprintf(fp, "unset size\n");
   fprintf(fp, "unset title\n");
   fprintf(fp, "\n");

#ifdef DEBUG
printf("---end gnu_stephisteast()---\n");
#endif
   }  /* gnu_stephisteast */

/********** gnu_stephistwest ***********/
/* Called by:           fprint_gnu(), gnu.c
   Parameters:
   Actions:             Plots a surface that shows the histogram of
			intensity values per timestep.
*/
void gnu_stephistwest(FILE *fp)
   {
#ifdef DEBUG
printf("---in gnu_stephistwest()---\n");
#endif

   fprintf(fp, "set term post eps\n");
   fprintf(fp, "set xlabel \"Timestep\"\n");
   fprintf(fp, "set ylabel \"Bins\"\n");
   fprintf(fp, "set zlabel \"Count\"\n");
   fprintf(fp, "set output \"run.%d.stephistwest.eps\"\n", Run_num);
   fprintf(fp, "set title \"Histogram of intensity values, west\"\n");
   fprintf(fp, "set dgrid3d 50,50 qnorm 2\n");
   fprintf(fp, "splot \"run.%d.stephistwest\" using 2:4:6 w lines\n", Run_num);
   fprintf(fp, "unset size\n");
   fprintf(fp, "unset title\n");
   fprintf(fp, "\n");

#ifdef DEBUG
printf("---end gnu_stephistwest()---\n");
#endif
   }  /* gnu_stephistwest */

/********** gnu_stepdemand ***********/
/* Called by:           fprint_gnu(), gnu.c
   Parameters:
   Actions:             Plots a surface that shows the histogram of
                        intensity values per timestep.
*/
void gnu_stepdemand(FILE *fp)
   {
#ifdef DEBUG
printf("---in gnu_stepdemand()---\n");
#endif

   fprintf(fp, "set term post eps color\n");
   fprintf(fp, "set xlabel \"Timestep\"\n");
   fprintf(fp, "set ylabel \"Distance\"\n");

   fprintf(fp, "set output \"run.%d.stepdemandnorth.eps\"\n", Run_num);
   fprintf(fp, "set title \"Demand and delivered, North\"\n");
   fprintf(fp, "plot \"run.%d.stepdemand\" using 2:5 title \"Demand\"  w lines,\\\n",
           Run_num);
   fprintf(fp, "     \"run.%d.stepdemand\" using 2:14 title \"Delivered\" w lines\n",
           Run_num);

   fprintf(fp, "set output \"run.%d.stepdemandsouth.eps\"\n", Run_num);
   fprintf(fp, "set title \"Demand and delivered, South\"\n");
   fprintf(fp, "plot \"run.%d.stepdemand\" using 2:7 title \"Demand\"  w lines,\\\n",
           Run_num);
   fprintf(fp, "     \"run.%d.stepdemand\" using 2:16 title \"Delivered\" w lines\n",
           Run_num);

   fprintf(fp, "set output \"run.%d.stepdemandeast.eps\"\n", Run_num);
   fprintf(fp, "set title \"Demand and delivered, East\"\n");
   fprintf(fp, "plot \"run.%d.stepdemand\" using 2:9 title \"Demand\"  w lines,\\\n",
           Run_num);
   fprintf(fp, "     \"run.%d.stepdemand\" using 2:18 title \"Delivered\" w lines\n",
           Run_num);

   fprintf(fp, "set output \"run.%d.stepdemandwest.eps\"\n", Run_num);
   fprintf(fp, "set title \"Demand and delivered, West\"\n");
   fprintf(fp, "plot \"run.%d.stepdemand\" using 2:11 title \"Demand\"  w lines,\\\n",
           Run_num);
   fprintf(fp, "     \"run.%d.stepdemand\" using 2:20 title \"Delivered\" w lines\n",
           Run_num);

   fprintf(fp, "unset size\n");
   fprintf(fp, "unset title\n");
   fprintf(fp, "\n");

#ifdef DEBUG
printf("---end gnu_stepdemand()---\n");
#endif
   }  /* gnu_stepdemand */

/********** gnu_stepsummary ***********/
/* Called by:           fprint_gnu(), gnu.c
   Parameters:
   Actions:             Plot data from stepsummary file.
			-- target and tracker paths
*/
void gnu_stepsummary(FILE *fp)
   {
#ifdef DEBUG
printf("---in gnu_stepsummary()---\n");
#endif

   // plot length of each step
   fprintf(fp, "set term post eps color\n");
   fprintf(fp, "set output \"run.%d.stepsummary.steplen.eps\"\n", Run_num);
   fprintf(fp, "set title \"Length of each step\"\n");
   fprintf(fp, "set xlabel \"Timestep\"\n");
   fprintf(fp, "set ylabel \"Step length\"\n");
   fprintf(fp, "plot [-2:] \"run.%d.stepsummary\" using 2:18 ", Run_num);
   fprintf(fp, "title \"Target\" w line,\\\n");
   fprintf(fp, "     \"run.%d.stepsummary\" using 2:20 ", Run_num);
   fprintf(fp, "title \"Tracker\" w line lc 3\n");
   fprintf(fp, "unset xlabel\n");
   fprintf(fp, "unset ylabel\n");
   fprintf(fp, "unset title\n");
   fprintf(fp, "\n");

   // plot target and tracker paths with linesp
   fprintf(fp, "set term post eps color\n");
   // make plots long instead of square for some of the paths
   if ( !strcmp(Target_path, "zigzag") ||
        !strcmp(Target_path, "scurve") ||
        !strcmp(Target_path, "sine") ||
        !strcmp(Target_path, "sine2") )
      {
      fprintf(fp, "set size ratio 0.5\n");
      }
   else
      {
      fprintf(fp, "set size square\n");
      }
   fprintf(fp, "set output \"run.%d.stepsummary.paths.linesp.eps\"\n", Run_num);
   fprintf(fp, "set title \"Target and Tracker paths\"\n");
   fprintf(fp, "plot\\\n");
   fprintf(fp, 
   "     \"run.%d.stepsummary\" using 4:5 title \"Target\" w linesp,\\\n",
                Run_num);
   fprintf(fp, 
   "     \"run.%d.stepsummary\" using 7:8 title \"Tracker\" w linesp lc 3\n", Run_num);
   fprintf(fp, "unset size\n");
   fprintf(fp, "unset title\n");
   fprintf(fp, "\n");

   // plot target and tracker paths with just line
   fprintf(fp, "set term post eps color\n");
   // make plots long instead of square for some of the paths
   if ( !strcmp(Target_path, "zigzag") ||
        !strcmp(Target_path, "scurve") ||
        !strcmp(Target_path, "sine") ||
        !strcmp(Target_path, "sine2") )
      {
      fprintf(fp, "set size ratio 0.5\n");
      }
   else
      {
      fprintf(fp, "set size square\n");
      }
   fprintf(fp, "set output \"run.%d.stepsummary.paths.line.eps\"\n", Run_num);
   fprintf(fp, "set size ratio -1\n");
   fprintf(fp, "set title \"Target and Tracker paths\"\n");
   fprintf(fp, "plot\\\n");
   fprintf(fp,
   "     \"run.%d.stepsummary\" using 4:5 title \"Target\" w line,\\\n",
                Run_num);
   fprintf(fp,
   "     \"run.%d.stepsummary\" using 7:8 title \"Tracker\" w line lc 3\n", Run_num);
   fprintf(fp, "unset size\n");
   fprintf(fp, "unset title\n");
   fprintf(fp, "\n");

   // plot distance between target and tracker in each timestep
   fprintf(fp, "set term post eps color\n");
   fprintf(fp, "set size ratio 0.5\n");
   fprintf(fp, "set output \"run.%d.stepsummary.dist.eps\"\n", Run_num);
   fprintf(fp, "set title \"Distance between Target and Tracker\"\n");
   fprintf(fp, "set xlabel \"Timestep\"\n");
   fprintf(fp, "set ylabel \"Distance between target and tracker\"\n");
   fprintf(fp, "plot [-2:] \"run.%d.stepsummary\" using 2:10 w impulse\n",
           Run_num);
   fprintf(fp, "unset size\n");
   fprintf(fp, "unset xlabel\n");
   fprintf(fp, "unset ylabel\n");
   fprintf(fp, "unset title\n");
   fprintf(fp, "\n");

   // plot number of agents pushing in each direction in each timestep
   fprintf(fp, "set term post eps color\n");
   fprintf(fp, "set size ratio 0.5\n");
   fprintf(fp, "set xlabel \"Timestep\"\n");
   fprintf(fp, "set ylabel \"Number of agents\"\n");
   // push north
   fprintf(fp, "set output \"run.%d.stepsummary.pushnorth.eps\"\n", Run_num);
   fprintf(fp, "set title \"Number of agents pushing north\"\n");
   fprintf(fp, "plot [-2:][0:%d] \"run.%d.stepsummary\" using 2:23 w impulse\n",
           Pop_size, Run_num);
   // push east
   fprintf(fp, "set output \"run.%d.stepsummary.pusheast.eps\"\n", Run_num);
   fprintf(fp, "set title \"Number of agents pushing east\"\n");
   fprintf(fp, "plot [-2:][0:%d] \"run.%d.stepsummary\" using 2:25 w impulse\n",
           Pop_size, Run_num);
   // push south
   fprintf(fp, "set output \"run.%d.stepsummary.pushsouth.eps\"\n", Run_num);
   fprintf(fp, "set title \"Number of agents pushing south\"\n");
   fprintf(fp, "plot [-2:][0:%d] \"run.%d.stepsummary\" using 2:27 w impulse\n",
           Pop_size, Run_num);
   // push west
   fprintf(fp, "set output \"run.%d.stepsummary.pushwest.eps\"\n", Run_num);
   fprintf(fp, "set title \"Number of agents pushing west\"\n");
   fprintf(fp, "plot [-2:][0:%d] \"run.%d.stepsummary\" using 2:29 w impulse\n",
           Pop_size, Run_num);
   // idle 
   fprintf(fp, "set output \"run.%d.stepsummary.pushnone.eps\"\n", Run_num);
   fprintf(fp, "set title \"Number of idle agents\"\n");
   fprintf(fp, "plot [-2:][0:%d] \"run.%d.stepsummary\" using 2:31 w impulse\n",
           Pop_size, Run_num);
   // total number of agents pushing in any direction
   fprintf(fp, "set output \"run.%d.stepsummary.pushall.eps\"\n", Run_num);
   fprintf(fp, "set title \"Total number of agents pushing\"\n");
   fprintf(fp, "plot [-2:][0:%d] \"run.%d.stepsummary\" using 2:($23+$25+$27+$29) w impulse\n",
           Pop_size, Run_num);
   // end
   fprintf(fp, "unset size\n");
   fprintf(fp, "unset xlabel\n");
   fprintf(fp, "unset ylabel\n");
   fprintf(fp, "unset title\n");
   fprintf(fp, "\n");

#ifdef DEBUG
printf("---end gnu_stepsummary()---\n");
#endif
   }  /* gnu_stepsummary */

/********** gnu_steptargetpath ***********/
/* Called by:           fprint_gnu(), gnu.c
   Parameters:
   Actions:             Plot target path.
*/
void gnu_steptargetpath(FILE *fp)
   {
#ifdef DEBUG
printf("---in gnu_steptargetpath()---\n");
#endif

   fprintf(fp, "set term post eps color\n");
   fprintf(fp, "set size square\n");
   fprintf(fp, "set output \"run.%d.steptargetpath.eps\"\n", Run_num);
   fprintf(fp, "set title \"Target path\"\n");
   fprintf(fp, "plot \"run.%d.steptargetpath\" using 4:6 w line\n", Run_num);
   fprintf(fp, "unset size\n");
   fprintf(fp, "unset title\n");
   fprintf(fp, "\n");

#ifdef DEBUG
printf("---end gnu_steptargetpath()---\n");
#endif
   }  /* gnu_steptargetpath */

/********** gnu_steptrackerpath ***********/
/* Called by:           fprint_gnu(), gnu.c
   Parameters:
   Actions:             Plot tracker path.
*/
void gnu_steptrackerpath(FILE *fp)
   {
#ifdef DEBUG
printf("---in gnu_steptrackerpath()---\n");
#endif

   fprintf(fp, "set term post eps color\n");
   fprintf(fp, "set size square\n");
   fprintf(fp, "set output \"run.%d.steptrackerpath.eps\"\n", Run_num);
   fprintf(fp, "set title \"Target path\"\n");
   fprintf(fp, "plot \"run.%d.steptrackerpath\" using 4:6 w line\n", Run_num);
   fprintf(fp, "unset size\n");
   fprintf(fp, "unset title\n");
   fprintf(fp, "\n");

#ifdef DEBUG
printf("---end gnu_steptrackerpath()---\n");
#endif
   }  /* gnu_steptrackerpath */

/********** gnu_stepbothpaths ***********/
/* Called by:           fprint_gnu(), gnu.c
   Parameters:
   Actions:             Plot target and tracker paths.
*/
void gnu_stepbothpaths(FILE *fp)
   {
#ifdef DEBUG
printf("---in gnu_stepbothpaths()---\n");
#endif

   fprintf(fp, "set term post eps color\n");
   fprintf(fp, "set size square\n");
   fprintf(fp, "set output \"run.%d.stepbothpaths.eps\"\n", Run_num);
   fprintf(fp, "set title \"Target and Tracker paths\"\n");
   fprintf(fp, "plot\\\n");
//   fprintf(fp, "plot[-35:35][-35:35]\\\n");
   fprintf(fp, "     \"run.%d.steptargetpath\" using 4:6 w linesp,\\\n",
		Run_num);
   fprintf(fp, "     \"run.%d.steptrackerpath\" using 4:6 w linesp\n",
		Run_num);
   fprintf(fp, "unset size\n");
   fprintf(fp, "unset title\n");
   fprintf(fp, "\n");

#ifdef DEBUG
printf("---end gnu_stepbothpaths()---\n");
#endif
   }  /* gnu_stepbothpaths */

/********** gnu_initpop ***********/
/* Called by:           fprint_gnu(), gnu.c
   Parameters:
   Actions:             Print gnuplot file.
*/
void gnu_initpop(FILE *fp)
   {
#ifdef DEBUG
printf("---in gnu_initpop()---\n");
#endif

   // plot raw threshold values -- value between 0.0 and 1.0
   fprintf(fp, "set term post eps color\n");
   fprintf(fp, "set size square\n");
   fprintf(fp, "set output \"run.%d.initpop.rawthresh.eps\"\n", Run_num);
   fprintf(fp, "set xtics (\"N\" 1, \"E\" 2, \"S\" 3, \"W\" 4)\n");
   fprintf(fp, "set ylabel \"Raw thresholds\"\n");
   fprintf(fp, "set title \"Initial population thresholds - raw\"\n");
   fprintf(fp, "plot [0:5][0:1.2]\\\n");
   fprintf(fp, "     \"run.%d.initpop\" using 23:5 w points,\\\n", Run_num);
   fprintf(fp, "     \"run.%d.initpop\" using 24:7 w points,\\\n", Run_num);
   fprintf(fp, "     \"run.%d.initpop\" using 25:9 w points,\\\n", Run_num);
   fprintf(fp, "     \"run.%d.initpop\" using 26:11 w points,\\\n", Run_num);
   fprintf(fp, "     1.0 title \"\" lt 1 lc 7\n");
   fprintf(fp, "unset size\n");
   fprintf(fp, "unset ylabel\n");
   fprintf(fp, "unset xtics\n");
   fprintf(fp, "set xtics\n");
   fprintf(fp, "\n");

   // plot scaled threshold values -- value between 0.0 and Range
   fprintf(fp, "set term post eps color\n");
   fprintf(fp, "set size square\n");
   fprintf(fp, "set output \"run.%d.initpop.scaledthresh.eps\"\n", Run_num);
   fprintf(fp, "set xtics (\"N\" 1, \"E\" 2, \"S\" 3, \"W\" 4)\n");
   fprintf(fp, "set ylabel \"Scaled thresholds\"\n");
   fprintf(fp, "set title \"Initial population thresholds - scaled\"\n");
   fprintf(fp, "plot [0:5][0:%lf]\\\n", Range*1.2);
   fprintf(fp, "     \"run.%d.initpop\" using 23:16 w points,\\\n", Run_num);
   fprintf(fp, "     \"run.%d.initpop\" using 24:18 w points,\\\n", Run_num);
   fprintf(fp, "     \"run.%d.initpop\" using 25:20 w points,\\\n", Run_num);
   fprintf(fp, "     \"run.%d.initpop\" using 26:22 w points,\\\n", Run_num);
   fprintf(fp, "     %lf title \"\" lt 1 lc 7\n", Range);
   fprintf(fp, "unset size\n");
   fprintf(fp, "unset ylabel\n");
   fprintf(fp, "unset xtics\n");
   fprintf(fp, "unset title\n");
   fprintf(fp, "set xtics\n");
   fprintf(fp, "\n");

#ifdef DEBUG
printf("---end gnu_initpop()---\n");
#endif
   }  /* gnu_initpop */

/********** gnu_finalpop ***********/
/* Called by:           fprint_gnu(), gnu.c
   Parameters:
   Actions:             Print gnuplot file.
*/
void gnu_finalpop(FILE *fp)
   {
#ifdef DEBUG
printf("---in gnu_finalpop()---\n");
#endif

   // plot scaled threshold values -- value between 0.0 and Range
   fprintf(fp, "set term post eps color\n");
   fprintf(fp, "set size square\n");
   fprintf(fp, "set output \"run.%d.finalpop.scaledthresh.eps\"\n", Run_num);
   fprintf(fp, "set xtics (\"N\" 1, \"E\" 2, \"S\" 3, \"W\" 4)\n");
   fprintf(fp, "set ylabel \"Scaled thresholds\"\n");
   fprintf(fp, "set title \"Initial population thresholds - scaled\"\n");
   fprintf(fp, "plot [0:5][0:%lf]\\\n", Range*1.2);
   fprintf(fp, "     \"run.%d.finalpop\" using 23:16 w points,\\\n", Run_num);
   fprintf(fp, "     \"run.%d.finalpop\" using 24:18 w points,\\\n", Run_num);
   fprintf(fp, "     \"run.%d.finalpop\" using 25:20 w points,\\\n", Run_num);
   fprintf(fp, "     \"run.%d.finalpop\" using 26:22 w points,\\\n", Run_num);
   fprintf(fp, "     %lf title \"\" lt 1 lc 7\n", Range);
   fprintf(fp, "unset size\n");
   fprintf(fp, "unset ylabel\n");
   fprintf(fp, "unset xtics\n");
   fprintf(fp, "unset title\n");
   fprintf(fp, "set xtics\n");
   fprintf(fp, "\n");

#ifdef DEBUG
printf("---end gnu_finalpop()---\n");
#endif
   }  /* gnu_finalpop */

/********** gnu_stepnorthsouth ***********/
/* Called by:           fprint_gnu(), gnu.c
   Parameters:
   Actions:             Prints two plots -- the target and tracker N/S
			locations and the differences between those
			locations.
*/
void gnu_stepnorthsouth(FILE *fp)
   {
#ifdef DEBUG
printf("---in gnu_stepnorthsouth()---\n");
#endif

   fprintf(fp, "set term post eps color\n");
   fprintf(fp, "set size ratio 0.5\n");
   fprintf(fp, "set output \"run.%d.stepnorthsouth.loc.eps\"\n", Run_num);
   fprintf(fp, "set title \"North/south locations\"\n");
   fprintf(fp, "set xlabel \"Timestep\"\n");
   fprintf(fp, "set ylabel \"y-coordinate\"\n");
   fprintf(fp, "plot \"run.%d.stepnorthsouth\" using 2:4 title \"Target\" w line,\\\n", Run_num);
   fprintf(fp, "     \"run.%d.stepnorthsouth\" using 2:6 title \"Tracker\" w line lc 3\n", Run_num);
   fprintf(fp, "unset size\n");
   fprintf(fp, "\n");

   fprintf(fp, "set term post eps color\n");
   fprintf(fp, "set size ratio 0.5\n");
   fprintf(fp, "set output \"run.%d.stepnorthsouth.diff.eps\"\n", Run_num);
   fprintf(fp, "set title \"North/south difference, Target loc - Tracker loc\"\n");
   fprintf(fp, "set xlabel \"Timestep\"\n");
   fprintf(fp, "set ylabel \"Difference on y-axis\"\n");
   fprintf(fp, "plot \"run.%d.stepnorthsouth\" using 2:8 title \"Target\" w impulse\n", Run_num);
   fprintf(fp, "unset size\n");
   fprintf(fp, "unset xlabel\n");
   fprintf(fp, "unset ylabel\n");
   fprintf(fp, "unset title\n");
   fprintf(fp, "\n");

#ifdef DEBUG
printf("---end gnu_stepnorthsouth()---\n");
#endif
   }  /* gnu_stepnorthsouth */

/********** gnu_stepeastwest ***********/
/* Called by:           fprint_gnu(), gnu.c
   Parameters:
   Actions:             Prints two plots -- the target and tracker N/S
                        locations and the differences between those
                        locations.
*/
void gnu_stepeastwest(FILE *fp)
   {
#ifdef DEBUG
printf("---in gnu_stepeastwest()---\n");
#endif

   fprintf(fp, "set term post eps color\n");
   fprintf(fp, "set size ratio 0.5\n");
   fprintf(fp, "set output \"run.%d.stepeastwest.loc.eps\"\n", Run_num);
   fprintf(fp, "set title \"East/west locations\"\n");
   fprintf(fp, "set xlabel \"Timestep\"\n");
   fprintf(fp, "set ylabel \"x-coordinate\"\n");
   fprintf(fp, "plot \"run.%d.stepeastwest\" using 2:4 title \"Target\" w line,\\\n", Run_num);
   fprintf(fp, "     \"run.%d.stepeastwest\" using 2:6 title \"Tracker\" w line lc 3\n", Run_num);
   fprintf(fp, "unset size\n");
   fprintf(fp, "\n");

   fprintf(fp, "set term post eps color\n");
   fprintf(fp, "set size ratio 0.5\n");
   fprintf(fp, "set output \"run.%d.stepeastwest.diff.eps\"\n", Run_num);
   fprintf(fp, "set title \"East/west difference, Target loc - Tracker loc\"\n");
   fprintf(fp, "set xlabel \"Timestep\"\n");
   fprintf(fp, "set ylabel \"Difference on x-axis\"\n");
   fprintf(fp, "plot \"run.%d.stepeastwest\" using 2:8 title \"Target\" w impulse\n", Run_num);
   fprintf(fp, "unset size\n");
   fprintf(fp, "unset xlabel\n");
   fprintf(fp, "unset ylabel\n");
   fprintf(fp, "unset title\n");
   fprintf(fp, "\n");

#ifdef DEBUG
printf("---end gnu_stepeastwest()---\n");
#endif
   }  /* gnu_stepeastwest */

/********** gnu_stepagentaction ***********/
/* Called by:           fprint_gnu(), gnu.c
   Parameters:
   Actions:             Plot target path.
*/
void gnu_stepagentaction(FILE *fp)
   {
#ifdef DEBUG
printf("---in gnu_stepagentaction()---\n");
#endif

   fprintf(fp, "set term post eps color\n");
   fprintf(fp, "set size ratio %lf\n", (double)Max_steps/(double)Pop_size);
   fprintf(fp, "set output \"run.%d.stepagentaction.eps\"\n", Run_num);
   fprintf(fp, "set title \"Agent actions, 1=N 2=E 3=S 4=W\"\n");
   fprintf(fp, "set xlabel \"Agent\"\n");
   fprintf(fp, "set ylabel \"Timestep\"\n");
   fprintf(fp, "set palette maxcolors 5\n");
   fprintf(fp, "set palette defined (0 \"white\", 1 \"blue\", 2 \"yellow\", 3 \"red\", 4 \"green\")\n");
   fprintf(fp, "set cbrange[-0.5:4.5]\n");
   fprintf(fp, "set view map\n");
   fprintf(fp, "plot [][%d:-2] \"run.%d.stepagentaction\" matrix w image\n",
           Max_steps+1, Run_num);
/*
   fprintf(fp, "unset size\n");
   fprintf(fp, "unset title\n");
   fprintf(fp, "unset xlabel\n");
   fprintf(fp, "unset ylabel\n");
*/
   fprintf(fp, "\n");

#ifdef DEBUG
printf("---end gnu_stepagentaction()---\n");
#endif
   }  /* gnu_stepagentaction */

/********** gnu_stepagentactionwtime ***********/
/* Called by:           fprint_gnu(), gnu.c
   Parameters:
   Actions:             Plot target path.
*/
void gnu_stepagentactionwtime(FILE *fp)
   {
   int spread, i, j;
   double plot_ratio;
#ifdef DEBUG
printf("---in gnu_stepagentactionwtime()---\n");
#endif

   spread = 14;
   fprintf(fp, "set term post eps\n");
   fprintf(fp, "set style rectangle fc rgb \"light-blue\" fs solid noborder\n");
/*
   fprintf(fp, "set style rectangle fc rgb \"gray90\" fs solid noborder\n");
   plot_ratio = (0.5*(double)Max_steps)/(double)Pop_size;
   if (plot_ratio > 2.0)  plot_ratio = 2.0;
   fprintf(fp, "set size ratio %lf\n", plot_ratio);
*/
   fprintf(fp, "set size ratio 2\n");
   fprintf(fp, "set output \"run.%d.stepagentactionwtime.eps\"\n", Run_num);
   fprintf(fp, "set title \"Agent actions\\n0=idle, 1=N, 2=E, 3=S, 4=W\"\n");
   fprintf(fp, "set xlabel \"Timestep\"\n");
   fprintf(fp, "unset ytics\n");
   fprintf(fp, "unset ylabel\n");

   j=0;
   for (i=0; i<Pop_size; i++)
      {
      fprintf(fp, "set object %d rect from 0,%d to %d,%d\n", 
              i+1, j, Max_steps, j+8);
      j+=spread;
      }

   fprintf(fp, "plot [][%lf:%lf]\\\n", 
           (-1)*0.01*(Pop_size*spread), 1.01*(Pop_size*spread));
   j=0;
   for (i=0; i<Pop_size-1; i++)
      {
      fprintf(fp, "     \"run.%d.stepagentactionwtime\"", Run_num);
         fprintf(fp, " using 2:(($%d*2)+%d)", i+3, j);
         fprintf(fp, " title \"\" w line lt 1,\\\n");
      j+=spread;
      }
   fprintf(fp, "     \"run.%d.stepagentactionwtime\"", Run_num);
      fprintf(fp, " using 2:(($%d*2)+%d)", i+3, j);
      fprintf(fp, " title \"\" w line lt 1\n");
   fprintf(fp, "\n");

   for (i=0; i<Pop_size; i++)
      {
      fprintf(fp, "unset object %d\n", i+1);
      }

#ifdef DEBUG
printf("---end gnu_stepagentactionwtime()---\n");
#endif
   }  /* gnu_stepagentactionwtime */

/********** gnu_stepthreshnorth ***********/
/* Called by:           fprint_gnu(), gnu.c
   Parameters:
   Actions:             Plot target path.
*/
void gnu_stepthreshnorth(FILE *fp)
   {
#ifdef DEBUG
printf("---in gnu_stepthreshnorth()---\n");
#endif

   fprintf(fp, "set term post eps color\n");
//   fprintf(fp, "set size ratio %lf\n", (double)Max_steps/(double)Pop_size);
   fprintf(fp, "set size ratio 2\n");
   fprintf(fp, "set output \"run.%d.stepthreshnorth.eps\"\n", Run_num);
   fprintf(fp, "set title \"Agent thresholds: North\"\n");
   fprintf(fp, "set xlabel \"Agent\"\n");
   fprintf(fp, "set ylabel \"Timestep\"\n");
   fprintf(fp, "set palette maxcolors 100\n");
   fprintf(fp, "set palette defined (0 \"green\", %lf \"yellow\", %lf \"red\")\n", Range/2.0, Range);
   fprintf(fp, "set cbrange[0:%lf]\n", Range);
   fprintf(fp, "set view map\n");
   fprintf(fp, "plot [%lf:%lf][%d:-2] \"run.%d.stepthreshnorth\" matrix title \"\" w image\n",
           Pop_size*0.1*(-1), Pop_size*1.1, Max_steps+1, Run_num);
/*
   fprintf(fp, "unset size\n");
   fprintf(fp, "unset title\n");
   fprintf(fp, "unset xlabel\n");
   fprintf(fp, "unset ylabel\n");
*/
   fprintf(fp, "\n");

#ifdef DEBUG
printf("---end gnu_stepthreshnorth()---\n");
#endif
   }  /* gnu_stepthreshnorth */

/********** gnu_stepthreshsouth ***********/
/* Called by:           fprint_gnu(), gnu.c
   Parameters:
   Actions:             Plot target path.
*/
void gnu_stepthreshsouth(FILE *fp)
   {
#ifdef DEBUG
printf("---in gnu_stepthreshsouth()---\n");
#endif

   fprintf(fp, "set term post eps color\n");
//   fprintf(fp, "set size ratio %lf\n", (double)Max_steps/(double)Pop_size);
   fprintf(fp, "set size ratio 2\n");
   fprintf(fp, "set output \"run.%d.stepthreshsouth.eps\"\n", Run_num);
   fprintf(fp, "set title \"Agent thresholds: South\"\n");
   fprintf(fp, "set xlabel \"Agent\"\n");
   fprintf(fp, "set ylabel \"Timestep\"\n");
   fprintf(fp, "set palette maxcolors 100\n");
   fprintf(fp, "set palette defined (0 \"green\", %lf \"yellow\", %lf \"red\")\n", Range/2.0, Range);
   fprintf(fp, "set cbrange[0:%lf]\n", Range);
   fprintf(fp, "set view map\n");
   fprintf(fp, "plot [%lf:%lf][%d:-2] \"run.%d.stepthreshsouth\" matrix title \"\" w image\n",
           Pop_size*0.1*(-1), Pop_size*1.1, Max_steps+1, Run_num);
/*
   fprintf(fp, "unset size\n");
   fprintf(fp, "unset title\n");
   fprintf(fp, "unset xlabel\n");
   fprintf(fp, "unset ylabel\n");
*/
   fprintf(fp, "\n");

#ifdef DEBUG
printf("---end gnu_stepthreshsouth()---\n");
#endif
   }  /* gnu_stepthreshsouth */

/********** gnu_stepthresheast ***********/
/* Called by:           fprint_gnu(), gnu.c
   Parameters:
   Actions:             Plot target path.
*/
void gnu_stepthresheast(FILE *fp)
   {
#ifdef DEBUG
printf("---in gnu_stepthresheast()---\n");
#endif

   fprintf(fp, "set term post eps color\n");
//   fprintf(fp, "set size ratio %lf\n", (double)Max_steps/(double)Pop_size);
   fprintf(fp, "set size ratio 2\n");
   fprintf(fp, "set output \"run.%d.stepthresheast.eps\"\n", Run_num);
   fprintf(fp, "set title \"Agent thresholds: East\"\n");
   fprintf(fp, "set xlabel \"Agent\"\n");
   fprintf(fp, "set ylabel \"Timestep\"\n");
   fprintf(fp, "set palette maxcolors 100\n");
   fprintf(fp, "set palette defined (0 \"green\", %lf \"yellow\", %lf \"red\")\n", Range/2.0, Range);
   fprintf(fp, "set cbrange[0:%lf]\n", Range);
   fprintf(fp, "set view map\n");
   fprintf(fp, "plot [%lf:%lf][%d:-2] \"run.%d.stepthresheast\" matrix title \"\" w image\n",
           Pop_size*0.1*(-1), Pop_size*1.1, Max_steps+1, Run_num);
/*
   fprintf(fp, "unset size\n");
   fprintf(fp, "unset title\n");
   fprintf(fp, "unset xlabel\n");
   fprintf(fp, "unset ylabel\n");
*/
   fprintf(fp, "\n");

#ifdef DEBUG
printf("---end gnu_stepthresheast()---\n");
#endif
   }  /* gnu_stepthresheast */

/********** gnu_stepthreshwest ***********/
/* Called by:           fprint_gnu(), gnu.c
   Parameters:
   Actions:             Plot target path.
*/
void gnu_stepthreshwest(FILE *fp)
   {
#ifdef DEBUG
printf("---in gnu_stepthreshwest()---\n");
#endif

   fprintf(fp, "set term post eps color\n");
//   fprintf(fp, "set size ratio %lf\n", (double)Max_steps/(double)Pop_size);
   fprintf(fp, "set size ratio 2\n");
   fprintf(fp, "set output \"run.%d.stepthreshwest.eps\"\n", Run_num);
   fprintf(fp, "set title \"Agent thresholds: West\"\n");
   fprintf(fp, "set xlabel \"Agent\"\n");
   fprintf(fp, "set ylabel \"Timestep\"\n");
   fprintf(fp, "set palette maxcolors 100\n");
   fprintf(fp, "set palette defined (0 \"green\", %lf \"yellow\", %lf \"red\")\n", Range/2.0, Range);
   fprintf(fp, "set cbrange[0:%lf]\n", Range);
   fprintf(fp, "set view map\n");
   fprintf(fp, "plot [%lf:%lf][%d:-2] \"run.%d.stepthreshwest\" matrix title \"\" w image\n",
           Pop_size*0.1*(-1), Pop_size*1.1, Max_steps+1, Run_num);
/*
   fprintf(fp, "unset size\n");
   fprintf(fp, "unset title\n");
   fprintf(fp, "unset xlabel\n");
   fprintf(fp, "unset ylabel\n");
*/
   fprintf(fp, "\n");

#ifdef DEBUG
printf("---end gnu_stepthreshwest()---\n");
#endif
   }  /* gnu_stepthreshwest */

/********** gnu_threshrange ***********/
/* Called by:           fprint_gnu(), gnu.c
   Parameters:
   Actions:             Plots initial threshold and threshold range for
			every agent.
*/
void gnu_threshrange(FILE *fp)
   {
#ifdef DEBUG
printf("---in gnu_threshrange()---\n");
#endif
   
   fprintf(fp, "set term post eps\n");
   fprintf(fp, "set size ratio %lf\n", 
           (double)Pop_size/((double)Max_steps*0.5) );
   fprintf(fp, "set xlabel \"Agent\"\n");
   fprintf(fp, "set ylabel \"Threshold\"\n");

   fprintf(fp, "set output \"run.%d.threshrangenorth.eps\"\n", Run_num);
   fprintf(fp, "set title \"Agent threshold ranges: North\"\n");
   fprintf(fp, 
	"plot \"run.%d.threshrange\" using 2:4:5:6 title \"\" w errorbars\n",
	Run_num);

   fprintf(fp, "set output \"run.%d.threshrangesouth.eps\"\n", Run_num);
   fprintf(fp, "set title \"Agent threshold ranges: South\"\n");
   fprintf(fp, 
	"plot \"run.%d.threshrange\" using 2:8:9:10 title \"\" w errorbars\n",
	Run_num);

   fprintf(fp, "set output \"run.%d.threshrangeeast.eps\"\n", Run_num);
   fprintf(fp, "set title \"Agent threshold ranges: East\"\n");
   fprintf(fp, 
	"plot \"run.%d.threshrange\" using 2:12:13:14 title \"\" w errorbars\n",
	Run_num);

   fprintf(fp, "set output \"run.%d.threshrangewest.eps\"\n", Run_num);
   fprintf(fp, "set title \"Agent threshold ranges: West\"\n");
   fprintf(fp, 
	"plot \"run.%d.threshrange\" using 2:16:17:18 title \"\" w errorbars\n",
	Run_num);

   fprintf(fp, "\n");

#ifdef DEBUG
printf("---end gnu_threshrange()---\n");
#endif
   }  /* gnu_threshrange */

/********** gnu_finalagent ***********/
/* Called by:           fprint_gnu(), gnu.c
   Parameters:
   Actions:             Print gnuplot file.
*/
void gnu_finalagent(FILE *fp)
   {
#ifdef DEBUG
printf("---in gnu_finalagent()---\n");
#endif

   // plot number of times each agent acted on each task
   fprintf(fp, "set term post eps color\n");
   fprintf(fp, "set size ratio 0.5\n");
   fprintf(fp, "set output \"run.%d.finalagent.count.eps\"\n", Run_num);
   fprintf(fp, "set xtics\n");
   fprintf(fp, "set ytics\n");
   fprintf(fp, "set xlabel \"Agent\"\n");
   fprintf(fp, "set ylabel \"Count\"\n");
   fprintf(fp, "set title \"Number of times acted on each task\"\n");
   fprintf(fp, "plot [-1:%lf][0:%lf]\\\n", Pop_size*1.2, Max_steps*1.1);
   fprintf(fp, "     \"run.%d.finalagent\" using 2:5 title \"N\" ", Run_num);
   fprintf(fp,       "w points pt 1 ps 2 lw 2 lc 1,\\\n");
   fprintf(fp, "     \"run.%d.finalagent\" using 2:6 title \"E\" ", Run_num);
   fprintf(fp,       "w points pt 2 ps 2 lw 2 lc 2,\\\n");
   fprintf(fp, "     \"run.%d.finalagent\" using 2:7 title \"S\" ", Run_num);
   fprintf(fp,       "w points pt 4 ps 2 lw 2 lc 3,\\\n");
   fprintf(fp, "     \"run.%d.finalagent\" using 2:8 title \"W\" ", Run_num);
   fprintf(fp,       "w points pt 6 ps 2 lw 2 lc 4,\\\n");
   fprintf(fp, "     \"run.%d.finalagent\" using 2:4 title \"I\" ", Run_num);
   fprintf(fp,       "w points pt 8 ps 2 lc 7\n");
   fprintf(fp, "unset xlabel\n");
   fprintf(fp, "unset ylabel\n");
   fprintf(fp, "unset title\n");
   fprintf(fp, "unset size\n");
   fprintf(fp, "\n");

   // plot final threshold for each task for each agent
   fprintf(fp, "set term post eps color\n");
   fprintf(fp, "set size ratio 0.5\n");
   fprintf(fp, "set output \"run.%d.finalagent.thresh.eps\"\n", Run_num);
   fprintf(fp, "set xtics\n");
   fprintf(fp, "set ytics\n");
   fprintf(fp, "set xlabel \"Agent\"\n");
   fprintf(fp, "set ylabel \"Threshold\"\n");
   fprintf(fp, "set title \"Final threshold for each task, Range = %lf\"\n",
		Range);
   fprintf(fp, "plot [-1:%lf][0:%lf]\\\n", Pop_size*1.2, Range*1.1);
   fprintf(fp, "     \"run.%d.finalagent\" using 2:10 title \"N\" ", Run_num);
   fprintf(fp,       "w points pt 1 ps 2 lw 2 lc 1,\\\n");
   fprintf(fp, "     \"run.%d.finalagent\" using 2:11 title \"E\" ", Run_num);
   fprintf(fp,       "w points pt 2 ps 2 lw 2 lc 2,\\\n");
   fprintf(fp, "     \"run.%d.finalagent\" using 2:12 title \"S\" ", Run_num);
   fprintf(fp,       "w points pt 4 ps 2 lw 2 lc 3,\\\n");
   fprintf(fp, "     \"run.%d.finalagent\" using 2:13 title \"W\" ", Run_num);
   fprintf(fp,       "w points pt 6 ps 2 lw 2 lc 4\n");
   fprintf(fp, "unset xlabel\n");
   fprintf(fp, "unset ylabel\n");
   fprintf(fp, "unset title\n");
   fprintf(fp, "unset size\n");
   fprintf(fp, "\n");

   // plot number of switches for each agent
   fprintf(fp, "set term post eps color\n");
   fprintf(fp, "set size ratio 0.5\n");
   fprintf(fp, "set output \"run.%d.finalagent.switch.eps\"\n", Run_num);
   fprintf(fp, "set xtics\n");
   fprintf(fp, "set ytics\n");
   fprintf(fp, "set xlabel \"Agent\"\n");
   fprintf(fp, "set ylabel \"Number of switches\"\n");
   fprintf(fp, "set title \"Number of task switches during run\"\n");
   fprintf(fp, "plot [-1:%lf][0:%lf]\\\n", Pop_size*1.2, Max_steps*1.1);
   fprintf(fp, "     \"run.%d.finalagent\" using 2:15 title \"N\" ", Run_num);
   fprintf(fp,       "w points pt 7 ps 2 lc 1\n");
   fprintf(fp, "unset xlabel\n");
   fprintf(fp, "unset ylabel\n"); 
   fprintf(fp, "unset title\n");
   fprintf(fp, "unset size\n");
   fprintf(fp, "\n");

   // NB; 2020.06.03
   // plot number of spontaneous switches for each agent
   fprintf(fp, "set term post eps color\n");
   fprintf(fp, "set size ratio 0.5\n");
   fprintf(fp, "set output \"run.%d.finalagent.spontaneousswitch.eps\"\n", Run_num);
   fprintf(fp, "set xtics\n");
   fprintf(fp, "set ytics\n");
   fprintf(fp, "set xlabel \"Agent\"\n");
   fprintf(fp, "set ylabel \"Number of spontaneous switches\"\n");
   fprintf(fp, "set title \"Number of task switches due to spontaneous response prob during run\"\n");
   fprintf(fp, "plot [-1:%lf][0:%lf]\\\n", Pop_size*1.2, Max_steps*1.1);
   fprintf(fp, "     \"run.%d.finalagent\" using 2:17 title \"N\" ", Run_num);
   fprintf(fp,       "w points pt 7 ps 2 lc 1\n");
   fprintf(fp, "unset xlabel\n");
   fprintf(fp, "unset ylabel\n"); 
   fprintf(fp, "unset title\n");
   fprintf(fp, "unset size\n");
   fprintf(fp, "\n");

   // NB; 2020.06.29
   // plot all agents Response prob values
   fprintf(fp, "set term post eps color\n");
   fprintf(fp, "set size ratio 0.5\n");
   fprintf(fp, "set output \"run.%d.finalagent.response_prob.eps\"\n", Run_num);
   fprintf(fp, "set xtics\n");
   fprintf(fp, "set ytics\n");
   fprintf(fp, "set xlabel \"Agent\"\n");
   fprintf(fp, "set ylabel \"Response prob Value\"\n");
   fprintf(fp, "set title \"Agent Response prob Values\"\n");
   fprintf(fp, "plot [-1:%lf][0:1]\\\n", Pop_size*1.1);
   fprintf(fp, "     \"run.%d.finalagent\" using 2:21 title \"N\" ", Run_num);
   fprintf(fp,       "w points pt 7 ps 2 lc 1\n");
   fprintf(fp, "unset xlabel\n");
   fprintf(fp, "unset ylabel\n"); 
   fprintf(fp, "unset title\n");
   fprintf(fp, "unset size\n");
   fprintf(fp, "\n");

   // NB; 2020.06.29
   // plot all agents Spontaneous response prob values
   fprintf(fp, "set term post eps color\n");
   fprintf(fp, "set size ratio 0.5\n");
   fprintf(fp, "set output \"run.%d.finalagent.spontaneous_response_prob.eps\"\n", Run_num);
   fprintf(fp, "set xtics\n");
   fprintf(fp, "set ytics\n");
   fprintf(fp, "set xlabel \"Agent\"\n");
   fprintf(fp, "set ylabel \"Spontaneous Value\"\n");
   fprintf(fp, "set title \"Agent Spontaneous Values\"\n");
   fprintf(fp, "plot [-1:%lf][0:1]\\\n", Pop_size*1.1);
   fprintf(fp, "     \"run.%d.finalagent\" using 2:23 title \"N\" ", Run_num);
   fprintf(fp,       "w points pt 7 ps 2 lc 1\n");
   fprintf(fp, "unset xlabel\n");
   fprintf(fp, "unset ylabel\n"); 
   fprintf(fp, "unset title\n");
   fprintf(fp, "unset size\n");
   fprintf(fp, "\n");

#ifdef DEBUG
printf("---end gnu_finalagent()---\n");
#endif
   }  /* gnu_finalagent */


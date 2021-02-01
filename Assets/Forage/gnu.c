/* gnu.c
   19.03.01.AW  Created.
                Contains routines for printing a gnuplot file.

   Routines:
*/

#include <stdio.h>
#include "types.h"
#include "extern.h"
#include "gnu.h"

/********** fprint_gnu **********/
/* paramters:   
   called by:   run_output(), output.c
   actions:
*/
void fprint_gnu(FILE *fp)
   {
   fprintf(fp, "set term post eps color\n");

   plot_stepdistance(fp);
   plot_stepnest(fp);
   plot_agent_stepdistance(fp);
   plot_finalavgmemory(fp);
   /* must call foodlocations after finalavgmemory if removing
      colorbox (heatmap color bar) from foodlocations but keep for
      finalavgmemory */
   plot_foodlocations(fp);

   }  /* fprint_gnu */

/********** plot_agent_stepdistance **********/
/* paramters:
   called by:   fprint_gnu(), gnu.c
   actions:	plot separate stepdistance plots for each agent
*/
void plot_agent_stepdistance(FILE *fp)
   {
   int i;

   fprintf(fp, "\n# plot data for individual agents\n");
   fprintf(fp, "set xlabel \"Cycle\"\n");
   fprintf(fp, "set ylabel \"Distance travelled\"\n");
   for (i=0; i<Pop_size; i++)
      {
      fprintf(fp, "set output \"run.%d.agent.%d.stepdistance.eps\"\n", 
		Run_num, i);
      fprintf(fp, "plot [][0:%d]", Max_sim_time+1);
      fprintf(fp, " \"run.%d.stepdistance\" using 1:%d", Run_num, i*3+4);
      fprintf(fp, " title \"ag%d\" w points\n", i);
      fprintf(fp, "#\n");
      }
   fprintf(fp, "unset xlabel\n");
   fprintf(fp, "unset ylabel\n");

   }  /* plot_agent_stepdistance */

/********** plot_stepdistance **********/
/* paramters:
   called by:   fprint_gnu(), gnu.c
   actions:	plot one stepdistance plot with all agents' data
*/
void plot_stepdistance(FILE *fp)
   {
   int i;

   fprintf(fp, "\n# plot stepdistance data\n");
   fprintf(fp, "set output \"run.%d.stepdistance.eps\"\n", Run_num);
   fprintf(fp, "set xlabel \"Cycle\"\n");
   fprintf(fp, "set ylabel \"Distance travelled\"\n");
   fprintf(fp, "plot [][0:]\\\n");
   for (i=0; i<Pop_size-1; i++)
      {
      fprintf(fp, "   \"run.%d.stepdistance\" using 1:%d", Run_num, i*3+4);
      fprintf(fp, " title \"ag%d\" w line lt 1 lc %d,\\\n", i, i);
      }
   fprintf(fp, "   \"run.%d.stepdistance\" using 1:%d", 
		Run_num, (Pop_size-1)*3+4);
   fprintf(fp, " title \"ag%d\" w line lt 1 lc %d\n", 
		Pop_size-1, Pop_size-1);
   fprintf(fp, "unset xlabel\n");
   fprintf(fp, "unset ylabel\n");

   }  /* plot_stepdistance */

/********** plot_stepnest **********/
/* paramters:   
   called by:   fprint_gnu(), gnu.c
   actions:     plot one stepnest plot
*/
void plot_stepnest(FILE *fp)
   {
   int i;
   
   fprintf(fp, "\n# plot stepnest data\n");
   fprintf(fp, "set output \"run.%d.food_in.stepnest.eps\"\n", Run_num);
   fprintf(fp, "set xlabel \"Cycle\"\n");
   fprintf(fp, "set ylabel \"Food found\"\n");
   fprintf(fp, "plot [][]\\\n");
   fprintf(fp, "   \"run.%d.stepnest\" using 1:3 w line\n", Run_num);
   fprintf(fp, "unset xlabel\n");
   fprintf(fp, "unset ylabel\n");

   fprintf(fp, "\n# plot stepnest data\n");
   fprintf(fp, "set output \"run.%d.num_actors.stepnest.eps\"\n", Run_num);
   fprintf(fp, "set xlabel \"Cycle\"\n");
   fprintf(fp, "set ylabel \"Number of actors\"\n");
   fprintf(fp, "plot [][]\\\n");
   fprintf(fp, "   \"run.%d.stepnest\" using 1:5 w line\n", Run_num);
   fprintf(fp, "unset xlabel\n");
   fprintf(fp, "unset ylabel\n");

   }  /* plot_stepnest */

/********** plot_foodlocations **********/
/* paramters:
   called by:   fprint_gnu(), gnu.c
   actions:	Plot food locations.
*/
void plot_foodlocations(FILE *fp)
   {
   fprintf(fp, "\n# plot foodlocations\n");
   fprintf(fp, "set output \"run.%d.foodlocations.eps\"\n", Run_num);
   fprintf(fp, "set size ratio -1\n");
   fprintf(fp, "set title \"run.%d: Food locations\"\n",
                Run_num);
   fprintf(fp, "unset key\n");
   fprintf(fp, "set tic scale 0\n");
   fprintf(fp, "set palette defined (0 \"#E0E0E0\", 1 \"blue\" )\n");
   fprintf(fp, "set cbrange [0.0:1.0]\n");
   fprintf(fp, "unset cblabel\n");
   fprintf(fp, "unset cbtics\n");
   fprintf(fp, "unset colorbox\n");
   fprintf(fp, "set xrange [-1:%d]\n", Envr.width);
   fprintf(fp, "set yrange [-1:%d] reverse\n", Envr.height);
   fprintf(fp, "set view map\n");
   fprintf(fp, "splot \"run.%d.foodlocations\" matrix with image\n", Run_num);

   }  /* plot_foodlocations */

/********** plot_finalavgmemory **********/
/* paramters:   
   called by:   fprint_gnu(), gnu.c
   actions:
*/
void plot_finalavgmemory(FILE *fp)
   {
   fprintf(fp, "\n# plot finalavgmemory heatmap\n");
   fprintf(fp, "set output \"run.%d.finalavgmemory.eps\"\n", Run_num);
   fprintf(fp, "set size ratio -1\n");
   fprintf(fp, "set title \"run.%d: Memory map averaged over all agents\"\n",
		Run_num);
   fprintf(fp, "unset key\n");
   fprintf(fp, "set tic scale 0\n");
   fprintf(fp, "set palette defined (0 \"#FF0000\", 1 \"#FFFF66\", 2 \"#00CC00\" )\n");
   fprintf(fp, "set cbrange [0.0:2.0]\n");
   fprintf(fp, "set cblabel \"Score\"\n");
   fprintf(fp, "set xrange [-1:%d]\n", Envr.width);
   fprintf(fp, "set yrange [-1:%d] reverse\n", Envr.height);
   fprintf(fp, "set view map\n");
   fprintf(fp, "splot \"run.%d.finalavgmemory\" matrix with image\n", Run_num);
   fprintf(fp, "unset cblabel\n");

   }  /* plot_finalavgmemory */

/********** fprint_agentstepmemory_gnu **********/
/* paramters:	
   called by:   run_output(), output.c
   actions:	Print memory of each agent at end of each step.
		Prints each memory into a separate file.
		Not called by fprint_gnu.
		Called when Print_agent_memory flag is turned on.
*/
void fprint_agentstepmemory_gnu()
   {
   FILE *fp;
   int i, t;
   char filename[100];

   sprintf(filename, "%s/run.%d/run.%d.agentstepmemory.gnu",
		Output_path, Run_num, Run_num);
   fp = fopen(filename, "w");

   fprintf(fp, "set term png\n");
   fprintf(fp, "set size ratio -1\n");
   fprintf(fp, "unset key\n");
   fprintf(fp, "set tic scale 0\n");
   fprintf(fp, "set palette defined (0 \"#FF0000\", 1 \"#FFFF66\", 2 \"#00CC00\" )\n");
   fprintf(fp, "set cbrange [0.0:2.0]\n");
   fprintf(fp, "set cblabel \"Score\"\n");
   fprintf(fp, "set xrange [-1:%d]\n", Envr.width);
   fprintf(fp, "set yrange [-1:%d] reverse\n", Envr.height);
   fprintf(fp, "set view map\n\n");

   for (i=0; i<Pop_size; i++)
      {
      // 19.03.25.AW for (t=0; t<Max_sim_time; t++)
      for (t=0; t<Max_steps; t++)
         {
         fprintf(fp, "#\n");
         fprintf(fp, "# plot agent %d step %d memory\n", i, t);
         fprintf(fp, "set output \"run.%d.agent%d.step%d.memory.png\"\n",
		Run_num, i, t);
         fprintf(fp, "set title \"run.%d: agent %d step %d memory map\"\n",
                Run_num, i, t);
         fprintf(fp, "splot \"run.%d.agent%d.step%d.memory\" matrix with image\n",
		Run_num, i, t);
         }
      }
   fclose(fp);
   }  /* fprint_agentstepmemory_gnu */

/********** fprint_agentfinalmemory_gnu **********/
/* paramters:   
   called by:   run_output(), output.c
   actions:     Print final memory of each agent at final step/cycle.
                Prints each memory into a separate file.
                Not called by fprint_gnu.
                Called when Print_agent_final_memory flag is turned on.
*/
void fprint_agentfinalmemory_gnu()
   {
   FILE *fp;
   int i;
   char filename[100];

   sprintf(filename, "%s/run.%d/run.%d.agentfinalmemory.gnu",
                Output_path, Run_num, Run_num);
   fp = fopen(filename, "w");

   fprintf(fp, "set term post eps color\n");
   fprintf(fp, "set size ratio -1\n");
   fprintf(fp, "unset key\n");
   fprintf(fp, "set tic scale 0\n");
   fprintf(fp, "set palette defined (0 \"#FF0000\", 1 \"#FFFF66\", 2 \"#00CC00\" )\n");
   fprintf(fp, "set cbrange [0.0:2.0]\n");
   fprintf(fp, "set cblabel \"Score\"\n");
   fprintf(fp, "set xrange [-1:%d]\n", Envr.width);
   fprintf(fp, "set yrange [-1:%d] reverse\n", Envr.height);
   fprintf(fp, "set view map\n\n");

   for (i=0; i<Pop_size; i++)
      {
      fprintf(fp, "#\n");
      fprintf(fp, "# plot agent %d step %d memory\n", i, Max_steps);
      fprintf(fp, "set output \"run.%d.agent%d.finalmemory.eps\"\n",
                Run_num, i);
      fprintf(fp, "set title \"run.%d: agent %d step %d memory map\"\n",
                Run_num, i, Max_steps);
      fprintf(fp, "splot \"run.%d.agent%d.finalmemory\" matrix with image\n",
                Run_num, i);
      }

   fprintf(fp, "unset size\n");
   fprintf(fp, "unset xrange\n");
   fprintf(fp, "unset yrange\n");
   fprintf(fp, "unset view\n");

   fclose(fp);
   }  /* fprint_agentfinalmemory_gnu */

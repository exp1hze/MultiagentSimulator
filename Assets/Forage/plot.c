/* plot.c
   14.10.29.AW	Print gnuplot file to plot agent task choices per timestep.
   14.11.10.AW	Revised for variable task simulation.
*/

#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>

#define ERROR -1

int main(int argc, char **argv)
   {
   FILE *fp;
   int run_num;
   int pop_size;
   int num_tasks;
   int i;
   int j;
   int alen;
   char **name;

   if (argc < 4)
      {
      printf(" Usage: %s <run number> <pop size> <num tasks>\n",
		argv[0]);
      return ERROR;
      }  /* if */

   sscanf(argv[1], "%d", &run_num);
   sscanf(argv[2], "%d", &pop_size);
   sscanf(argv[3], "%d", &num_tasks);
   printf(" run number: %s %d\n", argv[1], run_num);
   printf(" pop size: %s %d\n", argv[2], pop_size);
   printf(" num tasks: %s %d\n", argv[3], num_tasks);

   /********** print batch file **********/
   fp = fopen("batchfile", "w");
   fprintf(fp, "gnuplot *.gnu\n");
   fprintf(fp, "open run.%d.*.eps\n", run_num);
   fclose(fp);

   /********** plot nest statistics per timestep **********/
   /* percent done for each task in each timestep */
//
   fp = fopen("nest.gnu", "w");
   fprintf(fp, "set term post eps color\n");
   fprintf(fp, "set xlabel \"Timestep\"\n");
   fprintf(fp, "set ylabel \"Percent done\"\n");

   fprintf(fp, "\n");
   fprintf(fp, "set output \"run.%d.nest.eps\"\n", run_num);

   fprintf(fp, "plot [][-0.1:2.1]\\\n");
//   fprintf(fp, "   1.0,\\\n");
//   fprintf(fp, "   0.0,\\\n");

   for (i=0; i<num_tasks-1; i++)
      {
      fprintf(fp, "   \"../Output/run.%d/run.%d.stepnest\"",
           run_num, run_num);
      fprintf(fp, " using 2:%d title \"Task %d\" w line lw 3,\\\n",
              4 * i + 10, i);
      }
   fprintf(fp, "   \"../Output/run.%d/run.%d.stepnest\"",
           run_num, run_num);
   fprintf(fp, " using 2:%d title \"Task %d\" w line lw 3\n",
           4 * (num_tasks-1) + 10, num_tasks-1);

   fprintf(fp, "set nolabel\n");
   fprintf(fp, "set notitle\n");
   fclose(fp);

   /********** plot number of agents per task per timestep **********/
//
   fp = fopen("actors.gnu", "w");
   fprintf(fp, "set term post eps color\n");
   fprintf(fp, "set xlabel \"Timestep\"\n");

   for (i=0; i<num_tasks; i++)
      {
      fprintf(fp, "\n");
      fprintf(fp, "set output \"run.%d.a.task%d.eps\"\n", run_num, i);
      fprintf(fp, "plot [][-1:%d]\\\n", pop_size+1);
      fprintf(fp, "   \"../Output/run.%d/run.%d.steptask\"",
           run_num, run_num);
      fprintf(fp, " using 2:%d title \"Num agents on task %d\" w line lw 3\n", 
		8 + 2*pop_size + 2 + i*3, i);
      }

   fprintf(fp, "set nolabel\n");
   fprintf(fp, "set notitle\n");
   fclose(fp);

   /********** plot what tasks each agent is doing in each timestep **********/
//
   fp = fopen("agent.gnu", "w");
   fprintf(fp, "set term post eps color\n");
   fprintf(fp, "set xlabel \"Timestep\"\n");
   fprintf(fp, "set ylabel \"Task 0-%d per agent\"\n", num_tasks-1 );

   fprintf(fp, "\n");
   fprintf(fp, "set output \"run.%d.agent.eps\"\n", run_num);
   fprintf(fp, "plot [][-1:%d]\\\n", (num_tasks+1)*pop_size+1 );
   for (i=0; i<pop_size-1; i++)
      {
      for (j=0; j<num_tasks; j++)
         {
         fprintf(fp, "   \"../Output/run.%d/run.%d.steptask\"",
              run_num, run_num);
         fprintf(fp, " using 2:(%d + $%d)", i * (num_tasks+1), 9+i*2 );
         fprintf(fp, " title \"\" w points,\\\n");
         }
      }  /* for i */
   for (j=0; j<num_tasks-1; j++)
      {
      fprintf(fp, "   \"../Output/run.%d/run.%d.steptask\"",
           run_num, run_num);
      fprintf(fp, " using 2:(%d + $%d)", (pop_size-1) * (num_tasks+1), 9+i*2 );
      fprintf(fp, " title \"\" w points,\\\n");
      }  /* for j */
   fprintf(fp, "   \"../Output/run.%d/run.%d.steptask\"",
           run_num, run_num);
   fprintf(fp, " using 2:(%d + $%d)", (pop_size-1) * (num_tasks+1), 9+i*2 );
   fprintf(fp, " title \"\" w points");
   fprintf(fp, "\n");

   fprintf(fp, "set nolabel\n");
   fprintf(fp, "set notitle\n");
   fclose(fp);

   /********** plot agent thresholds **********/
//
   fp = fopen("thresholds.gnu", "w");
   fprintf(fp, "set term post eps color\n");
   fprintf(fp, "set xlabel \"Timestep\"\n");
   fprintf(fp, "set ylabel \"Threshold\"\n");

   for (i=0; i<pop_size; i++)
      {
      fprintf(fp, "\n");
      fprintf(fp, "set output \"run.%d.agent%d.eps\"\n", run_num, i);
      fprintf(fp, "set title \"Agent %d thresholds\"\n", i);
      fprintf(fp, "plot [][-0.1:1.2]\\\n");

      alen = 2 * num_tasks + 2;

      for (j=0; j<num_tasks-1; j++)
         {
         fprintf(fp, "   \"../Output/run.%d/run.%d.stepthresh\"",
              run_num, run_num);
         fprintf(fp, " using 2:%d", 10 + (i * alen) + 2*j);
         fprintf(fp, " title \"Task %d\" w line lw 3,\\\n", j);
         }
      fprintf(fp, "   \"../Output/run.%d/run.%d.stepthresh\"",
           run_num, run_num);
      fprintf(fp, " using 2:%d", 
           10 + (i * alen) + 2*(num_tasks-1));
      fprintf(fp, " title \"Task %d\" w line lw 3\n", num_tasks-1);
      }

   fprintf(fp, "set nolabel\n");
   fprintf(fp, "set notitle\n");
   fclose(fp);

   /********** plot percent agents working on each task each day **********/
//
   fp = fopen("daytask.gnu", "w");
   fprintf(fp, "set term post eps color\n");
   fprintf(fp, "set title \"Percent time spent on each task each day\"\n");
   fprintf(fp, "set xlabel \"Day\"\n");
   fprintf(fp, "set ylabel \"Percent time\"\n");

   for (i=0; i<pop_size; i++)
      {
      fprintf(fp, "\n");
      fprintf(fp, "set output \"run.%d.agent%dtasks.eps\"\n", run_num, i);
      fprintf(fp, 
	"set title \"Agent %d: Percent time spent on each task per day\"\n", i);
      fprintf(fp, "plot [][-0.1:1.2]\\\n");

      alen = 3*num_tasks + 2;

      for (j=0; j<num_tasks-1; j++)
         {
         fprintf(fp, "   \"../Output/run.%d/run.%d.dayagenttask\"",
              run_num, run_num);
         fprintf(fp, " using 2:%d", 7 + i*alen + 3*j);
         fprintf(fp, " title \"Pct time Task %d\" w linesp lw 3,\\\n", j);
         }

      fprintf(fp, "   \"../Output/run.%d/run.%d.dayagenttask\"",
              run_num, run_num);
      fprintf(fp, " using 2:%d", 7 + i*alen + 3 * (num_tasks-1) );
      fprintf(fp, " title \"Pct time Task %d\" w linesp lw 3\n", num_tasks-1);
      }

   fprintf(fp, "set nolabel\n");
   fprintf(fp, "set notitle\n");
   fclose(fp);

   /********** plot final thresholds of agents **********/
   fp = fopen("finalthresh.gnu", "w");
   fprintf(fp, "set term post eps color\n");
   fprintf(fp, "set title \"Final agent thresholds\"\n");
   fprintf(fp, "set xlabel \"Agent (w/ task spread)\"\n");
   fprintf(fp, "set ylabel \"Final threshold\"\n");

   fprintf(fp, "\n");
   fprintf(fp, "set output \"run.%d.finalthresh.eps\"\n", run_num);
   fprintf(fp, "plot [-1:][-0.1:1.3]\\\n");

   for (j=0; j<num_tasks-1; j++)
      {
      fprintf(fp, "   \"../Output/run.%d/run.%d.finalthresh\"",
          run_num, run_num);
      fprintf(fp, 
          " using ($2*(%d+3)+%d):%d title \"Task %d threshold\" w point,\\\n",
          num_tasks, j, 5 + 3*j, j);
      }

   fprintf(fp, "   \"../Output/run.%d/run.%d.finalthresh\"",
           run_num, run_num);
   fprintf(fp, " using ($2*(%d+3)+%d):%d title \"Task %d threshold\" w point\n",
           num_tasks, j, 5 + 3*(num_tasks-1), num_tasks-1);

   fprintf(fp, "set nolabel\n");
   fprintf(fp, "set notitle\n");
   fclose(fp);

   /********** plot percent achievement of each task each day **********/
//
   fp = fopen("daymaxpct.gnu", "w");
   fprintf(fp, "set term post eps color\n");
   fprintf(fp, "set title \"Percent time spent on each task each day\"\n");
   fprintf(fp, "set xlabel \"Day\"\n");
   fprintf(fp, "set ylabel \"Percent time\"\n");

   for (i=0; i<pop_size; i++)
      {
      fprintf(fp, "\n");
      fprintf(fp, "set output \"run.%d.daymaxpct.eps\"\n", run_num);
      fprintf(fp,
        "set title \"Percent task achievement per day\"\n");
      fprintf(fp, "plot\\\n");

      // don't print task 0
      for (j=1; j<num_tasks-1; j++)
         {
         fprintf(fp, "   \"../Output/run.%d/run.%d.daymaxpct\"",
              run_num, run_num);
         fprintf(fp, " using 2:%d", 4 + 2*j);
         fprintf(fp, " title \"Task %d\" w linesp lc %d lw 3,\\\n", j, j+1);
         }

      fprintf(fp, "   \"../Output/run.%d/run.%d.daymaxpct\"",
              run_num, run_num);
      fprintf(fp, " using 2:%d", 4 + 2 * (num_tasks-1) );
      fprintf(fp, " title \"Pct time Task %d\" w linesp lc %d lw 3\n",
              num_tasks-1, num_tasks);
      }

   fprintf(fp, "set nolabel\n");
   fprintf(fp, "set notitle\n");
   fclose(fp);

   }  /* main */

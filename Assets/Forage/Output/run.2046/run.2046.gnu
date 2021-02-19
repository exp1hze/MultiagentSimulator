set term post eps color

# plot stepdistance data
set output "run.2046.stepdistance.eps"
set xlabel "Cycle"
set ylabel "Distance travelled"
plot [][0:]\
   "run.2046.stepdistance" using 1:4 title "ag0" w line lt 1 lc 0,\
   "run.2046.stepdistance" using 1:7 title "ag1" w line lt 1 lc 1,\
   "run.2046.stepdistance" using 1:10 title "ag2" w line lt 1 lc 2,\
   "run.2046.stepdistance" using 1:13 title "ag3" w line lt 1 lc 3,\
   "run.2046.stepdistance" using 1:16 title "ag4" w line lt 1 lc 4,\
   "run.2046.stepdistance" using 1:19 title "ag5" w line lt 1 lc 5,\
   "run.2046.stepdistance" using 1:22 title "ag6" w line lt 1 lc 6,\
   "run.2046.stepdistance" using 1:25 title "ag7" w line lt 1 lc 7,\
   "run.2046.stepdistance" using 1:28 title "ag8" w line lt 1 lc 8,\
   "run.2046.stepdistance" using 1:31 title "ag9" w line lt 1 lc 9,\
   "run.2046.stepdistance" using 1:34 title "ag10" w line lt 1 lc 10,\
   "run.2046.stepdistance" using 1:37 title "ag11" w line lt 1 lc 11,\
   "run.2046.stepdistance" using 1:40 title "ag12" w line lt 1 lc 12,\
   "run.2046.stepdistance" using 1:43 title "ag13" w line lt 1 lc 13,\
   "run.2046.stepdistance" using 1:46 title "ag14" w line lt 1 lc 14,\
   "run.2046.stepdistance" using 1:49 title "ag15" w line lt 1 lc 15,\
   "run.2046.stepdistance" using 1:52 title "ag16" w line lt 1 lc 16,\
   "run.2046.stepdistance" using 1:55 title "ag17" w line lt 1 lc 17,\
   "run.2046.stepdistance" using 1:58 title "ag18" w line lt 1 lc 18,\
   "run.2046.stepdistance" using 1:61 title "ag19" w line lt 1 lc 19
unset xlabel
unset ylabel

# plot stepnest data
set output "run.2046.food_in.stepnest.eps"
set xlabel "Cycle"
set ylabel "Food found"
plot [][]\
   "run.2046.stepnest" using 1:3 w line
unset xlabel
unset ylabel

# plot stepnest data
set output "run.2046.num_actors.stepnest.eps"
set xlabel "Cycle"
set ylabel "Number of actors"
plot [][]\
   "run.2046.stepnest" using 1:5 w line
unset xlabel
unset ylabel

# plot data for individual agents
set xlabel "Cycle"
set ylabel "Distance travelled"
set output "run.2046.agent.0.stepdistance.eps"
plot [][0:1001] "run.2046.stepdistance" using 1:4 title "ag0" w points
#
set output "run.2046.agent.1.stepdistance.eps"
plot [][0:1001] "run.2046.stepdistance" using 1:7 title "ag1" w points
#
set output "run.2046.agent.2.stepdistance.eps"
plot [][0:1001] "run.2046.stepdistance" using 1:10 title "ag2" w points
#
set output "run.2046.agent.3.stepdistance.eps"
plot [][0:1001] "run.2046.stepdistance" using 1:13 title "ag3" w points
#
set output "run.2046.agent.4.stepdistance.eps"
plot [][0:1001] "run.2046.stepdistance" using 1:16 title "ag4" w points
#
set output "run.2046.agent.5.stepdistance.eps"
plot [][0:1001] "run.2046.stepdistance" using 1:19 title "ag5" w points
#
set output "run.2046.agent.6.stepdistance.eps"
plot [][0:1001] "run.2046.stepdistance" using 1:22 title "ag6" w points
#
set output "run.2046.agent.7.stepdistance.eps"
plot [][0:1001] "run.2046.stepdistance" using 1:25 title "ag7" w points
#
set output "run.2046.agent.8.stepdistance.eps"
plot [][0:1001] "run.2046.stepdistance" using 1:28 title "ag8" w points
#
set output "run.2046.agent.9.stepdistance.eps"
plot [][0:1001] "run.2046.stepdistance" using 1:31 title "ag9" w points
#
set output "run.2046.agent.10.stepdistance.eps"
plot [][0:1001] "run.2046.stepdistance" using 1:34 title "ag10" w points
#
set output "run.2046.agent.11.stepdistance.eps"
plot [][0:1001] "run.2046.stepdistance" using 1:37 title "ag11" w points
#
set output "run.2046.agent.12.stepdistance.eps"
plot [][0:1001] "run.2046.stepdistance" using 1:40 title "ag12" w points
#
set output "run.2046.agent.13.stepdistance.eps"
plot [][0:1001] "run.2046.stepdistance" using 1:43 title "ag13" w points
#
set output "run.2046.agent.14.stepdistance.eps"
plot [][0:1001] "run.2046.stepdistance" using 1:46 title "ag14" w points
#
set output "run.2046.agent.15.stepdistance.eps"
plot [][0:1001] "run.2046.stepdistance" using 1:49 title "ag15" w points
#
set output "run.2046.agent.16.stepdistance.eps"
plot [][0:1001] "run.2046.stepdistance" using 1:52 title "ag16" w points
#
set output "run.2046.agent.17.stepdistance.eps"
plot [][0:1001] "run.2046.stepdistance" using 1:55 title "ag17" w points
#
set output "run.2046.agent.18.stepdistance.eps"
plot [][0:1001] "run.2046.stepdistance" using 1:58 title "ag18" w points
#
set output "run.2046.agent.19.stepdistance.eps"
plot [][0:1001] "run.2046.stepdistance" using 1:61 title "ag19" w points
#
unset xlabel
unset ylabel

# plot finalavgmemory heatmap
set output "run.2046.finalavgmemory.eps"
set size ratio -1
set title "run.2046: Memory map averaged over all agents"
unset key
set tic scale 0
set palette defined (0 "#FF0000", 1 "#FFFF66", 2 "#00CC00" )
set cbrange [0.0:2.0]
set cblabel "Score"
set xrange [-1:100]
set yrange [-1:100] reverse
set view map
splot "run.2046.finalavgmemory" matrix with image
unset cblabel

# plot foodlocations
set output "run.2046.foodlocations.eps"
set size ratio -1
set title "run.2046: Food locations"
unset key
set tic scale 0
set palette defined (0 "#E0E0E0", 1 "blue" )
set cbrange [0.0:1.0]
unset cblabel
unset cbtics
unset colorbox
set xrange [-1:100]
set yrange [-1:100] reverse
set view map
splot "run.2046.foodlocations" matrix with image

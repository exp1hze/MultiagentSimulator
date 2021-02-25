set term post eps 20
set xlabel "Response probability"

set output "all-drop_level.eps"
set title "Drop level"
set ylabel "Drop level"
plot "all-plot_results.txt" using 1:23 w line

set output "all-pct_need_met.eps"
set title "Percent need met (need = 20)"
set ylabel "Percent need met (20 foragers)"
plot "all-plot_results.txt" using 1:12 w line,\
     "all-plot_results.txt" using 1:12:13 title "" w yerr

set output "all-ttrecover.eps"
set title "Time to recover"
set ylabel "Time to recover"
plot "all-plot_results.txt" using 1:17 w line

set output "all-drop_amount.eps"
set title "Drop amount"
set ylabel "Drop amount"
plot "all-plot_results.txt" using 1:15 w line

set output "all-total_food.eps"
set title "Total food collected"
set ylabel "Total food collected"
plot "all-plot_results.txt" using 1:6 w line,\
     "all-plot_results.txt" using 1:6:7 title "" w yerr

set output "all-food_div_ttrecover.eps"
set title "Total food/Time to recover"
set ylabel "Total food/Time to recover"
plot "all-plot_results.txt" using 1:21 w line

set output "all-food_div_drop.eps"
set title "Total food/Drop"
set ylabel "Total food/Drop"
plot "all-plot_results.txt" using 1:19 w line

set term post eps color

set output "all-indv-drop-before.eps"
set title "Average food before drop and 95% CI"
set ylabel "Average food before drop"
plot [][0:14]\
   "all-plot_drop_results.txt" using 1:4 title "t=124" w line lt 1 lc 1,\
   "all-plot_drop_results.txt" using 1:13 title "t=249" w line lt 2 lc 2,\
   "all-plot_drop_results.txt" using 1:22 title "t=374" w line lt 3 lc 3,\
   "all-plot_drop_results.txt" using 1:31 title "t=499" w line lt 4 lc 4,\
   "all-plot_drop_results.txt" using 1:4:5 title "" w yerr lt 1 lc 1,\
   "all-plot_drop_results.txt" using 1:13:14 title "" w yerr lt 1 lc 2,\
   "all-plot_drop_results.txt" using 1:22:23 title "" w yerr lt 1 lc 3,\
   "all-plot_drop_results.txt" using 1:31:32 title "" w yerr lt 1 lc 4

set output "all-indv-drop-after.eps"
set title "Average food after drop and 95% CI"
set ylabel "Average food after drop"
plot [][0:14]\
   "all-plot_drop_results.txt" using 1:7 title "t=124" w line lt 1 lc 1,\
   "all-plot_drop_results.txt" using 1:16 title "t=249" w line lt 2 lc 2,\
   "all-plot_drop_results.txt" using 1:25 title "t=374" w line lt 3 lc 3,\
   "all-plot_drop_results.txt" using 1:34 title "t=499" w line lt 4 lc 4,\
   "all-plot_drop_results.txt" using 1:7:8 title "" w yerr lt 1 lc 1,\
   "all-plot_drop_results.txt" using 1:16:17 title "" w yerr lt 1 lc 2,\
   "all-plot_drop_results.txt" using 1:25:26 title "" w yerr lt 1 lc 3,\
   "all-plot_drop_results.txt" using 1:34:35 title "" w yerr lt 1 lc 4

set output "all-indv-drop-amount.eps"
set title "Average food amount drop"
set ylabel "Average food amount drop"
plot [][0:14]\
   "all-plot_drop_results.txt" using 1:10 title "t=124" w line,\
   "all-plot_drop_results.txt" using 1:19 title "t=249" w line,\
   "all-plot_drop_results.txt" using 1:28 title "t=374" w line,\
   "all-plot_drop_results.txt" using 1:37 title "t=499" w line

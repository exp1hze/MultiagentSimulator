set term post eps color
set size ratio -1
unset key
set tic scale 0
set palette defined (0 "#FF0000", 1 "#FFFF66", 2 "#00CC00" )
set cbrange [0.0:2.0]
set cblabel "Score"
set xrange [-1:100]
set yrange [-1:100] reverse
set view map

#
# plot agent 0 step 2 memory
set output "run.2055.agent0.finalmemory.eps"
set title "run.2055: agent 0 step 2 memory map"
splot "run.2055.agent0.finalmemory" matrix with image
#
# plot agent 1 step 2 memory
set output "run.2055.agent1.finalmemory.eps"
set title "run.2055: agent 1 step 2 memory map"
splot "run.2055.agent1.finalmemory" matrix with image
#
# plot agent 2 step 2 memory
set output "run.2055.agent2.finalmemory.eps"
set title "run.2055: agent 2 step 2 memory map"
splot "run.2055.agent2.finalmemory" matrix with image
#
# plot agent 3 step 2 memory
set output "run.2055.agent3.finalmemory.eps"
set title "run.2055: agent 3 step 2 memory map"
splot "run.2055.agent3.finalmemory" matrix with image
#
# plot agent 4 step 2 memory
set output "run.2055.agent4.finalmemory.eps"
set title "run.2055: agent 4 step 2 memory map"
splot "run.2055.agent4.finalmemory" matrix with image
#
# plot agent 5 step 2 memory
set output "run.2055.agent5.finalmemory.eps"
set title "run.2055: agent 5 step 2 memory map"
splot "run.2055.agent5.finalmemory" matrix with image
#
# plot agent 6 step 2 memory
set output "run.2055.agent6.finalmemory.eps"
set title "run.2055: agent 6 step 2 memory map"
splot "run.2055.agent6.finalmemory" matrix with image
#
# plot agent 7 step 2 memory
set output "run.2055.agent7.finalmemory.eps"
set title "run.2055: agent 7 step 2 memory map"
splot "run.2055.agent7.finalmemory" matrix with image
#
# plot agent 8 step 2 memory
set output "run.2055.agent8.finalmemory.eps"
set title "run.2055: agent 8 step 2 memory map"
splot "run.2055.agent8.finalmemory" matrix with image
#
# plot agent 9 step 2 memory
set output "run.2055.agent9.finalmemory.eps"
set title "run.2055: agent 9 step 2 memory map"
splot "run.2055.agent9.finalmemory" matrix with image
#
# plot agent 10 step 2 memory
set output "run.2055.agent10.finalmemory.eps"
set title "run.2055: agent 10 step 2 memory map"
splot "run.2055.agent10.finalmemory" matrix with image
#
# plot agent 11 step 2 memory
set output "run.2055.agent11.finalmemory.eps"
set title "run.2055: agent 11 step 2 memory map"
splot "run.2055.agent11.finalmemory" matrix with image
#
# plot agent 12 step 2 memory
set output "run.2055.agent12.finalmemory.eps"
set title "run.2055: agent 12 step 2 memory map"
splot "run.2055.agent12.finalmemory" matrix with image
#
# plot agent 13 step 2 memory
set output "run.2055.agent13.finalmemory.eps"
set title "run.2055: agent 13 step 2 memory map"
splot "run.2055.agent13.finalmemory" matrix with image
#
# plot agent 14 step 2 memory
set output "run.2055.agent14.finalmemory.eps"
set title "run.2055: agent 14 step 2 memory map"
splot "run.2055.agent14.finalmemory" matrix with image
#
# plot agent 15 step 2 memory
set output "run.2055.agent15.finalmemory.eps"
set title "run.2055: agent 15 step 2 memory map"
splot "run.2055.agent15.finalmemory" matrix with image
#
# plot agent 16 step 2 memory
set output "run.2055.agent16.finalmemory.eps"
set title "run.2055: agent 16 step 2 memory map"
splot "run.2055.agent16.finalmemory" matrix with image
#
# plot agent 17 step 2 memory
set output "run.2055.agent17.finalmemory.eps"
set title "run.2055: agent 17 step 2 memory map"
splot "run.2055.agent17.finalmemory" matrix with image
#
# plot agent 18 step 2 memory
set output "run.2055.agent18.finalmemory.eps"
set title "run.2055: agent 18 step 2 memory map"
splot "run.2055.agent18.finalmemory" matrix with image
#
# plot agent 19 step 2 memory
set output "run.2055.agent19.finalmemory.eps"
set title "run.2055: agent 19 step 2 memory map"
splot "run.2055.agent19.finalmemory" matrix with image
unset size
unset xrange
unset yrange
unset view

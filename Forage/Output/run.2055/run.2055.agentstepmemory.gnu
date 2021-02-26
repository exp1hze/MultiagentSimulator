set term pngcairo
set size ratio -1
unset key
set tic scale 0
set palette defined (0 "#FF0000", 1 "#FFFF66", 2 "#00CC00" )
set cbrange [0.0:2.0]
set cblabel "Score"
set xrange [-1:100]
set yrange [-1:100] reverse
set lmargin at screen 0.08
set rmargin at screen 0.85
set bmargin at screen 0.08
set tmargin at screen 0.93
set view map

#
# plot agent 0 step 0 memory
set output "run.2055.agent0.step0.memory.png"
set title "run.2055: agent 0 step 0 memory map"
splot "run.2055.agent0.step0.memory" matrix with image
#
# plot agent 0 step 1 memory
set output "run.2055.agent0.step1.memory.png"
set title "run.2055: agent 0 step 1 memory map"
splot "run.2055.agent0.step1.memory" matrix with image
#
# plot agent 1 step 0 memory
set output "run.2055.agent1.step0.memory.png"
set title "run.2055: agent 1 step 0 memory map"
splot "run.2055.agent1.step0.memory" matrix with image
#
# plot agent 1 step 1 memory
set output "run.2055.agent1.step1.memory.png"
set title "run.2055: agent 1 step 1 memory map"
splot "run.2055.agent1.step1.memory" matrix with image
#
# plot agent 2 step 0 memory
set output "run.2055.agent2.step0.memory.png"
set title "run.2055: agent 2 step 0 memory map"
splot "run.2055.agent2.step0.memory" matrix with image
#
# plot agent 2 step 1 memory
set output "run.2055.agent2.step1.memory.png"
set title "run.2055: agent 2 step 1 memory map"
splot "run.2055.agent2.step1.memory" matrix with image
#
# plot agent 3 step 0 memory
set output "run.2055.agent3.step0.memory.png"
set title "run.2055: agent 3 step 0 memory map"
splot "run.2055.agent3.step0.memory" matrix with image
#
# plot agent 3 step 1 memory
set output "run.2055.agent3.step1.memory.png"
set title "run.2055: agent 3 step 1 memory map"
splot "run.2055.agent3.step1.memory" matrix with image
#
# plot agent 4 step 0 memory
set output "run.2055.agent4.step0.memory.png"
set title "run.2055: agent 4 step 0 memory map"
splot "run.2055.agent4.step0.memory" matrix with image
#
# plot agent 4 step 1 memory
set output "run.2055.agent4.step1.memory.png"
set title "run.2055: agent 4 step 1 memory map"
splot "run.2055.agent4.step1.memory" matrix with image
#
# plot agent 5 step 0 memory
set output "run.2055.agent5.step0.memory.png"
set title "run.2055: agent 5 step 0 memory map"
splot "run.2055.agent5.step0.memory" matrix with image
#
# plot agent 5 step 1 memory
set output "run.2055.agent5.step1.memory.png"
set title "run.2055: agent 5 step 1 memory map"
splot "run.2055.agent5.step1.memory" matrix with image
#
# plot agent 6 step 0 memory
set output "run.2055.agent6.step0.memory.png"
set title "run.2055: agent 6 step 0 memory map"
splot "run.2055.agent6.step0.memory" matrix with image
#
# plot agent 6 step 1 memory
set output "run.2055.agent6.step1.memory.png"
set title "run.2055: agent 6 step 1 memory map"
splot "run.2055.agent6.step1.memory" matrix with image
#
# plot agent 7 step 0 memory
set output "run.2055.agent7.step0.memory.png"
set title "run.2055: agent 7 step 0 memory map"
splot "run.2055.agent7.step0.memory" matrix with image
#
# plot agent 7 step 1 memory
set output "run.2055.agent7.step1.memory.png"
set title "run.2055: agent 7 step 1 memory map"
splot "run.2055.agent7.step1.memory" matrix with image
#
# plot agent 8 step 0 memory
set output "run.2055.agent8.step0.memory.png"
set title "run.2055: agent 8 step 0 memory map"
splot "run.2055.agent8.step0.memory" matrix with image
#
# plot agent 8 step 1 memory
set output "run.2055.agent8.step1.memory.png"
set title "run.2055: agent 8 step 1 memory map"
splot "run.2055.agent8.step1.memory" matrix with image
#
# plot agent 9 step 0 memory
set output "run.2055.agent9.step0.memory.png"
set title "run.2055: agent 9 step 0 memory map"
splot "run.2055.agent9.step0.memory" matrix with image
#
# plot agent 9 step 1 memory
set output "run.2055.agent9.step1.memory.png"
set title "run.2055: agent 9 step 1 memory map"
splot "run.2055.agent9.step1.memory" matrix with image
#
# plot agent 10 step 0 memory
set output "run.2055.agent10.step0.memory.png"
set title "run.2055: agent 10 step 0 memory map"
splot "run.2055.agent10.step0.memory" matrix with image
#
# plot agent 10 step 1 memory
set output "run.2055.agent10.step1.memory.png"
set title "run.2055: agent 10 step 1 memory map"
splot "run.2055.agent10.step1.memory" matrix with image
#
# plot agent 11 step 0 memory
set output "run.2055.agent11.step0.memory.png"
set title "run.2055: agent 11 step 0 memory map"
splot "run.2055.agent11.step0.memory" matrix with image
#
# plot agent 11 step 1 memory
set output "run.2055.agent11.step1.memory.png"
set title "run.2055: agent 11 step 1 memory map"
splot "run.2055.agent11.step1.memory" matrix with image
#
# plot agent 12 step 0 memory
set output "run.2055.agent12.step0.memory.png"
set title "run.2055: agent 12 step 0 memory map"
splot "run.2055.agent12.step0.memory" matrix with image
#
# plot agent 12 step 1 memory
set output "run.2055.agent12.step1.memory.png"
set title "run.2055: agent 12 step 1 memory map"
splot "run.2055.agent12.step1.memory" matrix with image
#
# plot agent 13 step 0 memory
set output "run.2055.agent13.step0.memory.png"
set title "run.2055: agent 13 step 0 memory map"
splot "run.2055.agent13.step0.memory" matrix with image
#
# plot agent 13 step 1 memory
set output "run.2055.agent13.step1.memory.png"
set title "run.2055: agent 13 step 1 memory map"
splot "run.2055.agent13.step1.memory" matrix with image
#
# plot agent 14 step 0 memory
set output "run.2055.agent14.step0.memory.png"
set title "run.2055: agent 14 step 0 memory map"
splot "run.2055.agent14.step0.memory" matrix with image
#
# plot agent 14 step 1 memory
set output "run.2055.agent14.step1.memory.png"
set title "run.2055: agent 14 step 1 memory map"
splot "run.2055.agent14.step1.memory" matrix with image
#
# plot agent 15 step 0 memory
set output "run.2055.agent15.step0.memory.png"
set title "run.2055: agent 15 step 0 memory map"
splot "run.2055.agent15.step0.memory" matrix with image
#
# plot agent 15 step 1 memory
set output "run.2055.agent15.step1.memory.png"
set title "run.2055: agent 15 step 1 memory map"
splot "run.2055.agent15.step1.memory" matrix with image
#
# plot agent 16 step 0 memory
set output "run.2055.agent16.step0.memory.png"
set title "run.2055: agent 16 step 0 memory map"
splot "run.2055.agent16.step0.memory" matrix with image
#
# plot agent 16 step 1 memory
set output "run.2055.agent16.step1.memory.png"
set title "run.2055: agent 16 step 1 memory map"
splot "run.2055.agent16.step1.memory" matrix with image
#
# plot agent 17 step 0 memory
set output "run.2055.agent17.step0.memory.png"
set title "run.2055: agent 17 step 0 memory map"
splot "run.2055.agent17.step0.memory" matrix with image
#
# plot agent 17 step 1 memory
set output "run.2055.agent17.step1.memory.png"
set title "run.2055: agent 17 step 1 memory map"
splot "run.2055.agent17.step1.memory" matrix with image
#
# plot agent 18 step 0 memory
set output "run.2055.agent18.step0.memory.png"
set title "run.2055: agent 18 step 0 memory map"
splot "run.2055.agent18.step0.memory" matrix with image
#
# plot agent 18 step 1 memory
set output "run.2055.agent18.step1.memory.png"
set title "run.2055: agent 18 step 1 memory map"
splot "run.2055.agent18.step1.memory" matrix with image
#
# plot agent 19 step 0 memory
set output "run.2055.agent19.step0.memory.png"
set title "run.2055: agent 19 step 0 memory map"
splot "run.2055.agent19.step0.memory" matrix with image
#
# plot agent 19 step 1 memory
set output "run.2055.agent19.step1.memory.png"
set title "run.2055: agent 19 step 1 memory map"
splot "run.2055.agent19.step1.memory" matrix with image

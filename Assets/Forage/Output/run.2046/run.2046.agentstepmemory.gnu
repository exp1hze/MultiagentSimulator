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
set output "run.2046.agent0.step0.memory.png"
set title "run.2046: agent 0 step 0 memory map"
splot "run.2046.agent0.step0.memory" matrix with image
#
# plot agent 0 step 1 memory
set output "run.2046.agent0.step1.memory.png"
set title "run.2046: agent 0 step 1 memory map"
splot "run.2046.agent0.step1.memory" matrix with image
#
# plot agent 0 step 2 memory
set output "run.2046.agent0.step2.memory.png"
set title "run.2046: agent 0 step 2 memory map"
splot "run.2046.agent0.step2.memory" matrix with image
#
# plot agent 0 step 3 memory
set output "run.2046.agent0.step3.memory.png"
set title "run.2046: agent 0 step 3 memory map"
splot "run.2046.agent0.step3.memory" matrix with image
#
# plot agent 0 step 4 memory
set output "run.2046.agent0.step4.memory.png"
set title "run.2046: agent 0 step 4 memory map"
splot "run.2046.agent0.step4.memory" matrix with image
#
# plot agent 1 step 0 memory
set output "run.2046.agent1.step0.memory.png"
set title "run.2046: agent 1 step 0 memory map"
splot "run.2046.agent1.step0.memory" matrix with image
#
# plot agent 1 step 1 memory
set output "run.2046.agent1.step1.memory.png"
set title "run.2046: agent 1 step 1 memory map"
splot "run.2046.agent1.step1.memory" matrix with image
#
# plot agent 1 step 2 memory
set output "run.2046.agent1.step2.memory.png"
set title "run.2046: agent 1 step 2 memory map"
splot "run.2046.agent1.step2.memory" matrix with image
#
# plot agent 1 step 3 memory
set output "run.2046.agent1.step3.memory.png"
set title "run.2046: agent 1 step 3 memory map"
splot "run.2046.agent1.step3.memory" matrix with image
#
# plot agent 1 step 4 memory
set output "run.2046.agent1.step4.memory.png"
set title "run.2046: agent 1 step 4 memory map"
splot "run.2046.agent1.step4.memory" matrix with image
#
# plot agent 2 step 0 memory
set output "run.2046.agent2.step0.memory.png"
set title "run.2046: agent 2 step 0 memory map"
splot "run.2046.agent2.step0.memory" matrix with image
#
# plot agent 2 step 1 memory
set output "run.2046.agent2.step1.memory.png"
set title "run.2046: agent 2 step 1 memory map"
splot "run.2046.agent2.step1.memory" matrix with image
#
# plot agent 2 step 2 memory
set output "run.2046.agent2.step2.memory.png"
set title "run.2046: agent 2 step 2 memory map"
splot "run.2046.agent2.step2.memory" matrix with image
#
# plot agent 2 step 3 memory
set output "run.2046.agent2.step3.memory.png"
set title "run.2046: agent 2 step 3 memory map"
splot "run.2046.agent2.step3.memory" matrix with image
#
# plot agent 2 step 4 memory
set output "run.2046.agent2.step4.memory.png"
set title "run.2046: agent 2 step 4 memory map"
splot "run.2046.agent2.step4.memory" matrix with image
#
# plot agent 3 step 0 memory
set output "run.2046.agent3.step0.memory.png"
set title "run.2046: agent 3 step 0 memory map"
splot "run.2046.agent3.step0.memory" matrix with image
#
# plot agent 3 step 1 memory
set output "run.2046.agent3.step1.memory.png"
set title "run.2046: agent 3 step 1 memory map"
splot "run.2046.agent3.step1.memory" matrix with image
#
# plot agent 3 step 2 memory
set output "run.2046.agent3.step2.memory.png"
set title "run.2046: agent 3 step 2 memory map"
splot "run.2046.agent3.step2.memory" matrix with image
#
# plot agent 3 step 3 memory
set output "run.2046.agent3.step3.memory.png"
set title "run.2046: agent 3 step 3 memory map"
splot "run.2046.agent3.step3.memory" matrix with image
#
# plot agent 3 step 4 memory
set output "run.2046.agent3.step4.memory.png"
set title "run.2046: agent 3 step 4 memory map"
splot "run.2046.agent3.step4.memory" matrix with image
#
# plot agent 4 step 0 memory
set output "run.2046.agent4.step0.memory.png"
set title "run.2046: agent 4 step 0 memory map"
splot "run.2046.agent4.step0.memory" matrix with image
#
# plot agent 4 step 1 memory
set output "run.2046.agent4.step1.memory.png"
set title "run.2046: agent 4 step 1 memory map"
splot "run.2046.agent4.step1.memory" matrix with image
#
# plot agent 4 step 2 memory
set output "run.2046.agent4.step2.memory.png"
set title "run.2046: agent 4 step 2 memory map"
splot "run.2046.agent4.step2.memory" matrix with image
#
# plot agent 4 step 3 memory
set output "run.2046.agent4.step3.memory.png"
set title "run.2046: agent 4 step 3 memory map"
splot "run.2046.agent4.step3.memory" matrix with image
#
# plot agent 4 step 4 memory
set output "run.2046.agent4.step4.memory.png"
set title "run.2046: agent 4 step 4 memory map"
splot "run.2046.agent4.step4.memory" matrix with image
#
# plot agent 5 step 0 memory
set output "run.2046.agent5.step0.memory.png"
set title "run.2046: agent 5 step 0 memory map"
splot "run.2046.agent5.step0.memory" matrix with image
#
# plot agent 5 step 1 memory
set output "run.2046.agent5.step1.memory.png"
set title "run.2046: agent 5 step 1 memory map"
splot "run.2046.agent5.step1.memory" matrix with image
#
# plot agent 5 step 2 memory
set output "run.2046.agent5.step2.memory.png"
set title "run.2046: agent 5 step 2 memory map"
splot "run.2046.agent5.step2.memory" matrix with image
#
# plot agent 5 step 3 memory
set output "run.2046.agent5.step3.memory.png"
set title "run.2046: agent 5 step 3 memory map"
splot "run.2046.agent5.step3.memory" matrix with image
#
# plot agent 5 step 4 memory
set output "run.2046.agent5.step4.memory.png"
set title "run.2046: agent 5 step 4 memory map"
splot "run.2046.agent5.step4.memory" matrix with image
#
# plot agent 6 step 0 memory
set output "run.2046.agent6.step0.memory.png"
set title "run.2046: agent 6 step 0 memory map"
splot "run.2046.agent6.step0.memory" matrix with image
#
# plot agent 6 step 1 memory
set output "run.2046.agent6.step1.memory.png"
set title "run.2046: agent 6 step 1 memory map"
splot "run.2046.agent6.step1.memory" matrix with image
#
# plot agent 6 step 2 memory
set output "run.2046.agent6.step2.memory.png"
set title "run.2046: agent 6 step 2 memory map"
splot "run.2046.agent6.step2.memory" matrix with image
#
# plot agent 6 step 3 memory
set output "run.2046.agent6.step3.memory.png"
set title "run.2046: agent 6 step 3 memory map"
splot "run.2046.agent6.step3.memory" matrix with image
#
# plot agent 6 step 4 memory
set output "run.2046.agent6.step4.memory.png"
set title "run.2046: agent 6 step 4 memory map"
splot "run.2046.agent6.step4.memory" matrix with image
#
# plot agent 7 step 0 memory
set output "run.2046.agent7.step0.memory.png"
set title "run.2046: agent 7 step 0 memory map"
splot "run.2046.agent7.step0.memory" matrix with image
#
# plot agent 7 step 1 memory
set output "run.2046.agent7.step1.memory.png"
set title "run.2046: agent 7 step 1 memory map"
splot "run.2046.agent7.step1.memory" matrix with image
#
# plot agent 7 step 2 memory
set output "run.2046.agent7.step2.memory.png"
set title "run.2046: agent 7 step 2 memory map"
splot "run.2046.agent7.step2.memory" matrix with image
#
# plot agent 7 step 3 memory
set output "run.2046.agent7.step3.memory.png"
set title "run.2046: agent 7 step 3 memory map"
splot "run.2046.agent7.step3.memory" matrix with image
#
# plot agent 7 step 4 memory
set output "run.2046.agent7.step4.memory.png"
set title "run.2046: agent 7 step 4 memory map"
splot "run.2046.agent7.step4.memory" matrix with image
#
# plot agent 8 step 0 memory
set output "run.2046.agent8.step0.memory.png"
set title "run.2046: agent 8 step 0 memory map"
splot "run.2046.agent8.step0.memory" matrix with image
#
# plot agent 8 step 1 memory
set output "run.2046.agent8.step1.memory.png"
set title "run.2046: agent 8 step 1 memory map"
splot "run.2046.agent8.step1.memory" matrix with image
#
# plot agent 8 step 2 memory
set output "run.2046.agent8.step2.memory.png"
set title "run.2046: agent 8 step 2 memory map"
splot "run.2046.agent8.step2.memory" matrix with image
#
# plot agent 8 step 3 memory
set output "run.2046.agent8.step3.memory.png"
set title "run.2046: agent 8 step 3 memory map"
splot "run.2046.agent8.step3.memory" matrix with image
#
# plot agent 8 step 4 memory
set output "run.2046.agent8.step4.memory.png"
set title "run.2046: agent 8 step 4 memory map"
splot "run.2046.agent8.step4.memory" matrix with image
#
# plot agent 9 step 0 memory
set output "run.2046.agent9.step0.memory.png"
set title "run.2046: agent 9 step 0 memory map"
splot "run.2046.agent9.step0.memory" matrix with image
#
# plot agent 9 step 1 memory
set output "run.2046.agent9.step1.memory.png"
set title "run.2046: agent 9 step 1 memory map"
splot "run.2046.agent9.step1.memory" matrix with image
#
# plot agent 9 step 2 memory
set output "run.2046.agent9.step2.memory.png"
set title "run.2046: agent 9 step 2 memory map"
splot "run.2046.agent9.step2.memory" matrix with image
#
# plot agent 9 step 3 memory
set output "run.2046.agent9.step3.memory.png"
set title "run.2046: agent 9 step 3 memory map"
splot "run.2046.agent9.step3.memory" matrix with image
#
# plot agent 9 step 4 memory
set output "run.2046.agent9.step4.memory.png"
set title "run.2046: agent 9 step 4 memory map"
splot "run.2046.agent9.step4.memory" matrix with image
#
# plot agent 10 step 0 memory
set output "run.2046.agent10.step0.memory.png"
set title "run.2046: agent 10 step 0 memory map"
splot "run.2046.agent10.step0.memory" matrix with image
#
# plot agent 10 step 1 memory
set output "run.2046.agent10.step1.memory.png"
set title "run.2046: agent 10 step 1 memory map"
splot "run.2046.agent10.step1.memory" matrix with image
#
# plot agent 10 step 2 memory
set output "run.2046.agent10.step2.memory.png"
set title "run.2046: agent 10 step 2 memory map"
splot "run.2046.agent10.step2.memory" matrix with image
#
# plot agent 10 step 3 memory
set output "run.2046.agent10.step3.memory.png"
set title "run.2046: agent 10 step 3 memory map"
splot "run.2046.agent10.step3.memory" matrix with image
#
# plot agent 10 step 4 memory
set output "run.2046.agent10.step4.memory.png"
set title "run.2046: agent 10 step 4 memory map"
splot "run.2046.agent10.step4.memory" matrix with image
#
# plot agent 11 step 0 memory
set output "run.2046.agent11.step0.memory.png"
set title "run.2046: agent 11 step 0 memory map"
splot "run.2046.agent11.step0.memory" matrix with image
#
# plot agent 11 step 1 memory
set output "run.2046.agent11.step1.memory.png"
set title "run.2046: agent 11 step 1 memory map"
splot "run.2046.agent11.step1.memory" matrix with image
#
# plot agent 11 step 2 memory
set output "run.2046.agent11.step2.memory.png"
set title "run.2046: agent 11 step 2 memory map"
splot "run.2046.agent11.step2.memory" matrix with image
#
# plot agent 11 step 3 memory
set output "run.2046.agent11.step3.memory.png"
set title "run.2046: agent 11 step 3 memory map"
splot "run.2046.agent11.step3.memory" matrix with image
#
# plot agent 11 step 4 memory
set output "run.2046.agent11.step4.memory.png"
set title "run.2046: agent 11 step 4 memory map"
splot "run.2046.agent11.step4.memory" matrix with image
#
# plot agent 12 step 0 memory
set output "run.2046.agent12.step0.memory.png"
set title "run.2046: agent 12 step 0 memory map"
splot "run.2046.agent12.step0.memory" matrix with image
#
# plot agent 12 step 1 memory
set output "run.2046.agent12.step1.memory.png"
set title "run.2046: agent 12 step 1 memory map"
splot "run.2046.agent12.step1.memory" matrix with image
#
# plot agent 12 step 2 memory
set output "run.2046.agent12.step2.memory.png"
set title "run.2046: agent 12 step 2 memory map"
splot "run.2046.agent12.step2.memory" matrix with image
#
# plot agent 12 step 3 memory
set output "run.2046.agent12.step3.memory.png"
set title "run.2046: agent 12 step 3 memory map"
splot "run.2046.agent12.step3.memory" matrix with image
#
# plot agent 12 step 4 memory
set output "run.2046.agent12.step4.memory.png"
set title "run.2046: agent 12 step 4 memory map"
splot "run.2046.agent12.step4.memory" matrix with image
#
# plot agent 13 step 0 memory
set output "run.2046.agent13.step0.memory.png"
set title "run.2046: agent 13 step 0 memory map"
splot "run.2046.agent13.step0.memory" matrix with image
#
# plot agent 13 step 1 memory
set output "run.2046.agent13.step1.memory.png"
set title "run.2046: agent 13 step 1 memory map"
splot "run.2046.agent13.step1.memory" matrix with image
#
# plot agent 13 step 2 memory
set output "run.2046.agent13.step2.memory.png"
set title "run.2046: agent 13 step 2 memory map"
splot "run.2046.agent13.step2.memory" matrix with image
#
# plot agent 13 step 3 memory
set output "run.2046.agent13.step3.memory.png"
set title "run.2046: agent 13 step 3 memory map"
splot "run.2046.agent13.step3.memory" matrix with image
#
# plot agent 13 step 4 memory
set output "run.2046.agent13.step4.memory.png"
set title "run.2046: agent 13 step 4 memory map"
splot "run.2046.agent13.step4.memory" matrix with image
#
# plot agent 14 step 0 memory
set output "run.2046.agent14.step0.memory.png"
set title "run.2046: agent 14 step 0 memory map"
splot "run.2046.agent14.step0.memory" matrix with image
#
# plot agent 14 step 1 memory
set output "run.2046.agent14.step1.memory.png"
set title "run.2046: agent 14 step 1 memory map"
splot "run.2046.agent14.step1.memory" matrix with image
#
# plot agent 14 step 2 memory
set output "run.2046.agent14.step2.memory.png"
set title "run.2046: agent 14 step 2 memory map"
splot "run.2046.agent14.step2.memory" matrix with image
#
# plot agent 14 step 3 memory
set output "run.2046.agent14.step3.memory.png"
set title "run.2046: agent 14 step 3 memory map"
splot "run.2046.agent14.step3.memory" matrix with image
#
# plot agent 14 step 4 memory
set output "run.2046.agent14.step4.memory.png"
set title "run.2046: agent 14 step 4 memory map"
splot "run.2046.agent14.step4.memory" matrix with image
#
# plot agent 15 step 0 memory
set output "run.2046.agent15.step0.memory.png"
set title "run.2046: agent 15 step 0 memory map"
splot "run.2046.agent15.step0.memory" matrix with image
#
# plot agent 15 step 1 memory
set output "run.2046.agent15.step1.memory.png"
set title "run.2046: agent 15 step 1 memory map"
splot "run.2046.agent15.step1.memory" matrix with image
#
# plot agent 15 step 2 memory
set output "run.2046.agent15.step2.memory.png"
set title "run.2046: agent 15 step 2 memory map"
splot "run.2046.agent15.step2.memory" matrix with image
#
# plot agent 15 step 3 memory
set output "run.2046.agent15.step3.memory.png"
set title "run.2046: agent 15 step 3 memory map"
splot "run.2046.agent15.step3.memory" matrix with image
#
# plot agent 15 step 4 memory
set output "run.2046.agent15.step4.memory.png"
set title "run.2046: agent 15 step 4 memory map"
splot "run.2046.agent15.step4.memory" matrix with image
#
# plot agent 16 step 0 memory
set output "run.2046.agent16.step0.memory.png"
set title "run.2046: agent 16 step 0 memory map"
splot "run.2046.agent16.step0.memory" matrix with image
#
# plot agent 16 step 1 memory
set output "run.2046.agent16.step1.memory.png"
set title "run.2046: agent 16 step 1 memory map"
splot "run.2046.agent16.step1.memory" matrix with image
#
# plot agent 16 step 2 memory
set output "run.2046.agent16.step2.memory.png"
set title "run.2046: agent 16 step 2 memory map"
splot "run.2046.agent16.step2.memory" matrix with image
#
# plot agent 16 step 3 memory
set output "run.2046.agent16.step3.memory.png"
set title "run.2046: agent 16 step 3 memory map"
splot "run.2046.agent16.step3.memory" matrix with image
#
# plot agent 16 step 4 memory
set output "run.2046.agent16.step4.memory.png"
set title "run.2046: agent 16 step 4 memory map"
splot "run.2046.agent16.step4.memory" matrix with image
#
# plot agent 17 step 0 memory
set output "run.2046.agent17.step0.memory.png"
set title "run.2046: agent 17 step 0 memory map"
splot "run.2046.agent17.step0.memory" matrix with image
#
# plot agent 17 step 1 memory
set output "run.2046.agent17.step1.memory.png"
set title "run.2046: agent 17 step 1 memory map"
splot "run.2046.agent17.step1.memory" matrix with image
#
# plot agent 17 step 2 memory
set output "run.2046.agent17.step2.memory.png"
set title "run.2046: agent 17 step 2 memory map"
splot "run.2046.agent17.step2.memory" matrix with image
#
# plot agent 17 step 3 memory
set output "run.2046.agent17.step3.memory.png"
set title "run.2046: agent 17 step 3 memory map"
splot "run.2046.agent17.step3.memory" matrix with image
#
# plot agent 17 step 4 memory
set output "run.2046.agent17.step4.memory.png"
set title "run.2046: agent 17 step 4 memory map"
splot "run.2046.agent17.step4.memory" matrix with image
#
# plot agent 18 step 0 memory
set output "run.2046.agent18.step0.memory.png"
set title "run.2046: agent 18 step 0 memory map"
splot "run.2046.agent18.step0.memory" matrix with image
#
# plot agent 18 step 1 memory
set output "run.2046.agent18.step1.memory.png"
set title "run.2046: agent 18 step 1 memory map"
splot "run.2046.agent18.step1.memory" matrix with image
#
# plot agent 18 step 2 memory
set output "run.2046.agent18.step2.memory.png"
set title "run.2046: agent 18 step 2 memory map"
splot "run.2046.agent18.step2.memory" matrix with image
#
# plot agent 18 step 3 memory
set output "run.2046.agent18.step3.memory.png"
set title "run.2046: agent 18 step 3 memory map"
splot "run.2046.agent18.step3.memory" matrix with image
#
# plot agent 18 step 4 memory
set output "run.2046.agent18.step4.memory.png"
set title "run.2046: agent 18 step 4 memory map"
splot "run.2046.agent18.step4.memory" matrix with image
#
# plot agent 19 step 0 memory
set output "run.2046.agent19.step0.memory.png"
set title "run.2046: agent 19 step 0 memory map"
splot "run.2046.agent19.step0.memory" matrix with image
#
# plot agent 19 step 1 memory
set output "run.2046.agent19.step1.memory.png"
set title "run.2046: agent 19 step 1 memory map"
splot "run.2046.agent19.step1.memory" matrix with image
#
# plot agent 19 step 2 memory
set output "run.2046.agent19.step2.memory.png"
set title "run.2046: agent 19 step 2 memory map"
splot "run.2046.agent19.step2.memory" matrix with image
#
# plot agent 19 step 3 memory
set output "run.2046.agent19.step3.memory.png"
set title "run.2046: agent 19 step 3 memory map"
splot "run.2046.agent19.step3.memory" matrix with image
#
# plot agent 19 step 4 memory
set output "run.2046.agent19.step4.memory.png"
set title "run.2046: agent 19 step 4 memory map"
splot "run.2046.agent19.step4.memory" matrix with image

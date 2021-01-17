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
# plot agent 0 step 1000 memory
set output "run.2003.agent0.finalmemory.eps"
set title "run.2003: agent 0 step 1000 memory map"
splot "run.2003.agent0.finalmemory" matrix with image
#
# plot agent 1 step 1000 memory
set output "run.2003.agent1.finalmemory.eps"
set title "run.2003: agent 1 step 1000 memory map"
splot "run.2003.agent1.finalmemory" matrix with image
#
# plot agent 2 step 1000 memory
set output "run.2003.agent2.finalmemory.eps"
set title "run.2003: agent 2 step 1000 memory map"
splot "run.2003.agent2.finalmemory" matrix with image
#
# plot agent 3 step 1000 memory
set output "run.2003.agent3.finalmemory.eps"
set title "run.2003: agent 3 step 1000 memory map"
splot "run.2003.agent3.finalmemory" matrix with image
#
# plot agent 4 step 1000 memory
set output "run.2003.agent4.finalmemory.eps"
set title "run.2003: agent 4 step 1000 memory map"
splot "run.2003.agent4.finalmemory" matrix with image
#
# plot agent 5 step 1000 memory
set output "run.2003.agent5.finalmemory.eps"
set title "run.2003: agent 5 step 1000 memory map"
splot "run.2003.agent5.finalmemory" matrix with image
#
# plot agent 6 step 1000 memory
set output "run.2003.agent6.finalmemory.eps"
set title "run.2003: agent 6 step 1000 memory map"
splot "run.2003.agent6.finalmemory" matrix with image
#
# plot agent 7 step 1000 memory
set output "run.2003.agent7.finalmemory.eps"
set title "run.2003: agent 7 step 1000 memory map"
splot "run.2003.agent7.finalmemory" matrix with image
#
# plot agent 8 step 1000 memory
set output "run.2003.agent8.finalmemory.eps"
set title "run.2003: agent 8 step 1000 memory map"
splot "run.2003.agent8.finalmemory" matrix with image
#
# plot agent 9 step 1000 memory
set output "run.2003.agent9.finalmemory.eps"
set title "run.2003: agent 9 step 1000 memory map"
splot "run.2003.agent9.finalmemory" matrix with image
#
# plot agent 10 step 1000 memory
set output "run.2003.agent10.finalmemory.eps"
set title "run.2003: agent 10 step 1000 memory map"
splot "run.2003.agent10.finalmemory" matrix with image
#
# plot agent 11 step 1000 memory
set output "run.2003.agent11.finalmemory.eps"
set title "run.2003: agent 11 step 1000 memory map"
splot "run.2003.agent11.finalmemory" matrix with image
#
# plot agent 12 step 1000 memory
set output "run.2003.agent12.finalmemory.eps"
set title "run.2003: agent 12 step 1000 memory map"
splot "run.2003.agent12.finalmemory" matrix with image
#
# plot agent 13 step 1000 memory
set output "run.2003.agent13.finalmemory.eps"
set title "run.2003: agent 13 step 1000 memory map"
splot "run.2003.agent13.finalmemory" matrix with image
#
# plot agent 14 step 1000 memory
set output "run.2003.agent14.finalmemory.eps"
set title "run.2003: agent 14 step 1000 memory map"
splot "run.2003.agent14.finalmemory" matrix with image
#
# plot agent 15 step 1000 memory
set output "run.2003.agent15.finalmemory.eps"
set title "run.2003: agent 15 step 1000 memory map"
splot "run.2003.agent15.finalmemory" matrix with image
#
# plot agent 16 step 1000 memory
set output "run.2003.agent16.finalmemory.eps"
set title "run.2003: agent 16 step 1000 memory map"
splot "run.2003.agent16.finalmemory" matrix with image
#
# plot agent 17 step 1000 memory
set output "run.2003.agent17.finalmemory.eps"
set title "run.2003: agent 17 step 1000 memory map"
splot "run.2003.agent17.finalmemory" matrix with image
#
# plot agent 18 step 1000 memory
set output "run.2003.agent18.finalmemory.eps"
set title "run.2003: agent 18 step 1000 memory map"
splot "run.2003.agent18.finalmemory" matrix with image
#
# plot agent 19 step 1000 memory
set output "run.2003.agent19.finalmemory.eps"
set title "run.2003: agent 19 step 1000 memory map"
splot "run.2003.agent19.finalmemory" matrix with image
#
# plot agent 20 step 1000 memory
set output "run.2003.agent20.finalmemory.eps"
set title "run.2003: agent 20 step 1000 memory map"
splot "run.2003.agent20.finalmemory" matrix with image
#
# plot agent 21 step 1000 memory
set output "run.2003.agent21.finalmemory.eps"
set title "run.2003: agent 21 step 1000 memory map"
splot "run.2003.agent21.finalmemory" matrix with image
#
# plot agent 22 step 1000 memory
set output "run.2003.agent22.finalmemory.eps"
set title "run.2003: agent 22 step 1000 memory map"
splot "run.2003.agent22.finalmemory" matrix with image
#
# plot agent 23 step 1000 memory
set output "run.2003.agent23.finalmemory.eps"
set title "run.2003: agent 23 step 1000 memory map"
splot "run.2003.agent23.finalmemory" matrix with image
#
# plot agent 24 step 1000 memory
set output "run.2003.agent24.finalmemory.eps"
set title "run.2003: agent 24 step 1000 memory map"
splot "run.2003.agent24.finalmemory" matrix with image
#
# plot agent 25 step 1000 memory
set output "run.2003.agent25.finalmemory.eps"
set title "run.2003: agent 25 step 1000 memory map"
splot "run.2003.agent25.finalmemory" matrix with image
#
# plot agent 26 step 1000 memory
set output "run.2003.agent26.finalmemory.eps"
set title "run.2003: agent 26 step 1000 memory map"
splot "run.2003.agent26.finalmemory" matrix with image
#
# plot agent 27 step 1000 memory
set output "run.2003.agent27.finalmemory.eps"
set title "run.2003: agent 27 step 1000 memory map"
splot "run.2003.agent27.finalmemory" matrix with image
#
# plot agent 28 step 1000 memory
set output "run.2003.agent28.finalmemory.eps"
set title "run.2003: agent 28 step 1000 memory map"
splot "run.2003.agent28.finalmemory" matrix with image
#
# plot agent 29 step 1000 memory
set output "run.2003.agent29.finalmemory.eps"
set title "run.2003: agent 29 step 1000 memory map"
splot "run.2003.agent29.finalmemory" matrix with image
#
# plot agent 30 step 1000 memory
set output "run.2003.agent30.finalmemory.eps"
set title "run.2003: agent 30 step 1000 memory map"
splot "run.2003.agent30.finalmemory" matrix with image
#
# plot agent 31 step 1000 memory
set output "run.2003.agent31.finalmemory.eps"
set title "run.2003: agent 31 step 1000 memory map"
splot "run.2003.agent31.finalmemory" matrix with image
#
# plot agent 32 step 1000 memory
set output "run.2003.agent32.finalmemory.eps"
set title "run.2003: agent 32 step 1000 memory map"
splot "run.2003.agent32.finalmemory" matrix with image
#
# plot agent 33 step 1000 memory
set output "run.2003.agent33.finalmemory.eps"
set title "run.2003: agent 33 step 1000 memory map"
splot "run.2003.agent33.finalmemory" matrix with image
#
# plot agent 34 step 1000 memory
set output "run.2003.agent34.finalmemory.eps"
set title "run.2003: agent 34 step 1000 memory map"
splot "run.2003.agent34.finalmemory" matrix with image
#
# plot agent 35 step 1000 memory
set output "run.2003.agent35.finalmemory.eps"
set title "run.2003: agent 35 step 1000 memory map"
splot "run.2003.agent35.finalmemory" matrix with image
#
# plot agent 36 step 1000 memory
set output "run.2003.agent36.finalmemory.eps"
set title "run.2003: agent 36 step 1000 memory map"
splot "run.2003.agent36.finalmemory" matrix with image
#
# plot agent 37 step 1000 memory
set output "run.2003.agent37.finalmemory.eps"
set title "run.2003: agent 37 step 1000 memory map"
splot "run.2003.agent37.finalmemory" matrix with image
#
# plot agent 38 step 1000 memory
set output "run.2003.agent38.finalmemory.eps"
set title "run.2003: agent 38 step 1000 memory map"
splot "run.2003.agent38.finalmemory" matrix with image
#
# plot agent 39 step 1000 memory
set output "run.2003.agent39.finalmemory.eps"
set title "run.2003: agent 39 step 1000 memory map"
splot "run.2003.agent39.finalmemory" matrix with image
#
# plot agent 40 step 1000 memory
set output "run.2003.agent40.finalmemory.eps"
set title "run.2003: agent 40 step 1000 memory map"
splot "run.2003.agent40.finalmemory" matrix with image
#
# plot agent 41 step 1000 memory
set output "run.2003.agent41.finalmemory.eps"
set title "run.2003: agent 41 step 1000 memory map"
splot "run.2003.agent41.finalmemory" matrix with image
#
# plot agent 42 step 1000 memory
set output "run.2003.agent42.finalmemory.eps"
set title "run.2003: agent 42 step 1000 memory map"
splot "run.2003.agent42.finalmemory" matrix with image
#
# plot agent 43 step 1000 memory
set output "run.2003.agent43.finalmemory.eps"
set title "run.2003: agent 43 step 1000 memory map"
splot "run.2003.agent43.finalmemory" matrix with image
#
# plot agent 44 step 1000 memory
set output "run.2003.agent44.finalmemory.eps"
set title "run.2003: agent 44 step 1000 memory map"
splot "run.2003.agent44.finalmemory" matrix with image
#
# plot agent 45 step 1000 memory
set output "run.2003.agent45.finalmemory.eps"
set title "run.2003: agent 45 step 1000 memory map"
splot "run.2003.agent45.finalmemory" matrix with image
#
# plot agent 46 step 1000 memory
set output "run.2003.agent46.finalmemory.eps"
set title "run.2003: agent 46 step 1000 memory map"
splot "run.2003.agent46.finalmemory" matrix with image
#
# plot agent 47 step 1000 memory
set output "run.2003.agent47.finalmemory.eps"
set title "run.2003: agent 47 step 1000 memory map"
splot "run.2003.agent47.finalmemory" matrix with image
#
# plot agent 48 step 1000 memory
set output "run.2003.agent48.finalmemory.eps"
set title "run.2003: agent 48 step 1000 memory map"
splot "run.2003.agent48.finalmemory" matrix with image
#
# plot agent 49 step 1000 memory
set output "run.2003.agent49.finalmemory.eps"
set title "run.2003: agent 49 step 1000 memory map"
splot "run.2003.agent49.finalmemory" matrix with image
#
# plot agent 50 step 1000 memory
set output "run.2003.agent50.finalmemory.eps"
set title "run.2003: agent 50 step 1000 memory map"
splot "run.2003.agent50.finalmemory" matrix with image
#
# plot agent 51 step 1000 memory
set output "run.2003.agent51.finalmemory.eps"
set title "run.2003: agent 51 step 1000 memory map"
splot "run.2003.agent51.finalmemory" matrix with image
#
# plot agent 52 step 1000 memory
set output "run.2003.agent52.finalmemory.eps"
set title "run.2003: agent 52 step 1000 memory map"
splot "run.2003.agent52.finalmemory" matrix with image
#
# plot agent 53 step 1000 memory
set output "run.2003.agent53.finalmemory.eps"
set title "run.2003: agent 53 step 1000 memory map"
splot "run.2003.agent53.finalmemory" matrix with image
#
# plot agent 54 step 1000 memory
set output "run.2003.agent54.finalmemory.eps"
set title "run.2003: agent 54 step 1000 memory map"
splot "run.2003.agent54.finalmemory" matrix with image
#
# plot agent 55 step 1000 memory
set output "run.2003.agent55.finalmemory.eps"
set title "run.2003: agent 55 step 1000 memory map"
splot "run.2003.agent55.finalmemory" matrix with image
#
# plot agent 56 step 1000 memory
set output "run.2003.agent56.finalmemory.eps"
set title "run.2003: agent 56 step 1000 memory map"
splot "run.2003.agent56.finalmemory" matrix with image
#
# plot agent 57 step 1000 memory
set output "run.2003.agent57.finalmemory.eps"
set title "run.2003: agent 57 step 1000 memory map"
splot "run.2003.agent57.finalmemory" matrix with image
#
# plot agent 58 step 1000 memory
set output "run.2003.agent58.finalmemory.eps"
set title "run.2003: agent 58 step 1000 memory map"
splot "run.2003.agent58.finalmemory" matrix with image
#
# plot agent 59 step 1000 memory
set output "run.2003.agent59.finalmemory.eps"
set title "run.2003: agent 59 step 1000 memory map"
splot "run.2003.agent59.finalmemory" matrix with image
#
# plot agent 60 step 1000 memory
set output "run.2003.agent60.finalmemory.eps"
set title "run.2003: agent 60 step 1000 memory map"
splot "run.2003.agent60.finalmemory" matrix with image
#
# plot agent 61 step 1000 memory
set output "run.2003.agent61.finalmemory.eps"
set title "run.2003: agent 61 step 1000 memory map"
splot "run.2003.agent61.finalmemory" matrix with image
#
# plot agent 62 step 1000 memory
set output "run.2003.agent62.finalmemory.eps"
set title "run.2003: agent 62 step 1000 memory map"
splot "run.2003.agent62.finalmemory" matrix with image
#
# plot agent 63 step 1000 memory
set output "run.2003.agent63.finalmemory.eps"
set title "run.2003: agent 63 step 1000 memory map"
splot "run.2003.agent63.finalmemory" matrix with image
#
# plot agent 64 step 1000 memory
set output "run.2003.agent64.finalmemory.eps"
set title "run.2003: agent 64 step 1000 memory map"
splot "run.2003.agent64.finalmemory" matrix with image
#
# plot agent 65 step 1000 memory
set output "run.2003.agent65.finalmemory.eps"
set title "run.2003: agent 65 step 1000 memory map"
splot "run.2003.agent65.finalmemory" matrix with image
#
# plot agent 66 step 1000 memory
set output "run.2003.agent66.finalmemory.eps"
set title "run.2003: agent 66 step 1000 memory map"
splot "run.2003.agent66.finalmemory" matrix with image
#
# plot agent 67 step 1000 memory
set output "run.2003.agent67.finalmemory.eps"
set title "run.2003: agent 67 step 1000 memory map"
splot "run.2003.agent67.finalmemory" matrix with image
#
# plot agent 68 step 1000 memory
set output "run.2003.agent68.finalmemory.eps"
set title "run.2003: agent 68 step 1000 memory map"
splot "run.2003.agent68.finalmemory" matrix with image
#
# plot agent 69 step 1000 memory
set output "run.2003.agent69.finalmemory.eps"
set title "run.2003: agent 69 step 1000 memory map"
splot "run.2003.agent69.finalmemory" matrix with image
#
# plot agent 70 step 1000 memory
set output "run.2003.agent70.finalmemory.eps"
set title "run.2003: agent 70 step 1000 memory map"
splot "run.2003.agent70.finalmemory" matrix with image
#
# plot agent 71 step 1000 memory
set output "run.2003.agent71.finalmemory.eps"
set title "run.2003: agent 71 step 1000 memory map"
splot "run.2003.agent71.finalmemory" matrix with image
#
# plot agent 72 step 1000 memory
set output "run.2003.agent72.finalmemory.eps"
set title "run.2003: agent 72 step 1000 memory map"
splot "run.2003.agent72.finalmemory" matrix with image
#
# plot agent 73 step 1000 memory
set output "run.2003.agent73.finalmemory.eps"
set title "run.2003: agent 73 step 1000 memory map"
splot "run.2003.agent73.finalmemory" matrix with image
#
# plot agent 74 step 1000 memory
set output "run.2003.agent74.finalmemory.eps"
set title "run.2003: agent 74 step 1000 memory map"
splot "run.2003.agent74.finalmemory" matrix with image
#
# plot agent 75 step 1000 memory
set output "run.2003.agent75.finalmemory.eps"
set title "run.2003: agent 75 step 1000 memory map"
splot "run.2003.agent75.finalmemory" matrix with image
#
# plot agent 76 step 1000 memory
set output "run.2003.agent76.finalmemory.eps"
set title "run.2003: agent 76 step 1000 memory map"
splot "run.2003.agent76.finalmemory" matrix with image
#
# plot agent 77 step 1000 memory
set output "run.2003.agent77.finalmemory.eps"
set title "run.2003: agent 77 step 1000 memory map"
splot "run.2003.agent77.finalmemory" matrix with image
#
# plot agent 78 step 1000 memory
set output "run.2003.agent78.finalmemory.eps"
set title "run.2003: agent 78 step 1000 memory map"
splot "run.2003.agent78.finalmemory" matrix with image
#
# plot agent 79 step 1000 memory
set output "run.2003.agent79.finalmemory.eps"
set title "run.2003: agent 79 step 1000 memory map"
splot "run.2003.agent79.finalmemory" matrix with image
#
# plot agent 80 step 1000 memory
set output "run.2003.agent80.finalmemory.eps"
set title "run.2003: agent 80 step 1000 memory map"
splot "run.2003.agent80.finalmemory" matrix with image
#
# plot agent 81 step 1000 memory
set output "run.2003.agent81.finalmemory.eps"
set title "run.2003: agent 81 step 1000 memory map"
splot "run.2003.agent81.finalmemory" matrix with image
#
# plot agent 82 step 1000 memory
set output "run.2003.agent82.finalmemory.eps"
set title "run.2003: agent 82 step 1000 memory map"
splot "run.2003.agent82.finalmemory" matrix with image
#
# plot agent 83 step 1000 memory
set output "run.2003.agent83.finalmemory.eps"
set title "run.2003: agent 83 step 1000 memory map"
splot "run.2003.agent83.finalmemory" matrix with image
#
# plot agent 84 step 1000 memory
set output "run.2003.agent84.finalmemory.eps"
set title "run.2003: agent 84 step 1000 memory map"
splot "run.2003.agent84.finalmemory" matrix with image
#
# plot agent 85 step 1000 memory
set output "run.2003.agent85.finalmemory.eps"
set title "run.2003: agent 85 step 1000 memory map"
splot "run.2003.agent85.finalmemory" matrix with image
#
# plot agent 86 step 1000 memory
set output "run.2003.agent86.finalmemory.eps"
set title "run.2003: agent 86 step 1000 memory map"
splot "run.2003.agent86.finalmemory" matrix with image
#
# plot agent 87 step 1000 memory
set output "run.2003.agent87.finalmemory.eps"
set title "run.2003: agent 87 step 1000 memory map"
splot "run.2003.agent87.finalmemory" matrix with image
#
# plot agent 88 step 1000 memory
set output "run.2003.agent88.finalmemory.eps"
set title "run.2003: agent 88 step 1000 memory map"
splot "run.2003.agent88.finalmemory" matrix with image
#
# plot agent 89 step 1000 memory
set output "run.2003.agent89.finalmemory.eps"
set title "run.2003: agent 89 step 1000 memory map"
splot "run.2003.agent89.finalmemory" matrix with image
#
# plot agent 90 step 1000 memory
set output "run.2003.agent90.finalmemory.eps"
set title "run.2003: agent 90 step 1000 memory map"
splot "run.2003.agent90.finalmemory" matrix with image
#
# plot agent 91 step 1000 memory
set output "run.2003.agent91.finalmemory.eps"
set title "run.2003: agent 91 step 1000 memory map"
splot "run.2003.agent91.finalmemory" matrix with image
#
# plot agent 92 step 1000 memory
set output "run.2003.agent92.finalmemory.eps"
set title "run.2003: agent 92 step 1000 memory map"
splot "run.2003.agent92.finalmemory" matrix with image
#
# plot agent 93 step 1000 memory
set output "run.2003.agent93.finalmemory.eps"
set title "run.2003: agent 93 step 1000 memory map"
splot "run.2003.agent93.finalmemory" matrix with image
#
# plot agent 94 step 1000 memory
set output "run.2003.agent94.finalmemory.eps"
set title "run.2003: agent 94 step 1000 memory map"
splot "run.2003.agent94.finalmemory" matrix with image
#
# plot agent 95 step 1000 memory
set output "run.2003.agent95.finalmemory.eps"
set title "run.2003: agent 95 step 1000 memory map"
splot "run.2003.agent95.finalmemory" matrix with image
#
# plot agent 96 step 1000 memory
set output "run.2003.agent96.finalmemory.eps"
set title "run.2003: agent 96 step 1000 memory map"
splot "run.2003.agent96.finalmemory" matrix with image
#
# plot agent 97 step 1000 memory
set output "run.2003.agent97.finalmemory.eps"
set title "run.2003: agent 97 step 1000 memory map"
splot "run.2003.agent97.finalmemory" matrix with image
#
# plot agent 98 step 1000 memory
set output "run.2003.agent98.finalmemory.eps"
set title "run.2003: agent 98 step 1000 memory map"
splot "run.2003.agent98.finalmemory" matrix with image
#
# plot agent 99 step 1000 memory
set output "run.2003.agent99.finalmemory.eps"
set title "run.2003: agent 99 step 1000 memory map"
splot "run.2003.agent99.finalmemory" matrix with image
unset size
unset xrange
unset yrange
unset view

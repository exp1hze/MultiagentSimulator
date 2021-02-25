set term post eps color

# plot finalagentsuccessrate heatmap
set output "finalagentsuccessrate.eps"
set size ratio 1
set title "final_agent_success_rate"
unset key
set tic scale 0
# set palette defined (0 "white", 1 "red" )
# set palette defined (0 "#FF0000", 1 "#00CC00" )
set palette rgbformula -7, 2, -7
set cbrange [0.0:1.0]
set cblabel "Score"
# set xrange [-1:100]
# set yrange [-1:100] 
set view map
splot "finalagentsuccessrate" matrix with image
unset cblabel

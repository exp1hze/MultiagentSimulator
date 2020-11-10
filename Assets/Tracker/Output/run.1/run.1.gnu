set term post eps
set xlabel "Timestep"
set ylabel "Bins"
set zlabel "Count"
set output "run.1.stephistnorth.eps"
set title "Histogram of intensity values, north"
set dgrid3d 50,50 qnorm 2
splot "run.1.stephistnorth" using 2:4:6 w lines
unset size
unset title

set term post eps
set xlabel "Timestep"
set ylabel "Bins"
set zlabel "Count"
set output "run.1.stephistsouth.eps"
set title "Histogram of intensity values, south"
set dgrid3d 50,50 qnorm 2
splot "run.1.stephistsouth" using 2:4:6 w lines
unset size
unset title

set term post eps
set xlabel "Timestep"
set ylabel "Bins"
set zlabel "Count"
set output "run.1.stephisteast.eps"
set title "Histogram of intensity values, east"
set dgrid3d 50,50 qnorm 2
splot "run.1.stephisteast" using 2:4:6 w lines
unset size
unset title

set term post eps
set xlabel "Timestep"
set ylabel "Bins"
set zlabel "Count"
set output "run.1.stephistwest.eps"
set title "Histogram of intensity values, west"
set dgrid3d 50,50 qnorm 2
splot "run.1.stephistwest" using 2:4:6 w lines
unset size
unset title

set term post eps color
set xlabel "Timestep"
set ylabel "Distance"
set output "run.1.stepdemandnorth.eps"
set title "Demand and delivered, North"
plot "run.1.stepdemand" using 2:5 title "Demand"  w lines,\
     "run.1.stepdemand" using 2:14 title "Delivered" w lines
set output "run.1.stepdemandsouth.eps"
set title "Demand and delivered, South"
plot "run.1.stepdemand" using 2:7 title "Demand"  w lines,\
     "run.1.stepdemand" using 2:16 title "Delivered" w lines
set output "run.1.stepdemandeast.eps"
set title "Demand and delivered, East"
plot "run.1.stepdemand" using 2:9 title "Demand"  w lines,\
     "run.1.stepdemand" using 2:18 title "Delivered" w lines
set output "run.1.stepdemandwest.eps"
set title "Demand and delivered, West"
plot "run.1.stepdemand" using 2:11 title "Demand"  w lines,\
     "run.1.stepdemand" using 2:20 title "Delivered" w lines
unset size
unset title

set term post eps color
set output "run.1.stepsummary.steplen.eps"
set title "Length of each step"
set xlabel "Timestep"
set ylabel "Step length"
plot [-2:] "run.1.stepsummary" using 2:18 title "Target" w line,\
     "run.1.stepsummary" using 2:20 title "Tracker" w line lc 3
unset xlabel
unset ylabel
unset title

set term post eps color
set size ratio 0.5
set output "run.1.stepsummary.paths.linesp.eps"
set title "Target and Tracker paths"
plot\
     "run.1.stepsummary" using 4:5 title "Target" w linesp,\
     "run.1.stepsummary" using 7:8 title "Tracker" w linesp lc 3
unset size
unset title

set term post eps color
set size ratio 0.5
set output "run.1.stepsummary.paths.line.eps"
set size ratio -1
set title "Target and Tracker paths"
plot\
     "run.1.stepsummary" using 4:5 title "Target" w line,\
     "run.1.stepsummary" using 7:8 title "Tracker" w line lc 3
unset size
unset title

set term post eps color
set size ratio 0.5
set output "run.1.stepsummary.dist.eps"
set title "Distance between Target and Tracker"
set xlabel "Timestep"
set ylabel "Distance between target and tracker"
plot [-2:] "run.1.stepsummary" using 2:10 w impulse
unset size
unset xlabel
unset ylabel
unset title

set term post eps color
set size ratio 0.5
set xlabel "Timestep"
set ylabel "Number of agents"
set output "run.1.stepsummary.pushnorth.eps"
set title "Number of agents pushing north"
plot [-2:][0:50] "run.1.stepsummary" using 2:23 w impulse
set output "run.1.stepsummary.pusheast.eps"
set title "Number of agents pushing east"
plot [-2:][0:50] "run.1.stepsummary" using 2:25 w impulse
set output "run.1.stepsummary.pushsouth.eps"
set title "Number of agents pushing south"
plot [-2:][0:50] "run.1.stepsummary" using 2:27 w impulse
set output "run.1.stepsummary.pushwest.eps"
set title "Number of agents pushing west"
plot [-2:][0:50] "run.1.stepsummary" using 2:29 w impulse
set output "run.1.stepsummary.pushnone.eps"
set title "Number of idle agents"
plot [-2:][0:50] "run.1.stepsummary" using 2:31 w impulse
set output "run.1.stepsummary.pushall.eps"
set title "Total number of agents pushing"
plot [-2:][0:50] "run.1.stepsummary" using 2:($23+$25+$27+$29) w impulse
unset size
unset xlabel
unset ylabel
unset title

set term post eps color
set size square
set output "run.1.initpop.rawthresh.eps"
set xtics ("N" 1, "E" 2, "S" 3, "W" 4)
set ylabel "Raw thresholds"
set title "Initial population thresholds - raw"
plot [0:5][0:1.2]\
     "run.1.initpop" using 23:5 w points,\
     "run.1.initpop" using 24:7 w points,\
     "run.1.initpop" using 25:9 w points,\
     "run.1.initpop" using 26:11 w points,\
     1.0 title "" lt 1 lc 7
unset size
unset ylabel
unset xtics
set xtics

set term post eps color
set size square
set output "run.1.initpop.scaledthresh.eps"
set xtics ("N" 1, "E" 2, "S" 3, "W" 4)
set ylabel "Scaled thresholds"
set title "Initial population thresholds - scaled"
plot [0:5][0:12.000000]\
     "run.1.initpop" using 23:16 w points,\
     "run.1.initpop" using 24:18 w points,\
     "run.1.initpop" using 25:20 w points,\
     "run.1.initpop" using 26:22 w points,\
     10.000000 title "" lt 1 lc 7
unset size
unset ylabel
unset xtics
unset title
set xtics

set term post eps color
set size square
set output "run.1.finalpop.scaledthresh.eps"
set xtics ("N" 1, "E" 2, "S" 3, "W" 4)
set ylabel "Scaled thresholds"
set title "Initial population thresholds - scaled"
plot [0:5][0:12.000000]\
     "run.1.finalpop" using 23:16 w points,\
     "run.1.finalpop" using 24:18 w points,\
     "run.1.finalpop" using 25:20 w points,\
     "run.1.finalpop" using 26:22 w points,\
     10.000000 title "" lt 1 lc 7
unset size
unset ylabel
unset xtics
unset title
set xtics

set term post eps color
set size ratio 0.5
set output "run.1.stepnorthsouth.loc.eps"
set title "North/south locations"
set xlabel "Timestep"
set ylabel "y-coordinate"
plot "run.1.stepnorthsouth" using 2:4 title "Target" w line,\
     "run.1.stepnorthsouth" using 2:6 title "Tracker" w line lc 3
unset size

set term post eps color
set size ratio 0.5
set output "run.1.stepnorthsouth.diff.eps"
set title "North/south difference, Target loc - Tracker loc"
set xlabel "Timestep"
set ylabel "Difference on y-axis"
plot "run.1.stepnorthsouth" using 2:8 title "Target" w impulse
unset size
unset xlabel
unset ylabel
unset title

set term post eps color
set size ratio 0.5
set output "run.1.stepeastwest.loc.eps"
set title "East/west locations"
set xlabel "Timestep"
set ylabel "x-coordinate"
plot "run.1.stepeastwest" using 2:4 title "Target" w line,\
     "run.1.stepeastwest" using 2:6 title "Tracker" w line lc 3
unset size

set term post eps color
set size ratio 0.5
set output "run.1.stepeastwest.diff.eps"
set title "East/west difference, Target loc - Tracker loc"
set xlabel "Timestep"
set ylabel "Difference on x-axis"
plot "run.1.stepeastwest" using 2:8 title "Target" w impulse
unset size
unset xlabel
unset ylabel
unset title

set term post eps color
set size ratio 1.000000
set output "run.1.stepagentaction.eps"
set title "Agent actions, 1=N 2=E 3=S 4=W"
set xlabel "Agent"
set ylabel "Timestep"
set palette maxcolors 5
set palette defined (0 "white", 1 "blue", 2 "yellow", 3 "red", 4 "green")
set cbrange[-0.5:4.5]
set view map
plot [][51:-2] "run.1.stepagentaction" matrix w image

set term post eps color
set size ratio 2
set output "run.1.stepthreshnorth.eps"
set title "Agent thresholds: North"
set xlabel "Agent"
set ylabel "Timestep"
set palette maxcolors 100
set palette defined (0 "green", 5.000000 "yellow", 10.000000 "red")
set cbrange[0:10.000000]
set view map
plot [-5.000000:55.000000][51:-2] "run.1.stepthreshnorth" matrix title "" w image
unset size
unset title
unset xlabel
unset ylabel

set term post eps color
set size ratio 2
set output "run.1.stepthreshsouth.eps"
set title "Agent thresholds: South"
set xlabel "Agent"
set ylabel "Timestep"
set palette maxcolors 100
set palette defined (0 "green", 5.000000 "yellow", 10.000000 "red")
set cbrange[0:10.000000]
set view map
plot [-5.000000:55.000000][51:-2] "run.1.stepthreshsouth" matrix title "" w image
unset size
unset title
unset xlabel
unset ylabel

set term post eps color
set size ratio 2
set output "run.1.stepthresheast.eps"
set title "Agent thresholds: East"
set xlabel "Agent"
set ylabel "Timestep"
set palette maxcolors 100
set palette defined (0 "green", 5.000000 "yellow", 10.000000 "red")
set cbrange[0:10.000000]
set view map
plot [-5.000000:55.000000][51:-2] "run.1.stepthresheast" matrix title "" w image
unset size
unset title
unset xlabel
unset ylabel

set term post eps color
set size ratio 2
set output "run.1.stepthreshwest.eps"
set title "Agent thresholds: West"
set xlabel "Agent"
set ylabel "Timestep"
set palette maxcolors 100
set palette defined (0 "green", 5.000000 "yellow", 10.000000 "red")
set cbrange[0:10.000000]
set view map
plot [-5.000000:55.000000][51:-2] "run.1.stepthreshwest" matrix title "" w image
unset size
unset title
unset xlabel
unset ylabel

set term post eps
set size ratio 0.5
set xlabel "Agent"
set ylabel "Threshold"
set output "run.1.threshrangenorth.eps"
set title "Agent threshold ranges: North"
plot "run.1.threshrange" using 2:4:5:6 title "" w errorbars
set output "run.1.threshrangesouth.eps"
set title "Agent threshold ranges: South"
plot "run.1.threshrange" using 2:8:9:10 title "" w errorbars
set output "run.1.threshrangeeast.eps"
set title "Agent threshold ranges: East"
plot "run.1.threshrange" using 2:12:13:14 title "" w errorbars
set output "run.1.threshrangewest.eps"
set title "Agent threshold ranges: West"
plot "run.1.threshrange" using 2:16:17:18 title "" w errorbars
unset size

set term post eps
set style rectangle fc rgb "light-blue" fs solid noborder
set size ratio 2
set output "run.1.stepagentactionwtime.eps"
set title "Agent actions\n0=idle, 1=N, 2=E, 3=S, 4=W"
set xlabel "Timestep"
unset ytics
unset ylabel
set object 1 rect from 0,0 to 50,8
set object 2 rect from 0,14 to 50,22
set object 3 rect from 0,28 to 50,36
set object 4 rect from 0,42 to 50,50
set object 5 rect from 0,56 to 50,64
set object 6 rect from 0,70 to 50,78
set object 7 rect from 0,84 to 50,92
set object 8 rect from 0,98 to 50,106
set object 9 rect from 0,112 to 50,120
set object 10 rect from 0,126 to 50,134
set object 11 rect from 0,140 to 50,148
set object 12 rect from 0,154 to 50,162
set object 13 rect from 0,168 to 50,176
set object 14 rect from 0,182 to 50,190
set object 15 rect from 0,196 to 50,204
set object 16 rect from 0,210 to 50,218
set object 17 rect from 0,224 to 50,232
set object 18 rect from 0,238 to 50,246
set object 19 rect from 0,252 to 50,260
set object 20 rect from 0,266 to 50,274
set object 21 rect from 0,280 to 50,288
set object 22 rect from 0,294 to 50,302
set object 23 rect from 0,308 to 50,316
set object 24 rect from 0,322 to 50,330
set object 25 rect from 0,336 to 50,344
set object 26 rect from 0,350 to 50,358
set object 27 rect from 0,364 to 50,372
set object 28 rect from 0,378 to 50,386
set object 29 rect from 0,392 to 50,400
set object 30 rect from 0,406 to 50,414
set object 31 rect from 0,420 to 50,428
set object 32 rect from 0,434 to 50,442
set object 33 rect from 0,448 to 50,456
set object 34 rect from 0,462 to 50,470
set object 35 rect from 0,476 to 50,484
set object 36 rect from 0,490 to 50,498
set object 37 rect from 0,504 to 50,512
set object 38 rect from 0,518 to 50,526
set object 39 rect from 0,532 to 50,540
set object 40 rect from 0,546 to 50,554
set object 41 rect from 0,560 to 50,568
set object 42 rect from 0,574 to 50,582
set object 43 rect from 0,588 to 50,596
set object 44 rect from 0,602 to 50,610
set object 45 rect from 0,616 to 50,624
set object 46 rect from 0,630 to 50,638
set object 47 rect from 0,644 to 50,652
set object 48 rect from 0,658 to 50,666
set object 49 rect from 0,672 to 50,680
set object 50 rect from 0,686 to 50,694
plot [][-7.000000:707.000000]\
     "run.1.stepagentactionwtime" using 2:(($3*2)+0) title "" w line lt 1,\
     "run.1.stepagentactionwtime" using 2:(($4*2)+14) title "" w line lt 1,\
     "run.1.stepagentactionwtime" using 2:(($5*2)+28) title "" w line lt 1,\
     "run.1.stepagentactionwtime" using 2:(($6*2)+42) title "" w line lt 1,\
     "run.1.stepagentactionwtime" using 2:(($7*2)+56) title "" w line lt 1,\
     "run.1.stepagentactionwtime" using 2:(($8*2)+70) title "" w line lt 1,\
     "run.1.stepagentactionwtime" using 2:(($9*2)+84) title "" w line lt 1,\
     "run.1.stepagentactionwtime" using 2:(($10*2)+98) title "" w line lt 1,\
     "run.1.stepagentactionwtime" using 2:(($11*2)+112) title "" w line lt 1,\
     "run.1.stepagentactionwtime" using 2:(($12*2)+126) title "" w line lt 1,\
     "run.1.stepagentactionwtime" using 2:(($13*2)+140) title "" w line lt 1,\
     "run.1.stepagentactionwtime" using 2:(($14*2)+154) title "" w line lt 1,\
     "run.1.stepagentactionwtime" using 2:(($15*2)+168) title "" w line lt 1,\
     "run.1.stepagentactionwtime" using 2:(($16*2)+182) title "" w line lt 1,\
     "run.1.stepagentactionwtime" using 2:(($17*2)+196) title "" w line lt 1,\
     "run.1.stepagentactionwtime" using 2:(($18*2)+210) title "" w line lt 1,\
     "run.1.stepagentactionwtime" using 2:(($19*2)+224) title "" w line lt 1,\
     "run.1.stepagentactionwtime" using 2:(($20*2)+238) title "" w line lt 1,\
     "run.1.stepagentactionwtime" using 2:(($21*2)+252) title "" w line lt 1,\
     "run.1.stepagentactionwtime" using 2:(($22*2)+266) title "" w line lt 1,\
     "run.1.stepagentactionwtime" using 2:(($23*2)+280) title "" w line lt 1,\
     "run.1.stepagentactionwtime" using 2:(($24*2)+294) title "" w line lt 1,\
     "run.1.stepagentactionwtime" using 2:(($25*2)+308) title "" w line lt 1,\
     "run.1.stepagentactionwtime" using 2:(($26*2)+322) title "" w line lt 1,\
     "run.1.stepagentactionwtime" using 2:(($27*2)+336) title "" w line lt 1,\
     "run.1.stepagentactionwtime" using 2:(($28*2)+350) title "" w line lt 1,\
     "run.1.stepagentactionwtime" using 2:(($29*2)+364) title "" w line lt 1,\
     "run.1.stepagentactionwtime" using 2:(($30*2)+378) title "" w line lt 1,\
     "run.1.stepagentactionwtime" using 2:(($31*2)+392) title "" w line lt 1,\
     "run.1.stepagentactionwtime" using 2:(($32*2)+406) title "" w line lt 1,\
     "run.1.stepagentactionwtime" using 2:(($33*2)+420) title "" w line lt 1,\
     "run.1.stepagentactionwtime" using 2:(($34*2)+434) title "" w line lt 1,\
     "run.1.stepagentactionwtime" using 2:(($35*2)+448) title "" w line lt 1,\
     "run.1.stepagentactionwtime" using 2:(($36*2)+462) title "" w line lt 1,\
     "run.1.stepagentactionwtime" using 2:(($37*2)+476) title "" w line lt 1,\
     "run.1.stepagentactionwtime" using 2:(($38*2)+490) title "" w line lt 1,\
     "run.1.stepagentactionwtime" using 2:(($39*2)+504) title "" w line lt 1,\
     "run.1.stepagentactionwtime" using 2:(($40*2)+518) title "" w line lt 1,\
     "run.1.stepagentactionwtime" using 2:(($41*2)+532) title "" w line lt 1,\
     "run.1.stepagentactionwtime" using 2:(($42*2)+546) title "" w line lt 1,\
     "run.1.stepagentactionwtime" using 2:(($43*2)+560) title "" w line lt 1,\
     "run.1.stepagentactionwtime" using 2:(($44*2)+574) title "" w line lt 1,\
     "run.1.stepagentactionwtime" using 2:(($45*2)+588) title "" w line lt 1,\
     "run.1.stepagentactionwtime" using 2:(($46*2)+602) title "" w line lt 1,\
     "run.1.stepagentactionwtime" using 2:(($47*2)+616) title "" w line lt 1,\
     "run.1.stepagentactionwtime" using 2:(($48*2)+630) title "" w line lt 1,\
     "run.1.stepagentactionwtime" using 2:(($49*2)+644) title "" w line lt 1,\
     "run.1.stepagentactionwtime" using 2:(($50*2)+658) title "" w line lt 1,\
     "run.1.stepagentactionwtime" using 2:(($51*2)+672) title "" w line lt 1,\
     "run.1.stepagentactionwtime" using 2:(($52*2)+686) title "" w line lt 1

unset object 1
unset object 2
unset object 3
unset object 4
unset object 5
unset object 6
unset object 7
unset object 8
unset object 9
unset object 10
unset object 11
unset object 12
unset object 13
unset object 14
unset object 15
unset object 16
unset object 17
unset object 18
unset object 19
unset object 20
unset object 21
unset object 22
unset object 23
unset object 24
unset object 25
unset object 26
unset object 27
unset object 28
unset object 29
unset object 30
unset object 31
unset object 32
unset object 33
unset object 34
unset object 35
unset object 36
unset object 37
unset object 38
unset object 39
unset object 40
unset object 41
unset object 42
unset object 43
unset object 44
unset object 45
unset object 46
unset object 47
unset object 48
unset object 49
unset object 50
set term post eps color
set size ratio 0.5
set output "run.1.finalagent.count.eps"
set xtics
set ytics
set xlabel "Agent"
set ylabel "Count"
set title "Number of times acted on each task"
plot [-1:60.000000][0:55.000000]\
     "run.1.finalagent" using 2:5 title "N" w points pt 1 ps 2 lw 2 lc 1,\
     "run.1.finalagent" using 2:6 title "E" w points pt 2 ps 2 lw 2 lc 2,\
     "run.1.finalagent" using 2:7 title "S" w points pt 4 ps 2 lw 2 lc 3,\
     "run.1.finalagent" using 2:8 title "W" w points pt 6 ps 2 lw 2 lc 4,\
     "run.1.finalagent" using 2:4 title "I" w points pt 8 ps 2 lc 7
unset xlabel
unset ylabel
unset title
unset size

set term post eps color
set size ratio 0.5
set output "run.1.finalagent.thresh.eps"
set xtics
set ytics
set xlabel "Agent"
set ylabel "Threshold"
set title "Final threshold for each task, Range = 10.000000"
plot [-1:60.000000][0:11.000000]\
     "run.1.finalagent" using 2:10 title "N" w points pt 1 ps 2 lw 2 lc 1,\
     "run.1.finalagent" using 2:11 title "E" w points pt 2 ps 2 lw 2 lc 2,\
     "run.1.finalagent" using 2:12 title "S" w points pt 4 ps 2 lw 2 lc 3,\
     "run.1.finalagent" using 2:13 title "W" w points pt 6 ps 2 lw 2 lc 4
unset xlabel
unset ylabel
unset title
unset size

set term post eps color
set size ratio 0.5
set output "run.1.finalagent.switch.eps"
set xtics
set ytics
set xlabel "Agent"
set ylabel "Number of switches"
set title "Number of task switches during run"
plot [-1:60.000000][0:55.000000]\
     "run.1.finalagent" using 2:15 title "N" w points pt 7 ps 2 lc 1
unset xlabel
unset ylabel
unset title
unset size

set term post eps color
set size ratio 0.5
set output "run.1.finalagent.spontaneousswitch.eps"
set xtics
set ytics
set xlabel "Agent"
set ylabel "Number of spontaneous switches"
set title "Number of task switches due to spontaneous response prob during run"
plot [-1:60.000000][0:55.000000]\
     "run.1.finalagent" using 2:17 title "N" w points pt 7 ps 2 lc 1
unset xlabel
unset ylabel
unset title
unset size

set term post eps color
set size ratio 0.5
set output "run.1.finalagent.response_prob.eps"
set xtics
set ytics
set xlabel "Agent"
set ylabel "Response prob Value"
set title "Agent Response prob Values"
plot [-1:55.000000][0:1]\
     "run.1.finalagent" using 2:21 title "N" w points pt 7 ps 2 lc 1
unset xlabel
unset ylabel
unset title
unset size

set term post eps color
set size ratio 0.5
set output "run.1.finalagent.spontaneous_response_prob.eps"
set xtics
set ytics
set xlabel "Agent"
set ylabel "Spontaneous Value"
set title "Agent Spontaneous Values"
plot [-1:55.000000][0:1]\
     "run.1.finalagent" using 2:23 title "N" w points pt 7 ps 2 lc 1
unset xlabel
unset ylabel
unset title
unset size


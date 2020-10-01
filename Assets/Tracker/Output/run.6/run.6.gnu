set term post eps color
set xlabel "Timestep"
set ylabel "Distance"
set output "run.6.stepdemandnorth.eps"
set title "Demand and delivered, North"
plot "run.6.stepdemand" using 2:5 title "Demand"  w lines,\
     "run.6.stepdemand" using 2:14 title "Delivered" w lines
set output "run.6.stepdemandsouth.eps"
set title "Demand and delivered, South"
plot "run.6.stepdemand" using 2:7 title "Demand"  w lines,\
     "run.6.stepdemand" using 2:16 title "Delivered" w lines
set output "run.6.stepdemandeast.eps"
set title "Demand and delivered, East"
plot "run.6.stepdemand" using 2:9 title "Demand"  w lines,\
     "run.6.stepdemand" using 2:18 title "Delivered" w lines
set output "run.6.stepdemandwest.eps"
set title "Demand and delivered, West"
plot "run.6.stepdemand" using 2:11 title "Demand"  w lines,\
     "run.6.stepdemand" using 2:20 title "Delivered" w lines
unset size
unset title

set term post eps color
set output "run.6.stepsummary.steplen.eps"
set title "Length of each step"
set xlabel "Timestep"
set ylabel "Step length"
plot [-2:] "run.6.stepsummary" using 2:18 title "Target" w line,\
     "run.6.stepsummary" using 2:20 title "Tracker" w line lc 3
unset xlabel
unset ylabel
unset title

set term post eps color
set size square
set output "run.6.stepsummary.paths.linesp.eps"
set title "Target and Tracker paths"
plot\
     "run.6.stepsummary" using 4:5 title "Target" w linesp,\
     "run.6.stepsummary" using 7:8 title "Tracker" w linesp lc 3
unset size
unset title

set term post eps color
set size square
set output "run.6.stepsummary.paths.line.eps"
set size ratio -1
set title "Target and Tracker paths"
plot\
     "run.6.stepsummary" using 4:5 title "Target" w line,\
     "run.6.stepsummary" using 7:8 title "Tracker" w line lc 3
unset size
unset title

set term post eps color
set size ratio 0.5
set output "run.6.stepsummary.dist.eps"
set title "Distance between Target and Tracker"
set xlabel "Timestep"
set ylabel "Distance between target and tracker"
plot [-2:] "run.6.stepsummary" using 2:10 w impulse
unset size
unset xlabel
unset ylabel
unset title

set term post eps color
set size ratio 0.5
set xlabel "Timestep"
set ylabel "Number of agents"
set output "run.6.stepsummary.pushnorth.eps"
set title "Number of agents pushing north"
plot [-2:][0:100] "run.6.stepsummary" using 2:23 w impulse
set output "run.6.stepsummary.pusheast.eps"
set title "Number of agents pushing east"
plot [-2:][0:100] "run.6.stepsummary" using 2:25 w impulse
set output "run.6.stepsummary.pushsouth.eps"
set title "Number of agents pushing south"
plot [-2:][0:100] "run.6.stepsummary" using 2:27 w impulse
set output "run.6.stepsummary.pushwest.eps"
set title "Number of agents pushing west"
plot [-2:][0:100] "run.6.stepsummary" using 2:29 w impulse
set output "run.6.stepsummary.pushnone.eps"
set title "Number of idle agents"
plot [-2:][0:100] "run.6.stepsummary" using 2:31 w impulse
set output "run.6.stepsummary.pushall.eps"
set title "Total number of agents pushing"
plot [-2:][0:100] "run.6.stepsummary" using 2:($23+$25+$27+$29) w impulse
unset size
unset xlabel
unset ylabel
unset title

set term post eps color
set size square
set output "run.6.initpop.rawthresh.eps"
set xtics ("N" 1, "E" 2, "S" 3, "W" 4)
set ylabel "Raw thresholds"
set title "Initial population thresholds - raw"
plot [0:5][0:1.2]\
     "run.6.initpop" using 23:5 w points,\
     "run.6.initpop" using 24:7 w points,\
     "run.6.initpop" using 25:9 w points,\
     "run.6.initpop" using 26:11 w points,\
     1.0 title "" lt 1 lc 7
unset size
unset ylabel
unset xtics
set xtics

set term post eps color
set size square
set output "run.6.initpop.scaledthresh.eps"
set xtics ("N" 1, "E" 2, "S" 3, "W" 4)
set ylabel "Scaled thresholds"
set title "Initial population thresholds - scaled"
plot [0:5][0:12.000000]\
     "run.6.initpop" using 23:16 w points,\
     "run.6.initpop" using 24:18 w points,\
     "run.6.initpop" using 25:20 w points,\
     "run.6.initpop" using 26:22 w points,\
     10.000000 title "" lt 1 lc 7
unset size
unset ylabel
unset xtics
unset title
set xtics

set term post eps color
set size square
set output "run.6.finalpop.scaledthresh.eps"
set xtics ("N" 1, "E" 2, "S" 3, "W" 4)
set ylabel "Scaled thresholds"
set title "Initial population thresholds - scaled"
plot [0:5][0:12.000000]\
     "run.6.finalpop" using 23:16 w points,\
     "run.6.finalpop" using 24:18 w points,\
     "run.6.finalpop" using 25:20 w points,\
     "run.6.finalpop" using 26:22 w points,\
     10.000000 title "" lt 1 lc 7
unset size
unset ylabel
unset xtics
unset title
set xtics

set term post eps color
set size ratio 0.5
set output "run.6.stepnorthsouth.loc.eps"
set title "North/south locations"
set xlabel "Timestep"
set ylabel "y-coordinate"
plot "run.6.stepnorthsouth" using 2:4 title "Target" w line,\
     "run.6.stepnorthsouth" using 2:6 title "Tracker" w line lc 3
unset size

set term post eps color
set size ratio 0.5
set output "run.6.stepnorthsouth.diff.eps"
set title "North/south difference, Target loc - Tracker loc"
set xlabel "Timestep"
set ylabel "Difference on y-axis"
plot "run.6.stepnorthsouth" using 2:8 title "Target" w impulse
unset size
unset xlabel
unset ylabel
unset title

set term post eps color
set size ratio 0.5
set output "run.6.stepeastwest.loc.eps"
set title "East/west locations"
set xlabel "Timestep"
set ylabel "x-coordinate"
plot "run.6.stepeastwest" using 2:4 title "Target" w line,\
     "run.6.stepeastwest" using 2:6 title "Tracker" w line lc 3
unset size

set term post eps color
set size ratio 0.5
set output "run.6.stepeastwest.diff.eps"
set title "East/west difference, Target loc - Tracker loc"
set xlabel "Timestep"
set ylabel "Difference on x-axis"
plot "run.6.stepeastwest" using 2:8 title "Target" w impulse
unset size
unset xlabel
unset ylabel
unset title

set term post eps color
set size ratio 2.000000
set output "run.6.stepagentaction.eps"
set title "Agent actions, 1=N 2=E 3=S 4=W"
set xlabel "Agent"
set ylabel "Timestep"
set palette maxcolors 5
set palette defined (0 "white", 1 "blue", 2 "yellow", 3 "red", 4 "green")
set cbrange[-0.5:4.5]
set view map
plot [][201:-2] "run.6.stepagentaction" matrix w image

set term post eps
set style rectangle fc rgb "light-blue" fs solid noborder
set size ratio 2
set output "run.6.stepagentactionwtime.eps"
set title "Agent actions\n0=idle, 1=N, 2=E, 3=S, 4=W"
set xlabel "Timestep"
unset ytics
unset ylabel
set object 1 rect from 0,0 to 200,8
set object 2 rect from 0,14 to 200,22
set object 3 rect from 0,28 to 200,36
set object 4 rect from 0,42 to 200,50
set object 5 rect from 0,56 to 200,64
set object 6 rect from 0,70 to 200,78
set object 7 rect from 0,84 to 200,92
set object 8 rect from 0,98 to 200,106
set object 9 rect from 0,112 to 200,120
set object 10 rect from 0,126 to 200,134
set object 11 rect from 0,140 to 200,148
set object 12 rect from 0,154 to 200,162
set object 13 rect from 0,168 to 200,176
set object 14 rect from 0,182 to 200,190
set object 15 rect from 0,196 to 200,204
set object 16 rect from 0,210 to 200,218
set object 17 rect from 0,224 to 200,232
set object 18 rect from 0,238 to 200,246
set object 19 rect from 0,252 to 200,260
set object 20 rect from 0,266 to 200,274
set object 21 rect from 0,280 to 200,288
set object 22 rect from 0,294 to 200,302
set object 23 rect from 0,308 to 200,316
set object 24 rect from 0,322 to 200,330
set object 25 rect from 0,336 to 200,344
set object 26 rect from 0,350 to 200,358
set object 27 rect from 0,364 to 200,372
set object 28 rect from 0,378 to 200,386
set object 29 rect from 0,392 to 200,400
set object 30 rect from 0,406 to 200,414
set object 31 rect from 0,420 to 200,428
set object 32 rect from 0,434 to 200,442
set object 33 rect from 0,448 to 200,456
set object 34 rect from 0,462 to 200,470
set object 35 rect from 0,476 to 200,484
set object 36 rect from 0,490 to 200,498
set object 37 rect from 0,504 to 200,512
set object 38 rect from 0,518 to 200,526
set object 39 rect from 0,532 to 200,540
set object 40 rect from 0,546 to 200,554
set object 41 rect from 0,560 to 200,568
set object 42 rect from 0,574 to 200,582
set object 43 rect from 0,588 to 200,596
set object 44 rect from 0,602 to 200,610
set object 45 rect from 0,616 to 200,624
set object 46 rect from 0,630 to 200,638
set object 47 rect from 0,644 to 200,652
set object 48 rect from 0,658 to 200,666
set object 49 rect from 0,672 to 200,680
set object 50 rect from 0,686 to 200,694
set object 51 rect from 0,700 to 200,708
set object 52 rect from 0,714 to 200,722
set object 53 rect from 0,728 to 200,736
set object 54 rect from 0,742 to 200,750
set object 55 rect from 0,756 to 200,764
set object 56 rect from 0,770 to 200,778
set object 57 rect from 0,784 to 200,792
set object 58 rect from 0,798 to 200,806
set object 59 rect from 0,812 to 200,820
set object 60 rect from 0,826 to 200,834
set object 61 rect from 0,840 to 200,848
set object 62 rect from 0,854 to 200,862
set object 63 rect from 0,868 to 200,876
set object 64 rect from 0,882 to 200,890
set object 65 rect from 0,896 to 200,904
set object 66 rect from 0,910 to 200,918
set object 67 rect from 0,924 to 200,932
set object 68 rect from 0,938 to 200,946
set object 69 rect from 0,952 to 200,960
set object 70 rect from 0,966 to 200,974
set object 71 rect from 0,980 to 200,988
set object 72 rect from 0,994 to 200,1002
set object 73 rect from 0,1008 to 200,1016
set object 74 rect from 0,1022 to 200,1030
set object 75 rect from 0,1036 to 200,1044
set object 76 rect from 0,1050 to 200,1058
set object 77 rect from 0,1064 to 200,1072
set object 78 rect from 0,1078 to 200,1086
set object 79 rect from 0,1092 to 200,1100
set object 80 rect from 0,1106 to 200,1114
set object 81 rect from 0,1120 to 200,1128
set object 82 rect from 0,1134 to 200,1142
set object 83 rect from 0,1148 to 200,1156
set object 84 rect from 0,1162 to 200,1170
set object 85 rect from 0,1176 to 200,1184
set object 86 rect from 0,1190 to 200,1198
set object 87 rect from 0,1204 to 200,1212
set object 88 rect from 0,1218 to 200,1226
set object 89 rect from 0,1232 to 200,1240
set object 90 rect from 0,1246 to 200,1254
set object 91 rect from 0,1260 to 200,1268
set object 92 rect from 0,1274 to 200,1282
set object 93 rect from 0,1288 to 200,1296
set object 94 rect from 0,1302 to 200,1310
set object 95 rect from 0,1316 to 200,1324
set object 96 rect from 0,1330 to 200,1338
set object 97 rect from 0,1344 to 200,1352
set object 98 rect from 0,1358 to 200,1366
set object 99 rect from 0,1372 to 200,1380
set object 100 rect from 0,1386 to 200,1394
plot [][-14.000000:1414.000000]\
     "run.6.stepagentactionwtime" using 2:(($3*2)+0) title "" w line lt 1,\
     "run.6.stepagentactionwtime" using 2:(($4*2)+14) title "" w line lt 1,\
     "run.6.stepagentactionwtime" using 2:(($5*2)+28) title "" w line lt 1,\
     "run.6.stepagentactionwtime" using 2:(($6*2)+42) title "" w line lt 1,\
     "run.6.stepagentactionwtime" using 2:(($7*2)+56) title "" w line lt 1,\
     "run.6.stepagentactionwtime" using 2:(($8*2)+70) title "" w line lt 1,\
     "run.6.stepagentactionwtime" using 2:(($9*2)+84) title "" w line lt 1,\
     "run.6.stepagentactionwtime" using 2:(($10*2)+98) title "" w line lt 1,\
     "run.6.stepagentactionwtime" using 2:(($11*2)+112) title "" w line lt 1,\
     "run.6.stepagentactionwtime" using 2:(($12*2)+126) title "" w line lt 1,\
     "run.6.stepagentactionwtime" using 2:(($13*2)+140) title "" w line lt 1,\
     "run.6.stepagentactionwtime" using 2:(($14*2)+154) title "" w line lt 1,\
     "run.6.stepagentactionwtime" using 2:(($15*2)+168) title "" w line lt 1,\
     "run.6.stepagentactionwtime" using 2:(($16*2)+182) title "" w line lt 1,\
     "run.6.stepagentactionwtime" using 2:(($17*2)+196) title "" w line lt 1,\
     "run.6.stepagentactionwtime" using 2:(($18*2)+210) title "" w line lt 1,\
     "run.6.stepagentactionwtime" using 2:(($19*2)+224) title "" w line lt 1,\
     "run.6.stepagentactionwtime" using 2:(($20*2)+238) title "" w line lt 1,\
     "run.6.stepagentactionwtime" using 2:(($21*2)+252) title "" w line lt 1,\
     "run.6.stepagentactionwtime" using 2:(($22*2)+266) title "" w line lt 1,\
     "run.6.stepagentactionwtime" using 2:(($23*2)+280) title "" w line lt 1,\
     "run.6.stepagentactionwtime" using 2:(($24*2)+294) title "" w line lt 1,\
     "run.6.stepagentactionwtime" using 2:(($25*2)+308) title "" w line lt 1,\
     "run.6.stepagentactionwtime" using 2:(($26*2)+322) title "" w line lt 1,\
     "run.6.stepagentactionwtime" using 2:(($27*2)+336) title "" w line lt 1,\
     "run.6.stepagentactionwtime" using 2:(($28*2)+350) title "" w line lt 1,\
     "run.6.stepagentactionwtime" using 2:(($29*2)+364) title "" w line lt 1,\
     "run.6.stepagentactionwtime" using 2:(($30*2)+378) title "" w line lt 1,\
     "run.6.stepagentactionwtime" using 2:(($31*2)+392) title "" w line lt 1,\
     "run.6.stepagentactionwtime" using 2:(($32*2)+406) title "" w line lt 1,\
     "run.6.stepagentactionwtime" using 2:(($33*2)+420) title "" w line lt 1,\
     "run.6.stepagentactionwtime" using 2:(($34*2)+434) title "" w line lt 1,\
     "run.6.stepagentactionwtime" using 2:(($35*2)+448) title "" w line lt 1,\
     "run.6.stepagentactionwtime" using 2:(($36*2)+462) title "" w line lt 1,\
     "run.6.stepagentactionwtime" using 2:(($37*2)+476) title "" w line lt 1,\
     "run.6.stepagentactionwtime" using 2:(($38*2)+490) title "" w line lt 1,\
     "run.6.stepagentactionwtime" using 2:(($39*2)+504) title "" w line lt 1,\
     "run.6.stepagentactionwtime" using 2:(($40*2)+518) title "" w line lt 1,\
     "run.6.stepagentactionwtime" using 2:(($41*2)+532) title "" w line lt 1,\
     "run.6.stepagentactionwtime" using 2:(($42*2)+546) title "" w line lt 1,\
     "run.6.stepagentactionwtime" using 2:(($43*2)+560) title "" w line lt 1,\
     "run.6.stepagentactionwtime" using 2:(($44*2)+574) title "" w line lt 1,\
     "run.6.stepagentactionwtime" using 2:(($45*2)+588) title "" w line lt 1,\
     "run.6.stepagentactionwtime" using 2:(($46*2)+602) title "" w line lt 1,\
     "run.6.stepagentactionwtime" using 2:(($47*2)+616) title "" w line lt 1,\
     "run.6.stepagentactionwtime" using 2:(($48*2)+630) title "" w line lt 1,\
     "run.6.stepagentactionwtime" using 2:(($49*2)+644) title "" w line lt 1,\
     "run.6.stepagentactionwtime" using 2:(($50*2)+658) title "" w line lt 1,\
     "run.6.stepagentactionwtime" using 2:(($51*2)+672) title "" w line lt 1,\
     "run.6.stepagentactionwtime" using 2:(($52*2)+686) title "" w line lt 1,\
     "run.6.stepagentactionwtime" using 2:(($53*2)+700) title "" w line lt 1,\
     "run.6.stepagentactionwtime" using 2:(($54*2)+714) title "" w line lt 1,\
     "run.6.stepagentactionwtime" using 2:(($55*2)+728) title "" w line lt 1,\
     "run.6.stepagentactionwtime" using 2:(($56*2)+742) title "" w line lt 1,\
     "run.6.stepagentactionwtime" using 2:(($57*2)+756) title "" w line lt 1,\
     "run.6.stepagentactionwtime" using 2:(($58*2)+770) title "" w line lt 1,\
     "run.6.stepagentactionwtime" using 2:(($59*2)+784) title "" w line lt 1,\
     "run.6.stepagentactionwtime" using 2:(($60*2)+798) title "" w line lt 1,\
     "run.6.stepagentactionwtime" using 2:(($61*2)+812) title "" w line lt 1,\
     "run.6.stepagentactionwtime" using 2:(($62*2)+826) title "" w line lt 1,\
     "run.6.stepagentactionwtime" using 2:(($63*2)+840) title "" w line lt 1,\
     "run.6.stepagentactionwtime" using 2:(($64*2)+854) title "" w line lt 1,\
     "run.6.stepagentactionwtime" using 2:(($65*2)+868) title "" w line lt 1,\
     "run.6.stepagentactionwtime" using 2:(($66*2)+882) title "" w line lt 1,\
     "run.6.stepagentactionwtime" using 2:(($67*2)+896) title "" w line lt 1,\
     "run.6.stepagentactionwtime" using 2:(($68*2)+910) title "" w line lt 1,\
     "run.6.stepagentactionwtime" using 2:(($69*2)+924) title "" w line lt 1,\
     "run.6.stepagentactionwtime" using 2:(($70*2)+938) title "" w line lt 1,\
     "run.6.stepagentactionwtime" using 2:(($71*2)+952) title "" w line lt 1,\
     "run.6.stepagentactionwtime" using 2:(($72*2)+966) title "" w line lt 1,\
     "run.6.stepagentactionwtime" using 2:(($73*2)+980) title "" w line lt 1,\
     "run.6.stepagentactionwtime" using 2:(($74*2)+994) title "" w line lt 1,\
     "run.6.stepagentactionwtime" using 2:(($75*2)+1008) title "" w line lt 1,\
     "run.6.stepagentactionwtime" using 2:(($76*2)+1022) title "" w line lt 1,\
     "run.6.stepagentactionwtime" using 2:(($77*2)+1036) title "" w line lt 1,\
     "run.6.stepagentactionwtime" using 2:(($78*2)+1050) title "" w line lt 1,\
     "run.6.stepagentactionwtime" using 2:(($79*2)+1064) title "" w line lt 1,\
     "run.6.stepagentactionwtime" using 2:(($80*2)+1078) title "" w line lt 1,\
     "run.6.stepagentactionwtime" using 2:(($81*2)+1092) title "" w line lt 1,\
     "run.6.stepagentactionwtime" using 2:(($82*2)+1106) title "" w line lt 1,\
     "run.6.stepagentactionwtime" using 2:(($83*2)+1120) title "" w line lt 1,\
     "run.6.stepagentactionwtime" using 2:(($84*2)+1134) title "" w line lt 1,\
     "run.6.stepagentactionwtime" using 2:(($85*2)+1148) title "" w line lt 1,\
     "run.6.stepagentactionwtime" using 2:(($86*2)+1162) title "" w line lt 1,\
     "run.6.stepagentactionwtime" using 2:(($87*2)+1176) title "" w line lt 1,\
     "run.6.stepagentactionwtime" using 2:(($88*2)+1190) title "" w line lt 1,\
     "run.6.stepagentactionwtime" using 2:(($89*2)+1204) title "" w line lt 1,\
     "run.6.stepagentactionwtime" using 2:(($90*2)+1218) title "" w line lt 1,\
     "run.6.stepagentactionwtime" using 2:(($91*2)+1232) title "" w line lt 1,\
     "run.6.stepagentactionwtime" using 2:(($92*2)+1246) title "" w line lt 1,\
     "run.6.stepagentactionwtime" using 2:(($93*2)+1260) title "" w line lt 1,\
     "run.6.stepagentactionwtime" using 2:(($94*2)+1274) title "" w line lt 1,\
     "run.6.stepagentactionwtime" using 2:(($95*2)+1288) title "" w line lt 1,\
     "run.6.stepagentactionwtime" using 2:(($96*2)+1302) title "" w line lt 1,\
     "run.6.stepagentactionwtime" using 2:(($97*2)+1316) title "" w line lt 1,\
     "run.6.stepagentactionwtime" using 2:(($98*2)+1330) title "" w line lt 1,\
     "run.6.stepagentactionwtime" using 2:(($99*2)+1344) title "" w line lt 1,\
     "run.6.stepagentactionwtime" using 2:(($100*2)+1358) title "" w line lt 1,\
     "run.6.stepagentactionwtime" using 2:(($101*2)+1372) title "" w line lt 1,\
     "run.6.stepagentactionwtime" using 2:(($102*2)+1386) title "" w line lt 1

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
unset object 51
unset object 52
unset object 53
unset object 54
unset object 55
unset object 56
unset object 57
unset object 58
unset object 59
unset object 60
unset object 61
unset object 62
unset object 63
unset object 64
unset object 65
unset object 66
unset object 67
unset object 68
unset object 69
unset object 70
unset object 71
unset object 72
unset object 73
unset object 74
unset object 75
unset object 76
unset object 77
unset object 78
unset object 79
unset object 80
unset object 81
unset object 82
unset object 83
unset object 84
unset object 85
unset object 86
unset object 87
unset object 88
unset object 89
unset object 90
unset object 91
unset object 92
unset object 93
unset object 94
unset object 95
unset object 96
unset object 97
unset object 98
unset object 99
unset object 100
set term post eps color
set size ratio 0.5
set output "run.6.finalagent.count.eps"
set xtics
set ytics
set xlabel "Agent"
set ylabel "Count"
set title "Number of times acted on each task"
plot [-1:120.000000][0:220.000000]\
     "run.6.finalagent" using 2:5 title "N" w points pt 1 ps 2 lw 2 lc 1,\
     "run.6.finalagent" using 2:6 title "E" w points pt 2 ps 2 lw 2 lc 2,\
     "run.6.finalagent" using 2:7 title "S" w points pt 4 ps 2 lw 2 lc 3,\
     "run.6.finalagent" using 2:8 title "W" w points pt 6 ps 2 lw 2 lc 4,\
     "run.6.finalagent" using 2:4 title "I" w points pt 8 ps 2 lc 7
unset xlabel
unset ylabel
unset title
unset size

set term post eps color
set size ratio 0.5
set output "run.6.finalagent.thresh.eps"
set xtics
set ytics
set xlabel "Agent"
set ylabel "Threshold"
set title "Final threshold for each task, Range = 10.000000"
plot [-1:120.000000][0:11.000000]\
     "run.6.finalagent" using 2:10 title "N" w points pt 1 ps 2 lw 2 lc 1,\
     "run.6.finalagent" using 2:11 title "E" w points pt 2 ps 2 lw 2 lc 2,\
     "run.6.finalagent" using 2:12 title "S" w points pt 4 ps 2 lw 2 lc 3,\
     "run.6.finalagent" using 2:13 title "W" w points pt 6 ps 2 lw 2 lc 4
unset xlabel
unset ylabel
unset title
unset size

set term post eps color
set size ratio 0.5
set output "run.6.finalagent.switch.eps"
set xtics
set ytics
set xlabel "Agent"
set ylabel "Number of switches"
set title "Number of task switches during run"
plot [-1:120.000000][0:220.000000]\
     "run.6.finalagent" using 2:15 title "N" w points pt 7 ps 2 lc 1
unset xlabel
unset ylabel
unset title
unset size

set term post eps color
set size ratio 0.5
set output "run.6.finalagent.spontaneousswitch.eps"
set xtics
set ytics
set xlabel "Agent"
set ylabel "Number of spontaneous switches"
set title "Number of task switches due to spontaneous response prob during run"
plot [-1:120.000000][0:220.000000]\
     "run.6.finalagent" using 2:17 title "N" w points pt 7 ps 2 lc 1
unset xlabel
unset ylabel
unset title
unset size

set term post eps color
set size ratio 0.5
set output "run.6.finalagent.response_prob.eps"
set xtics
set ytics
set xlabel "Agent"
set ylabel "Response prob Value"
set title "Agent Response prob Values"
plot [-1:110.000000][0:1]\
     "run.6.finalagent" using 2:21 title "N" w points pt 7 ps 2 lc 1
unset xlabel
unset ylabel
unset title
unset size

set term post eps color
set size ratio 0.5
set output "run.6.finalagent.spontaneous_response_prob.eps"
set xtics
set ytics
set xlabel "Agent"
set ylabel "Spontaneous Value"
set title "Agent Spontaneous Values"
plot [-1:110.000000][0:1]\
     "run.6.finalagent" using 2:23 title "N" w points pt 7 ps 2 lc 1
unset xlabel
unset ylabel
unset title
unset size


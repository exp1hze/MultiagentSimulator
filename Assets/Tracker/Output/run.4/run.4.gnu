set term post eps color
set xlabel "Timestep"
set ylabel "Distance"
set output "run.4.stepdemandnorth.eps"
set title "Demand and delivered, North"
plot "run.4.stepdemand" using 2:5 title "Demand"  w lines,\
     "run.4.stepdemand" using 2:14 title "Delivered" w lines
set output "run.4.stepdemandsouth.eps"
set title "Demand and delivered, South"
plot "run.4.stepdemand" using 2:7 title "Demand"  w lines,\
     "run.4.stepdemand" using 2:16 title "Delivered" w lines
set output "run.4.stepdemandeast.eps"
set title "Demand and delivered, East"
plot "run.4.stepdemand" using 2:9 title "Demand"  w lines,\
     "run.4.stepdemand" using 2:18 title "Delivered" w lines
set output "run.4.stepdemandwest.eps"
set title "Demand and delivered, West"
plot "run.4.stepdemand" using 2:11 title "Demand"  w lines,\
     "run.4.stepdemand" using 2:20 title "Delivered" w lines
unset size
unset title

set term post eps color
set output "run.4.stepsummary.steplen.eps"
set title "Length of each step"
set xlabel "Timestep"
set ylabel "Step length"
plot [-2:] "run.4.stepsummary" using 2:18 title "Target" w line,\
     "run.4.stepsummary" using 2:20 title "Tracker" w line lc 3
unset xlabel
unset ylabel
unset title

set term post eps color
set size ratio 0.5
set output "run.4.stepsummary.paths.linesp.eps"
set title "Target and Tracker paths"
plot\
     "run.4.stepsummary" using 4:5 title "Target" w linesp,\
     "run.4.stepsummary" using 7:8 title "Tracker" w linesp lc 3
unset size
unset title

set term post eps color
set size ratio 0.5
set output "run.4.stepsummary.paths.line.eps"
set size ratio -1
set title "Target and Tracker paths"
plot\
     "run.4.stepsummary" using 4:5 title "Target" w line,\
     "run.4.stepsummary" using 7:8 title "Tracker" w line lc 3
unset size
unset title

set term post eps color
set size ratio 0.5
set output "run.4.stepsummary.dist.eps"
set title "Distance between Target and Tracker"
set xlabel "Timestep"
set ylabel "Distance between target and tracker"
plot [-2:] "run.4.stepsummary" using 2:10 w impulse
unset size
unset xlabel
unset ylabel
unset title

set term post eps color
set size ratio 0.5
set xlabel "Timestep"
set ylabel "Number of agents"
set output "run.4.stepsummary.pushnorth.eps"
set title "Number of agents pushing north"
plot [-2:][0:200] "run.4.stepsummary" using 2:23 w impulse
set output "run.4.stepsummary.pusheast.eps"
set title "Number of agents pushing east"
plot [-2:][0:200] "run.4.stepsummary" using 2:25 w impulse
set output "run.4.stepsummary.pushsouth.eps"
set title "Number of agents pushing south"
plot [-2:][0:200] "run.4.stepsummary" using 2:27 w impulse
set output "run.4.stepsummary.pushwest.eps"
set title "Number of agents pushing west"
plot [-2:][0:200] "run.4.stepsummary" using 2:29 w impulse
set output "run.4.stepsummary.pushnone.eps"
set title "Number of idle agents"
plot [-2:][0:200] "run.4.stepsummary" using 2:31 w impulse
set output "run.4.stepsummary.pushall.eps"
set title "Total number of agents pushing"
plot [-2:][0:200] "run.4.stepsummary" using 2:($23+$25+$27+$29) w impulse
unset size
unset xlabel
unset ylabel
unset title

set term post eps color
set size square
set output "run.4.initpop.rawthresh.eps"
set xtics ("N" 1, "E" 2, "S" 3, "W" 4)
set ylabel "Raw thresholds"
set title "Initial population thresholds - raw"
plot [0:5][0:1.2]\
     "run.4.initpop" using 23:5 w points,\
     "run.4.initpop" using 24:7 w points,\
     "run.4.initpop" using 25:9 w points,\
     "run.4.initpop" using 26:11 w points,\
     1.0 title "" lt 1 lc 7
unset size
unset ylabel
unset xtics
set xtics

set term post eps color
set size square
set output "run.4.initpop.scaledthresh.eps"
set xtics ("N" 1, "E" 2, "S" 3, "W" 4)
set ylabel "Scaled thresholds"
set title "Initial population thresholds - scaled"
plot [0:5][0:12.000000]\
     "run.4.initpop" using 23:16 w points,\
     "run.4.initpop" using 24:18 w points,\
     "run.4.initpop" using 25:20 w points,\
     "run.4.initpop" using 26:22 w points,\
     10.000000 title "" lt 1 lc 7
unset size
unset ylabel
unset xtics
unset title
set xtics

set term post eps color
set size square
set output "run.4.finalpop.scaledthresh.eps"
set xtics ("N" 1, "E" 2, "S" 3, "W" 4)
set ylabel "Scaled thresholds"
set title "Initial population thresholds - scaled"
plot [0:5][0:12.000000]\
     "run.4.finalpop" using 23:16 w points,\
     "run.4.finalpop" using 24:18 w points,\
     "run.4.finalpop" using 25:20 w points,\
     "run.4.finalpop" using 26:22 w points,\
     10.000000 title "" lt 1 lc 7
unset size
unset ylabel
unset xtics
unset title
set xtics

set term post eps color
set size ratio 0.5
set output "run.4.stepnorthsouth.loc.eps"
set title "North/south locations"
set xlabel "Timestep"
set ylabel "y-coordinate"
plot "run.4.stepnorthsouth" using 2:4 title "Target" w line,\
     "run.4.stepnorthsouth" using 2:6 title "Tracker" w line lc 3
unset size

set term post eps color
set size ratio 0.5
set output "run.4.stepnorthsouth.diff.eps"
set title "North/south difference, Target loc - Tracker loc"
set xlabel "Timestep"
set ylabel "Difference on y-axis"
plot "run.4.stepnorthsouth" using 2:8 title "Target" w impulse
unset size
unset xlabel
unset ylabel
unset title

set term post eps color
set size ratio 0.5
set output "run.4.stepeastwest.loc.eps"
set title "East/west locations"
set xlabel "Timestep"
set ylabel "x-coordinate"
plot "run.4.stepeastwest" using 2:4 title "Target" w line,\
     "run.4.stepeastwest" using 2:6 title "Tracker" w line lc 3
unset size

set term post eps color
set size ratio 0.5
set output "run.4.stepeastwest.diff.eps"
set title "East/west difference, Target loc - Tracker loc"
set xlabel "Timestep"
set ylabel "Difference on x-axis"
plot "run.4.stepeastwest" using 2:8 title "Target" w impulse
unset size
unset xlabel
unset ylabel
unset title

set term post eps color
set size ratio 2.500000
set output "run.4.stepagentaction.eps"
set title "Agent actions, 1=N 2=E 3=S 4=W"
set xlabel "Agent"
set ylabel "Timestep"
set palette maxcolors 5
set palette defined (0 "white", 1 "blue", 2 "yellow", 3 "red", 4 "green")
set cbrange[-0.5:4.5]
set view map
plot [][501:-2] "run.4.stepagentaction" matrix w image

set term post eps color
set size ratio 2
set output "run.4.stepthreshnorth.eps"
set title "Agent thresholds: North"
set xlabel "Agent"
set ylabel "Timestep"
set palette maxcolors 100
set palette defined (0 "green", 5.000000 "yellow", 10.000000 "red")
set cbrange[0:10.000000]
set view map
plot [-20.000000:220.000000][501:-2] "run.4.stepthreshnorth" matrix title "" w image

set term post eps color
set size ratio 2
set output "run.4.stepthreshsouth.eps"
set title "Agent thresholds: South"
set xlabel "Agent"
set ylabel "Timestep"
set palette maxcolors 100
set palette defined (0 "green", 5.000000 "yellow", 10.000000 "red")
set cbrange[0:10.000000]
set view map
plot [-20.000000:220.000000][501:-2] "run.4.stepthreshsouth" matrix title "" w image

set term post eps color
set size ratio 2
set output "run.4.stepthresheast.eps"
set title "Agent thresholds: East"
set xlabel "Agent"
set ylabel "Timestep"
set palette maxcolors 100
set palette defined (0 "green", 5.000000 "yellow", 10.000000 "red")
set cbrange[0:10.000000]
set view map
plot [-20.000000:220.000000][501:-2] "run.4.stepthresheast" matrix title "" w image

set term post eps color
set size ratio 2
set output "run.4.stepthreshwest.eps"
set title "Agent thresholds: West"
set xlabel "Agent"
set ylabel "Timestep"
set palette maxcolors 100
set palette defined (0 "green", 5.000000 "yellow", 10.000000 "red")
set cbrange[0:10.000000]
set view map
plot [-20.000000:220.000000][501:-2] "run.4.stepthreshwest" matrix title "" w image

set term post eps
set size ratio 0.800000
set xlabel "Agent"
set ylabel "Threshold"
set output "run.4.threshrangenorth.eps"
set title "Agent threshold ranges: North"
plot "run.4.threshrange" using 2:4:5:6 title "" w errorbars
set output "run.4.threshrangesouth.eps"
set title "Agent threshold ranges: South"
plot "run.4.threshrange" using 2:8:9:10 title "" w errorbars
set output "run.4.threshrangeeast.eps"
set title "Agent threshold ranges: East"
plot "run.4.threshrange" using 2:12:13:14 title "" w errorbars
set output "run.4.threshrangewest.eps"
set title "Agent threshold ranges: West"
plot "run.4.threshrange" using 2:16:17:18 title "" w errorbars

set term post eps
set style rectangle fc rgb "light-blue" fs solid noborder
set size ratio 2
set output "run.4.stepagentactionwtime.eps"
set title "Agent actions\n0=idle, 1=N, 2=E, 3=S, 4=W"
set xlabel "Timestep"
unset ytics
unset ylabel
set object 1 rect from 0,0 to 500,8
set object 2 rect from 0,14 to 500,22
set object 3 rect from 0,28 to 500,36
set object 4 rect from 0,42 to 500,50
set object 5 rect from 0,56 to 500,64
set object 6 rect from 0,70 to 500,78
set object 7 rect from 0,84 to 500,92
set object 8 rect from 0,98 to 500,106
set object 9 rect from 0,112 to 500,120
set object 10 rect from 0,126 to 500,134
set object 11 rect from 0,140 to 500,148
set object 12 rect from 0,154 to 500,162
set object 13 rect from 0,168 to 500,176
set object 14 rect from 0,182 to 500,190
set object 15 rect from 0,196 to 500,204
set object 16 rect from 0,210 to 500,218
set object 17 rect from 0,224 to 500,232
set object 18 rect from 0,238 to 500,246
set object 19 rect from 0,252 to 500,260
set object 20 rect from 0,266 to 500,274
set object 21 rect from 0,280 to 500,288
set object 22 rect from 0,294 to 500,302
set object 23 rect from 0,308 to 500,316
set object 24 rect from 0,322 to 500,330
set object 25 rect from 0,336 to 500,344
set object 26 rect from 0,350 to 500,358
set object 27 rect from 0,364 to 500,372
set object 28 rect from 0,378 to 500,386
set object 29 rect from 0,392 to 500,400
set object 30 rect from 0,406 to 500,414
set object 31 rect from 0,420 to 500,428
set object 32 rect from 0,434 to 500,442
set object 33 rect from 0,448 to 500,456
set object 34 rect from 0,462 to 500,470
set object 35 rect from 0,476 to 500,484
set object 36 rect from 0,490 to 500,498
set object 37 rect from 0,504 to 500,512
set object 38 rect from 0,518 to 500,526
set object 39 rect from 0,532 to 500,540
set object 40 rect from 0,546 to 500,554
set object 41 rect from 0,560 to 500,568
set object 42 rect from 0,574 to 500,582
set object 43 rect from 0,588 to 500,596
set object 44 rect from 0,602 to 500,610
set object 45 rect from 0,616 to 500,624
set object 46 rect from 0,630 to 500,638
set object 47 rect from 0,644 to 500,652
set object 48 rect from 0,658 to 500,666
set object 49 rect from 0,672 to 500,680
set object 50 rect from 0,686 to 500,694
set object 51 rect from 0,700 to 500,708
set object 52 rect from 0,714 to 500,722
set object 53 rect from 0,728 to 500,736
set object 54 rect from 0,742 to 500,750
set object 55 rect from 0,756 to 500,764
set object 56 rect from 0,770 to 500,778
set object 57 rect from 0,784 to 500,792
set object 58 rect from 0,798 to 500,806
set object 59 rect from 0,812 to 500,820
set object 60 rect from 0,826 to 500,834
set object 61 rect from 0,840 to 500,848
set object 62 rect from 0,854 to 500,862
set object 63 rect from 0,868 to 500,876
set object 64 rect from 0,882 to 500,890
set object 65 rect from 0,896 to 500,904
set object 66 rect from 0,910 to 500,918
set object 67 rect from 0,924 to 500,932
set object 68 rect from 0,938 to 500,946
set object 69 rect from 0,952 to 500,960
set object 70 rect from 0,966 to 500,974
set object 71 rect from 0,980 to 500,988
set object 72 rect from 0,994 to 500,1002
set object 73 rect from 0,1008 to 500,1016
set object 74 rect from 0,1022 to 500,1030
set object 75 rect from 0,1036 to 500,1044
set object 76 rect from 0,1050 to 500,1058
set object 77 rect from 0,1064 to 500,1072
set object 78 rect from 0,1078 to 500,1086
set object 79 rect from 0,1092 to 500,1100
set object 80 rect from 0,1106 to 500,1114
set object 81 rect from 0,1120 to 500,1128
set object 82 rect from 0,1134 to 500,1142
set object 83 rect from 0,1148 to 500,1156
set object 84 rect from 0,1162 to 500,1170
set object 85 rect from 0,1176 to 500,1184
set object 86 rect from 0,1190 to 500,1198
set object 87 rect from 0,1204 to 500,1212
set object 88 rect from 0,1218 to 500,1226
set object 89 rect from 0,1232 to 500,1240
set object 90 rect from 0,1246 to 500,1254
set object 91 rect from 0,1260 to 500,1268
set object 92 rect from 0,1274 to 500,1282
set object 93 rect from 0,1288 to 500,1296
set object 94 rect from 0,1302 to 500,1310
set object 95 rect from 0,1316 to 500,1324
set object 96 rect from 0,1330 to 500,1338
set object 97 rect from 0,1344 to 500,1352
set object 98 rect from 0,1358 to 500,1366
set object 99 rect from 0,1372 to 500,1380
set object 100 rect from 0,1386 to 500,1394
set object 101 rect from 0,1400 to 500,1408
set object 102 rect from 0,1414 to 500,1422
set object 103 rect from 0,1428 to 500,1436
set object 104 rect from 0,1442 to 500,1450
set object 105 rect from 0,1456 to 500,1464
set object 106 rect from 0,1470 to 500,1478
set object 107 rect from 0,1484 to 500,1492
set object 108 rect from 0,1498 to 500,1506
set object 109 rect from 0,1512 to 500,1520
set object 110 rect from 0,1526 to 500,1534
set object 111 rect from 0,1540 to 500,1548
set object 112 rect from 0,1554 to 500,1562
set object 113 rect from 0,1568 to 500,1576
set object 114 rect from 0,1582 to 500,1590
set object 115 rect from 0,1596 to 500,1604
set object 116 rect from 0,1610 to 500,1618
set object 117 rect from 0,1624 to 500,1632
set object 118 rect from 0,1638 to 500,1646
set object 119 rect from 0,1652 to 500,1660
set object 120 rect from 0,1666 to 500,1674
set object 121 rect from 0,1680 to 500,1688
set object 122 rect from 0,1694 to 500,1702
set object 123 rect from 0,1708 to 500,1716
set object 124 rect from 0,1722 to 500,1730
set object 125 rect from 0,1736 to 500,1744
set object 126 rect from 0,1750 to 500,1758
set object 127 rect from 0,1764 to 500,1772
set object 128 rect from 0,1778 to 500,1786
set object 129 rect from 0,1792 to 500,1800
set object 130 rect from 0,1806 to 500,1814
set object 131 rect from 0,1820 to 500,1828
set object 132 rect from 0,1834 to 500,1842
set object 133 rect from 0,1848 to 500,1856
set object 134 rect from 0,1862 to 500,1870
set object 135 rect from 0,1876 to 500,1884
set object 136 rect from 0,1890 to 500,1898
set object 137 rect from 0,1904 to 500,1912
set object 138 rect from 0,1918 to 500,1926
set object 139 rect from 0,1932 to 500,1940
set object 140 rect from 0,1946 to 500,1954
set object 141 rect from 0,1960 to 500,1968
set object 142 rect from 0,1974 to 500,1982
set object 143 rect from 0,1988 to 500,1996
set object 144 rect from 0,2002 to 500,2010
set object 145 rect from 0,2016 to 500,2024
set object 146 rect from 0,2030 to 500,2038
set object 147 rect from 0,2044 to 500,2052
set object 148 rect from 0,2058 to 500,2066
set object 149 rect from 0,2072 to 500,2080
set object 150 rect from 0,2086 to 500,2094
set object 151 rect from 0,2100 to 500,2108
set object 152 rect from 0,2114 to 500,2122
set object 153 rect from 0,2128 to 500,2136
set object 154 rect from 0,2142 to 500,2150
set object 155 rect from 0,2156 to 500,2164
set object 156 rect from 0,2170 to 500,2178
set object 157 rect from 0,2184 to 500,2192
set object 158 rect from 0,2198 to 500,2206
set object 159 rect from 0,2212 to 500,2220
set object 160 rect from 0,2226 to 500,2234
set object 161 rect from 0,2240 to 500,2248
set object 162 rect from 0,2254 to 500,2262
set object 163 rect from 0,2268 to 500,2276
set object 164 rect from 0,2282 to 500,2290
set object 165 rect from 0,2296 to 500,2304
set object 166 rect from 0,2310 to 500,2318
set object 167 rect from 0,2324 to 500,2332
set object 168 rect from 0,2338 to 500,2346
set object 169 rect from 0,2352 to 500,2360
set object 170 rect from 0,2366 to 500,2374
set object 171 rect from 0,2380 to 500,2388
set object 172 rect from 0,2394 to 500,2402
set object 173 rect from 0,2408 to 500,2416
set object 174 rect from 0,2422 to 500,2430
set object 175 rect from 0,2436 to 500,2444
set object 176 rect from 0,2450 to 500,2458
set object 177 rect from 0,2464 to 500,2472
set object 178 rect from 0,2478 to 500,2486
set object 179 rect from 0,2492 to 500,2500
set object 180 rect from 0,2506 to 500,2514
set object 181 rect from 0,2520 to 500,2528
set object 182 rect from 0,2534 to 500,2542
set object 183 rect from 0,2548 to 500,2556
set object 184 rect from 0,2562 to 500,2570
set object 185 rect from 0,2576 to 500,2584
set object 186 rect from 0,2590 to 500,2598
set object 187 rect from 0,2604 to 500,2612
set object 188 rect from 0,2618 to 500,2626
set object 189 rect from 0,2632 to 500,2640
set object 190 rect from 0,2646 to 500,2654
set object 191 rect from 0,2660 to 500,2668
set object 192 rect from 0,2674 to 500,2682
set object 193 rect from 0,2688 to 500,2696
set object 194 rect from 0,2702 to 500,2710
set object 195 rect from 0,2716 to 500,2724
set object 196 rect from 0,2730 to 500,2738
set object 197 rect from 0,2744 to 500,2752
set object 198 rect from 0,2758 to 500,2766
set object 199 rect from 0,2772 to 500,2780
set object 200 rect from 0,2786 to 500,2794
plot [][-28.000000:2828.000000]\
     "run.4.stepagentactionwtime" using 2:(($3*2)+0) title "" w line lt 1,\
     "run.4.stepagentactionwtime" using 2:(($4*2)+14) title "" w line lt 1,\
     "run.4.stepagentactionwtime" using 2:(($5*2)+28) title "" w line lt 1,\
     "run.4.stepagentactionwtime" using 2:(($6*2)+42) title "" w line lt 1,\
     "run.4.stepagentactionwtime" using 2:(($7*2)+56) title "" w line lt 1,\
     "run.4.stepagentactionwtime" using 2:(($8*2)+70) title "" w line lt 1,\
     "run.4.stepagentactionwtime" using 2:(($9*2)+84) title "" w line lt 1,\
     "run.4.stepagentactionwtime" using 2:(($10*2)+98) title "" w line lt 1,\
     "run.4.stepagentactionwtime" using 2:(($11*2)+112) title "" w line lt 1,\
     "run.4.stepagentactionwtime" using 2:(($12*2)+126) title "" w line lt 1,\
     "run.4.stepagentactionwtime" using 2:(($13*2)+140) title "" w line lt 1,\
     "run.4.stepagentactionwtime" using 2:(($14*2)+154) title "" w line lt 1,\
     "run.4.stepagentactionwtime" using 2:(($15*2)+168) title "" w line lt 1,\
     "run.4.stepagentactionwtime" using 2:(($16*2)+182) title "" w line lt 1,\
     "run.4.stepagentactionwtime" using 2:(($17*2)+196) title "" w line lt 1,\
     "run.4.stepagentactionwtime" using 2:(($18*2)+210) title "" w line lt 1,\
     "run.4.stepagentactionwtime" using 2:(($19*2)+224) title "" w line lt 1,\
     "run.4.stepagentactionwtime" using 2:(($20*2)+238) title "" w line lt 1,\
     "run.4.stepagentactionwtime" using 2:(($21*2)+252) title "" w line lt 1,\
     "run.4.stepagentactionwtime" using 2:(($22*2)+266) title "" w line lt 1,\
     "run.4.stepagentactionwtime" using 2:(($23*2)+280) title "" w line lt 1,\
     "run.4.stepagentactionwtime" using 2:(($24*2)+294) title "" w line lt 1,\
     "run.4.stepagentactionwtime" using 2:(($25*2)+308) title "" w line lt 1,\
     "run.4.stepagentactionwtime" using 2:(($26*2)+322) title "" w line lt 1,\
     "run.4.stepagentactionwtime" using 2:(($27*2)+336) title "" w line lt 1,\
     "run.4.stepagentactionwtime" using 2:(($28*2)+350) title "" w line lt 1,\
     "run.4.stepagentactionwtime" using 2:(($29*2)+364) title "" w line lt 1,\
     "run.4.stepagentactionwtime" using 2:(($30*2)+378) title "" w line lt 1,\
     "run.4.stepagentactionwtime" using 2:(($31*2)+392) title "" w line lt 1,\
     "run.4.stepagentactionwtime" using 2:(($32*2)+406) title "" w line lt 1,\
     "run.4.stepagentactionwtime" using 2:(($33*2)+420) title "" w line lt 1,\
     "run.4.stepagentactionwtime" using 2:(($34*2)+434) title "" w line lt 1,\
     "run.4.stepagentactionwtime" using 2:(($35*2)+448) title "" w line lt 1,\
     "run.4.stepagentactionwtime" using 2:(($36*2)+462) title "" w line lt 1,\
     "run.4.stepagentactionwtime" using 2:(($37*2)+476) title "" w line lt 1,\
     "run.4.stepagentactionwtime" using 2:(($38*2)+490) title "" w line lt 1,\
     "run.4.stepagentactionwtime" using 2:(($39*2)+504) title "" w line lt 1,\
     "run.4.stepagentactionwtime" using 2:(($40*2)+518) title "" w line lt 1,\
     "run.4.stepagentactionwtime" using 2:(($41*2)+532) title "" w line lt 1,\
     "run.4.stepagentactionwtime" using 2:(($42*2)+546) title "" w line lt 1,\
     "run.4.stepagentactionwtime" using 2:(($43*2)+560) title "" w line lt 1,\
     "run.4.stepagentactionwtime" using 2:(($44*2)+574) title "" w line lt 1,\
     "run.4.stepagentactionwtime" using 2:(($45*2)+588) title "" w line lt 1,\
     "run.4.stepagentactionwtime" using 2:(($46*2)+602) title "" w line lt 1,\
     "run.4.stepagentactionwtime" using 2:(($47*2)+616) title "" w line lt 1,\
     "run.4.stepagentactionwtime" using 2:(($48*2)+630) title "" w line lt 1,\
     "run.4.stepagentactionwtime" using 2:(($49*2)+644) title "" w line lt 1,\
     "run.4.stepagentactionwtime" using 2:(($50*2)+658) title "" w line lt 1,\
     "run.4.stepagentactionwtime" using 2:(($51*2)+672) title "" w line lt 1,\
     "run.4.stepagentactionwtime" using 2:(($52*2)+686) title "" w line lt 1,\
     "run.4.stepagentactionwtime" using 2:(($53*2)+700) title "" w line lt 1,\
     "run.4.stepagentactionwtime" using 2:(($54*2)+714) title "" w line lt 1,\
     "run.4.stepagentactionwtime" using 2:(($55*2)+728) title "" w line lt 1,\
     "run.4.stepagentactionwtime" using 2:(($56*2)+742) title "" w line lt 1,\
     "run.4.stepagentactionwtime" using 2:(($57*2)+756) title "" w line lt 1,\
     "run.4.stepagentactionwtime" using 2:(($58*2)+770) title "" w line lt 1,\
     "run.4.stepagentactionwtime" using 2:(($59*2)+784) title "" w line lt 1,\
     "run.4.stepagentactionwtime" using 2:(($60*2)+798) title "" w line lt 1,\
     "run.4.stepagentactionwtime" using 2:(($61*2)+812) title "" w line lt 1,\
     "run.4.stepagentactionwtime" using 2:(($62*2)+826) title "" w line lt 1,\
     "run.4.stepagentactionwtime" using 2:(($63*2)+840) title "" w line lt 1,\
     "run.4.stepagentactionwtime" using 2:(($64*2)+854) title "" w line lt 1,\
     "run.4.stepagentactionwtime" using 2:(($65*2)+868) title "" w line lt 1,\
     "run.4.stepagentactionwtime" using 2:(($66*2)+882) title "" w line lt 1,\
     "run.4.stepagentactionwtime" using 2:(($67*2)+896) title "" w line lt 1,\
     "run.4.stepagentactionwtime" using 2:(($68*2)+910) title "" w line lt 1,\
     "run.4.stepagentactionwtime" using 2:(($69*2)+924) title "" w line lt 1,\
     "run.4.stepagentactionwtime" using 2:(($70*2)+938) title "" w line lt 1,\
     "run.4.stepagentactionwtime" using 2:(($71*2)+952) title "" w line lt 1,\
     "run.4.stepagentactionwtime" using 2:(($72*2)+966) title "" w line lt 1,\
     "run.4.stepagentactionwtime" using 2:(($73*2)+980) title "" w line lt 1,\
     "run.4.stepagentactionwtime" using 2:(($74*2)+994) title "" w line lt 1,\
     "run.4.stepagentactionwtime" using 2:(($75*2)+1008) title "" w line lt 1,\
     "run.4.stepagentactionwtime" using 2:(($76*2)+1022) title "" w line lt 1,\
     "run.4.stepagentactionwtime" using 2:(($77*2)+1036) title "" w line lt 1,\
     "run.4.stepagentactionwtime" using 2:(($78*2)+1050) title "" w line lt 1,\
     "run.4.stepagentactionwtime" using 2:(($79*2)+1064) title "" w line lt 1,\
     "run.4.stepagentactionwtime" using 2:(($80*2)+1078) title "" w line lt 1,\
     "run.4.stepagentactionwtime" using 2:(($81*2)+1092) title "" w line lt 1,\
     "run.4.stepagentactionwtime" using 2:(($82*2)+1106) title "" w line lt 1,\
     "run.4.stepagentactionwtime" using 2:(($83*2)+1120) title "" w line lt 1,\
     "run.4.stepagentactionwtime" using 2:(($84*2)+1134) title "" w line lt 1,\
     "run.4.stepagentactionwtime" using 2:(($85*2)+1148) title "" w line lt 1,\
     "run.4.stepagentactionwtime" using 2:(($86*2)+1162) title "" w line lt 1,\
     "run.4.stepagentactionwtime" using 2:(($87*2)+1176) title "" w line lt 1,\
     "run.4.stepagentactionwtime" using 2:(($88*2)+1190) title "" w line lt 1,\
     "run.4.stepagentactionwtime" using 2:(($89*2)+1204) title "" w line lt 1,\
     "run.4.stepagentactionwtime" using 2:(($90*2)+1218) title "" w line lt 1,\
     "run.4.stepagentactionwtime" using 2:(($91*2)+1232) title "" w line lt 1,\
     "run.4.stepagentactionwtime" using 2:(($92*2)+1246) title "" w line lt 1,\
     "run.4.stepagentactionwtime" using 2:(($93*2)+1260) title "" w line lt 1,\
     "run.4.stepagentactionwtime" using 2:(($94*2)+1274) title "" w line lt 1,\
     "run.4.stepagentactionwtime" using 2:(($95*2)+1288) title "" w line lt 1,\
     "run.4.stepagentactionwtime" using 2:(($96*2)+1302) title "" w line lt 1,\
     "run.4.stepagentactionwtime" using 2:(($97*2)+1316) title "" w line lt 1,\
     "run.4.stepagentactionwtime" using 2:(($98*2)+1330) title "" w line lt 1,\
     "run.4.stepagentactionwtime" using 2:(($99*2)+1344) title "" w line lt 1,\
     "run.4.stepagentactionwtime" using 2:(($100*2)+1358) title "" w line lt 1,\
     "run.4.stepagentactionwtime" using 2:(($101*2)+1372) title "" w line lt 1,\
     "run.4.stepagentactionwtime" using 2:(($102*2)+1386) title "" w line lt 1,\
     "run.4.stepagentactionwtime" using 2:(($103*2)+1400) title "" w line lt 1,\
     "run.4.stepagentactionwtime" using 2:(($104*2)+1414) title "" w line lt 1,\
     "run.4.stepagentactionwtime" using 2:(($105*2)+1428) title "" w line lt 1,\
     "run.4.stepagentactionwtime" using 2:(($106*2)+1442) title "" w line lt 1,\
     "run.4.stepagentactionwtime" using 2:(($107*2)+1456) title "" w line lt 1,\
     "run.4.stepagentactionwtime" using 2:(($108*2)+1470) title "" w line lt 1,\
     "run.4.stepagentactionwtime" using 2:(($109*2)+1484) title "" w line lt 1,\
     "run.4.stepagentactionwtime" using 2:(($110*2)+1498) title "" w line lt 1,\
     "run.4.stepagentactionwtime" using 2:(($111*2)+1512) title "" w line lt 1,\
     "run.4.stepagentactionwtime" using 2:(($112*2)+1526) title "" w line lt 1,\
     "run.4.stepagentactionwtime" using 2:(($113*2)+1540) title "" w line lt 1,\
     "run.4.stepagentactionwtime" using 2:(($114*2)+1554) title "" w line lt 1,\
     "run.4.stepagentactionwtime" using 2:(($115*2)+1568) title "" w line lt 1,\
     "run.4.stepagentactionwtime" using 2:(($116*2)+1582) title "" w line lt 1,\
     "run.4.stepagentactionwtime" using 2:(($117*2)+1596) title "" w line lt 1,\
     "run.4.stepagentactionwtime" using 2:(($118*2)+1610) title "" w line lt 1,\
     "run.4.stepagentactionwtime" using 2:(($119*2)+1624) title "" w line lt 1,\
     "run.4.stepagentactionwtime" using 2:(($120*2)+1638) title "" w line lt 1,\
     "run.4.stepagentactionwtime" using 2:(($121*2)+1652) title "" w line lt 1,\
     "run.4.stepagentactionwtime" using 2:(($122*2)+1666) title "" w line lt 1,\
     "run.4.stepagentactionwtime" using 2:(($123*2)+1680) title "" w line lt 1,\
     "run.4.stepagentactionwtime" using 2:(($124*2)+1694) title "" w line lt 1,\
     "run.4.stepagentactionwtime" using 2:(($125*2)+1708) title "" w line lt 1,\
     "run.4.stepagentactionwtime" using 2:(($126*2)+1722) title "" w line lt 1,\
     "run.4.stepagentactionwtime" using 2:(($127*2)+1736) title "" w line lt 1,\
     "run.4.stepagentactionwtime" using 2:(($128*2)+1750) title "" w line lt 1,\
     "run.4.stepagentactionwtime" using 2:(($129*2)+1764) title "" w line lt 1,\
     "run.4.stepagentactionwtime" using 2:(($130*2)+1778) title "" w line lt 1,\
     "run.4.stepagentactionwtime" using 2:(($131*2)+1792) title "" w line lt 1,\
     "run.4.stepagentactionwtime" using 2:(($132*2)+1806) title "" w line lt 1,\
     "run.4.stepagentactionwtime" using 2:(($133*2)+1820) title "" w line lt 1,\
     "run.4.stepagentactionwtime" using 2:(($134*2)+1834) title "" w line lt 1,\
     "run.4.stepagentactionwtime" using 2:(($135*2)+1848) title "" w line lt 1,\
     "run.4.stepagentactionwtime" using 2:(($136*2)+1862) title "" w line lt 1,\
     "run.4.stepagentactionwtime" using 2:(($137*2)+1876) title "" w line lt 1,\
     "run.4.stepagentactionwtime" using 2:(($138*2)+1890) title "" w line lt 1,\
     "run.4.stepagentactionwtime" using 2:(($139*2)+1904) title "" w line lt 1,\
     "run.4.stepagentactionwtime" using 2:(($140*2)+1918) title "" w line lt 1,\
     "run.4.stepagentactionwtime" using 2:(($141*2)+1932) title "" w line lt 1,\
     "run.4.stepagentactionwtime" using 2:(($142*2)+1946) title "" w line lt 1,\
     "run.4.stepagentactionwtime" using 2:(($143*2)+1960) title "" w line lt 1,\
     "run.4.stepagentactionwtime" using 2:(($144*2)+1974) title "" w line lt 1,\
     "run.4.stepagentactionwtime" using 2:(($145*2)+1988) title "" w line lt 1,\
     "run.4.stepagentactionwtime" using 2:(($146*2)+2002) title "" w line lt 1,\
     "run.4.stepagentactionwtime" using 2:(($147*2)+2016) title "" w line lt 1,\
     "run.4.stepagentactionwtime" using 2:(($148*2)+2030) title "" w line lt 1,\
     "run.4.stepagentactionwtime" using 2:(($149*2)+2044) title "" w line lt 1,\
     "run.4.stepagentactionwtime" using 2:(($150*2)+2058) title "" w line lt 1,\
     "run.4.stepagentactionwtime" using 2:(($151*2)+2072) title "" w line lt 1,\
     "run.4.stepagentactionwtime" using 2:(($152*2)+2086) title "" w line lt 1,\
     "run.4.stepagentactionwtime" using 2:(($153*2)+2100) title "" w line lt 1,\
     "run.4.stepagentactionwtime" using 2:(($154*2)+2114) title "" w line lt 1,\
     "run.4.stepagentactionwtime" using 2:(($155*2)+2128) title "" w line lt 1,\
     "run.4.stepagentactionwtime" using 2:(($156*2)+2142) title "" w line lt 1,\
     "run.4.stepagentactionwtime" using 2:(($157*2)+2156) title "" w line lt 1,\
     "run.4.stepagentactionwtime" using 2:(($158*2)+2170) title "" w line lt 1,\
     "run.4.stepagentactionwtime" using 2:(($159*2)+2184) title "" w line lt 1,\
     "run.4.stepagentactionwtime" using 2:(($160*2)+2198) title "" w line lt 1,\
     "run.4.stepagentactionwtime" using 2:(($161*2)+2212) title "" w line lt 1,\
     "run.4.stepagentactionwtime" using 2:(($162*2)+2226) title "" w line lt 1,\
     "run.4.stepagentactionwtime" using 2:(($163*2)+2240) title "" w line lt 1,\
     "run.4.stepagentactionwtime" using 2:(($164*2)+2254) title "" w line lt 1,\
     "run.4.stepagentactionwtime" using 2:(($165*2)+2268) title "" w line lt 1,\
     "run.4.stepagentactionwtime" using 2:(($166*2)+2282) title "" w line lt 1,\
     "run.4.stepagentactionwtime" using 2:(($167*2)+2296) title "" w line lt 1,\
     "run.4.stepagentactionwtime" using 2:(($168*2)+2310) title "" w line lt 1,\
     "run.4.stepagentactionwtime" using 2:(($169*2)+2324) title "" w line lt 1,\
     "run.4.stepagentactionwtime" using 2:(($170*2)+2338) title "" w line lt 1,\
     "run.4.stepagentactionwtime" using 2:(($171*2)+2352) title "" w line lt 1,\
     "run.4.stepagentactionwtime" using 2:(($172*2)+2366) title "" w line lt 1,\
     "run.4.stepagentactionwtime" using 2:(($173*2)+2380) title "" w line lt 1,\
     "run.4.stepagentactionwtime" using 2:(($174*2)+2394) title "" w line lt 1,\
     "run.4.stepagentactionwtime" using 2:(($175*2)+2408) title "" w line lt 1,\
     "run.4.stepagentactionwtime" using 2:(($176*2)+2422) title "" w line lt 1,\
     "run.4.stepagentactionwtime" using 2:(($177*2)+2436) title "" w line lt 1,\
     "run.4.stepagentactionwtime" using 2:(($178*2)+2450) title "" w line lt 1,\
     "run.4.stepagentactionwtime" using 2:(($179*2)+2464) title "" w line lt 1,\
     "run.4.stepagentactionwtime" using 2:(($180*2)+2478) title "" w line lt 1,\
     "run.4.stepagentactionwtime" using 2:(($181*2)+2492) title "" w line lt 1,\
     "run.4.stepagentactionwtime" using 2:(($182*2)+2506) title "" w line lt 1,\
     "run.4.stepagentactionwtime" using 2:(($183*2)+2520) title "" w line lt 1,\
     "run.4.stepagentactionwtime" using 2:(($184*2)+2534) title "" w line lt 1,\
     "run.4.stepagentactionwtime" using 2:(($185*2)+2548) title "" w line lt 1,\
     "run.4.stepagentactionwtime" using 2:(($186*2)+2562) title "" w line lt 1,\
     "run.4.stepagentactionwtime" using 2:(($187*2)+2576) title "" w line lt 1,\
     "run.4.stepagentactionwtime" using 2:(($188*2)+2590) title "" w line lt 1,\
     "run.4.stepagentactionwtime" using 2:(($189*2)+2604) title "" w line lt 1,\
     "run.4.stepagentactionwtime" using 2:(($190*2)+2618) title "" w line lt 1,\
     "run.4.stepagentactionwtime" using 2:(($191*2)+2632) title "" w line lt 1,\
     "run.4.stepagentactionwtime" using 2:(($192*2)+2646) title "" w line lt 1,\
     "run.4.stepagentactionwtime" using 2:(($193*2)+2660) title "" w line lt 1,\
     "run.4.stepagentactionwtime" using 2:(($194*2)+2674) title "" w line lt 1,\
     "run.4.stepagentactionwtime" using 2:(($195*2)+2688) title "" w line lt 1,\
     "run.4.stepagentactionwtime" using 2:(($196*2)+2702) title "" w line lt 1,\
     "run.4.stepagentactionwtime" using 2:(($197*2)+2716) title "" w line lt 1,\
     "run.4.stepagentactionwtime" using 2:(($198*2)+2730) title "" w line lt 1,\
     "run.4.stepagentactionwtime" using 2:(($199*2)+2744) title "" w line lt 1,\
     "run.4.stepagentactionwtime" using 2:(($200*2)+2758) title "" w line lt 1,\
     "run.4.stepagentactionwtime" using 2:(($201*2)+2772) title "" w line lt 1,\
     "run.4.stepagentactionwtime" using 2:(($202*2)+2786) title "" w line lt 1

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
unset object 101
unset object 102
unset object 103
unset object 104
unset object 105
unset object 106
unset object 107
unset object 108
unset object 109
unset object 110
unset object 111
unset object 112
unset object 113
unset object 114
unset object 115
unset object 116
unset object 117
unset object 118
unset object 119
unset object 120
unset object 121
unset object 122
unset object 123
unset object 124
unset object 125
unset object 126
unset object 127
unset object 128
unset object 129
unset object 130
unset object 131
unset object 132
unset object 133
unset object 134
unset object 135
unset object 136
unset object 137
unset object 138
unset object 139
unset object 140
unset object 141
unset object 142
unset object 143
unset object 144
unset object 145
unset object 146
unset object 147
unset object 148
unset object 149
unset object 150
unset object 151
unset object 152
unset object 153
unset object 154
unset object 155
unset object 156
unset object 157
unset object 158
unset object 159
unset object 160
unset object 161
unset object 162
unset object 163
unset object 164
unset object 165
unset object 166
unset object 167
unset object 168
unset object 169
unset object 170
unset object 171
unset object 172
unset object 173
unset object 174
unset object 175
unset object 176
unset object 177
unset object 178
unset object 179
unset object 180
unset object 181
unset object 182
unset object 183
unset object 184
unset object 185
unset object 186
unset object 187
unset object 188
unset object 189
unset object 190
unset object 191
unset object 192
unset object 193
unset object 194
unset object 195
unset object 196
unset object 197
unset object 198
unset object 199
unset object 200
set term post eps color
set size ratio 0.5
set output "run.4.finalagent.count.eps"
set xtics
set ytics
set xlabel "Agent"
set ylabel "Count"
set title "Number of times acted on each task"
plot [-1:240.000000][0:550.000000]\
     "run.4.finalagent" using 2:5 title "N" w points pt 1 ps 2 lw 2 lc 1,\
     "run.4.finalagent" using 2:6 title "E" w points pt 2 ps 2 lw 2 lc 2,\
     "run.4.finalagent" using 2:7 title "S" w points pt 4 ps 2 lw 2 lc 3,\
     "run.4.finalagent" using 2:8 title "W" w points pt 6 ps 2 lw 2 lc 4,\
     "run.4.finalagent" using 2:4 title "I" w points pt 8 ps 2 lc 7
unset xlabel
unset ylabel
unset title
unset size

set term post eps color
set size ratio 0.5
set output "run.4.finalagent.thresh.eps"
set xtics
set ytics
set xlabel "Agent"
set ylabel "Threshold"
set title "Final threshold for each task, Range = 10.000000"
plot [-1:240.000000][0:11.000000]\
     "run.4.finalagent" using 2:10 title "N" w points pt 1 ps 2 lw 2 lc 1,\
     "run.4.finalagent" using 2:11 title "E" w points pt 2 ps 2 lw 2 lc 2,\
     "run.4.finalagent" using 2:12 title "S" w points pt 4 ps 2 lw 2 lc 3,\
     "run.4.finalagent" using 2:13 title "W" w points pt 6 ps 2 lw 2 lc 4
unset xlabel
unset ylabel
unset title
unset size

set term post eps color
set size ratio 0.5
set output "run.4.finalagent.switch.eps"
set xtics
set ytics
set xlabel "Agent"
set ylabel "Number of switches"
set title "Number of task switches during run"
plot [-1:240.000000][0:550.000000]\
     "run.4.finalagent" using 2:15 title "N" w points pt 7 ps 2 lc 1
unset xlabel
unset ylabel
unset title
unset size

set term post eps color
set size ratio 0.5
set output "run.4.finalagent.spontaneousswitch.eps"
set xtics
set ytics
set xlabel "Agent"
set ylabel "Number of spontaneous switches"
set title "Number of task switches due to spontaneous response prob during run"
plot [-1:240.000000][0:550.000000]\
     "run.4.finalagent" using 2:17 title "N" w points pt 7 ps 2 lc 1
unset xlabel
unset ylabel
unset title
unset size

set term post eps color
set size ratio 0.5
set output "run.4.finalagent.response_prob.eps"
set xtics
set ytics
set xlabel "Agent"
set ylabel "Response prob Value"
set title "Agent Response prob Values"
plot [-1:220.000000][0:1]\
     "run.4.finalagent" using 2:21 title "N" w points pt 7 ps 2 lc 1
unset xlabel
unset ylabel
unset title
unset size

set term post eps color
set size ratio 0.5
set output "run.4.finalagent.spontaneous_response_prob.eps"
set xtics
set ytics
set xlabel "Agent"
set ylabel "Spontaneous Value"
set title "Agent Spontaneous Values"
plot [-1:220.000000][0:1]\
     "run.4.finalagent" using 2:23 title "N" w points pt 7 ps 2 lc 1
unset xlabel
unset ylabel
unset title
unset size


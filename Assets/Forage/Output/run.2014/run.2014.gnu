set term post eps color

# plot stepdistance data
set output "run.2014.stepdistance.eps"
set xlabel "Cycle"
set ylabel "Distance travelled"
plot [][0:]\
   "run.2014.stepdistance" using 1:4 title "ag0" w line lt 1 lc 0,\
   "run.2014.stepdistance" using 1:7 title "ag1" w line lt 1 lc 1,\
   "run.2014.stepdistance" using 1:10 title "ag2" w line lt 1 lc 2,\
   "run.2014.stepdistance" using 1:13 title "ag3" w line lt 1 lc 3,\
   "run.2014.stepdistance" using 1:16 title "ag4" w line lt 1 lc 4,\
   "run.2014.stepdistance" using 1:19 title "ag5" w line lt 1 lc 5,\
   "run.2014.stepdistance" using 1:22 title "ag6" w line lt 1 lc 6,\
   "run.2014.stepdistance" using 1:25 title "ag7" w line lt 1 lc 7,\
   "run.2014.stepdistance" using 1:28 title "ag8" w line lt 1 lc 8,\
   "run.2014.stepdistance" using 1:31 title "ag9" w line lt 1 lc 9,\
   "run.2014.stepdistance" using 1:34 title "ag10" w line lt 1 lc 10,\
   "run.2014.stepdistance" using 1:37 title "ag11" w line lt 1 lc 11,\
   "run.2014.stepdistance" using 1:40 title "ag12" w line lt 1 lc 12,\
   "run.2014.stepdistance" using 1:43 title "ag13" w line lt 1 lc 13,\
   "run.2014.stepdistance" using 1:46 title "ag14" w line lt 1 lc 14,\
   "run.2014.stepdistance" using 1:49 title "ag15" w line lt 1 lc 15,\
   "run.2014.stepdistance" using 1:52 title "ag16" w line lt 1 lc 16,\
   "run.2014.stepdistance" using 1:55 title "ag17" w line lt 1 lc 17,\
   "run.2014.stepdistance" using 1:58 title "ag18" w line lt 1 lc 18,\
   "run.2014.stepdistance" using 1:61 title "ag19" w line lt 1 lc 19,\
   "run.2014.stepdistance" using 1:64 title "ag20" w line lt 1 lc 20,\
   "run.2014.stepdistance" using 1:67 title "ag21" w line lt 1 lc 21,\
   "run.2014.stepdistance" using 1:70 title "ag22" w line lt 1 lc 22,\
   "run.2014.stepdistance" using 1:73 title "ag23" w line lt 1 lc 23,\
   "run.2014.stepdistance" using 1:76 title "ag24" w line lt 1 lc 24,\
   "run.2014.stepdistance" using 1:79 title "ag25" w line lt 1 lc 25,\
   "run.2014.stepdistance" using 1:82 title "ag26" w line lt 1 lc 26,\
   "run.2014.stepdistance" using 1:85 title "ag27" w line lt 1 lc 27,\
   "run.2014.stepdistance" using 1:88 title "ag28" w line lt 1 lc 28,\
   "run.2014.stepdistance" using 1:91 title "ag29" w line lt 1 lc 29,\
   "run.2014.stepdistance" using 1:94 title "ag30" w line lt 1 lc 30,\
   "run.2014.stepdistance" using 1:97 title "ag31" w line lt 1 lc 31,\
   "run.2014.stepdistance" using 1:100 title "ag32" w line lt 1 lc 32,\
   "run.2014.stepdistance" using 1:103 title "ag33" w line lt 1 lc 33,\
   "run.2014.stepdistance" using 1:106 title "ag34" w line lt 1 lc 34,\
   "run.2014.stepdistance" using 1:109 title "ag35" w line lt 1 lc 35,\
   "run.2014.stepdistance" using 1:112 title "ag36" w line lt 1 lc 36,\
   "run.2014.stepdistance" using 1:115 title "ag37" w line lt 1 lc 37,\
   "run.2014.stepdistance" using 1:118 title "ag38" w line lt 1 lc 38,\
   "run.2014.stepdistance" using 1:121 title "ag39" w line lt 1 lc 39,\
   "run.2014.stepdistance" using 1:124 title "ag40" w line lt 1 lc 40,\
   "run.2014.stepdistance" using 1:127 title "ag41" w line lt 1 lc 41,\
   "run.2014.stepdistance" using 1:130 title "ag42" w line lt 1 lc 42,\
   "run.2014.stepdistance" using 1:133 title "ag43" w line lt 1 lc 43,\
   "run.2014.stepdistance" using 1:136 title "ag44" w line lt 1 lc 44,\
   "run.2014.stepdistance" using 1:139 title "ag45" w line lt 1 lc 45,\
   "run.2014.stepdistance" using 1:142 title "ag46" w line lt 1 lc 46,\
   "run.2014.stepdistance" using 1:145 title "ag47" w line lt 1 lc 47,\
   "run.2014.stepdistance" using 1:148 title "ag48" w line lt 1 lc 48,\
   "run.2014.stepdistance" using 1:151 title "ag49" w line lt 1 lc 49,\
   "run.2014.stepdistance" using 1:154 title "ag50" w line lt 1 lc 50,\
   "run.2014.stepdistance" using 1:157 title "ag51" w line lt 1 lc 51,\
   "run.2014.stepdistance" using 1:160 title "ag52" w line lt 1 lc 52,\
   "run.2014.stepdistance" using 1:163 title "ag53" w line lt 1 lc 53,\
   "run.2014.stepdistance" using 1:166 title "ag54" w line lt 1 lc 54,\
   "run.2014.stepdistance" using 1:169 title "ag55" w line lt 1 lc 55,\
   "run.2014.stepdistance" using 1:172 title "ag56" w line lt 1 lc 56,\
   "run.2014.stepdistance" using 1:175 title "ag57" w line lt 1 lc 57,\
   "run.2014.stepdistance" using 1:178 title "ag58" w line lt 1 lc 58,\
   "run.2014.stepdistance" using 1:181 title "ag59" w line lt 1 lc 59,\
   "run.2014.stepdistance" using 1:184 title "ag60" w line lt 1 lc 60,\
   "run.2014.stepdistance" using 1:187 title "ag61" w line lt 1 lc 61,\
   "run.2014.stepdistance" using 1:190 title "ag62" w line lt 1 lc 62,\
   "run.2014.stepdistance" using 1:193 title "ag63" w line lt 1 lc 63,\
   "run.2014.stepdistance" using 1:196 title "ag64" w line lt 1 lc 64,\
   "run.2014.stepdistance" using 1:199 title "ag65" w line lt 1 lc 65,\
   "run.2014.stepdistance" using 1:202 title "ag66" w line lt 1 lc 66,\
   "run.2014.stepdistance" using 1:205 title "ag67" w line lt 1 lc 67,\
   "run.2014.stepdistance" using 1:208 title "ag68" w line lt 1 lc 68,\
   "run.2014.stepdistance" using 1:211 title "ag69" w line lt 1 lc 69,\
   "run.2014.stepdistance" using 1:214 title "ag70" w line lt 1 lc 70,\
   "run.2014.stepdistance" using 1:217 title "ag71" w line lt 1 lc 71,\
   "run.2014.stepdistance" using 1:220 title "ag72" w line lt 1 lc 72,\
   "run.2014.stepdistance" using 1:223 title "ag73" w line lt 1 lc 73,\
   "run.2014.stepdistance" using 1:226 title "ag74" w line lt 1 lc 74,\
   "run.2014.stepdistance" using 1:229 title "ag75" w line lt 1 lc 75,\
   "run.2014.stepdistance" using 1:232 title "ag76" w line lt 1 lc 76,\
   "run.2014.stepdistance" using 1:235 title "ag77" w line lt 1 lc 77,\
   "run.2014.stepdistance" using 1:238 title "ag78" w line lt 1 lc 78,\
   "run.2014.stepdistance" using 1:241 title "ag79" w line lt 1 lc 79,\
   "run.2014.stepdistance" using 1:244 title "ag80" w line lt 1 lc 80,\
   "run.2014.stepdistance" using 1:247 title "ag81" w line lt 1 lc 81,\
   "run.2014.stepdistance" using 1:250 title "ag82" w line lt 1 lc 82,\
   "run.2014.stepdistance" using 1:253 title "ag83" w line lt 1 lc 83,\
   "run.2014.stepdistance" using 1:256 title "ag84" w line lt 1 lc 84,\
   "run.2014.stepdistance" using 1:259 title "ag85" w line lt 1 lc 85,\
   "run.2014.stepdistance" using 1:262 title "ag86" w line lt 1 lc 86,\
   "run.2014.stepdistance" using 1:265 title "ag87" w line lt 1 lc 87,\
   "run.2014.stepdistance" using 1:268 title "ag88" w line lt 1 lc 88,\
   "run.2014.stepdistance" using 1:271 title "ag89" w line lt 1 lc 89,\
   "run.2014.stepdistance" using 1:274 title "ag90" w line lt 1 lc 90,\
   "run.2014.stepdistance" using 1:277 title "ag91" w line lt 1 lc 91,\
   "run.2014.stepdistance" using 1:280 title "ag92" w line lt 1 lc 92,\
   "run.2014.stepdistance" using 1:283 title "ag93" w line lt 1 lc 93,\
   "run.2014.stepdistance" using 1:286 title "ag94" w line lt 1 lc 94,\
   "run.2014.stepdistance" using 1:289 title "ag95" w line lt 1 lc 95,\
   "run.2014.stepdistance" using 1:292 title "ag96" w line lt 1 lc 96,\
   "run.2014.stepdistance" using 1:295 title "ag97" w line lt 1 lc 97,\
   "run.2014.stepdistance" using 1:298 title "ag98" w line lt 1 lc 98,\
   "run.2014.stepdistance" using 1:301 title "ag99" w line lt 1 lc 99
unset xlabel
unset ylabel

# plot stepnest data
set output "run.2014.food_in.stepnest.eps"
set xlabel "Cycle"
set ylabel "Food found"
plot [][]\
   "run.2014.stepnest" using 1:3 w line
unset xlabel
unset ylabel

# plot stepnest data
set output "run.2014.num_actors.stepnest.eps"
set xlabel "Cycle"
set ylabel "Number of actors"
plot [][]\
   "run.2014.stepnest" using 1:5 w line
unset xlabel
unset ylabel

# plot data for individual agents
set xlabel "Cycle"
set ylabel "Distance travelled"
set output "run.2014.agent.0.stepdistance.eps"
plot [][0:1001] "run.2014.stepdistance" using 1:4 title "ag0" w points
#
set output "run.2014.agent.1.stepdistance.eps"
plot [][0:1001] "run.2014.stepdistance" using 1:7 title "ag1" w points
#
set output "run.2014.agent.2.stepdistance.eps"
plot [][0:1001] "run.2014.stepdistance" using 1:10 title "ag2" w points
#
set output "run.2014.agent.3.stepdistance.eps"
plot [][0:1001] "run.2014.stepdistance" using 1:13 title "ag3" w points
#
set output "run.2014.agent.4.stepdistance.eps"
plot [][0:1001] "run.2014.stepdistance" using 1:16 title "ag4" w points
#
set output "run.2014.agent.5.stepdistance.eps"
plot [][0:1001] "run.2014.stepdistance" using 1:19 title "ag5" w points
#
set output "run.2014.agent.6.stepdistance.eps"
plot [][0:1001] "run.2014.stepdistance" using 1:22 title "ag6" w points
#
set output "run.2014.agent.7.stepdistance.eps"
plot [][0:1001] "run.2014.stepdistance" using 1:25 title "ag7" w points
#
set output "run.2014.agent.8.stepdistance.eps"
plot [][0:1001] "run.2014.stepdistance" using 1:28 title "ag8" w points
#
set output "run.2014.agent.9.stepdistance.eps"
plot [][0:1001] "run.2014.stepdistance" using 1:31 title "ag9" w points
#
set output "run.2014.agent.10.stepdistance.eps"
plot [][0:1001] "run.2014.stepdistance" using 1:34 title "ag10" w points
#
set output "run.2014.agent.11.stepdistance.eps"
plot [][0:1001] "run.2014.stepdistance" using 1:37 title "ag11" w points
#
set output "run.2014.agent.12.stepdistance.eps"
plot [][0:1001] "run.2014.stepdistance" using 1:40 title "ag12" w points
#
set output "run.2014.agent.13.stepdistance.eps"
plot [][0:1001] "run.2014.stepdistance" using 1:43 title "ag13" w points
#
set output "run.2014.agent.14.stepdistance.eps"
plot [][0:1001] "run.2014.stepdistance" using 1:46 title "ag14" w points
#
set output "run.2014.agent.15.stepdistance.eps"
plot [][0:1001] "run.2014.stepdistance" using 1:49 title "ag15" w points
#
set output "run.2014.agent.16.stepdistance.eps"
plot [][0:1001] "run.2014.stepdistance" using 1:52 title "ag16" w points
#
set output "run.2014.agent.17.stepdistance.eps"
plot [][0:1001] "run.2014.stepdistance" using 1:55 title "ag17" w points
#
set output "run.2014.agent.18.stepdistance.eps"
plot [][0:1001] "run.2014.stepdistance" using 1:58 title "ag18" w points
#
set output "run.2014.agent.19.stepdistance.eps"
plot [][0:1001] "run.2014.stepdistance" using 1:61 title "ag19" w points
#
set output "run.2014.agent.20.stepdistance.eps"
plot [][0:1001] "run.2014.stepdistance" using 1:64 title "ag20" w points
#
set output "run.2014.agent.21.stepdistance.eps"
plot [][0:1001] "run.2014.stepdistance" using 1:67 title "ag21" w points
#
set output "run.2014.agent.22.stepdistance.eps"
plot [][0:1001] "run.2014.stepdistance" using 1:70 title "ag22" w points
#
set output "run.2014.agent.23.stepdistance.eps"
plot [][0:1001] "run.2014.stepdistance" using 1:73 title "ag23" w points
#
set output "run.2014.agent.24.stepdistance.eps"
plot [][0:1001] "run.2014.stepdistance" using 1:76 title "ag24" w points
#
set output "run.2014.agent.25.stepdistance.eps"
plot [][0:1001] "run.2014.stepdistance" using 1:79 title "ag25" w points
#
set output "run.2014.agent.26.stepdistance.eps"
plot [][0:1001] "run.2014.stepdistance" using 1:82 title "ag26" w points
#
set output "run.2014.agent.27.stepdistance.eps"
plot [][0:1001] "run.2014.stepdistance" using 1:85 title "ag27" w points
#
set output "run.2014.agent.28.stepdistance.eps"
plot [][0:1001] "run.2014.stepdistance" using 1:88 title "ag28" w points
#
set output "run.2014.agent.29.stepdistance.eps"
plot [][0:1001] "run.2014.stepdistance" using 1:91 title "ag29" w points
#
set output "run.2014.agent.30.stepdistance.eps"
plot [][0:1001] "run.2014.stepdistance" using 1:94 title "ag30" w points
#
set output "run.2014.agent.31.stepdistance.eps"
plot [][0:1001] "run.2014.stepdistance" using 1:97 title "ag31" w points
#
set output "run.2014.agent.32.stepdistance.eps"
plot [][0:1001] "run.2014.stepdistance" using 1:100 title "ag32" w points
#
set output "run.2014.agent.33.stepdistance.eps"
plot [][0:1001] "run.2014.stepdistance" using 1:103 title "ag33" w points
#
set output "run.2014.agent.34.stepdistance.eps"
plot [][0:1001] "run.2014.stepdistance" using 1:106 title "ag34" w points
#
set output "run.2014.agent.35.stepdistance.eps"
plot [][0:1001] "run.2014.stepdistance" using 1:109 title "ag35" w points
#
set output "run.2014.agent.36.stepdistance.eps"
plot [][0:1001] "run.2014.stepdistance" using 1:112 title "ag36" w points
#
set output "run.2014.agent.37.stepdistance.eps"
plot [][0:1001] "run.2014.stepdistance" using 1:115 title "ag37" w points
#
set output "run.2014.agent.38.stepdistance.eps"
plot [][0:1001] "run.2014.stepdistance" using 1:118 title "ag38" w points
#
set output "run.2014.agent.39.stepdistance.eps"
plot [][0:1001] "run.2014.stepdistance" using 1:121 title "ag39" w points
#
set output "run.2014.agent.40.stepdistance.eps"
plot [][0:1001] "run.2014.stepdistance" using 1:124 title "ag40" w points
#
set output "run.2014.agent.41.stepdistance.eps"
plot [][0:1001] "run.2014.stepdistance" using 1:127 title "ag41" w points
#
set output "run.2014.agent.42.stepdistance.eps"
plot [][0:1001] "run.2014.stepdistance" using 1:130 title "ag42" w points
#
set output "run.2014.agent.43.stepdistance.eps"
plot [][0:1001] "run.2014.stepdistance" using 1:133 title "ag43" w points
#
set output "run.2014.agent.44.stepdistance.eps"
plot [][0:1001] "run.2014.stepdistance" using 1:136 title "ag44" w points
#
set output "run.2014.agent.45.stepdistance.eps"
plot [][0:1001] "run.2014.stepdistance" using 1:139 title "ag45" w points
#
set output "run.2014.agent.46.stepdistance.eps"
plot [][0:1001] "run.2014.stepdistance" using 1:142 title "ag46" w points
#
set output "run.2014.agent.47.stepdistance.eps"
plot [][0:1001] "run.2014.stepdistance" using 1:145 title "ag47" w points
#
set output "run.2014.agent.48.stepdistance.eps"
plot [][0:1001] "run.2014.stepdistance" using 1:148 title "ag48" w points
#
set output "run.2014.agent.49.stepdistance.eps"
plot [][0:1001] "run.2014.stepdistance" using 1:151 title "ag49" w points
#
set output "run.2014.agent.50.stepdistance.eps"
plot [][0:1001] "run.2014.stepdistance" using 1:154 title "ag50" w points
#
set output "run.2014.agent.51.stepdistance.eps"
plot [][0:1001] "run.2014.stepdistance" using 1:157 title "ag51" w points
#
set output "run.2014.agent.52.stepdistance.eps"
plot [][0:1001] "run.2014.stepdistance" using 1:160 title "ag52" w points
#
set output "run.2014.agent.53.stepdistance.eps"
plot [][0:1001] "run.2014.stepdistance" using 1:163 title "ag53" w points
#
set output "run.2014.agent.54.stepdistance.eps"
plot [][0:1001] "run.2014.stepdistance" using 1:166 title "ag54" w points
#
set output "run.2014.agent.55.stepdistance.eps"
plot [][0:1001] "run.2014.stepdistance" using 1:169 title "ag55" w points
#
set output "run.2014.agent.56.stepdistance.eps"
plot [][0:1001] "run.2014.stepdistance" using 1:172 title "ag56" w points
#
set output "run.2014.agent.57.stepdistance.eps"
plot [][0:1001] "run.2014.stepdistance" using 1:175 title "ag57" w points
#
set output "run.2014.agent.58.stepdistance.eps"
plot [][0:1001] "run.2014.stepdistance" using 1:178 title "ag58" w points
#
set output "run.2014.agent.59.stepdistance.eps"
plot [][0:1001] "run.2014.stepdistance" using 1:181 title "ag59" w points
#
set output "run.2014.agent.60.stepdistance.eps"
plot [][0:1001] "run.2014.stepdistance" using 1:184 title "ag60" w points
#
set output "run.2014.agent.61.stepdistance.eps"
plot [][0:1001] "run.2014.stepdistance" using 1:187 title "ag61" w points
#
set output "run.2014.agent.62.stepdistance.eps"
plot [][0:1001] "run.2014.stepdistance" using 1:190 title "ag62" w points
#
set output "run.2014.agent.63.stepdistance.eps"
plot [][0:1001] "run.2014.stepdistance" using 1:193 title "ag63" w points
#
set output "run.2014.agent.64.stepdistance.eps"
plot [][0:1001] "run.2014.stepdistance" using 1:196 title "ag64" w points
#
set output "run.2014.agent.65.stepdistance.eps"
plot [][0:1001] "run.2014.stepdistance" using 1:199 title "ag65" w points
#
set output "run.2014.agent.66.stepdistance.eps"
plot [][0:1001] "run.2014.stepdistance" using 1:202 title "ag66" w points
#
set output "run.2014.agent.67.stepdistance.eps"
plot [][0:1001] "run.2014.stepdistance" using 1:205 title "ag67" w points
#
set output "run.2014.agent.68.stepdistance.eps"
plot [][0:1001] "run.2014.stepdistance" using 1:208 title "ag68" w points
#
set output "run.2014.agent.69.stepdistance.eps"
plot [][0:1001] "run.2014.stepdistance" using 1:211 title "ag69" w points
#
set output "run.2014.agent.70.stepdistance.eps"
plot [][0:1001] "run.2014.stepdistance" using 1:214 title "ag70" w points
#
set output "run.2014.agent.71.stepdistance.eps"
plot [][0:1001] "run.2014.stepdistance" using 1:217 title "ag71" w points
#
set output "run.2014.agent.72.stepdistance.eps"
plot [][0:1001] "run.2014.stepdistance" using 1:220 title "ag72" w points
#
set output "run.2014.agent.73.stepdistance.eps"
plot [][0:1001] "run.2014.stepdistance" using 1:223 title "ag73" w points
#
set output "run.2014.agent.74.stepdistance.eps"
plot [][0:1001] "run.2014.stepdistance" using 1:226 title "ag74" w points
#
set output "run.2014.agent.75.stepdistance.eps"
plot [][0:1001] "run.2014.stepdistance" using 1:229 title "ag75" w points
#
set output "run.2014.agent.76.stepdistance.eps"
plot [][0:1001] "run.2014.stepdistance" using 1:232 title "ag76" w points
#
set output "run.2014.agent.77.stepdistance.eps"
plot [][0:1001] "run.2014.stepdistance" using 1:235 title "ag77" w points
#
set output "run.2014.agent.78.stepdistance.eps"
plot [][0:1001] "run.2014.stepdistance" using 1:238 title "ag78" w points
#
set output "run.2014.agent.79.stepdistance.eps"
plot [][0:1001] "run.2014.stepdistance" using 1:241 title "ag79" w points
#
set output "run.2014.agent.80.stepdistance.eps"
plot [][0:1001] "run.2014.stepdistance" using 1:244 title "ag80" w points
#
set output "run.2014.agent.81.stepdistance.eps"
plot [][0:1001] "run.2014.stepdistance" using 1:247 title "ag81" w points
#
set output "run.2014.agent.82.stepdistance.eps"
plot [][0:1001] "run.2014.stepdistance" using 1:250 title "ag82" w points
#
set output "run.2014.agent.83.stepdistance.eps"
plot [][0:1001] "run.2014.stepdistance" using 1:253 title "ag83" w points
#
set output "run.2014.agent.84.stepdistance.eps"
plot [][0:1001] "run.2014.stepdistance" using 1:256 title "ag84" w points
#
set output "run.2014.agent.85.stepdistance.eps"
plot [][0:1001] "run.2014.stepdistance" using 1:259 title "ag85" w points
#
set output "run.2014.agent.86.stepdistance.eps"
plot [][0:1001] "run.2014.stepdistance" using 1:262 title "ag86" w points
#
set output "run.2014.agent.87.stepdistance.eps"
plot [][0:1001] "run.2014.stepdistance" using 1:265 title "ag87" w points
#
set output "run.2014.agent.88.stepdistance.eps"
plot [][0:1001] "run.2014.stepdistance" using 1:268 title "ag88" w points
#
set output "run.2014.agent.89.stepdistance.eps"
plot [][0:1001] "run.2014.stepdistance" using 1:271 title "ag89" w points
#
set output "run.2014.agent.90.stepdistance.eps"
plot [][0:1001] "run.2014.stepdistance" using 1:274 title "ag90" w points
#
set output "run.2014.agent.91.stepdistance.eps"
plot [][0:1001] "run.2014.stepdistance" using 1:277 title "ag91" w points
#
set output "run.2014.agent.92.stepdistance.eps"
plot [][0:1001] "run.2014.stepdistance" using 1:280 title "ag92" w points
#
set output "run.2014.agent.93.stepdistance.eps"
plot [][0:1001] "run.2014.stepdistance" using 1:283 title "ag93" w points
#
set output "run.2014.agent.94.stepdistance.eps"
plot [][0:1001] "run.2014.stepdistance" using 1:286 title "ag94" w points
#
set output "run.2014.agent.95.stepdistance.eps"
plot [][0:1001] "run.2014.stepdistance" using 1:289 title "ag95" w points
#
set output "run.2014.agent.96.stepdistance.eps"
plot [][0:1001] "run.2014.stepdistance" using 1:292 title "ag96" w points
#
set output "run.2014.agent.97.stepdistance.eps"
plot [][0:1001] "run.2014.stepdistance" using 1:295 title "ag97" w points
#
set output "run.2014.agent.98.stepdistance.eps"
plot [][0:1001] "run.2014.stepdistance" using 1:298 title "ag98" w points
#
set output "run.2014.agent.99.stepdistance.eps"
plot [][0:1001] "run.2014.stepdistance" using 1:301 title "ag99" w points
#
unset xlabel
unset ylabel

# plot finalavgmemory heatmap
set output "run.2014.finalavgmemory.eps"
set size ratio -1
set title "run.2014: Memory map averaged over all agents"
unset key
set tic scale 0
set palette defined (0 "#FF0000", 1 "#FFFF66", 2 "#00CC00" )
set cbrange [0.0:2.0]
set cblabel "Score"
set xrange [-1:100]
set yrange [-1:100] reverse
set view map
splot "run.2014.finalavgmemory" matrix with image
unset cblabel

# plot foodlocations
set output "run.2014.foodlocations.eps"
set size ratio -1
set title "run.2014: Food locations"
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
splot "run.2014.foodlocations" matrix with image

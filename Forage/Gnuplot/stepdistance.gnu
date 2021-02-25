set term post eps color

set output "run.195.stepdistance.eps"

plot [][0:]\
   "../Output/run.195/run.195.stepdistance" using 1:4 title "ag0" w line lt 1 lc 1,\
   "../Output/run.195/run.195.stepdistance" using 1:7 title "ag1" w line lt 1 lc 2,\
   "../Output/run.195/run.195.stepdistance" using 1:10 title "ag2" w line lt 1 lc 3,\
   "../Output/run.195/run.195.stepdistance" using 1:13 title "ag3" w line lt 1 lc 4,\
   "../Output/run.195/run.195.stepdistance" using 1:16 title "ag4" w line lt 1 lc 5,\
   "../Output/run.195/run.195.stepdistance" using 1:19 title "ag5" w line lt 1 lc 6,\
   "../Output/run.195/run.195.stepdistance" using 1:22 title "ag6" w line lt 1 lc 7,\
   "../Output/run.195/run.195.stepdistance" using 1:25 title "ag7" w line lt 1 lc 8,\
   "../Output/run.195/run.195.stepdistance" using 1:28 title "ag8" w line lt 1 lc 9,\
   "../Output/run.195/run.195.stepdistance" using 1:31 title "ag9" w line lt 1 lc 10

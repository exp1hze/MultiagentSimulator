set term post eps
set output "path1.eps"

plot \
   "../Output/run.1/run.1.path" using 1:2 w line

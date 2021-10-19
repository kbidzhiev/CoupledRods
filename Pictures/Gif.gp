
###########################################
set terminal gif animate delay 5
set output 'Oscilators.gif'
FILE_LEFT = '../Data/Data.dat'

stats FILE_LEFT nooutput


set xrange [*:*]
set yrange [0:4]
set ylabel "Sx"
set xlabel "x"
percentile="P5 P10 P20 P25 P50 P75"
cir=7;

col1="black";
col2="red";
col3="orangel";
col4="#04B431";
col5="#3399FF";
col6="dark-violet";


f(x) = x;
do for [i=1:int(STATS_blocks)-1] {
    plot FILE_LEFT index (i) u ($1):($2) w lp pt cir ps 1.5 lt rgb "red" title columnheader 
}

!eog "./Oscilators.gif" &



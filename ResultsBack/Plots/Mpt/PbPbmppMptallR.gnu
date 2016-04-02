set yrange[-15:5]
set grid
set ytics
set size ratio 1
set ylabel "<mPt>"
set xlabel "Delta"
set key bottom right

set style line 1 lc rgb "blue"
set style line 2 lc rgb "yellow"
set style line 3 lc rgb "orange"
set style line 4 lc rgb "dark-green"
set style line 5 lc rgb "red"
set style line 6 lc rgb "grey"
set style line 7 lc rgb "brown"

#set boxwidth 2 relative
set style data histogram
set style histogram rowstacked
set style fill transparent solid 0.8 noborder
set terminal pngcairo

set title "PbPb-pp, 0-30%, Back"

plot "/home/peibols/ADSPYTHIA/Backreaction/Results/Mpt/PbPbMpt02.dat" u 1:16:17 with errorbars pt 7 t 'R=0.2', "/home/peibols/ADSPYTHIA/Backreaction/Results/Mpt/PbPbMpt03.dat" u 1:16:17 with errorbars pt 7 t 'R=0.3', "/home/peibols/ADSPYTHIA/Backreaction/Results/Mpt/PbPbMpt04.dat" u 1:16:17 with errorbars pt 7 t 'R=0.4', "/home/peibols/ADSPYTHIA/Backreaction/Results/Mpt/PbPbMpt05.dat" u 1:16:17 with errorbars pt 7 t 'R=0.5'
set output "PbPbmppMptAllR.png"
replot

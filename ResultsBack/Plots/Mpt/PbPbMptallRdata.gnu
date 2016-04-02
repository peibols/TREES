set yrange[-15:10]
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

set terminal pngcairo

set title "PbPb MC-Data 0-30%"

plot "<join /home/peibols/ADSPYTHIA/Backreaction/Results/Mpt/PbPbMpt02.dat /home/peibols/ADSPYTHIA/Backreaction/Results/Plots/CMS/PbPbMptR02.txt" u 1:(($14)-($20)):15 with errorbars lt rgb "black" pt 7 t 'R=0.2', "<join /home/peibols/ADSPYTHIA/Backreaction/Results/Mpt/PbPbMpt03.dat /home/peibols/ADSPYTHIA/Backreaction/Results/Plots/CMS/PbPbMptR03.txt" u 1:(($14)-($20)):15 with errorbars lt rgb "red" pt 7 t 'R=0.3', "<join /home/peibols/ADSPYTHIA/Backreaction/Results/Mpt/PbPbMpt04.dat /home/peibols/ADSPYTHIA/Backreaction/Results/Plots/CMS/PbPbMptR04.txt" u 1:(($14)-($20)):15 with errorbars lt rgb "blue" pt 7 t 'R=0.4', "<join /home/peibols/ADSPYTHIA/Backreaction/Results/Mpt/PbPbMpt05.dat /home/peibols/ADSPYTHIA/Backreaction/Results/Plots/CMS/PbPbMptR05.txt" u 1:(($14)-($20)):15 with errorbars lt rgb "green" pt 7 t 'R=0.5'

set output "PbPbMCmData.png"
replot

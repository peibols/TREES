set yrange[-10:10]
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

set title "pp MC-Data PY6"

plot "<join /home/peibols/ADSPYTHIA/Backreaction/Results/Vac/GenMPT/PY6VacMpt02.dat /home/peibols/ADSPYTHIA/Backreaction/Results/Plots/CMS/MptR02.txt" u 1:(($14)-($17)):15 with errorbars lt rgb "black" pt 7 t 'R=0.2', "<join /home/peibols/ADSPYTHIA/Backreaction/Results/Vac/GenMPT/PY6VacMpt03.dat /home/peibols/ADSPYTHIA/Backreaction/Results/Plots/CMS/MptR03.txt" u 1:(($14)-($17)):15 with errorbars lt rgb "red" pt 7 t 'R=0.3', "<join /home/peibols/ADSPYTHIA/Backreaction/Results/Vac/GenMPT/PY6VacMpt04.dat /home/peibols/ADSPYTHIA/Backreaction/Results/Plots/CMS/MptR04.txt" u 1:(($14)-($17)):15 with errorbars lt rgb "blue" pt 7 t 'R=0.4',  "<join /home/peibols/ADSPYTHIA/Backreaction/Results/Vac/GenMPT/PY6VacMpt05.dat /home/peibols/ADSPYTHIA/Backreaction/Results/Plots/CMS/MptR05.txt" u 1:(($14)-($17)):15 with errorbars lt rgb "green" pt 7 t 'R=0.5' 

set output "PY6ppMCmData.png"
replot

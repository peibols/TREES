set yrange[-30:10]
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

set title "pp, R=0.2"

plot "/home/peibols/ADSPYTHIA/Backreaction/Results/Vac/GenMPT/VacMpt02.dat" u 10:xtic(1) ls 5 t '8.0-300.0', "" u 8:xtic(1) ls 4 t '4.0-8.0', "" u 6:xtic(1) ls 3 t '2.0-4.0', "" u 4:xtic(1) ls 2 t '1.0-2.0', "" u 2:xtic(1) ls 1 t '0.5-1.0', "" u 12:xtic(1) ls 7 t '0.-0.5', "" u 0:14:15 with errorbars lt rgb "black" pt 7 notitle, "" u 0:16 w lines dashtype 2 lc rgb "black" notitle	

set output "ppMptR02.png"
replot

set title "pp, R=0.3"

plot "/home/peibols/ADSPYTHIA/Backreaction/Results/Vac/GenMPT/VacMpt03.dat" u 10:xtic(1) ls 5 t '8.0-300.0', "" u 8:xtic(1) ls 4 t '4.0-8.0', "" u 6:xtic(1) ls 3 t '2.0-4.0', "" u 4:xtic(1) ls 2 t '1.0-2.0', "" u 2:xtic(1) ls 1 t '0.5-1.0', "" u 12:xtic(1) ls 7 t '0.-0.5', "" u 0:14:15 with errorbars lt rgb "black" pt 7 notitle, "" u 0:16 w lines dashtype 2 lc rgb "black" notitle	

set output "ppMptR03.png"
replot

set title "pp, R=0.4"

plot "/home/peibols/ADSPYTHIA/Backreaction/Results/Vac/GenMPT/VacMpt04.dat" u 10:xtic(1) ls 5 t '8.0-300.0', "" u 8:xtic(1) ls 4 t '4.0-8.0', "" u 6:xtic(1) ls 3 t '2.0-4.0', "" u 4:xtic(1) ls 2 t '1.0-2.0', "" u 2:xtic(1) ls 1 t '0.5-1.0', "" u 12:xtic(1) ls 7 t '0.-0.5', "" u 0:14:15 with errorbars lt rgb "black" pt 7 notitle, "" u 0:16 w lines dashtype 2 lc rgb "black" notitle	

set output "ppMptR04.png"
replot

set title "pp, R=0.5"

plot "/home/peibols/ADSPYTHIA/Backreaction/Results/Vac/GenMPT/VacMpt05.dat" u 10:xtic(1) ls 5 t '8.0-300.0', "" u 8:xtic(1) ls 4 t '4.0-8.0', "" u 6:xtic(1) ls 3 t '2.0-4.0', "" u 4:xtic(1) ls 2 t '1.0-2.0', "" u 2:xtic(1) ls 1 t '0.5-1.0', "" u 12:xtic(1) ls 7 t '0.-0.5', "" u 0:14:15 with errorbars lt rgb "black" pt 7 notitle, "" u 0:16 w lines dashtype 2 lc rgb "black" notitle	

set output "ppMptR05.png"
replot

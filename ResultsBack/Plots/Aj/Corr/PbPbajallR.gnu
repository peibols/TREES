set yrange[-60:60]
set grid
set ytics
set size ratio 1
set ylabel "<mPt>"
set xlabel "Aj"
set key bottom left

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
set terminal png

set title "Corre, R=0.2, 0-10%, Back"

plot "/home/peibols/ADSPYTHIA/Backreaction/Results/Aj/Corr/1Corre02.dat" u 10:xtic(1) ls 5 t '8.0-300.0', "" u 8:xtic(1) ls 4 t '4.0-8.0', "" u 6:xtic(1) ls 3 t '2.0-4.0', "" u 4:xtic(1) ls 2 t '1.0-2.0', "" u 2:xtic(1) ls 1 t '0.5-1.0', "" u 12:xtic(1) ls 7 t '0.-0.5', "" u 0:13:14 with errorbars lt rgb "black" pt 7 notitle

set output "010CorreAjR02.png"
replot

set title "Corre, R=0.2, 10-30%, Back"

plot "/home/peibols/ADSPYTHIA/Backreaction/Results/Aj/Corr/2Corre02.dat" u 10:xtic(1) ls 5 t '8.0-300.0', "" u 8:xtic(1) ls 4 t '4.0-8.0', "" u 6:xtic(1) ls 3 t '2.0-4.0', "" u 4:xtic(1) ls 2 t '1.0-2.0', "" u 2:xtic(1) ls 1 t '0.5-1.0', "" u 12:xtic(1) ls 7 t '0.-0.5', "" u 0:13:14 with errorbars lt rgb "black" pt 7 notitle

set output "1030CorreAjR02.png"
replot

set title "Corre, R=0.3, 0-10%, Back"

plot "/home/peibols/ADSPYTHIA/Backreaction/Results/Aj/Corr/1Corre03.dat" u 10:xtic(1) ls 5 t '8.0-300.0', "" u 8:xtic(1) ls 4 t '4.0-8.0', "" u 6:xtic(1) ls 3 t '2.0-4.0', "" u 4:xtic(1) ls 2 t '1.0-2.0', "" u 2:xtic(1) ls 1 t '0.5-1.0', "" u 12:xtic(1) ls 7 t '0.-0.5', "" u 0:13:14 with errorbars lt rgb "black" pt 7 notitle

set output "010CorreAjR03.png"
replot

set title "Corre, R=0.3, 10-30%, Back"

plot "/home/peibols/ADSPYTHIA/Backreaction/Results/Aj/Corr/2Corre03.dat" u 10:xtic(1) ls 5 t '8.0-300.0', "" u 8:xtic(1) ls 4 t '4.0-8.0', "" u 6:xtic(1) ls 3 t '2.0-4.0', "" u 4:xtic(1) ls 2 t '1.0-2.0', "" u 2:xtic(1) ls 1 t '0.5-1.0', "" u 12:xtic(1) ls 7 t '0.-0.5', "" u 0:13:14 with errorbars lt rgb "black" pt 7 notitle

set output "1030CorreAjR03.png"
replot

set title "Corre, R=0.4, 0-10%, Back"

plot "/home/peibols/ADSPYTHIA/Backreaction/Results/Aj/Corr/1Corre04.dat" u 10:xtic(1) ls 5 t '8.0-300.0', "" u 8:xtic(1) ls 4 t '4.0-8.0', "" u 6:xtic(1) ls 3 t '2.0-4.0', "" u 4:xtic(1) ls 2 t '1.0-2.0', "" u 2:xtic(1) ls 1 t '0.5-1.0', "" u 12:xtic(1) ls 7 t '0.-0.5', "" u 0:13:14 with errorbars lt rgb "black" pt 7 notitle

set output "010CorreAjR04.png"
replot

set title "Corre, R=0.4, 10-30%, Back"

plot "/home/peibols/ADSPYTHIA/Backreaction/Results/Aj/Corr/2Corre04.dat" u 10:xtic(1) ls 5 t '8.0-300.0', "" u 8:xtic(1) ls 4 t '4.0-8.0', "" u 6:xtic(1) ls 3 t '2.0-4.0', "" u 4:xtic(1) ls 2 t '1.0-2.0', "" u 2:xtic(1) ls 1 t '0.5-1.0', "" u 12:xtic(1) ls 7 t '0.-0.5', "" u 0:13:14 with errorbars lt rgb "black" pt 7 notitle

set output "1030CorreAjR04.png"
replot

set title "Corre, R=0.5, 0-10%, Back"

plot "/home/peibols/ADSPYTHIA/Backreaction/Results/Aj/Corr/1Corre05.dat" u 10:xtic(1) ls 5 t '8.0-300.0', "" u 8:xtic(1) ls 4 t '4.0-8.0', "" u 6:xtic(1) ls 3 t '2.0-4.0', "" u 4:xtic(1) ls 2 t '1.0-2.0', "" u 2:xtic(1) ls 1 t '0.5-1.0', "" u 12:xtic(1) ls 7 t '0.-0.5', "" u 0:13:14 with errorbars lt rgb "black" pt 7 notitle

set output "010CorreAjR05.png"
replot

set title "Corre, R=0.5, 10-30%, Back"

plot "/home/peibols/ADSPYTHIA/Backreaction/Results/Aj/Corr/2Corre05.dat" u 10:xtic(1) ls 5 t '8.0-300.0', "" u 8:xtic(1) ls 4 t '4.0-8.0', "" u 6:xtic(1) ls 3 t '2.0-4.0', "" u 4:xtic(1) ls 2 t '1.0-2.0', "" u 2:xtic(1) ls 1 t '0.5-1.0', "" u 12:xtic(1) ls 7 t '0.-0.5', "" u 0:13:14 with errorbars lt rgb "black" pt 7 notitle

set output "1030CorreAjR05.png"
replot

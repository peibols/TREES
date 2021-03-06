set yrange[-50:50]
set grid
set ytics
set size ratio 1
set ylabel "<mPt>"
set xlabel "Aj"
set key top right

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

set title "PbPb-pp, R=0.2, 0-10%, NoBack"

plot "/home/peibols/ADSPYTHIA/Backreaction/Results/Aj/1difAj02nb.dat" u 10:xtic(1) ls 5 t '8.0-300.0', "" u 8:xtic(1) ls 4 t '4.0-8.0', "" u 6:xtic(1) ls 3 t '2.0-4.0', "" u 4:xtic(1) ls 2 t '1.0-2.0', "" u 2:xtic(1) ls 1 t '0.5-1.0', "" u 12:xtic(1) ls 7 t '0.-0.5', "" u 0:14:15 with errorbars lt rgb "black" pt 7 notitle

set output "dif010PbPbAjR02nb.png"
replot

set title "PbPb-pp, R=0.2, 10-30%, NoBack"

plot "/home/peibols/ADSPYTHIA/Backreaction/Results/Aj/2difAj02nb.dat" u 10:xtic(1) ls 5 t '8.0-300.0', "" u 8:xtic(1) ls 4 t '4.0-8.0', "" u 6:xtic(1) ls 3 t '2.0-4.0', "" u 4:xtic(1) ls 2 t '1.0-2.0', "" u 2:xtic(1) ls 1 t '0.5-1.0', "" u 12:xtic(1) ls 7 t '0.-0.5', "" u 0:14:15 with errorbars lt rgb "black" pt 7 notitle

set output "dif1030PbPbAjR02nb.png"
replot

set title "PbPb-pp, R=0.3, 0-10%, NoBack"

plot "/home/peibols/ADSPYTHIA/Backreaction/Results/Aj/1difAj03nb.dat" u 10:xtic(1) ls 5 t '8.0-300.0', "" u 8:xtic(1) ls 4 t '4.0-8.0', "" u 6:xtic(1) ls 3 t '2.0-4.0', "" u 4:xtic(1) ls 2 t '1.0-2.0', "" u 2:xtic(1) ls 1 t '0.5-1.0', "" u 12:xtic(1) ls 7 t '0.-0.5', "" u 0:14:15 with errorbars lt rgb "black" pt 7 notitle

set output "dif010PbPbAjR03nb.png"
replot

set title "PbPb-pp, R=0.3, 10-30%, NoBack"

plot "/home/peibols/ADSPYTHIA/Backreaction/Results/Aj/2difAj03nb.dat" u 10:xtic(1) ls 5 t '8.0-300.0', "" u 8:xtic(1) ls 4 t '4.0-8.0', "" u 6:xtic(1) ls 3 t '2.0-4.0', "" u 4:xtic(1) ls 2 t '1.0-2.0', "" u 2:xtic(1) ls 1 t '0.5-1.0', "" u 12:xtic(1) ls 7 t '0.-0.5', "" u 0:14:15 with errorbars lt rgb "black" pt 7 notitle

set output "dif1030PbPbAjR03nb.png"
replot

set title "PbPb-pp, R=0.4, 0-10%, NoBack"

plot "/home/peibols/ADSPYTHIA/Backreaction/Results/Aj/1difAj04nb.dat" u 10:xtic(1) ls 5 t '8.0-300.0', "" u 8:xtic(1) ls 4 t '4.0-8.0', "" u 6:xtic(1) ls 3 t '2.0-4.0', "" u 4:xtic(1) ls 2 t '1.0-2.0', "" u 2:xtic(1) ls 1 t '0.5-1.0', "" u 12:xtic(1) ls 7 t '0.-0.5', "" u 0:14:15 with errorbars lt rgb "black" pt 7 notitle

set output "dif010PbPbAjR04nb.png"
replot

set title "PbPb-pp, R=0.4, 10-30%, NoBack"

plot "/home/peibols/ADSPYTHIA/Backreaction/Results/Aj/2difAj04nb.dat" u 10:xtic(1) ls 5 t '8.0-300.0', "" u 8:xtic(1) ls 4 t '4.0-8.0', "" u 6:xtic(1) ls 3 t '2.0-4.0', "" u 4:xtic(1) ls 2 t '1.0-2.0', "" u 2:xtic(1) ls 1 t '0.5-1.0', "" u 12:xtic(1) ls 7 t '0.-0.5', "" u 0:14:15 with errorbars lt rgb "black" pt 7 notitle

set output "dif1030PbPbAjR04nb.png"
replot

set title "PbPb-pp, R=0.5, 0-10%, NoBack"

plot "/home/peibols/ADSPYTHIA/Backreaction/Results/Aj/1difAj05nb.dat" u 10:xtic(1) ls 5 t '8.0-300.0', "" u 8:xtic(1) ls 4 t '4.0-8.0', "" u 6:xtic(1) ls 3 t '2.0-4.0', "" u 4:xtic(1) ls 2 t '1.0-2.0', "" u 2:xtic(1) ls 1 t '0.5-1.0', "" u 12:xtic(1) ls 7 t '0.-0.5', "" u 0:14:15 with errorbars lt rgb "black" pt 7 notitle

set output "dif010PbPbAjR05nb.png"
replot

set title "PbPb-pp, R=0.5, 10-30%, NoBack"

plot "/home/peibols/ADSPYTHIA/Backreaction/Results/Aj/2difAj05nb.dat" u 10:xtic(1) ls 5 t '8.0-300.0', "" u 8:xtic(1) ls 4 t '4.0-8.0', "" u 6:xtic(1) ls 3 t '2.0-4.0', "" u 4:xtic(1) ls 2 t '1.0-2.0', "" u 2:xtic(1) ls 1 t '0.5-1.0', "" u 12:xtic(1) ls 7 t '0.-0.5', "" u 0:14:15 with errorbars lt rgb "black" pt 7 notitle

set output "dif1030PbPbAjR05nb.png"
replot


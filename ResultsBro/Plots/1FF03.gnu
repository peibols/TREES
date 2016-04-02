set size (1.,1.)
set mxtics
set xrange[0:5]
set mytics
set termoption dash
set border linewidth 3   
set yrange[0.2:2.5]
set style line 1 lc rgb '#000000'  
set style line 2 lc rgb '#0000CD'
set style line 3 lc rgb '#FF0000'
set style line 4 lc rgb '#228B22'
set style line 6 lc rgb '#DAA520'
set style line 5 lt 2 lc rgb 'black' lw 2
set ylabel "PbPb/pp"
set xlabel "ln(1/z)"
set style fill transparent solid 0.5 noborder
set key at 2,2.2
set label 1 "$0-10\\%$" at 3,2.1
f(x)=1.

plot '../BRO0/FF03.dat' w filledcu t 'K=0' ls 1, '../BRO3/FF03.dat' w filledcu t 'K=20' ls 2, '../BRO6/FF03.dat' w filledcu t 'K=40' ls 3, '../BRO5/FF03.dat' w filledcu t 'K=100' ls 6, f(x) ls 5 notitle, 'CMS/DataFFfullNEW0-10' u 1:2:($2-sqrt($3*$3+($2-$4)*($2-$4))):($2+sqrt($3*$3+($5-$2)*($5-$2))) with errorbars linecolor rgb "black" pt 7 ps 0.7 t 'CMS Data'

set terminal cairolatex truecolor
set output 'raa.tex'
replot

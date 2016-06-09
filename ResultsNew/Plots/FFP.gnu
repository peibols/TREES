set size (1.,1.)
set mxtics
set xrange[-0.5:4]
set mytics
set termoption dash
set border linewidth 3
set style line 1 lc rgb '#000000'   
set yrange[0.3:2]
set style line 2 lc rgb '#0000CD'
set style line 3 lc rgb '#FF0000'
set style line 4 lc rgb '#228B22'
set style line 5 lt 2 lc rgb 'black' lw 2
set ylabel "PbPb/pp"
set xlabel "ln(1/z)"
set style fill transparent solid 0.5 noborder
set key at 3.8,1.8
set label 1 "$0-30\\%$" at 2.6,1.2
set label 2 "$P_T^{Z^0}>60$ GeV, $P_T^{jet}>30$ GeV" at -0.1,1.75
set label 4 "$P_T^{parton}>1$ GeV" at -0.1,1.6
set label 3 "$|\\eta_{jet}|<1.6$, $|\\eta_{Z^0}|<2.5$, $r<0.3$" at -0.1,1.45
f(x)=1.

plot '../Strong/BRO0/FFP30.dat' u 1:2:3 w filledcu t 'Strong Coupling' ls 3, '../Rad/BRO0/FFP30.dat' u 1:2:3 w filledcu t 'Radiative' ls 1, '../Coll/BRO0/FFP30.dat' u 1:2:3 w filledcu t 'Collisional' ls 2,  f(x) ls 5 notitle

set terminal cairolatex truecolor
set output 'raa.tex'
replot

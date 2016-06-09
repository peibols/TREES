set yrange[0:2]
set xrange[35:130]
set mxtics
set mytics
set border linewidth 3
set style line 1 lc rgb '#000000'
set style line 2 lc rgb '#0000CD'
set style line 3 lc rgb '#FF0000'
set style line 4 lc rgb '#228B22'
set ylabel "$I_{AA}$" 
set xlabel "Jet $P_T$" 

set style fill transparent solid 0.5 noborder
set label 1 "$0-30\\%$ Centrality" at 72,0.25
set label 4 "$P_{T}^{Z^0}$ $>$ $80$ GeV" at 105,1.2

set key at 125,1.8

plot '../Strong/BRO0/IAA230.dat' u 1:2:3 w filledcu t 'Strong Coupling' ls 3, '../Rad/BRO0/IAA230.dat' u 1:2:3 w filledcu t 'Radiative' ls 1, '../Coll/BRO0/IAA230.dat' u 1:2:3 w filledcu t 'Collisional' ls 2

set output 'raa.tex'
set terminal cairolatex truecolor
replot

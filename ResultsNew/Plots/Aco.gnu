set size (1.,1.)
set mxtics
Pi=3.14159265359
set xrange[0:Pi]
set mytics

set termoption dash
set border linewidth 3   

set style line 1 lc rgb '#000000'  
set style line 2 lc rgb '#0000CD'
set style line 3 lc rgb '#FF0000'
set style line 4 lc rgb '#228B22'
set style line 6 lc rgb '#DAA520'
set style line 5 lt 2 lc rgb 'black' lw 2
set ylabel "$\\frac{1}{N_{Z^0}}\\frac{dN_{JZ^0}}{d \\Delta \\phi_{JZ}}$"
set xlabel "$\\Delta \\phi$"
set style fill transparent solid 0.5 noborder
set key at 1.2,2.7
set label 2 "$P_T^{Z^0}>60$ GeV, $P_T^{jet}>30$ GeV" at 1.35,2.5
set label 3 "$|\\eta_{jet}|<1.6$, $|\\eta_{Z^0}|<2.5$" at 1.35,2.2
set label 1 "$0-30\\%$" at 1.35,1.9

f(x)=1.

plot '../Strong/BRO0/Aco030.dat' u 1:2:3 w filledcu t 'Strong Coupling' ls 3, '../Rad/BRO0/Aco030.dat' u 1:2:3 w filledcu t 'Radiative' ls 1, '../Coll/BRO0/Aco030.dat' u 1:2:3 w filledcu t 'Collisional' ls 2, '../Strong/BRO0/Aco030.dat' u 1:4:5 with errorbars pt 7 ps 0.5 lc rgb "violet" t 'Smeared pp', 'CMS/AcoMed.dat' u 1:2:(abs(($2)-($3))) with errorbars pt 7 ps 0.5 lc rgb "black" t 'PbPb CMS' 

set terminal cairolatex truecolor
set output 'raa.tex'
replot

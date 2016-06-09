set yrange[0:1]
set xrange[40:115]
set mxtics
set mytics
set border linewidth 3
set style line 1 lc rgb '#000000'
set style line 2 lc rgb '#0000CD'
set style line 3 lc rgb '#FF0000'
set style line 4 lc rgb '#228B22'
set ylabel "$R_{JZ^0}$" 
set xlabel "$P_T^{Z^0}$"

set style fill transparent solid 0.5 noborder
set label 1 "$0-30\\%$ Centrality" at 80,0.9
set label 2 "$P_{T}^{jet}>30$ GeV" at 90,0.25
set label 3 "$\\Delta \\phi$ $>$ $7 \\pi /8$" at 90,0.17

set key at 70,0.95
f(x,y)=x*0.5+y*0.5
g(x,y)=sqrt(x*x*0.5*0.5+y*y*0.5*0.5)

plot '../Strong/BRO0/RJG030.dat' u 1:2:3 w filledcu t 'Strong Coupling' ls 3, '../Rad/BRO0/RJG030.dat' u 1:2:3 w filledcu t 'Radiative' ls 1, '../Coll/BRO0/RJG030.dat' u 1:2:3 w filledcu t 'Collisional' ls 2, "<join RJGA RJGB" u 1:(f(($2),($4))):(g(($3),($5))) with errorbars linecolor rgb "violet" pt 7 ps 0.5 t 'Smeared pp', 'CMS/RjzMed.dat' u 1:2:(abs(($2)-($3))) with errorbars pt 7 ps 0.5 lc rgb "black" t 'PbPb CMS' 

set output 'raa.tex'
set terminal cairolatex truecolor
replot

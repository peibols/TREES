set yrange[0:1.2]
set size (1.,1.)
set xrange[100:300]
set xtics autofreq 20
set mxtics
set mytics
set border linewidth 3
set style line 1 lc rgb '#000000'  
set style line 2 lc rgb '#0000CD'
set style line 3 lc rgb '#FF0000'
set style line 4 lc rgb '#228B22'
#set terminal png truecolor
set ylabel "Jet $R_{AA}$" 
set xlabel "$P_T$ (GeV)" 
set key at 150,1.1
set label 1 "0-10$\\%$ Centrality"  at 220,0.18

set style fill transparent solid 0.5 noborder

plot "../RAA/1RAA03.dat" w filledcu t 'R=0.3' ls 2,  "CMS/Rdata0-10.txt" using 1:3:2:4 with xyerrorbars t 'Data' lt 1 lw 4 linecolor "black"

set terminal cairolatex truecolor
set output 'raa.tex'
replot

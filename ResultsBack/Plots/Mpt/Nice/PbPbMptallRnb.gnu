set yrange[-45:15]
set ytics

set size ratio 1
set ylabel "$\\langle \\slashed{p}_T^{\\parallel} \\rangle$"
set xlabel "$\\Delta$"
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

f(x,y,z,w,t)=x+y+z+w+t
g(x,y,z,w,t)=sqrt(x**2+y**2+z**2+w**2+t**2)

#set label 1 "PbPb R=0.3, 0-30\\%" at 4,-20
set label 2 "Back-reaction OFF"	at 2,10

unset key

plot "/home/peibols/ADSPYTHIA/Backreaction/Results/Mpt/PbPbMpt03nb.dat" u 10:xtic(1) ls 5 t '8.0-300.0', "" u 8:xtic(1) ls 4 t '4.0-8.0', "" u 6:xtic(1) ls 3 t '2.0-4.0', "" u 4:xtic(1) ls 2 t '1.0-2.0', "" u 2:xtic(1) ls 1 t '0.5-1.0', "" u 0:14:15 with errorbars lt rgb "black" pt 7 ps 0.6 t "$\\langle \\slashed{p}_T^{\\parallel} \\rangle_{\\Delta}$", "" u 0:18 w lines dashtype 1 lt rgb "black" notitle, "/home/peibols/ADSPYTHIA/Backreaction/Results/Vac/GenMPT/VacMpt03.dat" u 0:16 w lines dashtype 2 lc rgb "black" notitle	 

set terminal cairolatex truecolor
set output 'raa.tex'
replot

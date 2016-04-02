set terminal cairolatex pdf color size 6,6
set macros

set yrange[-13:5]
set ytics
set size ratio 1
set xlabel "$\\Delta$"
set key bottom right

set style line 1 lc rgb "blue"
set style line 2 lc rgb "yellow"
set style line 3 lc rgb "orange"
set style line 4 lc rgb "dark-green"
set style line 5 lc rgb "red"
set style line 6 lc rgb "grey"
set style line 7 lc rgb "brown"

# Margins for each row resp. column
TMARGIN = "set tmargin at screen 0.95; set bmargin at screen 0.5"
Tv2MARGIN = "set tmargin at screen 0.85; set bmargin at screen 0.5"
BMARGIN = "set tmargin at screen 0.75; set bmargin at screen 0.15"
Bv2MARGIN = "set tmargin at screen 0.5; set bmargin at screen 0.15"
LMARGIN = "set lmargin at screen 0.1; set rmargin at screen 0.45"
RMARGIN = "set lmargin at screen 0.45; set rmargin at screen 0.85"

#set boxwidth 2 relative
set style data histogram
set style histogram rowstacked
set style fill transparent solid 0.8 noborder

everyfifth(col) = (column(col) == 0.1 || column(col) == 0.5 || column(col) == 0.9 || column(col) == 1.3 || column(col) == 1.7) ? stringcolumn(col) : ""

f(x,y,z,w,t)=x+y+z+w+t
g(x,y,z,w,t)=sqrt(x**2+y**2+z**2+w**2+t**2)

unset key
set output 'raa.tex'
set multiplot layout 2,2 rowsfirst


set ylabel "$\\langle \\slashed{p}_T^{\\parallel} \\rangle$"
unset xlabel
unset xtics
set label 1 "R=0.2" at graph 0.74,0.46
set label 2 "PbPb-pp, 0-30\\%" at graph 0.46,0.23
set ytics -12,4,4
@TMARGIN; @LMARGIN

plot "/home/peibols/ADSPYTHIA/Backreaction/Results/Mpt/NoCorr/PbPbmppMpt02.dat" u 10:xtic(everyfifth(1)) ls 5 t '8.0-300.0', "" u 8:xtic(everyfifth(1)) ls 4 t '4.0-8.0', "" u 6:xtic(everyfifth(1)) ls 3 t '2.0-4.0', "" u 4:xtic(everyfifth(1)) ls 2 t '1.0-2.0', "" u 2:xtic(everyfifth(1)) ls 1 t '0.5-1.0', "" u 0:14:15 with errorbars lt rgb "black" pt 7 ps 0.6 t "$\\langle \\slashed{p}_T^{\\parallel} \\rangle_{\\Delta}$"


unset ylabel
unset ytics
unset xlabel
unset xtics
set label 1 "R=0.3" at graph 0.74,0.46
unset label 2
@Tv2MARGIN; @RMARGIN

plot "/home/peibols/ADSPYTHIA/Backreaction/Results/Mpt/NoCorr/PbPbmppMpt03.dat" u 10:xtic(everyfifth(1)) ls 5 t '8.0-300.0', "" u 8:xtic(everyfifth(1)) ls 4 t '4.0-8.0', "" u 6:xtic(everyfifth(1)) ls 3 t '2.0-4.0', "" u 4:xtic(everyfifth(1)) ls 2 t '1.0-2.0', "" u 2:xtic(everyfifth(1)) ls 1 t '0.5-1.0', "" u 0:14:15 with errorbars lt rgb "black" pt 7 ps 0.6 t "$\\langle \\slashed{p}_T^{\\parallel} \\rangle_{\\Delta}$"

set ytics
set ylabel "$\\langle \\slashed{p}_T^{\\parallel} \\rangle$"
set xlabel "$\\Delta$"
set xtics
set label 1 "R=0.4" at graph 0.74,0.46
@BMARGIN; @LMARGIN
set ylabel "$\\langle \\slashed{p}_T^{\\parallel} \\rangle$"

plot "/home/peibols/ADSPYTHIA/Backreaction/Results/Mpt/NoCorr/PbPbmppMpt04.dat" u 10:xtic(everyfifth(1)) ls 5 t '8.0-300.0', "" u 8:xtic(everyfifth(1)) ls 4 t '4.0-8.0', "" u 6:xtic(everyfifth(1)) ls 3 t '2.0-4.0', "" u 4:xtic(everyfifth(1)) ls 2 t '1.0-2.0', "" u 2:xtic(everyfifth(1)) ls 1 t '0.5-1.0', "" u 0:14:15 with errorbars lt rgb "black" pt 7 ps 0.6 t "$\\langle \\slashed{p}_T^{\\parallel} \\rangle_{\\Delta}$"

unset ytics
unset ylabel
set key
set label 1 "R=0.5" at graph 0.74,0.46
set xlabel "$\\Delta$"
@Bv2MARGIN; @RMARGIN

plot "/home/peibols/ADSPYTHIA/Backreaction/Results/Mpt/NoCorr/PbPbmppMpt05.dat" u 10:xtic(everyfifth(1)) ls 5 t '8.0-300.0', "" u 8:xtic(everyfifth(1)) ls 4 t '4.0-8.0', "" u 6:xtic(everyfifth(1)) ls 3 t '2.0-4.0', "" u 4:xtic(everyfifth(1)) ls 2 t '1.0-2.0', "" u 2:xtic(everyfifth(1)) ls 1 t '0.5-1.0', "" u 0:14:15 with errorbars lt rgb "black" pt 7 ps 0.6 t "$\\langle \\slashed{p}_T^{\\parallel} \\rangle_{\\Delta}$"

unset multiplot

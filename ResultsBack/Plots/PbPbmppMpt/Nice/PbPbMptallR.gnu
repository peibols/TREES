set terminal cairolatex pdf color size 6,6
set macros

set yrange[-13:5]
set ytics
set size ratio 1
set xlabel "$\\Delta$"
set key bottom right

set xtics font ", 100"

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

f(x,y,z,w,t)=x+y+z+w+t
g(x,y,z,w,t)=sqrt(x**2+y**2+z**2+w**2+t**2)

unset key
set output 'raa.tex'

set multiplot layout 2,2 rowsfirst

set ylabel "$\\langle \\slashed{p}_T^{\\parallel} \\rangle$"
unset xlabel
unset xtics
@TMARGIN; @LMARGIN

plot "/home/peibols/ADSPYTHIA/Backreaction/Results/Mpt/NoCorr/PbPbmppMpt02.dat" u 10:xtic(1) ls 5 t '8.0-300.0', "" u 8:xtic(1) ls 4 t '4.0-8.0', "" u 6:xtic(1) ls 3 t '2.0-4.0', "" u 4:xtic(1) ls 2 t '1.0-2.0', "" u 2:xtic(1) ls 1 t '0.5-1.0', "" u 12:xtic(1) ls 7 t '0.-0.5', "" u 0:14:15 with errorbars lt rgb "black" pt 7 notitle


unset ylabel
unset ytics
unset xlabel
unset xtics
@Tv2MARGIN; @RMARGIN

plot "/home/peibols/ADSPYTHIA/Backreaction/Results/Mpt/NoCorr/PbPbmppMpt03.dat" u 10:xtic(1) ls 5 t '8.0-300.0', "" u 8:xtic(1) ls 4 t '4.0-8.0', "" u 6:xtic(1) ls 3 t '2.0-4.0', "" u 4:xtic(1) ls 2 t '1.0-2.0', "" u 2:xtic(1) ls 1 t '0.5-1.0', "" u 12:xtic(1) ls 7 t '0.-0.5', "" u 0:14:15 with errorbars lt rgb "black" pt 7 notitle

set ytics
set ylabel "$\\langle \\slashed{p}_T^{\\parallel} \\rangle$"
set xlabel "$\\Delta$"
set xtics

@BMARGIN; @LMARGIN
set ylabel "$\\langle \\slashed{p}_T^{\\parallel} \\rangle$"

plot "/home/peibols/ADSPYTHIA/Backreaction/Results/Mpt/NoCorr/PbPbmppMpt04.dat" u 10:xtic(1) ls 5 t '8.0-300.0', "" u 8:xtic(1) ls 4 t '4.0-8.0', "" u 6:xtic(1) ls 3 t '2.0-4.0', "" u 4:xtic(1) ls 2 t '1.0-2.0', "" u 2:xtic(1) ls 1 t '0.5-1.0', "" u 12:xtic(1) ls 7 t '0.-0.5', "" u 0:14:15 with errorbars lt rgb "black" pt 7 notitle

unset ytics
unset ylabel
set key

set xlabel "$\\Delta$"
@Bv2MARGIN; @RMARGIN

plot "/home/peibols/ADSPYTHIA/Backreaction/Results/Mpt/NoCorr/PbPbmppMpt05.dat" u 10:xtic(1) ls 5 t '8.0-300.0', "" u 8:xtic(1) ls 4 t '4.0-8.0', "" u 6:xtic(1) ls 3 t '2.0-4.0', "" u 4:xtic(1) ls 2 t '1.0-2.0', "" u 2:xtic(1) ls 1 t '0.5-1.0', "" u 12:xtic(1) ls 7 t '0.-0.5', "" u 0:14:15 with errorbars lt rgb "black" pt 7 notitle

unset multiplot

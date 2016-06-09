rm /home/peibols/NewHD/UliInv/UliFolder/Zeta502/ResultsNew/Strong/BRO0/RJG030.dat
rm /home/peibols/NewHD/UliInv/UliFolder/Zeta502/ResultsNew/Rad/BRO0/RJG030.dat
rm /home/peibols/NewHD/UliInv/UliFolder/Zeta502/ResultsNew/Coll/BRO0/RJG030.dat
rm /home/peibols/NewHD/UliInv/UliFolder/Zeta502/ResultsNew/Strong/BRO0/RJG031.dat
rm /home/peibols/NewHD/UliInv/UliFolder/Zeta502/ResultsNew/Rad/BRO0/RJG031.dat
rm /home/peibols/NewHD/UliInv/UliFolder/Zeta502/ResultsNew/Coll/BRO0/RJG031.dat

g++ fourIAA1.cc -o fourIAA1
g++ fourIAA2.cc -o fourIAA2
g++ fourIMB030.cc -o fourIMB030
g++ fourRJGL.cc -o fourRJGL
g++ fourRJG.cc -o fourRJG
g++ fourAco030.cc -o fourAco030
g++ fourFF.cc -o fourFF

./fourIAA1 1 0 0
./fourIAA1 1 0 1
./fourIAA1 2 0 0
./fourIAA1 2 0 1
./fourIAA1 3 0 0
./fourIAA1 3 0 1

./fourIAA2 1 0 0
./fourIAA2 1 0 1
./fourIAA2 2 0 0
./fourIAA2 2 0 1
./fourIAA2 3 0 0
./fourIAA2 3 0 1

./fourIMB030 1 0 0
./fourIMB030 1 0 1
./fourIMB030 2 0 0
./fourIMB030 2 0 1
./fourIMB030 3 0 0
./fourIMB030 3 0 1

./fourRJGL 1 0 0
./fourRJGL 1 0 1
./fourRJGL 2 0 0
./fourRJGL 2 0 1
./fourRJGL 3 0 0
./fourRJGL 3 0 1

./fourRJG 1 0 0
./fourRJG 1 0 1
./fourRJG 2 0 0
./fourRJG 2 0 1
./fourRJG 3 0 0
./fourRJG 3 0 1

./fourAco030 1 0 0
./fourAco030 1 0 1
./fourAco030 2 0 0
./fourAco030 2 0 1
./fourAco030 3 0 0
./fourAco030 3 0 1

./fourFF 1 0 0
./fourFF 1 0 1
./fourFF 2 0 0
./fourFF 2 0 1
./fourFF 3 0 0
./fourFF 3 0 1


sed -i 's/FFP/FFJ/g' fourFF.cc
sed -i 's/N=34/N=29/g' fourFF.cc

g++ fourFF.cc -o fourFF

./fourFF 1 0 0
./fourFF 1 0 1
./fourFF 2 0 0
./fourFF 2 0 1
./fourFF 3 0 0
./fourFF 3 0 1

sed -i 's/FFJ/FFP/g' fourFF.cc
sed -i 's/N=29/N=34/g' fourFF.cc


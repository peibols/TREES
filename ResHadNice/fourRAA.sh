g++ fourRAA.cc -o fourRAA
./fourRAA
g++ fourRAAnb.cc -o fourRAAnb
./fourRAAnb

sed -i 's/02.txt/03.txt/g' fourRAA.cc
sed -i 's/02.txt/03.txt/g' fourRAAnb.cc

g++ fourRAA.cc -o fourRAA
./fourRAA
g++ fourRAAnb.cc -o fourRAAnb
./fourRAAnb

sed -i 's/03.txt/04.txt/g' fourRAA.cc
sed -i 's/03.txt/04.txt/g' fourRAAnb.cc

g++ fourRAA.cc -o fourRAA
./fourRAA
g++ fourRAAnb.cc -o fourRAAnb
./fourRAAnb

sed -i 's/04.txt/05.txt/g' fourRAA.cc
sed -i 's/04.txt/05.txt/g' fourRAAnb.cc

g++ fourRAA.cc -o fourRAA
./fourRAA
g++ fourRAAnb.cc -o fourRAAnb
./fourRAAnb

sed -i 's/05.txt/06.txt/g' fourRAA.cc
sed -i 's/05.txt/06.txt/g' fourRAAnb.cc

g++ fourRAA.cc -o fourRAA
./fourRAA
g++ fourRAAnb.cc -o fourRAAnb
./fourRAAnb

sed -i 's/06.txt/08.txt/g' fourRAA.cc
sed -i 's/06.txt/08.txt/g' fourRAAnb.cc

g++ fourRAA.cc -o fourRAA
./fourRAA
g++ fourRAAnb.cc -o fourRAAnb
./fourRAAnb

sed -i 's/08.txt/1.txt/g' fourRAA.cc
sed -i 's/08.txt/1.txt/g' fourRAAnb.cc

g++ fourRAA.cc -o fourRAA
./fourRAA
g++ fourRAAnb.cc -o fourRAAnb
./fourRAAnb

sed -i 's/1.txt/12.txt/g' fourRAA.cc
sed -i 's/1.txt/12.txt/g' fourRAAnb.cc

g++ fourRAA.cc -o fourRAA
./fourRAA
g++ fourRAAnb.cc -o fourRAAnb
./fourRAAnb

sed -i 's/12.txt/14.txt/g' fourRAA.cc
sed -i 's/12.txt/14.txt/g' fourRAAnb.cc

g++ fourRAA.cc -o fourRAA
./fourRAA
g++ fourRAAnb.cc -o fourRAAnb
./fourRAAnb

sed -i 's/14.txt/02.txt/g' fourRAA.cc
sed -i 's/14.txt/02.txt/g' fourRAAnb.cc

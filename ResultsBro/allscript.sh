g++ fourRAA.cc -o fourRAA
g++ fourFF.cc -o fourFF
g++ fourShap.cc -o fourShap

for (( i=0; i <=6; i++))
do
	for (( j=2; j <=5; j++))
	do
        	./fourRAA  $j $i
		./fourShap  $j $i
		./fourFF  $j $i
	done
done


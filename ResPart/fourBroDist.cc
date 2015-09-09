#include <iostream>
#include <fstream>
#include <iomanip>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

using namespace std;

int main () {

        ofstream built;
        built.open ("BRO0/BroDistQ");
        std::ifstream infile1("BRO0/1centA/BroDistQ.txt");
        std::ifstream infile2("BRO0/2centA/BroDistQ.txt");
        std::ifstream infile3("BRO0/3centA/BroDistQ.txt");
        std::ifstream infile4("BRO0/4centA/BroDistQ.txt");
        std::ifstream infile5("BRO0/1centB/BroDistQ.txt");
        std::ifstream infile6("BRO0/2centB/BroDistQ.txt");
        std::ifstream infile7("BRO0/3centB/BroDistQ.txt");
        std::ifstream infile8("BRO0/4centB/BroDistQ.txt");

        double w1[4],w2[4];
        w1[0]=0.563;
        w2[0]=0.437;
        w1[1]=0.624;
        w2[1]=0.376;
        w1[2]=0.659;
        w2[2]=0.341;
        w1[3]=0.706;
        w2[3]=0.294;

        double y[6],z[6],w,dw;
        double a,b[6],db[6],d[6],dd[6];
        int bin=0;
        int N=49;
        int cent=0;
        do {
                infile1 >> a >> b[0] >> db[0] >> b[1] >> db[1] >> b[2] >> db[2] >> b[3] >> db[3] >> b[4] >> db[4] >> b[5] >> db[5];
                infile5 >> a >> d[0] >> dd[0] >> d[1] >> dd[1] >> d[2] >> dd[2] >> d[3] >> dd[3] >> d[4] >> dd[4] >> d[5] >> dd[5];
		for (unsigned e=0; e<6; e++) {
	                w=w1[cent]*b[e]+w2[cent]*d[e];
	                dw=sqrt(pow(w1[cent]*db[e],2.)+pow(w2[cent]*dd[e],2.));
	                y[e]=w+dw;
	                z[e]=w-dw;
		}

		infile2 >> a >> b[0] >> db[0] >> b[1] >> db[1] >> b[2] >> db[2] >> b[3] >> db[3] >> b[4] >> db[4] >> b[5] >> db[5];
                infile6 >> a >> d[0] >> dd[0] >> d[1] >> dd[1] >> d[2] >> dd[2] >> d[3] >> dd[3] >> d[4] >> dd[4] >> d[5] >> dd[5];
		for (unsigned e=0; e<6; e++) {
	                w=w1[cent]*b[e]+w2[cent]*d[e];
	                dw=sqrt(pow(w1[cent]*db[e],2.)+pow(w2[cent]*dd[e],2.));
	                if (w+dw>y[e]) y[e]=w+dw;
	                if (w-dw<z[e]) z[e]=w-dw;
		}

                infile3 >> a >> b[0] >> db[0] >> b[1] >> db[1] >> b[2] >> db[2] >> b[3] >> db[3] >> b[4] >> db[4] >> b[5] >> db[5];
                infile7 >> a >> d[0] >> dd[0] >> d[1] >> dd[1] >> d[2] >> dd[2] >> d[3] >> dd[3] >> d[4] >> dd[4] >> d[5] >> dd[5];
		for (unsigned e=0; e<6; e++) {
	                w=w1[cent]*b[e]+w2[cent]*d[e];
	                dw=sqrt(pow(w1[cent]*db[e],2.)+pow(w2[cent]*dd[e],2.));
	                if (w+dw>y[e]) y[e]=w+dw;
	                if (w-dw<z[e]) z[e]=w-dw;
		}

		infile4 >> a >> b[0] >> db[0] >> b[1] >> db[1] >> b[2] >> db[2] >> b[3] >> db[3] >> b[4] >> db[4] >> b[5] >> db[5];
                infile8 >> a >> d[0] >> dd[0] >> d[1] >> dd[1] >> d[2] >> dd[2] >> d[3] >> dd[3] >> d[4] >> dd[4] >> d[5] >> dd[5];
		for (unsigned e=0; e<6; e++) {
	                w=w1[cent]*b[e]+w2[cent]*d[e];
	                dw=sqrt(pow(w1[cent]*db[e],2.)+pow(w2[cent]*dd[e],2.));
	                if (w+dw>y[e]) y[e]=w+dw;
	                if (w-dw<z[e]) z[e]=w-dw;
		}

                built << a << " " << y[0] << " " << z[0] << " " << y[1] << " " << z[1] << " " << y[2] << " " << z[2] << " " << y[3] << " " << z[3] << " " << y[4] << " " << z[4] << " " << y[5] << " " << z[5] << "\n";

                bin+=1;
        } while (bin<N);

built.close();
//End Program
}


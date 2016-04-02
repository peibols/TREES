#include <iostream>
#include <fstream>
#include <iomanip>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <assert.h>
#include <sstream>

using namespace std;
//Arguments: Radius (2,3,4,5); BRO (0-6)
int main (int argc, char** argv) {
        assert(argc==3);

        ostringstream outF;
        ostringstream inf1, inf2, inf3, inf4, inf5, inf6, inf7, inf8, inf9, inf10;
        outF << "BRO" << argv[2] << "/FF0" << argv[1] << ".dat";
        ofstream built;
        built.open (outF.str().c_str());
        inf1 << "BRO" << argv[2] << "/1A/RatioFF0" << argv[1] << ".dat";
	inf2 << "BRO" << argv[2] << "/1B/RatioFF0" << argv[1] << ".dat";
	inf3 << "BRO" << argv[2] << "/2A/RatioFF0" << argv[1] << ".dat";
	inf4 << "BRO" << argv[2] << "/2B/RatioFF0" << argv[1] << ".dat";
	inf5 << "BRO" << argv[2] << "/3A/RatioFF0" << argv[1] << ".dat";
	inf6 << "BRO" << argv[2] << "/3B/RatioFF0" << argv[1] << ".dat";
	inf7 << "BRO" << argv[2] << "/4A/RatioFF0" << argv[1] << ".dat";
	inf8 << "BRO" << argv[2] << "/4B/RatioFF0" << argv[1] << ".dat";

        std::ifstream infile1(inf1.str().c_str());
        std::ifstream infile2(inf2.str().c_str());
        std::ifstream infile3(inf3.str().c_str());
        std::ifstream infile4(inf4.str().c_str());
        std::ifstream infile5(inf5.str().c_str());
        std::ifstream infile6(inf6.str().c_str());
        std::ifstream infile7(inf7.str().c_str());
        std::ifstream infile8(inf8.str().c_str());

        double w1[4],w2[4];
        w1[0]=0.563;
        w2[0]=0.437;
        w1[1]=0.624;
        w2[1]=0.376;
        w1[2]=0.659;
        w2[2]=0.341;
        w1[3]=0.706;
        w2[3]=0.294;

        double y,z,w,dw;
        double a,b,db,d,dd,v,dv;
        int bin=0;
        int N=10;
        int cent=0;
        do {

                infile1 >> a >> b >> db;
                infile2 >> a >> d >> dd;
                w=w1[cent]*b+w2[cent]*d;
                dw=sqrt(pow(w1[cent]*db,2.)+pow(w2[cent]*dd,2.));
                y=w+dw;
                z=w-dw;

                infile3 >> a >> b >> db;
                infile4 >> a >> d >> dd;
                w=w1[cent]*b+w2[cent]*d;
                dw=sqrt(pow(w1[cent]*db,2.)+pow(w2[cent]*dd,2.));
                if (w+dw>y) y=w+dw;
                if (w-dw<z) z=w-dw;

                infile5 >> a >> b >> db;
                infile6 >> a >> d >> dd;
                w=w1[cent]*b+w2[cent]*d;
                dw=sqrt(pow(w1[cent]*db,2.)+pow(w2[cent]*dd,2.));
                if (w+dw>y) y=w+dw;
                if (w-dw<z) z=w-dw;

		infile7 >> a >> b >> db;
                infile8 >> a >> d >> dd;
                w=w1[cent]*b+w2[cent]*d;
                dw=sqrt(pow(w1[cent]*db,2.)+pow(w2[cent]*dd,2.));
                if (w+dw>y) y=w+dw;
                if (w-dw<z) z=w-dw;

                built << a << " " << y << " " << z << "\n";

                bin+=1;
        } while (bin<N);

built.close();
//End Program
}


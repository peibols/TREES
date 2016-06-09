#include <iostream>
#include <fstream>
#include <iomanip>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <sstream>
#include <assert.h>

using namespace std;

	int main (int argc, char** argv) {
        assert(argc==4);

        ostringstream outF;
        ostringstream inf0, inf1, inf2, inf3, inf4, inf5, inf6, inf7, inf8, inf9, inf10,
        inf11, inf12, inf13, inf14, inf15, inf16;

        int qmethod=atoi(argv[1]);
        char model[100];
        if (qmethod==1) sprintf(model,"Coll");
        if (qmethod==2) sprintf(model,"Rad");
        if (qmethod==3) sprintf(model,"Strong");

        outF << model << "/BRO" << argv[2] << "/IMB3" << argv[3] << ".dat";
        ofstream built;
        built.open (outF.str().c_str());

        inf1 << model << "/BRO" << argv[2] << "/1A/IMB3eta" << argv[3] << ".dat";
        inf2 << model << "/BRO" << argv[2] << "/2A/IMB3eta" << argv[3] << ".dat";
        inf3 << model << "/BRO" << argv[2] << "/3A/IMB3eta" << argv[3] << ".dat";
        inf4 << model << "/BRO" << argv[2] << "/4A/IMB3eta" << argv[3] << ".dat";
        inf5 << model << "/BRO" << argv[2] << "/1B/IMB3eta" << argv[3] << ".dat";
        inf6 << model << "/BRO" << argv[2] << "/2B/IMB3eta" << argv[3] << ".dat";
        inf7 << model << "/BRO" << argv[2] << "/3B/IMB3eta" << argv[3] << ".dat";
        inf8 << model << "/BRO" << argv[2] << "/4B/IMB3eta" << argv[3] << ".dat";
        inf9 << model << "/BRO" << argv[2] << "/1C/IMB3eta" << argv[3] << ".dat";
        inf10 << model << "/BRO" << argv[2] << "/2C/IMB3eta" << argv[3] << ".dat";
        inf11 << model << "/BRO" << argv[2] << "/3C/IMB3eta" << argv[3] << ".dat";
        inf12 << model << "/BRO" << argv[2] << "/4C/IMB3eta" << argv[3] << ".dat";
        inf13 << model << "/BRO" << argv[2] << "/1D/IMB3eta" << argv[3] << ".dat";
        inf14 << model << "/BRO" << argv[2] << "/2D/IMB3eta" << argv[3] << ".dat";
        inf15 << model << "/BRO" << argv[2] << "/3D/IMB3eta" << argv[3] << ".dat";
        inf16 << model << "/BRO" << argv[2] << "/4D/IMB3eta" << argv[3] << ".dat";

        std::ifstream infile1(inf1.str().c_str());
        std::ifstream infile2(inf2.str().c_str());
        std::ifstream infile3(inf3.str().c_str());
        std::ifstream infile4(inf4.str().c_str());
        std::ifstream infile5(inf5.str().c_str());
        std::ifstream infile6(inf6.str().c_str());
        std::ifstream infile7(inf7.str().c_str());
        std::ifstream infile8(inf8.str().c_str());
        std::ifstream infile9(inf9.str().c_str());
        std::ifstream infile10(inf10.str().c_str());
        std::ifstream infile11(inf11.str().c_str());
        std::ifstream infile12(inf12.str().c_str());
        std::ifstream infile13(inf13.str().c_str());
        std::ifstream infile14(inf14.str().c_str());
        std::ifstream infile15(inf15.str().c_str());
        std::ifstream infile16(inf16.str().c_str());

	double w1,w2,w3,w4;
	w1=0.286;
	w2=0.221;
	w3=0.308;
	w4=0.185;

        double y,z,w,dw;
        double a,b,db,d,dd,e,de,f,df;
        int bin=0;
        int N=16;
        do {
                infile1 >> a >> b >> db;
		infile5 >> a >> d >> dd;
		infile9 >> a >> e >> de;
		infile13 >> a >> f >> df;
		w=w1*b+w2*d+w3*e+w4*f;
		dw=sqrt(pow(w1*db,2.)+pow(w2*dd,2.)+pow(w3*de,2.)+pow(w4*df,2.));
                y=w+dw;
                z=w-dw;

                infile2 >> a >> b >> db;
		infile6 >> a >> d >> dd;
		infile10 >> a >> e >> de;
                infile14 >> a >> f >> df;
		w=w1*b+w2*d+w3*e+w4*f;
                dw=sqrt(pow(w1*db,2.)+pow(w2*dd,2.)+pow(w3*de,2.)+pow(w4*df,2.));
		if (w+dw>y) y=w+dw;
                if (w-dw<z) z=w-dw;

		infile3 >> a >> b >> db;
                infile7 >> a >> d >> dd;
                infile11 >> a >> e >> de;
                infile15 >> a >> f >> df;
                w=w1*b+w2*d+w3*e+w4*f;
                dw=sqrt(pow(w1*db,2.)+pow(w2*dd,2.)+pow(w3*de,2.)+pow(w4*df,2.));
                if (w+dw>y) y=w+dw;
                if (w-dw<z) z=w-dw;

		infile4 >> a >> b >> db;
                infile8 >> a >> d >> dd;
                infile12 >> a >> e >> de;
                infile16 >> a >> f >> df;
                w=w1*b+w2*d+w3*e+w4*f;
                dw=sqrt(pow(w1*db,2.)+pow(w2*dd,2.)+pow(w3*de,2.)+pow(w4*df,2.));
                if (w+dw>y) y=w+dw;
                if (w-dw<z) z=w-dw;

		built << a << " " << y << " " << z << "\n";

                bin+=1;
        } while (bin<N);

built.close();
//End Program
}


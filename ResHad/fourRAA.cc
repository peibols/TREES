#include <iostream>
#include <fstream>
#include <iomanip>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

using namespace std;

int main () {

        ofstream built;
        built.open ("BACK1/R010.txt");
	std::ifstream infile0("VacSpecHad.txt");
        std::ifstream infile1("BACK1/1centA/MedSpecHad.txt");
        std::ifstream infile2("BACK1/2centA/MedSpecHad.txt");
        std::ifstream infile3("BACK1/3centA/MedSpecHad.txt");
        std::ifstream infile4("BACK1/4centA/MedSpecHad.txt");
	std::ifstream infile5("BACK1/1centB/MedSpecHad.txt");
        std::ifstream infile6("BACK1/2centB/MedSpecHad.txt");
        std::ifstream infile7("BACK1/3centB/MedSpecHad.txt");
        std::ifstream infile8("BACK1/4centB/MedSpecHad.txt");

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
        int N=11;
	int cent=0;
        do {
              	infile0 >> a >> v >> dv;

                infile1 >> a >> b >> db;
                infile5 >> a >> d >> dd;
		db=sqrt(pow(b/v/v*dv,2.)+pow(1./v*db,2.));
		dd=sqrt(pow(d/v/v*dv,2.)+pow(1./v*dd,2.));
		b/=v;
		d/=v;
                w=w1[cent]*b+w2[cent]*d;
                dw=sqrt(pow(w1[cent]*db,2.)+pow(w2[cent]*dd,2.));
                y=w+dw;
                z=w-dw;

                infile2 >> a >> b >> db;
                infile6 >> a >> d >> dd;
		db=sqrt(pow(b/v/v*dv,2.)+pow(1./v*db,2.));
		dd=sqrt(pow(d/v/v*dv,2.)+pow(1./v*dd,2.));
		b/=v;
		d/=v;
                w=w1[cent]*b+w2[cent]*d;
                dw=sqrt(pow(w1[cent]*db,2.)+pow(w2[cent]*dd,2.));
                if (w+dw>y) y=w+dw;
                if (w-dw<z) z=w-dw;

                infile3 >> a >> b >> db;
                infile7 >> a >> d >> dd;
		db=sqrt(pow(b/v/v*dv,2.)+pow(1./v*db,2.));
		dd=sqrt(pow(d/v/v*dv,2.)+pow(1./v*dd,2.));
		b/=v;
		d/=v;
                w=w1[cent]*b+w2[cent]*d;
                dw=sqrt(pow(w1[cent]*db,2.)+pow(w2[cent]*dd,2.));
                if (w+dw>y) y=w+dw;
                if (w-dw<z) z=w-dw;

		infile4 >> a >> b >> db;
                infile8 >> a >> d >> dd;
		db=sqrt(pow(b/v/v*dv,2.)+pow(1./v*db,2.));
		dd=sqrt(pow(d/v/v*dv,2.)+pow(1./v*dd,2.));
		b/=v;
		d/=v;
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


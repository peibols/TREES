#include <iostream>
#include <fstream>
#include <iomanip>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <sstream>
#include <assert.h>

using namespace std;

//Arguments: Radius (2,3,4,5);  Back(1) or NoBack(2); Cent 0-10(1) or 10-30(2)
int main (int argc, char** argv) {
	assert(argc==4);

	ostringstream outF;
	ostringstream inf0, inf1, inf2, inf3, inf4, inf5, inf6, inf7, inf8, inf9, inf10;
	if (atoi(argv[2])==1) outF << "RAA/" << argv[3] << "RAA0" << argv[1] << ".dat";
        else outF << "RAA/" << argv[3] << "RAA0" << argv[1] << "nb.dat";
	ofstream built;
        built.open (outF.str().c_str());
	inf0 << "Vac/" << argv[3] << "VacSpec0" << argv[1] << ".dat";
	std::ifstream infile0(inf0.str().c_str());
	inf9 << "Vac/BIG/" << argv[3] << "VacSpec0" << argv[1] << ".dat";
	std::ifstream infile9(inf9.str().c_str());
	inf10 << "/home/peibols/ADSPYTHIA/Backreaction/Dists/Resol/" << argv[3] << "R0" << argv[1] << "/Spectrum.dat";
        std::ifstream infile10(inf10.str().c_str());
	int centr=atoi(argv[3]);
	if (atoi(argv[2])==1) {
		if (centr==1) {
			inf1 << "1A/MedSpec0" << argv[1] << ".dat";
			inf2 << "1B/MedSpec0" << argv[1] << ".dat";
			inf3 << "2A/MedSpec0" << argv[1] << ".dat";
			inf4 << "2B/MedSpec0" << argv[1] << ".dat";
			inf5 << "3A/MedSpec0" << argv[1] << ".dat";
			inf6 << "3B/MedSpec0" << argv[1] << ".dat";
			inf7 << "4A/MedSpec0" << argv[1] << ".dat";
			inf8 << "4B/MedSpec0" << argv[1] << ".dat";
        	}
		if (centr==2) {
			inf1 << "1C/MedSpec0" << argv[1] << ".dat";
        	        inf2 << "1D/MedSpec0" << argv[1] << ".dat";
        	        inf3 << "2C/MedSpec0" << argv[1] << ".dat";
        	        inf4 << "2D/MedSpec0" << argv[1] << ".dat";
        	        inf5 << "3C/MedSpec0" << argv[1] << ".dat";
        	        inf6 << "3D/MedSpec0" << argv[1] << ".dat";
        	        inf7 << "4C/MedSpec0" << argv[1] << ".dat";
        	        inf8 << "4D/MedSpec0" << argv[1] << ".dat";
		}
	}
	else {
		if (centr==1) {
                        inf1 << "1A/MedSpec0" << argv[1] << "nb.dat";
                        inf2 << "1B/MedSpec0" << argv[1] << "nb.dat";
                        inf3 << "2A/MedSpec0" << argv[1] << "nb.dat";
                        inf4 << "2B/MedSpec0" << argv[1] << "nb.dat";
                        inf5 << "3A/MedSpec0" << argv[1] << "nb.dat";
                        inf6 << "3B/MedSpec0" << argv[1] << "nb.dat";
                        inf7 << "4A/MedSpec0" << argv[1] << "nb.dat";
                        inf8 << "4B/MedSpec0" << argv[1] << "nb.dat";
                }
                if (centr==2) {
                        inf1 << "1C/MedSpec0" << argv[1] << "nb.dat";
                        inf2 << "1D/MedSpec0" << argv[1] << "nb.dat";
                        inf3 << "2C/MedSpec0" << argv[1] << "nb.dat";
                        inf4 << "2D/MedSpec0" << argv[1] << "nb.dat";
                        inf5 << "3C/MedSpec0" << argv[1] << "nb.dat";
                        inf6 << "3D/MedSpec0" << argv[1] << "nb.dat";
                        inf7 << "4C/MedSpec0" << argv[1] << "nb.dat";
                        inf8 << "4D/MedSpec0" << argv[1] << "nb.dat";
                }
        }
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

	double u,du,n,dn;
        double y,z,w,dw;
        double a,b,db,d,dd,v,dv;
        int bin=0;
        int N=11;
	int cent=0;
        do {
		infile9 >> a >> n >> dn;
		infile10 >> a >> u >> du;
		double bbb=n/u;
		//cout << " Corre= " << bbb << "\n";

              	infile0 >> a >> v >> dv;

                infile1 >> a >> b >> db;
                infile2 >> a >> d >> dd;
		db=sqrt(pow(b/v/v*dv,2.)+pow(1./v*db,2.));
		dd=sqrt(pow(d/v/v*dv,2.)+pow(1./v*dd,2.));
		b/=v;
		d/=v;
                w=w1[cent]*b+w2[cent]*d;
                w*=bbb;
		dw=sqrt(pow(w1[cent]*db,2.)+pow(w2[cent]*dd,2.));
                if (bin==0) cout << " RAA at 105 GeV= " << w << " +- " << dw << "\n";
		y=w+dw;
                z=w-dw;

                infile3 >> a >> b >> db;
                infile4 >> a >> d >> dd;
		db=sqrt(pow(b/v/v*dv,2.)+pow(1./v*db,2.));
		dd=sqrt(pow(d/v/v*dv,2.)+pow(1./v*dd,2.));
		b/=v;
		d/=v;
                w=w1[cent]*b+w2[cent]*d;
                w*=bbb;
		dw=sqrt(pow(w1[cent]*db,2.)+pow(w2[cent]*dd,2.));
		if (bin==0) cout << " RAA at 105 GeV= " << w << " +- " << dw << "\n";
                if (w+dw>y) y=w+dw;
                if (w-dw<z) z=w-dw;

                infile5 >> a >> b >> db;
                infile6 >> a >> d >> dd;
		db=sqrt(pow(b/v/v*dv,2.)+pow(1./v*db,2.));
		dd=sqrt(pow(d/v/v*dv,2.)+pow(1./v*dd,2.));
		b/=v;
		d/=v;
                w=w1[cent]*b+w2[cent]*d;
                w*=bbb;
		dw=sqrt(pow(w1[cent]*db,2.)+pow(w2[cent]*dd,2.));
		if (bin==0) cout << " RAA at 105 GeV= " << w << " +- " << dw << "\n";
                if (w+dw>y) y=w+dw;
                if (w-dw<z) z=w-dw;

		infile7 >> a >> b >> db;
                infile8 >> a >> d >> dd;
		db=sqrt(pow(b/v/v*dv,2.)+pow(1./v*db,2.));
		dd=sqrt(pow(d/v/v*dv,2.)+pow(1./v*dd,2.));
		b/=v;
		d/=v;
                w=w1[cent]*b+w2[cent]*d;
                w*=bbb;
		dw=sqrt(pow(w1[cent]*db,2.)+pow(w2[cent]*dd,2.));
		if (bin==0) cout << " RAA at 105 GeV= " << w << " +- " << dw << "\n";
                if (w+dw>y) y=w+dw;
                if (w-dw<z) z=w-dw;
                built << a << " " << y << " " << z << "\n";

                bin+=1;
        } while (bin<N);

built.close();
//End Program
}


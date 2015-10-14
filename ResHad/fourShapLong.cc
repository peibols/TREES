#include <iostream>
#include <fstream>
#include <iomanip>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

using namespace std;

int main () {

        ofstream built;
        built.open ("BACK1/ShapLong.txt");
	std::ifstream infile0("ShapesLongVac.txt");
        std::ifstream infile1("BACK1/1centA/ShapesLong.txt");
        std::ifstream infile2("BACK1/2centA/ShapesLong.txt");
        std::ifstream infile3("BACK1/3centA/ShapesLong.txt");
        std::ifstream infile4("BACK1/4centA/ShapesLong.txt");
        std::ifstream infile5("BACK1/1centB/ShapesLong.txt");
        std::ifstream infile6("BACK1/2centB/ShapesLong.txt");
        std::ifstream infile7("BACK1/3centB/ShapesLong.txt");
        std::ifstream infile8("BACK1/4centB/ShapesLong.txt");

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
	double sy,sz,sw,sdw;
        double a,b,db,d,dd,v,dv;
	double sb,sdb,sd,sdd,sv,sdv;
        int bin=0;
        int N=14;
        int cent=0;
        do {
                infile0 >> a >> v >> dv >> sv >> sdv;

                infile1 >> a >> b >> db >> sb >> sdb;
                infile5 >> a >> d >> dd >> sd >> sdd;
		db=sqrt(pow(b/v/v*dv,2.)+pow(1./v*db,2.));
		dd=sqrt(pow(d/v/v*dv,2.)+pow(1./v*dd,2.));
		sdb=sqrt(pow(sb/sv/sv*sdv,2.)+pow(1./sv*sdb,2.));
		sdd=sqrt(pow(sd/sv/sv*sdv,2.)+pow(1./sv*sdd,2.));
		b/=v;
		d/=v;
		sb/=sv;
		sd/=sv;
                w=w1[cent]*b+w2[cent]*d;
                dw=sqrt(pow(w1[cent]*db,2.)+pow(w2[cent]*dd,2.));
                y=w+dw;
                z=w-dw;
		sw=w1[cent]*sb+w2[cent]*sd;
                sdw=sqrt(pow(w1[cent]*sdb,2.)+pow(w2[cent]*sdd,2.));
                sy=sw+sdw;
                sz=sw-sdw;

		infile2 >> a >> b >> db >> sb >> sdb;
                infile6 >> a >> d >> dd >> sd >> sdd;
                db=sqrt(pow(b/v/v*dv,2.)+pow(1./v*db,2.));
                dd=sqrt(pow(d/v/v*dv,2.)+pow(1./v*dd,2.));
                sdb=sqrt(pow(sb/sv/sv*sdv,2.)+pow(1./sv*sdb,2.));
                sdd=sqrt(pow(sd/sv/sv*sdv,2.)+pow(1./sv*sdd,2.));
                b/=v;
                d/=v;
                sb/=sv;
                sd/=sv;
                w=w1[cent]*b+w2[cent]*d;
                dw=sqrt(pow(w1[cent]*db,2.)+pow(w2[cent]*dd,2.));
                y=w+dw;
                z=w-dw;
                sw=w1[cent]*sb+w2[cent]*sd;
                sdw=sqrt(pow(w1[cent]*sdb,2.)+pow(w2[cent]*sdd,2.));
                sy=sw+sdw;
                sz=sw-sdw;
                if (w+dw>y) y=w+dw;
                if (w-dw<z) z=w-dw;
		if (sw+sdw>sy) sy=sw+sdw;
                if (sw-sdw<sz) sz=sw-sdw;

		infile3 >> a >> b >> db >> sb >> sdb;
                infile7 >> a >> d >> dd >> sd >> sdd;
                db=sqrt(pow(b/v/v*dv,2.)+pow(1./v*db,2.));
                dd=sqrt(pow(d/v/v*dv,2.)+pow(1./v*dd,2.));
                sdb=sqrt(pow(sb/sv/sv*sdv,2.)+pow(1./sv*sdb,2.));
                sdd=sqrt(pow(sd/sv/sv*sdv,2.)+pow(1./sv*sdd,2.));
                b/=v;
                d/=v;
                sb/=sv;
                sd/=sv;
                w=w1[cent]*b+w2[cent]*d;
                dw=sqrt(pow(w1[cent]*db,2.)+pow(w2[cent]*dd,2.));
                y=w+dw;
                z=w-dw;
                sw=w1[cent]*sb+w2[cent]*sd;
                sdw=sqrt(pow(w1[cent]*sdb,2.)+pow(w2[cent]*sdd,2.));
                sy=sw+sdw;
                sz=sw-sdw;
                if (w+dw>y) y=w+dw;
                if (w-dw<z) z=w-dw;
                if (sw+sdw>sy) sy=sw+sdw;
                if (sw-sdw<sz) sz=sw-sdw;

		infile4 >> a >> b >> db >> sb >> sdb;
                infile8 >> a >> d >> dd >> sd >> sdd;
                db=sqrt(pow(b/v/v*dv,2.)+pow(1./v*db,2.));
                dd=sqrt(pow(d/v/v*dv,2.)+pow(1./v*dd,2.));
                sdb=sqrt(pow(sb/sv/sv*sdv,2.)+pow(1./sv*sdb,2.));
                sdd=sqrt(pow(sd/sv/sv*sdv,2.)+pow(1./sv*sdd,2.));
                b/=v;
                d/=v;
                sb/=sv;
                sd/=sv;
                w=w1[cent]*b+w2[cent]*d;
                dw=sqrt(pow(w1[cent]*db,2.)+pow(w2[cent]*dd,2.));
                y=w+dw;
                z=w-dw;
                sw=w1[cent]*sb+w2[cent]*sd;
                sdw=sqrt(pow(w1[cent]*sdb,2.)+pow(w2[cent]*sdd,2.));
                sy=sw+sdw;
                sz=sw-sdw;
                if (w+dw>y) y=w+dw;
                if (w-dw<z) z=w-dw;
                if (sw+sdw>sy) sy=sw+sdw;
                if (sw-sdw<sz) sz=sw-sdw;

		built << a << " " << y << " " << z << " " << sy << " " << sz << "\n";

                bin+=1;
        } while (bin<N);

built.close();
//End Program
}


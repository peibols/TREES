#include <iostream>
#include <fstream>
#include <iomanip>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

using namespace std;

int main () {

        ofstream built;
        built.open ("BACK1/LeadTrack.txt");
	std::ifstream infile0("LeadJetTrackHad.txt");
        std::ifstream infile1("BACK1/1centA/LeadJetTrackHad.txt");
        std::ifstream infile2("BACK1/2centA/LeadJetTrackHad.txt");
        std::ifstream infile3("BACK1/3centA/LeadJetTrackHad.txt");
        std::ifstream infile4("BACK1/4centA/LeadJetTrackHad.txt");
	std::ifstream infile5("BACK1/1centB/LeadJetTrackHad.txt");
        std::ifstream infile6("BACK1/2centB/LeadJetTrackHad.txt");
        std::ifstream infile7("BACK1/3centB/LeadJetTrackHad.txt");
        std::ifstream infile8("BACK1/4centB/LeadJetTrackHad.txt");

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
	double aa, v, dv, vr, dvr, vp, dvp, vb, dvb;
        double a,b,db,d,ddb,dpb,dbr,ddr,br,bp,dbp,pb,dr,dp,ddp,wr,dwr,yyr,yzr,wp,dwp,yyp,yzp,wd,dwd,yd,zd;
        int bin=0;
        int N=17;
	int cent=0;
	std::string svr,sbr,sdr,sdvr,sdbr,sddr;
        do {
              	infile0 >> a >> svr >> sdvr >> aa >> vp >> dvp >> vb >> dvb;
		vr = strtod(svr.c_str(), NULL);
                dvr = strtod(sdvr.c_str(), NULL);
		if (vr!=vr) vr=1.;
		if (dvr!=dvr) dvr=1.;

                infile1 >> a >> sbr >> sdbr >> aa >> bp >> dbp >> pb >> dpb;
                infile5 >> a >> sdr >> sddr >> aa >> dp >> ddp >> db >> ddb;
                br = strtod(sbr.c_str(), NULL);
                dbr = strtod(sdbr.c_str(), NULL);
		dr = strtod(sdr.c_str(), NULL);
                ddr = strtod(sddr.c_str(), NULL);
		if (br!=br) br=0.;
		if (dbr!=dbr) dbr=0.;
		if (dr!=dr) dr=0.;
		if (ddr!=ddr) ddr=0.;
		br/=3.;
                dr/=3.;
		vr/=3.;
		dbr/=sqrt(6.);
		ddr/=sqrt(6.);
		dvr/=sqrt(6.);
		wr=w1[cent]*br+w2[cent]*dr;
                dwr=sqrt(pow(w1[cent]*dbr,2.)+pow(w2[cent]*ddr,2.));
		yyr=wr+dwr;
		yzr=wr-dwr;
		//---------
		bp/=3.;
                dp/=3.;
                vp/=3.;
                dbp/=sqrt(6.);
                ddp/=sqrt(6.);
                dvp/=sqrt(6.);
                wp=w1[cent]*bp+w2[cent]*dp;
                dwp=sqrt(pow(w1[cent]*dbp,2.)+pow(w2[cent]*ddp,2.));
                yyp=wp+dwp;
                yzp=wp-dwp;
		//--------
		cout << " a= " << a << "\n";
                cout << " br= " << br << "\n";
                cout << " dr= " << dr << "\n";
		cout << " vr= " << vr << "\n";
		br-=vr;
		dr-=vr;
		dbr=sqrt(pow(dbr,2.)+pow(dvr,2.));
		ddr=sqrt(pow(ddr,2.)+pow(dvr,2.));
		wd=w1[cent]*br+w2[cent]*dr;
		dwd=sqrt(pow(w1[cent]*dbr,2.)+pow(w2[cent]*ddr,2.));
                yd=wd+dwd;
                zd=wd-dwd;

		infile2 >> a >> sbr >> sdbr >> aa >> bp >> dbp >> pb >> dpb;
                infile6 >> a >> sdr >> sddr >> aa >> dp >> ddp >> db >> ddb;
                br = strtod(sbr.c_str(), NULL);
                dbr = strtod(sdbr.c_str(), NULL);
                dr = strtod(sdr.c_str(), NULL);
                ddr = strtod(sddr.c_str(), NULL);
		if (br!=br) br=0.;
                if (dbr!=dbr) dbr=0.;
                if (dr!=dr) dr=0.;
                if (ddr!=ddr) ddr=0.;
                br/=3.;
                dr/=3.;
                dbr/=sqrt(6.);
                ddr/=sqrt(6.);
                wr=w1[cent]*br+w2[cent]*dr;
                dwr=sqrt(pow(w1[cent]*dbr,2.)+pow(w2[cent]*ddr,2.));
                if (wr+dwr>yyr) yyr=wr+dwr;
                if (wr-dwr<yzr) yzr=wr-dwr;
                //---------
                bp/=3.;
                dp/=3.;
                dbp/=sqrt(6.);
                ddp/=sqrt(6.);
                wp=w1[cent]*bp+w2[cent]*dp;
                dwp=sqrt(pow(w1[cent]*dbp,2.)+pow(w2[cent]*ddp,2.));
                if (wp+dwp>yyp) yyp=wp+dwp;
                if (wp-dwp<yzp) yzp=wp-dwp;
                //--------
                br-=vr;
                dr-=vr;
		dbr=sqrt(pow(dbr,2.)+pow(dvr,2.));
                ddr=sqrt(pow(ddr,2.)+pow(dvr,2.));
                wd=w1[cent]*br+w2[cent]*dr;
                dwd=sqrt(pow(w1[cent]*dbr,2.)+pow(w2[cent]*ddr,2.));
                if (wd+dwd>yd) yd=wd+dwd;
                if (wd-dwd<zd) zd=wd-dwd;

		infile3 >> a >> sbr >> sdbr >> aa >> bp >> dbp >> pb >> dpb;
                infile7 >> a >> sdr >> sddr >> aa >> dp >> ddp >> db >> ddb;
                br = strtod(sbr.c_str(), NULL);
                dbr = strtod(sdbr.c_str(), NULL);
                dr = strtod(sdr.c_str(), NULL);
                ddr = strtod(sddr.c_str(), NULL);
                if (br!=br) br=0.;
                if (dbr!=dbr) dbr=0.;
                if (dr!=dr) dr=0.;
                if (ddr!=ddr) ddr=0.;
		br/=3.;
                dr/=3.;
                dbr/=sqrt(6.);
                ddr/=sqrt(6.);
                wr=w1[cent]*br+w2[cent]*dr;
                dwr=sqrt(pow(w1[cent]*dbr,2.)+pow(w2[cent]*ddr,2.));
                if (wr+dwr>yyr) yyr=wr+dwr;
                if (wr-dwr<yzr) yzr=wr-dwr;
                //---------
                bp/=3.;
                dp/=3.;
                dbp/=sqrt(6.);
                ddp/=sqrt(6.);
                wp=w1[cent]*bp+w2[cent]*dp;
                dwp=sqrt(pow(w1[cent]*dbp,2.)+pow(w2[cent]*ddp,2.));
                if (wp+dwp>yyp) yyp=wp+dwp;
                if (wp-dwp<yzp) yzp=wp-dwp;
                //--------
                br-=vr;
                dr-=vr;
		dbr=sqrt(pow(dbr,2.)+pow(dvr,2.));
                ddr=sqrt(pow(ddr,2.)+pow(dvr,2.));
                wd=w1[cent]*br+w2[cent]*dr;
                dwd=sqrt(pow(w1[cent]*dbr,2.)+pow(w2[cent]*ddr,2.));
                if (wd+dwd>yd) yd=wd+dwd;
                if (wd-dwd<zd) zd=wd-dwd;

		infile4 >> a >> sbr >> sdbr >> aa >> bp >> dbp >> pb >> dpb;
                infile8 >> a >> sdr >> sddr >> aa >> dp >> ddp >> db >> ddb;
                br = strtod(sbr.c_str(), NULL);
                dbr = strtod(sdbr.c_str(), NULL);
                dr = strtod(sdr.c_str(), NULL);
                ddr = strtod(sddr.c_str(), NULL);
                if (br!=br) br=0.;
                if (dbr!=dbr) dbr=0.;
                if (dr!=dr) dr=0.;
                if (ddr!=ddr) ddr=0.;
		br/=3.;
                dr/=3.;
                dbr/=sqrt(6.);
                ddr/=sqrt(6.);
                wr=w1[cent]*br+w2[cent]*dr;
                dwr=sqrt(pow(w1[cent]*dbr,2.)+pow(w2[cent]*ddr,2.));
                if (wr+dwr>yyr) yyr=wr+dwr;
                if (wr-dwr<yzr) yzr=wr-dwr;
                //---------
                bp/=3.;
                dp/=3.;
                dbp/=sqrt(6.);
                ddp/=sqrt(6.);
                wp=w1[cent]*bp+w2[cent]*dp;
                dwp=sqrt(pow(w1[cent]*dbp,2.)+pow(w2[cent]*ddp,2.));
                if (wp+dwp>yyp) yyp=wp+dwp;
                if (wp-dwp<yzp) yzp=wp-dwp;
                //--------
                br-=vr;
                dr-=vr;
		dbr=sqrt(pow(dbr,2.)+pow(dvr,2.));
                ddr=sqrt(pow(ddr,2.)+pow(dvr,2.));
                wd=w1[cent]*br+w2[cent]*dr;
                dwd=sqrt(pow(w1[cent]*dbr,2.)+pow(w2[cent]*ddr,2.));
                if (wd+dwd>yd) yd=wd+dwd;
                if (wd-dwd<zd) zd=wd-dwd;

		built << a << " " << yyr << " " << yzr << " " << aa << " " << yyp << " " << yzp << " " << yd << " " << zd << "\n";

                bin+=1;
        } while (bin<N);

built.close();
//End Program
}


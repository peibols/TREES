#include <iostream>
#include <fstream>
#include <iomanip>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <assert.h>
#include <sstream>

using namespace std;

//Arguments: Radius (2,3,4,5);  Back(1) or NoBack(2); Cent 0-10(1) or 10-30(2); Corre No(0) or Yes(1)
int main (int argc, char** argv) {
        assert(argc==5);

	int corre=atoi(argv[4]);

        ostringstream outF, outFdif;
        ostringstream inf0, inf1, inf2, inf3, inf4, inf5, inf6, inf7, inf8;
        if (atoi(argv[2])==1 && corre==1) outF << "Aj/" << argv[3] << "PbPbAj0" << argv[1] << ".dat";
        if (atoi(argv[2])!=1 && corre==1) outF << "Aj/" << argv[3] << "PbPbAj0" << argv[1] << "nb.dat";
        if (atoi(argv[2])==1 && corre==0) outF << "Aj/NoCorr/" << argv[3] << "PbPbAj0" << argv[1] << ".dat";
        if (atoi(argv[2])!=1 && corre==0) outF << "Aj/NoCorr/" << argv[3] << "PbPbAj0" << argv[1] << "nb.dat";

	if (atoi(argv[2])==1 && corre==1) outFdif << "Aj/" << argv[3] << "difAj0" << argv[1] << ".dat";
        if (atoi(argv[2])!=1 && corre==1) outFdif << "Aj/" << argv[3] << "difAj0" << argv[1] << "nb.dat";
	if (atoi(argv[2])==1 && corre==0) outFdif << "Aj/NoCorr/" << argv[3] << "difAj0" << argv[1] << ".dat";
        if (atoi(argv[2])!=1 && corre==0) outFdif << "Aj/NoCorr/" << argv[3] << "difAj0" << argv[1] << "nb.dat";

	ofstream correfile;
        if (corre==1) {
                ostringstream corrF;
                corrF << "Aj/Corr/" << argv[3] << "Corre0" << argv[1] << ".dat";
                correfile.open (corrF.str().c_str());
        }

	ofstream pbpb;
        pbpb.open (outF.str().c_str());
	ofstream pbpbmpp;
        pbpbmpp.open (outFdif.str().c_str());
        inf0 << "Vac/GenMPT/" << "VacAj0" << argv[1] << ".dat";
        std::ifstream infile0(inf0.str().c_str());

	//Correction
	ostringstream infG, infR;
	infG << "Vac/GenMPT/" << argv[3] << "VacAj0" << argv[1] << ".dat";
	infR << "Vac/RecoMPT/" << argv[3] << "VacAj0" << argv[1] << ".dat";

        int centr=atoi(argv[3]);
        if (atoi(argv[2])==1) {
                if (centr==1) {
                        inf1 << "1A/MedAj0" << argv[1] << ".dat";
                        inf2 << "1B/MedAj0" << argv[1] << ".dat";
                        inf3 << "2A/MedAj0" << argv[1] << ".dat";
                        inf4 << "2B/MedAj0" << argv[1] << ".dat";
                        inf5 << "3A/MedAj0" << argv[1] << ".dat";
                        inf6 << "3B/MedAj0" << argv[1] << ".dat";
                        inf7 << "4A/MedAj0" << argv[1] << ".dat";
                        inf8 << "4B/MedAj0" << argv[1] << ".dat";
                }
                if (centr==2) {
                        inf1 << "1C/MedAj0" << argv[1] << ".dat";
                        inf2 << "1D/MedAj0" << argv[1] << ".dat";
                        inf3 << "2C/MedAj0" << argv[1] << ".dat";
                        inf4 << "2D/MedAj0" << argv[1] << ".dat";
                        inf5 << "3C/MedAj0" << argv[1] << ".dat";
                        inf6 << "3D/MedAj0" << argv[1] << ".dat";
                        inf7 << "4C/MedAj0" << argv[1] << ".dat";
                        inf8 << "4D/MedAj0" << argv[1] << ".dat";
                }
        }
        else {
                if (centr==1) {
                        inf1 << "1A/MedAj0" << argv[1] << "nb.dat";
                        inf2 << "1B/MedAj0" << argv[1] << "nb.dat";
                        inf3 << "2A/MedAj0" << argv[1] << "nb.dat";
                        inf4 << "2B/MedAj0" << argv[1] << "nb.dat";
                        inf5 << "3A/MedAj0" << argv[1] << "nb.dat";
                        inf6 << "3B/MedAj0" << argv[1] << "nb.dat";
                        inf7 << "4A/MedAj0" << argv[1] << "nb.dat";
                        inf8 << "4B/MedAj0" << argv[1] << "nb.dat";
                }
                if (centr==2) {
                        inf1 << "1C/MedAj0" << argv[1] << "nb.dat";
                        inf2 << "1D/MedAj0" << argv[1] << "nb.dat";
                        inf3 << "2C/MedAj0" << argv[1] << "nb.dat";
                        inf4 << "2D/MedAj0" << argv[1] << "nb.dat";
                        inf5 << "3C/MedAj0" << argv[1] << "nb.dat";
                        inf6 << "3D/MedAj0" << argv[1] << "nb.dat";
                        inf7 << "4C/MedAj0" << argv[1] << "nb.dat";
                        inf8 << "4D/MedAj0" << argv[1] << "nb.dat";
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

	std::ifstream infileR(infR.str().c_str());
        std::ifstream infileG(infG.str().c_str());

	double x,ra[6],rd[6],ga[6],gd[6],ca[6],cd[6];
	double w1[4],w2[4];
        w1[1]=0.563;
        w2[1]=0.437;
        w1[2]=0.624;
        w2[2]=0.376;
        w1[3]=0.659;
        w2[3]=0.341;
        w1[4]=0.706;
        w2[4]=0.294;

        double aa[6],ab[6],da[6],db[6],va[6],vd[6];
	double derr[6],dval[6],boup[8],bodo[8],voup[8],vodo[8];
	double sumpt, sumerrtwo, sumdi, sumdierrtwo;

        int bin=0;
        int N=4;
        do {
		infileR >> x >> ra[0] >> rd[0] >> ra[1] >> rd[1] >> ra[2] >> rd[2] >> ra[3] >> rd[3] >> ra[4] >> rd[4] >> ra[5] >> rd[5];
        	infileG >> x >> ga[0] >> gd[0] >> ga[1] >> gd[1] >> ga[2] >> gd[2] >> ga[3] >> gd[3] >> ga[4] >> gd[4] >> ga[5] >> gd[5];
        	for (unsigned a=0; a<6; a++) {
        	        ca[a]=ra[a]-ga[a];
        	        cd[a]=sqrt(pow(rd[a],2.)+pow(gd[a],2.));
			if (corre==0) ca[a]=0., cd[a]=0.;
        	}

		infile0 >> x >> va[0] >> vd[0] >> va[1] >> vd[1] >> va[2] >> vd[2] >> va[3] >> vd[3] >> va[4] >> vd[4] >> va[5] >> vd[5];
		cout << " va[0]= " << va[0] << "\n";

                infile1 >> x >> aa[0] >> da[0] >> aa[1] >> da[1] >> aa[2] >> da[2] >> aa[3] >> da[3] >> aa[4] >> da[4] >> aa[5] >> da[5];
		infile2 >> x >> ab[0] >> db[0] >> ab[1] >> db[1] >> ab[2] >> db[2] >> ab[3] >> db[3] >> ab[4] >> db[4] >> ab[5] >> db[5];
		sumpt=0.;
		sumerrtwo=0.;
		sumdi=0.;
		sumdierrtwo=0.;
		for (unsigned a=0; a<6; a++) {
			derr[a]=sqrt(pow(da[a]*w1[centr],2.)+pow(db[a]*w2[centr],2.));
			derr[a]=sqrt(pow(derr[a],2.)+pow(cd[a],2.));
			dval[a]=aa[a]*w1[centr]+ab[a]*w2[centr];
			dval[a]-=ca[a];
			if (int(a)!=5) sumpt+=dval[a];
			if (int(a)!=5) sumerrtwo+=pow(derr[a],2.);
		}
		for (unsigned a=0; a<6; a++) {
			boup[a]=dval[a]+derr[a];
			bodo[a]=dval[a]-derr[a];
			voup[a]=dval[a]-va[a]+sqrt(pow(derr[a],2.)+pow(vd[a],2.));
			vodo[a]=dval[a]-va[a]-sqrt(pow(derr[a],2.)+pow(vd[a],2.));
			if (int(a)!=5) sumdi+=dval[a]-va[a];
			if (int(a)!=5) sumdierrtwo+=pow(sqrt(pow(derr[a],2.)+pow(vd[a],2.)),2.);
		}
		cout << " boup= " << boup[4] << " voup= " << voup[4] << "\n";
		boup[7]=sumpt+sqrt(sumerrtwo);
		bodo[7]=sumpt-sqrt(sumerrtwo);
		boup[6]=sumdi+sqrt(sumdierrtwo);
		bodo[6]=sumdi-sqrt(sumdierrtwo);

		infile3 >> x >> aa[0] >> da[0] >> aa[1] >> da[1] >> aa[2] >> da[2] >> aa[3] >> da[3] >> aa[4] >> da[4] >> aa[5] >> da[5];
                infile4 >> x >> ab[0] >> db[0] >> ab[1] >> db[1] >> ab[2] >> db[2] >> ab[3] >> db[3] >> ab[4] >> db[4] >> ab[5] >> db[5];
                sumpt=0.;
                sumerrtwo=0.;
		sumdi=0.;
                sumdierrtwo=0.;
                for (unsigned a=0; a<6; a++) {
			derr[a]=sqrt(pow(da[a]*w1[centr],2.)+pow(db[a]*w2[centr],2.));
                        derr[a]=sqrt(pow(derr[a],2.)+pow(cd[a],2.));
                        dval[a]=aa[a]*w1[centr]+ab[a]*w2[centr];
                        dval[a]-=ca[a];
                        if (int(a)!=5) sumpt+=dval[a];
                        if (int(a)!=5) sumerrtwo+=pow(derr[a],2.);
                }
                for (unsigned a=0; a<6; a++) {
                        if (dval[a]+derr[a]>boup[a]) boup[a]=dval[a]+derr[a];
                        if (dval[a]-derr[a]<bodo[a]) bodo[a]=dval[a]-derr[a];
                        if (dval[a]-va[a]+sqrt(pow(derr[a],2.)+pow(vd[a],2.))>voup[a]) voup[a]=dval[a]-va[a]+sqrt(pow(derr[a],2.)+pow(vd[a],2.));
                        if (dval[a]-va[a]-sqrt(pow(derr[a],2.)+pow(vd[a],2.))<vodo[a]) vodo[a]=dval[a]-va[a]-sqrt(pow(derr[a],2.)+pow(vd[a],2.));
                        if (int(a)!=5) sumdi+=dval[a]-va[a];
                        if (int(a)!=5) sumdierrtwo+=pow(sqrt(pow(derr[a],2.)+pow(vd[a],2.)),2.);
                }
		cout << " boup= " << boup[4] << " voup= " << voup[4] << "\n";
                if (sumpt+sqrt(sumerrtwo)>boup[7]) boup[7]=sumpt+sqrt(sumerrtwo);
                if (sumpt-sqrt(sumerrtwo)<bodo[7]) bodo[7]=sumpt-sqrt(sumerrtwo);
                if (sumdi+sqrt(sumdierrtwo)>boup[6]) boup[6]=sumdi+sqrt(sumdierrtwo);
                if (sumdi-sqrt(sumdierrtwo)<bodo[6]) bodo[6]=sumdi-sqrt(sumdierrtwo);

		infile5 >> x >> aa[0] >> da[0] >> aa[1] >> da[1] >> aa[2] >> da[2] >> aa[3] >> da[3] >> aa[4] >> da[4] >> aa[5] >> da[5];
                infile6 >> x >> ab[0] >> db[0] >> ab[1] >> db[1] >> ab[2] >> db[2] >> ab[3] >> db[3] >> ab[4] >> db[4] >> ab[5] >> db[5];
                sumpt=0.;
                sumerrtwo=0.;
		sumdi=0.;
                sumdierrtwo=0.;
                for (unsigned a=0; a<6; a++) {
			derr[a]=sqrt(pow(da[a]*w1[centr],2.)+pow(db[a]*w2[centr],2.));
                        derr[a]=sqrt(pow(derr[a],2.)+pow(cd[a],2.));
                        dval[a]=aa[a]*w1[centr]+ab[a]*w2[centr];
                        dval[a]-=ca[a];
                        if (int(a)!=5) sumpt+=dval[a];
                        if (int(a)!=5) sumerrtwo+=pow(derr[a],2.);
                }
                for (unsigned a=0; a<6; a++) {
                        if (dval[a]+derr[a]>boup[a]) boup[a]=dval[a]+derr[a];
                        if (dval[a]-derr[a]<bodo[a]) bodo[a]=dval[a]-derr[a];
                        if (dval[a]-va[a]+sqrt(pow(derr[a],2.)+pow(vd[a],2.))>voup[a]) voup[a]=dval[a]-va[a]+sqrt(pow(derr[a],2.)+pow(vd[a],2.));
                        if (dval[a]-va[a]-sqrt(pow(derr[a],2.)+pow(vd[a],2.))<vodo[a]) vodo[a]=dval[a]-va[a]-sqrt(pow(derr[a],2.)+pow(vd[a],2.));
                        if (int(a)!=5) sumdi+=dval[a]-va[a];
                        if (int(a)!=5) sumdierrtwo+=pow(sqrt(pow(derr[a],2.)+pow(vd[a],2.)),2.);
                }
		cout << " boup= " << boup[4] << " voup= " << voup[4] << "\n";
                if (sumpt+sqrt(sumerrtwo)>boup[7]) boup[7]=sumpt+sqrt(sumerrtwo);
                if (sumpt-sqrt(sumerrtwo)<bodo[7]) bodo[7]=sumpt-sqrt(sumerrtwo);
                if (sumdi+sqrt(sumdierrtwo)>boup[6]) boup[6]=sumdi+sqrt(sumdierrtwo);
                if (sumdi-sqrt(sumdierrtwo)<bodo[6]) bodo[6]=sumdi-sqrt(sumdierrtwo);

		infile7 >> x >> aa[0] >> da[0] >> aa[1] >> da[1] >> aa[2] >> da[2] >> aa[3] >> da[3] >> aa[4] >> da[4] >> aa[5] >> da[5];
                infile8 >> x >> ab[0] >> db[0] >> ab[1] >> db[1] >> ab[2] >> db[2] >> ab[3] >> db[3] >> ab[4] >> db[4] >> ab[5] >> db[5];
                sumpt=0.;
                sumerrtwo=0.;
		sumdi=0.;
                sumdierrtwo=0.;
                for (unsigned a=0; a<6; a++) {
			derr[a]=sqrt(pow(da[a]*w1[centr],2.)+pow(db[a]*w2[centr],2.));
                        derr[a]=sqrt(pow(derr[a],2.)+pow(cd[a],2.));
                        dval[a]=aa[a]*w1[centr]+ab[a]*w2[centr];
                        dval[a]-=ca[a];
                        if (int(a)!=5) sumpt+=dval[a];
                        if (int(a)!=5) sumerrtwo+=pow(derr[a],2.);
                }
                for (unsigned a=0; a<6; a++) {
                        if (dval[a]+derr[a]>boup[a]) boup[a]=dval[a]+derr[a];
                        if (dval[a]-derr[a]<bodo[a]) bodo[a]=dval[a]-derr[a];
                        if (dval[a]-va[a]+sqrt(pow(derr[a],2.)+pow(vd[a],2.))>voup[a]) voup[a]=dval[a]-va[a]+sqrt(pow(derr[a],2.)+pow(vd[a],2.));
                        if (dval[a]-va[a]-sqrt(pow(derr[a],2.)+pow(vd[a],2.))<vodo[a]) vodo[a]=dval[a]-va[a]-sqrt(pow(derr[a],2.)+pow(vd[a],2.));
                        if (int(a)!=5) sumdi+=dval[a]-va[a];
                        if (int(a)!=5) sumdierrtwo+=pow(sqrt(pow(derr[a],2.)+pow(vd[a],2.)),2.);
                }
		cout << " boup= " << boup[4] << " voup= " << voup[4] << "\n";
                if (sumpt+sqrt(sumerrtwo)>boup[7]) boup[7]=sumpt+sqrt(sumerrtwo);
                if (sumpt-sqrt(sumerrtwo)<bodo[7]) bodo[7]=sumpt-sqrt(sumerrtwo);
                if (sumdi+sqrt(sumdierrtwo)>boup[6]) boup[6]=sumdi+sqrt(sumdierrtwo);
                if (sumdi-sqrt(sumdierrtwo)<bodo[6]) bodo[6]=sumdi-sqrt(sumdierrtwo);

                pbpb << x << " " << (boup[0]+bodo[0])/2. << " " << (boup[0]-bodo[0])/2. << " " << 
		(boup[1]+bodo[1])/2. << " " << (boup[1]-bodo[1])/2. << " " << 
		(boup[2]+bodo[2])/2. << " " << (boup[2]-bodo[2])/2. << " " << 
		(boup[3]+bodo[3])/2. << " " << (boup[3]-bodo[3])/2. << " " << 
		(boup[4]+bodo[4])/2. << " " << (boup[4]-bodo[4])/2. << " " << 
		(boup[5]+bodo[5])/2. << " " << (boup[5]-bodo[5])/2. << " " << 
		(boup[7]+bodo[7])/2. << " " << (boup[7]-bodo[7])/2. << "\n";

		pbpbmpp << x << " " << (voup[0]+vodo[0])/2. << " " << (voup[0]-vodo[0])/2. << " " << 
                (voup[1]+vodo[1])/2. << " " << (voup[1]-vodo[1])/2. << " " << 
                (voup[2]+vodo[2])/2. << " " << (voup[2]-vodo[2])/2. << " " << 
                (voup[3]+vodo[3])/2. << " " << (voup[3]-vodo[3])/2. << " " << 
                (voup[4]+vodo[4])/2. << " " << (voup[4]-vodo[4])/2. << " " << 
                (voup[5]+vodo[5])/2. << " " << (voup[5]-vodo[5])/2. << " " << 
                (boup[6]+bodo[6])/2. << " " << (boup[6]-bodo[6])/2. << "\n";

		if (corre==1) {
                        double scom=0.;
                        double scomerrtwo=0.;
                        correfile << x << " ";
                        for (unsigned a=0; a<6; a++) {
                                double com=ca[a];
                                double dcom=cd[a];
                                if (int(a)!=5) scom+=com, scomerrtwo+=pow(dcom,2.);
                                correfile << com << " " << dcom << " ";
                        }
                        correfile << scom << " " << scomerrtwo << "\n";
                }

                bin+=1;
        } while (bin<N);

	if (corre==1) correfile.close();
	pbpb.close();
	pbpbmpp.close();
//End Program
}


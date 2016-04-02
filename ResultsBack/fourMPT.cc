#include <iostream>
#include <fstream>
#include <iomanip>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <assert.h>
#include <sstream>

using namespace std;

int main (int argc, char** argv) {
        assert(argc==4);

        ostringstream outF, outFdif;
        ostringstream inf0, inf1, inf2, inf3, inf4, inf5, inf6, inf7, inf8, inf9, inf10, inf11, inf12, inf13, inf14, inf15, inf16;

	//Corre=0 No corrections, Corre=1 corrections
	int corre=atoi(argv[3]);

	if (atoi(argv[2])==1 && corre==1) outF << "Mpt/PbPbMpt0" << argv[1] << ".dat";
        if (atoi(argv[2])!=1 && corre==1) outF << "Mpt/PbPbMpt0" << argv[1] << "nb.dat";
        if (atoi(argv[2])==1 && corre==0) outF << "Mpt/NoCorr/PbPbMpt0" << argv[1] << ".dat";
	if (atoi(argv[2])!=1 && corre==0) outF << "Mpt/NoCorr/PbPbMpt0" << argv[1] << "nb.dat";
	if (atoi(argv[2])==1 && corre==1) outFdif << "Mpt/PbPbmppMpt0" << argv[1] << ".dat";
        if (atoi(argv[2])!=1 && corre==1) outFdif << "Mpt/PbPbmppMpt0" << argv[1] << "nb.dat";
        if (atoi(argv[2])==1 && corre==0) outFdif << "Mpt/NoCorr/PbPbmppMpt0" << argv[1] << ".dat";
        if (atoi(argv[2])!=1 && corre==0) outFdif << "Mpt/NoCorr/PbPbmppMpt0" << argv[1] << "nb.dat";

	ofstream built;
        built.open (outF.str().c_str());

	ofstream builtdif;
        builtdif.open (outFdif.str().c_str());

	ofstream correfile;
	if (corre==1) {
		ostringstream corrF;
		corrF << "Mpt/Corr/Corre0" << argv[1] << ".dat";
		correfile.open (corrF.str().c_str());
	}

        inf0 << "Vac/GenMPT/" << "VacMpt0" << argv[1] << ".dat";
        std::ifstream infile0(inf0.str().c_str());
	//Correction
        ostringstream infGa, infRa, infGb, infRb;
        infGa << "Vac/GenMPT/1VacMpt0" << argv[1] << ".dat";
        infRa << "Vac/RecoMPT/1VacMpt0" << argv[1] << ".dat";
	infGb << "Vac/GenMPT/2VacMpt0" << argv[1] << ".dat";
        infRb << "Vac/RecoMPT/2VacMpt0" << argv[1] << ".dat";
        if (atoi(argv[2])==1) {
                        inf1 << "1A/MedMpt0" << argv[1] << ".dat";
                        inf2 << "1B/MedMpt0" << argv[1] << ".dat";
                        inf3 << "1C/MedMpt0" << argv[1] << ".dat";
                        inf4 << "1D/MedMpt0" << argv[1] << ".dat";
                        inf5 << "2A/MedMpt0" << argv[1] << ".dat";
                        inf6 << "2B/MedMpt0" << argv[1] << ".dat";
                        inf7 << "2C/MedMpt0" << argv[1] << ".dat";
                        inf8 << "2D/MedMpt0" << argv[1] << ".dat";
                	inf9 << "3A/MedMpt0" << argv[1] << ".dat";
                        inf10 << "3B/MedMpt0" << argv[1] << ".dat";
                        inf11 << "3C/MedMpt0" << argv[1] << ".dat";
                        inf12 << "3D/MedMpt0" << argv[1] << ".dat";
                        inf13 << "4A/MedMpt0" << argv[1] << ".dat";
                        inf14 << "4B/MedMpt0" << argv[1] << ".dat";
                        inf15 << "4C/MedMpt0" << argv[1] << ".dat";
                        inf16 << "4D/MedMpt0" << argv[1] << ".dat";
        }
        else {
			inf1 << "1A/MedMpt0" << argv[1] << "nb.dat";
                        inf2 << "1B/MedMpt0" << argv[1] << "nb.dat";
                        inf3 << "1C/MedMpt0" << argv[1] << "nb.dat";
                        inf4 << "1D/MedMpt0" << argv[1] << "nb.dat";
                        inf5 << "2A/MedMpt0" << argv[1] << "nb.dat";
                        inf6 << "2B/MedMpt0" << argv[1] << "nb.dat";
                        inf7 << "2C/MedMpt0" << argv[1] << "nb.dat";
                        inf8 << "2D/MedMpt0" << argv[1] << "nb.dat";
                        inf9 << "3A/MedMpt0" << argv[1] << "nb.dat";
                        inf10 << "3B/MedMpt0" << argv[1] << "nb.dat";
                        inf11 << "3C/MedMpt0" << argv[1] << "nb.dat";
                        inf12 << "3D/MedMpt0" << argv[1] << "nb.dat";
                        inf13 << "4A/MedMpt0" << argv[1] << "nb.dat";
                        inf14 << "4B/MedMpt0" << argv[1] << "nb.dat";
                        inf15 << "4C/MedMpt0" << argv[1] << "nb.dat";
                        inf16 << "4D/MedMpt0" << argv[1] << "nb.dat";
        }
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

	std::ifstream infileRa(infRa.str().c_str());
        std::ifstream infileGa(infGa.str().c_str());
	std::ifstream infileRb(infRb.str().c_str());
        std::ifstream infileGb(infGb.str().c_str());

	double x,ra[8],rd[8],ga[8],gd[8],ca[6],cd[6],cca[6],ccd[6];
	double w1[4];
	w1[0]=0.286;
	w1[1]=0.221;
	w1[2]=0.308;
	w1[3]=0.185;

        double aa[8],ab[8],ac[8],ad[8],da[8],db[8],dc[8],dd[8],va[8],vd[8];
	double derr[6],dval[6],boup[8],bodo[8],difup[6],difdo[6],diferr[6],difval[6];
	double sumpt, sumerrtwo;
	double acum[4], errtwo[4];

        int bin=0;
        int N=10;
        do {
		infileRa >> x >> ra[0] >> rd[0] >> ra[1] >> rd[1] >> ra[2] >> rd[2] >> ra[3] >> rd[3] >> ra[4] >> rd[4] >> ra[5] >> rd[5]
        	>> ra[6] >> rd[6] >> ra[7];
        	infileGa >> x >> ga[0] >> gd[0] >> ga[1] >> gd[1] >> ga[2] >> gd[2] >> ga[3] >> gd[3] >> ga[4] >> gd[4] >> ga[5] >> gd[5]
        	>> ga[6] >> gd[6] >> ga[7];
        	for (unsigned a=0; a<6; a++) {
        	        ca[a]=ra[a]-ga[a];
        		if (corre==0) ca[a]=0.;
		        //cout << " ca[a]= " << ca[a] << "\n";
			cd[a]=sqrt(pow(rd[a],2.)+pow(gd[a],2.));
			if (corre==0) cd[a]=0.;
		}
        	infileRb >> x >> ra[0] >> rd[0] >> ra[1] >> rd[1] >> ra[2] >> rd[2] >> ra[3] >> rd[3] >> ra[4] >> rd[4] >> ra[5] >> rd[5]
        	>> ra[6] >> rd[6] >> ra[7];
        	infileGb >> x >> ga[0] >> gd[0] >> ga[1] >> gd[1] >> ga[2] >> gd[2] >> ga[3] >> gd[3] >> ga[4] >> gd[4] >> ga[5] >> gd[5]
        	>> ga[6] >> gd[6] >> ga[7];
        	for (unsigned a=0; a<6; a++) {
        	        cca[a]=ra[a]-ga[a];
			if (corre==0) cca[a]=0.;
        	        ccd[a]=sqrt(pow(rd[a],2.)+pow(gd[a],2.));
        		if (corre==0) ccd[a]=0.;
		}

		infile0 >> x >> va[0] >> vd[0] >> va[1] >> vd[1] >> va[2] >> vd[2] >> va[3] >> vd[3] >> va[4] >> vd[4] >> va[5] >> vd[5] >> va[6] >> vd[6] >> va[7];

                infile1 >> x >> aa[0] >> da[0] >> aa[1] >> da[1] >> aa[2] >> da[2] >> aa[3] >> da[3] >> aa[4] >> da[4] >> aa[5] >> da[5] >> aa[6] >> da[6] >> aa[7];
		infile2 >> x >> ab[0] >> db[0] >> ab[1] >> db[1] >> ab[2] >> db[2] >> ab[3] >> db[3] >> ab[4] >> db[4] >> ab[5] >> db[5] >> ab[6] >> db[6] >> ab[7];
		infile3 >> x >> ac[0] >> dc[0] >> ac[1] >> dc[1] >> ac[2] >> dc[2] >> ac[3] >> dc[3] >> ac[4] >> dc[4] >> ac[5] >> dc[5] >> ac[6] >> dc[6] >> ac[7];
		infile4 >> x >> ad[0] >> dd[0] >> ad[1] >> dd[1] >> ad[2] >> dd[2] >> ad[3] >> dd[3] >> ad[4] >> dd[4] >> ad[5] >> dd[5] >> ad[6] >> dd[6] >> ad[7];
		//Compute 0-30% all colors
		sumpt=0.;
		sumerrtwo=0.;
		cout << " ab[0] " << ab[0] << "\n";
		for (unsigned a=0; a<6; a++) {
			da[a]=sqrt(pow(da[a],2.)+pow(cd[a],2.));
			db[a]=sqrt(pow(db[a],2.)+pow(cd[a],2.));
			dc[a]=sqrt(pow(dc[a],2.)+pow(ccd[a],2.));
			dd[a]=sqrt(pow(dd[a],2.)+pow(ccd[a],2.));
			derr[a]=sqrt(pow(da[a]*w1[0],2.)+pow(db[a]*w1[1],2.)+pow(dc[a]*w1[2],2.)+pow(dd[a]*w1[3],2.));
			dval[a]=(aa[a]-ca[a])*w1[0]+(ab[a]-ca[a])*w1[1]+(ac[a]-cca[a])*w1[2]+(ad[a]-cca[a])*w1[3];
			diferr[a]=sqrt(pow(derr[a],2.)+pow(vd[a],2.));
			difval[a]=dval[a]-va[a];
			if (int(a)!=5) sumpt+=dval[a];
			if (int(a)!=5) sumerrtwo+=pow(derr[a],2.);
		}
		for (unsigned a=0; a<6; a++) {
			boup[a]=dval[a]+derr[a];
			bodo[a]=dval[a]-derr[a];
			difup[a]=difval[a]+diferr[a];
			difdo[a]=difval[a]-diferr[a];
		}
		boup[7]=sumpt+sqrt(sumerrtwo);
		bodo[7]=sumpt-sqrt(sumerrtwo);
		boup[6]=sumpt-va[6]+sqrt(sumerrtwo+pow(vd[6],2.));
		bodo[6]=sumpt-va[6]-sqrt(sumerrtwo+pow(vd[6],2.));
		if (bin==0) {
                        acum[0]=sumpt;
			errtwo[0]=sumerrtwo;
                }
                else {
			acum[0]+=sumpt;
			errtwo[0]+=sumerrtwo;
                }

		infile5 >> x >> aa[0] >> da[0] >> aa[1] >> da[1] >> aa[2] >> da[2] >> aa[3] >> da[3] >> aa[4] >> da[4] >> aa[5] >> da[5] >> aa[6] >> da[6] >> aa[7];
                infile6 >> x >> ab[0] >> db[0] >> ab[1] >> db[1] >> ab[2] >> db[2] >> ab[3] >> db[3] >> ab[4] >> db[4] >> ab[5] >> db[5] >> ab[6] >> db[6] >> ab[7];
                infile7 >> x >> ac[0] >> dc[0] >> ac[1] >> dc[1] >> ac[2] >> dc[2] >> ac[3] >> dc[3] >> ac[4] >> dc[4] >> ac[5] >> dc[5] >> ac[6] >> dc[6] >> ac[7];
                infile8 >> x >> ad[0] >> dd[0] >> ad[1] >> dd[1] >> ad[2] >> dd[2] >> ad[3] >> dd[3] >> ad[4] >> dd[4] >> ad[5] >> dd[5] >> ad[6] >> dd[6] >> ad[7];
                //Compute 0-30% all colors
		sumpt=0.;
		sumerrtwo=0.;
                for (unsigned a=0; a<6; a++) {
			da[a]=sqrt(pow(da[a],2.)+pow(cd[a],2.));
                        db[a]=sqrt(pow(db[a],2.)+pow(cd[a],2.));
                        dc[a]=sqrt(pow(dc[a],2.)+pow(ccd[a],2.));
                        dd[a]=sqrt(pow(dd[a],2.)+pow(ccd[a],2.));
                        derr[a]=sqrt(pow(da[a]*w1[0],2.)+pow(db[a]*w1[1],2.)+pow(dc[a]*w1[2],2.)+pow(dd[a]*w1[3],2.));
                        dval[a]=(aa[a]-ca[a])*w1[0]+(ab[a]-ca[a])*w1[1]+(ac[a]-cca[a])*w1[2]+(ad[a]-cca[a])*w1[3];
                        diferr[a]=sqrt(pow(derr[a],2.)+pow(vd[a],2.));
                        difval[a]=dval[a]-va[a];
			if (int(a)!=5) sumpt+=dval[a];
                        if (int(a)!=5) sumerrtwo+=pow(derr[a],2.);
                }
                for (unsigned a=0; a<6; a++) {
                        if (dval[a]+derr[a]>boup[a]) boup[a]=dval[a]+derr[a];
                        if (dval[a]-derr[a]<bodo[a]) bodo[a]=dval[a]-derr[a];
			if (difval[a]+diferr[a]>difup[a]) difup[a]=difval[a]+diferr[a];
			if (difval[a]-diferr[a]<difdo[a]) difdo[a]=difval[a]-diferr[a];
                }
                if (sumpt+sqrt(sumerrtwo)>boup[7]) boup[7]=sumpt+sqrt(sumerrtwo);
                if (sumpt-sqrt(sumerrtwo)<bodo[7]) bodo[7]=sumpt-sqrt(sumerrtwo);
		if (sumpt-va[6]+sqrt(sumerrtwo+pow(vd[6],2.))>boup[6]) boup[6]=sumpt-va[6]+sqrt(sumerrtwo+pow(vd[6],2.));
                if (sumpt-va[6]-sqrt(sumerrtwo+pow(vd[6],2.))<bodo[6]) bodo[6]=sumpt-va[6]-sqrt(sumerrtwo+pow(vd[6],2.));
		if (bin==0) {
                        acum[1]=sumpt;
                        errtwo[1]=sumerrtwo;
                }
                else {
                        acum[1]+=sumpt;
                	errtwo[1]+=sumerrtwo;
		}

		infile9 >> x >> aa[0] >> da[0] >> aa[1] >> da[1] >> aa[2] >> da[2] >> aa[3] >> da[3] >> aa[4] >> da[4] >> aa[5] >> da[5] >> aa[6] >> da[6] >> aa[7];
                infile10 >> x >> ab[0] >> db[0] >> ab[1] >> db[1] >> ab[2] >> db[2] >> ab[3] >> db[3] >> ab[4] >> db[4] >> ab[5] >> db[5] >> ab[6] >> db[6] >> ab[7];
                infile11 >> x >> ac[0] >> dc[0] >> ac[1] >> dc[1] >> ac[2] >> dc[2] >> ac[3] >> dc[3] >> ac[4] >> dc[4] >> ac[5] >> dc[5] >> ac[6] >> dc[6] >> ac[7];
                infile12 >> x >> ad[0] >> dd[0] >> ad[1] >> dd[1] >> ad[2] >> dd[2] >> ad[3] >> dd[3] >> ad[4] >> dd[4] >> ad[5] >> dd[5] >> ad[6] >> dd[6] >> ad[7];
                //Compute 0-30% all colors
                sumpt=0.;
                sumerrtwo=0.;
		for (unsigned a=0; a<6; a++) {
                        da[a]=sqrt(pow(da[a],2.)+pow(cd[a],2.));
                        db[a]=sqrt(pow(db[a],2.)+pow(cd[a],2.));
                        dc[a]=sqrt(pow(dc[a],2.)+pow(ccd[a],2.));
                        dd[a]=sqrt(pow(dd[a],2.)+pow(ccd[a],2.));
                        derr[a]=sqrt(pow(da[a]*w1[0],2.)+pow(db[a]*w1[1],2.)+pow(dc[a]*w1[2],2.)+pow(dd[a]*w1[3],2.));
                        dval[a]=(aa[a]-ca[a])*w1[0]+(ab[a]-ca[a])*w1[1]+(ac[a]-cca[a])*w1[2]+(ad[a]-cca[a])*w1[3];
                        diferr[a]=sqrt(pow(derr[a],2.)+pow(vd[a],2.));
                        difval[a]=dval[a]-va[a];
                        if (int(a)!=5) sumpt+=dval[a];
                        if (int(a)!=5) sumerrtwo+=pow(derr[a],2.);
                }
                for (unsigned a=0; a<6; a++) {
                        if (dval[a]+derr[a]>boup[a]) boup[a]=dval[a]+derr[a];
                        if (dval[a]-derr[a]<bodo[a]) bodo[a]=dval[a]-derr[a];
                        if (difval[a]+diferr[a]>difup[a]) difup[a]=difval[a]+diferr[a];
                        if (difval[a]-diferr[a]<difdo[a]) difdo[a]=difval[a]-diferr[a];
                }
                if (sumpt+sqrt(sumerrtwo)>boup[7]) boup[7]=sumpt+sqrt(sumerrtwo);
                if (sumpt-sqrt(sumerrtwo)<bodo[7]) bodo[7]=sumpt-sqrt(sumerrtwo);
		if (sumpt-va[6]+sqrt(sumerrtwo+pow(vd[6],2.))>boup[6]) boup[6]=sumpt-va[6]+sqrt(sumerrtwo+pow(vd[6],2.));
                if (sumpt-va[6]-sqrt(sumerrtwo+pow(vd[6],2.))<bodo[6]) bodo[6]=sumpt-va[6]-sqrt(sumerrtwo+pow(vd[6],2.));
		if (bin==0) {
                        acum[2]=sumpt;
                        errtwo[2]=sumerrtwo;
                }
                else {
                        acum[2]+=sumpt;
                        errtwo[2]+=sumerrtwo;
                }

		infile13 >> x >> aa[0] >> da[0] >> aa[1] >> da[1] >> aa[2] >> da[2] >> aa[3] >> da[3] >> aa[4] >> da[4] >> aa[5] >> da[5] >> aa[6] >> da[6] >> aa[7];
                infile14 >> x >> ab[0] >> db[0] >> ab[1] >> db[1] >> ab[2] >> db[2] >> ab[3] >> db[3] >> ab[4] >> db[4] >> ab[5] >> db[5] >> ab[6] >> db[6] >> ab[7];
                infile15 >> x >> ac[0] >> dc[0] >> ac[1] >> dc[1] >> ac[2] >> dc[2] >> ac[3] >> dc[3] >> ac[4] >> dc[4] >> ac[5] >> dc[5] >> ac[6] >> dc[6] >> ac[7];
                infile16 >> x >> ad[0] >> dd[0] >> ad[1] >> dd[1] >> ad[2] >> dd[2] >> ad[3] >> dd[3] >> ad[4] >> dd[4] >> ad[5] >> dd[5] >> ad[6] >> dd[6] >> ad[7];
                //Compute 0-30% all colors
                sumpt=0.;
                sumerrtwo=0.;
		for (unsigned a=0; a<6; a++) {
                        da[a]=sqrt(pow(da[a],2.)+pow(cd[a],2.));
                        db[a]=sqrt(pow(db[a],2.)+pow(cd[a],2.));
                        dc[a]=sqrt(pow(dc[a],2.)+pow(ccd[a],2.));
                        dd[a]=sqrt(pow(dd[a],2.)+pow(ccd[a],2.));
                        derr[a]=sqrt(pow(da[a]*w1[0],2.)+pow(db[a]*w1[1],2.)+pow(dc[a]*w1[2],2.)+pow(dd[a]*w1[3],2.));
                        dval[a]=(aa[a]-ca[a])*w1[0]+(ab[a]-ca[a])*w1[1]+(ac[a]-cca[a])*w1[2]+(ad[a]-cca[a])*w1[3];
                        diferr[a]=sqrt(pow(derr[a],2.)+pow(vd[a],2.));
                        difval[a]=dval[a]-va[a];
                        if (int(a)!=5) sumpt+=dval[a];
                        if (int(a)!=5) sumerrtwo+=pow(derr[a],2.);
                }
                for (unsigned a=0; a<6; a++) {
                        if (dval[a]+derr[a]>boup[a]) boup[a]=dval[a]+derr[a];
                        if (dval[a]-derr[a]<bodo[a]) bodo[a]=dval[a]-derr[a];
                        if (difval[a]+diferr[a]>difup[a]) difup[a]=difval[a]+diferr[a];
                        if (difval[a]-diferr[a]<difdo[a]) difdo[a]=difval[a]-diferr[a];
                }
                if (sumpt+sqrt(sumerrtwo)>boup[7]) boup[7]=sumpt+sqrt(sumerrtwo);
                if (sumpt-sqrt(sumerrtwo)<bodo[7]) bodo[7]=sumpt-sqrt(sumerrtwo);
		if (sumpt-va[6]+sqrt(sumerrtwo+pow(vd[6],2.))>boup[6]) boup[6]=sumpt-va[6]+sqrt(sumerrtwo+pow(vd[6],2.));
                if (sumpt-va[6]-sqrt(sumerrtwo+pow(vd[6],2.))<bodo[6]) bodo[6]=sumpt-va[6]-sqrt(sumerrtwo+pow(vd[6],2.));
		if (bin==0) {
                        acum[3]=sumpt;
                        errtwo[3]=sumerrtwo;
                }
                else {
                        acum[3]+=sumpt;
                        errtwo[3]+=sumerrtwo;
                }

		double finup=acum[0];
		double findo=acum[0];
		for (unsigned a=1; a<4; a++) {
			if (acum[a]>finup) finup=acum[a];
			if (acum[a]<findo) findo=acum[a];
		}
		//bin 6 colors sumpt sumpt-pp acum
                built << x << " " << (boup[0]+bodo[0])/2. << " " << (boup[0]-bodo[0])/2. 
		<< " " << (boup[1]+bodo[1])/2. << " " << (boup[1]-bodo[1])/2. 
		<< " " << (boup[2]+bodo[2])/2. << " " << (boup[2]-bodo[2])/2. 
		<< " " << (boup[3]+bodo[3])/2. << " " << (boup[3]-bodo[3])/2. 
		<< " " << (boup[4]+bodo[4])/2. << " " << (boup[4]-bodo[4])/2. 
		<< " " << (boup[5]+bodo[5])/2. << " " << (boup[5]-bodo[5])/2. 
		<< " " << (boup[7]+bodo[7])/2. << " " << (boup[7]-bodo[7])/2. 
		<< " " << (boup[6]+bodo[6])/2. << " " << (boup[6]-bodo[6])/2. 
		<< " " << (finup+findo)/2. << " " << (finup-findo)/2. << "\n";

		//bin 6 sumpt-pp intept
                builtdif << x << " " << (difup[0]+difdo[0])/2. << " " << (difup[0]-difdo[0])/2. 
                << " " << (difup[1]+difdo[1])/2. << " " << (difup[1]-difdo[1])/2. 
                << " " << (difup[2]+difdo[2])/2. << " " << (difup[2]-difdo[2])/2. 
                << " " << (difup[3]+difdo[3])/2. << " " << (difup[3]-difdo[3])/2. 
                << " " << (difup[4]+difdo[4])/2. << " " << (difup[4]-difdo[4])/2. 
                << " " << (difup[5]+difdo[5])/2. << " " << (difup[5]-difdo[5])/2. 
                << " " << (boup[6]+bodo[6])/2. << " " << (boup[6]-bodo[6])/2. << "\n";

		if (corre==1) {
			double scom=0.;
			double scomerrtwo=0.;
			correfile << x << " ";
			for (unsigned a=0; a<6; a++) {
				double com=ca[a]*(w1[0]+w1[1])+cca[a]*(w1[2]+w1[3]);
				double dcom=sqrt(pow((w1[0]+w1[1])*cd[a],2.)+pow((w1[2]+w1[3])*ccd[a],2.));
				if (int(a)!=5) scom+=com, scomerrtwo+=pow(dcom,2.);
				correfile << com << " " << dcom << " ";
			}
			correfile << scom << " " << sqrt(scomerrtwo) << "\n";
		}

                bin+=1;
        } while (bin<N);

if (corre==1) correfile.close();
built.close();
builtdif.close();
//End Program
}


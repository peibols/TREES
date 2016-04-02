#include <iostream>
#include <fstream>
#include <iomanip>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <assert.h>
#include <sstream>

using namespace std;

//Arguments: Radius (2,3,4,5), Back (1) or NoBack (2), Corre (1) or NoCorre(0), Cent 0-10%(1) or 10-30%(2)
int main (int argc, char** argv) {
        assert(argc==5);

        ostringstream outF, outFdif;
        ostringstream inf0, inf1, inf2, inf3, inf4, inf5, inf6, inf7, inf8;

	int cent=atoi(argv[4]);
	//Corre=0 No corrections, Corre=1 corrections
	int corre=atoi(argv[3]);

	if (atoi(argv[2])==1 && corre==1) outF << "Mpt/" << cent << "PbPbMpt0" << argv[1] << ".dat";
        if (atoi(argv[2])!=1 && corre==1) outF << "Mpt/" << cent << "PbPbMpt0" << argv[1] << "nb.dat";
        if (atoi(argv[2])==1 && corre==0) outF << "Mpt/NoCorr/" << cent << "PbPbMpt0" << argv[1] << ".dat";
	if (atoi(argv[2])!=1 && corre==0) outF << "Mpt/NoCorr/" << cent << "PbPbMpt0" << argv[1] << "nb.dat";

	ofstream built;
        built.open (outF.str().c_str());

	ofstream correfile;
	if (corre==1) {
		ostringstream corrF;
		corrF << "Mpt/Corr/" << cent << "Corre0" << argv[1] << ".dat";
		correfile.open (corrF.str().c_str());
	}

        inf0 << "Vac/GenMPT/" << "VacMpt0" << argv[1] << ".dat";
        std::ifstream infile0(inf0.str().c_str());
	//Correction
        ostringstream infGa, infRa;
	if (cent==1) {
	        infGa << "Vac/GenMPT/1VacMpt0" << argv[1] << ".dat";
	        infRa << "Vac/RecoMPT/1VacMpt0" << argv[1] << ".dat";
	}
	else {
		infGa << "Vac/GenMPT/2VacMpt0" << argv[1] << ".dat";
	        infRa << "Vac/RecoMPT/2VacMpt0" << argv[1] << ".dat";
	}
        if (atoi(argv[2])==1) {
		if (cent==1) {
                        inf1 << "1A/MedMpt0" << argv[1] << ".dat";
                        inf2 << "1B/MedMpt0" << argv[1] << ".dat";
                        inf3 << "2A/MedMpt0" << argv[1] << ".dat";
                        inf4 << "2B/MedMpt0" << argv[1] << ".dat";
                        inf5 << "3A/MedMpt0" << argv[1] << ".dat";
                        inf6 << "3B/MedMpt0" << argv[1] << ".dat";
                        inf7 << "4A/MedMpt0" << argv[1] << ".dat";
                        inf8 << "4B/MedMpt0" << argv[1] << ".dat";
                }
		else {
			inf1 << "1C/MedMpt0" << argv[1] << ".dat";
                        inf2 << "1D/MedMpt0" << argv[1] << ".dat";
                        inf3 << "2C/MedMpt0" << argv[1] << ".dat";
                        inf4 << "2D/MedMpt0" << argv[1] << ".dat";
                        inf5 << "3C/MedMpt0" << argv[1] << ".dat";
                        inf6 << "3D/MedMpt0" << argv[1] << ".dat";
                        inf7 << "4C/MedMpt0" << argv[1] << ".dat";
                        inf8 << "4D/MedMpt0" << argv[1] << ".dat";
        	}
	}
        else {
		if (cent==1) {
                        inf1 << "1A/MedMpt0" << argv[1] << "nb.dat";
                        inf2 << "1B/MedMpt0" << argv[1] << "nb.dat";
                        inf3 << "2A/MedMpt0" << argv[1] << "nb.dat";
                        inf4 << "2B/MedMpt0" << argv[1] << "nb.dat";
                        inf5 << "3A/MedMpt0" << argv[1] << "nb.dat";
                        inf6 << "3B/MedMpt0" << argv[1] << "nb.dat";
                        inf7 << "4A/MedMpt0" << argv[1] << "nb.dat";
                        inf8 << "4B/MedMpt0" << argv[1] << "nb.dat";
                }
                else {
                        inf1 << "1C/MedMpt0" << argv[1] << "nb.dat";
                        inf2 << "1D/MedMpt0" << argv[1] << "nb.dat";
                        inf3 << "2C/MedMpt0" << argv[1] << "nb.dat";
                        inf4 << "2D/MedMpt0" << argv[1] << "nb.dat";
                        inf5 << "3C/MedMpt0" << argv[1] << "nb.dat";
                        inf6 << "3D/MedMpt0" << argv[1] << "nb.dat";
                        inf7 << "4C/MedMpt0" << argv[1] << "nb.dat";
                        inf8 << "4D/MedMpt0" << argv[1] << "nb.dat";
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

	std::ifstream infileRa(infRa.str().c_str());
        std::ifstream infileGa(infGa.str().c_str());

	double x,ra[8],rd[8],ga[8],gd[8],ca[6],cd[6],cca[6],ccd[6];
	double w1[2],w2[2];
	w1[1]=0.563;
        w2[1]=0.437;
        w1[2]=0.624;
        w2[2]=0.376;

        double aa[8],ab[8],ac[8],ad[8],da[8],db[8],dc[8],dd[8],va[8],vd[8];
	double derr[6],dval[6],boup[8],bodo[8];
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

		infile0 >> x >> va[0] >> vd[0] >> va[1] >> vd[1] >> va[2] >> vd[2] >> va[3] >> vd[3] >> va[4] >> vd[4] >> va[5] >> vd[5] >> va[6] >> vd[6] >> va[7];

                infile1 >> x >> aa[0] >> da[0] >> aa[1] >> da[1] >> aa[2] >> da[2] >> aa[3] >> da[3] >> aa[4] >> da[4] >> aa[5] >> da[5] >> aa[6] >> da[6] >> aa[7];
		infile2 >> x >> ab[0] >> db[0] >> ab[1] >> db[1] >> ab[2] >> db[2] >> ab[3] >> db[3] >> ab[4] >> db[4] >> ab[5] >> db[5] >> ab[6] >> db[6] >> ab[7];
		sumpt=0.;
		sumerrtwo=0.;
		cout << " ab[0] " << ab[0] << "\n";
		for (unsigned a=0; a<6; a++) {
			da[a]=sqrt(pow(da[a],2.)+pow(cd[a],2.));
			db[a]=sqrt(pow(db[a],2.)+pow(cd[a],2.));
			derr[a]=sqrt(pow(da[a]*w1[cent],2.)+pow(db[a]*w2[cent],2.));
			dval[a]=(aa[a]-ca[a])*w1[cent]+(ab[a]-ca[a])*w2[cent];
			if (int(a)!=5) sumpt+=dval[a];
			if (int(a)!=5) sumerrtwo+=pow(derr[a],2.);
		}
		for (unsigned a=0; a<6; a++) {
			boup[a]=dval[a]+derr[a];
			bodo[a]=dval[a]-derr[a];
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

		infile3 >> x >> aa[0] >> da[0] >> aa[1] >> da[1] >> aa[2] >> da[2] >> aa[3] >> da[3] >> aa[4] >> da[4] >> aa[5] >> da[5] >> aa[6] >> da[6] >> aa[7];
                infile4 >> x >> ab[0] >> db[0] >> ab[1] >> db[1] >> ab[2] >> db[2] >> ab[3] >> db[3] >> ab[4] >> db[4] >> ab[5] >> db[5] >> ab[6] >> db[6] >> ab[7];
		sumpt=0.;
		sumerrtwo=0.;
                for (unsigned a=0; a<6; a++) {
			da[a]=sqrt(pow(da[a],2.)+pow(cd[a],2.));
                        db[a]=sqrt(pow(db[a],2.)+pow(cd[a],2.));
                        derr[a]=sqrt(pow(da[a]*w1[cent],2.)+pow(db[a]*w2[cent],2.));
                        dval[a]=(aa[a]-ca[a])*w1[cent]+(ab[a]-ca[a])*w2[cent];
                        if (int(a)!=5) sumpt+=dval[a];
                        if (int(a)!=5) sumerrtwo+=pow(derr[a],2.);
                }
                for (unsigned a=0; a<6; a++) {
                        if (dval[a]+derr[a]>boup[a]) boup[a]=dval[a]+derr[a];
                        if (dval[a]-derr[a]<bodo[a]) bodo[a]=dval[a]-derr[a];
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

		infile5 >> x >> aa[0] >> da[0] >> aa[1] >> da[1] >> aa[2] >> da[2] >> aa[3] >> da[3] >> aa[4] >> da[4] >> aa[5] >> da[5] >> aa[6] >> da[6] >> aa[7];
                infile6 >> x >> ab[0] >> db[0] >> ab[1] >> db[1] >> ab[2] >> db[2] >> ab[3] >> db[3] >> ab[4] >> db[4] >> ab[5] >> db[5] >> ab[6] >> db[6] >> ab[7];
                sumpt=0.;
                sumerrtwo=0.;
                for (unsigned a=0; a<6; a++) {
                        da[a]=sqrt(pow(da[a],2.)+pow(cd[a],2.));
                        db[a]=sqrt(pow(db[a],2.)+pow(cd[a],2.));
                        derr[a]=sqrt(pow(da[a]*w1[cent],2.)+pow(db[a]*w2[cent],2.));
                        dval[a]=(aa[a]-ca[a])*w1[cent]+(ab[a]-ca[a])*w2[cent];
                        if (int(a)!=5) sumpt+=dval[a];
                        if (int(a)!=5) sumerrtwo+=pow(derr[a],2.);
                }
                for (unsigned a=0; a<6; a++) {
                        if (dval[a]+derr[a]>boup[a]) boup[a]=dval[a]+derr[a];
                        if (dval[a]-derr[a]<bodo[a]) bodo[a]=dval[a]-derr[a];
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

		infile7 >> x >> aa[0] >> da[0] >> aa[1] >> da[1] >> aa[2] >> da[2] >> aa[3] >> da[3] >> aa[4] >> da[4] >> aa[5] >> da[5] >> aa[6] >> da[6] >> aa[7];
                infile8 >> x >> ab[0] >> db[0] >> ab[1] >> db[1] >> ab[2] >> db[2] >> ab[3] >> db[3] >> ab[4] >> db[4] >> ab[5] >> db[5] >> ab[6] >> db[6] >> ab[7];
                sumpt=0.;
                sumerrtwo=0.;
                for (unsigned a=0; a<6; a++) {
                        da[a]=sqrt(pow(da[a],2.)+pow(cd[a],2.));
                        db[a]=sqrt(pow(db[a],2.)+pow(cd[a],2.));
                        derr[a]=sqrt(pow(da[a]*w1[cent],2.)+pow(db[a]*w2[cent],2.));
                        dval[a]=(aa[a]-ca[a])*w1[cent]+(ab[a]-ca[a])*w2[cent];
                        if (int(a)!=5) sumpt+=dval[a];
                        if (int(a)!=5) sumerrtwo+=pow(derr[a],2.);
                }
                for (unsigned a=0; a<6; a++) {
                        if (dval[a]+derr[a]>boup[a]) boup[a]=dval[a]+derr[a];
                        if (dval[a]-derr[a]<bodo[a]) bodo[a]=dval[a]-derr[a];
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
built.close();
//End Program
}


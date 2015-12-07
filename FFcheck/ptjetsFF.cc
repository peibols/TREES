//g++ -Wall Backreaction/FFcheck/ptjetsFF.cc -o Backreaction/FFcheck/ptjetsFF `fastjet-install/bin/fastjet-config --cxxflags --libs --plugins`
#include "fastjet/ClusterSequence.hh"
#include <iostream>
#include <fstream>
#include <iomanip>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
using namespace fastjet;
using namespace std;
int ir=1349;
double rando(int*);
int main () {
	ofstream fffile;
	ofstream shapfile;

	//#define HADRONIC
        #define VAC

#ifndef HADRONIC
	std::ifstream infile2("/home/peibols/NewHD/UliInv/Strong276/BACK1/1A.txt");
	#ifdef VAC
		fffile.open ("Backreaction/FFcheck/FFPartVnoEta.dat");
		shapfile.open ("Backreaction/FFcheck/ShapPartVnoEta.dat");
	#endif
	#ifndef VAC
		fffile.open ("Backreaction/FFcheck/FFPartMnoEta.dat");
                shapfile.open ("Backreaction/FFcheck/ShapPartMnoEta.dat");
	#endif
#endif

#ifdef HADRONIC
	#ifdef VAC
		std::ifstream infile2("/home/peibols/NewHD/UliInv/Strong276/hadVAC.txt");
		fffile.open ("Backreaction/FFcheck/FFHadVnoEta.dat");
		shapfile.open ("Backreaction/FFcheck/ShapHadVnoEta.dat");
	#endif
	#ifndef VAC
		std::ifstream infile2("/home/peibols/NewHD/UliInv/Strong276/BACK1/1Ahad.txt");
		fffile.open ("Backreaction/FFcheck/FFHadMnoEta.dat");
		shapfile.open ("Backreaction/FFcheck/ShapHadMnoEta.dat");
	#endif
#endif

	double pi=3.14159265359;
	double ptcut=100.;
	double fptcut=1.;

	int N=250000;

	int smearaxis=0;
        double meanshift=0.;
        double sigma=0.01;
	double axgauss, shphi, shrap, munt, fu, rup;

	int smearpt=0;
	double sfac=5.23;

	int etareflec=0;

	int count=0;
	double R=0.3;
	double binsize=R/6.;

	//FF Initialization
	double fragm[29];
	for (unsigned t=0; t<29; t++) {
		fragm[t]=0.;
	}

	//Jet Shapes Initialization
	double shapm[6], shap2m[6];
	double nshapm=0.;
	double fchm=0.;
	for (unsigned a=0; a<6; a++) {
		shapm[a]=0.;
		shap2m[a]=0.;
	}

	int nevents=0;
	vector<PseudoJet> particles;
	do {
		double momx[500], momy[500], momz[500], ener[500], mass[500], raper[500], mompt[500], pchar[500];
		int k=0;
	#ifdef HADRONIC
		double pdg, Px, Py, Pz, E, noth, charge;
		while (infile2 >> pdg >> Px >> Py >> Pz >> E >> noth >> charge)
		{
			if (pdg == 0.000123 && Px == 0. && Py == 0.) {
				break;
			}
			else {
				particles.push_back( PseudoJet(   Px,  Py,  Pz, E) );
				momx[k]=Px;
		 		momy[k]=Py;
		 		momz[k]=Pz;
		 		ener[k]=E;
				mompt[k]=sqrt(pow(Px,2.)+pow(Py,2.));
				mass[k]=sqrt(pow(E,2.)-pow(mompt[k],2.)-pow(Pz,2.));
				if (mass[k]!=mass[k]) mass[k]=0.;
				raper[k]=1./2.*log((sqrt(pow(mompt[k],2.)+pow(Pz,2.))+Pz)/(sqrt(pow(mompt[k],2.)+pow(Pz,2.))-Pz));
				//pchar[k]=charge;	//Only Charged
				pchar[k]=1.;		//All Tracks
		  		k+=1;
			}
		}
	#endif
	#ifndef HADRONIC
		double Px, Py, Pz, E, Qx, Qy, Qz, Qe, qg, ini, col, acol, ide;
		while (infile2 >> Px >> Py >> Pz >> E >> Qx >> Qy >> Qz >> Qe >> qg >> ini >> col >> acol >> ide)
                {
                        if (Px == 0.000123 && Py == 0. && Pz == 0.) {
                                break;
                        }
                        else if (qg!=0.) {			//To Exclude Remnants
				#ifdef VAC
					double IsX=Px, IsY=Py, IsZ=Pz, IsE=E;
				#endif
				#ifndef VAC
					double IsX=Qx, IsY=Qy, IsZ=Qz, IsE=Qe;
				#endif
                                particles.push_back( PseudoJet(   IsX,  IsY,  IsZ, IsE) );
                                momx[k]=IsX;
                                momy[k]=IsY;
                                momz[k]=IsZ;
                                ener[k]=IsE;
                                mompt[k]=sqrt(pow(IsX,2.)+pow(IsY,2.));
                                mass[k]=sqrt(pow(IsE,2.)-pow(mompt[k],2.)-pow(IsZ,2.));
                                if (mass[k]!=mass[k]) mass[k]=0.;
                                raper[k]=1./2.*log((sqrt(pow(mompt[k],2.)+pow(IsZ,2.))+IsZ)/(sqrt(pow(mompt[k],2.)+pow(IsZ,2.))-IsZ));
                                pchar[k]=1.;
                                k+=1;
                        }
                }
	#endif

		if (k!=0) nevents+=1;
		JetDefinition jet_def(antikt_algorithm, R);
		//run the clustering, extract the jets
		ClusterSequence cs(particles, jet_def);
		vector<PseudoJet> jets = sorted_by_pt(cs.inclusive_jets());
		int nojets=0;
		if (jets.size()==0) nojets=1;
		//cout << " jetSize= " << jets.size()<< " ";

		int po=0;
		int LV=0;
		int SV=1;
		int LN=0;
		int SN=1;
		double rj[1000][12];
		for (unsigned g=0; g<jets.size(); g++) {
			if (abs(jets[g].eta())<2. && nojets!=1) {
				// Px, Py and Pz
				rj[po][7]=jets[g].px();
				rj[po][8]=jets[g].py();
				rj[po][9]=jets[g].pz();
				// Rap
				rj[po][6]=jets[g].pseudorapidity();
				// Vacuum Pt
				rj[po][3]=jets[g].pt();
				//Energy
				rj[po][10]=jets[g].e();
				//Label
				rj[po][11]=g;
				//Smearing
				double fgaus=0.;
				double xusran;
				double usran=1.;
				do {
					usran=rando(&ir);
					xusran=10.*rando(&ir)-5.;
					fgaus=exp(-0.5*xusran*xusran);
				} while (usran>fgaus);
				double func=sqrt(0.0246*0.0246+1.213*1.213/rj[po][3]+sfac*sfac/(rj[po][3]*rj[po][3]));
				rj[po][4]=rj[po][3];
				if (rj[po][3]>15.) {
					if (smearpt==1) rj[po][4]*=(1.+func*xusran);
				}
				//End Smearing

				//Smeared: Find correct order for asymmetry and dijet in Vacuum
				if (po>0) {
					if (rj[po][4]>rj[LV][4]) SV=LV, LV=po;
					else {
						if (rj[po][4]>rj[SV][4]) SV=po;
					}
				}
				if (po>0) {
                                        if (rj[po][3]>rj[LN][3]) SN=LN, LN=po;
                                        else {
                                                if (rj[po][3]>rj[SN][3]) SN=po;
                                        }
                                }
				po+=1;
			}
		}

		//Jet Shapes & Frag Func (SMEARED)
		double ishapm[6];
		for (int h=0; h<po; h++) {
			double pjet=rj[h][4];
			for (unsigned a=0; a<6; a++) {
				ishapm[a]=0.;
			}
			if (pjet>100. && pjet<300. && abs(rj[h][6])>0.3) {
				nshapm+=1.;
				double rap=rj[h][6];
				double fac=pjet/rj[h][3];
				shphi=0.;
                                shrap=0.;
                                if (smearaxis==1) {
                                        axgauss=0.;
                                        munt=1.;
                                        do {
                                                fu=-1.+2.*rando(&ir);
                                                rup=-1.+2.*rando(&ir);
                                                axgauss=exp(-(pow(fu,2.)+pow(rup,2.))/2./pow(sigma,2.));
                                                munt=rando(&ir);
                                        } while (axgauss<munt);
                                        shphi=fu;
                                        shrap=rup;
                                        //cout << " shiftAxis= " << sqrt(pow(shphi,2.)+pow(shrap,2.)) << "\n";
                                        meanshift+=sqrt(pow(shphi,2.)+pow(shrap,2.));
                                }
				int na;
				double ptfrag, rapfrag, DeltaPhi, DeltaRap, DeltaR, DeltaRf, rDeltaR, rDeltaRf, rDeltaRap, vari;
				for (int vt=0; vt<k; vt++) {
					ptfrag=sqrt(momx[vt]*momx[vt]+momy[vt]*momy[vt]);
					rapfrag=raper[vt];
					DeltaPhi=acos((rj[h][7]*momx[vt]+rj[h][8]*momy[vt])/(ptfrag*rj[h][3]));
					DeltaRap=rap-rapfrag;
					DeltaR=sqrt(pow(DeltaPhi+shphi,2.)+pow(DeltaRap+shrap,2.));
					if (DeltaR!=DeltaR) DeltaR=0.;
					if (DeltaR<R && ptfrag>fptcut && pchar[vt]!=0.) {
						ishapm[int(DeltaR/binsize)]+=ptfrag;
					}
					rDeltaRap=-rap-rapfrag;
					rDeltaR=sqrt(pow(DeltaPhi+shphi,2.)+pow(rDeltaRap-shrap,2.));
					if (rDeltaR!=rDeltaR) rDeltaR=0.;
					if (rDeltaR<R && ptfrag>fptcut && pchar[vt]!=0.) {
                                                if (etareflec!=0) ishapm[int(rDeltaR/binsize)]-=ptfrag;
                                        }
					DeltaRf=sqrt(pow(DeltaPhi,2.)+pow(DeltaRap,2.));
                                	if (DeltaRf!=DeltaRf) DeltaRf=0.;
                                	if (DeltaRf<R && ptfrag>fptcut && pchar[vt]!=0.) {
                                		vari=(momx[vt]*rj[h][7]+momy[vt]*rj[h][8]+momz[vt]*rj[h][9])/(fac*(pow(rj[h][7],2.)+pow(rj[h][8],2.)+pow(rj[h][9],2.)));
                                	        na=int(2.*log(1./vari));
                                	        if (na>=0) fragm[na]+=1.;
                                	}
                                        rDeltaRf=sqrt(pow(DeltaPhi,2.)+pow(rDeltaRap,2.));
                                        if (rDeltaRf!=rDeltaRf) rDeltaRf=0.;
                                        if (rDeltaRf<R && ptfrag>fptcut && pchar[vt]!=0.) {
                                                vari=(momx[vt]*rj[h][7]+momy[vt]*rj[h][8]-momz[vt]*rj[h][9])/(fac*(pow(rj[h][7],2.)+pow(rj[h][8],2.)+pow(rj[h][9],2.)));
                                                na=int(2.*log(1./vari));
                                                if (na>=0 && etareflec!=0) fragm[na]-=1.;
                                 	}
				}
				double mptcone=0.;
				for (unsigned a=0; a<6; a++) {
					mptcone+=ishapm[a];
				}
				fchm+=mptcone/pjet;
				for (unsigned a=0; a<6; a++) {
					shapm[a]+=ishapm[a]/pjet;
					shap2m[a]+=pow(ishapm[a]/pjet,2.);
				}
			}
		}


		particles.clear();
		jets.clear();
		count+=1;
		cout <<  count << "\n";
	} while (count<N);
	cout << " Nshapm= " << nshapm << "\n";
	cout << " Nevents= " << nevents << "\n";

	//Histos
	//FF
	double meantracks=0.;
	for (unsigned e=0; e<10; e++) {
		double z=double(e)/2.;
		fffile << z+1./4. << " " << fragm[e]/nshapm << " " << sqrt(fragm[e])/nshapm << "\n";
		meantracks+=fragm[e]/nshapm;
	}
	cout << " <TracksperJetinFF>= " << meantracks << "\n";

	//Jet Shapes
	for (unsigned q=0; q<6; q++) {
		double vsher=sqrt(shap2m[q]+nshapm*pow(shapm[q]/nshapm,2.)-2.*shapm[q]/nshapm*shapm[q])/sqrt(nshapm*nshapm-nshapm)/binsize/(fchm/nshapm);
		shapfile << binsize/2.+double(q)*binsize << " " << shapm[q]/(nshapm*binsize)/(fchm/nshapm) << " " << vsher << "\n";
	}

	fffile.close();
	shapfile.close();

//End Main
}
//--------------Random Number-----------------------//
double rando (int *ir)
{
	double da=16807.;
	double db=2147483647.;
	double dc=2147483648.;
	double usran;

	*ir=int(abs(fmod(da*(*ir),db)+0.5));
	usran=double(*ir)/dc;
	return usran;
}

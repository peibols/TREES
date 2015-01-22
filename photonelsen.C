#include "Pythia8/Pythia.h"
#include "Pythia8/Event.h"
#include <math.h>
#include <fstream>
#include <iostream>
#include <iomanip>
using namespace std;
using namespace Pythia8;

int photonelsen() {

ofstream geneal;
ofstream angle;

//geneal.open ("/media/My Passport/TREES/bigRHICtree5.txt");
geneal.open ("TREES/PHOT20good.txt");
Pythia pythia;
pythia.readString("Beams:idB = 2212");
pythia.readString("Beams:eCM = 2760.");
pythia.readString("SoftQCD:all = off");
pythia.readString("HardQCD:all = on");
pythia.readString("HadronLevel:all = off");
pythia.readString("PartonLevel:ISR = on");
pythia.readString("PartonLevel:MPI = off");
pythia.readString("TimeShower:pTmin = 1.");
pythia.readString("PromptPhoton:nQuarkLoop = 4");
pythia.readString("PromptPhoton:all = on");

int N=50000;
int keep=0;
int count=0;
int finals, counter, m1, m2, use, qg, mam, mim, ini, b;
double tx,ty,tz,te,pex,pey,pez,pee,rapphot;
int phot[5];
double isolated=0.;
double prompt=0.;
double pete=0.;
double sumene;
double deltaphi, deltaR, deltarap;
//Mega array where first index is identity, and second runs through px, py, pz, E, mom, done, virt
double ultra[1000][7];

// Pthat begin loop
for (unsigned ei = 0; ei<1; ei++) {
      if (ei==0) pythia.readString("PhaseSpace:pTHatMin = 20.");
      if (ei==1) pythia.readString("PhaseSpace:pTHatMin = 30.");
      if (ei==2) pythia.readString("PhaseSpace:pTHatMin = 50.");
      if (ei==3) pythia.readString("PhaseSpace:pTHatMin = 80.");
      if (ei==4) pythia.readString("PhaseSpace:pTHatMin = 120.");
      if (ei==5) pythia.readString("PhaseSpace:pTHatMin = 170.");
      if (ei==6) pythia.readString("PhaseSpace:pTHatMin = 220.");
      if (ei==7) pythia.readString("PhaseSpace:pTHatMin = 280.");
      if (ei==8) pythia.readString("PhaseSpace:pTHatMin = 370.");
      pythia.init();

	// Begin event loop. Generate event. Skip if error. List first one.
	do {
		if (pythia.event.size()>950) {
			cout << " size= " << pythia.event.size();
		}
		finals = 0;
		counter = 0;
		b=0;
		for (unsigned e=0;e<1000; e++) {
			for (unsigned f=0;f<2;f++) {
				ultra[e][4+f]=0.;
			}
		}

		if (!pythia.next()) continue;
		int thereis=0;
    		// Loop over final particles in event. Reconstruct genealogical tree.
    		for (int i = 0; i < pythia.event.size(); ++i) {
      			if (pythia.event[i].isFinal()) {
         			if (pythia.event[i].mother2() == 0) continue;
				if (pythia.event.size()>1000) continue;
         			finals+=1;

                		//Find first non trivial mother.
                		use = i;
				for (unsigned k = 0; k<30; k++){
                			m1 = pythia.event[use].mother1();
                			m2 = pythia.event[use].mother2();
                   			if (m1!=m2) break;
                			use = m1;
                		}
				if (pythia.event[i].id()==22) thereis=1;
				ultra[i][0]=pythia.event[i].px();
				ultra[i][1]=pythia.event[i].py();
				ultra[i][2]=pythia.event[i].pz();
				ultra[i][3]=pythia.event[i].e();
				ultra[i][4]=m1;
			//End If final particle.
			}
		//End i loop.
		}
		if (thereis==0) continue;
        	donantli:
		for (unsigned l = 0; l<1000; l++) {
            		for (unsigned m=0; m<1000; m++) {
                		if (ultra[m][4]==ultra[l][4] && m!=l && ultra[m][5]==0 && ultra[m][4]!=0) {
                  			counter +=1;
                   			use = int(ultra[m][4]);
                   			ultra[use][0]=ultra[m][0]+ultra[l][0];
                   			ultra[use][1]=ultra[m][1]+ultra[l][1];
                   			ultra[use][2]=ultra[m][2]+ultra[l][2];
                   			ultra[use][3]=ultra[m][3]+ultra[l][3];
                   			int early = use;
                   			for ( unsigned y = 0; y<30; y++) {
                   				m1 = pythia.event[use].mother1();
                   				m2 = pythia.event[use].mother2();
                     				if (m1!=m2) break;
                   				use = m1;
                   			}
		   			if (pythia.event[m1].status()!=-41) {
                   				ultra[early][4]=m1;
		   			}
		   			else ultra[early][4]=3;
                   			ultra[m][5]=1;
                   			ultra[l][5]=1;
                   			if (counter < finals) goto donantli;
                		}
            		 }
          	}
		ultra[3][0]=0.;
		ultra[3][1]=0.;
		ultra[3][2]=0.;
		ultra[3][3]=0.;

		//Isolation cut
		keep=0;
		for (unsigned c=3; c<1000; c++){
			if (pythia.event[ultra[c][4]].status()==-41) ultra[c][4]=3;
			if ((ultra[c][4]!=0 || c==3) && pythia.event[c].status()!=-41) {
				if (pythia.event[c].id()==22) {
					phot[b]=c;	//Keep photon labels
					b+=1;
				}
			}
		}
		for (int h=0; h<b; h++) {
			sumene=0.;
			rapphot=1./2.*log((ultra[phot[h]][2]+ultra[phot[h]][3])/(ultra[phot[h]][3]-ultra[phot[h]][2]));
			pex=ultra[phot[h]][0];
                        pey=ultra[phot[h]][1];
			pete=sqrt(pex*pex+pey*pey);
			/*for (int d=3; d<1000; d++) {
				if ((ultra[d][4]!=0) && pythia.event[d].status()!=-41 && int(ultra[d][6])==0 && d!=phot[h]) {
					tx=ultra[d][0];
					ty=ultra[d][1];
					tz=ultra[d][2];
					te=ultra[d][3];
					pex=ultra[phot[h]][0];
					pey=ultra[phot[h]][1];
					pez=ultra[phot[h]][2];
					pee=ultra[phot[h]][3];
					pete=sqrt(pex*pex+pey*pey);
					deltaphi=acos((tx*pex+ty*pey)/(sqrt(tx*tx+ty*ty)*sqrt(pex*pex+pey*pey)));
					deltarap=1./2.*(log((te+tz)/(te-tz))-log((pee+pez)/(pee-pez)));
					deltaR=sqrt(pow(deltaphi,2.)+pow(deltarap,2.));
					if (deltaR<0.3) sumene+=ultra[d][3];
				}
			}*/
			if (sumene<5. && abs(rapphot)<1.44 && pete>40.) {	//If isolated, check whether prompt
				isolated+=1.;
				keep=1;
				use=phot[h];
				for (unsigned w=0; w<50; w++) {
					mam=pythia.event[use].mother1();
					mim=pythia.event[use].mother2();
					if (mam!=mim) {
						if (pythia.event[use].status()==-23) prompt+=1.;
						break;
					}
					else use=mam;
				}
			}
		}
		for (unsigned c=3; c<1000; c++) {
			if ((ultra[c][4]!=0 || c==3) && pythia.event[c].status()!=-41) {
				ultra[c][6]=abs(sqrt(abs(pow(ultra[c][3],2.)-pow(ultra[c][0],2.)-pow(ultra[c][1],2.)-pow(ultra[c][2],2.)-pow(pythia.event[c].m(),2.)))); //Before it was Sqrt[E^2-p^2]-m !!!

				// Set Identity
				int ide=abs(pythia.event[c].id());
				if (ide >=1 && ide <=6) qg=1;
				if (ide==21) qg=2;
				if (ide==22) {
					qg=3;
				}
				// Quark or Gluon Initiated Jets
				ini=0;
				use=c;
				for (unsigned w=0; w<50; w++) {
					mam=pythia.event[use].mother1();
					if (pythia.event[mam].status()==-23) {
						ide=abs(pythia.event[mam].id());
						if (ide >=1 && ide <=6) ini=1;
						if (ide==21) ini=2;
						break;
					}
					use=mam;
				}
				//------------------------------
				if (keep==1) {
					geneal << setw(10)<< c <<  setw(10)<< ultra[c][0] <<  setw(10)<< ultra[c][1] <<  setw(10) << ultra[c][2] << setw(10) << ultra[c][3] << setw(10)<<setw(10)<<fixed << setprecision(4) << ultra[c][6] << setw(10) << int(ultra[c][4]) << setw(10) << qg << setw(10) << ini << "\n"; 
				}
        		}
		}
		if (keep==1) {
			count+=1;
			geneal << "0.000123" << " 0. " << " 0. " << " 0."<< " " << "0.00"<< count << " 0. " << "0. " << " 0. " << " 0. " << "\n" ;
		}
	// End event loop.
	} while (count<N);
	//cout << " Isolation efficiency= " << prompt << " " << isolated << "\n";
//Pthat end loop
}

geneal.close();
pythia.stat();
return 0;
//End program
}


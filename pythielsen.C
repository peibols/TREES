#include "Pythia8/Pythia.h"
#include "Pythia8/Event.h"
#include <math.h>
#include <fstream>
#include <iostream>
#include <iomanip>
using namespace std;
using namespace Pythia8;

int pythielsen() {

ofstream geneal;

geneal.open ("TREES/tree50test.txt");
Pythia pythia;
pythia.readString("Beams:idB = 2212");	//Collide protons
pythia.readString("Beams:eCM = 2760.");	//At this center of mass energy (GeV)
pythia.readString("SoftQCD:all = off");	//Turn off diffractive events
pythia.readString("HardQCD:all = on");	//Turn on hard inelastic events
pythia.readString("HadronLevel:all = off");	//Don't hadronize
pythia.readString("PartonLevel:ISR = on");	//Include Initial State Radiation
pythia.readString("PartonLevel:MPI = off");	//Consider a single hard collision per proton collision
pythia.readString("TimeShower:pTmin = 1.");	//Minimum "virtuality" required for a parton to split

int N=10;	//Number of Events
int count=0;
int finals, counter, m1, m2, use, qg, mam, ini;
//Array where first index is label, and second runs through px, py, pz, E, mom, done, virt
double ultra[1000][7];

// Pthat begin loop (obsolete, just running for a single value of pTHatMin)
for (unsigned ei = 0; ei<1; ei++) {
      if (ei==0) pythia.readString("PhaseSpace:pTHatMin = 50."); //Set minimum Pt of Hard Process
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
		//Initialize array
		for (unsigned e=0;e<1000; e++) {
			for (unsigned f=0;f<2;f++) {
				ultra[e][4+f]=0.;
			}
		}

		if (!pythia.next()) continue;
    		// Loop over final particles in event
    		for (int i = 0; i < pythia.event.size(); ++i) {
      			if (pythia.event[i].isFinal()) {
         			if (pythia.event[i].mother2() == 0) continue;	//Don't want remnants
				if (pythia.event.size()>1000) continue;
         			finals+=1;

                		//Find first non trivial mother. Not interested in carbon copies.
                		use = i;
				for (unsigned k = 0; k<30; k++){
                			m1 = pythia.event[use].mother1();
                			m2 = pythia.event[use].mother2();
                   			if (m1!=m2) break;
                			use = m1;
                		}

				//Keep 4momentum and mother of final particles
				ultra[i][0]=pythia.event[i].px();
				ultra[i][1]=pythia.event[i].py();
				ultra[i][2]=pythia.event[i].pz();
				ultra[i][3]=pythia.event[i].e();
				ultra[i][4]=m1;
			//End If final particle.
			}
		//End i loop.
		}
        	donantli:
		//Run through all possible pairs of particles trying to find matching mother. Then add 4momenta to build mother's one
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
					//Find next non trivial mother
                   			for ( unsigned y = 0; y<30; y++) {
                   				m1 = pythia.event[use].mother1();
                   				m2 = pythia.event[use].mother2();
                     				if (m1!=m2) break;
                   				use = m1;
                   			}
					//If we get to first ISR radiated particle, whose mother has status "-41", name the mother "3".
					//"3" is default mother1 of hard products, so basically having mother "3" means one is at top of family tree, where the shower starts, at t=0 and z=0
		   			if (pythia.event[m1].status()!=-41) {
                   				ultra[early][4]=m1;
		   			}
		   			else ultra[early][4]=3;
					//Set these 2 partons as "done"
                   			ultra[m][5]=1;
                   			ultra[l][5]=1;
					//If there have been less splittings than # of final particles (which is always true...) start the double loop again. We are out of the loops when the "if" condition in line 90 is not met
                   			if (counter < finals) goto donantli;
                		}
            		}
          	}
		ultra[3][0]=0.;
		ultra[3][1]=0.;
		ultra[3][2]=0.;
		ultra[3][3]=0.;
		//Loop over all final and reconstructed particles to write their properties on output file "geneal"
		for (unsigned c=3; c<1000; c++) {
			if (pythia.event[ultra[c][4]].status()==-41) ultra[c][4]=3; //This is for ISR particles which never splitted. They were not treated in previous loop. So, if someone's mother status is "-41", it means it's a first ISR particle, name mother "3"
			if ((ultra[c][4]!=0 || c==3) && pythia.event[c].status()!=-41) {
				ultra[c][6]=abs(sqrt(abs(pow(ultra[c][3],2.)-pow(ultra[c][0],2.)-pow(ultra[c][1],2.)-pow(ultra[c][2],2.)-pow(pythia.event[c].m(),2.)))); //Calculate particle's virtuality Q. Final particles have Q=0

				// Set Quark (1) or Gluon (2) or Photon(3) label
				int ide=abs(pythia.event[c].id());
				if (ide >=1 && ide <=6) qg=1;
				if (ide==21) qg=2;
				if (ide==22) {
					qg=3;
				}
				// Set another label to Quark or Gluon Initiated Jets (can be inferred from familiy tree, but this is a shortcut for future purposes)
				ini=0; //ini=0 put by default, so that if condition of belonging to hard process below not met, one concludes it was ISR
				use=c;
				for (unsigned w=0; w<50; w++) {
					mam=pythia.event[use].mother1();
					if (pythia.event[mam].status()==-23) {	//If first mother is outcome of 2->2 hard process
						ide=abs(pythia.event[mam].id());
						if (ide >=1 && ide <=6) ini=1; //Comes from Quark (of hard process)
						if (ide==21) ini=2;	//Comes from Gluon (of hard process)
						break;
					}
					use=mam;
				}
				//Write "label", "Px", "Py", "Pz", "E", "Q (virtuality)", "mom's label", "quark or gluon label", "quark or gluon initiated jet label"
				geneal << setw(10) << c << setw(10) << ultra[c][0] <<  setw(10)<< ultra[c][1] <<  setw(10) << ultra[c][2] << setw(10) << ultra[c][3] << setw(10) << fixed << setprecision(4) << ultra[c][6] << setw(10) << int(ultra[c][4]) << setw(10) << qg << setw(10) << ini << "\n";
        		}
		}
		//Used to know that event ended
		geneal << "0.000123" << " 0. " << " 0. " << " 0. " << "0.00" << count << " 0. " << " 0. " << " 0. " << " 0. " << "\n" ;
		count+=1;
	// End event loop.
	} while (count<N);
//Pthat end loop
}

geneal.close();
pythia.stat();
return 0;
//End program
}


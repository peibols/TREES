// HYDRO QUENCHING

#include <iostream>
#include <fstream>
#include <iomanip>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

using namespace std;
int ir=1349;
double TA[4000], step, bmin, bmax;
double norm=1.;
double eta, etah;
double tau0, deltat, deltax, deltay;
int maxt, maxx, maxy, it, ix, iy;
double hydrot[180][101][101], hydroe[180][101][101], hydrox[180][101][101], hydroy[180][101][101];
double dt, dx, dy;
double PrNn=0.;
double rando(int*);
double gTAA(double, double, double);
double gWN(double, double, double);
double gT(double, double, double);
double gVy(double, double, double);
double gVx(double, double, double);
double gE(double, double, double);
double getGrid(double, double, double, double *, double *, double *, int *, int *, int *);
double alpha=0.8;
double tquench=0.6;
double Qnot=1.;
int qmethod=6; //1 Coll, 5 Radiative, 6 Strong, 7 OldStrong
int tmethod=0;
int main () {
	int N=500000;
	int Cent=0;
	ofstream check;
	check.open ("/home/peibols/NewHD/UliInv/Strong276/overq1A.txt");
	ofstream lamb;
	lamb.open ("MISC/0095L2Dlamb.txt");
	ofstream debug;
	debug.open ("MISC/bdist.txt");
	ofstream temp1;
	ofstream temp2;
	temp1.open ("MISCu/TempEta2.txt");
	temp2.open ("ULI/Tempx3m3.txt");

	double P[1000][9], id, px, py, pz, E, q, mom, qge, ini;
	double x,y,z,b;
	double gxy(double*, double*, double*);
	double gdE(double, double, double, double, double, double *, double *, double *, double, double, double *, double *, double *);
	int count=0;
	double ene=5.;
	double r=0.;
	double nr=0.;
/*c...Centrality in HIRANO HYDRO
c...LHC PbPb 2.76TeV
         b=3.3d0
         cent='0-10'
c         b=6.0d0
c         cent='10-20'
c         b=7.7d0
c         cent='20-30'
c         b=9.2d0
c         cent='30-40'
c         b=10.4d0
c         cent='40-50'
c         b=11.5d0
c         cent='50-60'
c         b=12.5d0
c         cent='60-70'
c         b=13.4d0
c         cent='70-80'

c...RHIC
c         b=2.0d0    ![fm] 0- 5%
c         cent='0-5'
c         b=3.2d0    ![fm] 0-10%
c         cent='0-10'
c         b=5.5d0    ![fm]10-20%
c         cent='10-20'
c         b=7.2d0    ![fm]20-30%
c         cent='20-30'
c         b=8.5d0    ![fm]30-40%
c         cent='30-40'
c         b=10.5d0    ![fm]40-60%
c         cent='40-60'
c         b=12.0d0   ![fm]60-80%
c         cent='60-80'*/
	ifstream infile3;
	if (Cent==0) {		//0-5%
		bmin=0.;
		bmax=3.5;
		infile3.open ("PhotJet/To_MIT/hydro_evo_converted/hydroinfoPlaintxtHuichaoFormat_C0-5.dat");
	}
	if (Cent==1) {		//5-10%
		bmin=3.5;
		bmax=4.94;
		infile3.open ("PhotJet/To_MIT/hydro_evo_converted/hydroinfoPlaintxtHuichaoFormat_C5-10.dat");
	}
	if (Cent==2) {		//10-20%
		bmin=4.94;
		bmax=6.98;
		infile3.open ("PhotJet/To_MIT/hydro_evo_converted/hydroinfoPlaintxtHuichaoFormat_C10-20.dat");
	}
	if (Cent==3) {		//20-30%
		bmin=6.98;
		bmax=8.55;
		infile3.open ("PhotJet/To_MIT/hydro_evo_converted/hydroinfoPlaintxtHuichaoFormat_C20-30.dat");
	}
	if (Cent==4) {		//30-40%
		bmin=8.55;
		bmax=9.88;
		infile3.open ("PhotJet/To_MIT/hydro_evo_converted/hydroinfoPlaintxtHuichaoFormat_C30-40.dat");
	}
	if (Cent==5) {		//40-50%
		bmin=9.88;
		bmax=11.04;
		infile3.open ("PhotJet/To_MIT/hydro_evo_converted/hydroinfoPlaintxtHuichaoFormat_C40-50.dat");
	}
	if (Cent==6) {		//50-60%
		bmin=11.04;
		bmax=12.09;
		infile3.open ("PhotJet/To_MIT/hydro_evo_converted/hydroinfoPlaintxtHuichaoFormat_C50-60.dat");
	}
	if (Cent==7) {		//60-70%
		bmin=12.09;
		bmax=13.05;
		infile3.open ("PhotJet/To_MIT/hydro_evo_converted/hydroinfoPlaintxtHuichaoFormat_C60-70.dat");
	}

	//Input Files
	std::ifstream infile1("TREES/tree50BIG.txt");
	std::ifstream infile2("TAb2LL.dat");

	//Reading T(t)
	double b2;
	for (unsigned a=0; a<4000; a++) {
		infile2 >> b2 >> TA[a];
		if (a == 1) step = b2;
	}

	//Reading HydroTemp
	double enedat, tdat, vxdat, vydat;
	double tou, hor, ver;
	maxt=179;
	maxx=100;
	maxy=100;
	tau0=0.6;
	deltat=0.1;
	deltax=0.3;
	deltay=0.3;
	/*for (int aa=0; aa<maxt+1; aa++) {
		for (int bb=0; bb<maxx+1; b++) {
			for (int cc=0; cc<maxy+1; cc++) {
				for (int dd=0; dd<maxh+1; dd++) {
					hydrot[aa][bb][cc][dd]=0.;
				}
			}
		}
	}*/
	double hormax=0.;
	double vermax=0.;
	double toumax=0.;
	tou=0.6;
	cout << " ELOUUU ";
	while (infile3 >> hor >> ver >> tou >> enedat >> tdat >> vxdat >> vydat)
		{
		if (fabs(hor)>hormax) hormax=fabs(hor);
		if (fabs(ver)>vermax) vermax=fabs(ver);
		if (fabs(tou)>toumax) toumax=fabs(tou);
		//if (ver==0.) cout << " ver= " << ver << "\n";
		it = int((tou+deltat/2.-tau0)/deltat);
          	ix = int((hor+deltax*maxx/2.+deltax/2.)/deltax);
           	iy = int((ver+deltay*maxy/2.+deltay/2.)/deltay);

		hydrot[it][ix][iy]=tdat;
		hydroe[it][ix][iy]=enedat;
		hydrox[it][ix][iy]=vxdat;
		hydroy[it][ix][iy]=vydat;
	}
	cout << " Xmax= " << hormax << " Ymax= " << vermax << " Taumax= " << toumax << "\n";

	//Calculating PrNn
	double Nnucleons=208.;
	double sigmann=7.2;
	for (unsigned i=0; i<4000; i++) {
		PrNn=PrNn+TA[i]*step;
	}
	PrNn=Nnucleons/3.1416/PrNn;
	PrNn=sigmann*PrNn;

	//Lambda Initialization
	double lambder[101];
	double nlamb=0.;
	for (unsigned e=0; e<101; e++) {
		lambder[e]=0.;
	}

	//Debug stuff
	double deb[101];
	for (unsigned a=0; a<101; a++) {
		deb[a]=0.;
	}

	int event=0;
	clock_t startClock = clock();
	//Event Loop
	do {
		//Getting initial x, y and b
		gxy(&x,&y,&b);
		//cout << " X= " << x << " Y= " << y << " B= " << b << "\n";
		double xcre=x;
		double ycre=y;
		r+=sqrt(xcre*xcre+ycre*ycre);
		nr+=1.;

		//DEBUG
		//xcre=0.;
		//ycre=0.;

		//Getting tree info
		int k=0;
		int FinId[500];
		for (unsigned a=0; a<1000; a++) {
			P[a][0]=0.;
			P[a][1]=0.;
			P[a][2]=0.;
			P[a][3]=0.;
			P[a][4]=0.;
			P[a][5]=0.;
			P[a][6]=0.;
			P[a][7]=0.;
			P[a][8]=0.;
		}
		while (infile1 >> id >> px >> py >> pz >> E >> q >> mom >> qge >> ini)
		{
			if (id!=0.000123) {
				P[int(id)][0]=px;
				P[int(id)][1]=py;
				P[int(id)][2]=pz;
				P[int(id)][3]=E;
				P[int(id)][4]=q;	//Virtuality
				P[int(id)][5]=mom;
				P[int(id)][6]=qge;	//Quark or Gluon
				P[int(id)][7]=ini;
				if (int(q+0.9)==0 && E!=0. && mom!=0.) {
					FinId[k]=int(id);
					k+=1;
				}
			}
			else {
				event+=1;
				break;
			}
		}
		int fam[30];
		double  Q[1000][8];
		//Energy Loss Loop
		for (int cr=0; cr<k; cr++) {
			int ind=FinId[cr];
			int fr=0;
			double frac;
			double acum;
			int mymomisko=0;
			fam[fr]=ind;
			for (unsigned a=0; a<50; a++) {
				int mom=int(P[ind][5]);
				if (P[mom][8]==1. && mom!=3) {
					frac=Q[mom][3]/P[mom][3];
					Q[ind][0]=P[ind][0]*frac;
					Q[ind][1]=P[ind][1]*frac;
					Q[ind][2]=P[ind][2]*frac;
					Q[ind][3]=P[ind][3]*frac;
					if (Q[mom][3]==0.) mymomisko=1;
					x=Q[mom][4];		// X
					y=Q[mom][5];		// Y
					z=Q[mom][6];		// Z
					acum=Q[mom][7];		// t
					break;
				}
				if (mom==3) {
					Q[ind][0]=P[ind][0];
					Q[ind][1]=P[ind][1];
					Q[ind][2]=P[ind][2];
					Q[ind][3]=P[ind][3];
					x=xcre;
					y=ycre;
					z=0.;
					acum=0.;
					break;
				}
				if (P[mom][8]==0.) {
					fr+=1;
					fam[fr]=mom;
					ind=mom;
				}
			}
			for (int w=fr; w>-1; w--) {
				if (mymomisko==1) {
					for (int ku=w; ku>-1; ku--) {
                                                Q[fam[ku]][3]=0.;
                                                P[fam[ku]][8]=1.;
                                        }
                                        break;
				}
				double pexe=Q[fam[w]][0];
				double peye=Q[fam[w]][1];
				double peze=Q[fam[w]][2];
				double we=Q[fam[w]][3];
				//if (fam[w]==43) cout << " EnerNow= " << we << " EnerPYT= " << P[fam[w]][3] << " PxNow= " << pexe << " or PxNowQ= " << Q[fam[w]][0] << " PxPYT= " << P[fam[w]][0] << " PzPYT= " << P[fam[w]][2] << " PzNow= " << peze << " or PzNowQ= " << Q[fam[w]][2] << " PyPYT= " << P[fam[w]][1] << " PyNow= " << peye << " or PyNowQ= " << Q[fam[w]][1] << "\n";
				double previous=acum;
				double tauf=0.2*2.*P[fam[w]][3]/max(pow(P[fam[w]][4],2.),Qnot*Qnot);
				if (fam[w]==FinId[cr]) tauf=10000.;
				acum=previous+tauf;
				double phi=atan2(peye,pexe);
				double dE=gdE(we,P[fam[w]][6],P[fam[w]][4],acum-previous,previous,&x,&y,&z,phi,b,&pexe,&peye,&peze);	//MUST make momenta a pointer too
				if (int(P[fam[w]][6])==3 || int(P[fam[w]][6])==4) {
					dE=0.;
				}
				if (we-dE<=0.)  {
					for (int ko=w; ko>-1; ko--) {
						Q[fam[ko]][3]=0.;
						P[fam[ko]][8]=1.;
					}
					break;
				}
				double ptx=pexe-Q[fam[w]][0];
				double pty=peye-Q[fam[w]][1];
				double ptz=peze-Q[fam[w]][2];
				if (ptx!=0.) cout << " Pttenemoos = " << ptx << " ";
				Q[fam[w]][0]=pexe*(we-dE)/we;
				Q[fam[w]][1]=peye*(we-dE)/we;
				Q[fam[w]][2]=peze*(we-dE)/we;
				Q[fam[w]][3]=we-dE;
				Q[fam[w]][4]=x;
				Q[fam[w]][5]=y;
				Q[fam[w]][6]=z;
				Q[fam[w]][7]=acum;
				P[fam[w]][8]=1.;
				if (fam[w]!=FinId[cr]) {
					//cout << " NOTFINAL-> EnerPYTHIA= " << P[fam[w]][3] << " EnerQUEN= " << Q[fam[w]][3] << "\n";
					frac=P[fam[w-1]][3]/P[fam[w]][3];
					Q[fam[w-1]][0]=P[fam[w-1]][0]*Q[fam[w]][3]/P[fam[w]][3]+frac*ptx;
					Q[fam[w-1]][1]=P[fam[w-1]][1]*Q[fam[w]][3]/P[fam[w]][3]+frac*pty;
					Q[fam[w-1]][2]=P[fam[w-1]][2]*Q[fam[w]][3]/P[fam[w]][3]+frac*ptz;
					Q[fam[w-1]][3]=P[fam[w-1]][3]*Q[fam[w]][3]/P[fam[w]][3];
					Q[fam[w-1]][4]=x;
					Q[fam[w-1]][5]=y;
					Q[fam[w-1]][6]=z;
					Q[fam[w-1]][7]=acum;
					//cout << P[fam[w]][0] << setw(15) << P[fam[w]][1] << setw(15) << P[fam[w]][2] << setw(15) << P[fam[w]][3]  << setw(15) << Q[fam[w]][0] << setw(15) << Q[fam[w]][1] << setw(15) << Q[fam[w]][2] << setw(15) << Q[fam[w]][3] << "\n";
				}
			}
			//cout << P[fam[0]][0] << fixed << setprecision(5) << setw(15) << P[fam[0]][1] << setw(15) << P[fam[0]][2] << setw(15) << P[fam[0]][3]  << setw(15) << Q[fam[0]][0] << setw(15) << Q[fam[0]][1] << setw(15) << Q[fam[0]][2] << setw(15) << Q[fam[0]][3] << setw(5) << int(P[fam[0]][6]) << setw(5) << int(P[fam[0]][7]) << "\n";
			check << P[fam[0]][0] << fixed << setprecision(5) << setw(15) << P[fam[0]][1] << setw(15) << P[fam[0]][2] << setw(15) << P[fam[0]][3]  << setw(15) << Q[fam[0]][0] << setw(15) << Q[fam[0]][1] << setw(15) << Q[fam[0]][2] << setw(15) << Q[fam[0]][3] << setw(15) << int(P[fam[0]][6]) << setw(15) << int(P[fam[0]][7]) << setw(15) << "\n";
			//cout << " EnerPYTHIA= " << P[fam[0]][3] << " EnerQUEN= " << Q[fam[0]][3] << "\n";
		}


		count +=1;
		//cout << " NEXT EVENT  \n";
		int mult=int(double(count)/(ene*100.));
		if (mult>0) {
			cout << " " << count << "\n";
			ene+=5.;
		}

		check << "0.000123" << fixed << setprecision(5) << setw(15) << " 0. " << setw(15) << " 0. " << setw(15) << xcre << setw(15) << ycre << setw(15) << b << setw(15) << " 0. "  << setw(15) << " 0. " << setw(15) << count  << setw(15) << " 0. " << "\n";
	//End Event Loop
	} while (count < N);
	clock_t endClock = clock();
	cout << " Time= ";
	printf("%ld", (endClock - startClock) / CLOCKS_PER_SEC);
	cout << " #Events= " << event << " ";
	//cout << " Mean r_new= " << r/nr << "\n";

	//HISTOS
	//Lambda
	for (unsigned e=0; e<101; e++) {
		lamb << double(e)/100. << " " << lambder[e]/nlamb << "\n";
	}

	//Debug
	for (unsigned e=0; e<101; e++) {
		debug << double(e)/3.8 << " " << deb[e] << "\n";
	}

	//Temp DEBUG
	for (unsigned a=0; a<120; a++) {
		temp2 << 0.6+double(a)*17./120. << " " << gT(3.,0.6+double(a)*17./120.,-3.) << "\n";
	}

debug.close();
lamb.close();
temp1.close();
temp2.close();
infile3.close();
//End Program
}
//------------------gdE-----------------------------//
double gdE(double E, double M, double gamma, double t, double t0, double *x, double *y, double *z, double phi, double p, double *pexe, double *peye, double *peze) {

	double ti, tih, tot;
	double proper, properh;
	double xp, yp, zp;
	double xph, yph, zph;
	double Temp, Temph;
	double Ev, CF;
	double Tc;
	if (tmethod==0) Tc=170./1000.;
	if (tmethod==1) Tc=145./1000.;
	if (tmethod==2) Tc=180./1000.;
	double integral=0.;
	double stepe=0.01;
	double wx, wy, wz;
	double vx, vy, vz;
	double lore, vscalw, v2;
	int marker=0;
	double i=0.;
	double gede=0.;
	double dist=0.;
	double distlab=0.;
	if (int(M)==1) CF=1.;
	if (int(M)==2) {
		if (qmethod==0 || qmethod==1 || qmethod==5) CF=pow(9./4.,1.);
		if (qmethod==2 || qmethod==3 || qmethod==4 || qmethod==6 || qmethod==7) CF=pow(9./4.,1./3.);
	}
	Ev=E;
	tot=t0+t;
	int said=0;
	//cout << "\n New Rung--- Ei= " << E << "\n";
	//cout << " gamma= " << gamma << "\n";
	//cout << " xini= " << *x << " yini= "<< *y << " zini= " << *z << " tauini= " << sqrt(t0*t0-pow(*z,2.))<< "\n";
	do {
		ti=t0+i*stepe;
		tih=ti+stepe;
		if (tih>tot) {
			marker=1;
			tih=tot;
			stepe=tih-ti;
		}
		wx=*pexe/E;
		wy=*peye/E;
		wz=*peze/E;

		xp=*x;
		yp=*y;
		zp=*z;
		proper=sqrt(ti*ti-zp*zp);
		eta=1./2.*log((ti+zp)/(ti-zp));

		xph=*x+wx*stepe;
                yph=*y+wy*stepe;
                zph=*z+wz*stepe;
                properh=sqrt(tih*tih-zph*zph);
                etah=1./2.*log((tih+zph)/(tih-zph));

                *x=xph;
                *y=yph;
                *z=zph;

		if (proper!=proper || properh!=properh || ti-zp<0. || tih-zph<0. || ti+zp<0. || tih+zph<0. ) {
			cout << " Proper= " << proper << " Properh= " << properh << " ti-zp= " << ti-zp << " tih-zph= " << tih-zph << " ti+zp= " << ti+zp << " tih+zph= " << tih+zph << "\n";
		}
                if (proper!=proper) proper=0.;
                if (properh!=properh) properh=0.;
		if (ti-zp<0.) eta=12.;
		if (tih-zph<0.) etah=12.;
		if (ti+zp<0.) eta=-12.;
		if (tih+zph<0.) etah=-12.;
		if ((proper+properh)/2.>=tquench) {
			//extract fluid velocity with LAB coordinates
			vx=gVx(proper,xp,yp);
			vy=gVy(proper,xp,yp);
			double frap=0.;
			vz=*z/tih;
			frap=atanh(vz);
			vx/=cosh(frap);
			vy/=cosh(frap);
			v2=pow(vx,2.)+pow(vy,2.)+pow(vz,2.);
			vscalw=vx*wx+vy*wy+vz*wz;
			if (v2>=1.) v2=0.9999999;
			lore=1./sqrt(1.-v2);
			double infi=stepe*sqrt(wx*wx+wy*wy+wz*wz+lore*lore*(v2-2.*vscalw+vscalw*vscalw));
			if (infi!=infi) infi=0.;
			dist+=infi;
			distlab+=stepe;
			Temp=gT(proper,xp,yp);
			Temph=gT(properh,xph,yph);
			if (said==0) {
				//cout << " Vx= " << vx << " Vy= " << vy << " Vz= " << vz << "\n";
				//cout << " Temp ini= " << (Temp+Temph)/2. << "\n";
				said=1;
			}
			if (Temph<Tc) {
				double cospart=xph*wx+yph*wy;
				if (cospart>0.) {
					Temp=0.;
					Temph=0.;
					*x=xph+wx*(tot-tih);
					*y=yph+wy*(tot-tih);
					*z=zph+wz*(tot-tih);
				}
			}
			if (Temph==0.) marker=1;
			if (Ev<=0.) marker=1;
		}
		if (Ev>0.) {
			if ((proper+properh)/2.>=tquench && Temp/2.+Temph/2.>Tc+0.00000001) {
				//Coll
				if (qmethod==1) {
					integral+=alpha*CF*stepe*5.*pow((Temp+Temph)/2.,2.);
					Ev=E-integral;
					if (Ev<0.) Ev=0.;
				}
				//Radiative
				if (qmethod==5) {
					integral+=5.*alpha*CF*stepe*dist*5.*pow((Temp+Temph)/2.,3.);
					Ev=E-integral;
					if (Ev<0.) Ev=0.;
				}
				double Ef, tstop, beta;
				//Strong
				if (qmethod==6) {
					Ef=E*lore*(1.-vscalw);
					tstop=0.2*pow(Ef,1./3.)/(2.*pow((Temp+Temph)/2.,4./3.)*alpha)/CF;
					beta=tstop/dist;
					if (beta>1.) {
						integral+=Ef*stepe*4./(3.141592)*(1./(beta*tstop*sqrt(beta*beta-1.)));
						Ev=E-integral;
					}
					else Ev=0.;
					if (Ev<0.) Ev=0.;
				}
				//OldStrong
				/*if (qmethod==7) {
					Ef=E*lore*(1.-vscalw);
					tstop=0.2*pow(Ef,1./3.)/(2.*pow((Temp+Temph)/2.,4./3.)*alpha)/CF;
					beta=tstop/dist;
					if (beta>1.) {
						integral+=Ef*stepe*4./(3.141592)*(1./(beta*tstop*sqrt(beta*beta-1.)));
						Ev=E-integral;
					}
					else Ev=0.;
					if (Ev<0.) Ev=0.;
				}*/
			}
		}
		else {
			gede=E;
			Ev=0.;
		}
		i+=1.;
	} while (marker!=1);
	//cout << " xfin= " << *x << " yfin= " << *y << " zfin= " << *z <<" Temp fin= " << (Temp+Temph)/2. << "\n";
	gede=E-Ev;
	//cout << " DistLab= " << distlab << " DistFluid= " << dist << "\n";
	//cout << " dE= " << gede << " ";
	return gede;
}
//------------------getGrid-------------------------//
double getGrid(double tau, double x, double y, double *dt, double *dx, double *dy, int *it, int *ix, int *iy) {

	*it=int((tau-tau0)/deltat);
	*dt=(tau-tau0-double(*it)*deltat)/deltat;

	if (y>0.) {
		*iy = int(y/deltay)+maxy/2;
		*dy = (y - double(*iy-maxy/2.)*deltay)/deltay;
	}
	else {
		*iy = int(y/deltay)+maxy/2-1;
		*dy = (y - double(*iy-maxy/2.)*deltay)/deltay;
	}

	if (x>0.) {
		*ix = int(x/deltax)+maxx/2;
		*dx = (x - double(*ix-maxx/2.)*deltax)/deltax;
	}
	else {
		*ix = int(x/deltax)+maxx/2-1;
		*dx = (x - double(*ix-maxx/2.)*deltax)/deltax;
	}

	return 0;
}

//------------------gT------------------------------//
double gT(double tau, double x, double y) {

	double gete=0.;
	double tau1=18.5;

	if (tau>tau1) {
		//cout << " No data for tau > " << tau1 << " fm ";
		return gete;
	}

	getGrid(tau,x,y,&dt,&dx,&dy,&it,&ix,&iy);
	//cout << " " << dt << " " << dx << " " << dy << " " << dh << " " << it << " " << ix << " " << iy << " " << ih << "\n";
	if (ix<0 || ix>maxx || iy<0 || iy>maxy) return gete;
	gete=hydrot[it][ix][iy]*(1.-dt)*(1.-dx)*(1.-dy);
	gete+=hydrot[it+1][ix][iy]*(1.-dx)*(1.-dy)*dt;
	gete+=hydrot[it][ix+1][iy]*(1.-dt)*(1.-dy)*dx;
	gete+=hydrot[it][ix][iy+1]*(1.-dx)*(1.-dt)*dy;
	gete+=hydrot[it+1][ix+1][iy]*dx*(1.-dy)*dt;
	gete+=hydrot[it][ix+1][iy+1]*(1.-dt)*dy*dx;
	gete+=hydrot[it+1][ix][iy+1]*(1.-dx)*dt*dy;
	gete+=hydrot[it+1][ix+1][iy+1]*dx*dt*dy;

	return gete*0.2;
}

//------------------gE------------------------------//
double gE(double tau, double x, double y) {

	double gener=0.;
	double tau1=18.5;

	if (tau>tau1) {
		//cout << " No data for tau > " << tau1 << " fm ";
		return gener;
	}

	getGrid(tau,x,y,&dt,&dx,&dy,&it,&ix,&iy);
	//cout << " " << dt << " " << dx << " " << dy << " " << dh << " " << it << " " << ix << " " << iy << " " << ih << "\n";
	if (ix<0 || ix>maxx || iy<0 || iy>maxy) return gener;
	gener=hydroe[it][ix][iy]*(1.-dt)*(1.-dx)*(1.-dy);
	gener+=hydroe[it+1][ix][iy]*(1.-dx)*(1.-dy)*dt;
	gener+=hydroe[it][ix+1][iy]*(1.-dt)*(1.-dy)*dx;
	gener+=hydroe[it][ix][iy+1]*(1.-dx)*(1.-dt)*dy;
	gener+=hydroe[it+1][ix+1][iy]*dx*(1.-dy)*dt;
	gener+=hydroe[it][ix+1][iy+1]*(1.-dt)*dy*dx;
	gener+=hydroe[it+1][ix][iy+1]*(1.-dx)*dt*dy;
	gener+=hydroe[it+1][ix+1][iy+1]*dx*dt*dy;

	return gener;
}

//------------------gVx------------------------------//
double gVx(double tau, double x, double y) {

        double gvelx=0.;
        double tau1=18.5;

        if (tau>tau1) {
                //cout << " No data for tau > " << tau1 << " fm ";
                return gvelx;
        }

        getGrid(tau,x,y,&dt,&dx,&dy,&it,&ix,&iy);
	//cout << " " << dt << " " << dx << " " << dy << " " << dh << " " << it << " " << ix << " " << iy << " " << ih << "\n";
	if (ix<0 || ix>maxx || iy<0 || iy>maxy) return gvelx;
	gvelx=hydrox[it][ix][iy]*(1.-dt)*(1.-dx)*(1.-dy);
	gvelx+=hydrox[it+1][ix][iy]*(1.-dx)*(1.-dy)*dt;
	gvelx+=hydrox[it][ix+1][iy]*(1.-dt)*(1.-dy)*dx;
	gvelx+=hydrox[it][ix][iy+1]*(1.-dx)*(1.-dt)*dy;
	gvelx+=hydrox[it+1][ix+1][iy]*dx*(1.-dy)*dt;
	gvelx+=hydrox[it][ix+1][iy+1]*(1.-dt)*dy*dx;
	gvelx+=hydrox[it+1][ix][iy+1]*(1.-dx)*dt*dy;
	gvelx+=hydrox[it+1][ix+1][iy+1]*dx*dt*dy;

        return gvelx;
}

//------------------gVy------------------------------//
double gVy(double tau, double x, double y) {

        double gvely=0.;
        double tau1=18.5;

        if (tau>tau1) {
                //cout << " No data for tau > " << tau1 << " fm ";
                return gvely;
        }

        getGrid(tau,x,y,&dt,&dx,&dy,&it,&ix,&iy);
	//cout << " " << dt << " " << dx << " " << dy << " " << dh << " " << it << " " << ix << " " << iy << " " << ih << "\n";
	if (ix<0 || ix>maxx || iy<0 || iy>maxy) return gvely;
	gvely=hydroy[it][ix][iy]*(1.-dt)*(1.-dx)*(1.-dy);
	gvely+=hydroy[it+1][ix][iy]*(1.-dx)*(1.-dy)*dt;
	gvely+=hydroy[it][ix+1][iy]*(1.-dt)*(1.-dy)*dx;
	gvely+=hydroy[it][ix][iy+1]*(1.-dx)*(1.-dt)*dy;
	gvely+=hydroy[it+1][ix+1][iy]*dx*(1.-dy)*dt;
	gvely+=hydroy[it][ix+1][iy+1]*(1.-dt)*dy*dx;
	gvely+=hydroy[it+1][ix][iy+1]*(1.-dx)*dt*dy;
	gvely+=hydroy[it+1][ix+1][iy+1]*dx*dt*dy;

        return gvely;
}

//------------------gWN-----------------------------//
double gWN(double x, double y, double b) {

	double rho2;
	int il, irr;
	rho2=pow(x+b/2.,2.)+y*y;
	il=rho2/step;
	rho2=pow(x-b/2.,2.)+y*y;
	irr=rho2/step;
	double gewn=0.;
	if (il<4000 && irr<4000) {
		gewn=TA[il]*(1.-exp(-PrNn*TA[irr]));
		gewn+=TA[irr]*(1.-exp(-PrNn*TA[il]));
	}
	gewn/=2.;
	return gewn;
}

//------------------gxy-----------------------------//
double gxy(double *x, double *y, double *b) {

	double rho,phi;
	double P;

        naiguels:
	*b=sqrt((bmax*bmax-bmin*bmin)*rando(&ir)+bmin*bmin);
        norm=1.;
        norm=gTAA(0.,0.,bmin);
	rho=sqrt(150.*rando(&ir));
	phi=2.*3.141592654*rando(&ir);
	*x=rho*cos(phi);
	*y=rho*sin(phi);
	P=rando(&ir);
	if(P>gTAA(*x,*y,*b)) goto naiguels;
	return 0;
}

//-----------------gTAA------------------------------//
double gTAA(double x, double y, double b)
{
	int il, irr;
	double rho2, use;

	rho2=pow(x+b/2.,2.)+y*y;
	il=int(rho2/step);
	rho2=pow(x-b/2.,2.)+y*y;
	irr=int(rho2/step);
	use=0.;
	if(il<4000 && irr<4000) {
		use=TA[il]*TA[irr]/norm;
	}
	return use;
}

//--------------Random Number-----------------------//
double rando (int *ir)
{
	double da=16807.;
	double db=2147483647.;
	double dc=2147483648.;
	double usran;

	*ir=abs(fmod(da*(*ir),db)+0.5);
	usran=double(*ir)/dc;
	return usran;
} 

#include <iostream>
#include <fstream>
#include <iomanip>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

using namespace std;

int main () {

        ofstream builtscale;
        builtscale.open ("Escale05.txt");
	ofstream builtmap;
        builtmap.open ("Map05.txt");
	std::ifstream infile1("Piece0/Escale05.txt");
	std::ifstream infile2("Piece1/Escale05.txt");
	std::ifstream infile3("Piece2/Escale05.txt");
	std::ifstream infile4("Piece3/Escale05.txt");
	std::ifstream infile5("Piece4/Escale05.txt");
	std::ifstream infile6("Piece5/Escale05.txt");
	std::ifstream infile7("Piece6/Escale05.txt");
	std::ifstream infile8("Piece7/Escale05.txt");
	std::ifstream infile9("Piece0/Map05.txt");
        std::ifstream infile10("Piece1/Map05.txt");
        std::ifstream infile11("Piece2/Map05.txt");
        std::ifstream infile12("Piece3/Map05.txt");
        std::ifstream infile13("Piece4/Map05.txt");
        std::ifstream infile14("Piece5/Map05.txt");
        std::ifstream infile15("Piece6/Map05.txt");
        std::ifstream infile16("Piece7/Map05.txt");

	double a, b, btwo, nb, m, mtwo, nm;
        int bin=0;
        int N=57;
        do {
		double escale=0.;
		double escaletwo=0.;
		double nscale=0.;
		double map=0.;
		double maptwo=0.;
		double nmap=0.;

		infile1 >> a >> b >> btwo >> nb;
		infile9 >> a >> m >> mtwo >> nm;
		escale+=b;
		escaletwo+=btwo;
		nscale+=nb;
		map+=m;
		maptwo+=mtwo;
		nmap+=nm;

		infile2 >> a >> b >> btwo >> nb;
                infile10 >> a >> m >> mtwo >> nm;
                escale+=b;
                escaletwo+=btwo;
                nscale+=nb;
                map+=m;
                maptwo+=mtwo;
                nmap+=nm;

		infile3 >> a >> b >> btwo >> nb;
                infile11 >> a >> m >> mtwo >> nm;
                escale+=b;
                escaletwo+=btwo;
                nscale+=nb;
                map+=m;
                maptwo+=mtwo;
                nmap+=nm;

		infile4 >> a >> b >> btwo >> nb;
                infile12 >> a >> m >> mtwo >> nm;
                escale+=b;
                escaletwo+=btwo;
                nscale+=nb;
                map+=m;
                maptwo+=mtwo;
                nmap+=nm;

		infile5 >> a >> b >> btwo >> nb;
                infile13 >> a >> m >> mtwo >> nm;
                escale+=b;
                escaletwo+=btwo;
                nscale+=nb;
                map+=m;
                maptwo+=mtwo;
                nmap+=nm;

		infile6 >> a >> b >> btwo >> nb;
                infile14 >> a >> m >> mtwo >> nm;
                escale+=b;
                escaletwo+=btwo;
                nscale+=nb;
                map+=m;
                maptwo+=mtwo;
                nmap+=nm;

		infile7 >> a >> b >> btwo >> nb;
                infile15 >> a >> m >> mtwo >> nm;
                escale+=b;
                escaletwo+=btwo;
                nscale+=nb;
                map+=m;
                maptwo+=mtwo;
                nmap+=nm;

		infile8 >> a >> b >> btwo >> nb;
                infile16 >> a >> m >> mtwo >> nm;
                escale+=b;
                escaletwo+=btwo;
                nscale+=nb;
                map+=m;
                maptwo+=mtwo;
                nmap+=nm;

		double scalerr=sqrt(escaletwo+nscale*pow(escale/nscale,2.)-2.*escale/nscale*escale)/sqrt(nscale*nscale-nscale);
                builtscale << a << " " << escale/nscale << " " << scalerr << "\n";
		scalerr=sqrt(maptwo+nmap*pow(map/nmap,2.)-2.*map/nmap*map)/sqrt(nmap*nmap-nmap);
                builtmap << a << " " << map/nmap << " " << scalerr << "\n";

                bin+=1;
        } while (bin<N);

builtscale.close();
builtmap.close();
//End Program
}


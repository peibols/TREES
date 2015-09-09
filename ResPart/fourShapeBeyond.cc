#include <iostream>
#include <fstream>
#include <iomanip>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

using namespace std;

int main () {

        ofstream built;
        built.open ("BRO5/ShapesBeyond03");
        std::ifstream infile1("BRO5/1centA/ShapesBeyond03.txt");
        std::ifstream infile2("BRO5/2centA/ShapesBeyond03.txt");
        std::ifstream infile3("BRO5/3centA/ShapesBeyond03.txt");
        std::ifstream infile4("BRO5/4centA/ShapesBeyond03.txt");
        std::ifstream infile5("BRO5/1centB/ShapesBeyond03.txt");
        std::ifstream infile6("BRO5/2centB/ShapesBeyond03.txt");
        std::ifstream infile7("BRO5/3centB/ShapesBeyond03.txt");
        std::ifstream infile8("BRO5/4centB/ShapesBeyond03.txt");

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
        double a,b,db,d,dd;
        int bin=0;
        int N=13;
        int cent=0;
        do {
                infile1 >> a >> b >> db;
                infile5 >> a >> d >> dd;
                w=w1[cent]*b+w2[cent]*d;
                dw=sqrt(pow(w1[cent]*db,2.)+pow(w2[cent]*dd,2.));
                y=w+dw;
                z=w-dw;

                infile2 >> a >> b >> db;
                infile6 >> a >> d >> dd;
                w=w1[cent]*b+w2[cent]*d;
                dw=sqrt(pow(w1[cent]*db,2.)+pow(w2[cent]*dd,2.));
                if (w+dw>y) y=w+dw;
                if (w-dw<z) z=w-dw;

                infile3 >> a >> b >> db;
                infile7 >> a >> d >> dd;
                w=w1[cent]*b+w2[cent]*d;
                dw=sqrt(pow(w1[cent]*db,2.)+pow(w2[cent]*dd,2.));
                if (w+dw>y) y=w+dw;
                if (w-dw<z) z=w-dw;

		infile4 >> a >> b >> db;
                infile8 >> a >> d >> dd;
                w=w1[cent]*b+w2[cent]*d;
                dw=sqrt(pow(w1[cent]*db,2.)+pow(w2[cent]*dd,2.));
                if (w+dw>y) y=w+dw;
                if (w-dw<z) z=w-dw;

                built << a << " " << y << " " << z << "\n";

                bin+=1;
        } while (bin<N);

built.close();
//End Program
}


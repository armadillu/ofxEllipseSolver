//
//  ofxEllipseSolver.h
//  emptyExample
//
//  Created by Oriol Ferrer Mesià on 21/02/13.
//
//

#ifndef emptyExample_ofxEllipseSolver_h
#define emptyExample_ofxEllipseSolver_h

#include "ofMain.h"
#include "ellipse.h"

class ofxEllipseSolver{

public:
	/*
	ax^2 + bxy + cy^2 + dx + ey + f = 0
	X = r cos(angle)
	Y = r sin(angle)
	X^2 + Y^2 = r^2
	 */


	bool solveElipse(
					 const ofVec2f & p0, const ofVec2f & p1, const ofVec2f & p2,
					 const ofVec2f & p3, const ofVec2f & p4){



		FLOAT pp0[3] = {p0.x, p0.y, 1 };
		FLOAT pp1[3] = {p1.x, p1.y, 1 };
		FLOAT pp2[3] = {p2.x, p2.y, 1 };
		FLOAT pp3[3] = {p3.x, p3.y, 1 };
		FLOAT pp4[3] = {p4.x, p4.y, 1 };

		int ok = toconic(pp0, pp1, pp2, pp3, pp4, &a, &b, &c, &d, &e, &f);
		//printf("abcdef : %f %f %f %f %f %f \n", a, b, c, d, e, f );
		return ok == 1;

	}

	bool solveElipse( double p0x, double p0y, double p1x, double p1y,
					 double p2x, double p2y,
					 double p3x, double p3y, double p4x, double p4y){

		FLOAT pp0[3] = {p0x, p0y, 1 };
		FLOAT pp1[3] = {p1x, p1y, 1 };
		FLOAT pp2[3] = {p2x, p2y, 1 };
		FLOAT pp3[3] = {p3x, p3y, 1 };
		FLOAT pp4[3] = {p4x, p4y, 1 };

		int ok = toconic(pp0, pp1, pp2, pp3, pp4, &a, &b, &c, &d, &e, &f);
		//printf("abcdef : %f %f %f %f %f %f \n", a, b, c, d, e, f );
		return ok == 1;
	}


	ofVec2f getEllipseVertexAt(double angle/*0..2pi*/){

		double cosinus = cos(angle);
		double sinus = sin(angle);

		double k1 = a * cosinus * cosinus + b * sinus * cosinus + c * sinus * sinus;
		double k2 = d * cosinus + e * sinus;

		double g1 = sqrt( k2 * k2 - 4.0 * f * k1);
		//double r1 = ( -k2 - g1 ) / (2.0 * k1);
		double r2 = ( -k2 + g1 ) / (2.0 * k1);

//		float x1 = r1 * cos( angle );
//		float y1 = r1 * sin( angle );
		double x2 = r2 * cosf( angle );
		double y2 = r2 * sinf( angle );


		if ( isnan(x2) || isnan(y2)){
			return ofVec2f();
		}
		//printf("%f  -  %f (%f)\n",x2 ,y2, (float)angle);
		return ofVec2f(x2, y2);
	}

	bool getIsEllipse(){
		double r = b * b - 4.0 * a * c;
		if ( !isnan(r) ){
			if (r < 0) return true;
		}
		return false;
	}


	double getEccentricity(){ // todo!
//		double r = b * b - 4 * a * c;
//		if ( fabs(r) > 0.001){
//			float ecc = sqrt((a*a - b*b) / (a*a) );
//			if (!isnan(ecc)) return ecc;
//		}
		return -1;
	}
private:

	double a; double b; double c; double d; double e; double f;



};

#endif

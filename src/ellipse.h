//
//  ellipse.h
//  emptyExample
//
//  Created by Oriol Ferrer Mesià on 21/02/13.
//
//

#ifndef emptyExample_ellipse_h
#define emptyExample_ellipse_h


/* Code to find the equation of a conic */
/*               Tom Davis              */
/*             April 12, 1996           */


#include <stdio.h>
#define FLOAT double

#define cross(a, b, ab) ab[0] = a[1]*b[2] - a[2]*b[1]; \
ab[1] = a[2]*b[0] - a[0]*b[2]; \
ab[2] = a[0]*b[1] - a[1]*b[0];

#define abs(x) ((x > 0.0) ? x : (-x))

/* toconic takes five points in homogeneous coordinates, and returns the
 * coefficients of a general conic equation in a, b, c, ..., f:
 *
 * a*x*x + b*x*y + c*y*y + d*x + e*y + f = 0.
 *
 * The routine returns 1 on success; 0 otherwise.  (It can fail, for
 * example, if there are duplicate points.
 *
 * Typically, the points will be finite, in which case the third (w)
 * coordinate for all the input vectors will be 1, although the code
 * deals cleanly with points at infinity.
 *
 * For example, to find the equation of the conic passing through (5, 0),
 * (-5, 0), (3, 2), (3, -2), and (-3, 2), set:
 *
 * p0[0] =  5, p0[1] =  0, p0[2] = 1,
 * p1[0] = -5, p1[1] =  0, p1[2] = 1,
 * p2[0] =  3, p2[1] =  2, p2[2] = 1,
 * p3[0] =  3, p3[1] = -2, p3[2] = 1,
 * p4[0] = -3, p4[1] =  2, p4[2] = 1.
 *
 * But if you want the equation of the hyperbola that is tangent to the
 * line 2x=y at infinity,  simply make one of the points be the point at
 * infinity along that line, for example:
 *
 * p0[0] = 1, p0[1] = 2, p0[2] = 0.
 */


int toconic(FLOAT p0[3], FLOAT p1[3], FLOAT p2[3], FLOAT p3[3], FLOAT p4[3],
			FLOAT *a, FLOAT *b, FLOAT *c, FLOAT *d, FLOAT *e, FLOAT *f);



#endif

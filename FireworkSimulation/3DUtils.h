/************************************************************************
     File:        3DUtils.cpp

     Author:     
                  Michael Gleicher, gleicher@cs.wisc.edu
     Modifier
                  Yu-Chi Lai, yu-chi@cs.wisc.edu
     
     Comment:     some useful routines for writing 3D interactive programs
                  written for CS638 - Michael Gleicher, November 1999
                  re-written and expanded, October 2005

									Routines to draw objects
									- drawCube
									- drawFloor
   
 		 Note:        The utilities in this file are meant to be an example for
									CS559 students to refer to. please follow the course policy on
									using example code!
     Platform:    Visio Studio.Net 2003
*************************************************************************/
#pragma once


//************************************************************************
// draw a little cube centered
//************************************************************************
// Note: we pass the size of the cube (rather than using a scale
//       transform) since we want our normals to stay unit length if possible
void drawCube(float l,float l2,float l3);
void drawCube2(float x, float y, float z, float l);
//************************************************************************
// draw a ground plane
//************************************************************************
// Note: this draws a colored checkerboard (so it does set the colors)
//       the actual colors are two global variables 
extern float floorColor1[3];
extern float floorColor2[3];

//************************************************************************
// draw the actual ground plane
// Note: The groundplane is square (which is why there is only
//       one size). the numSquares is the number of squares in each
//       across an edge
//************************************************************************
void drawFloor(float size = 10, int nSquares = 8);

//************************************************************************
// Code for doing shadows with the stencil buffer and blending
//************************************************************************
// Warning: these routines change the opengl state, and may not
// return it to where you want it to be! (a better implementation
// would save state)
// how to use:
//   1) call "setupFloor" :  draw your groundplane
//   2) call "setupShadows" :  draw your objects without any colors (otherwise, 
//                             you'll get colored shadows
//   3) call "unsetupShadows": draw your objects normally (with lighting, colors, ...)

// Before drawing the floor, setup the stencil buffer and enable depth testing
void setupFloor(void);
// Set up the projection matrix to project the shadow onto the floor.
void setupShadows(void);
// Set it back to original projection matrix
void unsetupShadows(void);

//************************************************************************
// stuff for mouse handling
//************************************************************************
// 
// Given the position of the mouse in 2D, we need to figure out where
// it is in 3D. of course, its not in one place, its a line
// this function gets that ray for you (well, it gets 2 points on the line)
int getMouseLine(double& p1x, double& p1y, double& p1z,
								 double& p2x, double& p2y, double& p2z);
			  
//************************************************************************
//
// * When you have a mouse line, you want to pick a point where you think the user 
//   wants to drag to
// * Idea: given a plane parallel to the floor, pick a point on that
//         plane (where the line intersects it)
// * Problem: what to do when the plane is parallel to the line?
// * Problem: how to make things go vertically?
// * Answer:
//   1. Have an "elevator mode" where we use a plane perpindicular to the floor
//   2. r1,r2 are two points on the line
//      a. l is the initial position of the point - we need this to know where
//         the plane is. 
//      b. r is the resulting position. it will share 1 of its coordinates
//         with l, but will be on the line
void mousePoleGo( double r1x, double r1y, double r1z,
									double r2x, double r2y, double r2z,
									double lx, double ly, double lz, 
									double &rx, double &ry, double &rz,
									bool elevator);

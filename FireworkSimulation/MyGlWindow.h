
#include <FL/Fl_Gl_Window.h>
#include <Fl/Fl.h>
#include <Fl/Fl_Value_Slider.H>
#include <windows.h>
#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>
#include <Fl/Fl_Double_Window.h>

#include "stdio.h"
#include "math.h"
#include "3DUtils.h"

#include "Vec3f.h"
#include "Mover.h"
#include "Viewer.h"
#include "Fireworks.h"
#include <vector>

#include "core.h"

class MyGlWindow : public Fl_Gl_Window {
	public:
		MyGlWindow(int x, int y, int w, int h);

		std::vector<Vec3f *> history;

		Fireworks *m_fireworks;

		int run;
		int windBlowing;
		Fl_Slider* time;

		void initMover();
		void initFirework();
		
		void update();
		void drawStuff();
		void doPick();
		
		void reset();
		void fire();
	private:
		void draw();					// standard FlTk
		
		int handle(int);				// standard FlTk
		
		void setProjection(int clearProjection = 1);
		void getMouseNDC(float& x, float& y);
		void setupLight(float x, float y, float z);

		float fieldOfView;
		Viewer *m_viewer;
		Mover *m_mover;
};


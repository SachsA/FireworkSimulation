// stdafx.h : include file for standard system include files,
// or project specific include files that are used frequently, but
// are changed infrequently


#pragma once

#define _CRT_SECURE_NO_DEPRECATE 1

#define WIN32_LEAN_AND_MEAN		// Exclude rarely-used stuff from Windows headers
// Windows Header Files:
#include <windows.h>

#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>
#include <stdio.h>
#include <string>
#include <sstream>
#include <stdlib.h>
#include <malloc.h>
#include <memory.h>
#include <tchar.h>


#include <GL/GL.h>
#include <GL/GLu.h>
#include <GL/GLut.h>

// FLTK widgets.
//
// The FLTK source is rife with dubious type conversions (i.e., void* to long), which
// causes a slew of compiler warnings to be generated.  All of the Fl widgets that
// we use are included in the following block, and for this block we temporarily
// supress display of these warnings.

#pragma warning( disable : 4312 )
#pragma warning( disable : 4311 )
#pragma warning( disable : 4244 )
#pragma warning( disable : 4275 )

#include <Fl/Fl.h>
#include <Fl/Fl_Box.h>
#include <Fl/Fl_Button.h>
#include <Fl/Fl_Counter.h>
#include <Fl/Fl_Check_Button.h>
#include <Fl/Fl_Repeat_Button.h>
#include <Fl/Fl_Choice.h>
#include <Fl/Fl_Double_Window.h>
#include <Fl/Fl_Float_Input.h>
#include <Fl/Fl_Gl_Window.h>
#include <Fl/Fl_Group.h>
#include <Fl/Fl_Input.h>
#include <Fl/Fl_Int_Input.h>
#include <Fl/Fl_Light_Button.h>
#include <Fl/Fl_Menu_Bar.h>
#include <Fl/Fl_Menu_Item.h>
#include <Fl/Fl_Menu_Button.h>
#include <Fl/Fl_Output.h>
#include <Fl/Fl_Multiline_Output.h>
#include <Fl/Fl_Return_Button.h>
#include <Fl/Fl_Select_Browser.h>
#include <Fl/Fl_Multi_Browser.h>
#include <Fl/Fl_Slider.h>
#include <Fl/Fl_Value_Slider.h>
#include <Fl/Fl_Tabs.h>
#include <Fl/Fl_Window.h>
#include <Fl/Fl_Widget.h>
#include <Fl/Fl_File_Chooser.h>

#include <Fl/fl_ask.h>
#include <Fl/fl_draw.h>
#include <Fl/fl_input.h>
#include <Fl/fl_message.h>
#include <Fl/filename.h>
#pragma warning( default : 4312 )
#pragma warning( default : 4311 )
#pragma warning( default : 4244 )



// TODO: reference additional headers your program requires here

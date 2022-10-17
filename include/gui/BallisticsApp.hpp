#include <wx/wxprec.h>
 
#ifndef WX_PRECOMP
    #include <wx/wx.h>
#endif

#include <gui/MainWindow.hpp>

#ifndef BALLISTICSAPP_HPP
#define BALLISTICSAPP_HPP

enum
{
	BUTTON_Calculate,
	TEXT_Mass,
	TEXT_Angle,
	TEXT_Force,
	TEXT_Draw,
	TEXT_Area,
	TEXT_DragCoeff
};

class BallisticsApp : public wxApp
{
	public:
		virtual bool OnInit();
};

#endif

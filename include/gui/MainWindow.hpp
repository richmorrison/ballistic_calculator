#include <wx/wxprec.h>
 
#ifndef WX_PRECOMP
    #include <wx/wx.h>
#endif

#ifndef MAINWINDOW_HPP
#define MAINWINDOW_HPP

#include <wx/chart.h>
#include <wx/chartpanel.h>
#include <wx/axis/numberaxis.h>
#include <wx/xy/xydynamicdataset.h>

#include <gui/elements/plot/LinePlot.hpp>
#include <gui/elements/InputPanel.hpp>

class MainWindow : public wxFrame
{
	public:
		MainWindow();
 
	private:
		
		PlotInterface* plot;
		
		InputPanel *inputPanel;
		
		void OnExit(wxCommandEvent& event);
		void OnAbout(wxCommandEvent& event);
		void OnCalculate(wxCommandEvent& event);
};

#endif

#ifndef PLOTINTERFACE_HPP
#define PLOTINTERFACE_HPP

#include <vector>
#include <wx/chartpanel.h>

class PlotInterface : public wxChartPanel
{
	public:
		PlotInterface(wxWindow *parent)
		: wxChartPanel(parent)
		{}
		
		virtual void update_plot(std::vector<std::pair<double, double>> data) = 0;
};

#endif

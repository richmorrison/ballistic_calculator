#ifndef LINEPLOT_HPP
#define LINEPLOT_HPP

#include <gui/elements/plot/PlotInterface.hpp>

#include <wx/xy/xyplot.h>
#include <wx/xy/xylinerenderer.h>
#include <wx/xy/xydynamicdataset.h>

class LinePlot : public PlotInterface
{
	private:
		
		Chart *chart=nullptr;
		
		XYDynamicSerie *dynamicSeries=nullptr;
		XYDynamicDataset *dataset=nullptr;
		NumberAxis *leftAxis=nullptr;
		NumberAxis *bottomAxis=nullptr;
		
		wxColour colour;
		
	public:
		
		LinePlot(wxWindow *parent, const char* title, const char* xTitle, const char* yTitle, wxColour colour);
		
		void update_plot(std::vector<std::pair<double, double>> data);
};

#endif

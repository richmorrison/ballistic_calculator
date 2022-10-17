#include <gui/elements/plot/LinePlot.hpp>

LinePlot::LinePlot(wxWindow *parent, const char* title, const char* xTitle, const char* yTitle, wxColour colour)
	: PlotInterface(parent)
{
	this->colour = colour;
	
	dynamicSeries = new XYDynamicSerie();
	dynamicSeries->AddXY(0, 0);
	dynamicSeries->AddXY(1, 1);

	dataset = new XYDynamicDataset();
	dataset->AddSerie(dynamicSeries);
	dataset->SetRenderer(new XYLineRenderer());
	dataset->GetRenderer()->SetSerieColour(0, new wxColour(255, 255, 255));
	

	leftAxis = new NumberAxis(AXIS_LEFT);
	bottomAxis = new NumberAxis(AXIS_BOTTOM);
	
	leftAxis->IntegerValues(false);
	bottomAxis->IntegerValues(false);
	
	leftAxis->SetTitle(yTitle);
	bottomAxis->SetTitle(xTitle);
	
	XYPlot *plot = new XYPlot();
	plot->AddObjects(dataset, leftAxis, bottomAxis);
	
	chart = new Chart(plot, title);
	SetChart(chart);
}

void LinePlot::update_plot(std::vector<std::pair<double, double>> data)
{
	double min_x=0.0, max_x=0.0;
	double min_y=0.0, max_y=0.0;
	
	for(auto i : data)
	{
		min_x = i.first < min_x ? i.first : min_x;
		max_x = i.first > max_x ? i.first : max_x;
		min_y = i.second < min_y ? i.second : min_y;
		max_y = i.second > max_y ? i.second : max_y;
	}
	
	leftAxis->SetFixedBounds(0, max_y);
	bottomAxis->SetFixedBounds(0, max_x);
	
	dataset->BeginUpdate();
	dataset->GetRenderer()->SetSerieColour(0, &colour);
	dynamicSeries->Clear();
	for(auto d : data)
		dynamicSeries->AddXY(d.first, d.second);
	dataset->EndUpdate();
}

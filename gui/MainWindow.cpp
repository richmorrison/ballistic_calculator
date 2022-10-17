#include <gui/MainWindow.hpp>

#include <wx/valnum.h>
#include <gui/BallisticsApp.hpp>

#include <vector>
#include <utility>

#include <numerics/methods.hpp>
#include <physics/BallisticState.hpp>
#include <physics/physics.hpp>

MainWindow::MainWindow()
    : wxFrame(NULL, wxID_ANY, "Ballistic Calculator")
{
	wxMenu *menuFile = new wxMenu;
	menuFile->Append(wxID_EXIT);
	
	wxMenu *menuHelp = new wxMenu;
	menuHelp->Append(wxID_ABOUT);
	
	wxMenuBar *menuBar = new wxMenuBar;
	menuBar->Append(menuFile, "&File");
	menuBar->Append(menuHelp, "&Help");
	
	SetMenuBar( menuBar );
	
	plot = new LinePlot(this, "Trajectory", "Distance (m)", "Height (m)", wxColour(0, 0, 255));
	
	wxBoxSizer *horizSizer = new wxBoxSizer( wxHORIZONTAL );
	horizSizer->Add(plot, 1,wxALL|wxEXPAND, 5);
	
	inputPanel = new InputPanel(
		this,
		{
			TextInputDescriptor( TEXT_Mass,      "0.190",    wxFloatingPointValidator<float>(), "Mass (Kg)"			),
			TextInputDescriptor( TEXT_Angle,     "45.0",     wxFloatingPointValidator<float>(), "Angle (degrees)"		),
			TextInputDescriptor( TEXT_Force,     "4360",     wxFloatingPointValidator<float>(), "Force (N)"			),
			TextInputDescriptor( TEXT_Draw,      "0.15",     wxFloatingPointValidator<float>(), "Draw (m)"			),
			TextInputDescriptor( TEXT_Area,      "0.000170", wxFloatingPointValidator<float>(), "Reference Area (m^2)"	),
			TextInputDescriptor( TEXT_DragCoeff, "2.0",      wxFloatingPointValidator<float>(), "Drag Coefficient"		)
		}
	);
	
	wxButton *Calculate = new wxButton(
		this, BUTTON_Calculate, _T("Calculate"),
		wxDefaultPosition, wxDefaultSize, 0
	);
	
	inputPanel->Add(Calculate, 1, wxEXPAND | wxALL, 10);

	horizSizer->Add(inputPanel, 1, wxEXPAND | wxALL, 10);
	
	SetSizerAndFit(horizSizer);
	
	int width, height;
	plot->GetSize(&width, &height);
	plot->SetMinSize( wxSize(height, height) );
	
	CreateStatusBar();
	SetStatusText("Richard Morrison 2022");
	
	Bind(wxEVT_MENU, &MainWindow::OnAbout, this, wxID_ABOUT);
	Bind(wxEVT_MENU, &MainWindow::OnExit, this, wxID_EXIT);
	Bind(wxEVT_BUTTON, &MainWindow::OnCalculate, this, BUTTON_Calculate);
}

void MainWindow::OnExit(wxCommandEvent& event)
{
	Close(true);
}

void MainWindow::OnAbout(wxCommandEvent& event)
{
	wxMessageBox(
		"A toy ballistic trajectory calculator.\nDeveloped for the developer to explore wxWidgets and wxFreeChart.\nRichard Morrison, 2022",
		"About", wxOK | wxICON_INFORMATION
	);
}

void MainWindow::OnCalculate(wxCommandEvent& event)
{
	double mass;
	inputPanel->get_value_by_label("Mass (Kg)").ToDouble(&mass);
	
	double angle;
	inputPanel->get_value_by_label("Angle (degrees)").ToDouble(&angle);
	
	double force;
	inputPanel->get_value_by_label("Force (N)").ToDouble(&force);
	
	double draw;
	inputPanel->get_value_by_label("Draw (m)").ToDouble(&draw);
	
	double area;
	inputPanel->get_value_by_label("Reference Area (m^2)").ToDouble(&area);
	
	double dragCoeff;
	inputPanel->get_value_by_label("Drag Coefficient").ToDouble(&dragCoeff);
	
	BallisticState bolt = release_bolt(mass, angle*3.14159/180.0, force, draw, area, dragCoeff, ds_dt);
	
	double target_time = bolt.time;
	
	std::vector<std::pair<double, double>> data;
	data.push_back({bolt.position[0], bolt.position[1]});
	
	while(bolt.position[1]>=0)
	{
		target_time+=0.0001;
		
		bolt.solve(
			0.001,
			[target_time](const BallisticState& state)->bool{return state.time >= target_time;},
			runge_kutta
		);
		
		data.push_back({bolt.position[0], bolt.position[1]});
	}
	
	plot->update_plot(data);
}

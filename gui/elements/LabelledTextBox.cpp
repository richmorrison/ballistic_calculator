#include <gui/elements/LabelledTextBox.hpp>

LabelledTextBox::LabelledTextBox(
	wxWindow *parent,
	const wxString & label,
	wxWindowID id,
	const wxString &value,
	const wxPoint &pos,
	const wxSize &size,
	long style,
	const wxValidator &validator,
	const wxString &name
)
	: wxBoxSizer( wxVERTICAL )
{
	
	staticlabel = new wxStaticText( parent, -1, label, pos, size, style, name);
	box = new wxTextCtrl( parent, id, value, pos, size, style, validator, name );
	Add(staticlabel, 1, wxEXPAND | wxALL, 10, NULL);
	Add(box, 1, wxEXPAND | wxALL, 10, NULL);
}

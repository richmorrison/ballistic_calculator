#ifndef LABELLEDTEXTBOX_HPP
#define LABELLEDTEXTBOX_HPP

#include <wx/stattext.h>
#include <wx/sizer.h>
#include <wx/textctrl.h>

class LabelledTextBox : public wxBoxSizer
{
	public:
	
		wxStaticText *staticlabel = nullptr;
		wxTextCtrl *box = nullptr;
		
		LabelledTextBox(
			wxWindow *parent,
			const wxString & label,
			wxWindowID id,
			const wxString &value=wxEmptyString,
			const wxPoint &pos=wxDefaultPosition,
			const wxSize &size=wxDefaultSize,
			long style=0,
			const wxValidator &validator=wxDefaultValidator,
			const wxString &name=wxTextCtrlNameStr
		);
};

#endif

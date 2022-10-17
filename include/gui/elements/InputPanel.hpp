#ifndef INPUTPANEL_HPP
#define INPUTPANEL_HPP

#include <initializer_list>
#include <map>
#include <string>

#include <wx/window.h>
#include <wx/sizer.h>
#include <wx/textctrl.h>


#include <gui/elements/LabelledTextBox.hpp>

class TextInputDescriptor
{
	public:
	
		const wxWindowID id;
		const wxString &value;
		const wxValidator &validator;
		const std::string reference;
		
		TextInputDescriptor(const wxWindowID id, const wxString &value, const wxValidator &validator, const std::string reference)
			: id{id}, value{value}, validator{validator}, reference{reference}
		{}
};

class InputPanel : public wxBoxSizer
{
	private:
		
		std::map<std::string, LabelledTextBox*> TextCtrls;
	public:
	
		InputPanel(wxWindow* parent, std::initializer_list<TextInputDescriptor> inputs, int orient=wxVERTICAL, int proportion=1, int flag=wxEXPAND | wxALL, int border=10, wxObject *userdata=NULL);
		
		wxString get_value_by_label(std::string reference);
};

#endif

#include <gui/elements/InputPanel.hpp>
	
#include <wx/stattext.h>

InputPanel::InputPanel(wxWindow* parent, std::initializer_list<TextInputDescriptor> inputs, int orient, int proportion, int flag, int border, wxObject *userdata)
	: wxBoxSizer( orient ), TextCtrls{}
{
	for(auto i : inputs)
	{
		LabelledTextBox *box = new LabelledTextBox( parent, i.reference, i.id, i.value, wxDefaultPosition, wxDefaultSize, wxTE_RICH, i.validator, wxTextCtrlNameStr );
		Add(box, proportion, flag, border, userdata);
		TextCtrls[i.reference]=box;
	}
}

wxString InputPanel::get_value_by_label(std::string reference)
{
	return TextCtrls[reference]->box->GetValue();
}

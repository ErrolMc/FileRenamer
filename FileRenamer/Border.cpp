#include "Border.h"
#include <wx/print.h>

Border::Border(wxWindow* parent, wxWindowID id, const wxPoint& pos, const wxSize& size) : wxPanel(parent, id, pos, size)
{
	wxPanel* center = new wxPanel(this, wxID_ANY, wxDefaultPosition, wxSize(600, 600));
	center->SetBackgroundColour(wxColor(0, 0, 0));

	wxBoxSizer* sizer = new wxBoxSizer(wxVERTICAL);
	sizer->Add(center, 1, wxEXPAND | wxALL, 10);

	this->SetSizerAndFit(sizer);
}
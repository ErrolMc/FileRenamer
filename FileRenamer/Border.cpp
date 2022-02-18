#include "Border.h"
#include <wx/print.h>

Border::Border(const wxColor& mainColor, const wxColor& borderColor, int borderWidth, wxWindow* parent, wxWindowID id, const wxPoint& pos, const wxSize& size) : wxPanel(parent, id, pos, size)
{
	wxSize centerSize = wxSize(size.x - borderWidth, size.y - borderWidth);

	center = new wxPanel(this, wxID_ANY, wxDefaultPosition, centerSize); // some math to calculate min size based on size and border width
	center->SetBackgroundColour(mainColor);

	sizer = new wxBoxSizer(wxVERTICAL);
	sizer->Add(center, 1, wxEXPAND | wxALL, borderWidth);

	this->SetSizerAndFit(sizer);
	this->SetBackgroundColour(borderColor);
}

wxPanel* Border::GetCenter()
{
	return center;
}

wxBoxSizer* Border::GetSizer()
{
	return sizer;
}

#pragma once

#include <wx/wx.h>

class Border : public wxPanel
{
private:
	wxPanel* center;
	wxBoxSizer* sizer;
public:
	Border(const wxColor& mainColor, const wxColor& borderColor, int borderWidth, wxWindow* parent, wxWindowID id, const wxPoint& pos, const wxSize& size);
	wxPanel* GetCenter();
	wxBoxSizer* GetSizer();
};

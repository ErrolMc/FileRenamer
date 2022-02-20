#pragma once

#include <wx/wx.h>
#include <wx/sizer.h>

class Border : public wxPanel
{
private:
	wxColor* mainColor = nullptr;
	wxColor* borderColor = nullptr;
	int borderWidth;
public:
	Border(wxColor* mainColor, wxColor* borderColor, int borderWidth, wxWindow* parent, wxWindowID id, const wxPoint& pos, const wxSize& size);
	~Border();
	
	void Render(wxDC& dc);

	void OnPaint(wxPaintEvent& evt);
	void OnResize(wxSizeEvent& evt);

	DECLARE_EVENT_TABLE()
};

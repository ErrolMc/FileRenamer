#pragma once

#include <wx/wx.h>
#include <wx/sizer.h>

class ListButton : public wxPanel
{
private:
	wxString label;
	bool hovered;

public:
	ListButton(wxString label, wxWindow* parent, wxWindowID id, const wxPoint& pos, const wxSize& size);
	~ListButton();

	void Render(wxDC& dc);

	void OnPaint(wxPaintEvent& evt);
	void OnResize(wxSizeEvent& evt);

	void OnMouseEnter(wxMouseEvent& evt);
	void OnMouseLeave(wxMouseEvent& evt);
};
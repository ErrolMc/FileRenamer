#include "Border.h"
#include "wx/dcbuffer.h"

BEGIN_EVENT_TABLE(Border, wxPanel)
EVT_PAINT(Border::OnPaint)
EVT_SIZE(Border::OnResize)
END_EVENT_TABLE()

Border::Border(wxColor* mainColor, wxColor* borderColor, int borderWidth, wxWindow* parent, wxWindowID id, const wxPoint& pos, const wxSize& size) : wxPanel(parent, id, pos, size)
{
	this->mainColor = mainColor;
	this->borderColor = borderColor;
	this->borderWidth = borderWidth;
}

void Border::Render(wxDC& dc)
{
	this->PrepareDC(dc);

	wxPen pen = wxPen(*borderColor, borderWidth);
	dc.SetPen(pen);

	wxBrush brush = wxBrush(*mainColor);
	dc.SetBrush(brush);

	int w, h;
	this->GetClientSize(&w, &h);

	dc.Clear();
	dc.DrawRectangle(0, 0, w, h);
}

void Border::OnPaint(wxPaintEvent& evt)
{
	wxBufferedPaintDC dc(this);
	Render(dc);
}

void Border::OnResize(wxSizeEvent& evt)
{
	this->Refresh();
}

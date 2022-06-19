#include "ListButton.h"
#include "wx/dcbuffer.h"

ListButton::ListButton(wxString label, int ind, cb::Callback1<void, int> callback, wxWindow* parent, wxWindowID id, const wxPoint& pos, const wxSize& size) : wxPanel(parent, id, pos, size)
{
    this->label = label;
    this->hovered = false;
    this->ind = ind;
    this->callback = callback;

    this->Connect(wxEVT_PAINT, wxPaintEventHandler(ListButton::OnPaint));
    this->Connect(wxEVT_SIZE, wxSizeEventHandler(ListButton::OnResize));
    this->Connect(wxEVT_ENTER_WINDOW, wxMouseEventHandler(ListButton::OnMouseEnter));
    this->Connect(wxEVT_LEAVE_WINDOW, wxMouseEventHandler(ListButton::OnMouseLeave));
    this->Connect(wxEVT_LEFT_UP, wxMouseEventHandler(ListButton::OnMouseClick));
}

void ListButton::Render(wxDC& dc)
{
    this->PrepareDC(dc);
    dc.Clear();

    dc.SetPen(*wxTRANSPARENT_PEN);

    wxBrush brush = wxBrush(hovered ? wxColor(100, 100, 100) : wxColor(30, 30, 30));
    dc.SetBrush(brush);

    int x, y, w, h;
    this->GetClientSize(&w, &h);
    this->GetPosition(&x, &y);

    dc.DrawRectangle(0, 0, w, h);

    dc.SetTextForeground(wxColor(255, 255, 255));
    dc.DrawText(label, 5, (h/4));
}

void ListButton::OnPaint(wxPaintEvent& evt)
{
    wxBufferedPaintDC dc(this);
    Render(dc);
}

void ListButton::OnResize(wxSizeEvent& evt)
{
    this->Refresh();
}

void ListButton::OnMouseEnter(wxMouseEvent& evt)
{
    hovered = true;
    this->Refresh();
}

void ListButton::OnMouseLeave(wxMouseEvent& evt)
{
    hovered = false;
    this->Refresh();
}

void ListButton::OnMouseClick(wxMouseEvent &evt)
{
    callback.Call(ind);
}

ListButton::~ListButton()
{

}
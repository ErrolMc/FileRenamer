#pragma once

#include <wx/wx.h>
#include <wx/sizer.h>
#include "callback.hpp"

class ListButton : public wxPanel
{
private:
    wxString label;
    bool hovered;
    int ind;
    cb::Callback1<void, int> callback;

public:
    ListButton(wxString label, int ind, cb::Callback1<void, int> callback, wxWindow* parent, wxWindowID id, const wxPoint& pos, const wxSize& size);
    ~ListButton();

    void Render(wxDC& dc);

    void OnPaint(wxPaintEvent& evt);
    void OnResize(wxSizeEvent& evt);

    void OnMouseEnter(wxMouseEvent& evt);
    void OnMouseLeave(wxMouseEvent& evt);
    void OnMouseClick(wxMouseEvent& evt);
};
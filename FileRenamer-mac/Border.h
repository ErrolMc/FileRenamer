#pragma once

#include <wx/wx.h>
#include <wx/sizer.h>

class Border : public wxPanel
{
private:
    wxColor* mainColor = nullptr;
public:
    Border(wxColor* mainColor, wxWindow* parent, wxWindowID id, const wxPoint& pos, const wxSize& size);
    ~Border();
};

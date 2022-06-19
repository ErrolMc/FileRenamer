#include "Border.h"
#include "wx/dcbuffer.h"

Border::Border(wxColor* mainColor, wxWindow* parent, wxWindowID id, const wxPoint& pos, const wxSize& size)
        : wxPanel(parent, id, pos, size)
{
    this->mainColor = mainColor;

    this->SetBackgroundColour(*mainColor);
}

Border::~Border()
{
    delete(mainColor);
}

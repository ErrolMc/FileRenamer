#include "DeleteWindow.h"

DeleteWindow::DeleteWindow(wxWindow* parent)
        : wxPanel(parent, wxID_ANY, wxDefaultPosition, wxDefaultSize)
{
    wxCheckBox* removeCurrentBox = new wxCheckBox(this, wxID_ANY, "Remove current name", wxPoint(10, 10));
    removeCurrentBox->SetOwnForegroundColour(wxColor(255, 255, 255));

}

DeleteWindow::~DeleteWindow()
{
}
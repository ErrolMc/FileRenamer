#pragma once

#include <wx/wx.h>
#include <wx/sizer.h>
#include "wx/listctrl.h"
#include "wx/numdlg.h"
#include "wx/spinctrl.h"

class DeleteWindow : public wxPanel
{
private:

public:
    DeleteWindow(wxWindow* parent);
    ~DeleteWindow();
};

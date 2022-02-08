#include <wx/wx.h>
#include "MainFrame.h"

class Application : public wxApp
{
public:
    virtual bool OnInit();
};

wxIMPLEMENT_APP(Application);
bool Application::OnInit()
{
    MainFrame* frame = new MainFrame();
    frame->Show(true);
    return true;
}

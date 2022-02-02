#include <wx/wxprec.h>
#ifndef WX_PRECOMP
#include <wx/wx.h>
#endif

#include "MyFrame.h"

class Application : public wxApp
{
public:
    virtual bool OnInit();
};

wxIMPLEMENT_APP(Application);
bool Application::OnInit()
{
    MyFrame* frame = new MyFrame();
    frame->Show(true);
    return true;
}

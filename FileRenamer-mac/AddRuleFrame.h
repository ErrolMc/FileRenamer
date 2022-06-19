#pragma once

#include <wx/wx.h>
#include "wx/listctrl.h"
#include "Border.h"
#include "ListButton.h"

#include "InsertWindow.h"
#include "DeleteWindow.h"

#include "Border.h"
#include "MainFrame.h"
#include "ListButton.h"

class MainFrame; // to avoid circular reference

enum class RuleType
{
    none,
    insert,
    delete_,
    replace,
};

class AddRuleFrame : public wxFrame
{
private:
    std::vector<ListButton*> listButtons;

    wxBoxSizer* m_SelectedWindowSizer;
    wxBoxSizer* m_ButtonSizer;
    wxBoxSizer* m_PanelSizer;
    wxPanel* m_PanelLeft;
    wxPanel* m_PanelRight;


    // selected button
    wxPanel* m_CurFrame;
    RuleType m_CurType;

    // reference to main
    MainFrame* m_MainFrame = nullptr;
public:
    AddRuleFrame(MainFrame* parent);
    ~AddRuleFrame();

    void Navigate(int ind);
};

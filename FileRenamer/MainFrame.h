#pragma once

#include <wx/wx.h>

#include "AddRuleFrame.h"
class AddRuleFrame; // to avoid circular reference

enum class State
{
    Idle = 0,
    AddRule = 1,
};

class MainFrame : public wxFrame
{
public:
    MainFrame();
    void OnClose_AddRule();
private:
    State state;
    wxMenuBar* m_MenuBar = nullptr;

    // rule tool bar
    wxToolBar* m_RuleToolBar = nullptr;
    wxButton* m_AddRuleButton = nullptr;
    wxButton* m_RemoveRuleButton = nullptr;
    wxButton* m_UpRuleButton = nullptr;
    wxButton* m_DownRuleButton = nullptr;

    AddRuleFrame* m_AddRuleFrame = nullptr;

    void OnExit(wxCommandEvent& evt);
    void OnClick_AddRule(wxCommandEvent& evt);
};
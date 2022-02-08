#include "MainFrame.h" 

MainFrame::MainFrame() : wxFrame(NULL, wxID_ANY, "Errol's File Renamer")
{
    state = State::Idle;

    // file menu
    wxMenu* menuFile = new wxMenu;
    menuFile->Append(wxID_EXIT);
    
    // menu bar
    m_MenuBar = new wxMenuBar;
    m_MenuBar->Append(menuFile, "&File");

    // rule tool bar
    m_RuleToolBar = this->CreateToolBar(wxTB_HORIZONTAL, wxID_ANY);
    m_AddRuleButton = new wxButton(m_RuleToolBar, 10001, "Add");
    m_RemoveRuleButton = new wxButton(m_RuleToolBar, 10002, "Remove");
    m_UpRuleButton = new wxButton(m_RuleToolBar, 10003, "Up");
    m_DownRuleButton = new wxButton(m_RuleToolBar, 10004, "Down");

    m_AddRuleButton->Bind(wxEVT_COMMAND_BUTTON_CLICKED, &MainFrame::OnClick_AddRule, this);

    m_RuleToolBar->AddControl(m_AddRuleButton);
    m_RuleToolBar->AddControl(m_RemoveRuleButton);
    m_RuleToolBar->AddControl(m_UpRuleButton);
    m_RuleToolBar->AddControl(m_DownRuleButton);

    m_RuleToolBar->Realize();

    this->SetToolBar(m_RuleToolBar);
    this->SetMenuBar(m_MenuBar);

    this->Bind(wxEVT_MENU, &MainFrame::OnExit, this, wxID_EXIT);
}

void MainFrame::OnClick_AddRule(wxCommandEvent& evt) 
{
    if (state == State::Idle)
    {
        state = State::AddRule;
        m_AddRuleFrame = new AddRuleFrame(this);
        m_AddRuleFrame->Show(true);
    }
}

void MainFrame::OnExit(wxCommandEvent& evt)
{
    this->Close(true);
}

void MainFrame::OnClose_AddRule()
{
    state = State::Idle;
}

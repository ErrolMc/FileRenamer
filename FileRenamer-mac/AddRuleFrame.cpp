#include "AddRuleFrame.h"

AddRuleFrame::AddRuleFrame(MainFrame* parent) : wxFrame(parent, wxID_ANY, "Add Rule", wxPoint(600, 200))
{
    m_MainFrame = parent;
    m_CurType = RuleType::none;

    m_PanelLeft = new Border(new wxColor(30, 30, 30), this, wxID_ANY, wxDefaultPosition, wxSize(200, 200));
    m_PanelRight = new Border(new wxColor(30, 30, 30), this, wxID_ANY, wxDefaultPosition, wxSize(600, 500));

    m_SideBySizePanelSizer = new wxBoxSizer(wxHORIZONTAL);
    m_SideBySizePanelSizer->Add(m_PanelLeft, 0, wxEXPAND | wxLEFT | wxTOP | wxBOTTOM, 10);
    m_SideBySizePanelSizer->Add(m_PanelRight, 2, wxEXPAND | wxALL, 10);

    m_ButtonSizer = new wxBoxSizer(wxVERTICAL);

    ListButton* listButton1 = new ListButton("Insert", (int)RuleType::insert, cb::Callback1<void, int>(this, &AddRuleFrame::Navigate), m_PanelLeft, wxID_ANY, wxDefaultPosition, wxSize(100, 30));
    ListButton* listButton2 = new ListButton("Delete", (int)RuleType::delete_, cb::Callback1<void, int>(this, &AddRuleFrame::Navigate), m_PanelLeft, wxID_ANY, wxDefaultPosition, wxSize(100, 30));
    ListButton* listButton3 = new ListButton("Replace", (int)RuleType::replace, cb::Callback1<void, int>(this, &AddRuleFrame::Navigate), m_PanelLeft, wxID_ANY, wxDefaultPosition, wxSize(100, 30));

    m_ButtonSizer->Add(listButton1, 0, wxALIGN_TOP);
    m_ButtonSizer->Add(listButton2, 0, wxALIGN_TOP);
    m_ButtonSizer->Add(listButton3, 0, wxALIGN_TOP);

    m_PanelLeft->SetSizerAndFit(m_ButtonSizer);

    m_MainSizer = new wxBoxSizer(wxVERTICAL);
    m_BottomButtonsSizer = new wxBoxSizer(wxHORIZONTAL);

    Border* m_AddRuleBtn = new Border(new wxColor(30, 30, 30), this, wxID_ANY, wxDefaultPosition, wxSize(200, 40));
    Border* m_CloseButton = new Border(new wxColor(30, 30, 30), this, wxID_ANY, wxDefaultPosition, wxSize(200, 40));
    m_BottomButtonsSizer->Add(m_AddRuleBtn, 2, wxEXPAND | wxBOTTOM | wxLEFT, 10);
    m_BottomButtonsSizer->Add(m_CloseButton, 0, wxEXPAND | wxBOTTOM | wxLEFT | wxRIGHT, 10);

    m_MainSizer->Add(m_SideBySizePanelSizer, 1, wxEXPAND);
    m_MainSizer->Add(m_BottomButtonsSizer, 0, wxEXPAND);

    m_SelectedWindowSizer = new wxBoxSizer(wxHORIZONTAL);
    m_CurFrame = nullptr;

    this->SetSizerAndFit(m_MainSizer);
    this->SetBackgroundColour(wxColor(45, 45, 48));
}

AddRuleFrame::~AddRuleFrame()
{
    m_MainFrame->OnClose_AddRule();
}

void AddRuleFrame::Navigate(int ind)
{
    RuleType type = (RuleType)ind;

    if (type != m_CurType)
    {
        if (m_CurFrame != nullptr)
        {
            delete(m_CurFrame);
            m_CurFrame = nullptr;
            m_SelectedWindowSizer->Clear(true);
        }

        switch (type)
        {
            case RuleType::insert:
                m_CurFrame = new InsertWindow(m_PanelRight);
                m_SelectedWindowSizer->Add(m_CurFrame, 1, wxEXPAND | wxALL, 20);
                break;
            case RuleType::delete_:
                m_CurFrame = new DeleteWindow(m_PanelRight);
                m_SelectedWindowSizer->Add(m_CurFrame, 1, wxEXPAND | wxALL, 20);
                break;
            case RuleType::replace:
                wxLogDebug(wxString("replace"));
                break;
            default:
                break;
        }

        m_PanelRight->SetSizerAndFit(m_SelectedWindowSizer);
        this->Layout();

        m_CurType = type;
    }
}


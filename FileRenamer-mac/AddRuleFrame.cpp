#include "AddRuleFrame.h"

AddRuleFrame::AddRuleFrame(MainFrame* parent) : wxFrame(parent, wxID_ANY, "Add Rule", wxPoint(600, 200))
{
    m_MainFrame = parent;

    m_PanelLeft = new Border(new wxColor(30, 30, 30), this, wxID_ANY, wxDefaultPosition, wxSize(200, 200));
    m_PanelRight = new Border(new wxColor(30, 30, 30), this, wxID_ANY, wxDefaultPosition, wxSize(600, 600));

    wxBoxSizer* sizer = new wxBoxSizer(wxHORIZONTAL);
    sizer->Add(m_PanelLeft, 0, wxEXPAND | wxLEFT | wxTOP | wxBOTTOM, 10);
    sizer->Add(m_PanelRight, 2, wxEXPAND | wxALL, 10);

    wxBoxSizer* buttonSizer = new wxBoxSizer(wxVERTICAL);

    ListButton* listButton1 = new ListButton("Insert", m_PanelLeft, wxID_ANY, wxDefaultPosition, wxSize(100, 30));
    ListButton* listButton2 = new ListButton("Delete", m_PanelLeft, wxID_ANY, wxDefaultPosition, wxSize(100, 30));
    ListButton* listButton3 = new ListButton("Replace", m_PanelLeft, wxID_ANY, wxDefaultPosition, wxSize(100, 30));

    buttonSizer->Add(listButton1, 0, wxALIGN_TOP);
    buttonSizer->Add(listButton2, 0, wxALIGN_TOP);
    buttonSizer->Add(listButton3, 0, wxALIGN_TOP);

    m_PanelLeft->SetSizerAndFit(buttonSizer);

    wxPanel* insertWindow = new InsertWindow(m_PanelRight);

    wxBoxSizer* rightSizer = new wxBoxSizer(wxHORIZONTAL);
    rightSizer->Add(insertWindow, 1, wxEXPAND | wxALL, 35);

    m_PanelRight->SetSizer(rightSizer);

    this->SetSizerAndFit(sizer);
    this->SetBackgroundColour(wxColor(45, 45, 48));
}

AddRuleFrame::~AddRuleFrame()
{
    m_MainFrame->OnClose_AddRule();
}


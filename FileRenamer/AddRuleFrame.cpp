#include "AddRuleFrame.h"

AddRuleFrame::AddRuleFrame(MainFrame* parent) : wxFrame(parent, wxID_ANY, "Add Rule", wxPoint(600, 200))
{
	m_MainFrame = parent;

	Border* panel_left = new Border(wxColor(255, 255, 255), wxColor(0, 0, 0), 2, this, wxID_ANY, wxDefaultPosition, wxSize(200, 200));
	Border* panel_right = new Border(wxColor(255, 255, 255), wxColor(0, 0, 0), 2, this, wxID_ANY, wxDefaultPosition, wxSize(600, 600));

	wxBoxSizer* sizer = new wxBoxSizer(wxHORIZONTAL);
	sizer->Add(panel_left, 0, wxEXPAND | wxLEFT | wxTOP | wxBOTTOM, 10);
	sizer->Add(panel_right, 2, wxEXPAND | wxALL, 10);

	this->SetSizerAndFit(sizer);
	
	wxListBox* m_ButtonListBox = new wxListBox(panel_left, wxID_ANY, wxPoint(10, 10), wxSize(180, 300));
	m_ButtonListBox->Append(wxT("Insert"));
	m_ButtonListBox->Append(wxT("Delete"));
	m_ButtonListBox->Append(wxT("Remove"));
	m_ButtonListBox->Append(wxT("Replace"));
	m_ButtonListBox->Append(wxT("Case"));
}

AddRuleFrame::~AddRuleFrame()
{
	m_MainFrame->OnClose_AddRule();
}

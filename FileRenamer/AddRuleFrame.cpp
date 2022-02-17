#include "AddRuleFrame.h"

AddRuleFrame::AddRuleFrame(MainFrame* parent) : wxFrame(parent, wxID_ANY, "Add Rule", wxPoint(600, 200))
{
	m_MainFrame = parent;

	wxPanel* panel_left = new wxPanel(this, wxID_ANY, wxDefaultPosition, wxSize(200, 200));
	panel_left->SetBackgroundColour(wxColor(255, 255, 255));

	wxPanel* panel_right = new wxPanel(this, wxID_ANY, wxDefaultPosition, wxSize(600, 600));
	panel_right->SetBackgroundColour(wxColor(255, 255, 255));

	wxPanel* panel_top_left = new wxPanel(panel_left, wxID_ANY, wxDefaultPosition, wxSize(200, 400));
	panel_top_left->SetBackgroundColour(wxColor(0, 0, 0));

	wxBoxSizer* sizer = new wxBoxSizer(wxHORIZONTAL);
	sizer->Add(panel_left, 0, wxEXPAND | wxLEFT | wxTOP | wxBOTTOM, 10);
	sizer->Add(panel_right, 2, wxEXPAND | wxALL, 10);

	wxBoxSizer* sizer_top = new wxBoxSizer(wxHORIZONTAL);
	sizer_top->Add(panel_top_left, 1, wxALL, 10);

	panel_left->SetSizerAndFit(sizer_top);

	this->SetSizerAndFit(sizer);
	
	wxListBox* m_ButtonListBox = new wxListBox(panel_top_left, wxID_ANY, wxPoint(10, 10), wxSize(180, 300));
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

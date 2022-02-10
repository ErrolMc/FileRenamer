#include "AddRuleFrame.h"

AddRuleFrame::AddRuleFrame(MainFrame* parent) : wxFrame(parent, wxID_ANY, "Add Rule", wxPoint(100, 100), wxSize(500, 500))
{
	m_MainFrame = parent;
	m_Panel = new wxPanel(this, wxID_ANY);

	m_ButtonListBox = new wxListBox(m_Panel, wxID_ANY, wxPoint(20, 20), wxSize(100, 200));
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

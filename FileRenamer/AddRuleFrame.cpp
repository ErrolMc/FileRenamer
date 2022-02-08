#include "AddRuleFrame.h"

AddRuleFrame::AddRuleFrame(MainFrame* parent) : wxFrame(parent, wxID_ANY, "Add Rule")
{
	m_MainFrame = parent;
}

AddRuleFrame::~AddRuleFrame()
{
	m_MainFrame->OnClose_AddRule();
}

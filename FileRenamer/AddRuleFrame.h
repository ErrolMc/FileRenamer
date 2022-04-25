#pragma once

#include <wx/wx.h>
#include "wx/listctrl.h"
#include "Border.h"
#include "ListButton.h"

#include "InsertWindow.h"

#include "Border.h"
#include "MainFrame.h"
class MainFrame; // to avoid circular reference

class AddRuleFrame : public wxFrame
{
private:
	std::vector<ListButton*> listButtons;
	wxPanel* m_PanelLeft;
	wxPanel* m_PanelRight;

	MainFrame* m_MainFrame = nullptr;
public:
	AddRuleFrame(MainFrame* parent);
	~AddRuleFrame();
};
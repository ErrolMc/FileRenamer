#pragma once

#include <wx/wx.h>

#include "MainFrame.h"
class MainFrame; // to avoid circular reference

class AddRuleFrame : public wxFrame
{
public:
	AddRuleFrame(MainFrame* parent);
	~AddRuleFrame();
private:
	MainFrame* m_MainFrame = nullptr;

	wxPanel* m_Panel = nullptr; // need this for the list box to work
	wxListBox* m_ButtonListBox = nullptr;
};
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
};
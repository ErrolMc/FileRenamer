#pragma once

#include <wx/wx.h>
#include "Border.h"

#include "Border.h"
#include "MainFrame.h"
class MainFrame; // to avoid circular reference

class AddRuleFrame : public wxFrame
{
private:
	MainFrame* m_MainFrame = nullptr;
public:
	AddRuleFrame(MainFrame* parent);
	~AddRuleFrame();
};
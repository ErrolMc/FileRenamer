#include "InsertWindow.h"

InsertWindow::InsertWindow(wxWindow* parent)
        : wxPanel(parent, wxID_ANY, wxDefaultPosition, wxDefaultSize)
{
    wxStaticText* insertLabel = new wxStaticText(this, wxID_ANY, "Insert:", wxPoint(30, 32));
    insertLabel->SetForegroundColour(wxColor(255, 255, 255));

    wxTextCtrl* insertTextInput = new wxTextCtrl(this, wxID_ANY, "", wxPoint(80, 30), wxSize(300, 23), wxBORDER_SIMPLE);
    insertTextInput->SetBackgroundColour(wxColor(40, 40, 40));
    insertTextInput->SetForegroundColour(wxColor(255, 255, 255));

    wxButton* insertMetaTagButton = new wxButton(this, wxID_ANY, "Insert Meta Tag", wxPoint(80, 58), wxSize(100, 23));
    insertMetaTagButton->SetOwnForegroundColour(wxColor(30, 30, 30));

    wxStaticText* whereLabel = new wxStaticText(this, wxID_ANY, "Where:", wxPoint(30, 130));
    whereLabel->SetForegroundColour(wxColor(255, 255, 255));

    wxRadioButton* prefixBox = new wxRadioButton(this, wxID_ANY, "Prefix", wxPoint(80, 100), wxDefaultSize, wxRB_GROUP);
    prefixBox->SetOwnForegroundColour(wxColor(255, 255, 255));
    wxRadioButton* suffixBox = new wxRadioButton(this, wxID_ANY, "Suffix", wxPoint(80, 130));
    suffixBox->SetOwnForegroundColour(wxColor(255, 255, 255));
    wxRadioButton* positionBox = new wxRadioButton(this, wxID_ANY, "Position:", wxPoint(80, 160));
    positionBox->SetOwnForegroundColour(wxColor(255, 255, 255));
    wxRadioButton* afterBox = new wxRadioButton(this, wxID_ANY, "After Text:", wxPoint(80, 190));
    afterBox->SetOwnForegroundColour(wxColor(255, 255, 255));
    wxRadioButton* beforeBox = new wxRadioButton(this, wxID_ANY, "Before Text:", wxPoint(80, 220));
    beforeBox->SetOwnForegroundColour(wxColor(255, 255, 255));
    wxRadioButton* replaceBox = new wxRadioButton(this, wxID_ANY, "Replace current name:", wxPoint(80, 250));
    replaceBox->SetOwnForegroundColour(wxColor(255, 255, 255));

    wxCheckBox* skipExtentionCheckBox = new wxCheckBox(this, wxID_ANY, "Skip extention", wxPoint(80, 280));
    skipExtentionCheckBox->SetOwnForegroundColour(wxColor(255, 255, 255));

    wxSpinCtrl* positionEntryDialog = new wxSpinCtrl(this, wxID_ANY, "0", wxPoint(182, 156));
    positionEntryDialog->SetForegroundColour(wxColor(30, 30, 30));

    wxCheckBox* rightToLeftBox = new wxCheckBox(this, wxID_ANY, "Right-to-left", wxPoint(240, 160));
    rightToLeftBox->SetOwnForegroundColour(wxColor(255, 255, 255));

    wxTextCtrl* afterTextInput = new wxTextCtrl(this, wxID_ANY, "", wxPoint(180, 186), wxSize(140, 23), wxBORDER_SIMPLE);
    afterTextInput->SetBackgroundColour(wxColor(40, 40, 40));
    afterTextInput->SetForegroundColour(wxColor(255, 255, 255));

    wxTextCtrl* beforeTextInput = new wxTextCtrl(this, wxID_ANY, "", wxPoint(180, 216), wxSize(140, 23), wxBORDER_SIMPLE);
    beforeTextInput->SetBackgroundColour(wxColor(40, 40, 40));
    beforeTextInput->SetForegroundColour(wxColor(255, 255, 255));

    this->SetBackgroundColour(wxColor(30, 30, 30));
}

InsertWindow::~InsertWindow()
{
}

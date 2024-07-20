#pragma once
#include <wx/wx.h>

class App : public wxApp
{
public:
	bool OnInit() override;

};

wxIMPLEMENT_APP(App);

class MyFrame : public wxFrame {
public:
	MyFrame(const wxString& title, const wxPoint& pos, const wxSize& size);


private:
	wxTextCtrl* display;

	void OnButtonClicked(wxCommandEvent&);
	void CreateUI();
	void EvaluateExpression();

	wxDECLARE_EVENT_TABLE();
};


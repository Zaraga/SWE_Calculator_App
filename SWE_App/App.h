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
	MyFrame();
	MyFrame(const wxString& title, const wxPoint& pos, const wxSize& size);


	wxTextCtrl* display;
	void EvaluateExpression();

private:
	

	void OnButtonClicked(wxCommandEvent&);
	void CreateUI();
	

	wxDECLARE_EVENT_TABLE();
};


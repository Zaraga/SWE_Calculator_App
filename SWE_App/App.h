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

class Factory {
public:

	static wxButton* CreateButton(wxWindow* parent, int id, const wxString& label);

	static wxButton* CreateAddButton(wxWindow* parent);
	static wxButton* CreateSubtractButton(wxWindow* parent);
	static wxButton* CreateMultiplyButton(wxWindow* parent);
	static wxButton* CreateDivideButton(wxWindow* parent);
	static wxButton* CreateModButton(wxWindow* parent);
	static wxButton* CreateSinButton(wxWindow* parent);
	static wxButton* CreateCosButton(wxWindow* parent);
	static wxButton* CreateTanButton(wxWindow* parent);
	static wxButton* CreateEqualButton(wxWindow* parent);
	static wxButton* CreateClearButton(wxWindow* parent);
	static wxButton* CreateBackSpaceButton(wxWindow* parent);
	static wxButton* CreateDecimalButton(wxWindow* parent);
	static wxButton* CreateNegativeButton(wxWindow* parent);
	static wxButton* CreateNumberButton(wxWindow* parent, int number);	
	static wxButton* CreateOpenParentButton(wxWindow* parent);
	static wxButton* CreateClosedParentButton(wxWindow* parent);
};
#include "App.h"

enum {
	ID_buttonZero = 1,
	ID_buttonOne = 2,
	ID_buttonTwo = 3,
	ID_buttonThree =4,
	ID_buttonFour = 5,
	ID_buttonFive = 6,
	ID_buttonSix = 7,
	ID_buttonSeven = 8,
	ID_buttonEight = 9,
	ID_buttonNine = 10,
	ID_buttonNegPos = 11,
	ID_buttonDec = 12,
	ID_buttonMod = 13,
	ID_buttonCE = 14,
	ID_buttonClear = 15,
	ID_buttonBack = 16,
	ID_buttonDiv = 17,
	ID_buttonMulti = 18,
	ID_buttonMin = 19,
	ID_buttonPlus = 20,
	ID_buttonEquals = 21,
	ID_buttonSin = 22,
	ID_buttonCos = 23,
	ID_buttonTan = 24,
	ID_textCtrl = 25
};




MyFrame::MyFrame(const wxString& title, const wxPoint& pos, const wxSize& size)
	: wxFrame(NULL, wxID_ANY, title, pos, size) {
	SetMinSize(wxSize(300, 200));
	
	//(width, height)
	//number buttons and operations
	wxButton* button7 = new wxButton(this, ID_buttonSeven, "7", wxPoint(10, 310), wxSize(100,100));
	wxButton* button8 = new wxButton(this, ID_buttonEight, "8", wxPoint(110, 310), wxSize(100, 100));
	wxButton* button9 = new wxButton(this, ID_buttonNine, "9", wxPoint(210, 310), wxSize(100, 100));
	wxButton* button4 = new wxButton(this, ID_buttonFour, "4", wxPoint(10, 410), wxSize(100, 100));
	wxButton* button5 = new wxButton(this, ID_buttonFive, "5", wxPoint(110, 410), wxSize(100, 100));
	wxButton* button6 = new wxButton(this, ID_buttonSix, "6", wxPoint(210, 410), wxSize(100, 100));
	wxButton* button1 = new wxButton(this, ID_buttonOne, "1", wxPoint(10, 510), wxSize(100, 100));
	wxButton* button2 = new wxButton(this, ID_buttonTwo, "2", wxPoint(110, 510), wxSize(100, 100));
	wxButton* button3 = new wxButton(this, ID_buttonThree, "3", wxPoint(210, 510), wxSize(100, 100));
	wxButton* button0 = new wxButton(this, ID_buttonZero, "0", wxPoint(110, 610), wxSize(100, 100));
	wxButton* buttonNegPos = new wxButton(this, ID_buttonNegPos, "+/-", wxPoint(10, 610), wxSize(100, 100));
	wxButton* buttonDec = new wxButton(this, ID_buttonDec, ".", wxPoint(210, 610), wxSize(100, 100));
	wxButton* buttonMod = new wxButton(this, ID_buttonMod, "%", wxPoint(10, 210), wxSize(100, 100));
	wxButton* buttonCE = new wxButton(this, ID_buttonCE, "CE", wxPoint(110, 210), wxSize(100, 100));
	wxButton* buttonClear = new wxButton(this, ID_buttonClear, "C", wxPoint(210, 210), wxSize(100, 100));
	wxButton* buttonBack = new wxButton(this, ID_buttonBack, "<", wxPoint(310, 110), wxSize(100, 100));
	wxButton* buttonDiv = new wxButton(this, ID_buttonDiv, "/", wxPoint(310, 210), wxSize(100, 100));
	wxButton* buttonMulti = new wxButton(this, ID_buttonMulti, "X", wxPoint(310, 310), wxSize(100, 100));
	wxButton* buttonMin = new wxButton(this, ID_buttonMin, "-", wxPoint(310, 410), wxSize(100, 100));
	wxButton* buttonPlus = new wxButton(this, ID_buttonPlus, "+", wxPoint(310, 510), wxSize(100, 100));
	wxButton* buttonEquals = new wxButton(this, ID_buttonEquals, "=", wxPoint(310, 610), wxSize(100, 100));
	wxButton* buttonSin = new wxButton(this, ID_buttonSin, "Sin", wxPoint(10, 110), wxSize(100, 100));
	wxButton* buttonCos = new wxButton(this, ID_buttonCos, "Cos", wxPoint(110, 110), wxSize(100, 100));
	wxButton* buttonTan = new wxButton(this, ID_buttonTan, "Tan", wxPoint(210, 110), wxSize(100, 100));
	//textCtrol for outputs
	m_textCtrl = new wxTextCtrl(this, ID_textCtrl, "", wxPoint(10, 10), wxSize(400, 100));
}

bool App::OnInit() {
	MyFrame* frame = new MyFrame("Calculator", wxPoint(50, 50), wxSize(440, 750));
	frame->Show(true);
	return true;
}
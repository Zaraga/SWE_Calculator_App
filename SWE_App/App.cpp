#include "App.h"
#include <wx/tokenzr.h>
#include <cmath>
#include <vector>
#include <string>
#include <sstream>
#include <wx/regex.h>
#include <stack>
#include <stdexcept>

enum {
	ID_BUTTON_0 = 1000,
	ID_BUTTON_1,
	ID_BUTTON_2,
	ID_BUTTON_3,
	ID_BUTTON_4,
	ID_BUTTON_5,
	ID_BUTTON_6,
	ID_BUTTON_7,
	ID_BUTTON_8,
	ID_BUTTON_9,
	ID_BUTTON_ADD,
	ID_BUTTON_SUBTRACT,
	ID_BUTTON_MULTIPLY,
	ID_BUTTON_DIVIDE,
	ID_BUTTON_MOD,
	ID_BUTTON_SIN,
	ID_BUTTON_COS,
	ID_BUTTON_TAN,
	ID_BUTTON_EQUAL,
	ID_BUTTON_CLEAR,
	ID_BUTTON_BACKSPACE,
	ID_BUTTON_DECIMAL,
	ID_BUTTON_NEGATIVE
};

// Event table to map events to handler methods
wxBEGIN_EVENT_TABLE(MyFrame, wxFrame)
	EVT_BUTTON(ID_BUTTON_0, MyFrame::OnButtonClicked)
	EVT_BUTTON(ID_BUTTON_1, MyFrame::OnButtonClicked)
	EVT_BUTTON(ID_BUTTON_2, MyFrame::OnButtonClicked)
	EVT_BUTTON(ID_BUTTON_3, MyFrame::OnButtonClicked)
	EVT_BUTTON(ID_BUTTON_4, MyFrame::OnButtonClicked)
	EVT_BUTTON(ID_BUTTON_5, MyFrame::OnButtonClicked)
	EVT_BUTTON(ID_BUTTON_6, MyFrame::OnButtonClicked)
	EVT_BUTTON(ID_BUTTON_7, MyFrame::OnButtonClicked)
	EVT_BUTTON(ID_BUTTON_8, MyFrame::OnButtonClicked)
	EVT_BUTTON(ID_BUTTON_9, MyFrame::OnButtonClicked)
	EVT_BUTTON(ID_BUTTON_ADD, MyFrame::OnButtonClicked)
	EVT_BUTTON(ID_BUTTON_SUBTRACT, MyFrame::OnButtonClicked)
	EVT_BUTTON(ID_BUTTON_MULTIPLY, MyFrame::OnButtonClicked)
	EVT_BUTTON(ID_BUTTON_DIVIDE, MyFrame::OnButtonClicked)
	EVT_BUTTON(ID_BUTTON_MOD, MyFrame::OnButtonClicked)
	EVT_BUTTON(ID_BUTTON_SIN, MyFrame::OnButtonClicked)
	EVT_BUTTON(ID_BUTTON_COS, MyFrame::OnButtonClicked)
	EVT_BUTTON(ID_BUTTON_TAN, MyFrame::OnButtonClicked)
	EVT_BUTTON(ID_BUTTON_EQUAL, MyFrame::OnButtonClicked)
	EVT_BUTTON(ID_BUTTON_CLEAR, MyFrame::OnButtonClicked)
	EVT_BUTTON(ID_BUTTON_BACKSPACE, MyFrame::OnButtonClicked)
	EVT_BUTTON(ID_BUTTON_DECIMAL, MyFrame::OnButtonClicked)
	EVT_BUTTON(ID_BUTTON_NEGATIVE, MyFrame::OnButtonClicked)	
wxEND_EVENT_TABLE()


MyFrame::MyFrame(const wxString& title, const wxPoint& pos, const wxSize& size)
	: wxFrame(NULL, wxID_ANY, title, wxDefaultPosition, wxSize(300, 400)) {
	// Create the user interface
	CreateUI();
}

void MyFrame::CreateUI() {
	// Vertical box sizer for layout
	wxBoxSizer* vbox = new wxBoxSizer(wxVERTICAL);

	// Text control for display
	display = new wxTextCtrl(this, wxID_ANY, "", wxDefaultPosition, wxSize(-1, 50), wxTE_RIGHT);
	vbox->Add(display, 0, wxEXPAND | wxTOP | wxBOTTOM, 4);

	// Grid sizer for buttons
	wxGridSizer* grid = new wxGridSizer(6, 4, 3, 3); // 6 rows, 4 columns

	// Add buttons to the grid
	grid->Add(new wxButton(this, ID_BUTTON_7, "7"), 0, wxEXPAND);
	grid->Add(new wxButton(this, ID_BUTTON_8, "8"), 0, wxEXPAND);
	grid->Add(new wxButton(this, ID_BUTTON_9, "9"), 0, wxEXPAND);
	grid->Add(new wxButton(this, ID_BUTTON_ADD, "+"), 0, wxEXPAND);

	grid->Add(new wxButton(this, ID_BUTTON_4, "4"), 0, wxEXPAND);
	grid->Add(new wxButton(this, ID_BUTTON_5, "5"), 0, wxEXPAND);
	grid->Add(new wxButton(this, ID_BUTTON_6, "6"), 0, wxEXPAND);
	grid->Add(new wxButton(this, ID_BUTTON_SUBTRACT, "-"), 0, wxEXPAND);

	grid->Add(new wxButton(this, ID_BUTTON_1, "1"), 0, wxEXPAND);
	grid->Add(new wxButton(this, ID_BUTTON_2, "2"), 0, wxEXPAND);
	grid->Add(new wxButton(this, ID_BUTTON_3, "3"), 0, wxEXPAND);
	grid->Add(new wxButton(this, ID_BUTTON_MULTIPLY, "*"), 0, wxEXPAND);

	grid->Add(new wxButton(this, ID_BUTTON_0, "0"), 0, wxEXPAND);
	grid->Add(new wxButton(this, ID_BUTTON_DECIMAL, "."), 0, wxEXPAND);
	grid->Add(new wxButton(this, ID_BUTTON_EQUAL, "="), 0, wxEXPAND);
	grid->Add(new wxButton(this, ID_BUTTON_DIVIDE, "/"), 0, wxEXPAND);

	grid->Add(new wxButton(this, ID_BUTTON_SIN, "sin"), 0, wxEXPAND);
	grid->Add(new wxButton(this, ID_BUTTON_COS, "cos"), 0, wxEXPAND);
	grid->Add(new wxButton(this, ID_BUTTON_TAN, "tan"), 0, wxEXPAND);
	grid->Add(new wxButton(this, ID_BUTTON_MOD, "%"), 0, wxEXPAND);

	grid->Add(new wxButton(this, ID_BUTTON_NEGATIVE, "-/+"), 0, wxEXPAND);
	grid->Add(new wxButton(this, ID_BUTTON_CLEAR, "C"), 0, wxEXPAND);
	grid->Add(new wxButton(this, ID_BUTTON_BACKSPACE, "<"), 0, wxEXPAND);

	vbox->Add(grid, 1, wxEXPAND);
	SetSizer(vbox);
}

bool App::OnInit() {
	MyFrame* frame = new MyFrame("Calculator", wxPoint(50, 50), wxSize(440, 750));
	frame->Show(true);
	return true;
}

void MyFrame::OnButtonClicked(wxCommandEvent& event) {
	int id = event.GetId();
	wxString label = ((wxButton*)event.GetEventObject())->GetLabel();

	switch (id) {
		// Append number and operator button labels to the display
	case ID_BUTTON_0: case ID_BUTTON_1: case ID_BUTTON_2:
	case ID_BUTTON_3: case ID_BUTTON_4: case ID_BUTTON_5:
	case ID_BUTTON_6: case ID_BUTTON_7: case ID_BUTTON_8:
	case ID_BUTTON_9:
	case ID_BUTTON_ADD: case ID_BUTTON_MULTIPLY:
	case ID_BUTTON_DIVIDE: case ID_BUTTON_MOD: case ID_BUTTON_DECIMAL:
		display->AppendText(label);
		break;
		// Append unary operator labels to the display with a space
	case ID_BUTTON_SIN: case ID_BUTTON_COS: case ID_BUTTON_TAN:
		display->AppendText(label + " ");
		break;
		// Clear the display
	case ID_BUTTON_CLEAR:
		display->Clear();
		break;
		// Remove the last character from the display
	case ID_BUTTON_BACKSPACE: {
		wxString text = display->GetValue();
		if (!text.IsEmpty()) {
			text.RemoveLast();
			display->SetValue(text);
		}
		break;
	}
							// Evaluate the expression in the display
	case ID_BUTTON_EQUAL:
		EvaluateExpression();
		break;
	case ID_BUTTON_SUBTRACT:
		display->AppendText("-");
		break;
		// Append a negative sign to the display
	case ID_BUTTON_NEGATIVE:
		display->AppendText("-");
		break;
	default:
		break;
	}
}

// Method to evaluate the expression in the display
void MyFrame::EvaluateExpression() {
	wxString input = display->GetValue();
	std::stack<double> values;
	std::stack<wxString> operators;

	auto get_precedence = [](const wxString& op) {
		if (op == "+" || op == "-") return 1;
		if (op == "*" || op == "/" || op == "%") return 2;
		return 0;
		};

	auto apply_operator = [](double lhs, double rhs, const wxString& op) -> double {
		if (op == "+") return lhs + rhs;
		if (op == "-") return lhs - rhs;
		if (op == "*") return lhs * rhs;
		if (op == "/") {
			if (rhs == 0) throw std::runtime_error("Division by zero");
			return lhs / rhs;
		}
		if (op == "%") {
			if (rhs == 0) throw std::runtime_error("Modulo by zero");
			return static_cast<int>(lhs) % static_cast<int>(rhs);
		}
		return 0.0;
		};

	try {
		for (size_t i = 0; i < input.Length(); ++i) {
			wxChar ch = input[i];

			if (wxIsdigit(ch) || ch == '.') {
				size_t start = i;
				while (i < input.Length() && (wxIsdigit(input[i]) || input[i] == '.')) ++i;
				wxString numberStr = input.Mid(start, i - start);
				double number;
				if (!numberStr.ToDouble(&number)) throw std::runtime_error("Invalid number format");
				values.push(number);
				--i; // step back to process last character
			}
			else if (wxIsspace(ch)) {
				continue; // skip spaces
			}
			else {
				wxString op(1, ch);
				while (!operators.empty() && get_precedence(operators.top()) >= get_precedence(op)) {
					if (values.size() < 2) throw std::runtime_error("Invalid expression");
					double rhs = values.top(); values.pop();
					double lhs = values.top(); values.pop();
					values.push(apply_operator(lhs, rhs, operators.top()));
					operators.pop();
				}
				operators.push(op);
			}
		}

		while (!operators.empty()) {
			if (values.size() < 2) throw std::runtime_error("Invalid expression");
			double rhs = values.top(); values.pop();
			double lhs = values.top(); values.pop();
			values.push(apply_operator(lhs, rhs, operators.top()));
			operators.pop();
		}

		if (!values.empty()) {
			display->SetValue(wxString::Format(wxT("%g"), values.top()));
		}
		else {
			wxMessageBox("No valid input detected.", "Error", wxOK | wxICON_ERROR);
		}
	}
	catch (const std::runtime_error& e) {
		wxMessageBox(e.what(), "Error", wxOK | wxICON_ERROR);
	}
}

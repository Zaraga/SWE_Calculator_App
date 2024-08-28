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
	ID_BUTTON_NEGATIVE,
	ID_BUTTON_CLOSEDPARENT,
	ID_BUTTON_OPENPARENT
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
	EVT_BUTTON(ID_BUTTON_CLOSEDPARENT, MyFrame::OnButtonClicked)
	EVT_BUTTON(ID_BUTTON_OPENPARENT, MyFrame::OnButtonClicked)
wxEND_EVENT_TABLE()

MyFrame::MyFrame()
	: wxFrame(nullptr, wxID_ANY, "Default Title", wxDefaultPosition, wxSize(300, 400)) {
	// Initialize the UI for the frame
	CreateUI();
}


MyFrame::MyFrame(const wxString& title, const wxPoint& pos, const wxSize& size)
	: wxFrame(NULL, wxID_ANY, title, wxDefaultPosition, wxSize(300, 400)) {
	// Create the user interface
	CreateUI();
}

wxButton* Factory::CreateButton(wxWindow* parent, int id, const wxString& label) {
	return new wxButton(parent, id, label);
}

wxButton* Factory::CreateAddButton(wxWindow* parent) {
	return CreateButton(parent, ID_BUTTON_ADD, "+");
}

wxButton* Factory::CreateSubtractButton(wxWindow* parent) {
	return CreateButton(parent, ID_BUTTON_SUBTRACT, "-");
}

wxButton* Factory::CreateMultiplyButton(wxWindow* parent) {
	return CreateButton(parent, ID_BUTTON_MULTIPLY, "*");
}

wxButton* Factory::CreateDivideButton(wxWindow* parent) {
	return CreateButton(parent, ID_BUTTON_DIVIDE, "/");
}

wxButton* Factory::CreateModButton(wxWindow* parent) {
	return CreateButton(parent, ID_BUTTON_MOD, "%");
}

wxButton* Factory::CreateCosButton(wxWindow* parent) {
	return CreateButton(parent, ID_BUTTON_COS, "Cos");
}

wxButton* Factory::CreateSinButton(wxWindow* parent) {
	return CreateButton(parent, ID_BUTTON_SIN, "Sin");
}

wxButton* Factory::CreateTanButton(wxWindow* parent) {
	return CreateButton(parent, ID_BUTTON_TAN, "Tan");
}

wxButton* Factory::CreateOpenParentButton(wxWindow* parent) {
	return CreateButton(parent, ID_BUTTON_OPENPARENT, "(");
}

wxButton* Factory::CreateClosedParentButton(wxWindow* parent) {
	return CreateButton(parent, ID_BUTTON_CLOSEDPARENT, ")");
}

wxButton* Factory::CreateClearButton(wxWindow* parent) {
	return CreateButton(parent, ID_BUTTON_CLEAR, "C");
}

wxButton* Factory::CreateBackSpaceButton(wxWindow* parent) {
	return CreateButton(parent, ID_BUTTON_BACKSPACE, "<");
}

wxButton* Factory::CreateEqualButton(wxWindow* parent) {
	return CreateButton(parent, ID_BUTTON_EQUAL, "=");
}

wxButton* Factory::CreateDecimalButton(wxWindow* parent) {
	return CreateButton(parent, ID_BUTTON_DECIMAL, ".");
}

wxButton* Factory::CreateNegativeButton(wxWindow* parent) {
	return CreateButton(parent, ID_BUTTON_CLEAR, "-/+");
}

wxButton* Factory::CreateNumberButton(wxWindow* parent, int number) {
	return CreateButton(parent, ID_BUTTON_0 + number, std::to_string(number));
}

void MyFrame::CreateUI() {
	// Vertical box sizer for layout
	wxBoxSizer* vbox = new wxBoxSizer(wxVERTICAL);

	// Text control for display
	display = new wxTextCtrl(this, wxID_ANY, "", wxDefaultPosition, wxSize(-1, 50), wxTE_RIGHT);
	vbox->Add(display, 0, wxEXPAND | wxTOP | wxBOTTOM, 4);

	// Grid sizer for buttons
	wxGridSizer* grid = new wxGridSizer(7, 4, 3, 3); // 6 rows, 4 columns

	// Add buttons to the grid
	grid->Add(Factory::CreateNumberButton(this, 7), 0, wxEXPAND);
	grid->Add(Factory::CreateNumberButton(this, 8), 0, wxEXPAND);
	grid->Add(Factory::CreateNumberButton(this, 9), 0, wxEXPAND);
	grid->Add(Factory::CreateAddButton(this), 0, wxEXPAND);

	grid->Add(Factory::CreateNumberButton(this, 4), 0, wxEXPAND);
	grid->Add(Factory::CreateNumberButton(this, 5), 0, wxEXPAND);
	grid->Add(Factory::CreateNumberButton(this, 6), 0, wxEXPAND);
	grid->Add(Factory::CreateSubtractButton(this), 0, wxEXPAND);

	grid->Add(Factory::CreateNumberButton(this, 1), 0, wxEXPAND);
	grid->Add(Factory::CreateNumberButton(this, 2), 0, wxEXPAND);
	grid->Add(Factory::CreateNumberButton(this, 3), 0, wxEXPAND);
	grid->Add(Factory::CreateMultiplyButton(this), 0, wxEXPAND);

	grid->Add(Factory::CreateNumberButton(this, 0), 0, wxEXPAND);
	grid->Add(Factory::CreateDecimalButton(this), 0, wxEXPAND);
	grid->Add(Factory::CreateEqualButton(this), 0, wxEXPAND);
	grid->Add(Factory::CreateDivideButton(this), 0, wxEXPAND);

	grid->Add(Factory::CreateSinButton(this), 0, wxEXPAND);
	grid->Add(Factory::CreateCosButton(this), 0, wxEXPAND);
	grid->Add(Factory::CreateTanButton(this), 0, wxEXPAND);
	grid->Add(Factory::CreateModButton(this), 0, wxEXPAND);

	grid->Add(Factory::CreateNegativeButton(this), 0, wxEXPAND);
	grid->Add(Factory::CreateClearButton(this), 0, wxEXPAND);
	grid->Add(Factory::CreateBackSpaceButton(this), 0, wxEXPAND);
	grid->Add(Factory::CreateOpenParentButton(this), 0, wxEXPAND);

	grid->Add(Factory::CreateClosedParentButton(this), 0, wxEXPAND);

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
		display->AppendText(label);
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
	case ID_BUTTON_CLOSEDPARENT:
		display->AppendText(")");
		break;
	case ID_BUTTON_OPENPARENT:
		display->AppendText("(");
		break;
	default:
		break;
	}
}

void MyFrame::EvaluateExpression() {
	wxString input = display->GetValue();
	std::stack<double> values;
	std::stack<wxString> operators;

	auto get_precedence = [](const wxString& op) {
		if (op == "+" || op == "-") return 1;
		if (op == "*" || op == "/" || op == "%") return 2;
		if (op == "cos" || op == "sin" || op == "log") return 3; // Higher precedence for functions
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

	auto apply_function = [](double value, const wxString& func) -> double {
		if (func == "cos") return cos(value);
		if (func == "sin") return sin(value);
		if (func == "log") return log(value);
		throw std::runtime_error("Unknown function: " + std::string(func.mb_str()));
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
			else if (wxIsalpha(ch)) { // Detect function names (e.g., cos, sin, log)
				size_t start = i;
				while (i < input.Length() && wxIsalpha(input[i])) ++i;
				wxString funcStr = input.Mid(start, i - start);
				if (input[i] == '(') {
					size_t openBrackets = 1;
					size_t startExpression = ++i;
					while (i < input.Length() && openBrackets != 0) {
						if (input[i] == '(') ++openBrackets;
						if (input[i] == ')') --openBrackets;
						++i;
					}
					wxString funcArgument = input.Mid(startExpression, i - startExpression - 1); // Get the argument inside the parentheses

					// Allocate the temporary frame dynamically
					MyFrame* tempFrame = new MyFrame();
					tempFrame->display = new wxTextCtrl(tempFrame, wxID_ANY, funcArgument);
					tempFrame->EvaluateExpression(); // Recursively evaluate the argument

					double result;
					if (!tempFrame->display->GetValue().ToDouble(&result)) throw std::runtime_error("Error evaluating function argument");

					values.push(apply_function(result, funcStr)); // Apply the function to the result

					// Clean up: delete the temporary frame
					delete tempFrame;
				}
				else {
					throw std::runtime_error("Invalid function format");
				}
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
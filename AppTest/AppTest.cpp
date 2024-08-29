//#define _CRT_SECURE_NO_WARNINGS
#include "pch.h"
#include "CppUnitTest.h"
#include "App.h"
#include "App.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

// Specialization of ToString for wxString
namespace Microsoft {
    namespace VisualStudio {
        namespace CppUnitTestFramework {
            template<> inline std::wstring ToString<wxString>(const wxString& str) {
                return std::wstring(str.wc_str());
            }
        }
    }
}

namespace AppTest
{
    TEST_CLASS(FactoryTests)
    {
    public:

        TEST_METHOD(CreateAddButton_ShouldReturnValidButton_1)
        {
            wxApp::SetInstance(new wxApp());
            wxEntryStart(0, nullptr);
            wxTheApp->CallOnInit();

            wxFrame* parent = new wxFrame(nullptr, wxID_ANY, "Test Frame");
            wxButton* addButton = Factory::CreateAddButton(parent);

            Assert::IsNotNull(addButton);
            Assert::AreEqual(wxString("+"), addButton->GetLabel());

            delete addButton;
            delete parent;
            wxEntryCleanup();
        }

        TEST_METHOD(CreateSubtractButton_ShouldReturnValidButton_2)
        {
            wxApp::SetInstance(new wxApp());
            wxEntryStart(0, nullptr);
            wxTheApp->CallOnInit();

            wxFrame* parent = new wxFrame(nullptr, wxID_ANY, "Test Frame");
            wxButton* addButton = Factory::CreateSubtractButton(parent);

            Assert::IsNotNull(addButton);
            Assert::AreEqual(wxString("-"), addButton->GetLabel());

            delete addButton;
            delete parent;
            wxEntryCleanup();
        }

        TEST_METHOD(CreateMultiplyButton_ShouldReturnValidButton_3)
        {
            wxApp::SetInstance(new wxApp());
            wxEntryStart(0, nullptr);
            wxTheApp->CallOnInit();

            wxFrame* parent = new wxFrame(nullptr, wxID_ANY, "Test Frame");
            wxButton* addButton = Factory::CreateMultiplyButton(parent);

            Assert::IsNotNull(addButton);
            Assert::AreEqual(wxString("*"), addButton->GetLabel());

            delete addButton;
            delete parent;
            wxEntryCleanup();
        }

        TEST_METHOD(CreateDivideButton_ShouldReturnValidButton_4)
        {
            wxApp::SetInstance(new wxApp());
            wxEntryStart(0, nullptr);
            wxTheApp->CallOnInit();

            wxFrame* parent = new wxFrame(nullptr, wxID_ANY, "Test Frame");
            wxButton* addButton = Factory::CreateDivideButton(parent);

            Assert::IsNotNull(addButton);
            Assert::AreEqual(wxString("/"), addButton->GetLabel());

            delete addButton;
            delete parent;
            wxEntryCleanup();
        }

        TEST_METHOD(CreateSinButton_ShouldReturnValidButton_5)
        {
            wxApp::SetInstance(new wxApp());
            wxEntryStart(0, nullptr);
            wxTheApp->CallOnInit();

            wxFrame* parent = new wxFrame(nullptr, wxID_ANY, "Test Frame");
            wxButton* addButton = Factory::CreateSinButton(parent);

            Assert::IsNotNull(addButton);
            Assert::AreEqual(wxString("Sin"), addButton->GetLabel());

            delete addButton;
            delete parent;
            wxEntryCleanup();
        }

        TEST_METHOD(CreateModButton_ShouldReturnValidButton_6)
        {
            wxApp::SetInstance(new wxApp());
            wxEntryStart(0, nullptr);
            wxTheApp->CallOnInit();

            wxFrame* parent = new wxFrame(nullptr, wxID_ANY, "Test Frame");
            wxButton* addButton = Factory::CreateModButton(parent);

            Assert::IsNotNull(addButton);
            Assert::AreEqual(wxString("%"), addButton->GetLabel());

            delete addButton;
            delete parent;
            wxEntryCleanup();
        }

        TEST_METHOD(CreateCosButton_ShouldReturnValidButton_7)
        {
            wxApp::SetInstance(new wxApp());
            wxEntryStart(0, nullptr);
            wxTheApp->CallOnInit();

            wxFrame* parent = new wxFrame(nullptr, wxID_ANY, "Test Frame");
            wxButton* addButton = Factory::CreateCosButton(parent);

            Assert::IsNotNull(addButton);
            Assert::AreEqual(wxString("Cos"), addButton->GetLabel());

            delete addButton;
            delete parent;
            wxEntryCleanup();
        }

        TEST_METHOD(CreateTanButton_ShouldReturnValidButton_8)
        {
            wxApp::SetInstance(new wxApp());
            wxEntryStart(0, nullptr);
            wxTheApp->CallOnInit();

            wxFrame* parent = new wxFrame(nullptr, wxID_ANY, "Test Frame");
            wxButton* addButton = Factory::CreateTanButton(parent);

            Assert::IsNotNull(addButton);
            Assert::AreEqual(wxString("Tan"), addButton->GetLabel());

            delete addButton;
            delete parent;
            wxEntryCleanup();
        }

        TEST_METHOD(CreateOpenParentButton_ShouldReturnValidButton_9)
        {
            wxApp::SetInstance(new wxApp());
            wxEntryStart(0, nullptr);
            wxTheApp->CallOnInit();

            wxFrame* parent = new wxFrame(nullptr, wxID_ANY, "Test Frame");
            wxButton* addButton = Factory::CreateOpenParentButton(parent);

            Assert::IsNotNull(addButton);
            Assert::AreEqual(wxString("("), addButton->GetLabel());

            delete addButton;
            delete parent;
            wxEntryCleanup();
        }

        TEST_METHOD(CreateClosedParentButton_ShouldReturnValidButton_10)
        {
            wxApp::SetInstance(new wxApp());
            wxEntryStart(0, nullptr);
            wxTheApp->CallOnInit();

            wxFrame* parent = new wxFrame(nullptr, wxID_ANY, "Test Frame");
            wxButton* addButton = Factory::CreateClosedParentButton(parent);

            Assert::IsNotNull(addButton);
            Assert::AreEqual(wxString(")"), addButton->GetLabel());

            delete addButton;
            delete parent;
            wxEntryCleanup();
        }
    };

    TEST_CLASS(EvaluateExpressionTests)
    {
    public:

        TEST_METHOD(EvaluateExpression_ShouldReturnCorrectResult_Addition)
        {
            wxApp::SetInstance(new wxApp());
            wxEntryStart(0, nullptr);
            wxTheApp->CallOnInit();

            MyFrame* frame = new MyFrame();
            frame->display->SetValue("2+3");
            frame->EvaluateExpression();
            Assert::AreEqual(wxString("5"), frame->display->GetValue());

            delete frame;
            wxEntryCleanup();
        }

        TEST_METHOD(EvaluateExpression_ShouldReturnCorrectResult_Subtraction)
        {
            wxApp::SetInstance(new wxApp());
            wxEntryStart(0, nullptr);
            wxTheApp->CallOnInit();

            MyFrame* frame = new MyFrame();
            frame->display->SetValue("10-7");
            frame->EvaluateExpression();
            Assert::AreEqual(wxString("3"), frame->display->GetValue());

            delete frame;
            wxEntryCleanup();
        }

        TEST_METHOD(EvaluateExpression_ShouldReturnCorrectResult_Multiplication)
        {
            wxApp::SetInstance(new wxApp());
            wxEntryStart(0, nullptr);
            wxTheApp->CallOnInit();

            MyFrame* frame = new MyFrame();
            frame->display->SetValue("4*5");
            frame->EvaluateExpression();
            Assert::AreEqual(wxString("20"), frame->display->GetValue());

            delete frame;
            wxEntryCleanup();
        }

        TEST_METHOD(EvaluateExpression_ShouldReturnCorrectResult_Division)
        {
            wxApp::SetInstance(new wxApp());
            wxEntryStart(0, nullptr);
            wxTheApp->CallOnInit();

            MyFrame* frame = new MyFrame();
            frame->display->SetValue("20/4");
            frame->EvaluateExpression();
            Assert::AreEqual(wxString("5"), frame->display->GetValue());

            delete frame;
            wxEntryCleanup();
        }

        TEST_METHOD(EvaluateExpression_ShouldReturnCorrectResult_Modulus)
        {
            wxApp::SetInstance(new wxApp());
            wxEntryStart(0, nullptr);
            wxTheApp->CallOnInit();

            MyFrame* frame = new MyFrame();
            frame->display->SetValue("10%3");
            frame->EvaluateExpression();
            Assert::AreEqual(wxString("1"), frame->display->GetValue());

            delete frame;
            wxEntryCleanup();
        }

        TEST_METHOD(EvaluateExpression_ShouldReturnCorrectResult_SinFunction)
        {
            wxApp::SetInstance(new wxApp());
            wxEntryStart(0, nullptr);
            wxTheApp->CallOnInit();

            MyFrame* frame = new MyFrame();
            frame->display->SetValue("sin(0)");
            frame->EvaluateExpression();
            Assert::AreEqual(wxString("0"), frame->display->GetValue());

            delete frame;
            wxEntryCleanup();
        }

        TEST_METHOD(EvaluateExpression_ShouldReturnCorrectResult_CosFunction)
        {
            wxApp::SetInstance(new wxApp());
            wxEntryStart(0, nullptr);
            wxTheApp->CallOnInit();

            MyFrame* frame = new MyFrame();
            frame->display->SetValue("cos(0)");
            frame->EvaluateExpression();
            Assert::AreEqual(wxString("1"), frame->display->GetValue());

            delete frame;
            wxEntryCleanup();
        }

        TEST_METHOD(EvaluateExpression_ShouldReturnCorrectResult_ComplexExpression)
        {
            wxApp::SetInstance(new wxApp());
            wxEntryStart(0, nullptr);
            wxTheApp->CallOnInit();

            MyFrame* frame = new MyFrame();
            frame->display->SetValue("2+3*4-5/2");
            frame->EvaluateExpression();
            Assert::AreEqual(wxString("11.5"), frame->display->GetValue());

            delete frame;
            wxEntryCleanup();
        }

        TEST_METHOD(EvaluateExpression_ShouldReturnCorrectResult_ComplexExpression2)
        {
            wxApp::SetInstance(new wxApp());
            wxEntryStart(0, nullptr);
            wxTheApp->CallOnInit();

            MyFrame* frame = new MyFrame();
            frame->display->SetValue("2+3*4-1");
            frame->EvaluateExpression();
            Assert::AreEqual(wxString("13"), frame->display->GetValue());

            delete frame;
            wxEntryCleanup();
        }

        TEST_METHOD(EvaluateExpression_ShouldHandleDivisionByZero)
        {
            wxApp::SetInstance(new wxApp());
            wxEntryStart(0, nullptr);
            wxTheApp->CallOnInit();

            MyFrame* frame = new MyFrame();
            frame->display->SetValue("10/0");

            bool exceptionCaught = true;
            try {
                frame->EvaluateExpression();
            }
            catch (const std::runtime_error& e) {
                exceptionCaught = true;
                std::wstring actualMessage = std::wstring(e.what(), e.what() + strlen(e.what()));
                Logger::WriteMessage(actualMessage.c_str());  // Log the actual message
                Assert::AreEqual(std::wstring(L"Division by zero"), actualMessage);
            }
            Assert::IsTrue(exceptionCaught, L"Expected division by zero exception not thrown");

            delete frame;
            wxEntryCleanup();
        }
    };


}





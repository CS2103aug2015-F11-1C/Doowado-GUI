#pragma once


#include <vector>
#include <algorithm>
#include <string>
#include <sstream>
#include "msclr\marshal_cppstd.h"
#include "DisplayController.h"

namespace DoowadoGUI {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	DisplayController* Controller;

	/// <summary>
	/// Summary for GUI
	/// </summary>
	public ref class GUI : public MetroFramework::Forms::MetroForm {
	public:
		GUI(void)
		{
			InitializeComponent();
			this->ActiveControl = inputBox;
			//initializing program
			Controller = new DisplayController;
			Controller->initialiseProgram();
			getListofEvents();
			getListofTasks();
		}
		 
	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~GUI()
		{
			if (components)
			{
				delete components;
			}
		}

	private: System::Windows::Forms::ListView^  EventListDisplay;
	private: System::Windows::Forms::ListViewItem^ NewListViewItem;
	private: System::Windows::Forms::ColumnHeader^  EventID;
	private: System::Windows::Forms::ColumnHeader^  EventName;
	private: System::Windows::Forms::ColumnHeader^  StartDate;
	private: System::Windows::Forms::ColumnHeader^  StartTime;
	private: System::Windows::Forms::ColumnHeader^  EndDate;
	private: System::Windows::Forms::ColumnHeader^  EndTime;


	private: System::Windows::Forms::ListView^  TaskListDisplay;
	private: System::Windows::Forms::ColumnHeader^  TaskID;
	private: System::Windows::Forms::ColumnHeader^  TaskDescription;
	private: System::Windows::Forms::ColumnHeader^  DueDate;
	private: System::Windows::Forms::ColumnHeader^  DueTime;
	private: MetroFramework::Controls::MetroLabel^  EventListLabel;
	private: MetroFramework::Controls::MetroLabel^  TaskListLabel;



	private: MetroFramework::Controls::MetroTextBox^  inputBox;
	private: MetroFramework::Controls::MetroLabel^  feedbackLabel;
	private: MetroFramework::Controls::MetroTextBox^  FeedbackDisplay;


	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->EventListDisplay = (gcnew System::Windows::Forms::ListView());
			this->EventID = (gcnew System::Windows::Forms::ColumnHeader());
			this->EventName = (gcnew System::Windows::Forms::ColumnHeader());
			this->StartDate = (gcnew System::Windows::Forms::ColumnHeader());
			this->StartTime = (gcnew System::Windows::Forms::ColumnHeader());
			this->EndDate = (gcnew System::Windows::Forms::ColumnHeader());
			this->EndTime = (gcnew System::Windows::Forms::ColumnHeader());
			this->TaskListDisplay = (gcnew System::Windows::Forms::ListView());
			this->TaskID = (gcnew System::Windows::Forms::ColumnHeader());
			this->TaskDescription = (gcnew System::Windows::Forms::ColumnHeader());
			this->DueDate = (gcnew System::Windows::Forms::ColumnHeader());
			this->DueTime = (gcnew System::Windows::Forms::ColumnHeader());
			this->EventListLabel = (gcnew MetroFramework::Controls::MetroLabel());
			this->TaskListLabel = (gcnew MetroFramework::Controls::MetroLabel());
			this->inputBox = (gcnew MetroFramework::Controls::MetroTextBox());
			this->feedbackLabel = (gcnew MetroFramework::Controls::MetroLabel());
			this->FeedbackDisplay = (gcnew MetroFramework::Controls::MetroTextBox());
			this->SuspendLayout();
			// 
			// EventListDisplay
			// 
			this->EventListDisplay->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->EventListDisplay->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->EventListDisplay->Columns->AddRange(gcnew cli::array< System::Windows::Forms::ColumnHeader^  >(6) {
				this->EventID, this->EventName,
					this->StartDate, this->StartTime, this->EndDate, this->EndTime
			});
			this->EventListDisplay->Location = System::Drawing::Point(12, 80);
			this->EventListDisplay->Name = L"EventListDisplay";
			this->EventListDisplay->Size = System::Drawing::Size(560, 287);
			this->EventListDisplay->TabIndex = 3;
			this->EventListDisplay->TabStop = false;
			this->EventListDisplay->UseCompatibleStateImageBehavior = false;
			this->EventListDisplay->View = System::Windows::Forms::View::Details;
			this->EventListDisplay->KeyDown += gcnew System::Windows::Forms::KeyEventHandler(this, &GUI::generalForm_KeyDown);
			this->EventListDisplay->KeyPress += gcnew System::Windows::Forms::KeyPressEventHandler(this, &GUI::generalForm_KeyPress);
			// 
			// EventID
			// 
			this->EventID->Text = L"ID.";
			this->EventID->Width = 30;
			// 
			// EventName
			// 
			this->EventName->Text = L"Event Description";
			this->EventName->Width = 200;
			// 
			// StartDate
			// 
			this->StartDate->Text = L"Start Date";
			this->StartDate->Width = 90;
			// 
			// StartTime
			// 
			this->StartTime->Text = L"Start Time";
			this->StartTime->Width = 75;
			// 
			// EndDate
			// 
			this->EndDate->Text = L"End Date";
			this->EndDate->Width = 90;
			// 
			// EndTime
			// 
			this->EndTime->Text = L"End Time";
			this->EndTime->Width = 75;
			// 
			// TaskListDisplay
			// 
			this->TaskListDisplay->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->TaskListDisplay->Columns->AddRange(gcnew cli::array< System::Windows::Forms::ColumnHeader^  >(4) {
				this->TaskID, this->TaskDescription,
					this->DueDate, this->DueTime
			});
			this->TaskListDisplay->Location = System::Drawing::Point(578, 80);
			this->TaskListDisplay->Name = L"TaskListDisplay";
			this->TaskListDisplay->Size = System::Drawing::Size(405, 287);
			this->TaskListDisplay->TabIndex = 14;
			this->TaskListDisplay->TabStop = false;
			this->TaskListDisplay->UseCompatibleStateImageBehavior = false;
			this->TaskListDisplay->View = System::Windows::Forms::View::Details;
			this->TaskListDisplay->KeyDown += gcnew System::Windows::Forms::KeyEventHandler(this, &GUI::generalForm_KeyDown);
			this->TaskListDisplay->KeyPress += gcnew System::Windows::Forms::KeyPressEventHandler(this, &GUI::generalForm_KeyPress);
			// 
			// TaskID
			// 
			this->TaskID->Text = L"ID.";
			this->TaskID->Width = 30;
			// 
			// TaskDescription
			// 
			this->TaskDescription->Text = L"Task Description";
			this->TaskDescription->Width = 200;
			// 
			// DueDate
			// 
			this->DueDate->Text = L"Due Date";
			this->DueDate->Width = 85;
			// 
			// DueTime
			// 
			this->DueTime->Text = L"Due Time";
			this->DueTime->Width = 75;
			// 
			// EventListLabel
			// 
			this->EventListLabel->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->EventListLabel->AutoSize = true;
			this->EventListLabel->FontWeight = MetroFramework::MetroLabelWeight::Bold;
			this->EventListLabel->Location = System::Drawing::Point(12, 58);
			this->EventListLabel->Name = L"EventListLabel";
			this->EventListLabel->Size = System::Drawing::Size(281, 19);
			this->EventListLabel->Style = MetroFramework::MetroColorStyle::Blue;
			this->EventListLabel->TabIndex = 16;
			this->EventListLabel->Text = L"These are the events you have for today:";
			this->EventListLabel->UseCustomBackColor = true;
			this->EventListLabel->UseCustomForeColor = true;
			this->EventListLabel->UseStyleColors = true;
			// 
			// TaskListLabel
			// 
			this->TaskListLabel->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->TaskListLabel->AutoSize = true;
			this->TaskListLabel->FontWeight = MetroFramework::MetroLabelWeight::Bold;
			this->TaskListLabel->Location = System::Drawing::Point(578, 58);
			this->TaskListLabel->Name = L"TaskListLabel";
			this->TaskListLabel->Size = System::Drawing::Size(208, 19);
			this->TaskListLabel->TabIndex = 17;
			this->TaskListLabel->Text = L"These are your pending tasks:";
			this->TaskListLabel->UseCustomBackColor = true;
			this->TaskListLabel->UseCustomForeColor = true;
			this->TaskListLabel->UseStyleColors = true;
			// 
			// inputBox
			// 
			this->inputBox->Anchor = System::Windows::Forms::AnchorStyles::None;
			// 
			// 
			// 
			this->inputBox->CustomButton->Image = nullptr;
			this->inputBox->CustomButton->Location = System::Drawing::Point(949, 1);
			this->inputBox->CustomButton->Name = L"";
			this->inputBox->CustomButton->Size = System::Drawing::Size(21, 21);
			this->inputBox->CustomButton->Style = MetroFramework::MetroColorStyle::Blue;
			this->inputBox->CustomButton->TabIndex = 1;
			this->inputBox->CustomButton->Theme = MetroFramework::MetroThemeStyle::Light;
			this->inputBox->CustomButton->UseSelectable = true;
			this->inputBox->CustomButton->Visible = false;
			this->inputBox->Lines = gcnew cli::array< System::String^  >(1) { L"Enter Command Here" };
			this->inputBox->Location = System::Drawing::Point(12, 418);
			this->inputBox->MaxLength = 32767;
			this->inputBox->Name = L"inputBox";
			this->inputBox->PasswordChar = '\0';
			this->inputBox->ScrollBars = System::Windows::Forms::ScrollBars::None;
			this->inputBox->SelectedText = L"";
			this->inputBox->SelectionLength = 0;
			this->inputBox->SelectionStart = 0;
			this->inputBox->Size = System::Drawing::Size(971, 23);
			this->inputBox->TabIndex = 1;
			this->inputBox->Text = L"Enter Command Here";
			this->inputBox->UseSelectable = true;
			this->inputBox->WaterMarkColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(109)), static_cast<System::Int32>(static_cast<System::Byte>(109)),
				static_cast<System::Int32>(static_cast<System::Byte>(109)));
			this->inputBox->WaterMarkFont = (gcnew System::Drawing::Font(L"Segoe UI", 12, System::Drawing::FontStyle::Italic, System::Drawing::GraphicsUnit::Pixel));
			this->inputBox->TextChanged += gcnew System::EventHandler(this, &GUI::inputBox_TextChanged);
			this->inputBox->DoubleClick += gcnew System::EventHandler(this, &GUI::inputBox_DoubleClick);
			this->inputBox->Enter += gcnew System::EventHandler(this, &GUI::inputBox_Enter);
			this->inputBox->KeyDown += gcnew System::Windows::Forms::KeyEventHandler(this, &GUI::inputBox_KeyDown);
			this->inputBox->Leave += gcnew System::EventHandler(this, &GUI::inputBox_Leave);
			// 
			// feedbackLabel
			// 
			this->feedbackLabel->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->feedbackLabel->AutoSize = true;
			this->feedbackLabel->FontSize = MetroFramework::MetroLabelSize::Small;
			this->feedbackLabel->FontWeight = MetroFramework::MetroLabelWeight::Regular;
			this->feedbackLabel->ForeColor = System::Drawing::SystemColors::ControlDarkDark;
			this->feedbackLabel->Location = System::Drawing::Point(12, 400);
			this->feedbackLabel->Name = L"feedbackLabel";
			this->feedbackLabel->Size = System::Drawing::Size(258, 15);
			this->feedbackLabel->Style = MetroFramework::MetroColorStyle::Orange;
			this->feedbackLabel->TabIndex = 19;
			this->feedbackLabel->Text = L"add / edit / show / search / delete / undo / save";
			this->feedbackLabel->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			this->feedbackLabel->Theme = MetroFramework::MetroThemeStyle::Light;
			this->feedbackLabel->UseCustomBackColor = true;
			this->feedbackLabel->UseCustomForeColor = true;
			this->feedbackLabel->UseStyleColors = true;
			// 
			// FeedbackDisplay
			// 
			this->FeedbackDisplay->Anchor = System::Windows::Forms::AnchorStyles::None;
			// 
			// 
			// 
			this->FeedbackDisplay->CustomButton->Image = nullptr;
			this->FeedbackDisplay->CustomButton->Location = System::Drawing::Point(949, 2);
			this->FeedbackDisplay->CustomButton->Name = L"";
			this->FeedbackDisplay->CustomButton->Size = System::Drawing::Size(19, 19);
			this->FeedbackDisplay->CustomButton->Style = MetroFramework::MetroColorStyle::Blue;
			this->FeedbackDisplay->CustomButton->TabIndex = 1;
			this->FeedbackDisplay->CustomButton->Theme = MetroFramework::MetroThemeStyle::Light;
			this->FeedbackDisplay->CustomButton->UseSelectable = true;
			this->FeedbackDisplay->CustomButton->Visible = false;
			this->FeedbackDisplay->Lines = gcnew cli::array< System::String^  >(0);
			this->FeedbackDisplay->Location = System::Drawing::Point(12, 373);
			this->FeedbackDisplay->MaxLength = 32767;
			this->FeedbackDisplay->Multiline = true;
			this->FeedbackDisplay->Name = L"FeedbackDisplay";
			this->FeedbackDisplay->PasswordChar = '\0';
			this->FeedbackDisplay->ReadOnly = true;
			this->FeedbackDisplay->ScrollBars = System::Windows::Forms::ScrollBars::Vertical;
			this->FeedbackDisplay->SelectedText = L"";
			this->FeedbackDisplay->SelectionLength = 0;
			this->FeedbackDisplay->SelectionStart = 0;
			this->FeedbackDisplay->Size = System::Drawing::Size(971, 24);
			this->FeedbackDisplay->Style = MetroFramework::MetroColorStyle::Black;
			this->FeedbackDisplay->TabIndex = 2;
			this->FeedbackDisplay->UseSelectable = true;
			this->FeedbackDisplay->WaterMarkColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(109)),
				static_cast<System::Int32>(static_cast<System::Byte>(109)), static_cast<System::Int32>(static_cast<System::Byte>(109)));
			this->FeedbackDisplay->WaterMarkFont = (gcnew System::Drawing::Font(L"Segoe UI", 12, System::Drawing::FontStyle::Italic, System::Drawing::GraphicsUnit::Pixel));
			this->FeedbackDisplay->KeyDown += gcnew System::Windows::Forms::KeyEventHandler(this, &GUI::generalForm_KeyDown);
			this->FeedbackDisplay->KeyPress += gcnew System::Windows::Forms::KeyPressEventHandler(this, &GUI::generalForm_KeyPress);
			// 
			// GUI
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(7, 15);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->AutoSize = true;
			this->AutoValidate = System::Windows::Forms::AutoValidate::EnablePreventFocusChange;
			this->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->CausesValidation = false;
			this->ClientSize = System::Drawing::Size(995, 451);
			this->Controls->Add(this->FeedbackDisplay);
			this->Controls->Add(this->feedbackLabel);
			this->Controls->Add(this->inputBox);
			this->Controls->Add(this->TaskListLabel);
			this->Controls->Add(this->EventListLabel);
			this->Controls->Add(this->TaskListDisplay);
			this->Controls->Add(this->EventListDisplay);
			this->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->ForeColor = System::Drawing::SystemColors::Highlight;
			this->HelpButton = true;
			this->MaximizeBox = false;
			this->Name = L"GUI";
			this->Resizable = false;
			this->Style = MetroFramework::MetroColorStyle::Default;
			this->Text = L"Welcome to Doowado";
			this->KeyDown += gcnew System::Windows::Forms::KeyEventHandler(this, &GUI::generalForm_KeyDown);
			this->KeyPress += gcnew System::Windows::Forms::KeyPressEventHandler(this, &GUI::generalForm_KeyPress);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion

	private:
		System::Void inputBox_KeyDown(System::Object^  sender, System::Windows::Forms::KeyEventArgs^  e) {
			if (e->KeyCode == Keys::Enter) {
					String^ inputText = inputBox->Text;

					checkExit(inputText);

					Controller->processInput(inputText);

					EventListDisplay->Items->Clear();
					getListofEvents();

					TaskListDisplay->Items->Clear();
					getListofTasks();

					getFeedbackList();

					inputBox->Clear();

					this->ActiveControl = FeedbackDisplay;

					e->Handled = true;
			}
			
			// Minimize via Ctrl + W
			else if (e->KeyData == (Keys::Control | Keys::W)) {
				if (WindowState == FormWindowState::Normal) {
					WindowState = FormWindowState::Minimized;
				}
				else {
					WindowState = FormWindowState::Normal;
				}
			}
			
			// Exit via Ctrl + Q
			else if (e->KeyData == (Keys::Control | Keys::Q)) {
				MetroFramework::MetroMessageBox::Show(this, "Good Bye!", "Exiting the Application:", MessageBoxButtons::OK, MessageBoxIcon::Information);
				Application::Exit();
			}

			// Undo via Ctrl + Z
			else if (e->KeyData == (Keys::Control | Keys::Z)) {
				Controller->processInput("undo");
			}

			// Redo via Ctrl + R
			else if (e->KeyData == (Keys::Control | Keys::R)) {
				Controller->processInput("redo");
			}

			e->Handled = true;
		}

	private:
		
		System::Void generalForm_KeyDown(System::Object^  sender, System::Windows::Forms::KeyEventArgs^  e) {
			// Minimize via Ctrl + W
			if (e->KeyData == (Keys::Control | Keys::W)) {
				WindowState = FormWindowState::Minimized;
			}

			// Exit via Ctrl + Q
			else if (e->KeyData == (Keys::Control | Keys::Q)) {
				MetroFramework::MetroMessageBox::Show(this, "Good Bye!", "Exiting the Application:", MessageBoxButtons::OK, MessageBoxIcon::Information);
				Application::Exit();
			}

			// Undo via Ctrl + Z
			else if (e->KeyData == (Keys::Control | Keys::Z)) {
				Controller->processInput("undo");
			}

			// Redo via Ctrl + R
			else if (e->KeyData == (Keys::Control | Keys::R)) {
				Controller->processInput("redo");
			}
			else {
				inputBox->Text = gcnew System::String(to_string(e->KeyValue).c_str());
				this->ActiveControl = inputBox;
			}
		}

		System::Void generalForm_KeyPress(System::Object^  sender, System::Windows::Forms::KeyPressEventArgs^  e) {
			if (e->KeyChar == (char)13 || e->KeyChar == (char)8) {
				this->ActiveControl = inputBox;
			}
			else {
				inputBox->Text = e->KeyChar.ToString();
				this->ActiveControl = inputBox;
				inputBox->SelectionStart = inputBox->Text->Length;
			}
		}

		System::Void getListofEvents() {
			for (int i = 0; i < Controller->getEventListSize(); i++) {
				NewListViewItem = Controller->retrieveEventFromList(i);

				EventListDisplay->Items->Add(this->NewListViewItem);
			}
		}

		System::Void getListofTasks() {
			for (int i = 0; i < Controller->getTaskListSize(); i++) {
				NewListViewItem = Controller->retrieveTaskFromList(i);

				TaskListDisplay->Items->Add(this->NewListViewItem);
			}
		}

		System::Void getFeedbackList() {
			FeedbackDisplay->AppendText("\r\n" + Controller->retrieveLastFeedback() + "\r\n");
		}
		
		System::Void checkExit(System::String^ input) {
			if (input == "exit") {
				MetroFramework::MetroMessageBox::Show(this, "Good Bye!", "Exiting the Application:", MessageBoxButtons::OK, MessageBoxIcon::Information);
				Application::Exit();
			}
		}

	private:
		System::Void inputBox_TextChanged(System::Object^ sender, System::EventArgs^ e) {
			if (inputBox->Text == "add") {
				feedbackLabel->Text = "add <Entry name> on <DD/MM/YYYY or day> from <start time> to <end time>";
			}
			else if (inputBox->Text == "edit") {
				feedbackLabel->Text = "edit <index> <what to change>";
			}
			else if (inputBox->Text == "show") {
				feedbackLabel->Text = "show <date / day>";
			}
			else if (inputBox->Text == "delete") {
				feedbackLabel->Text = "delete <index>";
			}
			else if (inputBox->Text == "undo") {
				feedbackLabel->Text = "undo";
			}
			else if (inputBox->Text == "search") {
				feedbackLabel->Text == "search <keyword>";
			}
			else if (inputBox->Text == ""){
				feedbackLabel->Text = "add / edit / show / search / delete / undo / save";
			}
		}

	private: 
		System::Void inputBox_DoubleClick(System::Object^  sender, System::EventArgs^  e) {
			this->inputBox->Clear();
		}

	private: 
		System::Void inputBox_Enter(System::Object^  sender, System::EventArgs^  e) {
			this->inputBox->Clear();
		}
	
	private: 
		System::Void inputBox_Leave(System::Object^  sender, System::EventArgs^  e) {
			this->inputBox->Text = "Enter Command Here";
		}
};
}
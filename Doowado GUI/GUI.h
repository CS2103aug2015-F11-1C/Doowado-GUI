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
	public ref class GUI : public System::Windows::Forms::Form {
	public:
		GUI(void)
		{
			InitializeComponent();
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
	private: System::Windows::Forms::TextBox^  inputBox;
	private: System::Windows::Forms::Label^  label1;
	private: System::Windows::Forms::TextBox^  FeedbackDisplay;
	private: System::Windows::Forms::ListView^  EventListDisplay;
	private: System::Windows::Forms::ListViewItem^ NewListViewItem;
	private: System::Windows::Forms::ColumnHeader^  EventID;
	private: System::Windows::Forms::ColumnHeader^  EventName;
	private: System::Windows::Forms::ColumnHeader^  StartDate;
	private: System::Windows::Forms::ColumnHeader^  StartTime;
	private: System::Windows::Forms::ColumnHeader^  EndDate;
	private: System::Windows::Forms::ColumnHeader^  EndTime;
	private: System::Windows::Forms::Label^  label2;
	private: System::Windows::Forms::DateTimePicker^  todayDateTime;
	private: System::Windows::Forms::ListView^  TaskListDisplay;
	private: System::Windows::Forms::ColumnHeader^  TaskID;
	private: System::Windows::Forms::ColumnHeader^  TaskDescription;
	private: System::Windows::Forms::ColumnHeader^  DueDate;
	private: System::Windows::Forms::ColumnHeader^  DueTime;
	private: System::Windows::Forms::Label^  feedbackLabel;


	protected:


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
			this->inputBox = (gcnew System::Windows::Forms::TextBox());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->FeedbackDisplay = (gcnew System::Windows::Forms::TextBox());
			this->EventListDisplay = (gcnew System::Windows::Forms::ListView());
			this->EventID = (gcnew System::Windows::Forms::ColumnHeader());
			this->EventName = (gcnew System::Windows::Forms::ColumnHeader());
			this->StartDate = (gcnew System::Windows::Forms::ColumnHeader());
			this->StartTime = (gcnew System::Windows::Forms::ColumnHeader());
			this->EndDate = (gcnew System::Windows::Forms::ColumnHeader());
			this->EndTime = (gcnew System::Windows::Forms::ColumnHeader());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->todayDateTime = (gcnew System::Windows::Forms::DateTimePicker());
			this->TaskListDisplay = (gcnew System::Windows::Forms::ListView());
			this->TaskID = (gcnew System::Windows::Forms::ColumnHeader());
			this->TaskDescription = (gcnew System::Windows::Forms::ColumnHeader());
			this->DueDate = (gcnew System::Windows::Forms::ColumnHeader());
			this->DueTime = (gcnew System::Windows::Forms::ColumnHeader());
			this->feedbackLabel = (gcnew System::Windows::Forms::Label());
			this->SuspendLayout();
			// 
			// inputBox
			// 
			this->inputBox->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Bottom | System::Windows::Forms::AnchorStyles::Right));
			this->inputBox->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->inputBox->Location = System::Drawing::Point(161, 660);
			this->inputBox->Multiline = true;
			this->inputBox->Name = L"inputBox";
			this->inputBox->Size = System::Drawing::Size(947, 21);
			this->inputBox->TabIndex = 0;
			this->inputBox->Text = L"Enter Command Here";
			this->inputBox->TextChanged += gcnew System::EventHandler(this, &GUI::inputBox_TextChanged);
			this->inputBox->DoubleClick += gcnew System::EventHandler(this, &GUI::inputBox_DoubleClick);
			this->inputBox->Enter += gcnew System::EventHandler(this, &GUI::inputBox_Enter);
			this->inputBox->KeyDown += gcnew System::Windows::Forms::KeyEventHandler(this, &GUI::inputBox_KeyDown);
			this->inputBox->Leave += gcnew System::EventHandler(this, &GUI::inputBox_Leave);
			this->inputBox->TabIndex = 1;
			// 
			// label1
			// 
			this->label1->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Bottom | System::Windows::Forms::AnchorStyles::Left));
			this->label1->BackColor = System::Drawing::Color::Maroon;
			this->label1->Font = (gcnew System::Drawing::Font(L"Century Gothic", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label1->Location = System::Drawing::Point(12, 639);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(143, 42);
			this->label1->TabIndex = 1;
			this->label1->Text = L"INPUT COMMAND";
			this->label1->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			this->label1->TabStop = false;
			// 
			// FeedbackDisplay
			// 
			this->FeedbackDisplay->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Left | System::Windows::Forms::AnchorStyles::Right));
			this->FeedbackDisplay->BackColor = System::Drawing::Color::White;
			this->FeedbackDisplay->ForeColor = System::Drawing::SystemColors::WindowText;
			this->FeedbackDisplay->Location = System::Drawing::Point(12, 529);
			this->FeedbackDisplay->Multiline = true;
			this->FeedbackDisplay->Name = L"FeedbackDisplay";
			this->FeedbackDisplay->ReadOnly = true;
			this->FeedbackDisplay->ScrollBars = System::Windows::Forms::ScrollBars::Vertical;
			this->FeedbackDisplay->Size = System::Drawing::Size(1096, 104);
			this->FeedbackDisplay->TabIndex = 5;
			this->FeedbackDisplay->Text = L"";
			this->FeedbackDisplay->TabIndex = 2;
			this->FeedbackDisplay->KeyDown += gcnew System::Windows::Forms::KeyEventHandler(this, &GUI::inputBox_KeyDown);

			// 
			// EventListDisplay
			// 
			this->EventListDisplay->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->EventListDisplay->Columns->AddRange(gcnew cli::array< System::Windows::Forms::ColumnHeader^  >(6) {
				this->EventID, this->EventName,
					this->StartDate, this->StartTime, this->EndDate, this->EndTime
			});
			this->EventListDisplay->Location = System::Drawing::Point(12, 12);
			this->EventListDisplay->Name = L"EventListDisplay";
			this->EventListDisplay->Size = System::Drawing::Size(660, 511);
			this->EventListDisplay->TabIndex = 3;
			this->EventListDisplay->UseCompatibleStateImageBehavior = false;
			this->EventListDisplay->View = System::Windows::Forms::View::Details;
			this->EventListDisplay->TabStop = false;
			this->EventListDisplay->KeyDown += gcnew System::Windows::Forms::KeyEventHandler(this, &GUI::inputBox_KeyDown);

			// 
			// EventID
			// 
			this->EventID->Text = L"ID.";
			this->EventID->Width = 30;
			// 
			// EventName
			// 
			this->EventName->Text = L"Event Description";
			this->EventName->Width = 300;
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
			// label2
			// 
			this->label2->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Right));
			this->label2->AutoSize = true;
			this->label2->BackColor = System::Drawing::Color::Transparent;
			this->label2->Font = (gcnew System::Drawing::Font(L"Elephant", 24, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label2->ForeColor = System::Drawing::Color::Firebrick;
			this->label2->Location = System::Drawing::Point(718, 12);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(361, 41);
			this->label2->TabIndex = 12;
			this->label2->Text = L"Welcome to Doowado";
			this->label2->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			this->label2->TabStop = false;
			// 
			// todayDateTime
			// 
			this->todayDateTime->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Left | System::Windows::Forms::AnchorStyles::Right));
			this->todayDateTime->CalendarFont = (gcnew System::Drawing::Font(L"Calibri", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->todayDateTime->CustomFormat = L"dddd, dd MMMM yyyy";
			this->todayDateTime->Font = (gcnew System::Drawing::Font(L"Calibri", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->todayDateTime->Format = System::Windows::Forms::DateTimePickerFormat::Custom;
			this->todayDateTime->Location = System::Drawing::Point(777, 71);
			this->todayDateTime->Name = L"todayDateTime";
			this->todayDateTime->Size = System::Drawing::Size(248, 27);
			this->todayDateTime->TabIndex = 13;
			this->todayDateTime->Value = System::DateTime::Today;
			this->todayDateTime->ValueChanged += gcnew System::EventHandler(this, &GUI::todayDateTime_ValueChanged);
			this->todayDateTime->TabStop = false;
			// 
			// TaskListDisplay
			// 
			this->TaskListDisplay->Columns->AddRange(gcnew cli::array< System::Windows::Forms::ColumnHeader^  >(4) {
				this->TaskID, this->TaskDescription,
					this->DueDate, this->DueTime
			});
			this->TaskListDisplay->Location = System::Drawing::Point(678, 118);
			this->TaskListDisplay->Name = L"TaskListDisplay";
			this->TaskListDisplay->Size = System::Drawing::Size(430, 405);
			this->TaskListDisplay->TabIndex = 14;
			this->TaskListDisplay->UseCompatibleStateImageBehavior = false;
			this->TaskListDisplay->View = System::Windows::Forms::View::Details;
			this->TaskListDisplay->TabStop = false;
			this->TaskListDisplay->KeyDown += gcnew System::Windows::Forms::KeyEventHandler(this, &GUI::inputBox_KeyDown);
			// 
			// TaskID
			// 
			this->TaskID->Text = L"ID.";
			this->TaskID->Width = 30;
			// 
			// TaskDescription
			// 
			this->TaskDescription->Text = L"Task Description";
			this->TaskDescription->Width = 225;
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
			// feedbackLabel
			// 
			this->feedbackLabel->AutoSize = true;
			this->feedbackLabel->ForeColor = System::Drawing::SystemColors::InactiveCaptionText;
			this->feedbackLabel->Location = System::Drawing::Point(163, 637);
			this->feedbackLabel->Name = L"feedbackLabel";
			this->feedbackLabel->Size = System::Drawing::Size(209, 15);
			this->feedbackLabel->TabIndex = 15;
			this->feedbackLabel->Text = L"add / edit / show / delete / undo / save";
			this->feedbackLabel->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			this->feedbackLabel->TabStop = false;
			// 
			// GUI
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(7, 15);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->AutoSize = true;
			this->BackColor = System::Drawing::Color::White;
			this->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->ClientSize = System::Drawing::Size(1120, 685);
			this->Controls->Add(this->feedbackLabel);
			this->Controls->Add(this->TaskListDisplay);
			this->Controls->Add(this->todayDateTime);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->EventListDisplay);
			this->Controls->Add(this->FeedbackDisplay);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->inputBox);
			this->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedSingle;
			this->HelpButton = true;
			this->MaximizeBox = false;
			this->MinimizeBox = false;
			this->Name = L"GUI";
			this->Text = L"Doowado";
			this->KeyDown += gcnew System::Windows::Forms::KeyEventHandler(this, &GUI::inputBox_KeyDown);
			this->ResumeLayout(false);
			this->PerformLayout();

			//initializing program
			Controller = new DisplayController;
			Controller->initialiseProgram();
			getListofEvents();
			getListofTasks();

		}
#pragma endregion

	private:
		System::Void inputBox_KeyDown(System::Object^  sender, System::Windows::Forms::KeyEventArgs^  e) {
			if (e->KeyCode == Keys::Enter) {
				if (this->ActiveControl == inputBox) {
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
				else {
					this->ActiveControl = inputBox;
				}
			}
			
			// Minimize via Ctrl + W
			else if (e->KeyData == (Keys::Control | Keys::W)) {
				WindowState = FormWindowState::Minimized;
			}
			
			// Exit via Ctrl + Q
			else if (e->KeyData == (Keys::Control | Keys::Q)) {
				MessageBox::Show("Good bye!");
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
				this->ActiveControl = inputBox;
			}
			e->Handled = true;
		}

	private:
		
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
			FeedbackDisplay->AppendText(Controller->retrieveLastFeedback() + "\r\n");
		}
		
		System::Void checkExit(System::String^ input) {
			if (input == "exit") {
				MessageBox::Show("Good bye!");
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
		System::Void todayDateTime_ValueChanged(System::Object^  sender, System::EventArgs^  e) {
			String^ chosenDate = gcnew String(this->todayDateTime->Value.ToString("dd/MM/yyyy"));

			Controller->processInput("show " + chosenDate);

			EventListDisplay->Items->Clear();
			getListofEvents();

			TaskListDisplay->Items->Clear();
			getListofTasks();
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
#pragma once


#include <vector>
#include <algorithm>
#include <string>
#include <sstream>
#include "MessageManager.h"


namespace DoowadoGUI {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for GUI
	/// </summary>
	public ref class GUI : public System::Windows::Forms::Form {
	private:
		static MessageManager^ magicManager;
	public:
		GUI(void)
		{
			InitializeComponent();
			magicManager = gcnew MessageManager();
			setGuiText("show on today");
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
			this->SuspendLayout();
			// 
			// inputBox
			// 
			this->inputBox->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Bottom | System::Windows::Forms::AnchorStyles::Right));
			this->inputBox->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->inputBox->Location = System::Drawing::Point(408, 791);
			this->inputBox->Multiline = true;
			this->inputBox->Name = L"inputBox";
			this->inputBox->Size = System::Drawing::Size(1038, 47);
			this->inputBox->TabIndex = 0;
			this->inputBox->Text = L"Enter Command Here";
			// 
			// label1
			// 
			this->label1->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Bottom | System::Windows::Forms::AnchorStyles::Left));
			this->label1->AutoSize = true;
			this->label1->BackColor = System::Drawing::Color::Maroon;
			this->label1->Font = (gcnew System::Drawing::Font(L"Century Gothic", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label1->Location = System::Drawing::Point(12, 791);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(362, 47);
			this->label1->TabIndex = 1;
			this->label1->Text = L"INPUT COMMAND";
			// 
			// FeedbackDisplay
			// 
			this->FeedbackDisplay->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Left | System::Windows::Forms::AnchorStyles::Right));
			this->FeedbackDisplay->BackColor = System::Drawing::Color::White;
			this->FeedbackDisplay->Location = System::Drawing::Point(12, 635);
			this->FeedbackDisplay->Multiline = true;
			this->FeedbackDisplay->Name = L"FeedbackDisplay";
			this->FeedbackDisplay->ReadOnly = true;
			this->FeedbackDisplay->ScrollBars = System::Windows::Forms::ScrollBars::Vertical;
			this->FeedbackDisplay->Size = System::Drawing::Size(1434, 125);
			this->FeedbackDisplay->TabIndex = 5;
			this->FeedbackDisplay->Text = L"Feedback and History Displayed here";
			// 
			// EventListDisplay
			// 
			this->EventListDisplay->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->EventListDisplay->CheckBoxes = true;
			this->EventListDisplay->Columns->AddRange(gcnew cli::array< System::Windows::Forms::ColumnHeader^  >(6) {
				this->EventID, this->EventName,
					this->StartDate, this->StartTime, this->EndDate, this->EndTime
			});
			this->EventListDisplay->Location = System::Drawing::Point(12, 12);
			this->EventListDisplay->Name = L"EventListDisplay";
			this->EventListDisplay->Size = System::Drawing::Size(760, 588);
			this->EventListDisplay->TabIndex = 3;
			this->EventListDisplay->UseCompatibleStateImageBehavior = false;
			this->EventListDisplay->View = System::Windows::Forms::View::Details;
			// 
			// EventID
			// 
			this->EventID->Text = L"ID.";
			this->EventID->Width = 30;
			// 
			// EventName
			// 
			this->EventName->Text = L"Event Description";
			this->EventName->Width = 275;
			// 
			// StartDate
			// 
			this->StartDate->Text = L"Start Date";
			this->StartDate->Width = 157;
			// 
			// StartTime
			// 
			this->StartTime->Text = L"Start Time";
			this->StartTime->Width = 118;
			// 
			// EndDate
			// 
			this->EndDate->Text = L"End Date";
			this->EndDate->Width = 90;
			// 
			// EndTime
			// 
			this->EndTime->Text = L"End Time";
			this->EndTime->Width = 112;
			// 
			// label2
			// 
			this->label2->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Right));
			this->label2->AutoSize = true;
			this->label2->BackColor = System::Drawing::Color::Transparent;
			this->label2->Font = (gcnew System::Drawing::Font(L"Comic Sans MS", 20, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label2->ForeColor = System::Drawing::Color::Firebrick;
			this->label2->Location = System::Drawing::Point(785, 9);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(702, 95);
			this->label2->TabIndex = 12;
			this->label2->Text = L"Welcome to Doowado";
			this->label2->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// todayDateTime
			// 
			this->todayDateTime->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Left | System::Windows::Forms::AnchorStyles::Right));
			this->todayDateTime->CalendarFont = (gcnew System::Drawing::Font(L"Calibri", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->todayDateTime->Font = (gcnew System::Drawing::Font(L"Calibri", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->todayDateTime->Location = System::Drawing::Point(827, 107);
			this->todayDateTime->Name = L"todayDateTime";
			this->todayDateTime->Size = System::Drawing::Size(619, 56);
			this->todayDateTime->TabIndex = 13;
			this->todayDateTime->Value = System::DateTime(2015, 10, 16, 11, 56, 5, 726);
			// 
			// TaskListDisplay
			// 
			this->TaskListDisplay->Columns->AddRange(gcnew cli::array< System::Windows::Forms::ColumnHeader^  >(4) {
				this->TaskID, this->TaskDescription,
					this->DueDate, this->DueTime
			});
			this->TaskListDisplay->Location = System::Drawing::Point(823, 195);
			this->TaskListDisplay->Name = L"TaskListDisplay";
			this->TaskListDisplay->Size = System::Drawing::Size(623, 405);
			this->TaskListDisplay->TabIndex = 14;
			this->TaskListDisplay->UseCompatibleStateImageBehavior = false;
			this->TaskListDisplay->View = System::Windows::Forms::View::Details;
			// 
			// TaskID
			// 
			this->TaskID->Text = L"ID.";
			this->TaskID->Width = 30;
			// 
			// TaskDescription
			// 
			this->TaskDescription->Text = L"Task Description";
			this->TaskDescription->Width = 268;
			// 
			// DueDate
			// 
			this->DueDate->Text = L"Due Date";
			this->DueDate->Width = 174;
			// 
			// DueTime
			// 
			this->DueTime->Text = L"Due Time";
			this->DueTime->Width = 386;
			// 
			// GUI
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(17, 36);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->AutoSize = true;
			this->BackColor = System::Drawing::Color::White;
			this->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->ClientSize = System::Drawing::Size(1499, 904);
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
			this->TopMost = true;
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion

	private:
		System::Void inputBox_KeyDown(System::Object^  sender, System::Windows::Forms::KeyEventArgs^  e) {
			if (e->KeyCode == Keys::Enter) {
				String^ inputText = inputBox->Text;
				setGuiText(inputText);
			}

			// Minimize via Ctrl + W
			if (e->KeyData == (Keys::Control | Keys::W)) {
				WindowState = FormWindowState::Minimized;
			}

			// Exit via Ctrl + Q
			if (e->KeyData == (Keys::Control | Keys::Q)) {
				MessageBox::Show("Good bye!");
				Application::Exit();
			}

			// Undo via Ctrl + Z
			if (e->KeyData == (Keys::Control | Keys::Z)) {
				setGuiText("undo");
			}

			// Redo via Ctrl + R
			if (e->KeyData == (Keys::Control | Keys::R)) {
				setGuiText("redo");
			}
		}

	private:
		System::Void setGuiText(String^ userInput) {

			checkExit(userInput);

			magicManager->generateOutput(userInput);

			clearCommandBox();

			EventListDisplay->Text = magicManager->getEventListMessage;

			TaskListDisplay->Text = magicManager->getTaskListMessage;


		}


		System::Void clearCommandBox() {
			inputBox->Text = "";
			inputBox->SelectionStart = 100;
		}

		System::Void checkExit(String^ input) {
			if (input == "exit") {
				MessageBox::Show("Good bye!");
				Application::Exit();
			}
		}
};
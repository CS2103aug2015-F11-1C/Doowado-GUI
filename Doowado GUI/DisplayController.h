#pragma once

#include "Logic.h"
#include <msclr/marshal_cppstd.h>
#include <boost/date_time/gregorian/gregorian.hpp>
#include <boost/date_time/posix_time/posix_time.hpp>

class DisplayController {
private:
	Logic *_logic;

public:
	DisplayController();
	~DisplayController();

	void initialiseProgram();

	void processInput(System::String^ inputString);
	int getEventListSize();
	int getTaskListSize();
	int getFeedbackListSize();

	System::String^ retrieveLastFeedback();

	System::Windows::Forms::ListViewItem^ retrieveEventNameFromList(int index);
	System::Windows::Forms::ListViewItem^ retrieveEventStartFromList(int index);
	System::Windows::Forms::ListViewItem^ retrieveEventEndFromList(int index);

	System::Windows::Forms::ListViewItem^ retrieveTaskNameFromList(int index);
	System::Windows::Forms::ListViewItem^ retrieveTaskDueFromList(int index);
};
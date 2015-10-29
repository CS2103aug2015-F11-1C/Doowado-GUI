#pragma once

#include "Logic.h"
#include <msclr\marshal_cppstd.h>
#include <boost/date_time/gregorian/gregorian.hpp>
#include <boost/date_time/posix_time/posix_time.hpp>

public ref class DisplayController {
private:
	Logic* _logic;

public:
	DisplayController();
	System::Void processInput(System::String^ inputString);
	int getEventListSize();
	int getTaskListSize();
	System::Windows::Forms::ListViewItem^ retrieveEventFromList(int index);
	System::Windows::Forms::ListViewItem^ retrieveTaskFromList(int index);
};
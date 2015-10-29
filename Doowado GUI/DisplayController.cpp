#include "DisplayController.h"

System::String^ convertToSystemString(std::string inputString) {
	return gcnew System::String(inputString.c_str());
}

std::string convertToStdString(System::String^ inputString) {
	return msclr::interop::marshal_as< std::string >(inputString);
}

DisplayController::DisplayController(){
	_logic = new Logic;
	_logic->initialiseProgram();
}

System::Void DisplayController::processInput(System::String ^ inputString){
	std::string input = convertToStdString(inputString);

	_logic->processCommand(input);
}

int DisplayController::getEventListSize() {
	return _logic->getDisplay()->getEventList().size();
}

int DisplayController::getTaskListSize() {
	return _logic->getDisplay()->getTaskList().size();
}

System::Windows::Forms::ListViewItem^ DisplayController::retrieveEventFromList(int index){
	System::String^ eventID;
	System::String^ eventTitle;
	System::String^ startDate;
	System::String^ startTime;
	System::String^ endDate;
	System::String^ endTime;
	
	Entry* currentEvent;

	currentEvent = _logic->getDisplay()->retrieveEvent(index);

	//process eventID
	eventID = convertToSystemString("E" + to_string(index+1));

	//process eventTitle
	std::string title = currentEvent->getTitle();
	eventTitle = convertToSystemString(title);

	//process startDate
	std::string startD = to_simple_string(currentEvent->getStartTime().date());
	startDate = convertToSystemString(startD);

	//process startTime
	std::string startT = to_simple_string(currentEvent->getStartTime().time_of_day());
	startTime = convertToSystemString(startT);

	//process endDate
	std::string endD = to_simple_string(currentEvent->getEndTime().date());
	endDate = convertToSystemString(endD);

	//process endTime
	std::string endT = to_simple_string(currentEvent->getEndTime().time_of_day());
	endTime = convertToSystemString(endT);

	return (gcnew System::Windows::Forms::ListViewItem(gcnew cli::array< System::String^>(6) { eventID, eventTitle, startDate, startTime, endDate, endTime }, -1));
}

System::Windows::Forms::ListViewItem^ DisplayController::retrieveTaskFromList(int index){
	System::String^ taskID;
	System::String^ taskTitle;
	System::String^ dueDate;
	System::String^ dueTime;

	Entry* currentTask;

	currentTask = _logic->getDisplay()->retrieveTask(index);

	//process taskID
	taskID = convertToSystemString("T" + to_string(index + 1));

	//process taskTitle
	std::string title = currentTask->getTitle();
	taskTitle = convertToSystemString(title);

	//process dueDate
	std::string dueD = to_simple_string(currentTask->getEndTime().date());
	dueDate = convertToSystemString(dueD);

	//process dueTime
	std::string dueT = to_simple_string(currentTask->getEndTime().time_of_day());
	dueTime = convertToSystemString(dueT);

	return (gcnew System::Windows::Forms::ListViewItem(gcnew cli::array< System::String^>(4) { taskID, taskTitle, dueDate, dueTime }, -1));
}

#include "DisplayController.h"

System::String^ convertToSystemString(std::string inputString) {
	return gcnew System::String(inputString.c_str());
}

std::string convertToStdString(System::String^ inputString) {
	return msclr::interop::marshal_as< std::string >(inputString);
}

DisplayController::DisplayController(){
	_logic = new Logic;
}

DisplayController::~DisplayController() {
	delete _logic;
}

void DisplayController::initialiseProgram() {
	_logic->initialiseProgram();
}

void DisplayController::processInput(System::String^ inputString){
	std::string stdInput = convertToStdString(inputString);

	_logic->processCommand(stdInput);
}

int DisplayController::getEventListSize() {
	return _logic->getDisplay()->getEventList().size();
}

int DisplayController::getTaskListSize() {
	return _logic->getDisplay()->getTaskList().size();
}

int DisplayController::getFeedbackListSize() {
	return _logic->getDisplay()->getCommandFeedback().size();
}

System::String ^ DisplayController::retrieveLastFeedback(){
	string lastFeedback;

	for (int i = 0; i < _logic->getDisplay()->getCommandFeedback().size(); i++) {
		lastFeedback += _logic->getDisplay()->getCommandFeedback().at(i);
		lastFeedback += " ";
	}

	System::String^ systemFeedback = convertToSystemString(lastFeedback);
	
	return systemFeedback;
}

System::Windows::Forms::ListViewItem ^ DisplayController::retrieveEventNameFromList(int index){
	System::String^ eventID;
	System::String^ eventDetails;

	Entry* currentEvent;

	currentEvent = _logic->getDisplay()->retrieveEntry(event, index);

	//process eventID
	eventID = convertToSystemString("E" + to_string(index + 1));

	//process eventTitle
	std::string title = currentEvent->getTitle();
	eventDetails = convertToSystemString(title);

	return (gcnew System::Windows::Forms::ListViewItem(gcnew cli::array< System::String^>(2) { eventID, eventDetails}, -1));
}

System::Windows::Forms::ListViewItem ^ DisplayController::retrieveEventStartFromList(int index){
	System::String^ eventID;
	System::String^ eventDetails;

	Entry* currentEvent;

	currentEvent = _logic->getDisplay()->retrieveEntry(event, index);

	//process eventID
	eventID = convertToSystemString("");

	//process start time
	std::string startTime = to_simple_string(currentEvent->getStartTime());
	eventDetails = convertToSystemString("Start at: " + startTime);

	return (gcnew System::Windows::Forms::ListViewItem(gcnew cli::array< System::String^>(2) { eventID, eventDetails }, -1));
}

System::Windows::Forms::ListViewItem ^ DisplayController::retrieveEventEndFromList(int index){
	System::String^ eventID;
	System::String^ eventDetails;

	Entry* currentEvent;

	currentEvent = _logic->getDisplay()->retrieveEntry(event, index);

	//process eventID
	eventID = convertToSystemString("");

	//process end Time
	std::string endTime = to_simple_string(currentEvent->getEndTime());
	eventDetails = convertToSystemString("End at: "+ endTime);

	return (gcnew System::Windows::Forms::ListViewItem(gcnew cli::array< System::String^>(2) { eventID, eventDetails }, -1));
}

System::Windows::Forms::ListViewItem ^ DisplayController::retrieveTaskNameFromList(int index){
	System::String^ taskID;
	System::String^ taskDetails;

	Entry* currentTask;

	currentTask = _logic->getDisplay()->retrieveEntry(task, index);

	//process taskID
	taskID = convertToSystemString("T" + to_string(index + 1));

	//process taskTitle
	std::string title = currentTask->getTitle();
	taskDetails = convertToSystemString(title);

	return (gcnew System::Windows::Forms::ListViewItem(gcnew cli::array< System::String^>(2) { taskID, taskDetails }, -1));
}

System::Windows::Forms::ListViewItem ^ DisplayController::retrieveTaskDueFromList(int index){
	System::String^ taskID;
	System::String^ taskDetails;

	Entry* currentTask;

	currentTask = _logic->getDisplay()->retrieveEntry(task, index);

	//process eventID
	taskID = convertToSystemString("");

	//process end Time
	if (currentTask->getEndTime().is_not_a_date_time()) {
		return (gcnew System::Windows::Forms::ListViewItem(gcnew cli::array< System::String^>(1) { taskID }, -1));
	}
	else {
		std::string endTime = to_simple_string(currentTask->getEndTime());
		taskDetails = convertToSystemString("Due by: " + endTime);

		return (gcnew System::Windows::Forms::ListViewItem(gcnew cli::array< System::String^>(2) { taskID, taskDetails }, -1));
	}

}


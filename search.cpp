#include "search.h"
#include "HashTable.cpp"
#include "DocList.cpp"
#include "MaxHeap.cpp"
#include <sstream>

using namespace dsaProj;

System::Void search::button1_Click(System::Object^ sender, System::EventArgs^ e) {
	String^ ser = textBox1->Text;
	std::string stdSer = msclr::interop::marshal_as<std::string>(ser);

	string data = isValidInput(stdSer);

	if (data == "-1") {
		MessageBox::Show("Search NOT Valid");
	}

	System::String^ sysStr = msclr::interop::marshal_as<System::String^>(data);
	MessageBox::Show(sysStr);

	textBox1->Clear();

	if (sr == nullptr) {
		sr = gcnew searchResults();
		sr->FormClosed += gcnew System::Windows::Forms::FormClosedEventHandler(this, &search::sr_FormClosed);
		sr->MdiParent = this->MdiParent;
		sr->StartPosition = FormStartPosition::Manual;
		sr->Location = Point(0, 0); // Set the desired starting position here
		sr->Width = this->Width;
		sr->Height = this->Height;
		sr->WindowState = FormWindowState::Maximized; // Scale to parent size
		sr->Show();
	}
	else {
		sr->Activate();
	}
}

System::Void search::sr_FormClosed(System::Object^ sender, System::Windows::Forms::FormClosedEventArgs^ e) {
	sr = nullptr;
}

std::string search::isValidInput(const std::string& input) {
	DocList* docuList = new DocList();

	std::string content;

	std::stringstream ss(input);
	std::string word1, word2, op;
	// Extracting word1, word2, and operator
	ss >> word1;
	// If there's only one word, it's considered a valid input
	if (ss.fail() || ss.eof()) {
		MaxHeap mh = docuList->getResults(word1);
		bool empty = mh.isEmpty();
		content = mh.getDocNamesInOrder();

		std::string boolString = empty ? "true" : "false";
		System::String^ s1 = msclr::interop::marshal_as<System::String^>(boolString);
		MessageBox::Show(s1);
		return content;
	}

	

	ss >> op >> word2;

	// Checking if the operator is either "AND" or "OR"
	if (op != "AND" && op != "OR") {
		return "-1";
	}
	else if (op == "AND") {
		MaxHeap mh = docuList->getResultsAND(word1, word2);
		content = mh.getDocNamesInOrder();
		return content;
	}
	else if (op == "OR") {
		MaxHeap mh = docuList->getResultsOR(word1, word2);
		content = mh.getDocNamesInOrder();
		return content;
	}

	delete docuList;
}
#include "search.h"
#include "searchResults.h"
#include "HashTable.cpp"
#include "DocList.cpp"
#include "MaxHeap.cpp"
#include <sstream>

using namespace dsaProj;

System::Void search::button1_Click(System::Object^ sender, System::EventArgs^ e) {
	String^ ser = textBox1->Text;
	if (String::IsNullOrWhiteSpace(ser)) {
		MessageBox::Show("Search Empty!");
		return;
	}
	std::string stdSer = msclr::interop::marshal_as<std::string>(ser);

	string data = isValidInput(stdSer);

	if (data == "-1") {
		MessageBox::Show("Search NOT Valid");
	}

	//System::String^ sysStr = msclr::interop::marshal_as<System::String^>(data);
	//MessageBox::Show(sysStr);

	textBox1->Clear();

	if (sr == nullptr) {
		sr = gcnew searchResults(this);
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
		//sr->Activate();
		sr->Close();
		sr = nullptr;

		sr = gcnew searchResults(this);
		sr->FormClosed += gcnew System::Windows::Forms::FormClosedEventHandler(this, &search::sr_FormClosed);
		sr->MdiParent = this->MdiParent;
		sr->StartPosition = FormStartPosition::Manual;
		sr->Location = Point(0, 0); // Set the desired starting position here
		sr->Width = this->Width;
		sr->Height = this->Height;
		sr->WindowState = FormWindowState::Maximized; // Scale to parent size
		sr->Show();
	}
}

System::Void search::sr_FormClosed(System::Object^ sender, System::Windows::Forms::FormClosedEventArgs^ e) {
	sr = nullptr;
}

std::string search::isValidInput(const std::string& input) {
	DocList* docuList = new DocList();

	std::string content;
	if (cache->exists(input)) {
		MaxHeap mh = cache->get(input);
		content = mh.getDocNamesInOrder();
		MessageBox::Show("Cache if");
		setDocs(content);
		delete docuList;
		return content;
	}
	else {
		MessageBox::Show("NON Cache if");

		std::stringstream ss(input);
		std::string word1, word2, op;
		// Extracting word1, word2, and operator
		ss >> word1;
		// If there's only one word, it's considered a valid input
		if (ss.fail() || ss.eof()) {
			MaxHeap mh = docuList->getResults(word1);
			content = mh.getDocNamesInOrder();
			cache->put(input, mh);
			setDocs(content);
			delete docuList;
			return content;
		}



		ss >> op >> word2;

		// Checking if the operator is either "AND" or "OR"
		if (op != "AND" && op != "OR") {
			delete docuList;
			return "-1";
		}
		else if (op == "AND") {
			MaxHeap mh = docuList->getResultsAND(word1, word2);
			content = mh.getDocNamesInOrder();
			cache->put(input, mh);
			setDocs(content);
			delete docuList;
			return content;
		}
		else if (op == "OR") {
			MaxHeap mh = docuList->getResultsOR(word1, word2);
			content = mh.getDocNamesInOrder();
			cache->put(input, mh);
			setDocs(content);
			delete docuList;
			return content;
		}
	}
	delete docuList; 
}
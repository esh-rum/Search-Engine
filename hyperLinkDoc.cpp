#include "hyperLinkDoc.h"
#include "HistoryBackend.cpp"

using namespace dsaProj;

System::Void hyperLinkDoc::button1_Click(System::Object^ sender, System::EventArgs^ e) {
	textBox1->Clear();
	
	String^ temp = textBox2->Text; // Get the resultSelected from searchResults
	//MessageBox::Show("Recieved the resultSelected." + temp);
	std::string stdName = msclr::interop::marshal_as<std::string>(temp);

	Doc* doc1 = docuList->getDoc(stdName);

	if (doc1 != nullptr) {
		std::string content = doc1->getContent();
		textBox1->AppendText(gcnew String(content.c_str()));
	}
	else {
		textBox1->Text = "Document not found.";
	}

	hist.push(stdName);

	DocGraph* hyperGraph = new DocGraph();
	hyperGraph->buildGraph();
	std::string words = hyperGraph->getMentions(stdName);
	System::String^ sysWords = msclr::interop::marshal_as<System::String^>(words);
	textBox1->AppendText("\r\n" + "\r\n" + sysWords);

	textBox2->Clear();
}
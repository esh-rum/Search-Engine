#include "srDoc.h"
#include "hyperLinkDoc.h"
 
using namespace dsaProj;


System::Void srDoc::button1_Click(System::Object^ sender, System::EventArgs^ e) {
	hyperWord = textBox2->Text;
	textBox2->Clear();
	if (hyperDoc == nullptr) {
		hyperDoc = gcnew hyperLinkDoc(this); // Pass the current instance of searchhyperDocs to srDoc
		hyperDoc->FormClosed += gcnew System::Windows::Forms::FormClosedEventHandler(this, &srDoc::hyperDoc_FormClosed);
		hyperDoc->MdiParent = this->MdiParent;
		hyperDoc->StartPosition = FormStartPosition::Manual;
		hyperDoc->Location = Point(0, 0); // Set the desired starting position here
		hyperDoc->Width = this->Width;
		hyperDoc->Height = this->Height;
		hyperDoc->WindowState = FormWindowState::Maximized; // Scale to parent size
		hyperDoc->Show();
	}
	else {
		hyperDoc->Close();
		hyperDoc = nullptr;
		hyperDoc = gcnew hyperLinkDoc(this); // Pass the current instance of searchResults to srDoc
		hyperDoc->FormClosed += gcnew System::Windows::Forms::FormClosedEventHandler(this, &srDoc::hyperDoc_FormClosed);
		hyperDoc->MdiParent = this->MdiParent;
		hyperDoc->StartPosition = FormStartPosition::Manual;
		hyperDoc->Location = Point(0, 0); // Set the desired starting position here
		hyperDoc->Width = this->Width;
		hyperDoc->Height = this->Height;
		hyperDoc->WindowState = FormWindowState::Maximized; // Scale to parent size
		hyperDoc->Show();
	}

}

System::Void srDoc::hyperDoc_FormClosed(System::Object^ sender, System::Windows::Forms::FormClosedEventArgs^ e) {
	hyperDoc = nullptr;
}

System::String^ srDoc::getHyperWord() {
	return hyperWord;
}
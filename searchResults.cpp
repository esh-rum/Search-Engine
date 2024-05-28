#include "searchResults.h"
#include "srDoc.h"

using namespace dsaProj;

System::Void searchResults::button1_Click(System::Object^ sender, System::EventArgs^ e) {
	resultSelected = textBox1->Text;
	textBox1->Clear();
	if (result == nullptr) {
		result = gcnew srDoc(this); // Pass the current instance of searchResults to srDoc
		result->FormClosed += gcnew System::Windows::Forms::FormClosedEventHandler(this, &searchResults::result_FormClosed);
		result->MdiParent = this->MdiParent;
		result->StartPosition = FormStartPosition::Manual;
		result->Location = Point(0, 0); // Set the desired starting position here
		result->Width = this->Width;
		result->Height = this->Height;
		result->WindowState = FormWindowState::Maximized; // Scale to parent size
		result->Show();
	}
	else {
		result->Close();
		result = nullptr;
		//result->Activate();
		result = gcnew srDoc(this); // Pass the current instance of searchResults to srDoc
		result->FormClosed += gcnew System::Windows::Forms::FormClosedEventHandler(this, &searchResults::result_FormClosed);
		result->MdiParent = this->MdiParent;
		result->StartPosition = FormStartPosition::Manual;
		result->Location = Point(0, 0); // Set the desired starting position here
		result->Width = this->Width;
		result->Height = this->Height;
		result->WindowState = FormWindowState::Maximized; // Scale to parent size
		result->Show();
	}
	
}

System::String^ searchResults::sendResult() {
	//MessageBox::Show("Sent the resultSelected." + resultSelected);
	return resultSelected;
}

System::Void searchResults::result_FormClosed(System::Object^ sender, System::Windows::Forms::FormClosedEventArgs^ e) {
	result = nullptr;
}

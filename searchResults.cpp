#include "searchResults.h"
#include "srDoc.h"

using namespace dsaProj;

System::Void searchResults::button1_Click(System::Object^ sender, System::EventArgs^ e) {
	resultSelected = textBox1->Text;
	if (String::IsNullOrWhiteSpace(resultSelected)) {
		MessageBox::Show("Empty! Enter result of choice!");
		return;
	}
	textBox1->Clear();
	if (result == nullptr) {
		//MessageBox::Show("1");
		result = gcnew srDoc(this); // Pass the current instance of searchResults to srDoc
		result->FormClosed += gcnew System::Windows::Forms::FormClosedEventHandler(this, &searchResults::result_FormClosed);
		//MessageBox::Show("2");
		result->MdiParent = this->MdiParent;
		result->StartPosition = FormStartPosition::Manual;
		result->Location = Point(0, 0); // Set the desired starting position here
		result->Width = this->Width;
		result->Height = this->Height;
		result->WindowState = FormWindowState::Maximized; // Scale to parent size
		result->Show();
		//MessageBox::Show("3");
	}
	else {
		//MessageBox::Show("4");
		result->Close();
		result = nullptr;
		//result->Activate();
		//MessageBox::Show("5");
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
#include "database.h"
#include "DocGraph.cpp"

using namespace dsaProj;

System::Void database::button1_Click(System::Object^ sender, System::EventArgs^ e) {
	try {
		System::Diagnostics::Debug::WriteLine("Button clicked, processing...");

		String^ name = textBox1->Text;
		String^ path = textBox2->Text;

		System::Diagnostics::Debug::WriteLine("Name: " + name + ", Path: " + path);

		if (!String::IsNullOrWhiteSpace(name) && !String::IsNullOrWhiteSpace(path)) {
			std::string stdName = msclr::interop::marshal_as<std::string>(name);
			std::string stdPath = msclr::interop::marshal_as<std::string>(path);

			System::Diagnostics::Debug::WriteLine("Converted Name: " + gcnew String(stdName.c_str()) + ", Path: " + gcnew String(stdPath.c_str()));

			Doc* doc1 = new Doc(stdName, stdPath);

			System::Diagnostics::Debug::WriteLine("Doc object created.");

			if (docuList == nullptr) {
				MessageBox::Show("docuList is not initialized.");
				return;
			}

			docuList->addDocument(doc1);

			System::Diagnostics::Debug::WriteLine("Document added to docuList.");

			MessageBox::Show("Document added in the network!!");
			Doc* temp = docuList->getDoc(stdName);
			System::String^ temp2 = msclr::interop::marshal_as<System::String^>(temp->getName());
			System::String^ temp3 = msclr::interop::marshal_as<System::String^>(temp->getFilePath());

			textBox1->Clear();
			textBox2->Clear();
			//MessageBox::Show("Document: " + temp2 + " | " + temp3);
		}
		else {
			MessageBox::Show("Please enter both name and path.");
		}
	}
	catch (const std::exception& ex) {
		String^ errorMsg = gcnew String(ex.what());
		MessageBox::Show("An error occurred: " + errorMsg);
		System::Diagnostics::Debug::WriteLine("Standard exception: " + errorMsg);
	}
	catch (Exception^ ex) {
		MessageBox::Show("An error occurred: " + ex->Message);
		System::Diagnostics::Debug::WriteLine("CLR exception: " + ex->Message);
	}
	catch (...) {
		MessageBox::Show("An unknown error occurred.");
		System::Diagnostics::Debug::WriteLine("Unknown exception.");
	}

	System::Diagnostics::Debug::WriteLine("button1_Click completed.");
}

System::Void database::button2_Click(System::Object^ sender, System::EventArgs^ e) {
	String^ docStart = textBox4->Text;
	String^ docEnd = textBox3->Text;

	std::string stdStart = msclr::interop::marshal_as<std::string>(docStart);
	std::string stdEnd = msclr::interop::marshal_as<std::string>(docEnd);

	DocGraph* shortPathGraph = new DocGraph();
	shortPathGraph->buildGraph();

	std::string path = shortPathGraph->findShortestPath(stdStart, stdEnd);

	System::String^ sysPath = msclr::interop::marshal_as<System::String^>(path);

	textBox5->AppendText("SHORTEST PATH: " + "\r\n" + sysPath);

	textBox3->Clear();
	textBox4->Clear();
}
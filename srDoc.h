#pragma once
#include "DocList.cpp"
#include "Doc.cpp"
#include "DocGraph.cpp"
#include "HistoryBackend.cpp"
#include "searchResults.h"
#include <fstream>
#include <string>
#include <msclr/marshal_cppstd.h>


namespace dsaProj {
	ref class hyperLinkDoc; // Forward declaration
}

namespace dsaProj {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for srDoc
	/// </summary>
	public ref class srDoc : public System::Windows::Forms::Form
	{
	public:
		srDoc(searchResults^ srForm)
		{
			InitializeComponent();
			this->srForm = srForm; // Store the reference to searchResults form

		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~srDoc()
		{
			if (components)
			{
				delete components;
			}

			delete docuList;
			delete srForm;
			//srForm = nullptr;
		}
	private: System::Windows::Forms::TextBox^ textBox1;
	private: searchResults^ srForm;
	private: hyperLinkDoc^ hyperDoc;
	protected:

	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>
		System::ComponentModel::Container ^components;
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::TextBox^ textBox2;
	private: System::Windows::Forms::Button^ button1;

		DocList* docuList = new DocList();
		String^ hyperWord;
		History& hist = History::getInstance("first");

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->textBox2 = (gcnew System::Windows::Forms::TextBox());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			// 
			// textBox1
			// 
			this->textBox1->BackColor = System::Drawing::Color::White;
			this->textBox1->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->textBox1->Dock = System::Windows::Forms::DockStyle::Top;
			this->textBox1->Font = (gcnew System::Drawing::Font(L"Courier New", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->textBox1->Location = System::Drawing::Point(0, 0);
			this->textBox1->Multiline = true;
			this->textBox1->Name = L"textBox1";
			this->textBox1->ReadOnly = true;
			this->textBox1->Size = System::Drawing::Size(890, 526);
			this->textBox1->TabIndex = 0;
			this->textBox1->TextChanged += gcnew System::EventHandler(this, &srDoc::textBox1_TextChanged);
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Arial Rounded MT Bold", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label1->Location = System::Drawing::Point(77, 553);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(219, 23);
			this->label1->TabIndex = 12;
			this->label1->Text = L"Enter hyperlink word:";
			// 
			// textBox2
			// 
			this->textBox2->Font = (gcnew System::Drawing::Font(L"Courier New", 13.2F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->textBox2->Location = System::Drawing::Point(315, 548);
			this->textBox2->Name = L"textBox2";
			this->textBox2->Size = System::Drawing::Size(368, 32);
			this->textBox2->TabIndex = 11;
			// 
			// button1
			// 
			this->button1->Font = (gcnew System::Drawing::Font(L"Arial Rounded MT Bold", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->button1->Location = System::Drawing::Point(680, 547);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(133, 34);
			this->button1->TabIndex = 10;
			this->button1->Text = L"Search";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &srDoc::button1_Click);
			// 
			// srDoc
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::Color::White;
			this->ClientSize = System::Drawing::Size(890, 630);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->textBox2);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->textBox1);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::SizableToolWindow;
			this->Name = L"srDoc";
			this->Text = L"srDoc";
			this->Load += gcnew System::EventHandler(this, &srDoc::srDoc_Load);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void srDoc_Load(System::Object^ sender, System::EventArgs^ e) {
		this->ControlBox = false;

		String^ temp = srForm->sendResult(); // Get the resultSelected from searchResults
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

		delete doc1;
		delete hyperGraph; 
		//std::ifstream infile("E:\\Solved lab tasks\\DS\\dsaProj\\example.txt");
		//if (infile.is_open()) {
		//	std::string line;
		//	textBox1->Clear(); // Clear the textbox before loading new content
		//	while (std::getline(infile, line)) {
		//		textBox1->AppendText(gcnew String(line.c_str()) + "\r\n");
		//	}
		//	infile.close();
		//}
		//else {
		//	MessageBox::Show("Unable to open file. Creating a new file.");
		//	std::ofstream outfile("E:\\Solved lab tasks\\DS\\dsaProj\\example.txt");
		//	if (outfile.is_open()) {
		//		std::string defaultContent = "This is a new file created by the application.";
		//		outfile << defaultContent << std::endl;
		//		outfile.close();
		//		// Now read the newly created file
		//		std::ifstream newfile("E:\\Solved lab tasks\\DS\\dsaProj\\example.txt");
		//		if (newfile.is_open()) {
		//			std::string line;
		//			textBox1->Clear(); // Clear the textbox before loading new content
		//			while (std::getline(newfile, line)) {
		//				textBox1->AppendText(gcnew String(line.c_str()) + "\r\n");
		//			}
		//			newfile.close();
		//		}
		//	}
		//	else {
		//		MessageBox::Show("Failed to create the file.");
		//	}
		//}
	}
	private: System::Void textBox1_TextChanged(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e);
	private: System::Void hyperDoc_FormClosed(System::Object^ sender, System::Windows::Forms::FormClosedEventArgs^ e);
	public: String^ getHyperWord();
};
}
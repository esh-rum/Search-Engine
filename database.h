#pragma once
#include <msclr/marshal_cppstd.h>
#include "Doc.cpp"
#include "DocList.cpp"

namespace dsaProj {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for database
	/// </summary>
	public ref class database : public System::Windows::Forms::Form
	{
	public:
		database(void)
		{
			InitializeComponent();

			docuList = new DocList();
			//
			//TODO: Add the constructor code here
			//
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~database()
		{
			if (components)
			{
				delete components;
			}
			delete docuList;
		}
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::TextBox^ textBox1;
	private: System::Windows::Forms::Button^ button1;
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::Label^ label3;
	private: System::Windows::Forms::TextBox^ textBox2;

	protected:

	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>
		System::ComponentModel::Container^ components;
		DocList* docuList;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->textBox2 = (gcnew System::Windows::Forms::TextBox());
			this->SuspendLayout();
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Arial Rounded MT Bold", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label1->Location = System::Drawing::Point(297, 39);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(370, 23);
			this->label1->TabIndex = 10;
			this->label1->Text = L"Add a new document in the database";
			this->label1->Click += gcnew System::EventHandler(this, &database::label1_Click);
			// 
			// textBox1
			// 
			this->textBox1->Font = (gcnew System::Drawing::Font(L"Courier New", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->textBox1->Location = System::Drawing::Point(331, 81);
			this->textBox1->Name = L"textBox1";
			this->textBox1->Size = System::Drawing::Size(483, 30);
			this->textBox1->TabIndex = 12;
			this->textBox1->TextChanged += gcnew System::EventHandler(this, &database::textBox1_TextChanged);
			// 
			// button1
			// 
			this->button1->Font = (gcnew System::Drawing::Font(L"Arial Rounded MT Bold", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->button1->Location = System::Drawing::Point(331, 181);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(133, 34);
			this->button1->TabIndex = 11;
			this->button1->Text = L"Add";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &database::button1_Click);
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Font = (gcnew System::Drawing::Font(L"Arial Rounded MT Bold", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label2->Location = System::Drawing::Point(150, 84);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(131, 23);
			this->label2->TabIndex = 13;
			this->label2->Text = L"Enter Name:";
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Font = (gcnew System::Drawing::Font(L"Arial Rounded MT Bold", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label3->Location = System::Drawing::Point(60, 132);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(221, 23);
			this->label3->TabIndex = 15;
			this->label3->Text = L"Enter document path:";
			// 
			// textBox2
			// 
			this->textBox2->Font = (gcnew System::Drawing::Font(L"Courier New", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->textBox2->Location = System::Drawing::Point(331, 129);
			this->textBox2->Name = L"textBox2";
			this->textBox2->Size = System::Drawing::Size(483, 30);
			this->textBox2->TabIndex = 14;
			// 
			// database
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::Color::White;
			this->ClientSize = System::Drawing::Size(890, 630);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->textBox2);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->textBox1);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->label1);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::SizableToolWindow;
			this->Name = L"database";
			this->StartPosition = System::Windows::Forms::FormStartPosition::Manual;
			this->Text = L"database";
			this->Load += gcnew System::EventHandler(this, &database::database_Load);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void database_Load(System::Object^ sender, System::EventArgs^ e) {
		this->ControlBox = false;
	}
	private: System::Void label1_Click(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e);

	// {
	//	try {
	//		System::Diagnostics::Debug::WriteLine("Button clicked, processing...");
	//		String^ name = textBox1->Text;
	//		String^ path = textBox2->Text;
	//		System::Diagnostics::Debug::WriteLine("Name: " + name + ", Path: " + path);
	//		if (!String::IsNullOrWhiteSpace(name) && !String::IsNullOrWhiteSpace(path)) {
	//			std::string stdName = msclr::interop::marshal_as<std::string>(name);
	//			std::string stdPath = msclr::interop::marshal_as<std::string>(path);
	//			System::Diagnostics::Debug::WriteLine("Converted Name: " + gcnew String(stdName.c_str()) + ", Path: " + gcnew String(stdPath.c_str()));
	//			Doc* doc1 = new Doc(stdName, stdPath);
	//			System::Diagnostics::Debug::WriteLine("Doc object created.");
	//			if (docuList == nullptr) {
	//				MessageBox::Show("docuList is not initialized.");
	//				return;
	//			}
	//			docuList->addDocument(doc1);
	//			System::Diagnostics::Debug::WriteLine("Document added to docuList.");
	//			MessageBox::Show("Document added in the network!!");
	//			Doc* temp = docuList->getDoc(stdName);
	//			System::String^ temp2 = msclr::interop::marshal_as<System::String^>(temp->getName());
	//			System::String^ temp3 = msclr::interop::marshal_as<System::String^>(temp->getFilePath());
	//			textBox1->Clear();
	//			textBox2->Clear();
	//			//MessageBox::Show("Document: " + temp2 + " | " + temp3);
	//		}
	//		else {
	//			MessageBox::Show("Please enter both name and path.");
	//		}
	//	}
	//	catch (const std::exception& ex) {
	//		String^ errorMsg = gcnew String(ex.what());
	//		MessageBox::Show("An error occurred: " + errorMsg);
	//		System::Diagnostics::Debug::WriteLine("Standard exception: " + errorMsg);
	//	}
	//	catch (Exception^ ex) {
	//		MessageBox::Show("An error occurred: " + ex->Message);
	//		System::Diagnostics::Debug::WriteLine("CLR exception: " + ex->Message);
	//	}
	//	catch (...) {
	//		MessageBox::Show("An unknown error occurred.");
	//		System::Diagnostics::Debug::WriteLine("Unknown exception.");
	//	}
	//	System::Diagnostics::Debug::WriteLine("button1_Click completed.");
	//}
	
private: System::Void textBox1_TextChanged(System::Object^ sender, System::EventArgs^ e) {
}
};
}

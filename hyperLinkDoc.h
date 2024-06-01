#pragma once

#include "srDoc.h"
#include "DocGraph.cpp"
#include "HistoryBackend.cpp"

namespace dsaProj {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for hyperLinkDoc
	/// </summary>
	public ref class hyperLinkDoc : public System::Windows::Forms::Form
	{
	public:
		hyperLinkDoc(srDoc^ s)
		{
			InitializeComponent();

			sr = s;
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~hyperLinkDoc()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::TextBox^ textBox1;
	protected:

	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>
		System::ComponentModel::Container ^components;

		srDoc^ sr;
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::TextBox^ textBox2;
	private: System::Windows::Forms::Button^ button1;
		   DocList* docuList = new DocList();
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
			this->textBox1->Dock = System::Windows::Forms::DockStyle::Top;
			this->textBox1->Font = (gcnew System::Drawing::Font(L"Courier New", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->textBox1->Location = System::Drawing::Point(0, 0);
			this->textBox1->Multiline = true;
			this->textBox1->Name = L"textBox1";
			this->textBox1->ReadOnly = true;
			this->textBox1->Size = System::Drawing::Size(890, 526);
			this->textBox1->TabIndex = 0;
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Arial Rounded MT Bold", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label1->Location = System::Drawing::Point(74, 549);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(219, 23);
			this->label1->TabIndex = 15;
			this->label1->Text = L"Enter hyperlink word:";
			// 
			// textBox2
			// 
			this->textBox2->Font = (gcnew System::Drawing::Font(L"Courier New", 13.2F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->textBox2->Location = System::Drawing::Point(312, 544);
			this->textBox2->Name = L"textBox2";
			this->textBox2->Size = System::Drawing::Size(368, 32);
			this->textBox2->TabIndex = 14;
			// 
			// button1
			// 
			this->button1->Font = (gcnew System::Drawing::Font(L"Arial Rounded MT Bold", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->button1->Location = System::Drawing::Point(677, 543);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(133, 34);
			this->button1->TabIndex = 13;
			this->button1->Text = L"Search";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &hyperLinkDoc::button1_Click);
			// 
			// hyperLinkDoc
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::Color::White;
			this->ClientSize = System::Drawing::Size(890, 630);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->textBox2);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->textBox1);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedToolWindow;
			this->Name = L"hyperLinkDoc";
			this->Text = L"hyperLinkDoc";
			this->Load += gcnew System::EventHandler(this, &hyperLinkDoc::hyperLinkDoc_Load);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void hyperLinkDoc_Load(System::Object^ sender, System::EventArgs^ e) {
		this->ControlBox = false;

		String^ temp = sr->getHyperWord(); 
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

	}
	private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e);
};
}

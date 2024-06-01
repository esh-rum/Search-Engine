#pragma once

#include "search.h"

namespace dsaProj {
	ref class srDoc; // Forward declaration
}

namespace dsaProj {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	public ref class searchResults : public System::Windows::Forms::Form
	{
	public:
		searchResults(search^ ser)
		{
			InitializeComponent();
			serDocs = ser;
		}

	protected:
		~searchResults()
		{
			if (components)
			{
				delete components;
			}
			delete serDocs;
			//serDocs = nullptr; 
		}

	private: System::Windows::Forms::Label^ label1;
	protected:
	private: System::Windows::Forms::TextBox^ textBox1;
	private: System::Windows::Forms::TextBox^ textBox2;
	private: System::Windows::Forms::ContextMenuStrip^ contextMenuStrip1;
	private: System::Windows::Forms::Button^ button1;

	public: String^ sendResult();
	private: System::ComponentModel::IContainer^ components;
	public:

	protected:

	private:

		srDoc^ result;

		//String^ example = "example";
		//String^ example2 = "example2";
		String^ resultSelected;
		search^ serDocs;

#pragma region Windows Form Designer generated code
		void InitializeComponent(void)
		{
			this->components = (gcnew System::ComponentModel::Container());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->textBox2 = (gcnew System::Windows::Forms::TextBox());
			this->contextMenuStrip1 = (gcnew System::Windows::Forms::ContextMenuStrip(this->components));
			this->SuspendLayout();
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Arial Rounded MT Bold", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label1->Location = System::Drawing::Point(68, 520);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(203, 23);
			this->label1->TabIndex = 9;
			this->label1->Text = L"Enter search result:";
			// 
			// textBox1
			// 
			this->textBox1->Font = (gcnew System::Drawing::Font(L"Courier New", 13.2F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->textBox1->Location = System::Drawing::Point(304, 515);
			this->textBox1->Name = L"textBox1";
			this->textBox1->Size = System::Drawing::Size(368, 32);
			this->textBox1->TabIndex = 8;
			// 
			// button1
			// 
			this->button1->Font = (gcnew System::Drawing::Font(L"Arial Rounded MT Bold", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->button1->Location = System::Drawing::Point(669, 514);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(133, 34);
			this->button1->TabIndex = 7;
			this->button1->Text = L"Search";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &searchResults::button1_Click);
			// 
			// textBox2
			// 
			this->textBox2->BackColor = System::Drawing::Color::White;
			this->textBox2->Dock = System::Windows::Forms::DockStyle::Top;
			this->textBox2->Font = (gcnew System::Drawing::Font(L"Courier New", 13.2F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->textBox2->Location = System::Drawing::Point(0, 0);
			this->textBox2->Multiline = true;
			this->textBox2->Name = L"textBox2";
			this->textBox2->ReadOnly = true;
			this->textBox2->Size = System::Drawing::Size(890, 485);
			this->textBox2->TabIndex = 10;
			// 
			// contextMenuStrip1
			// 
			this->contextMenuStrip1->ImageScalingSize = System::Drawing::Size(20, 20);
			this->contextMenuStrip1->Name = L"contextMenuStrip1";
			this->contextMenuStrip1->Size = System::Drawing::Size(61, 4);
			// 
			// searchResults
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::Color::White;
			this->ClientSize = System::Drawing::Size(890, 630);
			this->Controls->Add(this->textBox2);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->textBox1);
			this->Controls->Add(this->button1);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::SizableToolWindow;
			this->Name = L"searchResults";
			this->Text = L"searchResults";
			this->Load += gcnew System::EventHandler(this, &searchResults::searchResults_Load);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void searchResults_Load(System::Object^ sender, System::EventArgs^ e) {
		this->ControlBox = false;

		String^ docs = serDocs->getDocs();

		textBox2->AppendText(docs);
	}

	private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e);
	private: System::Void result_FormClosed(System::Object^ sender, System::Windows::Forms::FormClosedEventArgs^ e);

	/*public: String^ sendResult() { return resultSelected; }*/

	/*private: System::Void result_FormClosed(System::Object^ sender, System::Windows::Forms::FormClosedEventArgs^ e) {
		result = nullptr;
	}*/
	};
}

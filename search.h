#pragma once
#include "searchResults.h"


namespace dsaProj {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for search
	/// </summary>
	public ref class search : public System::Windows::Forms::Form
	{
	public:
		search(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~search()
		{
			if (components)
			{
				delete components;
			}
		}

	private: System::Windows::Forms::Button^ button1;
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::TextBox^ textBox1;
	protected:

	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>
		System::ComponentModel::Container ^components;
		searchResults^ sr;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->SuspendLayout();
			// 
			// button1
			// 
			this->button1->Font = (gcnew System::Drawing::Font(L"Arial Rounded MT Bold", 13.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->button1->Location = System::Drawing::Point(697, 260);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(133, 42);
			this->button1->TabIndex = 1;
			this->button1->Text = L"Search";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &search::button1_Click);
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Cooper Black", 30, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label1->Location = System::Drawing::Point(339, 171);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(370, 67);
			this->label1->TabIndex = 0;
			this->label1->Text = L"KEN ENGINE";
			this->label1->UseCompatibleTextRendering = true;
			// 
			// textBox1
			// 
			this->textBox1->Font = (gcnew System::Drawing::Font(L"Arial Rounded MT Bold", 16.2F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->textBox1->Location = System::Drawing::Point(252, 261);
			this->textBox1->Name = L"textBox1";
			this->textBox1->Size = System::Drawing::Size(448, 39);
			this->textBox1->TabIndex = 2;
			// 
			// search
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->AutoSize = true;
			this->BackColor = System::Drawing::Color::White;
			this->ClientSize = System::Drawing::Size(890, 630);
			this->Controls->Add(this->textBox1);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->label1);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::SizableToolWindow;
			this->Name = L"search";
			this->StartPosition = System::Windows::Forms::FormStartPosition::Manual;
			this->Text = L"search";
			this->Load += gcnew System::EventHandler(this, &search::search_Load);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void search_Load(System::Object^ sender, System::EventArgs^ e) {
		this->ControlBox = false;
	}
	private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) {
		if (sr == nullptr) {
			sr = gcnew searchResults();
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
			sr->Activate();
		}
	}
private: System::Void sr_FormClosed(System::Object^ sender, System::Windows::Forms::FormClosedEventArgs^ e) {
	sr = nullptr;
}
};
}

#pragma once

#include "srDoc.h"

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
		DocList* docuList = new DocList();

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->SuspendLayout();
			// 
			// textBox1
			// 
			this->textBox1->Dock = System::Windows::Forms::DockStyle::Fill;
			this->textBox1->Font = (gcnew System::Drawing::Font(L"Courier New", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->textBox1->Location = System::Drawing::Point(0, 0);
			this->textBox1->Multiline = true;
			this->textBox1->Name = L"textBox1";
			this->textBox1->Size = System::Drawing::Size(890, 630);
			this->textBox1->TabIndex = 0;
			// 
			// hyperLinkDoc
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(890, 630);
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

		String^ temp = sr->getHyperWord(); // Get the resultSelected from searchResults
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
	}
	};
}

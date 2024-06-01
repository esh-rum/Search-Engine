#pragma once

#include "Doc.cpp"
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
	/// Summary for next
	/// </summary>
	public ref class next : public System::Windows::Forms::Form
	{
	public:
		next(void)
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
		~next()
		{
			if (components)
			{
				delete components;
			}
		}

	protected:

	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>
		System::ComponentModel::Container ^components;
		History& hist = History::getInstance("first");
		History& histNext = History::getInstance("second");
	private: System::Windows::Forms::TextBox^ textBox1;
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
			this->textBox1->BackColor = System::Drawing::Color::White;
			this->textBox1->Dock = System::Windows::Forms::DockStyle::Fill;
			this->textBox1->Font = (gcnew System::Drawing::Font(L"Courier New", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->textBox1->Location = System::Drawing::Point(0, 0);
			this->textBox1->Multiline = true;
			this->textBox1->Name = L"textBox1";
			this->textBox1->ReadOnly = true;
			this->textBox1->Size = System::Drawing::Size(890, 630);
			this->textBox1->TabIndex = 0;
			// 
			// next
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::Color::White;
			this->ClientSize = System::Drawing::Size(890, 630);
			this->Controls->Add(this->textBox1);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::SizableToolWindow;
			this->Name = L"next";
			this->StartPosition = System::Windows::Forms::FormStartPosition::Manual;
			this->Text = L"next";
			this->Load += gcnew System::EventHandler(this, &next::next_Load);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void next_Load(System::Object^ sender, System::EventArgs^ e) {
		this->ControlBox = false;

		if (histNext.isEmpty()) {
			textBox1->AppendText("Nothing in next at the moment!"); 
			return;
		}
		std::string temp = histNext.top();
		
		hist.push(temp);
		histNext.pop();

		String^ stdName = gcnew String(temp.c_str());

		Doc* doc1 = docuList->getDoc(temp);

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

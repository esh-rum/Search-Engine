#pragma once

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
		searchResults(void)
		{
			InitializeComponent();
		}

	protected:
		~searchResults()
		{
			if (components)
			{
				delete components;
			}
		}

	private: System::Windows::Forms::Label^ label1;
	protected:
	private: System::Windows::Forms::TextBox^ textBox1;
	private: System::Windows::Forms::Button^ button1;
	private: System::Windows::Forms::ListBox^ listBox1;
	public: String^ sendResult();

	protected:

	private:
		System::ComponentModel::Container^ components;
		srDoc^ result;

		//String^ example = "example";
		//String^ example2 = "example2";
		String^ resultSelected;

#pragma region Windows Form Designer generated code
		void InitializeComponent(void)
		{
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->listBox1 = (gcnew System::Windows::Forms::ListBox());
			this->SuspendLayout();
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Arial Rounded MT Bold", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label1->Location = System::Drawing::Point(36, 520);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(284, 23);
			this->label1->TabIndex = 9;
			this->label1->Text = L"Enter search result number:";
			this->textBox1->Font = (gcnew System::Drawing::Font(L"Arial Rounded MT Bold", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->textBox1->Location = System::Drawing::Point(347, 517);
			this->textBox1->Name = L"textBox1";
			this->textBox1->Size = System::Drawing::Size(368, 31);
			this->textBox1->TabIndex = 8;
			this->button1->Font = (gcnew System::Drawing::Font(L"Arial Rounded MT Bold", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->button1->Location = System::Drawing::Point(712, 516);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(133, 34);
			this->button1->TabIndex = 7;
			this->button1->Text = L"Search";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &searchResults::button1_Click);
			this->listBox1->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->listBox1->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->listBox1->Font = (gcnew System::Drawing::Font(L"Arial Rounded MT Bold", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->listBox1->FormattingEnabled = true;
			this->listBox1->ItemHeight = 23;
			this->listBox1->Location = System::Drawing::Point(0, 0);
			this->listBox1->Name = L"listBox1";
			this->listBox1->Size = System::Drawing::Size(890, 485);
			this->listBox1->TabIndex = 6;
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::Color::White;
			this->ClientSize = System::Drawing::Size(890, 630);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->textBox1);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->listBox1);
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

		//listBox1->Items->Add("1. " + example); // test
		//listBox1->Items->Add("2. " + example2); // test
	}

	private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e);
	private: System::Void result_FormClosed(System::Object^ sender, System::Windows::Forms::FormClosedEventArgs^ e);

	/*public: String^ sendResult() { return resultSelected; }*/

	/*private: System::Void result_FormClosed(System::Object^ sender, System::Windows::Forms::FormClosedEventArgs^ e) {
		result = nullptr;
	}*/
	};
}

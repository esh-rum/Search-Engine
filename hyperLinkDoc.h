#pragma once

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
		hyperLinkDoc(void)
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
		~hyperLinkDoc()
		{
			if (components)
			{
				delete components;
			}
		}

	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->SuspendLayout();
			// 
			// hyperLinkDoc
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(890, 630);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedToolWindow;
			this->Name = L"hyperLinkDoc";
			this->Text = L"hyperLinkDoc";
			this->Load += gcnew System::EventHandler(this, &hyperLinkDoc::hyperLinkDoc_Load);
			this->ResumeLayout(false);

		}
#pragma endregion
	private: System::Void hyperLinkDoc_Load(System::Object^ sender, System::EventArgs^ e) {
	}
	};
}

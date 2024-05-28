#pragma once
#include "search.h"
#include "previous.h"
#include "next.h"
#include "history.h"
#include "database.h"
//#include "mdiProperties.cpp"
#include <algorithm>

namespace dsaProj {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for engine
	/// </summary>
	public ref class engine : public System::Windows::Forms::Form
	{
	public:
		engine(void)
		{
			InitializeComponent();
			//mdiProp();	
			//
			//TODO: Add the constructor code here
			//
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~engine()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::PropertyGrid^ propertyGrid1;
	private: System::Windows::Forms::PageSetupDialog^ pageSetupDialog1;
	private: System::Windows::Forms::BindingNavigator^ bindingNavigator1;
	private: System::Windows::Forms::ToolStripButton^ bindingNavigatorAddNewItem;
	private: System::Windows::Forms::ToolStripLabel^ bindingNavigatorCountItem;
	private: System::Windows::Forms::ToolStripButton^ bindingNavigatorDeleteItem;
	private: System::Windows::Forms::ToolStripButton^ bindingNavigatorMoveFirstItem;
	private: System::Windows::Forms::ToolStripButton^ bindingNavigatorMovePreviousItem;
	private: System::Windows::Forms::ToolStripSeparator^ bindingNavigatorSeparator;
	private: System::Windows::Forms::ToolStripTextBox^ bindingNavigatorPositionItem;
	private: System::Windows::Forms::ToolStripSeparator^ bindingNavigatorSeparator1;
	private: System::Windows::Forms::ToolStripButton^ bindingNavigatorMoveNextItem;
	private: System::Windows::Forms::ToolStripButton^ bindingNavigatorMoveLastItem;
	private: System::Windows::Forms::ToolStripSeparator^ bindingNavigatorSeparator2;
	private: System::Windows::Forms::Panel^ panel1;
	private: System::Windows::Forms::PictureBox^ btnMenu;

	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::FlowLayoutPanel^ sidebar;

	private:


	private: System::Windows::Forms::Button^ button1;
	private: System::Windows::Forms::Panel^ pnSearch;
	private: System::Windows::Forms::Panel^ pnPrev;


	private: System::Windows::Forms::Button^ button2;
	private: System::Windows::Forms::Panel^ pnNext;

	private: System::Windows::Forms::Button^ button3;
	private: System::Windows::Forms::Panel^ pnHistory;

	private: System::Windows::Forms::Button^ button4;
	private: System::Windows::Forms::Timer^ sidebarTransition;

	private: System::ComponentModel::IContainer^ components;
	protected:

	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>
		search^ ser;
		previous^ prev;
		next^ nex;
		//WindowsFormsApp10::mdiProperties^ mdi;
	private: System::Windows::Forms::Panel^ pnData;
	private: System::Windows::Forms::Button^ button5;
		history^ hist;
		database^ data;

		/*void mdiProp() {
			mdi->SetBevel(this, false);
			MdiClient^ client = nullptr;

			for each (Control ^ control in this->Controls) {
				client = dynamic_cast<MdiClient^>(control);
				if (client != nullptr) {
					break;
				}
			}

			if (client != nullptr) {
				client->BackColor = Color::FromArgb(255, 255, 255);
			}
		}*/


#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->components = (gcnew System::ComponentModel::Container());
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(engine::typeid));
			this->panel1 = (gcnew System::Windows::Forms::Panel());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->btnMenu = (gcnew System::Windows::Forms::PictureBox());
			this->sidebar = (gcnew System::Windows::Forms::FlowLayoutPanel());
			this->pnSearch = (gcnew System::Windows::Forms::Panel());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->pnHistory = (gcnew System::Windows::Forms::Panel());
			this->button4 = (gcnew System::Windows::Forms::Button());
			this->pnNext = (gcnew System::Windows::Forms::Panel());
			this->button3 = (gcnew System::Windows::Forms::Button());
			this->pnPrev = (gcnew System::Windows::Forms::Panel());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->pnData = (gcnew System::Windows::Forms::Panel());
			this->button5 = (gcnew System::Windows::Forms::Button());
			this->sidebarTransition = (gcnew System::Windows::Forms::Timer(this->components));
			this->panel1->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->btnMenu))->BeginInit();
			this->sidebar->SuspendLayout();
			this->pnSearch->SuspendLayout();
			this->pnHistory->SuspendLayout();
			this->pnNext->SuspendLayout();
			this->pnPrev->SuspendLayout();
			this->pnData->SuspendLayout();
			this->SuspendLayout();
			// 
			// panel1
			// 
			this->panel1->BackColor = System::Drawing::Color::Gainsboro;
			this->panel1->Controls->Add(this->label1);
			this->panel1->Controls->Add(this->btnMenu);
			this->panel1->Dock = System::Windows::Forms::DockStyle::Top;
			this->panel1->Location = System::Drawing::Point(0, 0);
			this->panel1->Name = L"panel1";
			this->panel1->Size = System::Drawing::Size(879, 38);
			this->panel1->TabIndex = 0;
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->BackColor = System::Drawing::Color::Transparent;
			this->label1->Font = (gcnew System::Drawing::Font(L"Segoe UI", 15, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label1->Location = System::Drawing::Point(51, 3);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(179, 35);
			this->label1->TabIndex = 2;
			this->label1->Text = L"Search Engine";
			this->label1->Click += gcnew System::EventHandler(this, &engine::label1_Click);
			// 
			// btnMenu
			// 
			this->btnMenu->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"btnMenu.Image")));
			this->btnMenu->Location = System::Drawing::Point(13, 1);
			this->btnMenu->Name = L"btnMenu";
			this->btnMenu->Size = System::Drawing::Size(32, 34);
			this->btnMenu->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->btnMenu->TabIndex = 1;
			this->btnMenu->TabStop = false;
			this->btnMenu->Click += gcnew System::EventHandler(this, &engine::pictureBox1_Click);
			this->btnMenu->MouseClick += gcnew System::Windows::Forms::MouseEventHandler(this, &engine::btnMenu_MouseClick);
			// 
			// sidebar
			// 
			this->sidebar->BackColor = System::Drawing::Color::Black;
			this->sidebar->Controls->Add(this->pnSearch);
			this->sidebar->Controls->Add(this->pnHistory);
			this->sidebar->Controls->Add(this->pnNext);
			this->sidebar->Controls->Add(this->pnPrev);
			this->sidebar->Controls->Add(this->pnData);
			this->sidebar->Dock = System::Windows::Forms::DockStyle::Left;
			this->sidebar->FlowDirection = System::Windows::Forms::FlowDirection::TopDown;
			this->sidebar->Location = System::Drawing::Point(0, 38);
			this->sidebar->Name = L"sidebar";
			this->sidebar->Size = System::Drawing::Size(62, 531);
			this->sidebar->TabIndex = 1;
			// 
			// pnSearch
			// 
			this->pnSearch->Anchor = System::Windows::Forms::AnchorStyles::Left;
			this->pnSearch->Controls->Add(this->button1);
			this->pnSearch->Location = System::Drawing::Point(3, 3);
			this->pnSearch->Name = L"pnSearch";
			this->pnSearch->Size = System::Drawing::Size(187, 47);
			this->pnSearch->TabIndex = 3;
			// 
			// button1
			// 
			this->button1->BackColor = System::Drawing::Color::Black;
			this->button1->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10.2F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->button1->ForeColor = System::Drawing::Color::White;
			this->button1->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"button1.Image")));
			this->button1->ImageAlign = System::Drawing::ContentAlignment::MiddleLeft;
			this->button1->Location = System::Drawing::Point(-13, -19);
			this->button1->Name = L"button1";
			this->button1->Padding = System::Windows::Forms::Padding(17, 3, 0, 0);
			this->button1->Size = System::Drawing::Size(222, 81);
			this->button1->TabIndex = 2;
			this->button1->Text = L"            search";
			this->button1->TextAlign = System::Drawing::ContentAlignment::MiddleLeft;
			this->button1->UseVisualStyleBackColor = false;
			this->button1->Click += gcnew System::EventHandler(this, &engine::button1_Click);
			// 
			// pnHistory
			// 
			this->pnHistory->Anchor = System::Windows::Forms::AnchorStyles::Left;
			this->pnHistory->Controls->Add(this->button4);
			this->pnHistory->Location = System::Drawing::Point(3, 56);
			this->pnHistory->Name = L"pnHistory";
			this->pnHistory->Size = System::Drawing::Size(187, 47);
			this->pnHistory->TabIndex = 4;
			// 
			// button4
			// 
			this->button4->BackColor = System::Drawing::Color::Black;
			this->button4->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10.2F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->button4->ForeColor = System::Drawing::Color::White;
			this->button4->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"button4.Image")));
			this->button4->ImageAlign = System::Drawing::ContentAlignment::MiddleLeft;
			this->button4->Location = System::Drawing::Point(-13, -19);
			this->button4->Name = L"button4";
			this->button4->Padding = System::Windows::Forms::Padding(17, 3, 0, 0);
			this->button4->Size = System::Drawing::Size(222, 81);
			this->button4->TabIndex = 2;
			this->button4->Text = L"            history";
			this->button4->TextAlign = System::Drawing::ContentAlignment::MiddleLeft;
			this->button4->UseVisualStyleBackColor = false;
			this->button4->Click += gcnew System::EventHandler(this, &engine::button4_Click);
			// 
			// pnNext
			// 
			this->pnNext->Anchor = System::Windows::Forms::AnchorStyles::Left;
			this->pnNext->Controls->Add(this->button3);
			this->pnNext->Location = System::Drawing::Point(3, 109);
			this->pnNext->Name = L"pnNext";
			this->pnNext->Size = System::Drawing::Size(187, 47);
			this->pnNext->TabIndex = 4;
			// 
			// button3
			// 
			this->button3->BackColor = System::Drawing::Color::Black;
			this->button3->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10.2F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->button3->ForeColor = System::Drawing::Color::White;
			this->button3->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"button3.Image")));
			this->button3->ImageAlign = System::Drawing::ContentAlignment::MiddleLeft;
			this->button3->Location = System::Drawing::Point(-13, -19);
			this->button3->Name = L"button3";
			this->button3->Padding = System::Windows::Forms::Padding(17, 3, 0, 0);
			this->button3->Size = System::Drawing::Size(222, 81);
			this->button3->TabIndex = 2;
			this->button3->Text = L"            next";
			this->button3->TextAlign = System::Drawing::ContentAlignment::MiddleLeft;
			this->button3->UseVisualStyleBackColor = false;
			this->button3->Click += gcnew System::EventHandler(this, &engine::button3_Click);
			// 
			// pnPrev
			// 
			this->pnPrev->Anchor = System::Windows::Forms::AnchorStyles::Left;
			this->pnPrev->Controls->Add(this->button2);
			this->pnPrev->Location = System::Drawing::Point(3, 162);
			this->pnPrev->Name = L"pnPrev";
			this->pnPrev->Size = System::Drawing::Size(187, 47);
			this->pnPrev->TabIndex = 4;
			// 
			// button2
			// 
			this->button2->BackColor = System::Drawing::Color::Black;
			this->button2->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10.2F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->button2->ForeColor = System::Drawing::Color::White;
			this->button2->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"button2.Image")));
			this->button2->ImageAlign = System::Drawing::ContentAlignment::MiddleLeft;
			this->button2->Location = System::Drawing::Point(-13, -19);
			this->button2->Name = L"button2";
			this->button2->Padding = System::Windows::Forms::Padding(17, 3, 0, 0);
			this->button2->Size = System::Drawing::Size(222, 81);
			this->button2->TabIndex = 2;
			this->button2->Text = L"            previous";
			this->button2->TextAlign = System::Drawing::ContentAlignment::MiddleLeft;
			this->button2->UseVisualStyleBackColor = false;
			this->button2->Click += gcnew System::EventHandler(this, &engine::button2_Click);
			// 
			// pnData
			// 
			this->pnData->Anchor = System::Windows::Forms::AnchorStyles::Left;
			this->pnData->Controls->Add(this->button5);
			this->pnData->Location = System::Drawing::Point(3, 215);
			this->pnData->Name = L"pnData";
			this->pnData->Size = System::Drawing::Size(187, 47);
			this->pnData->TabIndex = 5;
			// 
			// button5
			// 
			this->button5->BackColor = System::Drawing::Color::Black;
			this->button5->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10.2F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->button5->ForeColor = System::Drawing::Color::White;
			this->button5->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"button5.Image")));
			this->button5->ImageAlign = System::Drawing::ContentAlignment::MiddleLeft;
			this->button5->Location = System::Drawing::Point(-13, -19);
			this->button5->Name = L"button5";
			this->button5->Padding = System::Windows::Forms::Padding(17, 3, 0, 0);
			this->button5->Size = System::Drawing::Size(222, 81);
			this->button5->TabIndex = 2;
			this->button5->Text = L"            dataBase";
			this->button5->TextAlign = System::Drawing::ContentAlignment::MiddleLeft;
			this->button5->UseVisualStyleBackColor = false;
			this->button5->Click += gcnew System::EventHandler(this, &engine::button5_Click);
			// 
			// sidebarTransition
			// 
			this->sidebarTransition->Interval = 10;
			this->sidebarTransition->Tick += gcnew System::EventHandler(this, &engine::sidebarTransition_Tick);
			// 
			// engine
			// 
			this->BackColor = System::Drawing::Color::White;
			this->ClientSize = System::Drawing::Size(879, 569);
			this->Controls->Add(this->sidebar);
			this->Controls->Add(this->panel1);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::Fixed3D;
			this->IsMdiContainer = true;
			this->Name = L"engine";
			this->Load += gcnew System::EventHandler(this, &engine::engine_Load);
			this->panel1->ResumeLayout(false);
			this->panel1->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->btnMenu))->EndInit();
			this->sidebar->ResumeLayout(false);
			this->pnSearch->ResumeLayout(false);
			this->pnHistory->ResumeLayout(false);
			this->pnNext->ResumeLayout(false);
			this->pnPrev->ResumeLayout(false);
			this->pnData->ResumeLayout(false);
			this->ResumeLayout(false);

		}
#pragma endregion
		bool sidebarExpand = false;
private:  System::Void sidebarTransition_Tick(System::Object^ sender, System::EventArgs^ e) {
	if (sidebarExpand) {
		sidebar->Width -= 10;
		if (sidebar->Width <= 62) {
			sidebarExpand = false;
			sidebarTransition->Stop();

			pnSearch->Width = sidebar->Width;
			pnPrev->Width = sidebar->Width;
			pnNext->Width = sidebar->Width;
			pnHistory->Width = sidebar->Width;
			pnData->Width = sidebar->Width;
		}
	}
	else {
		sidebar->Width += 10;
		if (sidebar->Width >= 198) {
			sidebarExpand = true;
			sidebarTransition->Stop();

			pnSearch->Width = sidebar->Width;
			pnPrev->Width = sidebar->Width;
			pnNext->Width = sidebar->Width;
			pnHistory->Width = sidebar->Width;
			pnData->Width = sidebar->Width;

		}
	}
}
private: System::Void pictureBox1_Click(System::Object^ sender, System::EventArgs^ e) {
	sidebarTransition->Start();
}

private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) {
	if (ser == nullptr) {
		ser = gcnew search();
		ser->FormClosed += gcnew System::Windows::Forms::FormClosedEventHandler(this, &engine::ser_FormClosed);
		ser->MdiParent = this;
		ser->StartPosition = FormStartPosition::Manual;
		ser->Location = Point(0, 0); // Set the desired starting position here
		ser->Width = this->Width - sidebar->Width;
		ser->Height = this->Height - panel1->Height;
		ser->WindowState = FormWindowState::Maximized; // Scale to parent size
		ser->Show();
	}
	else {
		ser->Activate();
	}
}
private: System::Void ser_FormClosed(System::Object^ sender, System::Windows::Forms::FormClosedEventArgs^ e) {
	ser = nullptr;
}
private: System::Void button2_Click(System::Object^ sender, System::EventArgs^ e) {
	if (prev == nullptr) {
		prev = gcnew previous();
		prev->FormClosed += gcnew System::Windows::Forms::FormClosedEventHandler(this, &engine::prev_FormClosed);
		prev->MdiParent = this;
		prev->StartPosition = FormStartPosition::Manual;
		prev->Location = Point(0, 0); // Set the desired starting position here
		prev->Width = this->Width - sidebar->Width;
		prev->Height = this->Height - panel1->Height;
		prev->WindowState = FormWindowState::Maximized; // Scale to parent size
		prev->Show();
	}
	else {
		prev->Activate();
	}
}
private: System::Void prev_FormClosed(System::Object^ sender, System::Windows::Forms::FormClosedEventArgs^ e) {
	prev = nullptr;
}
private: System::Void button3_Click(System::Object^ sender, System::EventArgs^ e) {
	if (nex == nullptr) {
		nex = gcnew next();
		nex->FormClosed += gcnew System::Windows::Forms::FormClosedEventHandler(this, &engine::nex_FormClosed);
		nex->MdiParent = this;
		nex->StartPosition = FormStartPosition::Manual;
		nex->Location = Point(0, 0); // Set the desired starting position here
		nex->Width = this->Width - sidebar->Width;
		nex->Height = this->Height - panel1->Height;
		nex->WindowState = FormWindowState::Maximized; // Scale to parent size
		nex->Show();
	}
	else {
		nex->Activate();
	}
}
private: System::Void nex_FormClosed(System::Object ^ sender, System::Windows::Forms::FormClosedEventArgs ^ e) {
	nex = nullptr;
}
private: System::Void button4_Click(System::Object^ sender, System::EventArgs^ e) {
	if (hist == nullptr) {
		hist = gcnew history();
		hist->FormClosed += gcnew System::Windows::Forms::FormClosedEventHandler(this, &engine::hist_FormClosed);
		hist->MdiParent = this;
		hist->StartPosition = FormStartPosition::Manual;
		hist->Location = Point(0, 0); // Set the desired starting position here
		hist->Width = this->Width - sidebar->Width;
		hist->Height = this->Height - panel1->Height;
		hist->WindowState = FormWindowState::Maximized; // Scale to parent size
		hist->Show();
	}
	else {
		hist->Activate();
	}
}
private: System::Void hist_FormClosed(System::Object^ sender, System::Windows::Forms::FormClosedEventArgs^ e) {
	hist = nullptr;
}
private: System::Void button5_Click(System::Object^ sender, System::EventArgs^ e) {
	if (data == nullptr) {
		data = gcnew database();
		data->FormClosed += gcnew System::Windows::Forms::FormClosedEventHandler(this, &engine::data_FormClosed);
		data->MdiParent = this;
		data->StartPosition = FormStartPosition::Manual;
		data->Location = Point(0, 0); // Set the desired starting position here
		data->Width = this->Width - sidebar->Width;
		data->Height = this->Height - panel1->Height;
		data->WindowState = FormWindowState::Maximized; // Scale to parent size
		data->Show();
	}
	else {
		data->Activate();
	}
}
private: System::Void data_FormClosed(System::Object^ sender, System::Windows::Forms::FormClosedEventArgs^ e) {
	data = nullptr;
}

private: System::Void btnMenu_MouseClick(System::Object^ sender, System::Windows::Forms::MouseEventArgs^ e) {
}
private: System::Void label1_Click(System::Object^ sender, System::EventArgs^ e) {
}

private: System::Void engine_Load(System::Object^ sender, System::EventArgs^ e) {

}


};
}

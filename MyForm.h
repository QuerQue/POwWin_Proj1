#pragma once
#include <stdlib.h>
#include <stdio.h>
#include <string>
using namespace std;
using namespace System::IO;
namespace Project1 {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for MyForm
	/// </summary>
	public ref class MyForm : public System::Windows::Forms::Form
	{
	public:
		MyForm(void)
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
		~MyForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Button^  button1;
	private: System::Windows::Forms::Button^  btnOpen;
	private: System::Windows::Forms::OpenFileDialog^  openLas;
	private: System::Windows::Forms::Button^  button2;
	private: System::Windows::Forms::ComboBox^  comboBox1;



	protected: 

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
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->btnOpen = (gcnew System::Windows::Forms::Button());
			this->openLas = (gcnew System::Windows::Forms::OpenFileDialog());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->comboBox1 = (gcnew System::Windows::Forms::ComboBox());
			this->SuspendLayout();
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(171, 2);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(61, 22);
			this->button1->TabIndex = 0;
			this->button1->Text = L"Exit";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &MyForm::button1_Click);
			// 
			// btnOpen
			// 
			this->btnOpen->Location = System::Drawing::Point(4, 2);
			this->btnOpen->Name = L"btnOpen";
			this->btnOpen->Size = System::Drawing::Size(65, 23);
			this->btnOpen->TabIndex = 1;
			this->btnOpen->Text = L"Open";
			this->btnOpen->UseVisualStyleBackColor = true;
			this->btnOpen->Click += gcnew System::EventHandler(this, &MyForm::btnOpen_Click);
			// 
			// openLas
			// 
			this->openLas->FileName = L"openFileDialog1";
			// 
			// button2
			// 
			this->button2->Location = System::Drawing::Point(238, 2);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(65, 22);
			this->button2->TabIndex = 2;
			this->button2->Text = L"Show";
			this->button2->UseVisualStyleBackColor = true;
			// 
			// comboBox1
			// 
			this->comboBox1->FormattingEnabled = true;
			this->comboBox1->Location = System::Drawing::Point(75, 3);
			this->comboBox1->Name = L"comboBox1";
			this->comboBox1->Size = System::Drawing::Size(86, 21);
			this->comboBox1->TabIndex = 3;
			this->comboBox1->SelectedIndexChanged += gcnew System::EventHandler(this, &MyForm::comboBox1_SelectedIndexChanged);
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(552, 262);
			this->Controls->Add(this->comboBox1);
			this->Controls->Add(this->button2);
			this->Controls->Add(this->btnOpen);
			this->Controls->Add(this->button1);
			this->Name = L"MyForm";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"MyForm";
			this->ResumeLayout(false);

		}
#pragma endregion
	private: System::Void button1_Click(System::Object^  sender, System::EventArgs^  e) {
				 Application::Exit();
			 }

	private: System::Void btnOpen_Click(System::Object^  sender, System::EventArgs^  e) {
				 Stream^ myStream;
			  OpenFileDialog^ openFileDialog1 = gcnew OpenFileDialog;

			  openFileDialog1->InitialDirectory = "c:\\";
			  openFileDialog1->Filter = "txt files (*.las)|*.las|All files (*.*)|*.*";
			  openFileDialog1->FilterIndex = 2;
			  openFileDialog1->RestoreDirectory = true;

			  FILE* fp; 
			  char strf[20];
			  String^ stra;
			  sprintf(strf, "%s",openFileDialog1->SafeFileName);
			  fp = fopen(strf,"r");
			  if(fp = NULL)
			 {
				printf("Error in opening");
				exit(0);
			 }
			 

			  char c;
			  char arr[80];
			  if ( openFileDialog1->ShowDialog() == System::Windows::Forms::DialogResult::OK )
			  {
				  while((c=fscanf(fp, "%s", arr)) != EOF){
					  
					  //MessageBox::Show();
					  comboBox1->Items->Add(stra);
				  }
				  /*
				 if ( (myStream = openFileDialog1->OpenFile()) != nullptr )
				 {
					StreamReader^ sr = gcnew StreamReader(openFileDialog1->FileName);
					 for (;;) {

			
                    String^ line = sr->ReadLine();
                    if (line == nullptr) break;
					

					comboBox1->Items->Add( line );
					//MessageBox::Show(line);
				  }

					myStream->Close();
				 }
				 */
			  }
	

	private: System::Void comboBox1_SelectedIndexChanged(System::Object^  sender, System::EventArgs^  e) {

			 }
};
}

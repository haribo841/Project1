#pragma once
#include <Windows.h>

namespace Project1 {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Podsumowanie informacji o MyForm
	/// </summary>
	public ref class MainForm : public System::Windows::Forms::Form
	{
	public:
		MainForm(void)
		{
			InitializeComponent();
			//
			//TODO: kod konstruktora
			//
			openImage->Click += gcnew System::EventHandler(this, &MainForm::openImage_Click);
		}

	protected:
		/// <summary>
		/// Wyczyœæ wszystkie u¿ywane zasoby.
		/// </summary>
		~MainForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private:
		bool imageLoaded = false;
	private: System::Windows::Forms::Button^ openImage;

	private: System::Windows::Forms::PictureBox^ pictureBox1;
	private: System::Windows::Forms::OpenFileDialog^ openFileDialog1;
	protected:

	private:
		/// <summary>
		/// Wymagana zmienna projektanta.
		/// </summary>
		System::ComponentModel::Container^ components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Metoda wymagana do obs³ugi projektanta — nie nale¿y modyfikowaæ
		/// jej zawartoœci w edytorze kodu.
		/// </summary>
	private: System::Void openImage_Click(System::Object^ sender, System::EventArgs^ e);

		   void InitializeComponent(void)
		   {
			   this->openImage = (gcnew System::Windows::Forms::Button());
			   this->pictureBox1 = (gcnew System::Windows::Forms::PictureBox());
			   this->openFileDialog1 = (gcnew System::Windows::Forms::OpenFileDialog());
			   (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->BeginInit();
			   this->SuspendLayout();
			   // 
			   // openImage
			   // 
			   this->openImage->Location = System::Drawing::Point(53, 103);
			   this->openImage->Name = L"openImage";
			   this->openImage->Size = System::Drawing::Size(75, 23);
			   this->openImage->TabIndex = 0;
			   this->openImage->Text = L"Open Image";
			   this->openImage->UseVisualStyleBackColor = true;
			   this->openImage->Click += gcnew System::EventHandler(this, &MainForm::openImage_Click);
			   // 
			   // pictureBox1
			   // 
			   this->pictureBox1->Location = System::Drawing::Point(155, 87);
			   this->pictureBox1->Name = L"pictureBox1";
			   this->pictureBox1->Size = System::Drawing::Size(640, 480);
			   this->pictureBox1->TabIndex = 1;
			   this->pictureBox1->TabStop = false;
			   this->pictureBox1->Click += gcnew System::EventHandler(this, &MainForm::pictureBox1_Click);
			   // 
			   // openFileDialog1
			   // 
			   this->openFileDialog1->FileName = L"openFileDialog1";
			   this->openFileDialog1->FileOk += gcnew System::ComponentModel::CancelEventHandler(this, &MainForm::openFileDialog1_FileOk);
			   // 
			   // MainForm
			   // 
			   this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			   this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			   this->ClientSize = System::Drawing::Size(1006, 673);
			   this->Controls->Add(this->pictureBox1);
			   this->Controls->Add(this->openImage);
			   this->Name = L"MainForm";
			   this->Text = L"MainForm";
			   (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->EndInit();
			   this->ResumeLayout(false);

		   }
#pragma endregion
	private: System::Void pictureBox1_Click(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void openFileDialog1_FileOk(System::Object^ sender, System::ComponentModel::CancelEventArgs^ e) {
	}
	};// Funkcja obs³ugi zdarzeñ dla przycisku openImage
	System::Void MainForm::openImage_Click(System::Object^ sender, System::EventArgs^ e)
	{
		if (!imageLoaded)  // SprawdŸ, czy obraz nie zosta³ wczytany wczeœniej
		{
			if (openFileDialog1->ShowDialog() == System::Windows::Forms::DialogResult::OK)
			{
				System::String^ imagePath = openFileDialog1->FileName;
				if (!imagePath->Equals(""))
				{
					System::Drawing::Image^ loadedImage = System::Drawing::Image::FromFile(imagePath);
					pictureBox1->Image = loadedImage;
					imageLoaded = true;  // Ustaw flagê na true, aby oznaczyæ, ¿e obraz zosta³ wczytany
					openImage->Enabled = false;  // Wy³¹cz przycisk
				}
			}
		}
	}

}

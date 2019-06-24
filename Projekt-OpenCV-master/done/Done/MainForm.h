#include <opencv2\core\core.hpp>
#include <opencv2\highgui\highgui.hpp>
#include <opencv2\imgproc\imgproc.hpp>
#include <stdio.h>
#include <iostream>
#include <conio.h> 
#include "opencv2/objdetect.hpp"
#include <msclr\marshal_cppstd.h>
#include<opencv2/opencv.hpp>
namespace done {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace std;
	
	using namespace cv;
	using namespace msclr::interop;

	Mat frame;
	

	public ref class MainForm : public System::Windows::Forms::Form
	{
	public:
		MainForm(void)
		{
			InitializeComponent();
			
		}

	protected:
		/// <summary>
		
		/// </summary>
		~MainForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Button^  btnBrowser;

	private: System::Windows::Forms::Button^  btn_stop;
	private: System::Windows::Forms::OpenFileDialog^  openFileDialog1;

	private: System::Windows::Forms::Label^  label8;

	private: System::Windows::Forms::Label^  label9;
	private: System::Windows::Forms::Label^  label10;
	private: System::Windows::Forms::Label^  label11;
	private: System::Windows::Forms::Label^  label12;
	private: System::Windows::Forms::Label^  label13;
	private: System::Windows::Forms::Label^  label14;
	private: System::Windows::Forms::Label^  label15;
	private: System::Windows::Forms::Label^  label1;


	protected:

	protected:

	private:
		/// <summary>
		/// 
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// 
		/// 
		/// </summary>
		void InitializeComponent(void)
		{
			this->btnBrowser = (gcnew System::Windows::Forms::Button());
			this->btn_stop = (gcnew System::Windows::Forms::Button());
			this->openFileDialog1 = (gcnew System::Windows::Forms::OpenFileDialog());
			this->label8 = (gcnew System::Windows::Forms::Label());
			this->label9 = (gcnew System::Windows::Forms::Label());
			this->label10 = (gcnew System::Windows::Forms::Label());
			this->label11 = (gcnew System::Windows::Forms::Label());
			this->label12 = (gcnew System::Windows::Forms::Label());
			this->label13 = (gcnew System::Windows::Forms::Label());
			this->label14 = (gcnew System::Windows::Forms::Label());
			this->label15 = (gcnew System::Windows::Forms::Label());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->SuspendLayout();
			// 
			// btnBrowser
			// 
			this->btnBrowser->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(238)));
			this->btnBrowser->Location = System::Drawing::Point(13, 20);
			this->btnBrowser->Margin = System::Windows::Forms::Padding(4);
			this->btnBrowser->Name = L"btnBrowser";
			this->btnBrowser->Size = System::Drawing::Size(129, 37);
			this->btnBrowser->TabIndex = 0;
			this->btnBrowser->Text = L"Wybierz film";
			this->btnBrowser->UseVisualStyleBackColor = true;
			this->btnBrowser->Click += gcnew System::EventHandler(this, &MainForm::btnBrowser_Click);
			// 
			// btn_stop
			// 
			this->btn_stop->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(238)));
			this->btn_stop->Location = System::Drawing::Point(149, 20);
			this->btn_stop->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->btn_stop->Name = L"btn_stop";
			this->btn_stop->Size = System::Drawing::Size(123, 37);
			this->btn_stop->TabIndex = 6;
			this->btn_stop->Text = L"Grayscale";
			this->btn_stop->UseVisualStyleBackColor = true;
			this->btn_stop->Click += gcnew System::EventHandler(this, &MainForm::button1_Click);
			// 
			// openFileDialog1
			// 
			this->openFileDialog1->FileName = L"openFileDialog1";
			// 
			// label8
			// 
			this->label8->AutoSize = true;
			this->label8->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(238)));
			this->label8->Location = System::Drawing::Point(392, 48);
			this->label8->Name = L"label8";
			this->label8->Size = System::Drawing::Size(299, 25);
			this->label8->TabIndex = 8;
			this->label8->Text = L"Iloœæ wykrytych w tym momencie:";
			// 
			// label9
			// 
			this->label9->AutoSize = true;
			this->label9->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(238)));
			this->label9->Location = System::Drawing::Point(392, 9);
			this->label9->Name = L"label9";
			this->label9->Size = System::Drawing::Size(447, 25);
			this->label9->TabIndex = 11;
			this->label9->Text = L"Program wykrywaj¹cy i zliczaj¹cy samochody";
			// 
			// label10
			// 
			this->label10->AutoSize = true;
			this->label10->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(238)));
			this->label10->Location = System::Drawing::Point(398, 84);
			this->label10->Name = L"label10";
			this->label10->Size = System::Drawing::Size(26, 25);
			this->label10->TabIndex = 12;
			this->label10->Text = L"X";
			// 
			// label11
			// 
			this->label11->AutoSize = true;
			this->label11->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(238)));
			this->label11->Location = System::Drawing::Point(470, 84);
			this->label11->Name = L"label11";
			this->label11->Size = System::Drawing::Size(23, 25);
			this->label11->TabIndex = 13;
			this->label11->Text = L"0";
			// 
			// label12
			// 
			this->label12->AutoSize = true;
			this->label12->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(238)));
			this->label12->Location = System::Drawing::Point(398, 109);
			this->label12->Name = L"label12";
			this->label12->Size = System::Drawing::Size(25, 25);
			this->label12->TabIndex = 14;
			this->label12->Text = L"Y";
			// 
			// label13
			// 
			this->label13->AutoSize = true;
			this->label13->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(238)));
			this->label13->Location = System::Drawing::Point(470, 110);
			this->label13->Name = L"label13";
			this->label13->Size = System::Drawing::Size(23, 25);
			this->label13->TabIndex = 15;
			this->label13->Text = L"0";
			// 
			// label14
			// 
			this->label14->AutoSize = true;
			this->label14->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(238)));
			this->label14->Location = System::Drawing::Point(398, 159);
			this->label14->Name = L"label14";
			this->label14->Size = System::Drawing::Size(75, 25);
			this->label14->TabIndex = 16;
			this->label14->Text = L"SUMA";
			// 
			// label15
			// 
			this->label15->AutoSize = true;
			this->label15->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(238)));
			this->label15->Location = System::Drawing::Point(723, 159);
			this->label15->Name = L"label15";
			this->label15->Size = System::Drawing::Size(17, 25);
			this->label15->TabIndex = 17;
			this->label15->Text = L" ";
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(238)));
			this->label1->Location = System::Drawing::Point(733, 48);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(23, 25);
			this->label1->TabIndex = 18;
			this->label1->Text = L"0";
			this->label1->Click += gcnew System::EventHandler(this, &MainForm::label1_Click);
			// 
			// MainForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(873, 294);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->label15);
			this->Controls->Add(this->label14);
			this->Controls->Add(this->label13);
			this->Controls->Add(this->label12);
			this->Controls->Add(this->label11);
			this->Controls->Add(this->label10);
			this->Controls->Add(this->label9);
			this->Controls->Add(this->label8);
			this->Controls->Add(this->btn_stop);
			this->Controls->Add(this->btnBrowser);
			this->Margin = System::Windows::Forms::Padding(4);
			this->Name = L"MainForm";
			this->Text = L" ";
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion

#pragma endregion


	private: System::Void btnBrowser_Click(System::Object^  sender, System::EventArgs^  e)
	{
		const string cascade_name("cascade2.xml");
		CascadeClassifier cascade;

		if (!cascade.load(cascade_name)) {
			cout << "B³¹d ³adowania pliku xml";
			return ;
		}
		openFileDialog1->ShowDialog();

		VideoCapture capture;
		

		System::String^ managedString;

		managedString = openFileDialog1->FileName;

		string stringPointer = marshal_as<std::string>(managedString);

		
		capture.open(stringPointer);
		

		if (!capture.isOpened()) {
			cout << "B³¹d otwarcia Ÿród³a obrazu";
			return ;
		}
		
	
		int suma=0;
	
		while (capture.read(frame)) {
		
			if (frame.empty()) {
				cout << "Brak przechwyconej ramki!\n";
				return ;
			}
			Mat frame_gray;
			cvtColor(frame, frame_gray, COLOR_BGR2GRAY);
			equalizeHist(frame_gray, frame_gray);
			
			vector<Rect> faces;
			line(frame, cv::Point(0, (frame.rows/4)), cv::Point(frame.cols, (frame.rows/4)), Scalar(110, 220, 0), 2, 8);
			cascade.detectMultiScale(frame_gray, faces);
			
			int licznik = 0;
			int count2 = 0;
			for (auto& face : faces) {
				
				rectangle(frame, face, Scalar(255, 255, 0), 2);
				count2++;

				label1->Text = count2.ToString();
				face.x;
				face.y;
				licznik++;
				label11->Text = face.x.ToString();
				label13->Text = face.y.ToString();
				if (face.y == (frame.rows / 4))
				{
					suma++;
					line(frame, cv::Point(0, (frame.rows / 4)), cv::Point(frame.cols, (frame.rows / 4)), Scalar(215, 0, 0), 2, 8);
					
				}
				
				label15->Text = suma.ToString();
				
			}
			
			imshow("Cascade", frame);
			if (waitKey(10) == 27)
				break;
		//	resize(frame, frame, cv::Size(320, 240));
			//ptbVideo->Image = mat2bmp.Mat2Bimap(frame); // Mat convert to BMP we use from jackylib library
			//ptbVideo->Refresh();
		}
		
		capture.release();
		
		return ;
	}
	
	private: System::Void btnProcess_Click(System::Object^  sender, System::EventArgs^  e) {

	}
	
			 
	private: System::Void ptbVideo_Click(System::Object^  sender, System::EventArgs^  e) {
	}
private: System::Void textBox1_TextChanged(System::Object^  sender, System::EventArgs^  e) {

}
		 //=======================================
private: System::Void button1_Click(System::Object^  sender, System::EventArgs^  e) {
	
	const string cascade_name("cascade2.xml");
	CascadeClassifier cascade;

	if (!cascade.load(cascade_name)) {
		cout << "Error loading face cascade\n";
		return;
	}

	VideoCapture capture;

	capture.open("video.avi");
	//capture.open("video1.avi");

	if (!capture.isOpened()) {
		cout << "Error opening video capture";
		return;
	}
	int suma = 0;
	
	while (capture.read(frame)) {

		if (frame.empty()) {
			cout << "No capture frame!\n";
			return;
		}
		Mat frame_gray;
		cvtColor(frame, frame_gray, COLOR_BGR2GRAY);
		equalizeHist(frame_gray, frame_gray);

		vector<Rect> faces;
		line(frame, cv::Point(0, (frame.rows / 4)), cv::Point(frame.cols, (frame.rows / 4)), Scalar(110, 220, 0), 2, 8);
		cascade.detectMultiScale(frame_gray, faces);

		
		int count = 0;
		for (auto& face : faces) {
			
			rectangle(frame, face, Scalar(255, 255, 0), 2);
			count++;
			
			label1->Text = count.ToString();
		
			face.x;
			face.y;
			
			label11->Text = face.x.ToString();
			label13->Text = face.y.ToString();
			if (face.y == (frame.rows / 4))
			{
				suma++;
				line(frame, cv::Point(0, (frame.rows / 4)), cv::Point(frame.cols, (frame.rows / 4)), Scalar(215, 0, 0), 2, 8);

			}
			
			label15->Text = suma.ToString();
			

		}
		
		cvtColor(frame, frame, COLOR_RGB2GRAY);
		imshow("Cascade", frame);
		if (waitKey(10) == 27)
			break;
		//	resize(frame, frame, cv::Size(320, 240));
			//ptbVideo->Image = mat2bmp.Mat2Bimap(frame); // Mat convert to BMP we use from jackylib library
			//ptbVideo->Refresh();
	}

	capture.release();

	return;
}
		 //=======================================
private: System::Void checkBox1_Click(System::Object^  sender, System::EventArgs^  e) {
	
}
private: System::Void label1_Click(System::Object^  sender, System::EventArgs^  e) {
}
};



}

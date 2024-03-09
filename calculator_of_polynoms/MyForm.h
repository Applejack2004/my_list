#pragma once
#include"../my_list/TPolinom.h"
#include"msclr\marshal_cppstd.h"
#include <algorithm>
#include<vector>
std::vector<TPolinom> V;
int i = 0 ;
int f = 1;
TPolinom check;
namespace calculatorofpolynoms {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Data::OleDb;
	using namespace System::Drawing;
	using namespace System::IO;

	/// <summary>
	/// Сводка для MyForm
	/// </summary>
	public ref class MyForm : public System::Windows::Forms::Form
	{
	public:
	

		MyForm(void)
		{
			
			InitializeComponent();

		}
		int count_oper(std::string s) {
			int count = 0;

			for (int i = 0; i < s.size(); i++)
				if (s[i] == '+' || s[i] == '-' || s[i] == '*') count++;

			return count;
		}
		void doSom()
		{
			DataGridViewTextBoxColumn^ column0 = gcnew DataGridViewTextBoxColumn();
			column0->Name = "num";
			column0->HeaderText = "Номер";
			DataGridViewTextBoxColumn^ column1 = gcnew DataGridViewTextBoxColumn();
			column1->Name = "Polynom";
			column1->HeaderText = "Полином";
		}
		TPolinom Polinomoperation(std::string& operation, std::vector<TPolinom>& polyVector)
		{
			size_t pos = operation.find_first_of("+-*="); // Ищем позицию любого из символов "+", "-", "*", "="
			int count = count_oper(operation);
			if (count > 1)
			{
				label4->Text = "More then 1 operation!!!";
				f = 1;
				return TPolinom();
			}
			if (pos != std::string::npos && pos > 0 && pos < operation.size() - 1)
			{
				char operationChar = operation[pos]; // Получаем символ операции
				int index1;
				int index2;
					if (operation[pos + 1] == '=')
					{
						operationChar = '=';
						pos++;
						 index1 = std::stoi(operation.substr(0, pos - 2)) - 1;
						 index2 = std::stoi(operation.substr(pos + 1, operation.size())) - 1;
					}
					else
					{
						 index1 = std::stoi(operation.substr(0, pos - 1)) - 1;
						 index2 = std::stoi(operation.substr(pos + 1, operation.size())) - 1;

					}
				
				TPolinom result;
				// Извлекаем индексы из строки операции
				

				if (index1 >= 0 && index1 < polyVector.size() && index2 >= 0 && index2 < polyVector.size())
				{

					switch (operationChar)
					{

					case '+':
						//result = P1 + P2;
						f = 0;
						return polyVector[index1] + polyVector[index2];
					case '-':
						f = 0;
						//result = P1 - P2;
						return polyVector[index1] - polyVector[index2];
					case '*':
						f = 0;
						//result = P1 * P2;
						return polyVector[index1] * polyVector[index2];
					case '=':
						f = 0;
						//result = P1 += P2;
						return polyVector[index1] += polyVector[index2];
					default:
						label4->Text = "Unsupported operation!";
						f = 1;
					}
				}
				else
				{
					label4->Text = "Invalid operation format!!!";
					f = 1;
				}
			}
			else
			{
				label4->Text = "Invalid operation format!!!";
				f = 1;
			}

			return TPolinom(); // Возвращаем пустой полином, если операция не выполнена успешно
		}

		//std::vector<TPolinom> V =new std::vector<TPolinom>();

	protected:
		/// <summary>
		/// Освободить все используемые ресурсы.
		/// </summary>
		~MyForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Label^ label1;
	protected:
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::Label^ label3;
	private: System::Windows::Forms::TextBox^ textBox1;
	private: System::Windows::Forms::TextBox^ textBox2;
	private: System::Windows::Forms::Button^ button1;
	private: System::Windows::Forms::Button^ button2;
	private: System::Windows::Forms::DataGridView^ dataGridView1;
	private: System::Windows::Forms::DataGridViewComboBoxColumn^ Номер;
	private: System::Windows::Forms::DataGridViewComboBoxColumn^ Полином;
private: System::Windows::Forms::Label^ label4;















	protected:

	private:
		/// <summary>
		/// Обязательная переменная конструктора.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Требуемый метод для поддержки конструктора — не изменяйте 
		/// содержимое этого метода с помощью редактора кода.
		/// </summary>
		void InitializeComponent(void)
		{
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->textBox2 = (gcnew System::Windows::Forms::TextBox());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->dataGridView1 = (gcnew System::Windows::Forms::DataGridView());
			this->Номер = (gcnew System::Windows::Forms::DataGridViewComboBoxColumn());
			this->Полином = (gcnew System::Windows::Forms::DataGridViewComboBoxColumn());
			this->label4 = (gcnew System::Windows::Forms::Label());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView1))->BeginInit();
			this->SuspendLayout();
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->BackColor = System::Drawing::SystemColors::GradientActiveCaption;
			this->label1->Location = System::Drawing::Point(224, 23);
			this->label1->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(156, 15);
			this->label1->TabIndex = 0;
			this->label1->Text = L" Калькулятор полиномов ";
			this->label1->Click += gcnew System::EventHandler(this, &MyForm::label1_Click);
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->BackColor = System::Drawing::SystemColors::GradientActiveCaption;
			this->label2->Location = System::Drawing::Point(37, 63);
			this->label2->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(63, 15);
			this->label2->TabIndex = 1;
			this->label2->Text = L"Полином:";
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->BackColor = System::Drawing::SystemColors::GradientActiveCaption;
			this->label3->Location = System::Drawing::Point(32, 97);
			this->label3->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(68, 15);
			this->label3->TabIndex = 2;
			this->label3->Text = L"Операция:";
			this->label3->Click += gcnew System::EventHandler(this, &MyForm::label3_Click);
			// 
			// textBox1
			// 
			this->textBox1->Location = System::Drawing::Point(104, 60);
			this->textBox1->Margin = System::Windows::Forms::Padding(2);
			this->textBox1->Name = L"textBox1";
			this->textBox1->Size = System::Drawing::Size(380, 20);
			this->textBox1->TabIndex = 3;
			this->textBox1->TextChanged += gcnew System::EventHandler(this, &MyForm::textBox1_TextChanged);
			// 
			// textBox2
			// 
			this->textBox2->Location = System::Drawing::Point(104, 97);
			this->textBox2->Margin = System::Windows::Forms::Padding(2);
			this->textBox2->Name = L"textBox2";
			this->textBox2->Size = System::Drawing::Size(380, 20);
			this->textBox2->TabIndex = 4;
			this->textBox2->TextChanged += gcnew System::EventHandler(this, &MyForm::textBox2_TextChanged);
			// 
			// button1
			// 
			this->button1->BackColor = System::Drawing::SystemColors::ActiveBorder;
			this->button1->Location = System::Drawing::Point(495, 52);
			this->button1->Margin = System::Windows::Forms::Padding(2);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(82, 30);
			this->button1->TabIndex = 5;
			this->button1->Text = L"Добавить";
			this->button1->UseVisualStyleBackColor = false;
			this->button1->Click += gcnew System::EventHandler(this, &MyForm::button1_Click);
			// 
			// button2
			// 
			this->button2->BackColor = System::Drawing::SystemColors::ActiveBorder;
			this->button2->Location = System::Drawing::Point(495, 92);
			this->button2->Margin = System::Windows::Forms::Padding(2);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(82, 29);
			this->button2->TabIndex = 6;
			this->button2->Text = L"Выполнить";
			this->button2->UseVisualStyleBackColor = false;
			this->button2->Click += gcnew System::EventHandler(this, &MyForm::button2_Click);
			// 
			// dataGridView1
			// 
			this->dataGridView1->AllowUserToAddRows = false;
			this->dataGridView1->BackgroundColor = System::Drawing::SystemColors::ActiveCaption;
			this->dataGridView1->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->dataGridView1->Columns->AddRange(gcnew cli::array< System::Windows::Forms::DataGridViewColumn^  >(2) {
				this->Номер,
					this->Полином
			});
			this->dataGridView1->GridColor = System::Drawing::Color::Black;
			this->dataGridView1->Location = System::Drawing::Point(35, 125);
			this->dataGridView1->Margin = System::Windows::Forms::Padding(2);
			this->dataGridView1->Name = L"dataGridView1";
			this->dataGridView1->ReadOnly = true;
			this->dataGridView1->RowHeadersVisible = false;
			this->dataGridView1->RowHeadersWidth = 51;
			this->dataGridView1->RowTemplate->Height = 24;
			this->dataGridView1->Size = System::Drawing::Size(542, 349);
			this->dataGridView1->TabIndex = 7;
			this->dataGridView1->CellContentClick += gcnew System::Windows::Forms::DataGridViewCellEventHandler(this, &MyForm::dataGridView1_CellContentClick);
			// 
			// Номер
			// 
			this->Номер->HeaderText = L"Номер";
			this->Номер->MinimumWidth = 6;
			this->Номер->Name = L"Номер";
			this->Номер->ReadOnly = true;
			this->Номер->Resizable = System::Windows::Forms::DataGridViewTriState::True;
			this->Номер->SortMode = System::Windows::Forms::DataGridViewColumnSortMode::Automatic;
			this->Номер->Width = 195;
			// 
			// Полином
			// 
			this->Полином->HeaderText = L"Полином";
			this->Полином->MinimumWidth = 6;
			this->Полином->Name = L"Полином";
			this->Полином->ReadOnly = true;
			this->Полином->Resizable = System::Windows::Forms::DataGridViewTriState::True;
			this->Полином->SortMode = System::Windows::Forms::DataGridViewColumnSortMode::Automatic;
			this->Полином->Width = 250;
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->ForeColor = System::Drawing::Color::Red;
			this->label4->Location = System::Drawing::Point(37, 9);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(0, 15);
			this->label4->TabIndex = 8;
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::SystemColors::Info;
			this->ClientSize = System::Drawing::Size(602, 499);
			this->Controls->Add(this->label4);
			this->Controls->Add(this->dataGridView1);
			this->Controls->Add(this->button2);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->textBox2);
			this->Controls->Add(this->textBox1);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->label1);
			this->Margin = System::Windows::Forms::Padding(2);
			this->Name = L"MyForm";
			this->Text = L"MyForm";
			this->Load += gcnew System::EventHandler(this, &MyForm::MyForm_Load);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView1))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void label3_Click(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void textBox1_TextChanged(System::Object^ sender, System::EventArgs^ e) {
	}
public: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) {
	
	std::string inf; int indi = i + 1; std::string ind = std::to_string(indi);
	inf = msclr::interop::marshal_as<std::string>(textBox1->Text);
	try
	{
		TPolinom pol(inf);
		label4->Text = " ";


		//V[i - 1] = pol;
		V.push_back(pol);
		/*DataGridViewTextBoxColumn^ column0 = gcnew DataGridViewTextBoxColumn();
		column0->Name = "num";
		column0->HeaderText = "Номер";
		DataGridViewTextBoxColumn^ column1 = gcnew DataGridViewTextBoxColumn();
		column1->Name = "Polynom";
		column1->HeaderText = "Полином";*/
		//doSom();
		std::string inf2 = pol.ToString();

		DataGridViewCell^ Num0 = gcnew DataGridViewTextBoxCell();
		DataGridViewCell^ Num1 = gcnew DataGridViewTextBoxCell();
		String^ str2 = gcnew String(ind.c_str());
		String^ str3 = gcnew String(inf2.c_str());
		Num0->Value = str2;
		Num1->Value = str3;
		DataGridViewRow^ row0 = gcnew DataGridViewRow();
		//dataGridView1->DefaultCellStyle->BackColor=Color.FromArgb();
		row0->Cells->AddRange(Num0, Num1);
		//DataTable^ table = gcnew DataTable();
		//table->Columns->Add("Номер",string)
		dataGridView1->Rows->Add(row0);
		Color color = Color::LightSkyBlue;
		dataGridView1->DefaultCellStyle->BackColor = color;



		i++;
	}
	catch (const char* exep)
	{
		std::string exeption(exep);
		label4->Text = gcnew String(exeption.c_str());;
	}
}
private: System::Void textBox2_TextChanged(System::Object^ sender, System::EventArgs^ e) {

}
private: System::Void dataGridView1_CellContentClick(System::Object^ sender, System::Windows::Forms::DataGridViewCellEventArgs^ e) {
}
    
private: System::Void button2_Click(System::Object^ sender, System::EventArgs^ e) {
		std::string inf;  //std::string ind = std::to_string(i);
		inf = msclr::interop::marshal_as<std::string>(textBox2->Text);
		if (V.size() < 2)
		{
			throw  "Need at least 2 polynomials in the vector." ;

		}
		TPolinom res = Polinomoperation(inf, V);
		V.push_back(res);
		if (f == 0)
		{
			label4->Text = " ";
		}

		std::string inf2 = res.ToString();
		int indi = i + 1; std::string ind = std::to_string(indi);
		DataGridViewCell^ Num0 = gcnew DataGridViewTextBoxCell();
		DataGridViewCell^ Num1 = gcnew DataGridViewTextBoxCell();
		String^ str2 = gcnew String(ind.c_str());
		String^ str3 = gcnew String(inf2.c_str());
		Num0->Value = str2;
		Num1->Value = str3;
		DataGridViewRow^ row0 = gcnew DataGridViewRow();
		//dataGridView1->DefaultCellStyle->BackColor=Color.FromArgb();
		row0->Cells->AddRange(Num0, Num1);
		//DataTable^ table = gcnew DataTable();
		//table->Columns->Add("Номер",string)
		dataGridView1->Rows->Add(row0);
		Color color = Color::LightSkyBlue;
		dataGridView1->DefaultCellStyle->BackColor = color;



		i++;

	
	
	
	
	
	
	
	
	
	}





  private: System::Void label1_Click(System::Object^ sender, System::EventArgs^ e) {
  }
private: System::Void MyForm_Load(System::Object^ sender, System::EventArgs^ e) {
}
};
}

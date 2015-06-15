#pragma once

using namespace System;
using namespace System::ComponentModel;
using namespace System::Collections;
using namespace System::Windows::Forms;
using namespace System::Data;
using namespace System::Drawing;


namespace airplaneManager {
	//форма может быть 3х типов: добавление записи, редактирование, фильтрация
	public enum class FormType : Int32 { Add, Edit, Filter };

	public ref class addForm : public System::Windows::Forms::Form{
	public:
		//конструктор формы добавления рейса
		addForm(FlightStorage^ _flights){
			InitializeComponent();
			flights = _flights;
			type = FormType::Add;
		}
		//конструктор формы редактирования рейса, index - индекс редактируемого рейса
		addForm(FlightStorage^ _flights, Flight^ f, Int32 index){
			InitializeComponent();
			flights = _flights;
			editIndex = index;
			type = FormType::Edit;
			for(Int32 i = 0; i < 7; ++i){
				if (f->days & 1 << i){
					daysListBox->SetItemChecked(i, true);
				}
			}
			numberField->Value = f->number;
			airplaneNameText->Text = f->airplaneName;
			cityText->Text = f->cityName;
			costField->Value = f->cost;
			timeFromTextBox->Text = f->stringTimeFrom;
			timeToTextBox->Text = f->stringTimeTo;
			this->Text = L"Редактирование записи";
			addFlightButton->Text = L"Сохранить";
		}
		//конструктор формы фильтрации рейса
		addForm(FlightStorage^ _flights, Flight^ f){
			InitializeComponent();
			flights = _flights;
			filterFlight = f;
			type = FormType::Filter;
			this->Text = L"Отфильтровать записи";
			addFlightButton->Text = L"Отфильтровать";
			airplaneNameText->CausesValidation = false;
			cityText->CausesValidation = false;
			timeFromTextBox->CausesValidation = false;
			timeToTextBox->CausesValidation = false;
		}


	protected:
		~addForm(){
			if (components){
				delete components;
			}
		}
	private: 
		FlightStorage^ flights; //экземпляр класса для хранения рейсов
		Flight^ filterFlight; 	//аргумент для фильтра
		FormType type;			//что сейчас делает форма - добавление, редактирование, фильтрацию
		Int32 editIndex;		//индекс редактируемой записи

	//визуальные компоненты
	private: System::Windows::Forms::NumericUpDown^  numberField;
	private: System::Windows::Forms::Label^  numberLabel;
	private: System::Windows::Forms::TextBox^  airplaneNameText;
	private: System::Windows::Forms::Label^  airplaneNameLabel;
	private: System::Windows::Forms::Label^  cityLabel;
	private: System::Windows::Forms::TextBox^  cityText;
	private: System::Windows::Forms::NumericUpDown^  costField;
	private: System::Windows::Forms::Label^  costLabel;
	private: System::Windows::Forms::MaskedTextBox^  timeFromTextBox;
	private: System::Windows::Forms::MaskedTextBox^  timeToTextBox;
	private: System::Windows::Forms::Label^  timeFromLabel;
	private: System::Windows::Forms::Label^  timeToLabel;
	private: System::Windows::Forms::Label^  daysLabel;
	private: System::Windows::Forms::Button^  addFlightButton;
	private: System::Windows::Forms::CheckedListBox^  daysListBox;
	private:
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->numberField = (gcnew System::Windows::Forms::NumericUpDown());
			this->numberLabel = (gcnew System::Windows::Forms::Label());
			this->airplaneNameText = (gcnew System::Windows::Forms::TextBox());
			this->airplaneNameLabel = (gcnew System::Windows::Forms::Label());
			this->cityLabel = (gcnew System::Windows::Forms::Label());
			this->cityText = (gcnew System::Windows::Forms::TextBox());
			this->costField = (gcnew System::Windows::Forms::NumericUpDown());
			this->costLabel = (gcnew System::Windows::Forms::Label());
			this->timeFromTextBox = (gcnew System::Windows::Forms::MaskedTextBox());
			this->timeToTextBox = (gcnew System::Windows::Forms::MaskedTextBox());
			this->timeFromLabel = (gcnew System::Windows::Forms::Label());
			this->timeToLabel = (gcnew System::Windows::Forms::Label());
			this->daysLabel = (gcnew System::Windows::Forms::Label());
			this->addFlightButton = (gcnew System::Windows::Forms::Button());
			this->daysListBox = (gcnew System::Windows::Forms::CheckedListBox());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->numberField))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->costField))->BeginInit();
			this->SuspendLayout();
			// 
			// numberField
			// 
			this->numberField->Location = System::Drawing::Point(29, 53);
			this->numberField->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) {-294967296, 0, 0, 0});
			this->numberField->Name = L"numberField";
			this->numberField->Size = System::Drawing::Size(48, 22);
			this->numberField->TabIndex = 0;
			// 
			// numberLabel
			// 
			this->numberLabel->AutoSize = true;
			this->numberLabel->Location = System::Drawing::Point(26, 24);
			this->numberLabel->Name = L"numberLabel";
			this->numberLabel->Size = System::Drawing::Size(51, 17);
			this->numberLabel->TabIndex = 1;
			this->numberLabel->Text = L"Номер";
			// 
			// airplaneNameText
			// 
			this->airplaneNameText->Location = System::Drawing::Point(125, 53);
			this->airplaneNameText->Name = L"airplaneNameText";
			this->airplaneNameText->Size = System::Drawing::Size(139, 22);
			this->airplaneNameText->TabIndex = 3;
			this->airplaneNameText->Validating += gcnew System::ComponentModel::CancelEventHandler(this, &addForm::stringText_Validating);
			// 
			// airplaneNameLabel
			// 
			this->airplaneNameLabel->AutoSize = true;
			this->airplaneNameLabel->Location = System::Drawing::Point(125, 24);
			this->airplaneNameLabel->Name = L"airplaneNameLabel";
			this->airplaneNameLabel->Size = System::Drawing::Size(139, 17);
			this->airplaneNameLabel->TabIndex = 4;
			this->airplaneNameLabel->Text = L"Название самолёта";
			// 
			// cityLabel
			// 
			this->cityLabel->AutoSize = true;
			this->cityLabel->Location = System::Drawing::Point(293, 23);
			this->cityLabel->Name = L"cityLabel";
			this->cityLabel->Size = System::Drawing::Size(48, 17);
			this->cityLabel->TabIndex = 6;
			this->cityLabel->Text = L"Город";
			// 
			// cityText
			// 
			this->cityText->Location = System::Drawing::Point(293, 52);
			this->cityText->Name = L"cityText";
			this->cityText->Size = System::Drawing::Size(139, 22);
			this->cityText->TabIndex = 5;
			this->cityText->Validating += gcnew System::ComponentModel::CancelEventHandler(this, &addForm::stringText_Validating);
			// 
			// costField
			// 
			this->costField->Location = System::Drawing::Point(29, 124);
			this->costField->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) {-294967296, 0, 0, 0});
			this->costField->Name = L"costField";
			this->costField->Size = System::Drawing::Size(75, 22);
			this->costField->TabIndex = 7;
			// 
			// costLabel
			// 
			this->costLabel->AutoSize = true;
			this->costLabel->Location = System::Drawing::Point(29, 101);
			this->costLabel->Name = L"costLabel";
			this->costLabel->Size = System::Drawing::Size(43, 17);
			this->costLabel->TabIndex = 8;
			this->costLabel->Text = L"Цена";
			// 
			// timeFromTextBox
			// 
			this->timeFromTextBox->Location = System::Drawing::Point(165, 123);
			this->timeFromTextBox->Mask = L"00:00";
			this->timeFromTextBox->Name = L"timeFromTextBox";
			this->timeFromTextBox->Size = System::Drawing::Size(46, 22);
			this->timeFromTextBox->TabIndex = 9;
			this->timeFromTextBox->ValidatingType = System::DateTime::typeid;
			this->timeFromTextBox->Validating += gcnew System::ComponentModel::CancelEventHandler(this, &addForm::timeText_Validating);
			// 
			// timeToTextBox
			// 
			this->timeToTextBox->Location = System::Drawing::Point(325, 123);
			this->timeToTextBox->Mask = L"00:00";
			this->timeToTextBox->Name = L"timeToTextBox";
			this->timeToTextBox->Size = System::Drawing::Size(46, 22);
			this->timeToTextBox->TabIndex = 10;
			this->timeToTextBox->ValidatingType = System::DateTime::typeid;
			this->timeToTextBox->Validating += gcnew System::ComponentModel::CancelEventHandler(this, &addForm::timeText_Validating);
			// 
			// timeFromLabel
			// 
			this->timeFromLabel->AutoSize = true;
			this->timeFromLabel->Location = System::Drawing::Point(128, 101);
			this->timeFromLabel->Name = L"timeFromLabel";
			this->timeFromLabel->Size = System::Drawing::Size(115, 17);
			this->timeFromLabel->TabIndex = 11;
			this->timeFromLabel->Text = L"Время отправки";
			// 
			// timeToLabel
			// 
			this->timeToLabel->AutoSize = true;
			this->timeToLabel->Location = System::Drawing::Point(290, 101);
			this->timeToLabel->Name = L"timeToLabel";
			this->timeToLabel->Size = System::Drawing::Size(119, 17);
			this->timeToLabel->TabIndex = 12;
			this->timeToLabel->Text = L"Время прибытия";
			// 
			// daysLabel
			// 
			this->daysLabel->AutoSize = true;
			this->daysLabel->Location = System::Drawing::Point(68, 162);
			this->daysLabel->Name = L"daysLabel";
			this->daysLabel->Size = System::Drawing::Size(273, 17);
			this->daysLabel->TabIndex = 14;
			this->daysLabel->Text = L"Дни недели, по которым работает рейс";
			// 
			// addFlightButton
			// 
			this->addFlightButton->Location = System::Drawing::Point(131, 344);
			this->addFlightButton->Name = L"addFlightButton";
			this->addFlightButton->Size = System::Drawing::Size(154, 33);
			this->addFlightButton->TabIndex = 15;
			this->addFlightButton->Text = L"Добавить";
			this->addFlightButton->UseVisualStyleBackColor = true;
			this->addFlightButton->Click += gcnew System::EventHandler(this, &addForm::addFlightButton_Click);
			// 
			// daysListBox
			// 
			this->daysListBox->CheckOnClick = true;
			this->daysListBox->FormattingEnabled = true;
			this->daysListBox->Items->AddRange(gcnew cli::array< System::Object^  >(7) {L"Понедельник", L"Вторник", L"Среда", L"Четверг", 
				L"Пятница", L"Суббота", L"Воскресенье"});
			this->daysListBox->Location = System::Drawing::Point(71, 193);
			this->daysListBox->Name = L"daysListBox";
			this->daysListBox->Size = System::Drawing::Size(270, 123);
			this->daysListBox->TabIndex = 16;
			// 
			// addForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(452, 404);
			this->Controls->Add(this->daysListBox);
			this->Controls->Add(this->addFlightButton);
			this->Controls->Add(this->daysLabel);
			this->Controls->Add(this->timeToLabel);
			this->Controls->Add(this->timeFromLabel);
			this->Controls->Add(this->timeToTextBox);
			this->Controls->Add(this->timeFromTextBox);
			this->Controls->Add(this->costLabel);
			this->Controls->Add(this->costField);
			this->Controls->Add(this->cityLabel);
			this->Controls->Add(this->cityText);
			this->Controls->Add(this->airplaneNameLabel);
			this->Controls->Add(this->airplaneNameText);
			this->Controls->Add(this->numberLabel);
			this->Controls->Add(this->numberField);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedSingle;
			this->MaximizeBox = false;
			this->Name = L"addForm";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterParent;
			this->Text = L"Добавление записи";
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->numberField))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->costField))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
		//проверка, что в строку не входит разделитель
		private: System::Void stringText_Validating(System::Object^  sender, System::ComponentModel::CancelEventArgs^  e) {
			TextBox^ t = (TextBox^)sender;
			if(t->Text->Contains(L"|")){
				MessageBox::Show(L"Поле содержит недопустимый знак: |");
				e->Cancel = true;
			}else {
				if(t->Text->Trim() == L""){
					MessageBox::Show(L"Поле не может быть пустым");
					e->Cancel = true;
				}else {
					e->Cancel = false;
				}
			}
			
		}
		//проверка корректности времени
		private: System::Void timeText_Validating(System::Object^  sender, System::ComponentModel::CancelEventArgs^  e) {
			MaskedTextBox^ t = (MaskedTextBox^)sender;
			array<Char>^ separator = gcnew array<Char>{L':'};
			array<String^>^ nums = t->Text->Split(separator);
			Int32 hours; 
			Int32 minutes;
			if(Int32::TryParse(nums[0], hours) && 
				Int32::TryParse(nums[1], minutes)){
				e->Cancel = hours > 23 || minutes > 59;
			}else {
				e->Cancel = true;
			}
			if(e->Cancel){
				MessageBox::Show(L"Время введено неправильно");
			}
		}
		//окончательная валидация и возврат записи
		private: System::Void addFlightButton_Click(System::Object^  sender, System::EventArgs^  e) {
			Int32 days = 0;
			Flight^ f = filterFlight;
			for each(Int32 index in daysListBox->CheckedIndices){
				days |= 1<<index;
			}
			if(type != FormType::Filter){
				if(numberField->Value == 0){
					MessageBox::Show(L"Номер не может быть равен 0");	
					return;
				}
				if(costField->Value == 0){
					MessageBox::Show(L"Цена не может быть равна 0");	
					return;
				}
				if(timeFromTextBox->Text->Trim() == L":" || 
					timeToTextBox->Text->Trim() == L":"){
					MessageBox::Show(L"Время введено неправильно");
					return;
				}
				if(airplaneNameText->Text->Trim() == L"" || 
					cityText->Text->Trim() == L""){
					MessageBox::Show(L"Некоторые поля пусты");
					return;
				}
				if(days == 0){
					MessageBox::Show(L"Нужно выделить хотя бы один день недели");
					return;
				}
				f = gcnew Flight();
			}
			f->number = numberField->Value;
			f->airplaneName = airplaneNameText->Text;
			f->cityName = cityText->Text;
			f->cost = costField->Value;
			f->days = days;
			f->stringTimeFrom = timeFromTextBox->Text;
			f->stringTimeTo = timeToTextBox->Text;
			if(type == FormType::Add){
				flights->AddFlight(f);
			}else if(type == FormType::Edit){
				flights->ChangeFlight(editIndex, f);
			}
			Close();
		}
	};
}

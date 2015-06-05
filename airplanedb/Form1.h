#pragma once
#include "addForm.h"
#include "gameForm.h"

namespace airplanedb {
	using namespace System::IO;
	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	//класс главной формы
	public ref class MainForm : public System::Windows::Forms::Form{
	public:
		//конструктор без параметров
		MainForm(void){
			InitializeComponent();
			flights = nullptr;
			filterFlight = gcnew Flight();
		}

	protected:
		~MainForm(){
			if (components){
				delete components;
			}
		}
	static Int32 indexColumnIdx = 7;	//индекс колонки, хранящей номер записи
	private: 
		FlightStorage^ flights;	//экземпляр класса для хранения рейсов
		Flight^ filterFlight;	//аргумент для фильтра

	//визуальные компоненты
	private: System::Windows::Forms::DataGridView^  MainTable;
	private: System::Windows::Forms::OpenFileDialog^  openDBFileDialog;
	private: System::Windows::Forms::MenuStrip^  MainMenu;
	private: System::Windows::Forms::ToolStripMenuItem^  Menu;
	private: System::Windows::Forms::ToolStripMenuItem^  menuOpenButton;
	private: System::Windows::Forms::ToolStripMenuItem^  menuExitButton;
	private: System::Windows::Forms::Button^  addButton;
	private: System::Windows::Forms::ToolStripMenuItem^  actionsMenu;
	private: System::Windows::Forms::ToolStripMenuItem^  addMenuItem;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  number;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  airplane;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  city;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  cost;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  days;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  timeFrom;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  timeTo;
	private: System::Windows::Forms::Button^  deleteButton;
	private: System::Windows::Forms::ToolStripMenuItem^  deleteMenuItem;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  index;
	private: System::Windows::Forms::Button^  editButton;
	private: System::Windows::Forms::ToolStripMenuItem^  editMenuItem;
	private: System::Windows::Forms::Button^  filterButton;
	private: System::Windows::Forms::Button^  clearFilterButton;
	private: System::Windows::Forms::ToolStripMenuItem^  filterMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  clearFilterMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  gameMenu;
	private: System::Windows::Forms::ToolStripMenuItem^  openGameMenuItem;
	private:
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->MainTable = (gcnew System::Windows::Forms::DataGridView());
			this->number = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->airplane = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->city = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->cost = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->days = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->timeFrom = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->timeTo = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->index = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->openDBFileDialog = (gcnew System::Windows::Forms::OpenFileDialog());
			this->MainMenu = (gcnew System::Windows::Forms::MenuStrip());
			this->Menu = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->menuOpenButton = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->menuExitButton = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->actionsMenu = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->addMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->deleteMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->editMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->filterMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->clearFilterMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->gameMenu = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->openGameMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->addButton = (gcnew System::Windows::Forms::Button());
			this->deleteButton = (gcnew System::Windows::Forms::Button());
			this->editButton = (gcnew System::Windows::Forms::Button());
			this->filterButton = (gcnew System::Windows::Forms::Button());
			this->clearFilterButton = (gcnew System::Windows::Forms::Button());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->MainTable))->BeginInit();
			this->MainMenu->SuspendLayout();
			this->SuspendLayout();
			// 
			// MainTable
			// 
			this->MainTable->AllowUserToAddRows = false;
			this->MainTable->AllowUserToDeleteRows = false;
			this->MainTable->AllowUserToOrderColumns = true;
			this->MainTable->AutoSizeColumnsMode = System::Windows::Forms::DataGridViewAutoSizeColumnsMode::AllCells;
			this->MainTable->AutoSizeRowsMode = System::Windows::Forms::DataGridViewAutoSizeRowsMode::AllCells;
			this->MainTable->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->MainTable->Columns->AddRange(gcnew cli::array< System::Windows::Forms::DataGridViewColumn^  >(8) {this->number, this->airplane, 
				this->city, this->cost, this->days, this->timeFrom, this->timeTo, this->index});
			this->MainTable->EditMode = System::Windows::Forms::DataGridViewEditMode::EditProgrammatically;
			this->MainTable->Location = System::Drawing::Point(12, 87);
			this->MainTable->Margin = System::Windows::Forms::Padding(0);
			this->MainTable->MultiSelect = false;
			this->MainTable->Name = L"MainTable";
			this->MainTable->ReadOnly = true;
			this->MainTable->RowHeadersWidth = 25;
			this->MainTable->RowTemplate->Height = 24;
			this->MainTable->SelectionMode = System::Windows::Forms::DataGridViewSelectionMode::FullRowSelect;
			this->MainTable->Size = System::Drawing::Size(980, 344);
			this->MainTable->TabIndex = 0;
			this->MainTable->KeyUp += gcnew System::Windows::Forms::KeyEventHandler(this, &MainForm::MainTable_KeyUp);
			// 
			// number
			// 
			this->number->AutoSizeMode = System::Windows::Forms::DataGridViewAutoSizeColumnMode::None;
			this->number->FillWeight = 483.2488F;
			this->number->HeaderText = L"Номер";
			this->number->Name = L"number";
			this->number->ReadOnly = true;
			this->number->Width = 75;
			// 
			// airplane
			// 
			this->airplane->AutoSizeMode = System::Windows::Forms::DataGridViewAutoSizeColumnMode::None;
			this->airplane->FillWeight = 36.12521F;
			this->airplane->HeaderText = L"Самолёт";
			this->airplane->Name = L"airplane";
			this->airplane->ReadOnly = true;
			// 
			// city
			// 
			this->city->AutoSizeMode = System::Windows::Forms::DataGridViewAutoSizeColumnMode::None;
			this->city->FillWeight = 36.12521F;
			this->city->HeaderText = L"Город";
			this->city->Name = L"city";
			this->city->ReadOnly = true;
			// 
			// cost
			// 
			this->cost->AutoSizeMode = System::Windows::Forms::DataGridViewAutoSizeColumnMode::None;
			this->cost->FillWeight = 36.12521F;
			this->cost->HeaderText = L"Стоимость";
			this->cost->Name = L"cost";
			this->cost->ReadOnly = true;
			// 
			// days
			// 
			this->days->AutoSizeMode = System::Windows::Forms::DataGridViewAutoSizeColumnMode::Fill;
			this->days->FillWeight = 36.12521F;
			this->days->HeaderText = L"Дни рейса";
			this->days->Name = L"days";
			this->days->ReadOnly = true;
			// 
			// timeFrom
			// 
			this->timeFrom->AutoSizeMode = System::Windows::Forms::DataGridViewAutoSizeColumnMode::None;
			this->timeFrom->FillWeight = 36.12521F;
			this->timeFrom->HeaderText = L"Время отлёта";
			this->timeFrom->Name = L"timeFrom";
			this->timeFrom->ReadOnly = true;
			this->timeFrom->Width = 65;
			// 
			// timeTo
			// 
			this->timeTo->AutoSizeMode = System::Windows::Forms::DataGridViewAutoSizeColumnMode::None;
			this->timeTo->FillWeight = 36.12521F;
			this->timeTo->HeaderText = L"Время прилёта";
			this->timeTo->Name = L"timeTo";
			this->timeTo->ReadOnly = true;
			this->timeTo->Width = 65;
			// 
			// index
			// 
			this->index->HeaderText = L"index";
			this->index->Name = L"index";
			this->index->ReadOnly = true;
			this->index->Visible = false;
			this->index->Width = 66;
			// 
			// MainMenu
			// 
			this->MainMenu->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(3) {this->Menu, this->actionsMenu, 
				this->gameMenu});
			this->MainMenu->Location = System::Drawing::Point(0, 0);
			this->MainMenu->Name = L"MainMenu";
			this->MainMenu->Size = System::Drawing::Size(1005, 28);
			this->MainMenu->TabIndex = 1;
			this->MainMenu->Text = L"menuStrip1";
			// 
			// Menu
			// 
			this->Menu->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(2) {this->menuOpenButton, 
				this->menuExitButton});
			this->Menu->Name = L"Menu";
			this->Menu->Size = System::Drawing::Size(57, 24);
			this->Menu->Text = L"Файл";
			// 
			// menuOpenButton
			// 
			this->menuOpenButton->Name = L"menuOpenButton";
			this->menuOpenButton->Size = System::Drawing::Size(152, 24);
			this->menuOpenButton->Text = L"Открыть";
			this->menuOpenButton->Click += gcnew System::EventHandler(this, &MainForm::menuOpenButton_Click);
			// 
			// menuExitButton
			// 
			this->menuExitButton->Name = L"menuExitButton";
			this->menuExitButton->Size = System::Drawing::Size(152, 24);
			this->menuExitButton->Text = L"Выход";
			this->menuExitButton->Click += gcnew System::EventHandler(this, &MainForm::menuExitButton_Click);
			// 
			// actionsMenu
			// 
			this->actionsMenu->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(5) {this->addMenuItem, 
				this->deleteMenuItem, this->editMenuItem, this->filterMenuItem, this->clearFilterMenuItem});
			this->actionsMenu->Name = L"actionsMenu";
			this->actionsMenu->Size = System::Drawing::Size(71, 24);
			this->actionsMenu->Text = L"Записи";
			// 
			// addMenuItem
			// 
			this->addMenuItem->Name = L"addMenuItem";
			this->addMenuItem->Size = System::Drawing::Size(196, 24);
			this->addMenuItem->Text = L"Добавить";
			this->addMenuItem->Click += gcnew System::EventHandler(this, &MainForm::addButton_Click);
			// 
			// deleteMenuItem
			// 
			this->deleteMenuItem->Name = L"deleteMenuItem";
			this->deleteMenuItem->Size = System::Drawing::Size(196, 24);
			this->deleteMenuItem->Text = L"Удалить";
			this->deleteMenuItem->Click += gcnew System::EventHandler(this, &MainForm::deleteButton_Click);
			// 
			// editMenuItem
			// 
			this->editMenuItem->Name = L"editMenuItem";
			this->editMenuItem->Size = System::Drawing::Size(196, 24);
			this->editMenuItem->Text = L"Редактировать";
			this->editMenuItem->Click += gcnew System::EventHandler(this, &MainForm::editButton_Click);
			// 
			// filterMenuItem
			// 
			this->filterMenuItem->Name = L"filterMenuItem";
			this->filterMenuItem->Size = System::Drawing::Size(196, 24);
			this->filterMenuItem->Text = L"Отфильтровать";
			this->filterMenuItem->Click += gcnew System::EventHandler(this, &MainForm::filterButton_Click);
			// 
			// clearFilterMenuItem
			// 
			this->clearFilterMenuItem->Name = L"clearFilterMenuItem";
			this->clearFilterMenuItem->Size = System::Drawing::Size(196, 24);
			this->clearFilterMenuItem->Text = L"Очистить фильтр";
			this->clearFilterMenuItem->Click += gcnew System::EventHandler(this, &MainForm::clearFilterButton_Click);
			// 
			// gameMenu
			// 
			this->gameMenu->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(1) {this->openGameMenuItem});
			this->gameMenu->Name = L"gameMenu";
			this->gameMenu->Size = System::Drawing::Size(55, 24);
			this->gameMenu->Text = L"Игра";
			// 
			// openGameMenuItem
			// 
			this->openGameMenuItem->Name = L"openGameMenuItem";
			this->openGameMenuItem->Size = System::Drawing::Size(136, 24);
			this->openGameMenuItem->Text = L"Открыть";
			this->openGameMenuItem->Click += gcnew System::EventHandler(this, &MainForm::openGameMenuItem_Click);
			// 
			// addButton
			// 
			this->addButton->ImageAlign = System::Drawing::ContentAlignment::MiddleLeft;
			this->addButton->Location = System::Drawing::Point(12, 41);
			this->addButton->Name = L"addButton";
			this->addButton->Size = System::Drawing::Size(160, 26);
			this->addButton->TabIndex = 2;
			this->addButton->Text = L"Добавить запись";
			this->addButton->TextImageRelation = System::Windows::Forms::TextImageRelation::ImageBeforeText;
			this->addButton->UseVisualStyleBackColor = true;
			this->addButton->Click += gcnew System::EventHandler(this, &MainForm::addButton_Click);
			// 
			// deleteButton
			// 
			this->deleteButton->ImageAlign = System::Drawing::ContentAlignment::MiddleLeft;
			this->deleteButton->Location = System::Drawing::Point(193, 41);
			this->deleteButton->Name = L"deleteButton";
			this->deleteButton->Size = System::Drawing::Size(148, 26);
			this->deleteButton->TabIndex = 3;
			this->deleteButton->Text = L"Удалить запись";
			this->deleteButton->TextImageRelation = System::Windows::Forms::TextImageRelation::ImageBeforeText;
			this->deleteButton->UseVisualStyleBackColor = true;
			this->deleteButton->Click += gcnew System::EventHandler(this, &MainForm::deleteButton_Click);
			// 
			// editButton
			// 
			this->editButton->ImageAlign = System::Drawing::ContentAlignment::MiddleLeft;
			this->editButton->Location = System::Drawing::Point(357, 41);
			this->editButton->Name = L"editButton";
			this->editButton->Size = System::Drawing::Size(190, 26);
			this->editButton->TabIndex = 4;
			this->editButton->Text = L"Редактировать запись";
			this->editButton->TextImageRelation = System::Windows::Forms::TextImageRelation::ImageBeforeText;
			this->editButton->UseVisualStyleBackColor = true;
			this->editButton->Click += gcnew System::EventHandler(this, &MainForm::editButton_Click);
			// 
			// filterButton
			// 
			this->filterButton->Location = System::Drawing::Point(569, 41);
			this->filterButton->Name = L"filterButton";
			this->filterButton->Size = System::Drawing::Size(188, 26);
			this->filterButton->TabIndex = 5;
			this->filterButton->Text = L"Отфильтровать записи";
			this->filterButton->UseVisualStyleBackColor = true;
			this->filterButton->Click += gcnew System::EventHandler(this, &MainForm::filterButton_Click);
			// 
			// clearFilterButton
			// 
			this->clearFilterButton->Location = System::Drawing::Point(781, 41);
			this->clearFilterButton->Name = L"clearFilterButton";
			this->clearFilterButton->Size = System::Drawing::Size(167, 26);
			this->clearFilterButton->TabIndex = 6;
			this->clearFilterButton->Text = L"Очистить фильтр";
			this->clearFilterButton->UseVisualStyleBackColor = true;
			this->clearFilterButton->Click += gcnew System::EventHandler(this, &MainForm::clearFilterButton_Click);
			// 
			// MainForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(1005, 445);
			this->Controls->Add(this->clearFilterButton);
			this->Controls->Add(this->filterButton);
			this->Controls->Add(this->editButton);
			this->Controls->Add(this->deleteButton);
			this->Controls->Add(this->addButton);
			this->Controls->Add(this->MainTable);
			this->Controls->Add(this->MainMenu);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedSingle;
			this->MainMenuStrip = this->MainMenu;
			this->MaximizeBox = false;
			this->Name = L"MainForm";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"Расписание самолётов";
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->MainTable))->EndInit();
			this->MainMenu->ResumeLayout(false);
			this->MainMenu->PerformLayout();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
		//обновляет и фильтрует список полётов
		private: Void listFlights(){
			MainTable->Rows->Clear();
			for each(Flight^ f in flights){
				bool fits = true;
				if(filterFlight->number != 0)
					fits = fits && f->number == filterFlight->number;
				if(filterFlight->airplaneName != L"")
					fits = fits && f->airplaneName == filterFlight->airplaneName;
				if(filterFlight->cityName != L"")
					fits = fits && f->cityName == filterFlight->cityName;
				if(filterFlight->days != 0)
					fits = fits && (f->days & filterFlight->days);
				if(filterFlight->timeFrom != nullptr)
					fits = fits && *f->timeFrom <= *filterFlight->timeFrom;
				if(filterFlight->timeTo != nullptr)
					fits = fits && *f->timeTo <= *filterFlight->timeTo;
				if(filterFlight->cost != 0)
					fits = fits && f->cost <= filterFlight->cost;
				if(fits){
					Int32 idx = MainTable->Rows->Add(f->number,
													f->airplaneName,
													f->cityName,
													f->cost,
													f->stringDays,
													f->stringTimeFrom,
													f->stringTimeTo);
					MainTable->Rows[idx]->Tag = f;
					MainTable->Rows[idx]->Cells[indexColumnIdx]->Value = idx;
				}
			}
		}
		//выход из приложения
		private: System::Void menuExitButton_Click(System::Object^  sender, System::EventArgs^  e) {
			Close();
		}
		//загрузка файла с данными
		private: System::Void menuOpenButton_Click(System::Object^  sender, System::EventArgs^  e) {
			if(openDBFileDialog->ShowDialog() == ::System::Windows::Forms::DialogResult::OK){
				flights = gcnew FlightStorage(openDBFileDialog->FileName);
				listFlights();
			}
		}
		//добавление записи
		private: System::Void addButton_Click(System::Object^  sender, System::EventArgs^  e) {
			if(flights == nullptr){
				MessageBox::Show(L"Сперва нужно открыть файл!");
				return;
			}
			(gcnew addForm(flights))->ShowDialog();
			listFlights();
		}
		//удаление записи
		private: System::Void deleteButton_Click(System::Object^  sender, System::EventArgs^  e) {
			if(MainTable->SelectedRows->Count == 0){
				MessageBox::Show(L"Сперва нужно выбрать строку таблицы!");
			}else {
				if (MessageBox::Show("Вы точно хотите удалить эту запись?", 
									"Подтверждение удаления", 
									MessageBoxButtons::YesNo) == 
									::System::Windows::Forms::DialogResult::Yes){
					flights->RemoveFlight((Int32)MainTable->SelectedRows[0]->Cells[indexColumnIdx]->Value);
					listFlights();
				}
			}
		}
		//удаление записи при нажатии на кнопку Delete
		private: System::Void MainTable_KeyUp(System::Object^  sender, System::Windows::Forms::KeyEventArgs^  e) {
			if(e->KeyCode == Keys::Delete){
				deleteButton_Click(sender, e);
			}
		}
		//открытие формы редактирования записи
		private: System::Void editButton_Click(System::Object^  sender, System::EventArgs^  e) {
			if(MainTable->SelectedRows->Count == 0){
				MessageBox::Show(L"Сперва нужно выбрать строку таблицы!");
			}else {
				(gcnew addForm(flights, (Flight^)MainTable->SelectedRows[0]->Tag, (Int32)MainTable->SelectedRows[0]->Cells[indexColumnIdx]->Value))->ShowDialog();
				listFlights();
			}
		}
		//открытие формы фильтрации
		private: System::Void filterButton_Click(System::Object^  sender, System::EventArgs^  e) {
			if(flights == nullptr){
				MessageBox::Show(L"Сперва нужно открыть файл!");
				return;
			}
			(gcnew addForm(flights, filterFlight))->ShowDialog();
			listFlights();
		}
		//очистка фильтра
		private: System::Void clearFilterButton_Click(System::Object^  sender, System::EventArgs^  e) {
			if(flights == nullptr){
				MessageBox::Show(L"Сперва нужно открыть файл!");
				return;
			}
			filterFlight = gcnew Flight();
			listFlights();
		}
		//открытие окна с игрой
		private: System::Void openGameMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
			(gcnew gameForm())->Show();
		}
	};
}


#pragma once

using namespace System;
using namespace System::ComponentModel;
using namespace System::Collections;
using namespace System::Windows::Forms;
using namespace System::Data;
using namespace System::Drawing;


namespace airplaneManager {
	//класс формы с игрой
	public ref class gameForm : public System::Windows::Forms::Form{
	static const Int32 FIELDSIZE = 15;	//размеры показываемого поля
	static const Int32 EASY = 7; //лёгкая сложность
	static const Int32 MIDDLE = 5; //средняя сложность
	static const Int32 HARD = 3; //трудная сложность
			 
	public:
		//конструктор без параметров
		gameForm(void){
			InitializeComponent();
			cells = gcnew array<array<CheckBox^>^>(FIELDSIZE);
			for(Int32 i = 0; i < FIELDSIZE; ++i){
				cells[i] = gcnew array<CheckBox^>(FIELDSIZE);
				for(Int32 j = 0; j < FIELDSIZE; ++j){
					cells[i][j] = gcnew CheckBox();
					cells[i][j]->Appearance = Appearance::Button;
					cells[i][j]->Checked = true;
					cells[i][j]->Font = (gcnew System::Drawing::Font(L"Courier New", 10.0F, FontStyle::Bold, GraphicsUnit::Point, 
						static_cast<System::Byte>(204)));
					cells[i][j]->Size = System::Drawing::Size(25, 25);
					cells[i][j]->Text = L" ";
					cells[i][j]->Location = Point(50+ i*25, 75+ j*25);
					cells[i][j]->Tag = Point(i,j);
					cells[i][j]->MouseUp += gcnew MouseEventHandler(this, &gameForm::CellClicked);
					cells[i][j]->KeyUp += gcnew KeyEventHandler(this, &gameForm::gameForm_KeyUp);
					this->Controls->Add(cells[i][j]);
				}
			}
			difficulty = EASY;
			newGame();
		}

	protected:
		~gameForm(){
			if (components){
				delete components;
			}
		}

		
	private: 
		Minesweeper^ gameLogic; //экземпляр класса с логикой игры
		array<array<CheckBox^>^>^ cells; //матрица визуального представления игровых клеток
		Point topCoords;	//координаты угла области, которую видно
		Int32 difficulty;	//сложность игры
	//визуальные компоненты
	private: System::Windows::Forms::Label^  scoreTextLabel;
	private: System::Windows::Forms::Label^  scoreLabel;
	private: System::Windows::Forms::Button^  newGameButton;
	private: System::Windows::Forms::Button^  upField;
	private: System::Windows::Forms::Button^  leftField;
	private: System::Windows::Forms::Button^  rightField;
	private: System::Windows::Forms::Button^  downField;
	private: System::Windows::Forms::MenuStrip^  difficultyMenu;
	private: System::Windows::Forms::ToolStripMenuItem^  difficultyCaption;
	private: System::Windows::Forms::ToolStripMenuItem^  easyItem;
	private: System::Windows::Forms::ToolStripMenuItem^  middleItem;
	private: System::Windows::Forms::ToolStripMenuItem^  hardItem;
	private:
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->newGameButton = (gcnew System::Windows::Forms::Button());
			this->upField = (gcnew System::Windows::Forms::Button());
			this->leftField = (gcnew System::Windows::Forms::Button());
			this->rightField = (gcnew System::Windows::Forms::Button());
			this->downField = (gcnew System::Windows::Forms::Button());
			this->difficultyMenu = (gcnew System::Windows::Forms::MenuStrip());
			this->difficultyCaption = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->easyItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->middleItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->hardItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->scoreTextLabel = (gcnew System::Windows::Forms::Label());
			this->scoreLabel = (gcnew System::Windows::Forms::Label());
			this->difficultyMenu->SuspendLayout();
			this->SuspendLayout();
			// 
			// newGameButton
			// 
			this->newGameButton->BackColor = System::Drawing::SystemColors::Control;
			this->newGameButton->Location = System::Drawing::Point(25, 43);
			this->newGameButton->Name = L"newGameButton";
			this->newGameButton->Size = System::Drawing::Size(100, 30);
			this->newGameButton->TabIndex = 0;
			this->newGameButton->Text = L"Новая игра";
			this->newGameButton->UseVisualStyleBackColor = false;
			this->newGameButton->Click += gcnew System::EventHandler(this, &gameForm::newGameButton_Click);
			this->newGameButton->KeyUp += gcnew System::Windows::Forms::KeyEventHandler(this, &gameForm::gameForm_KeyUp);
			// 
			// upField
			// 
			this->upField->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 13, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(204)));
			this->upField->Location = System::Drawing::Point(223, 43);
			this->upField->Name = L"upField";
			this->upField->Size = System::Drawing::Size(37, 25);
			this->upField->TabIndex = 1;
			this->upField->Text = L"^";
			this->upField->UseVisualStyleBackColor = true;
			this->upField->Click += gcnew System::EventHandler(this, &gameForm::upField_Click);
			this->upField->KeyUp += gcnew System::Windows::Forms::KeyEventHandler(this, &gameForm::gameForm_KeyUp);
			// 
			// leftField
			// 
			this->leftField->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(204)));
			this->leftField->Location = System::Drawing::Point(12, 245);
			this->leftField->Name = L"leftField";
			this->leftField->Size = System::Drawing::Size(27, 25);
			this->leftField->TabIndex = 2;
			this->leftField->Text = L"<";
			this->leftField->UseVisualStyleBackColor = true;
			this->leftField->Click += gcnew System::EventHandler(this, &gameForm::leftField_Click);
			this->leftField->KeyUp += gcnew System::Windows::Forms::KeyEventHandler(this, &gameForm::gameForm_KeyUp);
			// 
			// rightField
			// 
			this->rightField->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(204)));
			this->rightField->Location = System::Drawing::Point(443, 245);
			this->rightField->Name = L"rightField";
			this->rightField->Size = System::Drawing::Size(27, 25);
			this->rightField->TabIndex = 3;
			this->rightField->Text = L">";
			this->rightField->UseVisualStyleBackColor = true;
			this->rightField->Click += gcnew System::EventHandler(this, &gameForm::rightField_Click);
			this->rightField->KeyUp += gcnew System::Windows::Forms::KeyEventHandler(this, &gameForm::gameForm_KeyUp);
			// 
			// downField
			// 
			this->downField->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(204)));
			this->downField->Location = System::Drawing::Point(223, 464);
			this->downField->Name = L"downField";
			this->downField->Size = System::Drawing::Size(37, 25);
			this->downField->TabIndex = 4;
			this->downField->Text = L"V";
			this->downField->UseVisualStyleBackColor = true;
			this->downField->Click += gcnew System::EventHandler(this, &gameForm::downField_Click);
			this->downField->KeyUp += gcnew System::Windows::Forms::KeyEventHandler(this, &gameForm::gameForm_KeyUp);
			// 
			// difficultyMenu
			// 
			this->difficultyMenu->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(1) {this->difficultyCaption});
			this->difficultyMenu->Location = System::Drawing::Point(0, 0);
			this->difficultyMenu->Name = L"difficultyMenu";
			this->difficultyMenu->Size = System::Drawing::Size(482, 28);
			this->difficultyMenu->TabIndex = 5;
			// 
			// difficultyCaption
			// 
			this->difficultyCaption->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(3) {this->easyItem, 
				this->middleItem, this->hardItem});
			this->difficultyCaption->Name = L"difficultyCaption";
			this->difficultyCaption->Size = System::Drawing::Size(97, 24);
			this->difficultyCaption->Text = L"Сложность";
			// 
			// easyItem
			// 
			this->easyItem->Checked = true;
			this->easyItem->CheckState = System::Windows::Forms::CheckState::Checked;
			this->easyItem->Name = L"easyItem";
			this->easyItem->Size = System::Drawing::Size(129, 24);
			this->easyItem->Text = L"Легко";
			this->easyItem->Click += gcnew System::EventHandler(this, &gameForm::easyItem_Click);
			// 
			// middleItem
			// 
			this->middleItem->Name = L"middleItem";
			this->middleItem->Size = System::Drawing::Size(129, 24);
			this->middleItem->Text = L"Средне";
			this->middleItem->Click += gcnew System::EventHandler(this, &gameForm::middleItem_Click);
			// 
			// hardItem
			// 
			this->hardItem->Name = L"hardItem";
			this->hardItem->Size = System::Drawing::Size(129, 24);
			this->hardItem->Text = L"Трудно";
			this->hardItem->Click += gcnew System::EventHandler(this, &gameForm::hardItem_Click);
			// 
			// scoreTextLabel
			// 
			this->scoreTextLabel->AutoSize = true;
			this->scoreTextLabel->Location = System::Drawing::Point(313, 43);
			this->scoreTextLabel->Name = L"scoreTextLabel";
			this->scoreTextLabel->Size = System::Drawing::Size(78, 17);
			this->scoreTextLabel->TabIndex = 6;
			this->scoreTextLabel->Text = L"Ваш счёт: ";
			// 
			// scoreLabel
			// 
			this->scoreLabel->AutoSize = true;
			this->scoreLabel->Location = System::Drawing::Point(398, 43);
			this->scoreLabel->Name = L"scoreLabel";
			this->scoreLabel->Size = System::Drawing::Size(16, 17);
			this->scoreLabel->TabIndex = 7;
			this->scoreLabel->Text = L"0";
			// 
			// gameForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(482, 501);
			this->Controls->Add(this->scoreLabel);
			this->Controls->Add(this->scoreTextLabel);
			this->Controls->Add(this->downField);
			this->Controls->Add(this->rightField);
			this->Controls->Add(this->leftField);
			this->Controls->Add(this->upField);
			this->Controls->Add(this->newGameButton);
			this->Controls->Add(this->difficultyMenu);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedSingle;
			this->MainMenuStrip = this->difficultyMenu;
			this->MaximizeBox = false;
			this->Name = L"gameForm";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"Сапёр";
			this->KeyUp += gcnew System::Windows::Forms::KeyEventHandler(this, &gameForm::gameForm_KeyUp);
			this->difficultyMenu->ResumeLayout(false);
			this->difficultyMenu->PerformLayout();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private:
		//создание новой игры
		Void newGame(){
			gameLogic = gcnew Minesweeper(difficulty);
			topCoords = Point(0,0);
		}
		//сообщение о конце игры и показ мин
		Void gameOver(){
			Cell^ cell;
			for(Int32 i = 0; i < FIELDSIZE; ++i){
				for(Int32 j = 0; j < FIELDSIZE; ++j){
					cell = gameLogic->MapGet(topCoords.X + i, topCoords.Y+ j);
					if(cell->state == CellState::Mined){
						cells[i][j]->Text = L"\u2622";
					}
				}
			}
			MessageBox::Show("Вы проиграли!");
		}
		//перерисовка клеток
		Void redrawCells(){
			Int32 x,y;
			Cell^ cell;
			for(Int32 i = 0; i < FIELDSIZE; ++i){
				x = topCoords.X + i;
				for(Int32 j = 0; j < FIELDSIZE; ++j){
					y = topCoords.Y+ j;
					cell = gameLogic->MapGet(x,y);
					if(cell->state == CellState::Opened){
						if(cell->minesCount == 0){
							cells[i][j]->Text = L" ";
						}else {
							cells[i][j]->Text = cell->minesCount.ToString();
						}
						cells[i][j]->FlatStyle = FlatStyle::Flat;
					}else {
						if(cell->flagged){
							cells[i][j]->Text = L"\u2691";
						}
						else{
							cells[i][j]->Text = L" ";
						}
						cells[i][j]->FlatStyle = FlatStyle::Standard;
					}
				}
			}
			scoreLabel->Text = gameLogic->score.ToString();
		}
		//реакция на клик по клетке
		Void CellClicked(Object^  sender, MouseEventArgs^  e){
			CheckBox^ cb = (CheckBox^)sender;
			cb->Checked = true;
			Point coords = (Point)cb->Tag;
			Int32 x = topCoords.X + coords.X;
			Int32 y = topCoords.Y + coords.Y;

			Cell^ cell = gameLogic->MapGet(topCoords.X + coords.X, topCoords.Y + coords.Y);
			bool rightButtonClicked = e->Button == System::Windows::Forms::MouseButtons::Right;
			if(cell->state != CellState::Opened){
				if(rightButtonClicked){
					cell->flagged = !cell->flagged;
				}else if(!cell->flagged){
					cell = gameLogic->Open(x, y);
					if(cell->state == CellState::Mined){
						gameOver();
						newGame();
					}
				}
			}else if(rightButtonClicked){
				cell = gameLogic->OpenNear(x, y);
				if(cell->state == CellState::Mined){
						gameOver();
						newGame();
				}
			}			
			redrawCells();
		}
		//реакция на клик по кнопке начала игры
		System::Void newGameButton_Click(System::Object^  sender, System::EventArgs^  e) {
			newGame();
			redrawCells();
		}
		//перемещаем поле зрения вверх
		private: System::Void upField_Click(System::Object^  sender, System::EventArgs^  e) {
			topCoords.Y -= 1;
			redrawCells();
		}
		//перемещаем поле зрения вниз
		private: System::Void downField_Click(System::Object^  sender, System::EventArgs^  e) {
			topCoords.Y += 1;
			redrawCells();
		}
		//перемещаем поле зрения влево
		private: System::Void leftField_Click(System::Object^  sender, System::EventArgs^  e) {
			topCoords.X -= 1;
			redrawCells();
		}
		//перемещаем поле зрения вправо
		private: System::Void rightField_Click(System::Object^  sender, System::EventArgs^  e) {
			topCoords.X += 1;
			redrawCells();
		}
		//отслеживаем, что нажаты стрелочки на клавиатуре и перемещаем поле зрения
		private: System::Void gameForm_KeyUp(System::Object^  sender, System::Windows::Forms::KeyEventArgs^  e) {
			e->Handled =true;
			switch(e->KeyCode){
				case Keys::Up: 
					upField_Click(nullptr, nullptr);
					break;
				case Keys::Down: 
					downField_Click(nullptr, nullptr);
					break;
				case Keys::Left: 
					leftField_Click(nullptr, nullptr);
					break;
				case Keys::Right: 
					rightField_Click(nullptr, nullptr);
					break;
				}
			}
		//изменение сложности на легкую
		private: System::Void easyItem_Click(System::Object^  sender, System::EventArgs^  e) {
			gameLogic->difficulty = difficulty = EASY;
			easyItem->Checked = true;
			middleItem->Checked = false;
			hardItem->Checked = false;
		}
		//изменение сложности на среднюю
		private: System::Void middleItem_Click(System::Object^  sender, System::EventArgs^  e) {
			gameLogic->difficulty = difficulty = MIDDLE;
			easyItem->Checked = false;
			middleItem->Checked = true;
			hardItem->Checked = false;
		}
		//изменение сложности на сложную
		private: System::Void hardItem_Click(System::Object^  sender, System::EventArgs^  e) {
			gameLogic->difficulty = difficulty = HARD;
			easyItem->Checked = false;
			middleItem->Checked = false;
			hardItem->Checked = true;
		}
	};
}

#pragma once

namespace airplanedb {
	using namespace System::Collections::Generic;
	//состояния ячейки поля
	public enum class CellState { Undefined, NotCalculated, Opened, Mined };
	//класс представляющий клетку игрового поля
	public ref class Cell{
	public:
		CellState state;//состояние клетки
		bool flagged;	//помечена ли клетка флажком
		Int32 minesCount;//количество мин вокруг клетки
		//конструктор без параметров
		Cell(){
			 state = CellState::Undefined;
			 flagged = false;
			 minesCount = 0;
		}
		//конструктор с параметром - состояние клетки
		Cell(CellState _state){
			state = _state;
			minesCount = 0;
			flagged = false;
		}
	};
	//класс логики игры в сапёр
	public ref class Minesweeper{
	private:
		Random^ r;	//генератор случайных чисел
		bool firstClick;	//первый ли это клик в игре - при первом клике нельзя попасть на мину
		Dictionary<String^, Cell^> map;	//игровое поле
		//установить ячейку игрового поля
		Void MapSet(Int32 x, Int32 y, Cell^ val){
			String^ key = x.ToString() + L"," + y.ToString();
			map[key] = val;
		}
		//определить, является ли клетка минированной или нет
		Cell^ Define(Int32 x, Int32 y, Cell^ cell){
			if(cell->state == CellState::Undefined){
				if(r->Next(0,difficulty) == 1 && !firstClick){
					cell->state = CellState::Mined;
				}else {
					cell->state = CellState::NotCalculated;
					firstClick = false;
				}
			}
			MapSet(x, y, cell);
			return cell;
		}
		//посчитать минированные клетки вокруг данной и открыть её.
		//Если вокруг нет мин, то открыть все соседние клетки
		Cell^ Calculate(Int32 x, Int32 y, Cell^ res, Int32 depth){
			res->state = CellState::Opened;
			res->flagged = false;
			++score;
			Cell^ tmpCell;
			for(Int32 i = -1; i <= 1; ++i){
				for(Int32 j = -1; j <= 1; ++j){
					if(i != 0 || j != 0){
						tmpCell = MapGet(x+i,y+j);
						Define(x+i,y+j, tmpCell);
						if(tmpCell->state == CellState::Mined){
							res->minesCount += 1;
						}
					}
				}
			}
			if(res->minesCount == 0){
				for(Int32 i = -1; i <= 1; ++i){
					for(Int32 j = -1; j <= 1; ++j){
						if(i != 0 || j != 0){
							tmpCell = MapGet(x+i,y+j);
							if(tmpCell->state != CellState::Opened && depth < 100){
								Calculate(x+i, y+j, tmpCell, depth+1);
							}
						}
					}
				}
			}
			return res;
		}
	public:
		property Int32 difficulty;	//сложность игры
		property Int32 score;	//счёт игрока
		//конструктор принимающий параметр - сложность игры
		Minesweeper(Int32 _difficulty){
			r = gcnew Random();
			difficulty = _difficulty;
			score = 0;
			firstClick = true;
		}
		//получить ячейку по заданным координатам
		Cell^ MapGet(Int32 x, Int32 y){
			String^ key = x.ToString() + L"," + y.ToString();
			Cell^ result;
			if(!map.TryGetValue(key, result)){
				result = gcnew Cell();
			}
			return result;
		}
		//открыть заданную ячейку
		Cell^ Open(Int32 x, Int32 y){
			Cell^ res;
			res = MapGet(x,y);
			switch(res->state){
				case CellState::Undefined:
					Define(x,y,res);
					res = Open(x,y);
					break;
				case CellState::NotCalculated:
					Calculate(x, y, res, 0);
					break;
			}
			return res;
		}
		//открыть ячейки вокруг данной, если все мины вокруг неё помечены
		Cell^ OpenNear(Int32 x, Int32 y){
			Cell^ tmpCell;
			Cell^ cell = MapGet(x,y);
			Int32 flagsCount = 0;
			for(Int32 i = -1; i <= 1; ++i){
				for(Int32 j = -1; j <= 1; ++j){
					if(i != 0 || j != 0){
						tmpCell = MapGet(x+i,y+j);
						if(tmpCell->flagged){
							flagsCount += 1;
						}
					}
				}
			}
			if(flagsCount == cell->minesCount){
				for(Int32 i = -1; i <= 1; ++i){
					for(Int32 j = -1; j <= 1; ++j){
						if(i != 0 || j != 0){
							tmpCell = MapGet(x+i,y+j);
							if(tmpCell->state != CellState::Opened && !tmpCell->flagged){
								tmpCell = Open(x+i,y+j);
								if(tmpCell->state == CellState::Mined)
									return tmpCell;
							}
						}
					}
				}
			}
			return cell;
		}
	};
}
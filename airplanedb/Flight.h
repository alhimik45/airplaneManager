#pragma once

namespace airplanedb {
	using namespace System;

	//Класс представляющий запись об одном рейсе
	public ref class Flight {
	private:
		static array<String^>^ weekDays = gcnew array<String^> 
		{L"Понедельник",  
		L"Вторник",
		L"Среда",
		L"Четверг",
		L"Пятница",
		L"Суббота",
		L"Воскресенье"};
		//конвертирует строку в объект TimeSpan
		TimeSpan^ toTime(String^ str){
			array<Char>^ separator = gcnew array<Char>{L':'};
			array<String^>^ nums = str->Split(separator);
			Int32 hours, minutes;
			if(Int32::TryParse(nums[0], hours) && Int32::TryParse(nums[1], minutes)){
				return  gcnew TimeSpan(hours, minutes, 0);
			}else {
				return nullptr;
			}
		}
	public:		
		property Decimal number; 		//номер записи
		property String^ airplaneName;	//название самолёта
		property String^ cityName; 		//город прилёта
		property Decimal cost; 			//стоимость
		property Int32 days;			//по каким дням рейс
		property TimeSpan^ timeFrom; 	//врёмя отлёта
		property TimeSpan^ timeTo;		//время прилёта

		//получение списка дней в человеко-читаемом виде
		property String^ stringDays {
			String^ get(){
				String^ result = L"";
				bool writed = false;
				for(Int32 i = 0; i < 7; ++i){
					if (days & 1 << i){
						result += weekDays[i] + L",";
						writed = true;
					}
				}
				if(writed) //удаление лишней запятой
					result = result->TrimEnd(L',');
				return result;
			}
		}
		//получение времени отправки в виде строки
		property String^ stringTimeFrom {
			String^ get(){
				return  (gcnew DateTime(timeFrom->Ticks))->ToString(L"HH:mm");
			}
			void set(String^ str){
				timeFrom = toTime(str);
			}
		}
		//получение времени прилёта в виде строки
		property String^ stringTimeTo {
			String^ get(){
				return  (gcnew DateTime(timeTo->Ticks))->ToString(L"HH:mm");
			}
			void set(String^ str){
				timeTo = toTime(str);
			}
		}
		//конструктор без параметров
		Flight(){	
			number = 0;
			airplaneName = L"";
			cityName = L"";
			cost = 0;
			days = 0;
			timeFrom = nullptr;
			timeTo = nullptr;
		}
		// конструктор принимающий строковое представление рейса
		Flight(String^ stringedFlight){ 
			array<Char>^ separator = gcnew array<Char>{L'|'};
			array<String^>^ lines = stringedFlight->Split(separator);
			number = Decimal::Parse(lines[0]);
			airplaneName = lines[1];
			cityName = lines[2];
			cost = Decimal::Parse(lines[3]);
			days = Int32::Parse(lines[4]);
			stringTimeFrom = lines[5];
			stringTimeTo = lines[6];
		}
		//конвертация рейса в строку
		virtual String^ ToString() override { 
			return number 		+ L"|"
			+ airplaneName 		+ L"|"
			+ cityName 			+ L"|"
			+ cost 				+ L"|"
			+ days				+ L"|"
			+ stringTimeFrom 	+ L"|"
			+ stringTimeTo;
		}
	};
}
#pragma once

#include "Flight.h"

namespace airplanedb {
	using namespace System;
	using namespace System::IO;
	using namespace System::Collections;

	//Функция для безопасного открытия файла
	static FileStream^ OpenFile(String^ filename){
		if (File::Exists(filename)){
			return gcnew FileStream(filename, FileMode::Open, FileAccess::ReadWrite);
		}else {
			return gcnew FileStream(filename, FileMode::Create, FileAccess::ReadWrite);
		}
	}
	//Функция для освобождения ресурсов
	static void Delete(Object^ obj){
		if(obj != nullptr) delete obj;
	}

	//класс для итерации по всему списку рейсов
	private ref class FlightEnum : public IEnumerator, IDisposable {
	private:
		Flight^ current;	//текущий рейс
		StreamReader^ sr;	//читатель потока
		FileStream^ fs;		//файловый поток
		String^ filename;	//имя файла
	public:
		//конструктор принимающий имя файла
		FlightEnum(String^ name){
			filename = name;
			fs = nullptr;
			sr = nullptr;
			Reset();
		}
		//попытка получения следующего рейса, при успехе он становится текущим
		virtual bool MoveNext(){
			String^ line = sr->ReadLine();
			if(line == nullptr){
				return false;
			}
			current = gcnew Flight(line);
			return true;
		}
		//переход к началу списка
		virtual void Reset(){
			Delete(sr);
			Delete(fs);
			fs = OpenFile(filename);
			sr = gcnew StreamReader(fs);
			current = nullptr;
		}
		//получение текущего рейса
		property Object^ Current{
			virtual Object^ get(){
				return current;
			}
		}
		//деструктор, закрывающий потоки
		~FlightEnum(){
			Delete(sr);
			Delete(fs);
		}
	};
	//класс для хранения/добавления/удаления/изменения рейсов
	public ref class FlightStorage: public IEnumerable {
	private:
		String^ filename;	//файл с данными
	public:
		//конструктор принимающий имя файла
		FlightStorage(String^ name){
			filename = name;
		}
		//получение итератора по списку рейсов
		virtual IEnumerator^ GetEnumerator(){
			return gcnew FlightEnum(filename);
		}
		//добавление рейса
		void AddFlight(Flight^ f){
			FileStream^ fs = OpenFile(filename);
			fs->Seek(0, SeekOrigin::End);
			{
				StreamWriter sw(fs);
				sw.WriteLine(f->ToString());
			}
			Delete(fs);
		}
		//удаление рейса
		void RemoveFlight(Int32 index){
			String^ tempFile = Path::GetTempFileName();
			FileStream^ fs = OpenFile(filename);
			{
				FileStream^ temp = OpenFile(tempFile);
				StreamReader sr(fs);
				StreamWriter sw(temp);
				String^ line;
				for(Int32 i = 0; (line = sr.ReadLine()) != nullptr; ++i){
					if(i != index){
						sw.WriteLine(line);
					}
				}
			}
			if (File::Exists(tempFile)) {
				File::Delete(filename);
				File::Move(tempFile, filename);
			}
			Delete(fs);
		}
		//изменение рейса
		void ChangeFlight(Int32 index, Flight^ f){
			String^ tempFile = Path::GetTempFileName();
			FileStream^ fs = OpenFile(filename);
			{
				FileStream^ temp = OpenFile(tempFile);
				StreamReader sr(fs);
				StreamWriter sw(temp);
				String^ line;
				for(Int32 i = 0; (line = sr.ReadLine()) != nullptr; ++i){
					if(i == index){
						sw.WriteLine(f->ToString());
					}else {
						sw.WriteLine(line);
					}
				}
			}
			if (File::Exists(tempFile)) {
				File::Delete(filename);
				File::Move(tempFile, filename);
			}
			Delete(fs);
		}
	};
}
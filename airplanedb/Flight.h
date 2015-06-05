#pragma once

namespace airplanedb {
	using namespace System;

	//����� �������������� ������ �� ����� �����
	public ref class Flight {
	private:
		static array<String^>^ weekDays = gcnew array<String^> 
		{L"�����������",  
		L"�������",
		L"�����",
		L"�������",
		L"�������",
		L"�������",
		L"�����������"};
		//������������ ������ � ������ TimeSpan
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
		property Decimal number; 		//����� ������
		property String^ airplaneName;	//�������� �������
		property String^ cityName; 		//����� ������
		property Decimal cost; 			//���������
		property Int32 days;			//�� ����� ���� ����
		property TimeSpan^ timeFrom; 	//���� �����
		property TimeSpan^ timeTo;		//����� ������

		//��������� ������ ���� � ��������-�������� ����
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
				if(writed) //�������� ������ �������
					result = result->TrimEnd(L',');
				return result;
			}
		}
		//��������� ������� �������� � ���� ������
		property String^ stringTimeFrom {
			String^ get(){
				return  (gcnew DateTime(timeFrom->Ticks))->ToString(L"HH:mm");
			}
			void set(String^ str){
				timeFrom = toTime(str);
			}
		}
		//��������� ������� ������ � ���� ������
		property String^ stringTimeTo {
			String^ get(){
				return  (gcnew DateTime(timeTo->Ticks))->ToString(L"HH:mm");
			}
			void set(String^ str){
				timeTo = toTime(str);
			}
		}
		//����������� ��� ����������
		Flight(){	
			number = 0;
			airplaneName = L"";
			cityName = L"";
			cost = 0;
			days = 0;
			timeFrom = nullptr;
			timeTo = nullptr;
		}
		// ����������� ����������� ��������� ������������� �����
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
		//����������� ����� � ������
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
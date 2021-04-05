#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

#define MinYear 1
#define MaxYear 2021
#define MinMonth 1
#define MaxMonth 12
#define MinDay 1
#define Jan 31
#define Mar 31
#define Apr 30
#define May 31
#define Jun 30
#define Jul 31
#define Aug 31
#define Sep 30
#define Oct 31
#define Nov 30
#define Dec 31

struct myDate{
	private:
		unsigned int day;
		unsigned int month;
		unsigned int year;
	public:
	myDate(	unsigned int Day=1,unsigned int Month=1,unsigned int Year=1 ){
		set(Day,Month,Year);
	}
	unsigned int getParams(unsigned int x=0){
		unsigned int temp=1;
		if(x==1) return day;
		if(x==2) return month;
		if(x==3) return year;
		return temp;
	} 
	string displayStr(char DEL='.'){
		char buffer[4];
		string temp="";
		if(day<10) temp=temp+"0"+itoa(day,buffer,10);
		else temp+=itoa(day,buffer,10);
		temp+=DEL;
		if(month<10) temp=temp+"0"+itoa(month,buffer,10);
		else temp+=itoa(month,buffer,10);
		temp+=DEL;
		temp=temp+itoa(year,buffer,10);
		return temp;
	}
	void set(unsigned int Day=1,unsigned int Month=1,unsigned int Year=1){
		setMonth(Month);
		setYear(Year);
		setDay(Day);
	}
	void setMonth(unsigned int Month){
		if(Month<1) Month=1;
		if(Month>12) Month=12;
		month=Month;
	}
	void setYear(unsigned int Year){
		if(Year<1) Year=1;
		if(Year>2021) Year=2021;
		year=Year;
	}
	bool checkYear(){
		bool temp=false;
		if (year % 4 == 0) {
        	if (year % 100 == 0) {
            	if (year % 400 == 0) temp=true;
            	else temp=false;
        	} else temp=true;
    	} else temp=false;
		return temp;
	}
	void setDay(unsigned int Day){
		if(Day<1) Day=1;
		if(month==2){
			if(checkYear() && Day>29) Day=29;
			if(!checkYear() && Day>28) Day=28;
		}
		if(month==1 && Day>Jan) Day=Jan;
		if(month==3 && Day>Mar) Day=Mar;
		if(month==4 && Day>Apr) Day=Apr;
		if(month==5 && Day>May) Day=May;
		if(month==6 && Day>Jun) Day=Jun;
		if(month==7 && Day>Jul) Day=Jul;
		if(month==8 && Day>Aug) Day=Aug;
		if(month==9 && Day>Sep) Day=Sep;
		if(month==10 && Day>Oct) Day=Oct;
		if(month==11 && Day>Nov) Day=Nov;
		if(month==12 && Day>Dec) Day=Dec;
		day=Day;
	}
};

myDate nextDay(myDate currentDay){
	unsigned int Day=currentDay.getParams(1);
	unsigned int Month=currentDay.getParams(2);
	unsigned int Year=currentDay.getParams(3);
	if(Month==2){
		if(currentDay.checkYear() && Day>=29) return myDate(1,Month+1,Year);
		if(!currentDay.checkYear() && Day>=28) return myDate(1,Month+1,Year);
	}
	if(Month==1 && Day>=Jan) return myDate(1,Month+1,Year);
	if(Month==3 && Day>=Mar) return myDate(1,Month+1,Year);
	if(Month==4 && Day>=Apr) return myDate(1,Month+1,Year);
	if(Month==5 && Day>=May) return myDate(1,Month+1,Year);
	if(Month==6 && Day>=Jun) return myDate(1,Month+1,Year);
	if(Month==7 && Day>=Jul) return myDate(1,Month+1,Year);
	if(Month==8 && Day>=Aug) return myDate(1,Month+1,Year);
	if(Month==9 && Day>=Sep) return myDate(1,Month+1,Year);
	if(Month==10 && Day>=Oct) return myDate(1,Month+1,Year);
	if(Month==11 && Day>=Nov) return myDate(1,Month+1,Year);
	if(Month==12 && Day>=Dec) return myDate(1,1,Year+1);
	return myDate(Day+1,Month,Year);
}
struct myTime{
	private:
		unsigned int second;
		unsigned int minute;
		unsigned int hour;
	public:
	myTime(	unsigned int Second=1,unsigned int Minute=1,unsigned int Hour=1){
		set(Second,Minute,Hour);
	}
	unsigned int getParams(unsigned int x=0){
		unsigned int temp=1;
		if(x==1) return second;
		if(x==2) return minute;
		if(x==3) return hour;
		return temp;
	} 
	void set(unsigned int Second=1,unsigned int Minute=1,unsigned int Hour=1){
		setSecond(Second);
		setMinute(Minute);
		setHour(Hour);
	}
	void setSecond(unsigned int Second){
		if(Second<1) Second=0;
		if(Second>59) Second=59;
		second=Second;
	}
	void setMinute(unsigned int Minute){
		if(Minute<1) Minute=0;
		if(Minute>59) Minute=59;
		minute=Minute;
	}
	void setHourDefault(unsigned int Hour){
		if(Hour<1) Hour=0;
		if(Hour>12) Hour=11;
		hour=Hour;
	}
	void setHour(unsigned int Hour){
		if(Hour<1) Hour=0;
		if(Hour>24) Hour=23;
		hour=Hour;
	}
//	unsigned int checkFormat(bool format,unsigned int Hour){
//		if(format) return setHour(Hour);
//		else return setHourDefault(Hour);
//	}
	string displayStr(char DEL=':'){
		char buffer[4];
		string temp="";
		if(hour<10) temp=temp+"0"+itoa(hour,buffer,10);
		else temp+=itoa(hour,buffer,10);
		temp+=DEL;
		if(minute<10) temp=temp+"0"+itoa(minute,buffer,10);
		else temp+=itoa(minute,buffer,10);
		temp+=DEL;
		if(second<10) temp=temp+"0"+itoa(second,buffer,10);
		else temp+=itoa(second,buffer,10);
		return temp;
	}
};

void currentDateTime(){
	time_t now = time(0);
	tm *ltm = localtime(&now); 																	
	cout<<" Current Time  => \t"<<ltm->tm_mday<<"."<<1 + ltm->tm_mon<<"."<<1900 + ltm->tm_year<<" \t "<<ltm->tm_hour<<":"<<ltm->tm_min<<":"<<ltm->tm_sec<<endl;
}

unsigned int chooseOption(){
	cout<<endl<<"---------------------------------------------------------"<<endl<<endl;
	cout<<"    Choose option( write only number! ) : "<<endl<<endl;
	cout<<" (1)  Difference between current day and current input day"<<endl;
	cout<<" (2)  Difference between current day and new input day"<<endl;
	cout<<" (3)  Difference between current time and current input time"<<endl;
	cout<<" (4)  Difference between current time and new input time"<<endl;
	cout<<" (5)  Sum between current day and current input day"<<endl;
	cout<<" (6)  Sum between current day and new input day"<<endl;
	cout<<" (7)  Sum between current time and current input time"<<endl;
	cout<<" (8)  Sum between current time and new input time"<<endl;
	cout<<" (9)  Get day week for input date"<<endl;
	cout<<" (10) Get day week for new input date"<<endl;
	cout<<" (11) Transfer new input time in seconds"<<endl;
	cout<<" (12) Transfer new input time in minutes"<<endl;
	cout<<" (13) Transfer new input time in hours"<<endl;
	cout<<" (14) Transfer new input seconds in time format"<<endl;
	cout<<" (15) Transfer new input minutes in time format"<<endl;
	cout<<" (16) Transfer new input hours in time format"<<endl;
	cout<<" (17) Convert new input AM to 24H format"<<endl;
	cout<<" (18) Convert new input PM to 24H format"<<endl;
	cout<<" (19) Convert new input 24H format to AM format"<<endl;
	cout<<" (20) Convert new input 24H format to PM format"<<endl;
	cout<<" (21) Renew current input date and time"<<endl;
	cout<<" (22) Code author"<<endl;
	cout<<" (23) Close program"<<endl<<endl;
	unsigned int option=0;cout<<"Choosen option =";cin>>option;
	while(option<1 || option>23){
		cout<<"Number must be 1-23 ! Choose option =";cin>>option;
	}
	cout<<endl<<"---------------------------------------------------------"<<endl<<endl;
	return option;
}

int main(int argc, char** argv) {
	cout<<endl<<"-----------------Date && Time----------------------------"<<endl<<endl;
	cout<<"    Input time | Format Hours:Minute:Second"<<endl<<endl;
	unsigned int currentHour=0;cout<<" Hour=";cin>>currentHour;
	unsigned int currentMinute=0;cout<<" Minute=";cin>>currentMinute;
	unsigned int currentSecond=0;cout<<" Second=";cin>>currentSecond;
	cout<<endl<<"    Input date | Format Day.Month.Hours"<<endl<<endl;
	unsigned int currentDay=0;cout<<" Day=";cin>>currentDay;
	unsigned int currentMonth=0;cout<<" Month=";cin>>currentMonth;
	unsigned int currentYear=0;cout<<" Year=";cin>>currentYear;
	cout<<endl<<"---------------------------------------------------------"<<endl<<endl;
	myTime myTimeStruct=myTime(currentSecond,currentMinute,currentHour);
	myDate myDateStruct=myDate(currentDay,currentMonth,currentYear);
	cout<<" Current input => \t"<<myDateStruct.displayStr()<<" \t "<<myTimeStruct.displayStr()<<endl; 
	      /*Current Time :*/currentDateTime();
	unsigned int choosenOption = chooseOption();
	system("pause");
	return 0;
}

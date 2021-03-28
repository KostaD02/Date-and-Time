#include <iostream>
#include <cstdlib>

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
myTime nextHour(myTime currentTime){
	unsigned int Seconds=currentTime.getParams(1);
	unsigned int Minutes=currentTime.getParams(2);
	unsigned int Hours=currentTime.getParams(3);
}
int main(int argc, char** argv) {
	unsigned int currentDay=0;cout<<"Day=";cin>>currentDay;
	unsigned int currentMonth=0;cout<<"Month=";cin>>currentMonth;
	unsigned int currentYear=0;cout<<"Year=";cin>>currentYear;
	myDate myDateStruct=myDate(currentDay,currentMonth,currentYear);
	cout<<"DAY.MONTH.YEAR"<<endl<<myDateStruct.displayStr()<<endl;
	myDate NextDay=nextDay(myDateStruct);
	cout<<NextDay.displayStr()<<endl;
	unsigned int currentHour=0;cout<<"Hour=";cin>>currentHour;
	unsigned int currentMinute=0;cout<<"Minute=";cin>>currentMinute;
	unsigned int currentSecond=0;cout<<"Second=";cin>>currentSecond;
	myTime myTimeStruct=myTime(currentSecond,currentMinute,currentHour);
	cout<<"HOURS:MINUTES:SECONDS"<<endl<<myTimeStruct.displayStr()<<endl;

	//cout<<NextDay.day<<"."<<NextDay.month<<"."<<NextDay.year<<endl;
	return 0;
}

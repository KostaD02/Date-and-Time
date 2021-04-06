#include <iostream>
#include <cstdlib>
#include <ctime>
#include <math.h>
  
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

void decoration(unsigned int choose){
	if(choose == 1) cout<<endl<<"-----------------Date && Time----------------------------"<<endl<<endl;
	if(choose == 2) cout<<endl<<"---------------------------------------------------------"<<endl<<endl;
}

unsigned int currentDateTime(unsigned int choose=0){
	time_t now = time(0);
	tm *ltm = localtime(&now);
	if(choose == 0){
		cout<<" Current Time  => \t";
		if(ltm->tm_mday<10) cout<<"0"<<ltm->tm_mday<<".";
		else cout<<ltm->tm_mday<<".";
		if(1 + ltm->tm_mon<10) cout<<"0"<<1 + ltm->tm_mon<<".";
		else cout<<1 + ltm->tm_mon<<".";  
		cout<<1900 + ltm->tm_year<<" \t "; 
		if(ltm->tm_hour<10) cout<<"0"<<ltm->tm_hour<<":";
		else cout<<ltm->tm_hour<<":";
		if(ltm->tm_min<10) cout<<"0"<<ltm->tm_min<<":"<<ltm->tm_sec<<endl;
		else cout<<ltm->tm_min<<":";
		if(ltm->tm_sec<10) cout<<"0"<<ltm->tm_sec<<endl;
		else cout<<ltm->tm_sec<<endl;
		return 1;
	}													
	if(choose == 1){
		return ltm->tm_mday;
	}
	if(choose == 2){
		return 1 + ltm->tm_mon;
	}
	if(choose == 3){
		return 1900 + ltm->tm_year;
	}
	if(choose == 4){
		return ltm->tm_sec;
	}
	if(choose == 5){
		return ltm->tm_min;
	}
	if(choose == 6){
		return ltm->tm_hour;
	}
}

class myDate{
	private:
		unsigned int day;
		unsigned int month;
		unsigned int year;
		unsigned int currentYear;
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
		if(Year>currentDateTime(3)+1) Year=currentDateTime(3);
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
myDate difDayDefault(myDate currentDayDif){
	unsigned int Day=currentDayDif.getParams(1);
	unsigned int Month=currentDayDif.getParams(2);
	unsigned int Year=currentDayDif.getParams(3);
	unsigned int currentDay=currentDateTime(1);
	unsigned int currentMonth=currentDateTime(2);
	unsigned int currentYear=currentDateTime(3);
	unsigned int difDay=currentDay-Day;
	unsigned int difMonth=currentMonth-Month;
	unsigned int difYear=currentYear-Year;
	return myDate(difDay,difMonth,difYear);
}
myDate difDayNew(myDate currentDayDif){
	decoration(1);
	cout<<" Choose option was second:"<<endl<<endl<<" Difference between current day and new input day"<<endl<<endl;
	unsigned int Day=0;cout<<" Day= ";cin>>Day;
	unsigned int Month=0;cout<<" Month= ";cin>>Month;
	unsigned int Year=0;cout<<" Year= ";cin>>Year;cout<<endl;
	unsigned int currentDay=currentDateTime(1);
	unsigned int currentMonth=currentDateTime(2);
	unsigned int currentYear=currentDateTime(3);
	unsigned int difDay=currentDay-Day;
	unsigned int difMonth=currentMonth-Month;
	unsigned int difYear=currentYear-Year;
	return myDate(difDay,difMonth,difYear);
}
myDate sumDayDefault(myDate currentDaySum){
	unsigned int Day=currentDaySum.getParams(1);
	unsigned int Month=currentDaySum.getParams(2);
	unsigned int Year=currentDaySum.getParams(3);
	unsigned int currentDay=currentDateTime(1);
	unsigned int currentMonth=currentDateTime(2);
	unsigned int currentYear=currentDateTime(3);
	unsigned int difDay=currentDay+Day;
	unsigned int difMonth=currentMonth+Month;
	unsigned int difYear=currentYear+Year;
	return myDate(difDay,difMonth,difYear);
}
myDate sumDayNew(myDate currentDayDif){
	decoration(1);
	cout<<" Choose option was sixth :"<<endl<<endl<<" Difference between current day and new input day"<<endl<<endl;
	unsigned int Day=0;cout<<" Day= ";cin>>Day;
	unsigned int Month=0;cout<<" Month= ";cin>>Month;
	unsigned int Year=0;cout<<" Year= ";cin>>Year;cout<<endl;
	unsigned int currentDay=currentDateTime(1);
	unsigned int currentMonth=currentDateTime(2);
	unsigned int currentYear=currentDateTime(3);
	unsigned int difDay=currentDay+Day;
	unsigned int difMonth=currentMonth+Month;
	unsigned int difYear=currentYear+Year;
	return myDate(difDay,difMonth,difYear);
}
class myTime{
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
		if(Second>=59) Second=59;
		second=Second;
	}
	void setMinute(unsigned int Minute){
		if(Minute<1) Minute=0;
		if(Minute>=59) Minute=59;
		minute=Minute;
	}
	void setHourDefault(unsigned int Hour){
		if(Hour<1) Hour=0;
		if(Hour>=12) Hour=11;
		hour=Hour;
	}
	void setHour(unsigned int Hour){
		if(Hour<1) Hour=0;
		if(Hour>=24) Hour=23;
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
myTime difTimeDefault(myTime currentTimeDif){
	unsigned int Seconds=currentTimeDif.getParams(1);
	unsigned int Minute=currentTimeDif.getParams(2);
	unsigned int Hours=currentTimeDif.getParams(3);
	unsigned int currentSeconds=currentDateTime(4);
	unsigned int currentMinute=currentDateTime(5);
	unsigned int currentHours=currentDateTime(6);
	unsigned int difSeconds=currentSeconds-Seconds;
	unsigned int difMinute=currentMinute-Minute;
	unsigned int difHours=currentHours-Hours;
	return myTime(difSeconds,difMinute,difHours);
}
myTime difTimeNew(myTime currentTimeDif){
	decoration(1);
	cout<<" Choose option was fourth :"<<endl<<endl<<" Difference between current time and new input time"<<endl<<endl;
	unsigned int Hour=0;cout<<" Hour= ";cin>>Hour;
	unsigned int Minute=0;cout<<" Minute= ";cin>>Minute;
	unsigned int Second=0;cout<<" Second= ";cin>>Second; cout<<endl;
	unsigned int currentSeconds=currentDateTime(4);
	unsigned int currentMinute=currentDateTime(5);
	unsigned int currentHours=currentDateTime(6);
	unsigned int difSeconds=currentSeconds-Second;
	unsigned int difMinute=currentMinute-Minute;
	unsigned int difHours=currentHours-Hour;
	return myTime(difSeconds,difMinute,difHours);
}
myTime sumTimeDefault(myTime currentTimeSum){
	unsigned int Seconds=currentTimeSum.getParams(1);
	unsigned int Minute=currentTimeSum.getParams(2);
	unsigned int Hours=currentTimeSum.getParams(3);
	unsigned int currentSeconds=currentDateTime(4);
	unsigned int currentMinute=currentDateTime(5);
	unsigned int currentHours=currentDateTime(6);
	unsigned int difSeconds=currentSeconds+Seconds;
	unsigned int difMinute=currentMinute+Minute;
	unsigned int difHours=currentHours+Hours;
	return myTime(difSeconds,difMinute,difHours);
}
myTime sumTimeNew(myTime currentTimeSum){
	decoration(1);
	cout<<" Choose option was eighth :"<<endl<<endl<<" Sum between current time and new input time"<<endl<<endl;
	unsigned int Hour=0;cout<<" Hour= ";cin>>Hour;
	unsigned int Minute=0;cout<<" Minute= ";cin>>Minute;
	unsigned int Second=0;cout<<" Second= ";cin>>Second;cout<<endl;
	unsigned int currentSeconds=currentDateTime(4);
	unsigned int currentMinute=currentDateTime(5);
	unsigned int currentHours=currentDateTime(6);
	unsigned int difSeconds=currentSeconds+Second;
	unsigned int difMinute=currentMinute+Minute;
	unsigned int difHours=currentHours+Hour;
	return myTime(difSeconds,difMinute,difHours);
}
unsigned int chooseOption(){
	decoration(2);
	cout<<"    Choose option( write only number! )  "<<endl<<endl;
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
	cout<<" (11) Transfer current input time in seconds"<<endl;
	cout<<" (12) Transfer current input time in minutes"<<endl;
	cout<<" (13) Transfer current input time in hours"<<endl;
	cout<<" (14) Transfer new input seconds in time format"<<endl;
	cout<<" (15) Transfer new input minutes in time format"<<endl;
	cout<<" (16) Convert current input 24H to AM/PM format"<<endl;
	cout<<" (17) Convert new input 24H format to AM/PM format"<<endl;
	cout<<" (18) Renew current input date and time"<<endl;
	cout<<" (19) Code author"<<endl;
	cout<<" (20) Close program"<<endl<<endl;
	unsigned int option=0;cout<<"Choosen option = ";cin>>option;
	while(option<1 || option>20){
		cout<<" Number must be 1-20 ! Choose option =";cin>>option;
	}
	decoration(2);
	return option;
}

string week(myDate myDateStruct,unsigned int choose=0){ //Zeller’s Algorithm
	if(choose == 1){
		decoration(1);
		cout<<" Choose option was one :"<<endl<<endl<<" Difference between current day and current input day"<<endl<<endl;
	}
	unsigned int Day=0;
	unsigned int Month=0;
	unsigned int Year=0;
	if(choose == 0){
		Day=myDateStruct.getParams(1);
		Month=myDateStruct.getParams(2);
		Year=myDateStruct.getParams(3);
	}else if(choose == 1){
	cout<<" Day= ";cin>>Day;
	cout<<" Month= ";cin>>Month;
	cout<<" Year= ";cin>>Year;
	}else{
		return "Unexpected error , choose was given wrong";
	}
	string days[7]={"Saturday","Sunday","Monday","Tuesday", "Wednesday","Thursday","Friday"};
	unsigned int Mon=0;
	if(Month >2){
		Mon=Month;//for march to december month code is same as month
	}else{
		Mon=(12+Month);//for Jan and Feb, month code will be 13 and 14
		Year--;//decrease year for month Jan and Feb
	}
	int y=Year%100;//last two digit
	int c=Year/100;//first two digit
	int w=(Day+floor((13*(Mon+1))/5)+y+floor(y/4)+floor(c/4)+(5*c));
	w=w%7;
	return days[w];
}

unsigned long long int transferTime(myTime myTimeStruct,unsigned int choose){
	unsigned int rez=0;
	unsigned int Second=0;
	unsigned int Minute=0;
	unsigned int Hour=0;
	if(choose == 1){
	 	Second=myTimeStruct.getParams(1);
		Minute=myTimeStruct.getParams(2);
	 	Hour=myTimeStruct.getParams(3);
		return rez=(Hour*3600)+(Minute*60)+Second;
	}
	else if(choose == 2){
	 	Second=myTimeStruct.getParams(1);
		Minute=myTimeStruct.getParams(2);
	 	Hour=myTimeStruct.getParams(3);		
		return rez=(Hour*60)+Minute+(Second/60);
	}
	else if(choose == 3){
	 	Second=myTimeStruct.getParams(1);
		Minute=myTimeStruct.getParams(2);
	 	Hour=myTimeStruct.getParams(3);				
		return rez=Hour+(Minute/60)+(Second/3600); 
	}
	else if(choose == 4){
		decoration(1);
		cout<<" Choose option was fourteenth :"<<endl<<endl<<" Transfer current input seconds in time format"<<endl<<endl;
		cout<<" Second= ";cin>>Second;cout<<endl;
		return Second;
	}
	else if(choose == 5){
		decoration(1);
		cout<<" Choose option was fifteenth :"<<endl<<endl<<" Transfer current input minute in time format"<<endl<<endl;
		cout<<" Minute= ";cin>>Minute;cout<<endl;
		return Minute;
	}
	else{
		cout<<"Unexpected error , choose was given wrong"<<endl;
		return 1;
	}
}

bool checkTime(unsigned int myHour){
	if(myHour>12) return true; //PM	
	else return false; //AM
}

void displayTimeformated(unsigned int second,unsigned int minute,unsigned int hour){
	if(hour>12){
		if(hour-12>10) cout<<hour-12<<":";
		else cout<<"0"<<hour-12<<":";
	}
	else if(hour>=12) cout<<hour<<":";
	else cout<<"0"<<hour<<":";
	if(minute>=10) cout<<minute<<":";
	else cout<<"0"<<minute<<":";
	if(second>=10) cout<<second;
	else cout<<"0"<<second;
	if(checkTime(hour)) cout<<" PM"<<endl;
	else cout<<" AM"<<endl;
}

void returnChoise();
void codeAuthor();
void givingChoises(){
	cout<<" Do you like to back to menu ?"<<endl<<endl;
	cout<<" [0] No(program close)"<<endl;
	cout<<" [1] Yes(back to main menu)"<<endl;
	cout<<" [2] View code author"<<endl<<endl<<endl;
	unsigned int option=0;cout<<" Choosen option = ";cin>>option;
	while(option<0 || option>2){
		cout<<" Number must be 0-2 ! Choose option = ";cin>>option;
	}
	if(option == 1) returnChoise();
	if(option == 2) codeAuthor();
	decoration(2);
}

void displayOption(unsigned int option,myDate myDateStruct,myTime myTimeStruct){
	switch(option){
		default:
			system("cls");
			cout<<endl<<endl<<"Unexpected error , option case doesn't exit"<<endl<<endl;
			break;
		case 1:{
			system("cls");
			decoration(1);
			cout<<" Choose option was first :"<<endl<<endl<<" Difference between current day and current input day"<<endl<<endl;
			myDate DifDayDefault=difDayDefault(myDateStruct);
			currentDateTime();
			cout<<" Current input => \t"<<myDateStruct.displayStr()<<" \t "<<myTimeStruct.displayStr()<<endl; 
	        cout<<endl<<" Answer : "<<DifDayDefault.displayStr()<<endl;
			decoration(2);
			givingChoises();
			break;
		}
		case 2:{
			system("cls");
			myDate DifDayNew=difDayNew(myDateStruct);
			currentDateTime();
			cout<<" Current input => \t"<<myDateStruct.displayStr()<<" \t "<<myTimeStruct.displayStr()<<endl; 
	        cout<<endl<<" Answer : "<<DifDayNew.displayStr()<<endl;
			decoration(2);
			givingChoises();
			break;
		}
		case 3:{
			system("cls");
			myTime DifDayDefault=difTimeDefault(myTimeStruct);
			decoration(1);
			cout<<" Choose option was third :"<<endl<<endl<<" Difference between current time and current input time"<<endl<<endl;
			currentDateTime();
			cout<<" Current input => \t"<<myDateStruct.displayStr()<<" \t "<<myTimeStruct.displayStr()<<endl; 
	        cout<<endl<<" Answer : "<<DifDayDefault.displayStr()<<endl;
			decoration(2);
			givingChoises();
			break;
		}
		case 4:{
			system("cls");
			myTime DifDayDefault=difTimeNew(myTimeStruct);
			currentDateTime();
			cout<<" Current input => \t"<<myDateStruct.displayStr()<<" \t "<<myTimeStruct.displayStr()<<endl; 
	        cout<<endl<<" Answer : "<<DifDayDefault.displayStr()<<endl;
			decoration(2);
			givingChoises();
			break;
		}
		case 5:{
			system("cls");
			myDate SumDayDefault=sumDayDefault(myDateStruct);
			decoration(1);
			cout<<" Choose option was fifth :"<<endl<<endl<<" Sum between current day and current input day"<<endl<<endl;
			currentDateTime();
			cout<<" Current input => \t"<<myDateStruct.displayStr()<<" \t "<<myTimeStruct.displayStr()<<endl; 
	        cout<<endl<<" Answer : "<<SumDayDefault.displayStr()<<endl;
			decoration(2);
			givingChoises();
			break;
		}
		case 6:{
			system("cls");
			myDate SumDayNew=sumDayNew(myDateStruct);
			currentDateTime();
			cout<<" Current input => \t"<<myDateStruct.displayStr()<<" \t "<<myTimeStruct.displayStr()<<endl; 
	        cout<<endl<<" Answer : "<<SumDayNew.displayStr()<<endl;
			decoration(2);
			givingChoises();
			break;
		}
		case 7:{
			system("cls");
			myTime SumTimeDefault=sumTimeDefault(myTimeStruct);
			decoration(1);
			cout<<" Choose option was seventh :"<<endl<<endl<<" Sum between current time and current input time"<<endl<<endl;
			currentDateTime();
			cout<<" Current input => \t"<<myDateStruct.displayStr()<<" \t "<<myTimeStruct.displayStr()<<endl; 
	        cout<<endl<<" Answer : "<<SumTimeDefault.displayStr()<<endl;
			decoration(2);
			givingChoises();
			break;
		}
		case 8:{
			system("cls");
			myTime SumTimeNew=sumTimeNew(myTimeStruct);
			currentDateTime();
			cout<<" Current input => \t"<<myDateStruct.displayStr()<<" \t "<<myTimeStruct.displayStr()<<endl; 
	        cout<<endl<<" Answer : "<<SumTimeNew.displayStr()<<endl;
			decoration(2);
			givingChoises();
			break;
		}
		case 9:{
			system("cls");
			decoration(1);
			cout<<" Choose option was ninth :"<<endl<<endl<<" Get day week for current input date"<<endl<<endl;
			currentDateTime();
			cout<<" Current input => \t"<<myDateStruct.displayStr()<<" \t "<<myTimeStruct.displayStr()<<endl;
			cout<<endl<<" Day of week will be => "<<week(myDateStruct)<<endl;
			decoration(2);
			givingChoises();
			break;
		}
		case 10:{
			system("cls");
			decoration(1);
			cout<<" Choose option was tenth :"<<endl<<endl<<" Get day week for new input date"<<endl<<endl;
			currentDateTime();
			cout<<" Current input => \t"<<myDateStruct.displayStr()<<" \t "<<myTimeStruct.displayStr()<<endl;
			cout<<endl<<" Day of week will be => "<<week(myDateStruct,1)<<endl;
			decoration(2);
			givingChoises();
			break;
		}
		case 11:{
			system("cls");
			decoration(1);
			cout<<" Choose option was eleventh :"<<endl<<endl<<" Transfer current input time in seconds"<<endl<<endl;
			currentDateTime();
			cout<<" Current input => \t"<<myDateStruct.displayStr()<<" \t "<<myTimeStruct.displayStr()<<endl;
			cout<<endl<<" Answer : "<<transferTime(myTimeStruct,1)<<" Seconds"<<endl;
			decoration(2);
			givingChoises();
			break;
		}
		case 12:{
			system("cls");
			decoration(1);
			cout<<" Choose option was twelfth :"<<endl<<endl<<" Transfer current input time in minutes"<<endl<<endl;
			currentDateTime();
			cout<<" Current input => \t"<<myDateStruct.displayStr()<<" \t "<<myTimeStruct.displayStr()<<endl;
			cout<<endl<<" Answer : "<<transferTime(myTimeStruct,2)<<" Minute"<<endl;
			decoration(2);
			givingChoises();
			break;
		}
		case 13:{
			system("cls");
			decoration(1);
			cout<<" Choose option was thirteenth :"<<endl<<endl<<" Transfer current input time in hours"<<endl<<endl;
			currentDateTime();
			cout<<" Current input => \t"<<myDateStruct.displayStr()<<" \t "<<myTimeStruct.displayStr()<<endl;
			cout<<endl<<" Answer : "<<transferTime(myTimeStruct,3)<<" Hour"<<endl;
			decoration(2);
			givingChoises();
			break;
		}
		case 14:{
			system("cls");
			unsigned long long int second = transferTime(myTimeStruct,4);
			unsigned long long int minute = second/60;
			unsigned long long int hour = minute/60;
			currentDateTime();
			cout<<" Current input => \t"<<myDateStruct.displayStr()<<" \t "<<myTimeStruct.displayStr()<<endl;
			cout<<endl<<" Answer : "<<hour<<":"<<(minute%60)<<":"<<(second%60)<<endl;
			decoration(2);
			givingChoises();
			break;
		}
		case 15:{
			system("cls");
			unsigned long long int minute = transferTime(myTimeStruct,5);
			unsigned long long int second = minute*60;
			unsigned long long int hour = minute/60;
			currentDateTime();
			cout<<" Current input => \t"<<myDateStruct.displayStr()<<" \t "<<myTimeStruct.displayStr()<<endl;
			cout<<endl<<" Answer : "<<hour<<":"<<(minute%60)<<":"<<(second%60)<<endl;
			decoration(2);
			givingChoises();
			break;
		}
		case 16:{ 
			system("cls");
			unsigned int hour = myTimeStruct.getParams(3);
			unsigned int minute = myTimeStruct.getParams(2);
			unsigned int second = myTimeStruct.getParams(1);
			myTime DifDayDefault=difTimeDefault(myTimeStruct);
			decoration(1);
			cout<<" Choose option was sixteenth :"<<endl<<endl<<" Convert current input 24H to AM/PM format"<<endl<<endl;
			currentDateTime();
			cout<<" Current input => \t"<<myDateStruct.displayStr()<<" \t "<<myTimeStruct.displayStr()<<endl;
			cout<<endl<<" Answer : ";displayTimeformated(second,minute,hour);
			cout<<endl<<endl;
			decoration(2);
			givingChoises();
			break;
		}
		case 17:{
			system("cls");
			decoration(1);
			cout<<" Choose option was seventeenth :"<<endl<<endl<<" Convert new input 24H format to AM/PM format"<<endl<<endl;
			unsigned int Hour=0;cout<<" Hour= ";cin>>Hour;
			unsigned int Minute=0;cout<<" Minute= ";cin>>Minute;
			unsigned int Second=0;cout<<" Second= ";cin>>Second;cout<<endl;
			currentDateTime();
			myTime myTimeStructt=myTime(Second,Minute,Hour);
			cout<<" Current input => \t"<<myDateStruct.displayStr()<<" \t "<<myTimeStructt.displayStr()<<endl<<endl;
			cout<<endl<<" Answer : ";displayTimeformated(Second,Minute,Hour);
			cout<<endl<<endl;
			givingChoises();
			break;
		}
		case 18:{
			returnChoise();
			break;
		}
		case 19:{
			system("cls");
			codeAuthor();
			break;
		}
		case 20:{
			//Program close
			break;
		}
	}
}

void returnChoise(){
	system("cls");
	decoration(1);
	cout<<"    Input time | Format Hours:Minute:Second"<<endl<<endl;
	unsigned int currentHour=0;cout<<" Hour= ";cin>>currentHour;
	unsigned int currentMinute=0;cout<<" Minute= ";cin>>currentMinute;
	unsigned int currentSecond=0;cout<<" Second= ";cin>>currentSecond;
	cout<<endl<<"    Input date | Format Day.Month.Hours"<<endl<<endl;
	unsigned int currentDay=0;cout<<" Day= ";cin>>currentDay;
	unsigned int currentMonth=0;cout<<" Month= ";cin>>currentMonth;
	unsigned int currentYear=0;cout<<" Year= ";cin>>currentYear;
	decoration(2);
	myTime myTimeStruct=myTime(currentSecond,currentMinute,currentHour);
	myDate myDateStruct=myDate(currentDay,currentMonth,currentYear);
	currentDateTime();
	cout<<" Current input => \t"<<myDateStruct.displayStr()<<" \t "<<myTimeStruct.displayStr()<<endl; 
	unsigned int choosenOption = chooseOption();
	displayOption(choosenOption,myDateStruct,myTimeStruct);	
}

void codeAuthor(){
	cout<<endl<<"--------------------------------Date && Time--------------------------------------"<<endl<<endl; 
	cout<<" Choose option was Code Author "<<endl<<endl;
	currentDateTime();
	cout<<endl<<endl<<"================================================================================="<<endl<<endl;
	cout<<" Thanks for using my code"<<endl;
	cout<<endl;
	cout<<" If u appreciate my work,u can star code on github and follow me ^_^"<<endl;
	cout<<endl;
	cout<<" My GitHub : https://github.com/kostad02    | Check also other repositories "<<endl;
	cout<<endl;
	cout<<endl;
	cout<<"((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((("<<endl;
	cout<<"( /&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&"<<endl;
	cout<<"( /&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&"<<endl;
	cout<<"( &&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&"<<endl;
	cout<<"( /&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&"<<endl;
	cout<<"(&/&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&"<<endl;
	cout<<"(&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&"<<endl;
	cout<<"(&/&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&"<<endl;
	cout<<"(&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&"<<endl;
	cout<<"(&&&&&&&&&&&&&&&&&&            &&&&&&&&&&&&                &&&&&&&&&&&&&&&&&&&&"<<endl;
	cout<<"(&/&&&&&&&&&&&&&&&&   &&&&&(   &&&&&&&&&&    &&&&&&&    &&&&&&&&&&&&&&&&&&&&&&&"<<endl;
	cout<<"(&&&&&&&&&&&&&&&&&&   &&&&&(   &&&&&&&#    &&&&&&*    &&&&&&&&&&&&&&&&&&&&&&&&&"<<endl;
	cout<<"(&/&&&&&&&&&&&&&&&&   &&&&&(   &&&&&     &&&&&&    /&&&&&&&&&&&&&&&&&&&&&&&&&&&"<<endl;
	cout<<"(&/&&&&&&&&&&&&&&&&   &&&&&(   &&&    %&&&&&&    &&&&&&&&&&&&&&&&&&&&&&&&&&&&&&"<<endl;
	cout<<"(&&&&&&&&&&&&&&&&&&   &&&&&(   &&&    %&&&     &&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&"<<endl;
	cout<<"(&/&&&&&&&&&&&&&&&&   &&&&&(   &&&&& &&&    &&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&"<<endl;
	cout<<"(&/&&&&&&&&&&&&&&&&   &&&&&(    &&&&&/    &&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&"<<endl;
	cout<<"(&&&&&&&&&&&&&&&&&&   &&&&&&&#    &&&, *&&   &&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&"<<endl;
	cout<<"(&/&&&&&&&&&&&&&&&&   &&&&&&&&&%    &&&&&&&    &&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&"<<endl;
	cout<<"(&/&&&&&&&&&&&&&&&&   &&&&&&&( &&&    &&&&&&&    &&&&&&&&&&&&&&&&&&&&&&&&&&&&&&"<<endl;
	cout<<"(&&&&&&&&&&&&&&&&&&   &&&&&    ,&&&&    &&&&&&&    &&&&&&&&&&&&&&&&&&&&&&&&&&&&"<<endl;
	cout<<"(&/&&&&&&&&&&&&&&&&   &&(    &&&&&&&&&    &&&&&&&    &&&&&&&&&&&&&&&&&&&&&&&&&&"<<endl;
	cout<<"(&&&&&&&&&&&&&&&&&&       ,&&&&&&&&&&&&&    &&&&&&&    &&&&&&&&&&&&&&&&&&&&&&&&"<<endl;
	cout<<"(&&&&&&&&&&&&&&&&&&     &&&&&&&&&&&&&&&&&&    &&&&&&&    %&&&&&&&&&&&&&&&&&&&&&"<<endl;
	cout<<"(&/&&&&&&&&&&&&&&&&  .&&&&&&&&&&&&&&&&&&&&&&               #&&&&&&&&&&&&&&&&&&&"<<endl;
	cout<<"(&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&...............(&&&&&&&&&&&&&&&&&"<<endl;
	cout<<"(&%&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&"<<endl;
	cout<<"(&/&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&"<<endl;
	cout<<"( &&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&"<<endl;
	cout<<"( /&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&"<<endl;
	cout<<"( /&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&%&&&&&&&&&&&&&&&&&&&&&&&&&&&&&"<<endl; 
	cout<<"( &&    &&&    &&&    &&&    &&&    &&&    &&&    &&&    &&&    &&&    &&&    &"<<endl;
	cout<<endl<<endl<<"================================================================================="<<endl<<endl; 
}

int main(int argc, char** argv) {
	decoration(1);
	cout<<"    Input time | Format Hours:Minute:Second"<<endl<<endl;
	unsigned int currentHour=0;cout<<" Hour= ";cin>>currentHour;
	unsigned int currentMinute=0;cout<<" Minute= ";cin>>currentMinute;
	unsigned int currentSecond=0;cout<<" Second= ";cin>>currentSecond;
	cout<<endl<<"    Input date | Format Day.Month.Hours"<<endl<<endl;
	unsigned int currentDay=0;cout<<" Day= ";cin>>currentDay;
	unsigned int currentMonth=0;cout<<" Month= ";cin>>currentMonth;
	unsigned int currentYear=0;cout<<" Year= ";cin>>currentYear;
	decoration(2);
	myTime myTimeStruct=myTime(currentSecond,currentMinute,currentHour);
	myDate myDateStruct=myDate(currentDay,currentMonth,currentYear);
	currentDateTime();
	cout<<" Current input => \t"<<myDateStruct.displayStr()<<" \t "<<myTimeStruct.displayStr()<<endl; 
	unsigned int choosenOption = chooseOption();
	displayOption(choosenOption,myDateStruct,myTimeStruct);
	return 0;
}

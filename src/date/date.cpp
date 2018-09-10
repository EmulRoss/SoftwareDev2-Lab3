// date.cpp
// Implementation of the Date class

#include "date.h"

Date::Date(int day, Month month, int year):_day{day},_month{month},_year{year}
{
	if(daysInMonth()<day ||day<=0 ){
	
	throw InvalidDate();
}
else if(year < 0){
	 
        throw InvalidDate();
    }
}

Date::Date(){
	_day = _default._day;
    _month = _default._month;
    _year = _default._year;
}

Date Date::_default{1, Month::January,1900};

bool Date::operator==(const Date& rhs) const{
	
	if (_day == rhs._day && _month == rhs._month &&_year == rhs._year ){
		return true;
	}else{
	return false;}
}

 void Date::setDefaultDate(int day, Month month, int year)
{
    _default._day = day;
    _default._month = month;
    _default._year = year;
	return;
}

void Date::DateIncrease(){
	_day++;
	
	if(_day>daysInMonth()){
		_day =1;
		int temp = static_cast<int> (_month);
		 temp++;
		 if(temp==13){
			 _year++;
			 temp =1;
		 }
		 _month= static_cast<Month> (temp);
	}
	return;
}


int Date::day() const
{
	return _day;
}

Month Date::month() const
{
    return _month;
}

int Date::year() const
{
	return _year;
}

bool Date::isLeapYear() const
{
    // leap years must be divisible by 4 but not by 100
    // or divisible by 400
    if(((_year % 4 == 0) && (_year % 100 != 0)) || (_year % 400 == 0))
        return true;
    else
        return false;
}

int Date::daysInMonth() const
{
	switch (_month) {
		case Month::January: 
		case Month::March: 
		case Month::May: 
		case Month::July:
		case Month::August: 
		case Month::October: 
		case Month::December:
			return 31;	
		case Month::April: 
		case Month::June: 
		case Month::September:
		case Month::November:
			return 30;	
		case Month::February:
			if ( isLeapYear() ) return 29;
			else return 28;
		default:
			// should never reach here 
			assert(false); // See: http://www.cplusplus.com/reference/cassert/assert/
            return -1;
	}    
}

// Note, this standalone function is not part of the Date class
void printDate(const Date& date)
{
	cout << date.day() << "/"
		// cast to an integer to allow the month to be sent to the stream
        << static_cast<int>(date.month()) << "/"
		<< date.year()
		<< endl;
}


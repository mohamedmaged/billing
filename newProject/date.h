#ifndef DATE_H
#define DATE_H
class date
{
        private:
int day ;
int month;
int year;
  public:

date (int d=0,int m=0,int y=0)
	{
		day =d;
		m=month;
		year=y;
	}
	void setday (int d){
		day=d;
	}
	void setmonth (int m)
	{
		month=m;
	}
	void setyear (int y)
	{
		year=y;
	}
	int getday()
	{
		return day;
	}
	int getmonth()
	{
		return month;
	}
	int getyear ()
	{
		return year;
	}
};

#endif // DATE_H
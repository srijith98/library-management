#include<iostream>
#include<string.h>
using namespace std;
class Library
{
	int bookid[10];
	int index;
	int due_dd[10],due_mm[10],due_yy[10];
	char title[10][20];
	char author[10][20];
	int qty[10];
	int issued[10];
	int balance[10];
	public:
	Library()
	{
		index=0;
		for(int i=0;i<10;i++)
			issued[i]=0;
	}
	void entry();
	void disp();
	int search();
	int issue();
	void dispduedate();
	void Return();
};
void Library::entry()
{
	cout<<"\nEnter the book ID:";
	cin>>bookid[index];
	cout<<"\nEnter the book title:";
	cin>>title[index];
	cout<<"\nEnter the author name:";
	cin>>author[index];
	cout<<"\nEnter the number of books:";
	cin>>qty[index];
	balance[index]=qty[index];
	cout<<"\nYou have entered the following details:";
	cout<<"\nTitle:"<<title[index];
	cout<<"\nAuthor:"<<author[index];
	cout<<"\nQuantity:"<<qty[index];
	cout<<"\nIssued:"<<issued[index];
	cout<<"\nBalance:"<<balance[index];
	index++;
}
int Library::search()
{
	int sid;
	cout<<"\nEnter the book ID of the book to be searched:";
	cin>>sid;
	for(int i=0;i<index;i++)
	{
		if(sid==bookid[i])
		{
			cout<<"\nBook found!!....Book details:";
			cout<<"\nTitle:"<<title[i];
			cout<<"\nAuthor:"<<author[i];
			cout<<"\nQuantity:"<<qty[i];
			cout<<"\nIssued:"<<issued[i];
			cout<<"\nBalance:"<<balance[i];
			return 0;
		}
	}
	cout<<"\nBook not found!!!";
	return 0;
}
int Library::issue()
{
	int temp;
	cout<<"\nEnter the book ID of the book to be issued:";
	cin>>temp;
	for(int i=0;i<index;i++)
	{
		if(temp==bookid[i])
		{
			if(balance[i]==0)
				cout<<"\nBook not available";
			else
			{
				int dd,mm,yy;
				issued[i]++;
				balance[i]--;
				cout<<"\nEnter the date of issue:";
				cout<<"\nDate:";
				cin>>dd;
				cout<<"\nMonth:";
				cin>>mm;
				cout<<"\nYear:";
				cin>>yy;
				due_dd[i]=dd+10;
				due_mm[i]=mm;
				due_yy[i]=yy;
				cout<<"\nBook issued:";
				return 0;
			}	
		}
	}
	cout<<"\nBook not found";
	return 0;
}
void Library::dispduedate()
{
	int d,m,y;
	cout<<"\nEnter today's date:";
	cout<<"\nDate:";
	cin>>d;
	cout<<"\nMonth:";
	cin>>m;
	cout<<"\nYear:";
	cin>>y;
	cout<<"\nThe books which have crossed the due date are:\n";
	for(int i=0;i<index;i++)
	{
		if(d>due_dd[i]||m>due_mm[i]||y>due_yy[i])
		{
			cout<<bookid[i]<<"\t"<<title[i]<<endl;
		}
	}
}
void Library::Return()
{
	int id;
	cout<<"\nEnter the book ID of the book to be returned:";
	cin>>id;
	for(int i=0;i<index;i++)
	{
		if(id==bookid[i])
		{
			issued[i]--;
			balance[i]++;
		}
	}
}
void Library::disp()
{
	char str[20];
	cout<<"\nEnter the title of the book to be searched:";
	cin>>str;
	for(int i=0;i<index;i++)
	{
		if(strcmp(str,title[i])==0)
		{
			cout<<"\nTitle:"<<title[i];
			cout<<"\nAuthor:"<<author[i];
			cout<<"\nQuantity:"<<qty[i];
			cout<<"\nIssued:"<<issued[i];
			cout<<"\nBalance:"<<balance[i];
		}
	}
}
int main()
{
	Library ob;
	int ch;
	
	while(1)
	{
		cout<<"\n1.Enter new book details\n2.Search a book\n3.Issue a book\n4.List due date books\n5.Return book\n6.Display all books on a given title\n7.Exit\nEnter your choice:";
		cin>>ch;
		switch(ch)
		{
			case 1:ob.entry();break;
			case 2:ob.search();break;
			case 3:ob.issue();break;
			case 4:ob.dispduedate();break;
			case 5:ob.Return();break;
			case 6:ob.disp();break;
			case 7:return 0;
			default:cout<<"\nEnter correct choice:";
		}
	}
	return 0;
}
			
	
	
	




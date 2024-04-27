


#include<iostream>
using namespace std;
class hash_table
{
	public:
	int key;
	long mob_no;
};
class hashing
{
	hash_table h[10];
	public:
		hashing()
		{
			for(int i=0;i<10;i++)
			{
				h[i].key=i;
				h[i].mob_no=-1;
			}
		}
	void insert(int probe_choice);
	int linear_probing(int collision_position);
	int quadratic_probing(int collision_position);
	void display();
};
void hashing::insert(int probe_choice)
{
	int temp,position;
	int collision_position,temp_position;
	cout<<"enter mobile number:";
	cin>>temp;
	position=temp%10;
	if(h[position].mob_no==-1)
	{
	 	h[position].mob_no=temp;
	  
	}
	else if(probe_choice==1)   		  //linear probing 
	{
		temp_position=linear_probing(position);
		h[temp_position].mob_no=temp;
	}
	else if(probe_choice==2)			//quadratic probing
	{
		int collision_position=position;
		int temp_position=quadratic_probing(collision_position);
		h[temp_position].mob_no=temp;
	}
}
int hashing::linear_probing(int position)
{
	int i;
	for(i=position;i<10;i++)
	{
		if(h[i].mob_no==-1)
		{
			return i;
		}
		if(i==9) 
		{
			i=-1;      						//i value 9 to 0
		}	
	}
}
int hashing::quadratic_probing(int collision_position)
{
	int position,temp,i;
	position=(h[temp].mob_no+i*i)%10;
	if(h[position].mob_no==-1)
	{
		h[position].mob_no=temp;
	}
}

void hashing::display()
{
	for(int i=0;i<10;i++)
	{
		cout<<h[i].key<<"\t"<<h[i].mob_no<<endl;
 	   
	}
}
int main()
{
	hashing h1;
	int ch,probe_choice;
	do
	{
	cout<<"*****Menu*****";
	cout<<"\n1.Insert a data.";
	cout<<"\n2.Display data.";
	cout<<"\n3.Exit.";
	cout<<"\nEnter a choice:";
	cin>>ch;
	switch(ch)
	{
		case 1:
		{
			cout<<"\n1.linear probing. \n2.Quadratic probing.";
			cout<<"\nEnter a choice:";
			cin>>probe_choice;
			h1.insert(probe_choice);
		}
		break;
	
		case 2:
			h1.display();
			break;
	
		case 3:
			cout<<"End of program......";
			break;
	
	}
	
	}while(ch!=4);
	return 0;
}



/

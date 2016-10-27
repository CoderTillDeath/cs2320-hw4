#include <iostream>
using namespace std;

struct Person {
	string name;
	Person * next;
};

Person * newPerson(string name)
{
	Person * p = new Person;
	p->name = name;
	p->next = NULL;
	return p;
}

struct People {
	Person * first;
	Person * last;
};

People * newPeople()
{
	People * p = new People;
	p->first = NULL;
	p->last = NULL;
	return p;
}

void insert(People * peo, Person * per)
{
	if(peo->first == NULL)
	{
		peo->first = per;
		peo->last = per;
	}
	else
	{
		peo->last->next = per;
		peo->last = per;
	}
}

struct Bus {
	People * people;
	int seatsLeft;
	int id;
	Bus * next;
};

Bus * newBus(int id, int seats)
{
	Bus * b = new Bus;
	b->people = newPeople();
	b->seatsLeft = seats;
	b->id = id;
	b->next = NULL;
}

void printBus(Bus * b)
{
	int num = b->id;
	
	for(Person * p = b->people->first; p; p = p->next)
	{
		cout << "bus" << num << "\t" << p->name << endl;
	}
}



struct Buses {
	Bus * front;
	Bus * back;
	int count;
	int seats;
};

Buses * newBuses(int seats)
{
	Buses * b = new Buses;
	b->front = NULL;
	b->back = NULL;
	b->count = 0;
	b->seats = seats;
	return b;
}

void insert(Buses * bs, Bus * b)
{
	if(bs->front == NULL)
	{
		bs->front = b;
		bs->back = b;
	}
	else
	{
		bs->back->next = b;
		bs->back = b;
	}
}

void insert(Buses * b, string name, int number)
{
	Bus * current = b->front;

	while(current)
	{
		if(current->seatsLeft >= number)
		{
			current->seatsLeft -= number;
			insert(current->people, newPerson(name));
		
			if(current->seatsLeft == 0)
			{
				printBus(current);
			}
			return;
		}
		current = current->next;
	}
	
	b->count++;
	Bus * newB = newBus(b->count, b->seats);
	newB->seatsLeft -= number;
	insert(newB->people, newPerson(name));
	insert(b,newB);
}

void printBuses(Buses * b)
{
	Bus * current = b->front;

	while(current)
	{
		if(current->seatsLeft > 0)
			printBus(current);
		current = current->next;
	}
}

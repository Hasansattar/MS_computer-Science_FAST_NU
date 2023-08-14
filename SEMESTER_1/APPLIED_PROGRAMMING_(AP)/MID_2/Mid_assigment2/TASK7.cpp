#include <iostream>
using namespace std;

struct Person
{
	int ID;
	string name;
	Person* next;
};

class BankSystem
{
private:
	Person* person;
	int limit, current_size;

	bool CanAddMore()
	{
		if (limit == -1 || limit == 0)
			return true;
		return (current_size != limit);
	}
	bool IsEmpty()
	{
		return current_size == 0;
	}
public:
	BankSystem()
	{
		person = NULL;
		limit = -1;
		current_size = 0;
	}

	void Insert(int ID, string name)
	{
		if (!CanAddMore())
		{
			cout << "queue is full..." << endl;
			return;
		}
		Person* p = new Person();
		p->ID = ID;
		p->name = name;
		p->next = NULL;

		if (person == NULL)
		{
			person = p;
		}
		else
		{
			Person* temp = person;
			//	p = 80->NULL
			//	temp = 10->20->30->40->50->60->70->NULL
			while (temp->next != NULL)
				temp = temp->next;
			//	temp = 70->NULL
			temp->next = p;
			//	temp = 70->80->NULL
		}
		if (limit != -1)
		{
			current_size++;
		}
	}

	Person* GetFirstPersonFromQueue()
	{
		return person;
	}

	void Serve()
	{
		//	0th-case: Do not do anything, if queue is empty
		if (IsEmpty())
		{
			cout << "queue is empty..." << endl;
			return;
		}
		//	1st-case: Get first person from queue
		Person* p = GetFirstPersonFromQueue();
		//	2nd-case: Perform some action
		cout << "Say; Cashier is serving person. " << p->ID << ", " << p->name << endl;
		//	3rd-case: Remove from queue

		//	person = 10->20->30->40->50->60->70->NULL, 20
		//	p = 10->20->30->40->50->60->70->NULL, 10
		person = person->next;
		p->next = NULL;
		delete p;

		if (limit != -1)
		{
			current_size--;
		}
	}

	void Display()
	{
		Person* p = person;
		while (p != NULL)
		{
			cout << "ID: " << p->ID << ", Name: " << p->name << endl;
			p = p->next;
		}
	}

	void SetLimit(int limit)
	{
		this->limit = limit;
	}
};

int main()
{
	BankSystem cashier;
	cashier.SetLimit(5);

	cashier.Serve();

	cashier.Insert(1, "Person-1");
	cashier.Insert(2, "Person-2");
	cashier.Insert(3, "Person-3");
	cashier.Insert(4, "Person-4");
	cashier.Insert(5, "Person-5");
	cashier.Insert(6, "Person-6" );
	cashier.Serve();

	cashier.Insert(6, "Person-6");
	cashier.Serve();
	cashier.Serve();
	cashier.Serve();
	cashier.Serve();
	cashier.Serve();

	cashier.Display();

	system("PAUSE");
	return 0;
}

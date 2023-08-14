#include <iostream>

using namespace std;

struct Node
{
	int ID, time;
	Node* next;
};

class ProcessControl
{
private:
	Node* head;
public:
	ProcessControl();
	void Insert(int ID, int time);
	void Delete(int ID);
	void DisplayTotalProcess();
	void Process(int Timeslice);
};

ProcessControl::ProcessControl()
{
	this->head = NULL;
}

void ProcessControl::Insert(int ID, int time)
{
	Node* node = new Node;
	node->ID = ID;
	node->time = time;
	if (head == NULL)
	{
		head = node;
		head->next = head;
	}
	else
	{
		Node* ptr = head;
		while (ptr->next != head)
		{
			ptr = ptr->next;
		}
		ptr->next = node;
		node->next = head;
	}
}

void ProcessControl::Delete(int ID)
{
	 
	if (head == NULL)
		return;

	
	if (head->ID == ID && head->next == head)
	{
		delete head;
		head = NULL;
		return;
	}

	 
	Node* last = head, *delete_node;
	if (head->ID == ID)
	{
	 
		while (last->next != head)
			last = last->next;

		 
		last->next = head->next;
		delete head;
		head = last->next;
		return;
	}

	while (last->next != head && last->next->ID != ID)
		last = last->next;

	if (last->next->ID == ID)
	{
		delete_node = last->next;
		last->next = delete_node->next;
		delete delete_node;
	}
	else
	{
		cout << "No Node Found...\n";
	}
}

void ProcessControl::DisplayTotalProcess()
{
	Node* ptr = head;
	cout << "Processes in Linked List: ";
	do
	{
		cout << ptr->ID << " ";
		ptr = ptr->next;
	} while (ptr != head);
}

void ProcessControl::Process(int Timeslice)
{
	int timetaken = 0;
	Node* ptr = head;
	bool flag = false;
	while (head != NULL)
	{
		flag = false;
		do
		{
			DisplayTotalProcess();
			if (ptr->time <= Timeslice && (ptr->time - Timeslice <= 0))
			{
				cout << "Process #" << ptr->ID << " executed for " << ptr->time << " seconds" << endl;
				timetaken += ptr->time;
				cout << "Process #" << ptr->ID << " has been executed. Time Taken: " << timetaken  << endl;
				Delete(ptr->ID);	//	 Delete Current Node...
				ptr = head;
				continue;
			} 
			else
			{
				cout << "Process #" << ptr->ID << " executed for " << Timeslice << " seconds" << endl;
				ptr->time -= Timeslice;
				timetaken += Timeslice;
			}
			
			ptr = ptr->next;
		} while (ptr != head);
	}
	cout << "Execution Completed" << endl;
}

int main()
{
	ProcessControl d_obj;

	int processes, time;
	cout << "Enter number of processes: ";
	cin >> processes;
	for (int i = 1; i <= processes; i++)
	{
		cout << "Enter Process #" << i << " Execution Time: ";
		cin >> time;
		d_obj.Insert(i, time);
	}
	int timeslice;
	cout << "Enter Time Slice: ";
	cin >> timeslice;

	d_obj.Process(timeslice);

	system("PAUSE");
	return 0;
}

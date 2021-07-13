#include<iostream>
#include<unordered_map>
using namespace std;

struct NODE
{
	int data;
	struct NODE* next;
};

NODE* CreateNode(int value)
{
	NODE* head = new NODE;
	head->next = NULL;
	head->data = value;
	return head;
}

NODE* AddElement(NODE* p, int value)
{
	NODE* temp = CreateNode(value); //head
	p->next = temp;
	return temp;
}

void removeDuplicates(NODE* head)
{
	NODE* p1, * p2, * dup;
	p1 = head;
	while (p1 != NULL && p1->next != NULL)
	{
		p2 = p1;

		while (p2->next != NULL)
		{
			if (p1->data == p2->next->data)
			{
				dup = p2->next;
				p2->next = p2->next->next;
				delete(dup);
			}
			else
				p2 = p2->next;
		}
		p1 = p1->next;
	}
}

void PrintList(NODE* head)
{
	NODE* p = head;
	while (p != NULL)
	{
		cout << p->data << " ";
		p = p->next;
	}
}

int main()
{

	int x;
	cin >> x;
	if (x == 0) cout << "Danh sach rong." << endl;
	else
	{
		NODE* l = CreateNode(x);
		NODE* p = l;
		while (x != 0)
		{
			cin >> x;
			p = AddElement(p, x);
		}
		p = l;
		while (p->next->next != NULL)
		{
			p = p->next;
		}
		delete(p->next);
		p->next = NULL;
		cout << "Danh sach vua nhap la: ";
		PrintList(l);
		p = l;
		cout << "\nSo lan xuat hien cua tung phan tu trong danh sach la: \n";
		unordered_map <int, int> mymap;
		p = l;
		while (p != NULL)
		{
			mymap[p->data]++;
			p = p->next;
		}
		removeDuplicates(l);
		p = l;
		while (p != NULL)
		{
			cout << p->data << ": " << mymap[p->data] << endl;
			p = p->next;
		}

	}
	return 0;
}
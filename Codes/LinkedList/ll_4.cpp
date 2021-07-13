#include<iostream>
using namespace std;

struct NODE
{
	int data;
	struct NODE* next;
};

bool CheckSNT(int val)
{
	if (val < 2)
		return false;
	for (int i = 2; i * i <= val; i++)
	{
		if (val % i == 0)
			return false;
	}
	return true;
}

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
		int count = 0, res = 0;
		while (p != NULL)
		{
			count++;
			if (count % 2 != 0 && CheckSNT(p->data))
			{
				res++;
			}
			p = p->next;
		}
		cout << "\nDanh sach co " << res << " so nguyen to o vi tri le." << endl;
	}
	return 0;
}
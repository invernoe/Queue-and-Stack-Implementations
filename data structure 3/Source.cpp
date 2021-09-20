#include <iostream>

using namespace std;
const int M = 10;

struct stack {
	int top = -1;
	int array[M] = {};
};

struct queue {
	int head = 0;
	int tail = 0;
	int array[M] = {};
};

bool stackEmpty(stack s) {
	if (s.top == -1)
		return true;
	else
		return false;
}

void push(stack &s, int x) {
	s.array[++s.top] = x;
}

int pop(stack &s) {
	if (stackEmpty(s))
		cout << "underflow error\n";
	else
		return s.array[s.top--];
}

void tailEnqueue(queue &q, int x) {
	q.array[q.tail] = x;
	if (q.tail == M - 1)
		q.tail = 0;
	else
		q.tail++;
}

int headDequeue(queue &q) {
	int x = q.array[q.head];
	if (q.head == M - 1)
		q.head = 0;
	else
		q.head++;
	return x;
}

int tailDequeue(queue &q) {
	int x;
	if (q.tail == 0) {
		q.tail = M - 1;
		x = q.array[q.tail];
	}
	else
		x = q.array[--q.tail];
	return x;
}

void headEnqueue(queue &q, int x) {
	if (q.head == 0) {
		q.head = M - 1;
		q.array[q.head] = x;
	}
	else
		q.array[--q.head] = x;
}

int main() {
	stack s;
	queue q;

	for (int i = 0; i < M; i++)
	{
		push(s, i * 3);
	}

	for (int i = 0; i < M; i++)
	{
		cout << s.array[i] << "\t";
	}
	cout << endl;

	for (int i = 0; i < 3; i++)
	{
		cout << "popped element number " << i+1 << " = " << pop(s) << endl;
	}
	cout << endl;
	push(s, 44);
	push(s, 20);
	push(s, 90);

	for (int i = 0; i < M; i++)
	{
		cout << s.array[i] << "\t";
	}
	cout << endl << "----------------------------------------" << endl;

	cout << "queue 9 elements from tail" << endl;
	for (int i = 0; i < M - 1; i++)
	{
		tailEnqueue(q, i * 5);
	}

	for (int i = 0; i < M; i++)
	{
		cout << q.array[i] << "\t";
	}
	cout << endl <<endl;

	for (int i = 0; i < 6; i++)
	{
		cout << "head dequed element number " << i + 1 << " = " << headDequeue(q) << endl;
	}
	cout << endl;

	cout << "queued 3 elements from tail" << endl;
	for (int i = 0; i < 3; i++)
	{
		tailEnqueue(q,3);
	}

	for (int i = 0; i < M; i++)
	{
		cout << q.array[i] << "\t";
	}
	cout << endl << endl;

	cout << "queued 2 elements from head" << endl;
	for (int i = 0; i < 2; i++)
	{
		headEnqueue(q, 0);
	}

	for (int i = 0; i < M; i++)
	{
		cout << q.array[i] << "\t";
	}
	cout << endl;

	for (int i = 0; i < 6; i++)
	{
		cout << "tail dequed element number " << i + 1 << " = " << tailDequeue(q) << endl;
	}
	cout << endl;

	system("pause");
	return 0;
}
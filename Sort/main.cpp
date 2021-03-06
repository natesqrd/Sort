#include <iostream>
#include "Sort.h"


using namespace std;

int main()
{
	Sort<int> s(20);
	
	cout << "Original: "; s.print();
	s.insertionSort();
	cout << "Insertion: " << s.sortCount() << endl;
	s.print();
	cout << endl;
	s.unsort();

	cout << "Original: "; s.print();
	s.selectionSort();
	cout << "Selection: " << s.sortCount() << endl;
	s.print();
	cout << endl;
	s.unsort();

	cout << "Original: "; s.print();
	s.shellSort();
	cout << "Shell: " << s.sortCount() << endl;
	s.print();
	cout << endl;
	s.unsort();

	cout << "Original: "; s.print();
	s.quickSort();
	cout << "Quick: " << s.sortCount() << endl;
	s.print();
	cout << endl;
	
	return 0;
}
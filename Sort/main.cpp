#include <iostream>
#include "Sort.h"
#include <random>

using namespace std;

int main()
{
	Sort s;
	cout << "Original: "; s.print();
	s.insertionSort();
	cout << "Insertion: " << s.sortCount() << endl;
	s.print();
	cout << endl;
	s.unsort(20, 0, 100);

	cout << "Original: "; s.print();
	s.selectionSort();
	cout << "Selection: " << s.sortCount() << endl;
	s.print();
	cout << endl;
	s.unsort(20, 0, 100);

	cout << "Original: "; s.print();
	s.shellSort();
	cout << "Shell: " << s.sortCount() << endl;
	s.print();
	cout << endl;
	s.unsort(20, 0, 100);
	



	return 0;
}
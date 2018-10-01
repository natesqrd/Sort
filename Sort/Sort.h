#pragma once
#include <ctime>
#include <random>
#include "Timer.h"


template<class T>
class Sort
{
	int ARRSIZE = 20;
	T *sortMe;
	int sortIteration = 0;
	void swap(T a[], int m, int k)
	{
		T tmp = a[m];
		a[m] = a[k];
		a[k] = tmp;
	}
	void quickSort(T a[], int left, int right, int sortIt)
	{
	///I was getting errors with the code in the lecture notes so I rewrote
	///the algorithm to work. What was happening is the i and j were
	///never able to leave the while loop and kept flipping only two numbers indefinantly
		int i = left, j = right;
		T k = a[(left + right) / 2];

		while (i <= j)
		{
			while (a[i] < k)
				i++;
			while (a[j] > k)
				j--;
			if (i <= j)
			{
				swap(a, i, j);
				i++;
				j--;
			}
			this->sortIteration++;
		}
		if (left < j)
			quickSort(a, left, j, this->sortIteration++);
		if (i < right)
			quickSort(a, i, right, this->sortIteration++);
		return;
	}
	void fillArray(int min, int max)
	{
		for (int i = 0; i < ARRSIZE; i++)
			this->sortMe[i] = static_cast<T>((((double)rand() / (double)RAND_MAX) * max - min) + min);
	}
public:
	Sort() :sortMe(new T[ARRSIZE]) { this->unsort(); }
	
	Sort(int size) :sortMe(new T[size]) { this->ARRSIZE = size; this->unsort(); }

	Sort(int size, int min, int max) :sortMe(new T[size]) { this->unsort(size, min, max); }

	Sort(T a[], int size) :sortMe(new T[size]) { this->setArray(a, size); }

	void setArray(T a[], int size)
	{
		this->ARRSIZE = size;
		for (int i = 0; i < ARRSIZE; i++)
			this->sortMe[i] = a[i];
	}
	int size() { return this->ARRSIZE; }

	int sortCount() { return sortIteration; }

	void unsort() { this->unsort(ARRSIZE, 10, 1000); }

	void unsort(int size, int min, int max)
	{
		srand(static_cast<int>(time(0)));
		this->ARRSIZE = size;
		this->fillArray(min, max);
	}

	void print()
	{
		for (int i = 0; i < this->ARRSIZE; i++)
		{
			std::cout << this->sortMe[i] << " ";
		}
		std::cout << std::endl;
	}

	void insertionSort()
	{
		this->sortIteration = 0;
		T hold = 0;
		int search = 0;

		timer t;
		for (int current = 1; current < this->size(); current++)
		{
			hold = this->sortMe[current];
			for (search = current - 1; search >= 0 && hold < this->sortMe[search]; search--)
			{
				this->sortMe[search + 1] = this->sortMe[search];
				this->sortIteration++;
			}
			this->sortMe[search + 1] = hold;
			this->sortIteration++;
		}
	}

	void selectionSort()
	{
		this->sortIteration = 0;
		int smallest = 0;
		T holdData;

		timer t;
		for (int current = 0; current < this->size(); current++)
		{
			smallest = current;
			for (int index = current + 1; index < this->size(); index++)
			{
				if (this->sortMe[index] < this->sortMe[smallest])
				{
					smallest = index;
				}
				this->sortIteration++;
			}
			holdData = this->sortMe[current];
			this->sortMe[current] = this->sortMe[smallest];
			this->sortMe[smallest] = holdData;
			this->sortIteration++;
		}
	}
	void quickSort()
	{
		timer t;
		this->quickSort(this->sortMe, 0, this->ARRSIZE - 1, this->sortIteration = 0);
	}
	
	void shellSort()
	{
		this->sortIteration = 0;
		T hold;
		int incre;
		int index;

		timer t;
		incre = this->size() / 2;
		while (incre != 0)
		{
			for (int curr = incre; curr < this->size(); curr++)
			{
				hold = this->sortMe[curr];
				index = curr - incre;
				while (index >= 0 && hold < this->sortMe[index])
				{
					//move larger element up in list
					this->sortMe[index + incre] = this->sortMe[index];
					//Fall back one partition
					index = (index - incre);
					sortIteration++;
				}

				//Insert hold in proper position
				this->sortMe[index + incre] = hold;
				sortIteration++;
			}

			//End of pass--calculate next incrementhis->
			incre = incre / 2;
			sortIteration++;
		}
	}
};
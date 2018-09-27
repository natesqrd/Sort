#pragma once
#include <iostream>
#include <iomanip>
#include <ctime>
#include "Timer.h"
#include <random>
#include <vector>

class Sort : public Timer
{
	int arrSize = 20;
	std::vector<int> sortMe;
	int sortIteration = 0;
	void swap(int list[], int m, int k)
	{
		int tmp = list[m];
		list[m] = list[k];
		list[k] = tmp;
	}
	int choosePivot(int i, int j)
	{
		return((i + j) / 2);
	}
	void merge(int a[], int low, int high, int mid)
	{
		int i, j, k, c[100];
		i = low;
		j = mid + 1;
		k = low;
		while ((i < mid) && (j < high))
		{
			if (a[i] < a[j])
			{
				c[k] = a[i];
				k++;
				i++;
			}
			else
			{
				c[k] = a[j];
				k++;
				j++;
			}
		}
		while (i < mid)
		{
			c[k] = a[j];
			k++;
			j++;
		}
		while (j < high)
		{
			c[k] = a[i];
			k++;
			j++;
		}
		for (i = low; i < k; i++)
		{
			a[i] = c[i];
		}
	}
	void fillArray(int min, int max)
	{
		for (int i = 0; i < this->size(); i++)
			this->sortMe.push_back(rand() % max + min);
	}
public:
	Sort()
	{
		this->unsort(arrSize, 0, 100);
	}

	Sort(int size, int min, int max)
	{
		this->unsort(size, min, max);
	}

	int size()
	{
		return this->arrSize;
	}

	int sortCount()
	{
		return sortIteration;
	}

	void unsort(int size, int min, int max)
	{
		srand(static_cast<int>(time(0)));
		this->sortMe.clear();
		this->arrSize = size;
		this->fillArray(min, max);
	}

	void print()
	{
		for (int i = 0; i < this->size(); i++)
		{
			std::cout << this->sortMe[i] << " ";
		}
		std::cout << std::endl;
	}

	void insertionSort()
	{
		this->sortIteration = 0;
		int hold = 0;
		int search = 0;

		this->startTimer();
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
		this->stopTimer();
	}

	void selectionSort()
	{
		this->sortIteration = 0;
		int smallest = 0;
		int holdData = 0;

		this->startTimer();
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
		this->stopTimer();
		return;
	}
	
	void quickSort(int list[], int m, int n, int sortIt = 0) //<+++++ Recursion
	{
		int key, i, j, k;
		if (m < n)
		{
			k = choosePivot(m, n);
			swap(list, m, k);
			key = list[m];
			i = m + 1;
			j = n;

			while (i <= j)
			{
				while ((i <= n) && (list[i] <= key))
					i++;
				while ((i >= m) && (list[j] <= key))
					j--;
				if (i < j)
					swap(list, i, j);
				sortIt++;
			}
			swap(list, m, j);

			//recursively sort the lesser list
			quickSort(list, m, j - 1, sortIt++);

			//recursively sort the greater list
			quickSort(list, j + 1, n, sortIt++);
		}
		return;
	}
	void shellSort()
	{
		this->sortIteration = 0;
		int hold;
		int incre;
		int index;

		this->startTimer();
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
		this->stopTimer();

		return;
	}
	int mergesort(int a[], int low, int high)//<+++++ Recursion
	{
		int mid;
		if (low < high)
		{
			mid = (low + high) / 2;
			mergesort(a, low, mid);
			mergesort(a, mid + 1, high);
			merge(a, low, high, mid);
		}
		return(0);
	}
};
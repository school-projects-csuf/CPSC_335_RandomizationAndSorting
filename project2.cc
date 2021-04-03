///////////////////////////////////////////////////////////////////////////////
// project2.hh
//
// The three algorithms specified in the project 1 requirements
// document, plus helper functions.
//
///////////////////////////////////////////////////////////////////////////////

#include "project2.hh"

#include <algorithm>
#include <cassert>
#include <cstdlib>
#include <ctime>
#include <fstream>
#include <string>
#include <vector>
#include <iostream>

using namespace std;


//-----------------------------------------------------------------------------
// Randomize the order of all items in the list
//-----------------------------------------------------------------------------
void randomize_list(string_vector & strings) {

	srand(time(0));
	int random_number;

	for (size_t i = 0; i < strings.size(); i++)
	{
		random_number = (rand() % strings.size());
		swap(strings[i], strings[random_number]);
	}

  return;
}

//-----------------------------------------------------------------------------
void merge(string_vector & strings, size_t start, size_t mid, size_t end) {
  
	size_t i = start;
	size_t j = mid + 1;
	string_vector temp;
	
	if (mid < end && strings[mid] <= strings[mid + 1]) {
		return;
	}
	
	while (i <= mid && j <= end) {
		if (strings[i] > strings[j]) {
			temp.push_back(strings[j++]);
		}
		else {
			temp.push_back(strings[i++]);
		}
	}

	while (i <= mid) {
		temp.push_back(strings[i++]);
	}

	while (j <= end) {
		temp.push_back(strings[j++]);
	}

	for (int i = 0; i < temp.size(); i++) {
		strings[start + i] = temp[i];
	}

	return;
}

//-----------------------------------------------------------------------------
// Sort the given list using the merge sort algorithm.
// This is a recursive method which splits the list into two
// parts, recursively calls itself on the two parts and then merges 
// the two parts together using the merge() method.
//-----------------------------------------------------------------------------
void mergesort(string_vector & strings, size_t start, size_t end) {

	//pick center then split left side and right side 
	size_t mid;

	if (start < end) {
		mid = (start + end) / 2;

		mergesort(strings, start, mid);
		mergesort(strings, mid + 1, end);

		merge(strings, start, mid, end);
	}
  return;
}

//-----------------------------------------------------------------------------
// Implementation of the Hoare Partition.
// This partition uses the first element of the list as a partition
// and divides the list into less than and greater than the pivot value
// It returns the index of the final position of the pivot value.
//-----------------------------------------------------------------------------
int hoare_partition(string_vector & strings, int start, int end) {

	int i = start;
	int j = end;

	string pivot = strings[start];

	while (i < j) {

		while (pivot < strings[j] && j > i) {
			j--;
		}

		swap(strings[i], strings[j]);

		while (pivot >= strings[i] && i < j) {
			i++;
		}
		swap(strings[j], strings[i]);
	}
	return i;

}

//-----------------------------------------------------------------------------
// Sort the given list using the quicksort algorithm.
// This is a recursive method which splits the list into two
// parts, recursively calls itself on the two parts and then merges 
// the two parts together using the merge() method.
//-----------------------------------------------------------------------------
void quicksort(string_vector & strings, int start, int end) {
  
	int pivot;
	if (start < end) {
		pivot = hoare_partition(strings, start, end);
		quicksort(strings, start, pivot - 1);
		quicksort(strings, pivot + 1, end);
	}
	return;
}


//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
// ALREADY IMPLEMENTED 
//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------

//-----------------------------------------------------------------------------
// Load words from the file at the given path. The words vector is
// cleared, and then each word from the file is added to the
// vector. Returns true on success or fale on I/O error.
//-----------------------------------------------------------------------------
bool load_words(string_vector& words, const std::string& path) 
{
  words.clear();

  std::ifstream ifs(path.c_str());

  if (!ifs.is_open() || !ifs.good()) {
  
    return false;

  }
  int countWordsLoaded = 0;
  while (!ifs.eof()) {

    std::string lineBuffer;

    std::getline(ifs, lineBuffer);

    if (ifs.eof()) {
      break;
    }
    words.push_back(lineBuffer);
    countWordsLoaded++;
  }

  return true;
}

//-----------------------------------------------------------------------------
// Sort the given list using the merge sort algorithm.
// This method is simply a helper to make the initial 
// call the recursive mergesort() method below that requires
// first and last indexes for sorting range
//-----------------------------------------------------------------------------
void mergesort(string_vector & strings) {
  if (strings.size() == 0) {
    return;
  }
  mergesort(strings, 0, strings.size() - 1);
  return;
}

//-----------------------------------------------------------------------------
// Sort the given list using the quicksort algorithm.
// This method is simply a helper to make the initial 
// call the recursive mergesort() method below that requires
// first and last indexes for sorting range
//-----------------------------------------------------------------------------
void quicksort(string_vector & strings) {
  if (strings.size() == 0) {
    return;
  }
  quicksort(strings, 0, strings.size() - 1);
  return;
}


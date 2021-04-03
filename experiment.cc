///////////////////////////////////////////////////////////////////////////////
// experiment.cc
//
// Example code showing how to run an algorithm once and measure its elapsed
// time precisely. You should modify this program to gather all of your
// experimental data.
//
///////////////////////////////////////////////////////////////////////////////

#include <iostream>

#include "project2.hh"
#include "timer.hh"
#include <vector>
#include <fstream>

using namespace std;

int main() {

  string_vector all_words;
  if ( ! load_words(all_words, "words.txt") ) {
    cerr << "error: cannot open \"words.txt\"" << endl;
    return 1;
  }

  //ofstream used to store data into a text file
  ofstream fout;
  fout.open("mergesortData.txt");

  int n = 99171;
  //for loop used to run the experiment 300 times
  for (size_t i = 0; i < 300; i++)
  {
		string_vector n_words(all_words.begin(), all_words.begin() + n);

		randomize_list(n_words);

		Timer timer;
		mergesort(n_words);
		/*quicksort(n_words);*/
		double elapsed = timer.elapsed();

		cout << "quicksort, "
			<< "n=" << n << ", "
			<< "elapsed time = " << elapsed << " seconds" << endl;
		fout << elapsed << endl;
  }
  


  return 0;
}




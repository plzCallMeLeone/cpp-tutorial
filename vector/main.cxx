#include <iostream>

using namespace std;
class vector {
  int sz;
  double* elem;
public:
  vector (int s)
    :sz{s}, elem{new double[s]}
  { for(auto i = 0; i < s; ++i) { elem[i] = 0; } }

  int size()const { return sz; }
  double get(unsigned n)const{ return elem[n]; }
  void set(unsigned n, double v) { elem[n] = v; }
  ~vector () { delete[] elem; }
};


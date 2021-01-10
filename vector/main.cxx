#include <initializer_list>
#include <iostream>
#include <assert.h>
#include <memory>
#include <stdexcept>

struct Range_error : std::out_of_range{
  int idx;
  Range_error(int i) : std::out_of_range("Range Error"), idx(i) { }
};

using namespace std;

template <typename T, int N>
struct array {
  T elem[N];

  T& operator[] (int n) { return elem[n]; }
  const T& operator[] (int n) const { return elem[n]; } 

  T& at(int n);
  const T& at(int n) const;

  T* data() { return elem; };
  const T* data() const { return elem; }

  int size() const { return N; }
};

template < typename T, typename A = allocator<T> >
class vector {
  A alloc;
  T* data;
  size_t sz;
  size_t cap;

public:

  vector()
    :sz{0}, cap{0}, data{nullptr} { }
  explicit vector(size_t sz); // simply zerofill every elements.
  vector(initializer_list<T> lst);

  vector(vector&& vec);
  vector& operator=(vector&& vec);
 // for move semantics

  vector(const vector& vec)            = delete; 
  vector& operator=(const vector& vec) = delete;
  // to avoid unnecessary copy

  T& operator[](size_t idx) { return data[idx]; } // bracket for accessing element
  T  operator[](size_t idx) const { return data[idx]; } // bracket for get element

  T& at(int n); // access element with bound checking
  const T& at(int n) const; // access element with bound checking

  size_t size() const { return sz; }
  size_t capacity() const { return cap; }

  void reserve(size_t alloc_size);
  void resize(size_t new_size, T def = T());
  void push_back(T elem); // push a elem at the end of the vector.

  ~vector(){ delete[] data; }
};


int main()
{
  vector<double> test;
  vector<int> test2;

  for(size_t i = 0; i < 20; ++i) {
    test.push_back(i);
  }
  for(size_t i = 0; i < test.size(); ++i) {
    cout << test[i] << ' ';
  }
  cout << "\n============\n";
  cout << "capacity: " << test.capacity() << " size: " << test.size() << '\n';

  for(size_t i = 0; i < 20; ++i) {
    test2.push_back(i);
  }
  for(size_t i = 0; i < test2.size(); ++i) {
    cout << test2[i] << ' ';
  }
  cout << "\n============\n";
  cout << "capacity: " << test2.capacity() << " size: " << test2.size() << '\n';
  try {
    test2.at(30);
  }
  catch (out_of_range& e) {
    cerr << e.what();
  }
}

template<typename T, typename A>
vector<T, A>::vector(size_t size)
  :sz{size}, cap{size}, data{new T[size]}
{
  for(size_t i = 0; i < sz; ++i) {
    data[i] = 0;
  }
}

template<typename T, typename A>
vector<T, A>::vector(initializer_list<T> lst)
  :sz{lst.size()}, cap{lst.size()}, data{new T[lst.size()]}
{
  auto it = lst.begin();
  for(size_t i = 0; i < lst.size(); ++i) {
    data[i] = *it;
    ++it;
  }
}

template<typename T, typename A>
void vector<T, A>::reserve(size_t alloc_size)
{
  if(alloc_size <= cap) { return; }

  cap = alloc_size;
  T* p = alloc.allocate(alloc_size);
  for(size_t i = 0; i < sz; ++i) {
    p[i] = data[i];
  }
  alloc.deallocate(data, cap);
  data = p;
}

template<typename T, typename A>
void vector<T, A>::resize(size_t new_size, T def)
{
  reserve(new_size);
  for(size_t i = 0; i < sz; ++i)        { alloc.construct(&data[i], def); }
  for(size_t i = sz; i < new_size; ++i) { alloc.destroy(&data[i]); }
  sz = new_size;
}

template<typename T, typename A>
void vector<T, A>::push_back(T elem)
{
  if(cap == 0) { reserve(8); }
  else if (cap == sz) { reserve (cap*2); }

  alloc.construct(&data[sz], elem);
  ++sz;
}
template<typename T, typename A>
vector<T, A>::vector(vector&& vec)
  :cap{vec.cap}, sz{vec.sz}, data{vec.data}
{
  vec.data = nullptr;
  vec.cap  = 0;
  vec.sz   = 0;
}

template<typename T, typename A>
vector<T, A>& vector<T, A>::operator=(vector&& vec)
{
  delete[] data;

  cap  = vec.cap;
  data = vec.data;
  sz   = vec.sz;

  vec.data = nullptr;
  vec.cap  = 0;
  vec.sz   = 0;
  return *this;
}

template<typename T, typename A>
T& vector<T, A>:: at(int n)
{
  if (n >= sz) { throw out_of_range("しし"); }
  return data[n];
}
template<typename T, typename A>
const T& vector<T, A>:: at(int n) const
{
  if (n >= sz) { throw out_of_range("しし"); }
  return data[n];
}

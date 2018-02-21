

int int_min = numeric_limits<int>::min();
int int_max = numeric_limits<int>::max();


// http://www.cplusplus.com/reference/cctype/
#include <ctype.h>

int isalpha(char ch);
int iscntrl(int ch);
int isdigit(char ch);
int isgraph(int ch);
int islower(int ch);
int isupper(int ch);
int tolower(int ch);
int toupper(int ch);
int isalnum(int ch);
int isprint(int ch);
int ispunct(int ch);
int isspace(int ch);
int isxdigit(int ch);
int isascii(int ch);


// std::find
template<class InputIterator, class T>
  InputIterator find (InputIterator first, InputIterator last, const T& val)
{
  while (first!=last) {
    if (*first==val) return first;
    ++first;
  }
  return last;
}

// std::reverse
template <class BidirectionalIterator>
  void reverse (BidirectionalIterator first, BidirectionalIterator last)
{
  while ((first!=last)&&(first!=--last)) {
    std::iter_swap (first,last);
    ++first;
  }
}

// std::accumulate
// Returns the result of accumulating all the values in the range [first,last) to init.
template< class InputIt, class T >
T accumulate( InputIt first, InputIt last, T init );
template< class InputIt, class T, class BinaryOperation >
T accumulate( InputIt first, InputIt last, T init,
              BinaryOperation op );

// std::lower_bound
// Returns an iterator pointing to the first element in the range [first,last) which does not compare less than val.
template <class ForwardIterator, class T>
  ForwardIterator lower_bound (ForwardIterator first, ForwardIterator last,
                               const T& val);
// Binary function that accepts two arguments (the first of the type pointed by ForwardIterator, and the second, always val), and returns a value convertible to bool. 
// The value returned indicates whether the first argument is considered to go before the second.
template <class ForwardIterator, class T, class Compare>
  ForwardIterator lower_bound (ForwardIterator first, ForwardIterator last,
                               const T& val, Compare comp);

// std::upper_bound
// Returns an iterator pointing to the first element in the range [first,last) which compares greater than val.
template <class ForwardIterator, class T>
  ForwardIterator upper_bound (ForwardIterator first, ForwardIterator last,
                               const T& val);
template <class ForwardIterator, class T, class Compare>
  ForwardIterator upper_bound (ForwardIterator first, ForwardIterator last,
                               const T& val, Compare comp);

// std::min_element
template <class ForwardIterator>
  ForwardIterator *min_element (ForwardIterator first, ForwardIterator last);
template <class ForwardIterator, class Compare>
  ForwardIterator *min_element (ForwardIterator first, ForwardIterator last,
                               Compare comp);

// std::max_element
template <class ForwardIterator>
  ForwardIterator *max_element (ForwardIterator first, ForwardIterator last);
template <class ForwardIterator, class Compare>
  ForwardIterator *max_element (ForwardIterator first, ForwardIterator last,
                               Compare comp);

// std::minmax_element
template <class ForwardIterator>
  pair<ForwardIterator,ForwardIterator>
    minmax_element (ForwardIterator first, ForwardIterator last);
template <class ForwardIterator, class Compare>
  pair<ForwardIterator,ForwardIterator>
    minmax_element (ForwardIterator first, ForwardIterator last, Compare comp);


// std::make_heap
// The element with the highest value is always pointed by first.
// The standard container adaptor priority_queue calls make_heap, push_heap and pop_heap automatically to maintain heap properties for a container.
template <class RandomAccessIterator>
  void make_heap (RandomAccessIterator first, RandomAccessIterator last);
template <class RandomAccessIterator, class Compare>
  void make_heap (RandomAccessIterator first, RandomAccessIterator last,
                  Compare comp );


// cmath头文件
// http://www.cplusplus.com/reference/cmath/.
// Returns the natural logarithm of x.
     double log (double x);
      float log (float x);
long double log (long double x);
     double log (T x);           // additional overloads for integral types
// Returns the binary (base-2) logarithm of x.
     double log2 (double x);
      float log2 (float x);
long double log2 (long double x);
     double log2 (T x);           // additional overloads for integral types
// Returns the common (base-10) logarithm of x.
     double log10 (double x);
      float log10 (float x);
long double log10 (long double x);
     double log10 (T x);           // additional overloads for integral types
// Returns base raised to the power exponent.
     double pow (double base     , double exponent);
      float pow (float base      , float exponent);
long double pow (long double base, long double exponent);
     double pow (Type1 base      , Type2 exponent);        // additional overloads
// Returns the square root of x.
     double sqrt (double x);
      float sqrt (float x);
long double sqrt (long double x);
     double sqrt (T x);           // additional overloads for integral types
// Returns the cubic root of x
     double cbrt (double x);
      float cbrt (float x);
long double cbrt (long double x);
     double cbrt (T x);           // additional overloads for integral types
// Rounds x upward, returning the smallest integral value that is not less than x.
     double ceil (double x);
      float ceil (float x);
long double ceil (long double x);
     double ceil (T x);           // additional overloads for integral types.
// Rounds x downward, returning the largest integral value that is not greater than x.
     double floor (double x);
      float floor (float x);
long double floor (long double x);
     double floor (T x);           // additional overloads for integral types
// Returns the absolute value of x: |x|
     double abs (double x);
      float abs (float x);
long double abs (long double x);
     double abs (T x);           // additional overloads for integral types


// std::string
// Iterators: begin end rbegin rend cbegin cend crbegin crend.
// Capacity: size length max_size resize capacity reserve clear empty shrink_to_fit.
// Element access: operator[] at back front
// Modifiers: operator+= append push_back assign insert erase replace swap pop_back.
// String operations: c_str data get_allocator copy find rfind find_first_of find_last_of find_first_not_of find_last_not_of substr compare.
// Member constants: npos: Maximum value for size_t.

/*
  Summary: represents substring in string api:
  string:       (const string& str) 
                (const string& str, size_t subpos, size_t sublen)
  c-string:     (const char* s)
                (const char* s, size_t n)
  n same char:  (size_t n, char c)
*/

// Extends the string by appending additional characters at the end of its current value.
string& append (const string& str);
string& append (const string& str, size_t subpos, size_t sublen);
string& append (const char* s);
string& append (const char* s, size_t n);
string& append (size_t n, char c);
template <class InputIterator>
   string& append (InputIterator first, InputIterator last);
string& append (initializer_list<char> il);

// Assigns a new value to the string, replacing its current contents.
string& assign (const string& str); 
string& assign (const string& str, size_t subpos, size_t sublen);
string& assign (const char* s);
string& assign (const char* s, size_t n);
string& assign (size_t n, char c);
template <class InputIterator>
   string& assign (InputIterator first, InputIterator last);
string& assign (initializer_list<char> il);
string& assign (string&& str) noexcept;

// Inserts additional characters into the string right before the character indicated by pos (or p).
// The signatures returning a reference to string, return *this.
// Those returning an iterator, return an iterator pointing to the first character inserted.
string& insert (size_t pos, const string& str);
string& insert (size_t pos, const string& str, size_t subpos, size_t sublen);
string& insert (size_t pos, const char* s);
string& insert (size_t pos, const char* s, size_t n);
string& insert (size_t pos,   size_t n, char c);
iterator insert (const_iterator p, size_t n, char c);
iterator insert (const_iterator p, char c);
template <class InputIterator>
iterator insert (iterator p, InputIterator first, InputIterator last);
string& insert (const_iterator p, initializer_list<char> il);

// Erase(index) 去掉index后面所有的   erase(index, index) 去掉区间的.
// Erases part of the string, reducing its length.
// The sequence version (1) returns *this.
// The others return an iterator referring to the character that now occupies the position of the first character erased, or string::end if no such character exists.
string& erase (size_t pos = 0, size_t len = npos);
iterator erase (const_iterator p);
iterator erase (const_iterator first, const_iterator last);

// Replaces the portion of the string that begins at character pos and spans len characters (or the part of the string in the range between [i1,i2)) by new contents.
string& replace (size_t pos,        size_t len,        const string& str);
string& replace (const_iterator i1, const_iterator i2, const string& str);
string& replace (size_t pos,        size_t len,        const string& str,
                 size_t subpos, size_t sublen);   
string& replace (size_t pos,        size_t len,        const char* s);
string& replace (const_iterator i1, const_iterator i2, const char* s);
string& replace (size_t pos,        size_t len,        const char* s, size_t n);
string& replace (const_iterator i1, const_iterator i2, const char* s, size_t n);
string& replace (size_t pos,        size_t len,        size_t n, char c);
string& replace (const_iterator i1, const_iterator i2, size_t n, char c);
template <class InputIterator>
  string& replace (const_iterator i1, const_iterator i2,
                   InputIterator first, InputIterator last);
string& replace (const_iterator i1, const_iterator i2, initializer_list<char> il);


// split a string
// http://www.cplusplus.com/faq/sequences/strings/split/

// ostringstream 对象用来进行格式化的输出，可以方便的将各种类型转换为string类型，只支持<<操作符
// istringstream 对象用来把一个已定字符串中的以空格隔开的内容提取出来，只支持>>操作符
// stringstream 是两者的结合

vector<string> split1(const string &s, string delim) {
    vector<string> res;
    size_t cur, next = -1;
    do {
        cur = next + 1;
        next = s.find_first_of(delim, cur);
        res.push_back(s.substr(cur, next-cur));
    } while (next != string::npos);
    return res;
}

vector<string> split2(const string &s, char delim) {  // 分割后，最后一个若为空，则不会加入到结果中
    vector<string> res;
    stringstream ss(s);		// 或者 ss.str(s);
    string item;
    while (!ss.eof()) {
        getline(ss, item, delim);
        res.push_back(item);
    }
    return res;
}

// trim a string
void trim(string &s) {
    s.erase(0, s.find_first_not_of(" "));
    s.erase(s.find_last_not_of(" ") + 1);
}


// string::find_first_of
// http://www.cplusplus.com/reference/string/string/find_first_of/
size_t find_first_of (const string& str, size_t pos = 0) const noexcept;  // string
size_t find_first_of (const char* s, size_t pos = 0) const;               // c-string
size_t find_first_of (const char* s, size_t pos, size_t n) const;         // buffer
size_t find_first_of (char c, size_t pos = 0) const noexcept;             // char

// Copies the values of num bytes from the location pointed to by source directly to the memory block pointed to by destination.
// The underlying type of the objects pointed to by both the source and destination pointers are irrelevant for this function; The result is a binary copy of the data.
// The function does not check for any terminating null character in source - it always copies exactly num bytes.
// To avoid overflows, the size of the arrays pointed to by both the destination and source parameters, shall be at least num bytes, and should not overlap (for overlapping memory blocks, memmove is a safer approach).
void * memcpy ( void * destination, const void * source, size_t num );

// Copies the C string pointed by source into the array pointed by destination, including the terminating null character (and stopping at that point).
// To avoid overflows, the size of the array pointed by destination shall be long enough to contain the same C string as source (including the terminating null character), and should not overlap in memory with source.
char * strcpy ( char * destination, const char * source );

// Sets the first num bytes of the block of memory pointed by ptr to the specified value (interpreted as an unsigned char).
void * memset ( void * ptr, int value, size_t num );

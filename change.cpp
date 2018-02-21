
// stringstream
#include <sstream>

void func(void) { 
	// std::istringstream
	istringstream istr("1 56.7");	//初始化
    cout <<istr.str() <<endl;		//str()成员函数返回字符串
    int a;
    float b;
	istr >>a;						//以空格为分界符
    cout <<a <<endl;
	istr >>b;
    cout <<b <<endl;

    stringstream sstr; 
	//--------int转string----------- 
	int a = 100;
	string str;
	sstr <<a;
	sstr >>str;
	cout <<str <<endl;
	//--------string转int----------- 
	sstr.clear();		// 如果你想通过使用同一stringstream对象实现多种类型的转换，请注意在每一次转换之后都必须调用clear()成员函数.
	string str("100");
	int a = 0;
	sstr <<str;
	sstr >>a;
	cout <<a <<endl;
	//--------string转char[]-------- 
	sstr.clear(); 
	string name = "colinguan";
	char cname[200];
	sstr <<name;
	sstr >>cname;
	cout <<cname;
	//--------string转longlong------ 
	sstr.clear();
	string str("100");
	long long ll;
	sstr <<str;
	sstr >>ll;
	cout <<ll;
}


int       stoi( const std::string& str, size_t *pos = 0, int base = 10 );
long      stol( const std::string& str, size_t *pos = 0, int base = 10 );
long long stoll( const std::string& str, size_t *pos = 0, int base = 10 );

float       stof( const std::string& str, size_t *pos = 0 );
double      stod( const std::string& str, size_t *pos = 0 );
long double stold( const std::string& str, size_t *pos = 0 );

int       atoi( const char *str );
long      atol( const char *str )
long long atoll( const char *str );

std::string to_string( int value );
std::string to_string( long value );
std::string to_string( long long value );
std::string to_string( unsigned value );
std::string to_string( unsigned long value );
std::string to_string( unsigned long long value );
std::string to_string( float value );
std::string to_string( double value );
std::string to_string( long double value );

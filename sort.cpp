//使用外部定义的比较函数
//如果在类中定义，需要变成静态成员函数，即前面加入static
bool complare(int a, int b) {
	return a > b;		//从大到小
}

sort(v.begin(), v.end(), complare);		//在这里就不需要对complare函数传入参数了

//使用标准库的比较函数
less<数据类型>()//从小到大排序
greater<数据类型>()//从大到小排序

sort(v.begin(), v.end(),less<int>());	//这里要有括号

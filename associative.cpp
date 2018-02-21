//pair 类型
pair<T1, T2> p1;
pair<T1, T2> p1(v1, v2);
make_pair(v1, v2);
p1 < p2
p1.first
p1.second

//map
//构造函数
map<k, v> m;
map<k, v> m1(m2);
map<k, v> m(b, e);
//map类定义的类型
map<k, v>::key_value k;
map<k, v>::mapped_value v;
map<k, v>::value_type kv;

//赋值
map<string, int> word_cout;
word_count["Love"] = 1;
++word_count["Love"];	//返回左值

//map的insert
m.insert(e);	//e是value_type的值，存在则不会插入，返回一个pair值，第一个是迭代器，第二个是bool，表示是否插入
m.insert(b, e);
m.insert(iter, e);

word_count.insert(map<string, int>::value_type("Yu", 1));
word_count.insert(make_pair("Yu", 1));

//map查询
m.count(k);
m.find(k);	//返回迭代器，查不到返回末端迭代器

//map删除
m.erase(k);	//返回删除个数
m.erase(p);	//p为迭代器
m.erase(b, e);


//set
//set不支持下标操作符
//set的插入只用insert，返回值和map相同
//set查找与map相同，用count和find

//multimap和multiset
//multimap不支持下标运算
//元素的添加：insert总会添加一个元素
//元素的删除：带一个键的erase将删除拥有该键的所有元素,并返回删除元素的个数。而带有一个或一对迭代器参数只删除指定的元素,并返回void类型
//查找元素：同一键所关联的元素必须相邻存放，find返回第一个元素的迭代器
m.lower_bound(k);	//返回一个迭代器,指向键不小于k的第一个元素
m.upper_bound(k);	//返回一个迭代器,指向键大于k的第一个元素
//如果该键不在multimap中,这两个操作将返回同一个迭代器,指向依据元素的排列顺序该键应该插入的位置。
m.equal_range(k);	//返回一个迭代器的pair对象







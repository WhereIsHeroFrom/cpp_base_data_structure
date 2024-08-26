#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <cstring>
using namespace std;

class String {
private:
    // 字符串长度
    size_t length;
    // 动态分配的字符串内存空间
    char* str;

public:
    // 构造函数，初始化字符串为空
    String();
    // 构造函数，初始化字符串为给定的字符串副本
    String(const char* s);
    // 拷贝构造函数
    String(const String& s);
    // 析构函数，释放动态分配的字符串内存空间
    ~String();
    // 获取字符串长度的函数
    size_t getLength() const;
    // 访问字符串中指定索引位置的字符的函数
    char operator[](size_t index) const;
    // 重载赋值运算符，将字符串赋值给当前字符串
    String& operator=(const String& s);
    // 重载等于运算符，比较两个字符串是否相等
    bool operator==(const String& s) const;
    // 重载不等于运算符，比较两个字符串是否不相等
    bool operator!=(const String& s) const;
    // 字符串拷贝函数
    String copy() const;
    // 字符串拼接函数
    String operator+(const String& s) const;

    friend ostream& operator<<(ostream& out, const String& s);
};



String::String() {
    length = 0;
    str = new char[1];
    str[0] = '\0';
}

String::String(const char* s) {
    length = strlen(s);
    str = new char[length + 1];
    strcpy(str, s);
}

String::String(const String& s) {
    length = s.length;
    str = new char[length + 1];
    strcpy(str, s.str);
}

String::~String() {
    delete[] str;
}

size_t String::getLength() const {
    return length;
}

char String::operator[](size_t index) const {
    return str[index];
}

String& String::operator=(const String& s) {
    if (this != &s) {
        delete[] str;
        length = s.length;
        str = new char[length + 1];
        strcpy(str, s.str);
    }
    return *this;
}

bool String::operator==(const String& s) const {
    return strcmp(str, s.str) == 0;
}

bool String::operator!=(const String& s) const {
    return strcmp(str, s.str) != 0;
}

String String::copy() const {
    String s = *this;
    return s;
}

String String::operator+(const String& s) const {
    String result;
    result.length = length + s.length;
    result.str = new char[result.length + 1];
    strcpy(result.str, str);
    strcat(result.str, s.str);
    return result;
}

ostream& operator<<(ostream& out, const String& s) {
    out << s.str;
    return out;
}

int main() {
    String s("12345d");
    cout << s << endl;
    cout << s + "445" << endl;
    cout << s[5] << endl;
    cout << (s == "12345d") << endl;
    cout << (s != "12345d") << endl;
    s = s + "asd";
    String a, b, c;
    a = b = c = s;
    cout << s << endl;
    cout << a << b << c << s << endl;
    String x = s.copy();
    cout << x << endl;


    return 0;
}
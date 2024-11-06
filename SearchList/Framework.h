#pragma once

#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <cassert>

using namespace std;

template <typename type>
ostream& operator<<(ostream& os, std::vector<type> container)
{
    os << "[ ";
    int count{ 0 };
    for (auto& x : container)
        if (!count++)
            os << x;
        else
            os << ", " << x;
    os << " ]";
    return os;
}

template <typename type, typename type2>
ostream& operator<<(ostream& os, std::map<type, type2> container)
{
    os << "{ ";
    int count{ 0 };
    for (auto& x : container)
        if (!count++)
            os << x.first() << ": " << x.second();
        else
            os << ", " << x.first() << ": " << x.second();
    os << " }";
    return os;
}

template <typename type>
ostream& operator<<(ostream& os, std::set<type> container)
{
    os << "{ ";
    int count{ 0 };
    for (auto& x : container)
        if (!count++)
            os << x;
        else {
            os << ", " << x;
        }
    os << " }";
    return os;
}

template <typename T, typename U>
void AssertEqualImpl(const T& t, const U& u, const string& t_str, const string& u_str, const string& file,
    const string& func, unsigned line, const string& hint) {
    if (t != u) {
        cerr << boolalpha;
        cerr << file << "("s << line << "): "s << func << ": "s;
        cerr << "ASSERT_EQUAL("s << t_str << ", "s << u_str << ") failed: "s;
        cerr << t << " != "s << u << "."s;
        if (!hint.empty()) {
            cerr << " Hint: "s << hint;
        }
        cerr << endl;
        abort();
    }
}

template <typename T>
void AssertEqual(const T& t, const string& t_str, const string& file,
    const string& func, unsigned line, const string& hint) {
    if (t != true) {
        cerr << boolalpha;
        cerr << file << "("s << line << "): "s << func << ": "s;
        cerr << "ASSERT("s << t_str << ") failed: "s;
        cerr << t << " != true"s;
        if (!hint.empty()) {
            cerr << " Hint: "s << hint;
        }
        cerr << endl;
        abort();
    }
}

vector<int> TakeEvens(const vector<int>& numbers) {
    vector<int> evens;
    for (int x : numbers) {
        if (x % 3 == 0) {
            evens.push_back(x);
        }
    }
    return evens;
}

vector<int> TakePositives(const vector<int>& numbers) {
    vector<int> positives;
    for (int x : numbers) {
        if (x > 0) {
            positives.push_back(x);
        }
    }
    return positives;
}

int Sum(int a, int b) {

    return a + b;
}

#define ASSERT_EQUAL(a, b) AssertEqualImpl((a), (b), #a, #b, "__FILE__", __FUNCTION__, __LINE__, ""s)

#define ASSERT_EQUAL_HINT(a, b, hint) AssertEqualImpl((a), (b), #a, #b, "__FILE__" , __FUNCTION__, __LINE__, (hint))

#define ASSERT(a) AssertEqual((a), #a, "__FILE__" , __FUNCTION__, __LINE__, ""s)

#define ASSERT_HINT(a, hint) AssertEqual((a), #a, "__FILE__" , __FUNCTION__, __LINE__, (hint))

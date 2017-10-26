/**
 * <h1>DataValue</h1>
 *
 * <p>A generic data value.</p>
 *
 * <p>Copyright (c) 2017 by Ronald Mak</p>
 * <p>For instructional purposes only.  No warranties.</p>
 */
#ifndef DATAVALUE_H_
#define DATAVALUE_H_

#include <iostream>
#include <string>

namespace wci {

using namespace std;

/**
 * Data value type.
 */
enum class ValueType
{
    INTEGER, FLOAT, CHAR, BOOLEAN, STRING, COMPLEX,
};

constexpr ValueType INTEGER = ValueType::INTEGER;
constexpr ValueType FLOAT = ValueType::FLOAT;
constexpr ValueType CHAR = ValueType::CHAR;
constexpr ValueType BOOLEAN = ValueType::BOOLEAN;
constexpr ValueType STRING = ValueType::STRING;
constexpr ValueType COMPLEX = ValueType::COMPLEX;

/**
 * Generic data value.
 */
class DataValue
{
public:
    ValueType type;
    union
    {
        int i;
        float f;
        char c;
        bool b;
        string s;
        double complex[2];
    };

    DataValue()              : type((ValueType) -1) {};
    DataValue(const int i)   : type(ValueType::INTEGER), i(i) {}
    DataValue(const float f) : type(ValueType::FLOAT),   f(f) {}
    DataValue(const char c)  : type(ValueType::CHAR),    c(c) {}
    DataValue(const bool b)  : type(ValueType::BOOLEAN), b(b) {}

    DataValue(const string s) : type(ValueType::STRING)
    {
        new (&this->s) string(s);
    }

    DataValue(const double cmplx[2]) : type(ValueType::COMPLEX) {
        complex[0] = cmplx[0];
        complex[1] = cmplx[1];
    }

    DataValue(const DataValue& orig)
    {
        this->type = orig.type;

        switch (orig.type)
        {
            case ValueType::INTEGER: this->i = orig.i; break;
            case ValueType::FLOAT:   this->f = orig.f; break;
            case ValueType::CHAR:    this->c = orig.c; break;
            case ValueType::BOOLEAN: this->b = orig.b; break;
            case ValueType::STRING:  new (&this->s) string(orig.s); break;
            case ValueType::COMPLEX:
                this->complex[0] = orig.complex[0];
                this->complex[1] = orig.complex[1];
                break;
        }
	}

    ~DataValue() {}

    string display() const
    {
        switch (type)
        {
            case ValueType::INTEGER: return to_string(this->i);
            case ValueType::FLOAT:   return to_string(this->f);
            case ValueType::CHAR:    return string(1, this->c);
            case ValueType::BOOLEAN: return to_string(this->b);
            case ValueType::STRING:  return this->s;
            case ValueType::COMPLEX: return
                        to_string(this->complex[0]),to_string(this->complex[1]);
            default: return "";
        }
    }
};

}  // namespace wci

#endif /* DATAVALUE_H_ */

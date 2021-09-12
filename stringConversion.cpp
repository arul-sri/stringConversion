#include <iostream>
#include <sstream>
#include <string>

/*
Write a templated function, named "all_convert", that takes a const reference to a string and a pointer to an int. This 
function should convert the string to the templated type and return that. It should also adjust the int being pointed 
to to indicate the number of characters of the string that were converted (be sure to count leading whitespace too).

You can assume that the string does not have any newline characters, and your function should ignore leading whitespace 
(like stoi does).
*/

template <typename T>
T all_convert(std::string &str, int *pos)
{
    T result;
    //If the template type is of integer
    if constexpr (std::is_same<T, int>::value)
    {
        result = stoi(str);
        *pos = (std::to_string(result).length());
    }
    else if constexpr (std::is_same<T, float>::value)
    {
        result = static_cast<float>(stof(str));
        *pos = (std::to_string(result).length());
    }
    else if constexpr (std::is_same<T, double>::value)
    {
        result = static_cast<double>(stod(str));
        *pos = (std::to_string(result).length());
    }
    else if constexpr (std::is_same<T, std::string>::value)
    {
        result = str;
        *pos = str.length();
    }

    return result;
}

int main()
{
    int length = 99;
    std::string str = "   -67.34x";
    auto D = all_convert<double>(str, &length);
    std::cout << "The value of D is: " << D << std::endl;
    std::cout << "The length of D is: " << length << std::endl;
}

// template <typename T>
// T AllConvert (const string &str , int *length)
// {
// istringstream ss(str);
// T num;
// ss >> num;
// ostringstream str1;
// str1 << num;
// string s = str1.str();
// *length = s.length();
// return num;
// }

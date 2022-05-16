#ifndef SPLITSTRING_STRINGLIB_SPLIT_STRING_H
#define SPLITSTRING_STRINGLIB_SPLIT_STRING_H
#include <algorithm>
#include <chrono>
#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <string_view>
#include <vector>

using namespace std::literals;

inline const std::string LoremIpsumStrv{"Lorem ipsum dolor sit amet, consectetur adipiscing elit, "
                                        "sed do eiusmod tempor incididuntsuperlongwordsuper ut labore et dolore magna aliqua. Ut enim ad minim veniam, "
                                        "quis nostrud exercitation ullamco laboris nisi ut aliquipsuperlongword ex ea commodo consequat. Duis aute "
                                        "irure dolor in reprehenderit in voluptate velit esse cillum dolore eu fugiat nulla pariatur. "
                                        "Excepteur sint occaecat cupidatatsuperlongword non proident, sunt in culpa qui officia deserunt mollit anim id est laborum."};

// uses string::find_first_of
std::vector<std::string>
split(const std::string &str, const std::string &delims = " ");

// uses std::find_first_of
std::vector<std::string>
splitStd(const std::string &str, const std::string &delims = " ");

// strings, but works on pointers rather than iterators
// code by JFT
std::vector<std::string> splitPtr(const std::string &str, const std::string &delims = " ");

// uses string_view::find_first_of
std::vector<std::string_view>
splitSV(std::string_view strv, std::string_view delims = " ");

// uses std::find_first_of rather than string_view::find_first_of
std::vector<std::string_view>
splitSVStd(std::string_view strv, std::string_view delims = " ");

// based on the JFT's comment:
std::vector<std::string_view> splitSVPtr(std::string_view str, std::string_view delims = " ");

#endif//SPLITSTRING_STRINGLIB_SPLIT_STRING_H

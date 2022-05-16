#include "split_string.h"

// uses string::find_first_of
std::vector<std::string>
split(const std::string &str, const std::string &delims) {
  std::vector<std::string> output;
  //output.reserve(str.length() / 4);
  size_t first = 0;

  while (first < str.size()) {
    const auto second = str.find_first_of(delims, first);

    if (first != second) {
      output.emplace_back(str.data() + first, str.data() + (second == std::string::npos ? str.size() : second));
    }

    if (second == std::string::npos)
      break;

    first = second + 1;
  }

  return output;
}
// uses std::find_first_of
std::vector<std::string>
splitStd(const std::string &str, const std::string &delims) {
  std::vector<std::string> output;
  //output.reserve(str.length() / 4);
  auto first = std::cbegin(str);

  while (first != std::cend(str)) {
    const auto second = std::find_first_of(first, std::cend(str),
                                           std::cbegin(delims), std::cend(delims));
    if (first != second) {
      output.emplace_back(first, second);
    }

    if (second == std::cend(str))
      break;

    first = std::next(second);
  }

  return output;
}

// strings, but works on pointers rather than iterators
// code by JFT
std::vector<std::string> splitPtr(const std::string &str, const std::string &delims) {
  std::vector<std::string> output;
  //output.reserve(str.size() / 2);

  for (auto first = str.data(), second = str.data(), last = first + str.size(); second != last && first != last; first = second + 1) {
    second = std::find_first_of(first, last, std::cbegin(delims), std::cend(delims));

    if (first != second)
      output.emplace_back(first, second);
  }

  return output;
}

// uses string_view::find_first_of
std::vector<std::string_view>
splitSV(std::string_view strv, std::string_view delims) {
  std::vector<std::string_view> output;

  size_t first = 0;

  while (first < strv.size()) {
    const auto second = strv.find_first_of(delims, first);
    if (first != second) {
      output.emplace_back(strv.substr(first, second - first));
    }

    if (second == std::string_view::npos)
      break;

    first = second + 1;
  }

  return output;
}

// uses std::find_first_of rather than string_view::find_first_of
std::vector<std::string_view>
splitSVStd(std::string_view strv, std::string_view delims) {
  std::vector<std::string_view> output;

  auto first = strv.begin();

  while (first != strv.end()) {
    const auto second = std::find_first_of(first, std::cend(strv),
                                           std::cbegin(delims), std::cend(delims));
    if (first != second) {
      output.emplace_back(strv.substr(std::distance(strv.begin(), first), std::distance(first, second)));
    }

    if (second == strv.end())
      break;

    first = std::next(second);
  }

  return output;
}

// based on the JFT's comment:
std::vector<std::string_view> splitSVPtr(std::string_view str, std::string_view delims) {
  std::vector<std::string_view> output;

  for (auto first = str.data(), second = str.data(), last = first + str.size(); second != last && first != last; first = second + 1) {
    second = std::find_first_of(first, last, std::cbegin(delims), std::cend(delims));

    if (first != second)
      output.emplace_back(first, second - first);
  }

  return output;
}
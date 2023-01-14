#include "random_string.hpp"
#include <random>

using namespace Crails;
using namespace std;

static const string_view default_random_charset =
  "abcdefghijklmnopqrstuvwxyz"
  "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
  "0123456789,.;:!?&%$#()[]{}+-";

namespace Crails
{
  string generate_random_string(unsigned short length)
  {
    return generate_random_string(default_random_charset, length);
  }

  string generate_random_string(const char* charset, unsigned short length)
  {
    return generate_random_string(string_view(charset), length);
  }

  string generate_random_string(const string& charset, unsigned short length)
  {
    return generate_random_string(string_view(charset.c_str(), charset.length()), length);
  }

  string generate_random_string(const string_view charset, unsigned short length)
  {
    string result;
    std::random_device rd;
    std::mt19937 generator(rd());
    std::uniform_int_distribution<> index_dist(0, charset.size() - 1);

    result.reserve(length);
    for (unsigned short i = 0 ; i < length ; ++i)
      result += charset[index_dist(generator)];
    return result;
  }
}

#include <crails/utils/random_string.hpp>

#undef NDEBUG
#include <cassert>

int main()
{
  using namespace std;

  // Produces the right amount of characters
  assert(Crails::generate_random_string(12).length() == 12);

  // Uses the specified charset
  {
    string result = Crails::generate_random_string("~", 12);
    for (int i = 0 ; i != 12 ; ++i)
      assert(result[i] == '~');
  }

  return 0;
}

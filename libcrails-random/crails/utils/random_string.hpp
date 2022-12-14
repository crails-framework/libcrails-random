#ifndef  CRAILS_RANDOM_STRING_HPP
# define CRAILS_RANDOM_STRING_HPP

# include <string>

namespace Crails
{
  std::string generate_random_string(unsigned short length);
  std::string generate_random_string(const std::string& charset, unsigned short length);
}

#endif

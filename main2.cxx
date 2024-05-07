#include <locale.h>
#ifdef __APPLE__
#include <xlocale.h>
#endif
#include <iostream>


int main(int, const char* [])
{
  locale_t new_locale;
  new_locale = newlocale (LC_NUMERIC_MASK, "fr_FR.utf-8", NULL);
  std::cout << "newlocale="<<newlocale<<std::endl;
  
  locale_t old_locale = uselocale(new_locale);
  std::cout << "old_locale="<<old_locale<<std::endl;

  char szOrbits[] = "365,24 29,53";
  double v = strtod (szOrbits, NULL);
  std::cout << "v="<<v<<std::endl;
  
  uselocale(old_locale);
  freelocale(new_locale);

  return 0;
}
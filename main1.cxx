#include <locale.h>
#ifdef __APPLE__
#include <xlocale.h>
#endif
#include <iostream>


int main(int, const char* [])
{
#if defined(_WIN32)
  const char * test_locale = setlocale(LC_NUMERIC, "fra_FRA.1252");
#else
  const char * test_locale = setlocale(LC_NUMERIC, "fr_FR.utf-8");
#endif
  if (test_locale)
  {
    std::cout << "test_locale="<<test_locale<<std::endl<<std::flush;
    char szOrbits[] = "365,24 29,53";
    double v = strtod (szOrbits, NULL);
    std::cout << "v="<<v<<std::endl<<std::flush;
  }
  else
    std::cout << "!test_locale"<<std::endl<<std::flush;
  return 0;
}

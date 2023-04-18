#if !defined (_CUTILS_H_)
#define _CUTILS_H_

#include <string>

namespace utils
{
  class CUtils
  {
  public:
    static int CrearMenu(const char *opciones_menu[], int num_opciones);
    static bool LeerDato(int& dato);
    static bool LeerDato(double& dato);
    static bool LeerDato(char *dato, int n);
    static bool LeerDato(std::string& dato);
    static char* ConverMayus(char* str);
    static std::string& ConverMayus(std::string& str);
  };
};

#endif // _CUTILS_H_
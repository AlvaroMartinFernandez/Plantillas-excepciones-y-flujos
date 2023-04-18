#include <iostream>
#include <limits>
#include <iomanip>
#include "utils.h"
using namespace std;
using namespace utils;

int CUtils::CrearMenu(const char *opciones_menu[], int num_opciones)
{
  int i = 0, opcion = 0;
  cout << endl;
  for(i = 0; i < num_opciones; i++)
  {
    cout << setw(3) << i+1 << "." << opciones_menu[i] << endl; // escribe: a5 ". " << opciones_menu[i] << endl;
  }

  do
  {
    cout << endl << "\tElija una opcion: " ;
    LeerDato(opcion);
    cout << endl;
  }
  while(opcion < 1 || opcion > num_opciones);
  return opcion;
}

bool CUtils::LeerDato(int& dato)
{
  // Habilitar excepciones
  cin.exceptions(ios::failbit | ios::badbit);
  try
  {
    cin >> dato;
    // Eliminar caracteres sobrantes. Por ejemplo <Entrar>.
    cin.ignore(numeric_limits<int>::max(), '\n');
    // deshabilitar excepciones
    cin.exceptions(ios::goodbit);
    return true;
  }
  catch(ios_base::failure& e)
  {
    if (cin.eof())
    {
      cin.clear();
      return false; // se pulsó Ctrl+Z
    }
    else
    {
      cout << e.what() << ": dato no válido\n";
      cin.clear();
      cin.ignore(numeric_limits<int>::max(), '\n');
      return LeerDato(dato);
    }
  }
}

bool CUtils::LeerDato(double& dato)
{
  cin.exceptions(ios::failbit | ios::badbit);
  try
  {
    cin >> dato;
    // Eliminar caracteres sobrantes. Por ejemplo <Entrar>.
    cin.ignore(numeric_limits<int>::max(), '\n');
    cin.exceptions(ios::goodbit);
    return true;
  }
  catch(ios_base::failure& e)
  {
    if (cin.eof())
    {
      cin.clear();
      return false; // se pulsó Ctrl+Z
    }
    else
    {
      cout << e.what() << ": dato no válido\n";
      cin.clear();
      cin.ignore(numeric_limits<int>::max(), '\n');
      return LeerDato(dato);
    }
  }
}

bool CUtils::LeerDato(char *dato, int n)
{
  cin.exceptions(ios::failbit | ios::badbit);
  try
  {
    cin.getline(dato, n, '\n');
    cin.exceptions(ios::goodbit);
    return true;
  }
  catch(ios_base::failure& e)
  {
    if (cin.eof())
    {
      cin.clear();
      return false; // se pulsó Ctrl+Z
    }
    else
    {
      cout << e.what() << ": dato no válido\n";
      cin.clear();
      cin.ignore(numeric_limits<int>::max(), '\n');
      return LeerDato(dato, n);
    }
  }
}

bool CUtils::LeerDato(string& dato)
{
  cin.exceptions(ios::failbit | ios::badbit);
  try
  {
    getline(cin, dato);
    cin.exceptions(ios::goodbit);
    return true;
  }
  catch(ios_base::failure& e)
  {
    if (cin.eof())
    {
      cin.clear();
      return false; // se pulsó Ctrl+Z
    }
    else
    {
      cout << e.what() << ": dato no válido\n";
      cin.clear();
      cin.ignore(numeric_limits<int>::max(), '\n');
      return LeerDato(dato);
    }
  }
}

char* CUtils::ConverMayus(char* str)
{
  if (str == NULL) return 0;
  for (int i = 0; i < strlen(str); i++)
    str[i] = toupper(str[i]);
  return str;
}

string& CUtils::ConverMayus(string& str)
{
  for (int i = 0; i < str.size(); i++)
    //str.at(i) = toupper(str.at(i)); // o bien:
    str[i] = toupper(str[i]);
  return str;
}

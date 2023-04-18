#include "CCliente.h"
#include <iostream>
using namespace std;
//Contructor copia
CCliente::CCliente(const string& Nom, const CContrato& c) : m_Nombre(Nom)
{
    m_Contratos.insert(m_Contratos.begin() + m_Contratos.size(), c);
}
// PREGUNTA 6: AgregarContrato de CCliente
void CCliente::AgregarContrato(const CContrato& c)
{
    m_Contratos.insert(m_Contratos.begin() + m_Contratos.size(), c);
}


// PREGUNTA 3: operator<< (cout << unCliente)
ostream& operator<<(ostream& os, CCliente& cli)
{
	os << "Nombre del cliente: " << cli.GetNombre() << endl;
	for (int i = 0; i < cli.m_Contratos.size(); i++)
	{
		os << cli.m_Contratos[i];
	}
	return os;
}


// PREGUNTA 7: total += seguros[i]
CCliente::operator int()
{
return m_Contratos.size();
}

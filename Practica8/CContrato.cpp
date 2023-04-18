#include "CContrato.h"
//#include "MemoryManager.h"
using namespace std;

CContrato::CContrato(int NumSerie, const string& Desc, const string& FF, long Poliza, long ValorCompra)
  : m_NumSerie(NumSerie), m_Descripcion(Desc),
  m_FechaFin(FF), m_Poliza(Poliza), m_ValorCompra(ValorCompra)
{
    m_Siniestros.clear();
}

// PREGUNTA 1: constructor copia de la clase CContrato
CContrato::CContrato(const CContrato &c)
{
    *this = c;
    cout << endl << "Constructor copia de CContrato ejecutado con exito." << endl;
}
// PREGUNTA 1: operador = de CContrato
CContrato& CContrato::operator=(const CContrato &c)
{
    if (this != &c)
    {
        for (int i = 0; i < c.m_Siniestros.size(); i++)
        {
             m_Siniestros.push_back(unique_ptr<CSiniestro>(c.m_Siniestros[i]->Clonar()));   
        }
        SetDescripcion(c.GetDescripcion());
        SetFechaFin(c.GetFechaFin());
        SetNumSerie(c.GetNumSerie());
        SetPoliza(c.GetPoliza());
        SetValorCom(c.GetValorCom());
        return *this;
    }
    else
        return *this;
}


// PREGUNTA 2: AgregarSiniestro de la clase CContrato
void CContrato::AgregarSiniestro(const CSiniestro& s)
{
    int tam = 0;
    tam = m_Siniestros.size();
    m_Siniestros.push_back(unique_ptr<CSiniestro>(s.Clonar()));
}


void CContrato::BorrarSiniestros()
{
  if (!m_Siniestros.empty())
  {
    m_Siniestros.clear(); // eliminar los elementos del vector
  }
}


void CContrato::MostrarSiniestros(ostream& os)
{
    for(int i=0; i< m_Siniestros.size(); i++)
            m_Siniestros[i]->Mostrar(os);
}


// Necesaria para PREGUNTA 3
ostream& operator<<(ostream& os, CContrato& c)
{
    cout << "Descripcion del producto: " << c.GetDescripcion() << endl;
    cout << "Fecha fin de contrato: " << c.GetFechaFin() << endl;
    cout << "Numero Serie: " << c.GetNumSerie() << endl;
    cout << "Poliza del seguro: " << c.GetPoliza() << endl;
    cout << "Valor del electrodomestico: " << c.GetValorCom() << endl;
    c.MostrarSiniestros();
    return os;
}

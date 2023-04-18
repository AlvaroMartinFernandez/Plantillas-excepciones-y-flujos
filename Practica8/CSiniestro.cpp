#include "CSiniestro.h"
using namespace std;
//CSiniestroNormal s("Rotura de tambor")
// PREGUNTA 4: iniciar m_SigCodigo

int CSiniestro::m_SigCodigo = 1;

CSiniestro::CSiniestro(const std::string& Desc)
  : m_Descripcion(Desc)
{
    m_Codigo = m_SigCodigo;
    m_SigCodigo++;
    m_HorasMO = 0;
    m_CostePiezas = 0;
    m_Coste = 0;
}



// PREGUNTA 9: GetCoste
void CSiniestro::Mostrar(ostream &os) const
{
    os << " Codigo del siniestro: " << m_Codigo << endl
        << " Descripcion de la averia: " << m_Descripcion << endl
        << " Horas de mano de obra: " << m_HorasMO << endl
        << " Coste de las piezas: " << m_CostePiezas << endl
        << " Coste total de reparacion: " << m_Coste << endl;
}

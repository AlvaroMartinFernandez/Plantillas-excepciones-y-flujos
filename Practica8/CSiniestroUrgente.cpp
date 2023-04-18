#include "CSiniestroUrgente.h"

using namespace std;

float CSiniestroUrgente::m_Recargo = 5;
float CSiniestroUrgente::m_CosteHoraMO = 3.5;

CSiniestroUrgente::CSiniestroUrgente(TSituacion s, const string& Desc)
  : CSiniestro(Desc), m_Situacion(s)
{

}

CSiniestroUrgente* CSiniestroUrgente::Clonar() const
{
  return new CSiniestroUrgente(*this);
}

void CSiniestroUrgente::Mostrar(ostream &os) const
{
  CSiniestro::Mostrar(os);
  os << " Tipo de cobertura: " << m_Situacion << endl
    << " Recargo por urgencia: " << m_Recargo << endl
    << " Coste hora de mano de obra: " << m_CosteHoraMO << endl;
}

// PREGUNTA 5
void CSiniestroUrgente::Presupuestar(float Horas, float Piezas)
{
    m_HorasMO = Horas;
    m_CostePiezas = Piezas;
    m_Coste = m_CosteHoraMO * m_HorasMO + m_CostePiezas + m_Recargo;
}

float CSiniestroUrgente::GetPresupuesto() const
{
  return m_Coste;
}

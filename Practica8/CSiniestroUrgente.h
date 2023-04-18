#if !defined(_SINIESTROURGENTE_H)
#define _SINIESTROURGENTE_H

#include "CSiniestro.h"

enum TSituacion
{
  local, nacional, internacional
};

class CSiniestroUrgente : public CSiniestro
{
private:
  TSituacion m_Situacion;
  static float m_Recargo;
  static float m_CosteHoraMO;

public:
  CSiniestroUrgente(TSituacion s = TSituacion::local, const std::string& Desc = "Sin Descripcion");

  void Presupuestar(float Horas = 0.5f, float Piezas = 0);
  void Mostrar(std::ostream & os = std::cout) const;
  CSiniestroUrgente* Clonar() const;
  float GetPresupuesto() const;
};

#endif
#if !defined(_SINIESTRONORMAL_H)
#define _SINIESTRONORMAL_H

#include "CSiniestro.h"

class CSiniestroNormal : public CSiniestro
{
private:
  static float m_CosteHoraMO;
public:
  CSiniestroNormal (const std::string& Desc = "Sin Descripcion");
  void Presupuestar(float Horas = 0.5f, float Piezas = 0);
  void Mostrar(std::ostream& os = std::cout) const;
  CSiniestroNormal* Clonar() const;
  float GetPresupuesto() const;
};

#endif
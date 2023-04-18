#if !defined(_SINIESTRO_H)
#define _SINIESTRO_H

#include <iostream>
#include <string>

class CSiniestro
{
private:
  int m_Codigo;
  static int m_SigCodigo;
protected:
  std::string m_Descripcion;
  float m_HorasMO;
  float m_CostePiezas;
  float m_Coste; // PREGUNTA 7
public:
  CSiniestro(const std::string& Desc = "Sin Descripcion");
  virtual ~CSiniestro() {};

  virtual float GetPresupuesto() const = 0;
  int GetCodigo() const { return m_Codigo; }
  float GetCoste() const { return m_Coste; } // PREGUNTA 7
  virtual void Presupuestar(float Horas, float Piezas) = 0;
  virtual void Mostrar(std::ostream& os = std::cout) const; // PREGUNTA 12
  virtual CSiniestro* Clonar() const = 0;
};

#endif

#include <fstream>
#include "CContrato.h"
#include "CSiniestroUrgente.h"
#include "CSiniestroNormal.h"
#include "CCliente.h"
#include "utils.h"
#include "CEmpresa.h"

using namespace std;
using namespace utils;

const int MAX_CLIENTES=10;

int main()
{
  {
    const char * OpMenu[]={"Constructor copia de CContrato.",
                     "AgregarSiniestro() de CContrato.",
                     "Operador << CCliente.",
                     "m_pSigCodigo static.",
                     "Presupuestar() de CSiniestro y derivadas",
                     "AgregarContrato() de CCliente",
                     "total += seguros[i]",
                     "Constructor CSiniestro y CSiniestroNormal",
                     "GetCoste()?",
                     "c.AgregarSiniestro()",
                     "Plantilla CEmpresa.",
                     "Guardar empresa.",
                     "Salir."
                    };
    const int numopciones = sizeof(OpMenu)/sizeof(char *);
    int opcion=0;

    do
    {
      opcion = CUtils::CrearMenu(OpMenu,numopciones);
      switch(opcion)
      {
      case 1: // Pregunta 1
        {
          // Crear e iniciar objeto CContrato a copiar
          CContrato original(12345,"Prueba constructor copia","11-01-21",123456789,987654321);
          // Rellenar objeto original
          TSituacion situacion = TSituacion::local;
          original.AgregarSiniestro(CSiniestroUrgente(local,"siniestro 1"));
          original.AgregarSiniestro(CSiniestroNormal("siniestro 2"));
          original.AgregarSiniestro(CSiniestroNormal("siniestro 3"));

          CContrato copia(original);
          original = copia;
          cout << "\n Constructor copia de CContrato ejecutado con exito." << endl << endl;
          cout << " CONTRATO ORIGINAL: " << endl << endl << original << endl
               << " CONTRATO COPIA: " << endl << endl << copia << endl;
          system("pause");
          break;
        }
      case 2:
        {
          CContrato prueba(12345);
          cout << "\n Creado un objeto CContrato prueba sin siniestros." << endl;
          prueba.AgregarSiniestro(CSiniestroUrgente(local,"siniestro 1"));  // Agregar siniestro 1
          cout << "\n Agregado siniestro 1 (urgente) a prueba: " << endl << endl;
          prueba.MostrarSiniestros();
          prueba.AgregarSiniestro(CSiniestroNormal("siniestro 2"));		  // Agregar siniestro 2
          cout << "\n Agregado siniestro 2 (normal) a prueba: " << endl << endl;
          prueba.MostrarSiniestros();
          cout << endl;
          cout << "\n Añadir respuesta" << endl;
          system("pause");
          break;
        }
      case 3:
        {
          // Crear cliente
          CCliente cli("Juan");
          // Rellenar datos
          CContrato con(12345, "Contrato 1 de Juan", "12-11-08", 1234567, 23000);
          con.AgregarSiniestro(CSiniestroUrgente(nacional,"Siniestro 1"));
          con.AgregarSiniestro(CSiniestroNormal("Siniestro 2"));
          cli.AgregarContrato(con);
          // Mostrar datos
          cout << "Datos del cliente:\n" << endl << cli << endl;
          system("pause");
          operator<<(operator<<(cout, "Datos del cliente: \n").operator<<(endl), cli).operator<<(endl);
          cout << endl << "Llamada explícita:\n"
               << "operator<<(operator<<(cout, \"Datos del cliente: \\n\").operator<<(endl), cli).operator<<(endl);" << endl;
          system("pause");
          break;
        }
      case 4:
        {
          cout << "\n Añadir respuesta" << endl;
          system("pause");
          break;
        }
      case 5:
        {
          CSiniestroUrgente MiSiniestroUrgente(internacional,"Siniestro Urgente Ejemplo");
          MiSiniestroUrgente.Presupuestar(7,3);
          CSiniestroNormal MiSiniestroNormal("Siniestro Normal Ejemplo");
          MiSiniestroNormal.Presupuestar(9,4);

          cout << "\n Ejemplo funcion Presupuestar de CSiniestro: " << endl << endl
            << " Presupuesto de Siniestro Urgente Ejemplo: " << MiSiniestroUrgente.GetPresupuesto() << endl << endl
            << " Presupuesto de Siniestro Normal Ejemplo: " << MiSiniestroNormal.GetPresupuesto() << endl << endl;
          
          cout << "Respuestas a las preguntas: ..." << endl;
          system("pause");
          break;
        }
      case 6:
        {
          // Crear cliente
          CCliente cli("Juan");
          // Rellenar datos
          CContrato con(12345, "Contrato 1 de Juan", "12-11-08", 1234567, 23000);
          con.AgregarSiniestro(CSiniestroUrgente(nacional,"Siniestro 1"));
          con.AgregarSiniestro(CSiniestroNormal("Siniestro 2"));
          cli.AgregarContrato(con);
          // Mostrar datos
          cout << " Datos del cliente: \n" << endl << cli << endl;
          system("pause");
          break;
        }
      case 7:
        {
          // Crear matriz dinamica
          vector<unique_ptr<CCliente>> seguros(0);

          // Rellenar matriz dinamica (El cliente i tiene i+1 contratos)
          for (int i = 0; i < MAX_CLIENTES; i++)
          {
              seguros.push_back(unique_ptr<CCliente>(new CCliente));
              for (int j = 0; j < (i + 1); j++)
                  seguros[i]->AgregarContrato(CContrato(j + 1));
          }
          // Contar numero total de contratos
          long total = 0;
          for(int i=0; i < MAX_CLIENTES; i++)
            total += *seguros[i]; // No implementar operator+=
          cout << "\n El numero total de contratos de los clientes asciende a: ";
          cout << total << " contratos\n";
          system("pause");
          //for(int i=0; i<seguros.size(); i++)
          //      delete seguros[i];
          break;
        }
      case 8:
        {
          CSiniestroNormal s("Rotura de tambor");
          cout << endl;
          s.Mostrar(); cout << endl;
          cout << "Respuestas a las preguntas: ...\n";
          system("pause");
          break;
        }
      
      case 9:
        {
          cout << "\nRespuestas a las preguntas: ..." << endl;
          system("pause");
          break;
        }
      case 10:
        {
          CContrato c(12345, "Cafetera C1Z","2/1/2002", 100, 1000);
          CSiniestroUrgente s(nacional, "Fallo general");
          c.AgregarSiniestro(s);
          // PREGUNTA 10
          cout << "\n Funciones que son llamadas: \n" << endl
            << "Respuestas a las preguntas : ..." << endl;
          system("pause");
          break;
        }
      case 11:
        {
          // Crear empresa
          CEmpresa<CCliente> empresa1;
          // Rellenar empresa
          empresa1.AgregarElemento(CCliente("Cliente 1"));
          empresa1.AgregarElemento(CCliente("Cliente 2"));
          empresa1.AgregarElemento(CCliente("Cliente 3"));
          // Copiar empresa
          CEmpresa<CCliente> empresa2(empresa1);
          // Mostrar empresa
          cout << "\n CLIENTES DE LA EMPRESA: \n" << endl;
          for(int i=0; i<empresa2.Tamanyo(); i++)
            cout << empresa2[i];
          cout << endl;
          system("pause");
          break;
        }
      case 12:
        {
          // Crear empresa
          CEmpresa<CCliente> empresa1;
          // Añadir clientes a la empresa
          empresa1.AgregarElemento(CCliente("Cliente 1"));
          empresa1.AgregarElemento(CCliente("Cliente 2"));
          empresa1.AgregarElemento(CCliente("Cliente 3"));
          // Guardar los nombres en un fichero (escribir)
          //Añadir el código que falta
          system("pause");
          break;
        }
      }
    }
    while(opcion < numopciones);
  }
  
}

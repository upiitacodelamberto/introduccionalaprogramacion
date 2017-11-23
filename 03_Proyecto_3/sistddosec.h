/**
 * sistddosec.h - Sistema de dos ecuaciones
 */
 #ifndef SISTDDOSEC_H
 #define SISTDDOSEC_H
 struct sistddosec{
   int M;          /* num. de ecuaciones */
   int N;          /** num. de variabes */
   float **MA;     /* Matriz Aumentada del sistema */
 };
 /**
  * inicializar sistema de ecuaciones.
  */
 struct sistddosec *inic_sis(float ma[2][],int numDEcs,int numDVars);
 void print_sistddosec(struct sistddosec *struct_sisddosecPt);
 void mostrar_sist_decs(float ma[2][3],int numDEcs,int numDVars);
 #endif /* SISTDDOSEC_H */

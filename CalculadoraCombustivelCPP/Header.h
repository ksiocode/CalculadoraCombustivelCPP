#pragma once
#include <iostream>
#include <iomanip>
#include <cmath>  
#include <locale>
#include "ElementosCalc.h"


using namespace std;


enum opc_menu_principal
{
	opc_exit,
	opc_qnt_combust,
	opc_consumo_kml,
	opc_distanc,
	opc_reaiskms
};

int clear_screen();
void MostraMenuPrincipal();
void MenuQntCombust();
void MenuKMlFeito();
void MenuDistancia();
void MenuReaisDist();
void MenuCalculaCusto(ElementsCalc* elements);



float CalcCusto(float *litros, float *preco);
float LitrosGastos(float *a, float *c);
float CalcKMl(float *a, float *c);
float DistanciaPercor(float *a, float *c);
float QuantosListrosCompra(float *a, float *c);
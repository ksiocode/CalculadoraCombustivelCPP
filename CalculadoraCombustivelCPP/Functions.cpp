#include "Header.h"



float CalcKMl(float *a, float *c)
{   //Calculo Kilometros por Litro, onde a � "a" Distancia Percorrida e "c" � os Litros gastos 
    return (*a / *c);
}


float CalcCusto(float *litros, float *preco)
{   //Calculo qual pre�o ir� gastar para fazer a viagem 
    return (*litros * *preco);
}

float LitrosGastos(float * a, float * c)
{   //Calculo Litros por Litro, onde a � "a" Distancia Percorrida e "c" � os Litros gastos 
    return (*a / *c);
}


float DistanciaPercor(float *a, float *c)
{   //Calculo Kilometros Percorrido a cada 1 Litro, onde a � "a" Consumo KM/l e "c" � os Litros gastos 
    return (*c * *a);
}


float QuantosListrosCompra(float *a, float *c)
{   //Calculo Quantos Litros seu Dinheiro compra onde a � "a" Gasto e "c" � o Pre�o do Litro 
    return (*a / *c);
}
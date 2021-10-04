#include "Header.h"



float CalcKMl(float *a, float *c)
{   //Calculo Kilometros por Litro, onde a é "a" Distancia Percorrida e "c" é os Litros gastos 
    return (*a / *c);
}


float CalcCusto(float *litros, float *preco)
{   //Calculo qual preço irá gastar para fazer a viagem 
    return (*litros * *preco);
}

float LitrosGastos(float * a, float * c)
{   //Calculo Litros por Litro, onde a é "a" Distancia Percorrida e "c" é os Litros gastos 
    return (*a / *c);
}


float DistanciaPercor(float *a, float *c)
{   //Calculo Kilometros Percorrido a cada 1 Litro, onde a é "a" Consumo KM/l e "c" é os Litros gastos 
    return (*c * *a);
}


float QuantosListrosCompra(float *a, float *c)
{   //Calculo Quantos Litros seu Dinheiro compra onde a é "a" Gasto e "c" é o Preço do Litro 
    return (*a / *c);
}
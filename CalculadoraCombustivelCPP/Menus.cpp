#include "Header.h"



void MostraMenuPrincipal()
{
	cout << "### Calculadora de Consumo de Combust�vel ###" << endl;
	cout << endl;
	cout << "Digite o N�mero da Opc�o abaixo do que Deseja Fazer" << endl;
	cout << opc_qnt_combust << " - Calcular a Quantidade Combust�vel (Litros) que ir� gastar" << endl;
	cout << opc_consumo_kml << " - Calcular o Consumo em Km/l que o carro ir� fazer" << endl;
	cout << opc_distanc << " - Calcular a Dist�ncia que o Carro pode Percorrer com Determinado Valor de Combust�vel" << endl;
	cout << opc_reaiskms << " - Calcular quantos KMs Kilometros de distancia � possivel fazer com o Dinheiro em R$ " << endl;
	cout << endl;
	cout << "Digite o N�mero da Opc�o ou 0 para sair: ";

	int opc = 0;
	cin >> opc;
	clear_screen();

	switch (opc)
	{
	case opc_qnt_combust:
		MenuQntCombust();
		break;
	case opc_consumo_kml:
		MenuKMlFeito();
		break;
	case opc_distanc:
		MenuDistancia();
		break;
	case opc_reaiskms:
		MenuReaisDist();
		break;
	case opc_exit:
		exit(EXIT_SUCCESS);
		break;
	default:
		break;
	}
}


void MenuQntCombust()
{
	ElementsCalc * calc = new ElementsCalc;

	cout << endl;
	cout << "Digite a Distancia em KM que � percorrida: ";
	cin >> calc->DistancKM;
	cout << "Digite o Consumo M�dio em Km/l do seu Carro: ";
	cin >> calc->ConsuKMlit;
	cout << endl;
	calc->LitrosCombus = CalcKMl(&calc->DistancKM, &calc->ConsuKMlit);

	cout << "Ser� consumido " << setprecision(2) << fixed << calc->LitrosCombus << " Litros" << endl;
	MenuCalculaCusto(calc);
	delete calc;

	cout << endl << "Fazer outro Calculo? (Digite Sim ou N�o): ";
	char opt_continue[4];
	cin >> opt_continue;
	if (opt_continue[0] == 'S' || opt_continue[0] == 's')
	{
		clear_screen();
		MostraMenuPrincipal();
	}
	
}

void MenuCalculaCusto(ElementsCalc *elements)
{
	cout << endl;
	cout << "Deseja saber qual seria o Gasto em R$? (Sim ou N�o irei sair): ";
	char opt_custo[4];
	elements->PrecoLitro = 1.0f;
	cin >> opt_custo;
	if (opt_custo[0] == 'S' || opt_custo[0] == 's')
	{
		cout << "Digite o Pre�o em R$ do Combustivel Ex: 5.79, Digite o Pre�o: ";
		cin >> elements->PrecoLitro;
		if (elements->PrecoLitro == 0 && elements->DistancKM > 0 && elements->ConsuKMlit > 0)
			elements->LitrosCombus = CalcKMl(&elements->DistancKM, &elements->ConsuKMlit);

		elements->Gastos = CalcCusto(&elements->LitrosCombus, &elements->PrecoLitro);

		cout << endl;
		cout << "Voc� ir� gastar R$" << setprecision(2) << fixed << elements->Gastos << " reais. ";
	}
}


void MenuKMlFeito()
{
	ElementsCalc* calc = new ElementsCalc;

	cout << endl;
	cout << "Digite a Distancia em KM que � percorrida: ";
	cin >> calc->DistancKM;
	cout << "Digite quantos Litros � Gasto para fazer a viagem: ";
	cin >> calc->LitrosCombus;

	calc->ConsuKMlit = CalcKMl(&calc->DistancKM, &calc->LitrosCombus);

	cout << endl;
	cout << "O Seu ve�culo fez " << setprecision(2) << fixed << calc->ConsuKMlit << " KM/l Kilometros por Litro" << endl;
	MenuCalculaCusto(calc);
	delete calc;

	cout << endl << "Fazer outro Calculo? (Digite Sim ou N�o): ";
	char opt_continue[4];
	cin >> opt_continue;
	if (opt_continue[0] == 'S' || opt_continue[0] == 's')
	{
		clear_screen();
		MostraMenuPrincipal();
	}
}


void MenuDistancia()
{
	ElementsCalc* calc = new ElementsCalc;

	cout << endl;
	cout << "Digite quantos KM/l Kilometros por Litro seu carro Consome em M�dia: ";
	cin >> calc->ConsuKMlit;
	cout << "Digite quantos Litros � Gasto para fazer a viagem: ";
	cin >> calc->LitrosCombus;

	calc->DistancKM = DistanciaPercor(&calc->ConsuKMlit, &calc->LitrosCombus);

	cout << endl;
	cout << "� poss�vel percorrer " << setprecision(2) << fixed << calc->DistancKM << " KM Kilometros com " << calc->LitrosCombus << "Litros de Combustivel" << endl;
	MenuCalculaCusto(calc);
	delete calc;

	cout << endl << "Fazer outro Calculo? (Digite Sim ou N�o): ";
	char opt_continue[4];
	cin >> opt_continue;
	if (opt_continue[0] == 'S' || opt_continue[0] == 's')
	{
		clear_screen();
		MostraMenuPrincipal();
	}
}


void MenuReaisDist()
{
	ElementsCalc* calc = new ElementsCalc;

	cout << endl;
	cout << "Digite quantos R$ reais voc� prentende Gastar: ";
	cin >> calc->Gastos;
	cout << "Digite o Pre�o em R$ reais do Litro de Combustivel: ";
	cin >> calc->PrecoLitro;
	cout << "Digite quantos KM/l Kilometros por Litro seu carro Consome em M�dia: ";
	cin >> calc->ConsuKMlit;

	calc->LitrosCombus = QuantosListrosCompra(&calc->Gastos, &calc->PrecoLitro);
	calc->DistancKM = DistanciaPercor(&calc->ConsuKMlit, &calc->LitrosCombus);

	cout << endl;
	cout << "� poss�vel percorrer " << setprecision(2) << fixed << calc->DistancKM << " KM Kilometros com " << calc->LitrosCombus << " Litros de Combustivel" << endl;
	delete calc;

	cout << endl << "Fazer outro Calculo? (Digite Sim ou N�o): ";
	char opt_continue[4];
	cin >> opt_continue;
	if (opt_continue[0] == 'S' || opt_continue[0] == 's')
	{
		clear_screen();
		MostraMenuPrincipal();
	}
}
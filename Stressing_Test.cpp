/* Stressing Test */

#include <iostream>

#include "polygon.h"
#include "IsoTriangle.h"
#include "rhombus.h"
#include "rectangle.h"

#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <string.h>

// definizione parametri per il test

#define D1 4
#define D2 5
#define L1 7
#define L2 8
#define B1 10
#define H 12


int main() 

{

	/*--------------------------------------------Rectangle---------------------------------------------------*/

	Rectangle rectA(10, 5);		// definizione di oggetti rettangolo
	Rectangle rectB = rectA;	// testing costruttore di copia
	Rectangle rectC, rectD;		// creazione oggetti per default

	if (rectC = rectB)			// testing overloading operatore '='
	{
		cout << "I due rettangoli sono uguali" << endl;
	}
	else
	{
		cout << "I due rettangoli NON sono uguali" << endl;
	}

	rectD.SetDim(0, 1);

	rectD.SetDim(1);			// passaggio di un solo parametro alla SetDim

	/*--------------------------------------------Rhombus-----------------------------------------------------*/

	Rhombus RhombusW(5, 6);		// creazione oggetto rombo per costruttore normale

	Rhombus RhombusT(RhombusW);	// creazione oggetto rombo per costruttore per copia

	RhombusT.Dump();			// lancio la Dump del rombo T che ha assunto per copia i valori del rombo W

	int d1 = D1;					// definizione diagonali
	int d2 = D2;
	int area = 0;

	area = (D1 * D2) / 2;

	Rhombus RhombusK(D1, D2);	// creazione oggetto rombo per costruttore normale

	if (area == RhombusK.Area())	// testing funzione area
	{
		cout << "Le aree sono uguali" << endl;
	}
	else
	{
		cout << "Le aree NON sono uguali" << endl;
	}
	/*--------------------------------------------IsoTriangle--------------------------------------------------*/

	IsoTriangle isoTA(98, 5);
	IsoTriangle isoTB = isoTA;
	IsoTriangle isoTC;
	IsoTriangle isoTD;

	if (isoTC == isoTB)				// testing overloading operatore '=='
	{
		cout "Impossibile che sia vero" << endl;
	}
	else
	{
		cout << "L'overloading dell'operatore '==' funziona correttamente" << endl;
	}

	isoTD.SetDim(0, -6);			// creazione oggetto triangolo isoscele per costruttore normale

	cout << "Area" << isoTD.Area() << endl;		// area di oggetto triangolo isoscele che geometricamente non ha senso


	/*---------------------------------------------All of them-------------------------------------------------*/

	rectA(L1, L2);						// definizione di oggetto rettangolo con costruttore normale
	IsoTriangle isoTJ(B1, H);			// definizione di oggetto triangolo iscoscele con costruttore normale

	int RectAPerimeter = 0;
	int IsoTJPerimeter = 0;

	int side = 0;

	side = isoTJ.Side();

	RectAPerimeter = (L1 + L2) * 2;		// calcolo perimetro localmente
	IsoTJPerimeter = (2 * side) + B1;

	if (RectAPerimeter == rectA.Perimeter)		// controllo se le funzioni perimetro funzionano correttamente
	{
		cout << "La funzione perimetro funziona correttamente" << endl;
	}
	else
	{
		cout << "La funzione perimetro NON funziona correttamente" << endl;
	}

	// confronto funzionamento Draw() e Dump() --> nel ".cpp" la Draw() chiama la Dump()

	rectA.Draw();
	rectA.Dump();

	if (rectA.Draw()==rectA.Dump())
	{
		return 1;
	}

	else
	{
		cout << "Le due funzioni comunicano dati diversi" << endl;
	}

	cout << endl;

	RhombusW.Draw();
	RhombusW.Dump(); 

	if (RhombusW.Draw() == RhombusW.Dump())
	{
		return 1;
	}
	else
	{
		cout << "Le due funzioni comunicano dati diversi" << endl;
	}

	cout << endl;

	isoTJ.Draw();
	isoTJ.Dump();

	if (isoTJ.Draw() == isoTJ.Dump())
	{
		return 1;
	}

	else
	{
		cout << "Le due funzioni comunicano dati diversi" << endl;
	}

	cout << endl;

	/*rectA.Draw(89);*/				// passo argomenti ad una funzione definita virtual pura: SE non si commenta
									// verificato che non compila, come è giusto che sia

	
	return 0;

}
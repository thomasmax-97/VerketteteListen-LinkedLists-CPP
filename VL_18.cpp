#include <iostream>
#include <fstream>
#include "CZahl.h"
using namespace std;


int main()
{
	double z;

	CZahl *firstPtr = 0;
	CZahl *listPtr = 0;
	CZahl *lastPtr = 0;

	// Liste anlegen

	do
	{
		listPtr = new CZahl;
		cout<<"Zahl? "; cin>>z;
		listPtr->setZahl(z);
		listPtr->next = 0;

		if(lastPtr)
		{
			lastPtr->next = listPtr;	
		}
		else
		{
			firstPtr = listPtr;			
		}

		lastPtr = listPtr;
	}
	while(listPtr->getZahl() != 0);

	// Ausgabe der Liste

	listPtr = firstPtr;

	do
	{
		cout<<listPtr->getZahl()<<"\t";
		listPtr = listPtr->next;
	}
	while(listPtr->getZahl() != 0);
	cout<<"\n";

	// Serielles Suchen (Lineares Suchen)

	bool gefunden;
	int pos;

	cout<<"Zahl? ";	cin>>z;

	gefunden = false;
	pos = 0;

	listPtr = firstPtr;

	do
	{
		if(listPtr->getZahl() == z)
		{
			gefunden = true;
			break;
		}
		listPtr = listPtr->next;
		pos++;
	}
	while(listPtr->getZahl() != 0);

	if(gefunden)
		cout<<"Gefunden an "<<pos<<". Position mit dem Wert "<<(*listPtr).getZahl()<<".\n";
	else
		cout<<"Nicht vorhanden.\n";

	// Ein Objekt löschen

	cout<<"Zahl loeschen? ";	cin>>z;
	
	listPtr = firstPtr;

	do
	{
		if(listPtr->next->getZahl() == z)
		{
			listPtr->next = listPtr->next->next;
		}
		listPtr = listPtr->next;
	}
	while(listPtr->getZahl() != 0);


	// Ausgabe

	listPtr = firstPtr;

	do
	{
		cout<<listPtr->getZahl()<<"\t";
		listPtr = listPtr->next;
	}
	while(listPtr->getZahl() != 0);
	cout<<"\n";

	// Liste Speichern

	fstream aus;
	aus.open("Z:\\Liste.txt", ios::out);

	listPtr = firstPtr;
	do
	{
		aus<<listPtr->getZahl()<<"\n";
		listPtr = listPtr->next;
	}
	while(listPtr->getZahl() != 0);

	aus.close();

	cout<<"\nDatei:\n";
	system("type Z:\\Liste.txt");

	system("pause");
	return 0;
}
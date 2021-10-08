class CZahl
{
private:
	double Zahl;
public:
	CZahl *next;
	CZahl();
	void setZahl(double Zahl);
	double getZahl();
};

CZahl::CZahl()
{
	this->Zahl = 0.0;
}

void CZahl::setZahl(double Zahl)
{
	this->Zahl = Zahl;
}

double CZahl::getZahl()
{
	return this->Zahl;
}
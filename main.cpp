#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>

using namespace std;

double f(double x)  
{	
	return x*(3.0/4.0) - 7.0/4.0;
}	


int main()

{	ifstream data("data.txt");  //nome del file da cui prendere i dati
	ofstream result("result.txt");  // file su cui stampare l'output
	
	if (!data){     //check sui due file
		cerr << "Errore: non è stato possibile aprire il file dei dati" << endl;
		return 1;
	}
	
	if (!result){
		cerr << "Errore: non è stato possibile aprire il file di output" << endl;
		return 1;
	}
	
	result << "#\tN Mean \n";
	
	string line;  //inizializziamo la stringa "line"
	double n;
	int contatore = 0;
	double media = 0.0;
	
	while (data >> n)
	{
		contatore++;
		double N = f(n);
		media = (media * (contatore-1)+N)/contatore;
		result << contatore << "\t" << setprecision(16) << scientific << media << endl;
	}
    return 0;
}

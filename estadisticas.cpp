/*crear un programa en c++ de Programacion Orientada a Objetos que permita introducir datos por medio de la clase estadisticas
se identifique el sexo, año de nacimiento de la persona y su estado civil
Usar los metodos Setters y Getters*/

#include <stdio.h>
#include <stdlib.h>
#include<iostream>
#include<string>
#include<conio.h>
#include <list>
#include <iostream>
#include <vector>
#include <dos.h>
#include <time.h>

using namespace std;

class Estadisticas {
	private:
		int intSexo;
		int intEstado;
		int intAno;
		/*Declaración de lo métodos getter y setter*/

	public :
		int getIntSexo() {
			return intSexo;
		}
		void setIntSexo(int vIntSexo) {
			intSexo=vIntSexo;
		}
		int getIntEstado() {
			return intEstado;
		}
		void setIntEstado(int vIntEstado){
			intEstado=vIntEstado;
		}

		int getIntAno() {
			return intAno;
		}
		void setIntAno(int vIntAno){
			intAno=vIntAno;
		}
		/*Métodos encargados de realizar las operaciones*/

	/**Tomo la fecha actual del sistema para verificar quien puede votar*/
	static int fechaSistema(){
		struct tm *tiempo;
		//int dia;
		//int mes;
		int anio;

		time_t fecha_sistema;
		time(&fecha_sistema);
		tiempo=localtime(&fecha_sistema);
	
		anio=tiempo->tm_year + 1900;
		//mes=tiempo->tm_mon + 1;
		//dia=tiempo->tm_mday;
		return anio;
	}
	/*Número de Hombres solteros que si pueden votar*/
	int numeroHombresSolterosSiVotan(vector<Estadisticas> listaPersona){
		int votantes;
		/*Recorro la lista de personas que tengo*/
		for(int x=0;x<listaPersona.size();x++){
			Estadisticas esta;
			esta= listaPersona[x];
			if(esta.getIntSexo()==1&esta.getIntEstado()==1&(fechaSistema()-esta.getIntAno())>=18){
				votantes++;
			}
		}	
		return votantes;
	}
	/*Número de Hombres casados que si pueden votar*/
	int numeroHombresCasadosSiVotan(vector<Estadisticas> listaPersona){
		int votantes;
		/*Recorro la lista de personas que tengo*/
		for(int x=0;x<listaPersona.size();x++){
			Estadisticas esta;
			esta= listaPersona[x];
			if(esta.getIntSexo()==1&esta.getIntEstado()==2&(fechaSistema()-esta.getIntAno())>=18){
				votantes++;
			}
		}
		return votantes;
	}
	
	/*Número de Mujeres solteras que si pueden votar*/
	int numeroMujeresSolterasSiVotan(vector<Estadisticas> listaPersona){
		int votantes;
		/*Recorro la lista de personas que tengo*/
		for(int x=0;x<listaPersona.size();x++){
			Estadisticas esta;
			esta= listaPersona[x];
			if(esta.getIntSexo()==2&esta.getIntEstado()==1&(fechaSistema()-esta.getIntAno())>=18){
				votantes++;
			}
		}
		return votantes;
	}
	/*Número de Mujeres casadas que si pueden votar*/
	int numeroMujeresCasadasSiVotan(vector<Estadisticas> listaPersona){
		int votantes;
		/*Recorro la lista de personas que tengo*/
		for(int x=0;x<listaPersona.size();x++){
			Estadisticas esta;
			esta= listaPersona[x];
			if(esta.getIntSexo()==2&esta.getIntEstado()==2&(fechaSistema()-esta.getIntAno())>=18){
				votantes++;
			}
		}
		return votantes;
	}
	/*Número total de solteros que si pueden votar*/
	int numeroTotalSolterosSiVotan(vector<Estadisticas> listaPersona){
		int votantes;
		/*Recorro la lista de personas que tengo*/
		for(int x=0;x<listaPersona.size();x++){
			Estadisticas esta;
			esta= listaPersona[x];
			if(esta.getIntEstado()==1&(fechaSistema()-esta.getIntAno())>=18){
				votantes++;
			}
		}
		return votantes;
	}
	/*Número total de casados que si pueden votar*/
	int numeroTotalCasadosSiVotan(vector<Estadisticas> listaPersona){
		int votantes;
		/*Recorro la lista de personas que tengo*/
		for(int x=0;x<listaPersona.size();x++){
			Estadisticas esta;
			esta= listaPersona[x];
			if(esta.getIntEstado()==2&(fechaSistema()-esta.getIntAno())>=18){
				votantes++;
			}
		}
		return votantes;
	}
	/*Número total de personas que si pueden votar*/
	int numeroTotalPersonasSiVotan(vector<Estadisticas> listaPersona){
		int votantes;
		/*Recorro la lista de personas que tengo*/
		for(int x=0;x<listaPersona.size();x++){
			Estadisticas esta;
			esta= listaPersona[x];
			if((fechaSistema()-esta.getIntAno())>=18){
				votantes++;
			}
		}
		return votantes;
	}
	/*Número total de personas que no pueden votar*/
	int numeroTotalPersonasNoVotan(vector<Estadisticas> listaPersona){
		int votantes;
		/*Recorro la lista de personas que tengo*/
		for(int x=0;x<listaPersona.size();x++){
			Estadisticas esta;
			esta= listaPersona[x];
			if((fechaSistema()-esta.getIntAno())<18){
				votantes++;
			}
		}
		return votantes;
	}

};


/*Inicio del método main en c++ */
int main(){
	int empezarPrograma=1;
	vector<Estadisticas> lista;
	int sexo;
	int estado;
	int ano;

	while(empezarPrograma==1){
		Estadisticas est;
		
		cout <<" Digite el Sexo por favor : 1 Masculino, 2:Femenino: \n";
		cin>> sexo;
		est.setIntSexo(sexo);
		cout <<"Sexo ingresado:" <<est.getIntSexo()<<"\n";
		
		cout <<" Digite su estado Civil 1 si es Soltero y 2 si es Casado \n";
		cin>> estado;
		est.setIntEstado(estado);
		cout <<"Estado Civil ingresado:" <<est.getIntEstado()<<"\n";
		cout <<" Digite Año de Nacimiento\n";
		
		cin>> ano;
		est.setIntAno(ano);
		cout <<"Año de Nacimiento:" <<est.getIntAno()<<"\n";

		lista.push_back(est);

		cout <<" Desea continuar ingresando mas personal Digite 1, para continuar 0 para salir\n";
		cin>> empezarPrograma;

	}
	Estadisticas es;

	cout << "Numero de Hombres solteros que pueden votar : "<<es.numeroHombresSolterosSiVotan(lista)<<"\n";
	cout << "Numero de Mujeras solteras que pueden votar : "<<es.numeroMujeresSolterasSiVotan(lista)<<"\n";
	cout << "Numero de Hombres casados que pueden votar : "<<es.numeroHombresCasadosSiVotan(lista)<<"\n";
	cout << "Numero de Mujeras casadas que pueden votar : "<<es.numeroMujeresCasadasSiVotan(lista)<<"\n";
	cout << "Numero total de solteros que pueden votar : "<<es.numeroTotalSolterosSiVotan(lista)<<"\n";
	cout << "Numero total de casados que pueden votar : "<<es.numeroTotalCasadosSiVotan(lista)<<"\n";
	cout << "Numero total de personas que pueden votar : "<<es.numeroTotalPersonasSiVotan(lista)<<"\n";
	cout << "Numero total de personas que no pueden votar : "<<es.numeroTotalPersonasNoVotan(lista)<<"\n";

	return 0;
}

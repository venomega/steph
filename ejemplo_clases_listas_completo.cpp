#include <iostream>
#include <vector>  
using namespace std;

class a{
	public:	
	int is_b = 0; 
};

class b:public a{
	public:
		b(){ 
			is_b = 1;
		}	
};

class control{ 
	public:
		vector <a*> lista; 

	void agregar_a_la_lista( a* elemento){ 
		lista.push_back(elemento);
	}

	void mostrar_lista(){
		for (a* x:lista){
			if (x->is_b == 1) // igual a 1 es que es de tipo b
			{
				cout << "soy B" << endl;
			}
			if (x->is_b != 1) // distinto de 1 es qeu no es de tipo b
			{
				cout << "NO soy B"<< endl;
			}
				
		}
	}
};

int main(){
	b objeto_1;
	cout << "is_b = " << objeto_1.is_b <<endl; 

	control objeto_control;

	objeto_control.agregar_a_la_lista(&objeto_1);
	objeto_control.mostrar_lista();			
	cout << "fin de la primera muestra" << endl;

	a objeto_a;
	objeto_control.agregar_a_la_lista(&objeto_a);
	objeto_control.mostrar_lista();			
	cout << "fin de la segunda muestra" << endl;		

	return 0;
}

/*  SALIDA DEL PROGRAMA

		is_b = 1
		soy B
		fin de la primera muestra
		soy B
		NO soy B
		fin de la segunda muestra
*/

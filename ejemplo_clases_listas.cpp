#include <iostream>
#include <vector>  //libreria para crear las listas
using namespace std;

class a{     // esta es la clase padre
	public:	
	int is_b = 0; //esto es para usarlo a la hora de definir
			//si la clase es a o b
	
};

class b:public a{
	public:
		b(){ // al crear un objeto b, decimos que es de ese tipo
			is_b = 1;  //para posterior uso al buscar en la lista
		}	
};

class control{ //este es un ejemplo de una clase controladora
	public:
		vector <a*> lista; //asi se crea la lista usando vector

	//asi es como se agregan objetos a la lista
	void agregar_a_la_lista( a* elemento){ 
		lista.push_back(elemento);
	}
	//en este metodo es donde se recorre la lista
	//y en caso de encontrar el tipo de objeto deseado
	//se realiza una operacion x
	void mostrar_lista(){
		for (a* x:lista){
			cout << "el objeto es b?: " << x->is_b <<endl;
		}
	}
};

int main(){
	//creamos un objeto de tipo b
	b objeto_1;
	cout << "is_b = " << objeto_1.is_b <<endl; //aqui esto muestra 1 en la pantalla

	// creamos el objeto controlador
	control objeto_control;

	//ahora agregamos a la lista
	objeto_control.agregar_a_la_lista(&objeto_1);
	//y aqui mostramos el objeto
	objeto_control.mostrar_lista();			
	cout << "fin de la primera muestra" << endl;
	//si ahora creamos un objeto de tipo a
	a objeto_a;
	// y luego agregamos a la lista el nuevo objeto a
	objeto_control.agregar_a_la_lista(&objeto_a);
	//y aqui mostramos el objeto
	objeto_control.mostrar_lista();			
	cout << "fin de la segunda muestra" << endl;	


	/*
	Cuando ejecutas el codigo se muestra esto:

	is_b = 1
	el objeto es b?: 1
	fin de la primera muestra
	el objeto es b?: 1
	el objeto es b?: 0
	fin de la segunda muestra

	---------------------------------
	en el metodo de la linea 30, osea este
		void mostrar_lista(){
		for (a* x:lista){
			cout << "el objeto es b?: " << x->is_b <<endl;
		}
	^
	|
	Aqui es donde va lo de si la clase es de un tipo o de otro 
	haga algo especifico, un ejemplo seria


		void mostrar_lista(){
		for (a* x:lista){
			if (x->is_b == 1) // igual a 1 es que es de tipo b
			{
				cout << "soy B";
			}
			if (x->is_b != 1) // distinto de 1 es qeu no es de tipo b
			{
				cout << "NO soy B";
			}
				
		}
	


	
	*/

	return 0;
}


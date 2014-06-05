//este programa es casi igual al ClaseVectorTemplate2013, pero la clase 
//errorsubindice se deriva de la clase exception, que es una clase
// base, de la cual disponemos en c++
//va a modo  de ejemplo para completar la breve aproximación al tema hecha en clase


#include <iostream>
using namespace std; //lo necesitamos para la clase exception

//Por motivos didácticos, para mostrar un ejemplo de clase para excepciones
// se definió esta clase para el manejo de los errores de subíndice en 
// tiempo de ejecución
//Pudo haberse derivado la clase de la clase exception (aplicando el concepto de herencia)

	class errorsubindice: public exception
	{
	public:
	errorsubindice();
	};
	errorsubindice::errorsubindice(){std::cout<<"Mensaje emitido al crear el objeto de la excepcion: \n Error de subíndice"<<std::endl;}

	template <class T>
	class Array
	{
	public:
	Array(); // constructor
	Array( const Array<T> & ); // constructor copia
	~Array( ); // destructor
	int getSize( ) const; // retorna tamaño
	Array<T>&operator=( const Array<T> & ); // operador asignacion
	bool operator==( const Array<T> & ) const; // operador comparacion
	T &operator[ ]( int ); // operator indexacion
	private:
	int size; // size del array
	T *ptr; // puntero al primer elemento del array
	};



	// Constructor por defecto sin argumentos
	template <class T>
	Array<T>::Array()
	{
	ptr = new T[10];
	size=10;
	}

	// Constructor copia recibe una referencia
	template <class T>
	Array<T>::Array( const Array<T> &init )
	{
	size=init.size ;
	ptr = new T[ size ];
	for ( int i = 0; i < size; i++ )
	ptr[ i ] = init.ptr[ i ]; // copia el contenido del objeto pasado por referencia
	//deberá estar sobrecargado el operador de asignación
	// para el tipo T
	}
	// Destructor

	template <class T>
	Array<T>::~Array()
	{
	if (ptr)
	delete [ ] ptr; // libera el espacio del array
	}
	// Retorna el tamaño del objeto
	template <class T>
	int Array<T>::getSize() const { return size; }
	// Sobrecarga del operador asignacion
	template <class T>
	Array<T>& Array<T>::operator=( const Array<T> &rigth )
	{
	if ( &rigth != this ) // chequea para evitar autoasignaciones
	{ // para arrays de diferentes tamaños, libera espacio usado y luego genera zona nueva y la carga

	if ( size != rigth.size )
	{
	T *aux; //auxiliar por si no se obtiene el espacio; en ese caso se eligió dejar el array como estaba
	aux=new T[ rigth.size ]; //se pide espacio; si no se obtiene new lanza bad_alloc
	delete [] ptr; // si llegó acá es que obtuvo el espacio;libera el anterior espacio
	size =rigth.size ; // asigna el tamaño adecuado
	ptr=aux; //apunta a la nueva zona
	for ( int i = 0; i < size; i++ )
	ptr[ i ] = rigth.ptr[ i ]; // copia el array en el nuevo objeto
	return *this; // al retornar una referencia permite x = y = z;
	}
	else //si tienen el mismo tamaño, sólo hay que reasignar valores
	{
	for ( int i = 0; i < size; i++ )
	ptr[ i ] = rigth.ptr[ i ]; // copia el array en el nuevo objeto
	return *this; // al retornar una referencia permite x = y = z;
	}

	}
	return *this;
	}
	// Determina si dos arrays son iguales, retornando true o false
	template <class T>
	bool Array<T>::operator==( const Array<T> &rigth ) const
	{
	if ( size != rigth.size )
	return false; // arrays de diferentes tamaños
	else
	for ( int i = 0; i < size; i++ )
	if ( ptr[ i ] != rigth.ptr[ i ] )
	return false; // los arrays no son iguales
	return true; // los arrays son iguales
	}
	
	// Sobrecarga del operador indexacion; la referencia retornada es un lvalue
	template <class T>
	T & Array<T>::operator [ ]( int subscript )
	{
	//si el subíndice no es válido, se arroja una excepción
	if( (0 > subscript)|| (subscript > size) ) throw errorsubindice();
	else
	{
	return ptr[ subscript ]; // retorna referencia
	}}

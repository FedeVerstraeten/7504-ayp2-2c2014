#include"file_load.hpp"


//Especificaciones de la funcion:
//le pasan una referencia al archivo ya abierto previamente.
//devuelve por interfaz un arreglo de punteros a objeto string cargados con el archivo file(una linea por string).
//devuelve la cantindad de lineas leidas.

status_t loadFileMemory(fstream &file,string ***lines,size_t &size){

        size_t alloc_size,i;
        string **aux,str;

        if(lines==NULL)return ERROR_NULL_POINTER;
        if(((*lines)=new string*[INIT_CHOP])==NULL)return ERROR_MEMORY_NO_AVAILABLE;

        size=0;
        alloc_size=INIT_CHOP;

        while(getline(file,str)){

                if(size==alloc_size){

                        if((aux=new string*[CHOP_SIZE+alloc_size])==NULL){

                                for(i=0;i<size;i++){
                                        delete(*lines)[i];
                                }
                                delete[](*lines);
                                return ERROR_MEMORY_NO_AVAILABLE;
                        }
                        alloc_size+=CHOP_SIZE;
                        for(i=0;i<size;i++){

                                aux[i]=(*lines)[i];
                        }
                        delete [](*lines);//elimino el viejo arreglo
                        (*lines)=aux;

                }

                (*lines)[size++]=new string(str);
        }
 return OK;
}

//Especificaciones de funcion.
//Borra los string y luego el arreglo de punteros  a string.
status_t eraseFileMemory(string ***lines,size_t &size){

        size_t i;

        if(lines==NULL)return ERROR_NULL_POINTER;
        for(i=0;i<size;i++){
                delete(*lines)[i];//vuela el puntero iesimo en memoria
        }
        delete[](*lines);//vuela el arreglo
        *lines=NULL;
return OK;
}












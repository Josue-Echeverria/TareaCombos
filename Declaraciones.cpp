#include "Declaraciones.h"

    int Combo::componente_en_pos(string nombre_buscar){
        for(int i = 0; i<contador_componentes; i++){
            if(Componentes[i]->nombre == nombre_buscar)
                return i;
        }
        return -1;
    }


    int base_datos::combo_en_pos(string nombre_buscar){
        for(int i = 0; i<contador_combos;i++){
            if(Combos[i]->nombre == nombre_buscar)
                return i;
        }
        return -1;
    }

    /*Pseudocodigo:
        1. Se crea una bandera que se encedera cuando el valor actual del array es null y si la bandera no esta encendida
        2. Se recorre el array
        3. Si algun valor del array es null se guarda en la bandera la posicion en la que se encenio
        4. Si se encuentra con un valor que no es null y la bandera esta encendida
            4.1 Debera reemplazar la posicion en la que la bandera se encendio con el valor actual y dejar el valor actual en null
            4.2 Pregunta si aun hay valores para reacomodar
                4.2.1 Si aun quedan: solo se aumenta el valor de la bandera (La siguiente posicion es la que deberia de estar null)
                4.2.1 Por lo tanto se sigue recorriendo el array en busca de ese valor
                4.2.2 Si no quedan significa que el array quedo listoo y se saldra del ciclo en la siguiente linea
        5. Si el valor no es null y la bandera no esta encendida se sigue recorriendo el array con normalidad
    */

    void reacomodar_array(auto* array, int valores_NOTNULL){ // Paramentros:  array = array por ordenar, tamanio = tamanio del array, valores_NOTNULL = cuantos valores del array no son nulos
        int pos = -1;
        for (int i = 0; valores_NOTNULL != 0 ; i++){
            if ((array[i] == NULL) & (pos == -1)){
                pos = i;
                continue;
            } else if ((array[i] == NULL) & (pos != -1)){
                continue;
            } else if ((array[i] != NULL) & (pos != -1)){
                array[pos] = array[i];
                array[i] = NULL;
                if (valores_NOTNULL-1 != 0){
                    pos++;
                }
            }
            valores_NOTNULL--;
        }
    };


    void Combo::agregrar_componente(Componente *componente_entrada){
        if (contador_componentes == 30){
            cout<<"\nERROR: NO PUEDE AGREGAR MAS COMPONENTES... COMBO LLENO!!"<<endl;
        } else {
            Componentes[contador_componentes] = componente_entrada;
            contador_componentes++;
            cout<<"\n¡Componente agregado con exito!\n"<<endl;
        }
    }


    void base_datos::agregar_combo(Combo *combo_entrada){
        if (contador_combos == 100){
            cout<<"\nERROR: NO SE PUEDEN AGREGAR MAS COMBOS!! MEMORIA LLENA!!\n"<<endl;
        } else {
                Combos[contador_combos] = combo_entrada;
                contador_combos++;
                cout<<"\n¡Combo agregado con exito!\n"<<endl;
        }
    }


    void base_datos::agregar_componente_combo(string nombre, Componente *nuevo_componente){
        Combos[combo_en_pos(nombre)]->agregrar_componente(nuevo_componente);
    }


    void Componente::imprimir_componente(){
        cout<<"Nombre: "<<nombre<<endl;
        cout<<"Cantidad: "<<cantidad<<endl;
        cout<<"Unidad de medida: "<<unidad_medida<<endl;
    }


    void Combo::imprimir_componentes(){
        if (contador_componentes == 0)
            cout<<"\nNO HAY NADA EN EL COMBO\n"<<endl;
        else {
            for(int i = 0; i<contador_componentes; i++)
                Componentes[i]->imprimir_componente();
        }
    }


    void base_datos::imprimir_combos(){
        if (contador_combos == 0)
            cout<<"\nNO HAY NADA EN EL COMBO\n"<<endl;
        else {
            for(int i = 0; i<contador_combos; i++){
                cout<<Combos[i]->nombre<<":"<<endl;
                Combos[i]->imprimir_componentes();
            }
        }
    }


    void base_datos::borrar_combo(string combo_borrar){
        if(contador_combos == 0){
            cout<<"ERROR: NO HAY COMBOS POR ELIMINAR"<<endl;
        } else {
            int pos = combo_en_pos(combo_borrar);
            if (pos == -1){
                cout<<"ERROR: EL COMBO QUE ESTA INTENTANDO ELIMINAR NO EXISTE"<<endl;
            } else {
                Combos[pos] = NULL;
                contador_combos--;
                reacomodar_array(Combos,contador_combos);
                cout<<"Se elimino el combo con exito!"<<endl;
            }
        }
    }


    void Interfaz(){
    /*AQUI INICIA LA BASE DE DATOS*/
    base_datos* menu = new base_datos();
    inicio:
    // Apenas se inicia el programa se imprimen las opciones que tiene el usuario para hacer:

    cout<<"^-^-^-^-^-^-^-^Menu^-^-^-^-^-^-^-^"<<endl;
    cout<< "1. Agregar combo" <<endl;
    cout<< "2. Buscar combo" <<endl;
    cout<< "3. Borrar combo" <<endl;
    cout<< "4. Imprimir todos los combos" <<endl;
    cout<< "5. Modificar nombre de un combo" <<endl;
    cout<< "6. Modificar cantidad de un componente de un combo" <<endl;
    cout<< "7. Agregar componente a un combo" <<endl;
    cout<< "8. Calcular para porciones" <<endl;
    cout<< "9. Salir\n"<<endl;

    // Se genera la entrada para que el usuario introduzca el numero correspondiente a la accion que desea hacer
    string entrada;
    string entrada1;
    string entrada2;
    string entrada3;
    int posicion;
    cin>>entrada; // Se guarda lo que el usuario meta en consola en la variable de entrada
    int opcion;
    try { // Se genera un try y uun catch para confirmar que la entrada es un entero
        opcion = stoi(entrada); // SI ES un int: se guarda en una var convirtiendo la entrada a int
    } catch (...){              // SI NO ES un int: cae en una excepcion que le indica al usuario que hizo mal y lo manda al inicion de la interfaz
        cout<<"\nPor favor digite un numero como entrada!!\n"<<endl;
        goto inicio;
    }

    // Si no hubo excepcion, cae en el switch para confirmar que tarea desea realizar el usuario
    switch(opcion){
        case 1:
            cout<<"Ingrese el nombre del nuevo combo: ";
            cin>>entrada;
            if (menu->combo_en_pos(entrada) == -1){// El combo no existe y por lo tanto no se repetira
                menu->agregar_combo(new Combo(entrada));
            } else {
                cout<<"\nEL COMBO YA ESTA EN EL LA BASE DE DATOS\n"<<endl;
            }
            goto inicio;

        case 2:
            cout<<"Ingrese el nombre del combo que desea buscar: ";
            cin>>entrada;
            menu->Combos[menu->combo_en_pos(entrada)]->imprimir_componentes();
            goto inicio;

        case 3:
            cout<<"Introduzca el nombre del combo que desea eliminar: ";
            cin>>entrada;
            menu->borrar_combo(entrada);
            goto inicio;

        case 4:
            // Imprime todos los combos (No hace falta decirle al usuario que acaba de elegir)
            menu->imprimir_combos();
            goto inicio;

        case 5:
            cout<<"\nUsted a elegido la opcion para cambiar el nombre de algun combo\n"<<endl;

            cout<<"TO DO"<<endl;
            goto inicio;

        case 6:
            cout<<"\nUsted a elegido la opcion para modifica la cantidad de un componente de un combo\n"<<endl;

            cout<<"TO DO"<<endl;
            goto inicio;

        case 7:
            cout<<"Ingrese el nombre del combo al que desea agregar el componente: ";
            cin>>entrada;
            posicion = menu->combo_en_pos(entrada);
            if(posicion == -1){ // EL combo al que se quiere añadir un componente no existe y por lo tanto no se puede agregar nada
                cout<<"ERROR: NO SE PUEDE AGREGAR COMPONENTE YA QUE EL COMBO NO EXISTE"<<endl;
                goto inicio;
            }
            cout<<"Ingrese el nombre del nuevo componente: ";
            cin>>entrada1;
            if (menu->Combos[posicion]->componente_en_pos(entrada1) != -1){
                cout<<"\nERROR: EL COMPONENTE YA ESTA EN EL COMBO"<<endl;
                goto inicio;
            }
preguntar_cuantos:
            cout<<"Digite cuantos desea agregar al combo: ";
            cin>>entrada2;
            try{
            stoi(entrada2);
            } catch(...){
                cout<<"\nINGRESAR SOLO NUMEROS ENTEROS"<<endl;
                goto preguntar_cuantos;
            }
Eleccion_medida:
            cout<<"Elija una unidad de medida: \n1.Vaso\n2.Lata\n3.Unidad\n";
            cin>>entrada3;
            try{
                if(stoi(entrada3) == 1 || stoi(entrada3) == 2 || stoi(entrada3) == 3){
                    menu->agregar_componente_combo(entrada, new Componente(entrada1,stoi(entrada2),stoi(entrada3)-1));
                } else {
                    cout<<"\nERROR: NO ES UNA OPCION VALIDA\n";
                    goto Eleccion_medida;
                }
            } catch (...){
                cout<<"\nERROR: NO ES UNA OPCION VALIDA\n";
                goto Eleccion_medida;
            }
            goto inicio;
        case 8:
            cout<<"\nUsted a elegido la opcion para calcular las porciones para n personas\n"<<endl;

            cout<<"TO DO"<<endl;
            goto inicio;
        case 9:
            cout<<"Gracias por su tiempo :)";
            break;
        default: // Si no digita un numero entre las opciones se manda al usuario al inicio de la interfaz
            cout<<"Por favor digite un numero que este entre las opciones!!"<<endl;
            goto inicio;
    }
}

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
            cout<<"\n�Componente agregado con exito!\n"<<endl;
        }
    }


    void base_datos::agregar_combo(Combo *combo_entrada){
        if (contador_combos == 100){
            cout<<"\nERROR: NO SE PUEDEN AGREGAR MAS COMBOS!! MEMORIA LLENA!!\n"<<endl;
        } else {
                Combos[contador_combos] = combo_entrada;
                contador_combos++;
                cout<<"\nCombo agregado con exito!\n"<<endl;
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
    
    void Combo::imprimir_porciones(){
        cout<<"La cantidad de porciones es de: "<<endl;

    }

    void base_datos::imprimir_combos(){
        if (contador_combos == 0)
            cout<<"\nNO HAY NADA EN EL COMBO\n"<<endl;
        else {
            for(int i = 0; i<contador_combos; i++){
                cout<<"\n"<<Combos[i]->nombre<<":"<<endl;
                Combos[i]->imprimir_componentes();
                cout<<"Cantidad de porciones: "<<Combos[i]->porciones<<endl;
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

    void base_datos::modificar_nombre(string nuevo_nombre, string nombre_actual){
        int pos = combo_en_pos(nombre_actual);
        if (combo_en_pos(nuevo_nombre) == -1){
            Combos[pos] -> nombre = nuevo_nombre;
            cout<<"Combo modificado con exito"<<endl;
        }else
            cout<<"ERROR: NO SE PUEDE MODIFIDICAR EL NOMBRE DEL COMBO YA QUE EL NOMBRE SE ENCUENTRA UTILIZADO"<<endl;
    }

    void base_datos::modifica_cantidad_componente(int posComp, int nueva_cantidad, int pos){
        Combos[pos]-> Componentes[posComp]->cantidad = nueva_cantidad;
        cout<<"Cantidad modificada con exito"<<endl;
    }

    void base_datos::calcular_porciones(int combo, int n_personas){
        double calculo;
        int contador_componentes = Combos[combo]->contador_componentes;
        int porcion = Combos[combo]->porciones;
        for(int i = 0; i<contador_componentes; i++){
            calculo = Combos[combo]->Componentes[i]->cantidad;
            calculo = (n_personas * calculo) / porcion; 
            Combos[combo]->Componentes[i]->imprimir_componente();
            cout<<"La nueva cantidad estimada es de: "<<calculo<<" "<<Combos[combo]->Componentes[i]->unidad_medida<<endl;
        }   
    }

    void Interfaz(base_datos *menu){
    /*AQUI INICIA LA BASE DE DATOS*/
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
    getline(cin,entrada); // Se guarda lo que el usuario meta en consola en la variable de entrada
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
            getline(cin,entrada);
            if (menu->combo_en_pos(entrada) == -1){// El combo no existe y por lo tanto no se repetira
                menu->agregar_combo(new Combo(entrada));
                posicion = menu->combo_en_pos(entrada);
preguntar_componente:
                cout<<"Ingrese el nombre del nuevo componente: ";
                getline(cin,entrada1);
                if (menu->Combos[posicion]->componente_en_pos(entrada1) != -1){
                    cout<<"\nERROR: EL COMPONENTE YA ESTA EN EL COMBO"<<endl;
                    goto preguntar_componente;
                }
preguntar_cant:
                cout<<"Digite cuantos desea agregar al combo: ";
                getline(cin,entrada2);
                try{
                stoi(entrada2);
                } catch(...){
                    cout<<"\nINGRESAR SOLO NUMEROS ENTEROS"<<endl;
                    goto preguntar_cant;
                }
                cout<<"Ingrese la una unidad de medida: ";
                getline(cin,entrada3);
                menu->agregar_componente_combo(entrada, new Componente(entrada1,stoi(entrada2),entrada3));
                cout<<"Desea agregar otro componente y/n.... "<<endl;
                getline(cin,entrada3);
                if(entrada3 == "n"){
                    cout<<"Ingrese la cantidad de porciones: "<<endl;
                    getline(cin, entrada2);
                    menu->Combos[posicion]->porciones = stoi(entrada2);
                    goto inicio;
                }
                goto preguntar_componente;
            } else {
                cout<<"\nEL COMBO YA ESTA EN EL LA BASE DE DATOS\n"<<endl;
            }
            goto inicio;

        case 2:
            cout<<"Ingrese el nombre del combo que desea buscar: ";
            getline(cin,entrada);
            if (menu->combo_en_pos(entrada) != -1){// El combo no existe y por lo tanto no se repetira
                menu->Combos[menu->combo_en_pos(entrada)]->imprimir_componentes();
                cout<<"Cantidad de porciones: "<<menu->Combos[menu->combo_en_pos(entrada)]->porciones<<endl;

            } else {
                cout<<"\nEl combo no existe\n"<<endl;
            }
            goto inicio;

        case 3:
            cout<<"Introduzca el nombre del combo que desea eliminar: ";
            getline(cin,entrada);
            menu->borrar_combo(entrada);
            goto inicio;

        case 4:
            // Imprime todos los combos (No hace falta decirle al usuario que acaba de elegir)
            menu->imprimir_combos();
            goto inicio;

        case 5:
            cout<<"\nUsted a elegido la opcion para cambiar el nombre de algun combo\n"<<endl;
            cout<<"Inserte el nombre del combo a modificar: ";
            getline(cin,entrada);
            posicion = menu->combo_en_pos(entrada);
            if(posicion == -1){
                cout<<"ERROR: NO SE PUEDE MODIFIDICAR EL NOMBRE DEL COMBO YA QUE EL COMBO NO EXISTE"<<endl;
                goto inicio;
            }
            cout<<"\nEscriba el nombre a modificar: "<<endl;
            getline(cin,entrada1);
            menu->modificar_nombre(entrada1, entrada);
            goto inicio;

        case 6:
            cout<<"\nUsted a elegido la opcion para modificar la cantidad de un componente de un combo\n"<<endl;
            cout<<"Ingrese el nombre del combo al que desea modificar la cantidad componente: ";
            getline(cin,entrada);
            posicion = menu->combo_en_pos(entrada);
            if(posicion == -1){ // EL combo al que se quiere a�adir un componente no existe y por lo tanto no se puede agregar nada
                cout<<"ERROR: NO SE PUEDE AGREGAR COMPONENTE YA QUE EL COMBO NO EXISTE"<<endl;
                goto inicio;
            }
            menu->Combos[posicion]->imprimir_componentes();
            cout<<"Ingrese el nombre del componente: ";
            getline(cin,entrada1);
            if (menu->Combos[posicion]->componente_en_pos(entrada1) == -1)
                cout<<"\nERROR: EL COMPONENTE NO ESTA EN EL COMBO"<<endl;
            else{
                int cant;
                cout<<"\nInserte la cantidad nueva: ";
                cin>>cant;
                int posComp = menu->Combos[posicion]->componente_en_pos(entrada1);
                menu-> modifica_cantidad_componente(posComp, cant, posicion);
            }
            goto inicio;

        case 7:
            cout<<"Ingrese el nombre del combo al que desea agregar el componente: ";
            getline(cin,entrada);
            posicion = menu->combo_en_pos(entrada);
            if(posicion == -1){ // EL combo al que se quiere a�adir un componente no existe y por lo tanto no se puede agregar nada
                cout<<"ERROR: NO SE PUEDE AGREGAR COMPONENTE YA QUE EL COMBO NO EXISTE"<<endl;
                goto inicio;
            }
            cout<<"Ingrese el nombre del nuevo componente: ";
            getline(cin,entrada1);
            if (menu->Combos[posicion]->componente_en_pos(entrada1) != -1){
                cout<<"\nERROR: EL COMPONENTE YA ESTA EN EL COMBO"<<endl;
                goto inicio;
            }
preguntar_cuantos:
            cout<<"Digite cuantos desea agregar al combo: ";
            getline(cin,entrada2);
            try{
            stoi(entrada2);
            } catch(...){
                cout<<"\nINGRESAR SOLO NUMEROS ENTEROS"<<endl;
                goto preguntar_cuantos;
            }
            cout<<"Ingrese la una unidad de medida: ";
            getline(cin,entrada3);
            menu->agregar_componente_combo(entrada, new Componente(entrada1,stoi(entrada2),entrada3));
            goto inicio;
        case 8:
            cout<<"\nUsted a elegido la opcion para calcular las porciones para n personas\n"<<endl;
            cout<<"Ingrese el nombre del combo al que desea calcular la cantidad de porciones: ";
            getline(cin,entrada);
            posicion = menu->combo_en_pos(entrada);
            if(posicion == -1){ // EL combo al que se quiere a�adir un componente no existe y por lo tanto no se puede agregar nada
                cout<<"ERROR: NO SE PUEDE CALCULAR COMPONENTES YA QUE EL COMBO NO EXISTE"<<endl;
                goto inicio;
            }
            if(menu->Combos[posicion]->contador_componentes == 0){
                cout<<"ERROR: NO SE PUEDE CALCULAR COMPONENTES YA QUE EL COMBO NO POSEE COMPONENTES"<<endl;
                goto inicio;
            }
            //menu->Combos[posicion]->imprimir_componentes();
            menu->Combos[posicion]->imprimir_componentes();
preguntar_estimado:
            cout<<"Digite para cuantas personas desea calcular el combo: ";
            getline(cin,entrada2);
            try{
            stoi(entrada2);
            } catch(...){
                cout<<"\nINGRESAR SOLO NUMEROS ENTEROS"<<endl;
                goto preguntar_estimado;
            }
            menu->calcular_porciones(posicion, stoi(entrada2));
            goto inicio;
        case 9:
            cout<<"Gracias por su tiempo :)";
            break;
        default: // Si no digita un numero entre las opciones se manda al usuario al inicio de la interfaz
            cout<<"Por favor digite un numero que este entre las opciones!!"<<endl;
            goto inicio;
    }
}

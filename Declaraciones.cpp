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

    void Combo::agregrar_componente(Componente *componente_entrada){
        if (contador_componentes == 30){
            cout<<"\nERROR: NO PUEDE AGREGAR MAS COMPONENTES... COMBO LLENO!!"<<endl;
        } else {
            if (componente_en_pos(componente_entrada->nombre) == -1){
                Componentes[contador_componentes] = componente_entrada;
                contador_componentes++;
                cout<<"\n¡Componente agregado con exito!\n"<<endl;
            } else {
                cout<<"\nERROR: EL COMPONENTE YA ESTA EN EL COMBO"<<endl;
            }
        }
    }

    void base_datos::agregar_combo(Combo *combo_entrada){
        if (contador_combos == 100){
            cout<<"\nERROR: NO SE PUEDEN AGREGAR MAS COMBOS!! MEMORIA LLENA!!\n"<<endl;
        } else {
            if (combo_en_pos(combo_entrada->nombre) == -1){
                Combos[contador_combos] = combo_entrada;
                contador_combos++;
                cout<<"\n¡Combo agregado con exito!\n"<<endl;
            } else {
                cout<<"\nEL COMBO YA ESTA EN EL LA BASE DE DATOS\n"<<endl;
            }
        }
    }

    void Componente::imprimir_componente(){
        cout<<"Nombre: "<<nombre<<endl;
        cout<<"Cantidad: "<<cantidad<<endl;
        cout<<"Unidad de medida: "<<unidad_medida<<endl;
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
    cin>>entrada; // Se guarda lo que el usuario meta en consola en la variable de entrada
    int opcion;
    try { // Se genera un try y uun catch para confirmar que la entrada es un entero
        opcion = stoi(entrada); // SI ES un int: se guarda en una var convirtiendo la entrada a int
    } catch (...){              // SI NO ES un int: cae en una excepcion que le indica al usuario que hizo mal y lo manda al inicion de la interfaz
        cout<<"Por favor digite un numero como entrada!!"<<endl;
        goto inicio;
    }

    // Si no hubo excepcion, cae en el switch para confirmar que tarea desea realizar el usuario
    switch(opcion){
        case 1:
            cout<<"¿Como desea llamar al nuevo combo?"<<endl;
            cin>>entrada;
            menu->agregar_combo(new Combo(entrada));
            goto inicio;

        case 2:
            cout<<"\nUsted a elegido la opcion para buscar un combo\n"<<endl;
            cout<<"¿Cual es el nombre del combo que desea buscar?"<<endl;
            cin>>entrada;
            menu->Combos[menu->combo_en_pos(entrada)]->imprimir_componentes();
            cout<<"TO DO"<<endl;
            goto inicio;

        case 3:
            cout<<"\nUsted a elegido la opcion para borrar un combo\n"<<endl;

            cout<<"TO DO"<<endl;
            goto inicio;

        case 4:
            // Imprime todos los combos (No hace falta decirle al usuario que acaba de elegir)

            cout<<"TO DO"<<endl;
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
            cout<<"\nUsted a elegido la opcion para agregar un componente a un combo\n"<<endl;

            cout<<"TO DO"<<endl;
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


    void Combo::imprimir_componentes(){


        if (contador_componentes == 0)
            cout<<"\nNO HAY NADA EN EL COMBO\n"<<endl;
        else {
            for(int i = 0; i<contador_componentes; i++)
                Componentes[i]->imprimir_componente();

        }
    }

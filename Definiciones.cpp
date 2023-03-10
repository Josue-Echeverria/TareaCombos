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


    void Combo::imprimir_componentes(){
        if (contador_componentes == 0)
            cout<<"\nNO HAY NADA EN EL COMBO\n"<<endl;
        else {
            for(int i = 0; i<contador_componentes; i++)
                Componentes[i]->imprimir_componente();

        }
    }

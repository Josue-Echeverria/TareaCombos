#include <iostream>
#include <string>
using namespace std;


// Estrcutura de comida que sera parte de un combo

struct Componente{
    string nombre;
    int cantidad;
    string unidad_medida;

    Componente(){};
    Componente(string nombre_entrada, int cantidad_entrada, string unidad_medida_entrada){
        nombre = nombre_entrada;
        cantidad = cantidad_entrada;
        unidad_medida = unidad_medida_entrada;    
    }

    //Procedimientos:
    void imprimir_componente();
};

// Estructura que tendra un array de componentes

struct Combo{
    // Atributos
    string nombre;
    Componente *Componentes[30];
    int contador_componentes = 0;
    int porciones;

    Combo(string nombre_entrada){
        nombre = nombre_entrada;
    }
    Combo(){}

    // Procedimientos
    int componente_en_pos(string nombre_buscar);
    void agregrar_componente(Componente *componente_entrada); // Agrega un componente al combo
    void modificar_cant_componente(string nombre, int nueva_cant); // Busca el componente con el nombre correspondiente y cambia la cantidad
    void imprimir_componentes(); // Imprime todos los componentes del combo
    void imprimir_porciones();
};

// Estructura que almacenara todos los combos del restaurante

struct base_datos{

    // Atributos
    Combo *Combos[100];
    int contador_combos = 0;

    base_datos(){}

    // Procedimientos
    int combo_en_pos(string nombre_buscar);
    void agregar_combo(Combo *combo); // Agrega un combo al array de la base de datos
    void buscar_combo(string nombre_combo); // Busca el combo con el nombre que se dio de entrada y lo imprime
    void borrar_combo(string combo_borrar); // Borra el combo con el nombre que se dio de entrada
    void imprimir_combos(); // Imprime todos los combos que se han agregado a la base de datos
    void modificar_nombre(string nuevo_nombre, string nombre_actual); // Busca el nombre actual del combo en la base de datos y lo cambia por un nombre nuevo
    void modifica_cantidad_componente(int posComp, int nueva_cantidad, int pos); // Buca el combo con el nombre correspondiente y modifica la cantidad de componente de un combo
    void agregar_componente_combo(string nombre, Componente *componente_agregar); // Busca el combo que se va a modificar y agrega el componente de entrada
    void calcular_porciones(int combo, int n_personas); // Calcula cuantos componentes tiene que tener un combo para servir a n personas (Regla de 3)

};
void Interfaz(base_datos* menu);


#include <iostream>
#include <string>
using namespace std;

// Estrcutura de comida que sera parte de un combo
struct Componente{
    string nombre;
    int cantidad;
    string unidad_medida;
    string unidades_medida[2][3] = {{"Pequenia","Mediana","Grande"},{"Vaso","Lata","Unidad"}};

    Componente(){};
    Componente(string nombre_entrada, int cantidad_entrada, int tipo_alimento, int unidad_medida_entrada){
        nombre = nombre_entrada;
        cantidad = cantidad_entrada;
        unidad_medida = unidades_medida[tipo_alimento][unidad_medida_entrada];
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

    Combo(string nombre_entrada){
        nombre = nombre_entrada;
    }
        Combo(){}

    // Procedimientos
    int componente_en_pos(string nombre_buscar);
    void agregrar_componente(Componente *componente_entrada); // Agrega un componente al combo
    void modificar_cant_componente(string nombre, int nueva_cant); // Busca el componente con el nombre correspondiente y cambia la cantidad
    void imprimir_componentes(); // Imprime todos los componentes del combo
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
    void imprimir(); // Imprime todos los combos que se han agregado a la base de datos
    void modificar_nombre(string nuevo_nombre, string nombre_actual); // Busca el nombre actual del combo en la base de datos y lo cambia por un nombre nuevo
    void modifica_cantidad_componente(string nombre, int nueva_cantidad); // Buca el combo con el nombre correspondiente y modifica la cantidad de componente de un combo
    void agregar_componente_combo(string nombre, Componente componente_agregar); // Busca el combo que se va a modificar y agrega el componente de entrada
    void calcular_porciones(string nombre, int n_personas); // Calcula cuantos componentes tiene que tener un combo para servir a n personas (Regla de 3)

};

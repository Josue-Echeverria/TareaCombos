
#include "Declaraciones.cpp"

int main()
{
    Componente *componente_prueba0 = new Componente("Hamburguesa", 2, "Unidad");
    Componente *componente_prueba1 = new Componente("Coca", 2, "Litros");
    Componente *componente_prueba2 = new Componente("Cafe", 1, "Taza");
    Componente *componente_prueba3 = new Componente("Pollo frito", 4, "Pieza");
    Componente *componente_prueba4 = new Componente("Pizza", 1, "Unidad");
    Componente *componente_prueba5 = new Componente("Platano Maduro", 2, "Unidad");
    Componente *componente_prueba6 = new Componente("Pinto", 1, "Unidad");
    Componente *componente_prueba7 = new Componente("Salchichon", 3, "Unidad");
    Componente *componente_prueba8 = new Componente("Papas fritas", 2, "Unidad");
    Componente *componente_prueba9 = new Componente("Taco", 1, "Unidad");
    Componente *componente_prueba10 = new Componente("Cerveza", 1, "Botella");


    Combo *combo_prueba0 = new Combo("Combo Familiar");
    combo_prueba0->agregrar_componente(componente_prueba0);
    combo_prueba0->agregrar_componente(componente_prueba3);
    combo_prueba0->agregrar_componente(componente_prueba8);
    combo_prueba0->agregrar_componente(componente_prueba4);
    combo_prueba0->agregrar_componente(componente_prueba1);
    combo_prueba0 ->porciones = 4;

    Combo *combo_prueba1 = new Combo("Combo Personal");
    combo_prueba1->agregrar_componente(componente_prueba0);
    combo_prueba1->agregrar_componente(componente_prueba1);
    combo_prueba1 ->porciones = 1;

    Combo *combo_prueba3 = new Combo("Combo Estudiantec");

    Combo *combo_prueba4 = new Combo("Combo Ingeniero");
    combo_prueba4->agregrar_componente(componente_prueba2);

    Combo *combo_prueba5 = new Combo("Combo Mexicano");
    combo_prueba5->agregrar_componente(componente_prueba9);
    combo_prueba5->agregrar_componente(componente_prueba10);

    Combo *combo_prueba6 = new Combo("Combo Tico");
    combo_prueba6->agregrar_componente(componente_prueba6);
    combo_prueba6->agregrar_componente(componente_prueba7);
    combo_prueba6->agregrar_componente(componente_prueba5);
    combo_prueba6->agregrar_componente(componente_prueba2);
    combo_prueba6 ->porciones = 2;
    base_datos *base_pruebas = new base_datos();

    base_pruebas->agregar_combo(combo_prueba0);
    base_pruebas->agregar_combo(combo_prueba1);
    base_pruebas->agregar_combo(combo_prueba3);
    base_pruebas->agregar_combo(combo_prueba4);
    base_pruebas->agregar_combo(combo_prueba5);
    base_pruebas->agregar_combo(combo_prueba6);
    Interfaz(base_pruebas);

    return 0;
}


#include "Declaraciones.cpp"
void imprimir(int *array, int largo){
    cout<<"{";
	for (int i = 0; i< largo; i++){
        cout<<array[i]<<",";
	}
	cout<<"}"<<endl;
}
int main()
{
    Interfaz();

    cout << "Hello world!" << endl;
    return 0;
}

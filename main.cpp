#include <iostream>
#include <cmath>

using namespace std;

double calcularFuncao(double x) {
    double resultado = x*x*x - x - 2;
    return resultado;
}


double encontrarRaiz(double menor, double maior){
       double  meio= (menor+ maior)/2;
       if (abs(calcularFuncao(meio)) < 0.001) {
           return meio;
       } else   if (  calcularFuncao( meio) * calcularFuncao(menor) < 0){
         return    encontrarRaiz(menor, meio);
       }else{
       return encontrarRaiz(meio, maior);
           
       }
    
}
 
int main(int argc, char** argv) {
    double menor =-20;
    double maior=20;
    
    if (menor > maior) {

        cout << "Intervalo invalido! Impossivel calcular Raiz" << endl;
        return 0;
    }

    double raizEncontrada= encontrarRaiz(menor, maior);
    cout<< "Funcao da Raiz:"<< raizEncontrada;
 
    return 0;
}


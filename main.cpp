#include <iostream>
#include <conio.h>
#include "BinarySearchTree.h"

using namespace std;

int main () {

    BinarySearchTree MyTree;
    int opc, opc2, size;
    cout << "INGRESE LA CANTIDAD DE NODOS QUE TENDRA EL ARBOL: ";
    cin >> size;

    for (int i = 0; i < size; i++) {
        int data;
        cout << "INGRESE UN ELEMENTO: ";
        cin >> data;
        MyTree.insert(data);
    }

    do {
        system("CLS");
        cout << "MENU" << endl;
        cout << "01. INSERTAR UN NODO" << endl;
        cout << "02. MOSTRAR LOS ELEMENTOS COMO ARBOL" << endl;
        cout << "03. RECORRIDOS EN PROFUNDIDAD" << endl;
        cout << "04. RECORRIDO EN AMPLITUD" << endl;
        cout << "05. BUSCAR UN NODO" << endl;
        cout << "06. ELIMINAR UN NODO" << endl;
        cout << "07. MOSTRAR NUMERO DE HOJAS" << endl;
        cout << "08. MOSTRAR ALTURA" << endl;
        cout << "09. CONTAR NODOS Y NIVELES" << endl;
        cout << "10. ELIMINAR TODOS LOS NODOS" << endl;
        cout << "11. SALIR" << endl;
        cout << "INGRESE LA OPCION QUE DESEA REALIZAR: ";
        cin >> opc;
        switch (opc) {
            case 1:
                int val;
                cout << "INGRESE EL VALOR QUE DESEA INSERTAR: ";
                cin >> val;
                MyTree.insert(val);
                break;
            case 2:
                cout << "ARBOL DE MANERA VERTICAL" << endl;
                MyTree.displayVerticalTree();
                getch();
                break;
            case 3:
                do {
                    system("CLS");
                    cout << "MENU" << endl;
                    cout << "1. MOSTRAR LOS ELEMENTOS EN PREORDEN" << endl;
                    cout << "2. MOSTRAR LOS ELEMENTOS EN INORDEN" << endl;
                    cout << "3. MOSTRAR LOS ELEMENTOS EN POSTORDEN" << endl;
                    cout << "4. SALIR" << endl;
                    cout << "INGRESE LA OPCION QUE DESEA REALIZAR: ";
                    cin >> opc2;
                    switch (opc2) {
                        case 1:
                            MyTree.preorderTraversal();
                            getch();
                            break;
                        case 2:
                            MyTree.inorderTraversal();
                            getch();
                            break;
                        case 3:
                            MyTree.postorderTraversal();
                            getch();
                            break;
                        case 4:
                            break;
                        default:
                            cout << "OPCION NO VALIDA, INGRESE DE NUEVO POR FAVOR" << endl;
                            getch();
                            break;
                    }
                } while (opc2 != 1 && opc2 != 2 && opc2 != 3 && opc2 != 4);
                break;
            case 4:
                MyTree.breadthTraversal();
                getch();
                break;
            case 5:
                int val2;
                cout << "INGRESE EL ELEMENTO QUE DESEA BUSCAR EN EL ARBOL: ";
                cin >> val2;
                if (MyTree.searchNode(val2)) {
                    cout << "NODO ENCONTRADO EN EL ARBOL" << endl;
                } else {
                    cout << "NODO NO ENCONTRADO EN EL ARBOL" << endl;
                }
                getch();
                break;
            case 6:
                int val3;
                cout << "INGRESE EL VALOR QUE DESEA ELIMINAR: ";
                cin >> val3;
                MyTree.removeNode(val3);
                break;
            case 7:
                cout << "EL NUMERO DE HOJAS DEL ARBOL ES DE " << MyTree.numberOfLeafs() << endl;
                getch();
                break;
            case 8:
                cout << "LA ALTURA DEL ARBOL ES DE " << MyTree.getHeight()<< endl;
                getch();
                break;
            case 9:
                cout << "EL NUMERO DE NODOS DEL ARBOL ES DE " << MyTree.numberOfNodes() << endl;
                cout << "EL NUMERO DE NIVELES DEL ARBOL ES DE " << MyTree.numberOfLevels() << endl;
                getch();
                break;
            case 10:
                MyTree.deleteTree();
                cout << "EL ARBOL HA SIDO ELIMINADO";
                getch();
                break;
            case 11:
                break;
            default:
                cout << "OPCION NO VALIDA, INGRESE DE NUEVO POR FAVOR" << endl;
                getch();
                break;
        }

    } while (opc != 11);

    getch();
    return 0;
}

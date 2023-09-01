#include"Coleccion.h"

int main(){
    int op = 1;
    string nombre;
    string id;
    float peso = 0;
    float estatura = 0;
    string genero;
    int annoNac = 0;
    string casa;
    int numL = 0;
    int numS = 0;
    string fechaV;
    string fechaA;
   
    Coleccion cole;
    Paciente* ptrPac;
    Vacuna* ptrVac;

    do {
        system("cls");
        cout << "\tMENU PRINCIPAL" << endl << endl;
        cout << "1- Ingresar paciente" << endl;
        cout << "2- Mostrar todos los pacientes" << endl;
        cout << "3- Buscar paciente especifico" << endl;
        cout << "4- Vacunar paciente" << endl;
        cout << "5- Lista pacientes vacunados (por genero)" << endl;
        cout << "6- Porcentajes de vacunacion" << endl;
        cout << "7- Vacunados por casa comercial" << endl;
        cout << "8- Salir" << endl << endl;
        cout << "Digite la opcion: ";
        cin >> op;

        switch (op) {
            case 1:
                op1:
                system("cls");
                cout << "\tRegistro del paciente:" << endl << endl;
                cout << "Nombre: ";
                getline(cin.ignore(), nombre);

                if (cole.estaNombre(nombre)) {
                    cout << "\n\tNombre repetido, por favor ingrese una persona diferente..!!" << endl << endl;
                    system("pause");
                    goto op1;
                }

                cout << "Cedula: ";
                cin >> id;

                if (cole.estaId(id)) {
                    cout << "\n\tCedula repetida, por favor ingrese una persona diferente..!!" << endl << endl;
                    system("pause");
                    goto op1;
                }

                cout << "Peso: ";
                cin >> peso;
                cout << "Estatura: ";
                cin >> estatura;
                cout << "Genero: ";
                cin >> genero;

                if (genero != "hombre" && genero != "mujer") {
                    cout << "\n\tPor favor, ingrese (hombre) o (mujer)!!" << endl << endl;
                    system("pause");
                    goto op1;
                }

                cout << "Anio de nacimiento: ";
                cin >> annoNac;
                
                ptrPac = new Paciente(nombre, id, peso, estatura, genero, annoNac);

                if (cole.ingresaPaciente(ptrPac)) {
                    cout << "\n\tSe ha ingresado correctamente" << endl << endl;
                }
                else { cout << "\n\tNo se ha ingresado correctamente" << endl << endl; }

                system("pause");
            break;

            case 2:
                system("cls");

                if (cole.getCanP() < 1) {
                    cout << "\n\tNo hay pacientes aun, por favor ingrese un paciente!!" << endl << endl;
                    system("pause");
                    break;
                }

                cout << "\tPacientes Registrados:" << endl << endl;
                cout << cole.listaPac();
                system("pause");
            break;

            case 3:
                op3:
                system("cls");
            
                cout << "\tConsulta de Paciente Especifico:" << endl << endl;

                if (cole.getCanP() < 1) {
                    cout << "\n\tNo hay pacientes aun, por favor ingrese un paciente!!" << endl << endl;
                    system("pause");
                    break;
                }

                cout << "Ingrese la cedula del paciente: ";
                cin >> id;
                cout << endl;

                if (cole.estaId(id)) {
                    cout << cole.buscaPac(id);
                }
                else {
                    cout << "\n\tCedula no encontrada, por favor ingrese una cedula presente!!" << endl << endl;
                    system("pause");
                    goto op3;
                }

                system("pause");
            break;

            case 4:
                op4:
                system("cls");
                cout << "\tVacunacion del paciente " << endl << endl;

                if (cole.getCanP() < 1) {
                    cout << "\n\tNo hay pacientes aun, por favor ingrese un paciente!!" << endl << endl;
                    system("pause");
                    break;
                }

                cout << "Ingrese la cedula del paciente a vacunar: ";
                cin >> id;

                if (cole.estaId(id) != true) {
                    cout << "\n\tCedula no encontrada, por favor ingrese una cedula presente!!" << endl << endl;
                    system("pause");
                    goto op4;
                }
                if (cole.estaVacunado(id)) {
                    cout << "\n\tPersona ya vacunada, por favor ingrese una persona diferente!!" << endl << endl;
                    system("pause");
                    goto op4;
                }

                cout << "\n\tInformacion de la vacuna:" << endl << endl;
                cout << "Casa comercial: ";
                getline(cin.ignore(), casa);
                cout << "Numero de lote: ";
                cin >> numL;
                cout << "Numero de serie: ";
                cin >> numS;

                if (cole.estaVacuna(numS)) {
                    cout << "\n\tVacuna ya registrada, por favot ingrese un numero de serie diferente!!" << endl << endl;
                    system("pause");
                    goto op4;
                }
                
                cout << "Fecha de vencimiento(d/m/a): ";
                cin >> fechaV;
                cout << "Fecha de Aplicacion(d/m/a): ";
                cin >> fechaA;

                ptrVac = new Vacuna(casa, numL, numS, fechaV, fechaA);

                if (cole.ponerVacuna(ptrVac, id)) {
                    cout << "\n\tVacuna ingresada correctamente!!" << endl << endl;
                }
                else { cout << "\n\tNo se ha podido ingresado la vacuna correctamente!!" << endl << endl; }
                
                system("pause");
            break;

            case 5:
                system("cls");
                cout << cole.listaVac();
                system("pause");
            break;

            case 6:
                system("cls");
                cout << "\tPorcentaje de Vacunacion:" << endl << endl;

                if (cole.getCanV() < 1) {
                    cout << "\n\tNo hay pacientes aun, por favor ingrese un paciente!!" << endl << endl;
                    system("pause");
                    break;
                }

                cout << "Hay un " << cole.porceVacu() << "% de personas vacunadas" << endl << endl;
                
                system("pause");
            break;

            case 7:
                op7:
                system("cls");
                cout << "\tVacunacion por Casa Comercial" << endl << endl;

                if (cole.getCanV() < 1) {
                    cout << "\n\tNo hay pacientes aun, por favor ingrese un paciente!!" << endl << endl;
                    system("pause");
                    break;
                }

                cout << "Ingrese la casa comercial: ";
                cin >> casa;
                cout << endl;

                if (cole.estaCasa(casa)) {
                    cout << cole.listaVacXCasa(casa);
                }
                else { 
                    cout << "Casa no encontrada, por favor ingrese una casa presente!!" << endl << endl;
                    system("pause");
                    goto op7;
                }

                system("pause");
            break;
        }
    } while (op != 8);
    return 0;
}
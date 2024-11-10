#include<iostream>
#include<cstdlib>
#include<string>
#include<ctime>
#include<windows.h>

using namespace std;

struct articulos{
    string id = " ";
    string art = " ";
    string desc = " ";
    int cost = 0;
    int exst = 0;
    int min = 0;
};

struct registro{
    int idCli;
    string nombre;
    string apPat;
    string apMat;
    string dir;
    string email;
    string tel;
    string rfc;
};

struct cfdi{
    string idCFDI;
    string desc;
};

struct factura{
    int idCli;
    string razSoc;
    string rfc;
    string fecha;
    string usoCFDI;
};

void submenu(){
    cout<<"*** Elija una opcion: ***"<<endl;
    cout<<"1. Alta"<<endl;
    cout<<"2. Actualizacion"<<endl;
    cout<<"3. Baja"<<endl;
    cout<<"4. Consulta"<<endl;
}

void printArrA(int arraySize, struct articulos arrA[]){
    for(int i = 0; i < arraySize; i++){
        cout<<endl<<endl<<"*** Articulo #"<<(i+1)<<" ***"<<endl;
        cout<<"ID del articulo: "<<arrA[i].id<<endl;
        cout<<"Nombre del articulo: "<<arrA[i].art<<endl;
        cout<<"Descripcion del articulo: "<<arrA[i].desc<<endl;
        cout<<"Costo por unidad: "<<arrA[i].cost<<endl;
        cout<<"Existencias del articulo: "<<arrA[i].exst<<endl;;
        cout<<"Minimo de existencias del articulo: "<<arrA[i].min;
    }
}

void printArrB(int arraySize, struct registro arrB[]){
    for(int i = 0; i < arraySize; i++){
        cout<<endl<<endl<<"*** Cliente #"<<(i+1)<<" ***"<<endl;
        cout<<"ID del cliente: "<<arrB[i].idCli<<endl;
        cout<<"Nombre: "<<arrB[i].nombre<<endl;
        cout<<"Apellido paterno: "<<arrB[i].apPat<<endl;
        cout<<"Apellido materno: "<<arrB[i].apMat<<endl;
        cout<<"Direccion: "<<arrB[i].dir<<endl;
        cout<<"Correo: "<<arrB[i].email<<endl;
        cout<<"Telefono: "<<arrB[i].tel<<endl;
        cout<<"RFC: "<<arrB[i].rfc<<endl;
    }
}

void printArrC(struct cfdi arrC[]){
    for(int i = 0; i < 10; i++){
        cout<<(i+1)<<". "<<arrC[i].idCFDI<<": "<<arrC[i].desc<<endl;
    }
}

int main(){
    //Variables GENERALES
    bool rpt = false, menu = false;
    int opt, subopt, arrSize = 3;
    //Variables ARTICULOS
    int altaCheck = 0, actuArt, actuArtPar, bajaArt;
    bool submenuArt, idArtCheck, costoCheck, exstCheck, minCheck, actuArtCheck, actuArtCheck2, bajaArtCheck;
    //Variables CLIENTES
    int clNum = 0, actuCli, actuCliPar, bajaCli;
    bool submenuCli, actuCliCheck, actuCliCheck2, bajaCliCheck;
    //Variables VENTAS
    int carrito[arrSize][2], billetes[6][2], monedas[4][2];
    int contadorCarr = 0, subtotal, cliSel, facTic, facturas = 0, cfdiSel, total, pago, totalBill, totalMon, sumaBillMon, cambio, sumaPrecios;
    string numTar = " ", cvv = " ";
    char selArtsChar, cliChar, usaBill, otroBill, usaMon, otraMon;
    bool selArts, selArtsCheck, exstCheckVenta, pagoCheck, cliCharCheck, cliSelCheck, nuevoCli, facTicCheck, facSoli, billetesRpt, denoBillCheck, cantBillCheck, otroBillCheck, monedasRpt, denoMonCheck, cantMonCheck, otraMonCheck, monCheck, billCheck, arrBfull;

    string cfdis[10][2] = {{"G01","Adquisicion de mercancias"},{"G02","Devoluciones, descuentos o bonificaciones"},{"G03","Gastos en general"},{"I01","Construcciones"},{"I02","Mobiliario y equipo de oficina por inversiones"},{"I03","Equipo de transporte"},{"I08","Otra maquinaria y equipo"},{"D02","Gastos medicos por incapacidad o discapacidad"},{"D04","Donativos"},{"P01","Por definir"}};
    struct articulos arrA[arrSize];
    struct registro arrB[arrSize];
    struct cfdi arrC[10];
    struct factura arrD[arrSize];

    int x;
    for(int i = 0; i < 10; i++){
        x = 0;
        arrC[i].idCFDI = cfdis[i][x];
        x++;
        arrC[i].desc = cfdis[i][x];
    }

    while(rpt == false){
        menu = false;
        arrBfull = false;
        while(menu == false){
            cout<<endl<<"*** Elija una opcion: ***"<<endl;
            cout<<"1. Articulos"<<endl;
            cout<<"2. Clientes"<<endl;
            cout<<"3. Venta"<<endl;
            cout<<"4. Salir"<<endl;
            cin>>opt;
            menu = true;

            switch(opt){
                case 1: //ARTICULOS
                    submenuArt = false;
                    while(submenuArt == false){
                        submenu();
                        cin>>subopt;
                        submenuArt = true;
                        switch(subopt){
                            case 1: //alta
                                if(altaCheck == 0){
                                    altaCheck++;
                                    for(int i = 0; i < arrSize; i++){
                                        cout<<"*** Articulo #"<<(i+1)<<" ***"<<endl;
                                        idArtCheck = false;
                                        while(idArtCheck == false){
                                            cout<<"ID del articulo: ";
                                            cin>>arrA[i].id;
                                            fflush(stdin);
                                            if(i == 0){
                                                idArtCheck = true;
                                            }
                                            else{
                                                for(int j = 0; j < arrSize; j++){
                                                    if(i != j){
                                                        if(arrA[i].id == arrA[j].id){
                                                            cout<<"ID del articulo repetido! Por favor, introduce uno diferente."<<endl;
                                                            idArtCheck = false;
                                                            break;
                                                        }
                                                        else{
                                                            idArtCheck = true;
                                                        }
                                                    }
                                                }
                                            }
                                        }
                                        cout<<"Nombre del articulo: ";
                                        cin>>arrA[i].art;
                                        fflush(stdin);
                                        cout<<"Descripcion del articulo: ";
                                        //cin>>arrA[i].desc;
                                        getline(cin, arrA[i].desc);
                                        fflush(stdin);
                                        costoCheck = false;
                                        while(costoCheck == false){
                                            cout<<"Costo por unidad: ";
                                            cin>>arrA[i].cost;
                                            if(arrA[i].cost <= 0){
                                                cout<<"Por favor, introduzca un costo valido!"<<endl;
                                            }
                                            else{
                                                costoCheck = true;
                                            }
                                        }
                                        exstCheck = false;
                                        while(exstCheck == false){
                                            cout<<"Existencias del articulo: ";
                                            cin>>arrA[i].exst;
                                            if(arrA[i].exst <= 0){
                                                cout<<"Por favor, introduzca una cantidad valida!"<<endl;
                                            }
                                            else{
                                                exstCheck = true;
                                            }
                                        }
                                        minCheck = false;
                                        while(minCheck == false){
                                            cout<<"Minimo de existencias del articulo: ";
                                            cin>>arrA[i].min;
                                            if(arrA[i].min <= 0){
                                                cout<<"Por favor, introduzca una cantidad valida!"<<endl;
                                            }
                                            else{
                                                minCheck = true;
                                            }
                                        }
                                    }
                                }
                                else{
                                    cout<<"La lista de articulos ya ha sido dada de alta. Si lo desea, puede actualizar alguno de los articulos por separado."<<endl<<endl;
                                }
                                break;
                            case 2: //actualizacion
                                actuArtCheck = false;
                                while(actuArtCheck == false){
                                    cout<<"Seleccione el numero del articulo que desea modificar:"<<endl<<endl;
                                    for(int i = 0; i < arrSize; i++){
                                        cout<<i+1<<". "<<arrA[i].art<<endl;
                                    }
                                    cin>>actuArt; //articulo a actualizar
                                    if(actuArt < 1 || actuArt > 10){
                                        cout<<"Por favor, seleccione una opcion valida!"<<endl;
                                    }
                                    else{
                                        actuArtCheck = true;
                                        cout<<"*** Articulo #"<<(actuArt+1)<<" ***"<<endl<<endl;
                                        actuArtCheck2 = false;
                                        while(actuArtCheck2 == false){
                                            cout<<"Seleccione el parametro que desea modificar: "<<endl;
                                            cout<<"1. ID del articulo."<<endl;
                                            cout<<"2. Nombre del articulo."<<endl;
                                            cout<<"3. Descripcion del articulo."<<endl;
                                            cout<<"4. Costo por unidad."<<endl;
                                            cout<<"5. Existencias del articulo."<<endl;
                                            cout<<"6. Minimo de existencias del articulo."<<endl;
                                            cin>>actuArtPar; //parametro a actualizar
                                            actuArtCheck2 = true;
                                            switch(actuArtPar){
                                                case 1:
                                                    cout<<"ID actual del articulo: "<<arrA[actuArt-1].id<<endl;
                                                    cout<<"Nuevo ID del articulo: ";
                                                    cin>>arrA[actuArt-1].id;
                                                    fflush(stdin);
                                                    break;
                                                case 2:
                                                    cout<<"Nombre actual del articulo: "<<arrA[actuArt-1].art<<endl;
                                                    cout<<"Nuevo nombre del articulo: ";
                                                    cin>>arrA[actuArt-1].art;
                                                    fflush(stdin);
                                                    break;
                                                case 3:
                                                    cout<<"Descripcion actual del articulo: "<<arrA[actuArt-1].desc<<endl;
                                                    cout<<"Nueva descripcion del articulo: ";
                                                    getline(cin, arrA[actuArt-1].desc);
                                                    fflush(stdin);
                                                    break;
                                                case 4:
                                                    cout<<"Costo por unidad actual: "<<arrA[actuArt-1].cost<<endl;
                                                    cout<<"Nuevo costo por unidad: ";
                                                    cin>>arrA[actuArt-1].cost;
                                                    break;
                                                case 5:
                                                    cout<<"Existencias actuales del articulo: "<<arrA[actuArt-1].exst<<endl;
                                                    cout<<"Nuevas existencias del articulo: ";
                                                    cin>>arrA[actuArt-1].exst;
                                                    break;
                                                case 6:
                                                    cout<<"Minimo de existencias actual del articulo: "<<arrA[actuArt-1].min<<endl;
                                                    cout<<"Nuevo minimo de existencias del articulo: ";
                                                    cin>>arrA[actuArt-1].min;
                                                    break;
                                                default:
                                                    cout<<"Por favor, seleccione una opcion valida!"<<endl;
                                                    actuArtCheck2 = false;
                                            } //end switch
                                        } //end while
                                    } //end else
                                } //end while
                                break;
                            case 3: //baja
                                bajaArtCheck = false;
                                while(bajaArtCheck == false){
                                    cout<<"Seleccione el numero del articulo que desea dar de baja:"<<endl;
                                    for(int i = 0; i < arrSize; i++){
                                        cout<<i+1<<". "<<arrA[i].art<<endl;
                                    }
                                    cin>>bajaArt;
                                    if(bajaArt < 1 || bajaArt > 10){
                                        cout<<"Por favor, seleccione una opcion valida!"<<endl;
                                    }
                                    else{
                                        bajaArtCheck = true;
                                        arrA[bajaArt-1].id = " ";
                                        arrA[bajaArt-1].art = " ";
                                        arrA[bajaArt-1].desc = " ";
                                        arrA[bajaArt-1].cost = 0;
                                        arrA[bajaArt-1].exst = 0;
                                        arrA[bajaArt-1].min = 0;
                                        for(int i = bajaArt-1; i < arrSize-1; i++){ //recorrer restantes
                                            swap(arrA[i].id, arrA[i+1].id);
                                            swap(arrA[i].art, arrA[i+1].art);
                                            swap(arrA[i].desc, arrA[i+1].desc);
                                            swap(arrA[i].cost, arrA[i+1].cost);
                                            swap(arrA[i].exst, arrA[i+1].exst);
                                            swap(arrA[i].min, arrA[i+1].min);
                                        }
                                    }
                                }
                                break;
                            case 4: //consulta
                                printArrA(arrSize, arrA);
                                break;
                            default:
                                cout<<"Por favor, seleccione una opcion valida!"<<endl;
                                submenuArt = false;
                        }//end switch
                    }//end while
                    break;
                case 2: //CLIENTES
                    submenuCli = false;
                    while(submenuCli == false){
                        submenu();
                        cin>>subopt;
                        submenuCli = true;
                        switch(subopt){
                            case 1: //alta
                                if(clNum == arrSize){
                                    cout<<"Lista de clientes llena! Por favor, da de baja un cliente si deseas agregar uno nuevo."<<endl;
                                }
                                else{
                                    arrB[clNum].idCli = (clNum+1);
                                    cout<<"ID del cliente: "<<arrB[clNum].idCli<<endl;
                                    cout<<"Nombre: ";
                                    cin>>arrB[clNum].nombre;
                                    fflush(stdin);
                                    cout<<"Apellido paterno: ";
                                    cin>>arrB[clNum].apPat;
                                    fflush(stdin);
                                    cout<<"Apellido materno: ";
                                    cin>>arrB[clNum].apMat;
                                    fflush(stdin);
                                    cout<<"Direccion: ";
                                    getline(cin, arrB[clNum].dir);
                                    fflush(stdin);
                                    cout<<"Correo electronico: ";
                                    cin>>arrB[clNum].email;
                                    fflush(stdin);
                                    cout<<"Numero de telefono: ";
                                    cin>>arrB[clNum].tel;
                                    fflush(stdin);
                                    cout<<"RFC: ";
                                    cin>>arrB[clNum].rfc;
                                    fflush(stdin);
                                    clNum++;
                                }
                                break;
                            case 2: //actualizacion
                                actuCliCheck = false;
                                while(actuCliCheck == false){
                                    cout<<"Introduzca el numero del cliente que desea modificar:"<<endl<<endl;
                                    for(int i = 0; i < clNum; i++){
                                        cout<<i+1<<". "<<arrB[i].nombre<<" "<<arrB[i].apPat<<endl;
                                    }
                                    cin>>actuCli;
                                    if(actuCli < 1 || actuCli > 10){
                                        cout<<"Por favor, seleccione una opcion valida!"<<endl;
                                    }
                                    else{
                                        actuCliCheck = true;
                                        cout<<"*** Cliente: "<<arrB[actuCli-1].nombre<<" "<<arrB[actuCli-1].apPat<<" ***"<<endl<<endl;
                                        actuCliCheck2 = false;
                                        while(actuCliCheck2 == false){
                                            cout<<"Seleccione el parametro que desea modificar: "<<endl;
                                            cout<<"1. Nombre."<<endl;
                                            cout<<"2. Apellido paterno."<<endl;
                                            cout<<"3. Apellido materno."<<endl;
                                            cout<<"4. Direccion."<<endl;
                                            cout<<"5. Correo electronico."<<endl;
                                            cout<<"6. Numero de telefono."<<endl;
                                            cout<<"7. RFC."<<endl;
                                            cin>>actuCliPar;
                                            actuCliCheck2 = true;
                                            switch(actuCliPar){
                                                case 1:
                                                    cout<<"Nombre actual: "<<arrB[actuCli-1].nombre<<endl;
                                                    cout<<"Nuevo nombre: ";
                                                    cin>>arrB[actuCli-1].nombre;
                                                    fflush(stdin);
                                                    break;
                                                case 2:
                                                    cout<<"Apellido paterno actual: "<<arrB[actuCli-1].apPat<<endl;
                                                    cout<<"Nuevo apellido paterno: ";
                                                    cin>>arrB[actuCli-1].apPat;
                                                    fflush(stdin);
                                                    break;
                                                case 3:
                                                    cout<<"Apellido materno actual: "<<arrB[actuCli-1].apMat<<endl;
                                                    cout<<"Nuevo apellido materno: ";
                                                    cin>>arrB[actuCli-1].apMat;
                                                    fflush(stdin);
                                                    break;
                                                case 4:
                                                    cout<<"Direccion actual: "<<arrB[actuCli-1].dir<<endl;
                                                    cout<<"Nueva direccion: ";
                                                    getline(cin, arrB[actuCli-1].dir);
                                                    fflush(stdin);
                                                    break;
                                                case 5:
                                                    cout<<"Correo electroico actual: "<<arrB[actuCli-1].email<<endl;
                                                    cout<<"Nuevo correo electronico: ";
                                                    cin>>arrB[actuCli-1].email;
                                                    fflush(stdin);
                                                    break;
                                                case 6:
                                                    cout<<"Numero de telefono actual: "<<arrB[actuCli-1].tel<<endl;
                                                    cout<<"Nuevo numero de telefono: ";
                                                    cin>>arrB[actuCli-1].tel;
                                                    fflush(stdin);
                                                    break;
                                                case 7:
                                                    cout<<"RFC actual: "<<arrB[actuCli-1].rfc<<endl;
                                                    cout<<"Nuevo RFC: ";
                                                    cin>>arrB[actuCli-1].rfc;
                                                    fflush(stdin);
                                                    break;
                                                default:
                                                    cout<<"Por favor, seleccione una opcion valida!"<<endl;
                                                    actuCliCheck2 = false;
                                            }
                                        }
                                    }
                                }
                                break;
                            case 3: //baja
                                bajaCliCheck = false;
                                while(bajaCliCheck == false){
                                    cout<<"Seleccione el numero del cliente que desea dar de baja:"<<endl;
                                    for(int i = 0; i < clNum; i++){
                                        cout<<i+1<<". "<<arrB[i].nombre<<" "<<arrB[i].apPat<<endl;
                                    }
                                    cin>>bajaCli;
                                    if(bajaCli < 1 || bajaCli > 10){
                                        cout<<"Por favor, seleccione una opcion valida!"<<endl;
                                    }
                                    else{
                                        bajaCliCheck = true;
                                        arrB[bajaCli-1].idCli = 0;
                                        arrB[bajaCli-1].nombre = " ";
                                        arrB[bajaCli-1].apPat = " ";
                                        arrB[bajaCli-1].apMat = " ";
                                        arrB[bajaCli-1].dir = " ";
                                        arrB[bajaCli-1].email = " ";
                                        arrB[bajaCli-1].tel = " ";
                                        arrB[bajaCli-1].rfc = " ";
                                        for(int i = bajaCli-1; i < clNum; i++){
                                            swap(arrB[i].nombre, arrB[i+1].nombre);
                                            swap(arrB[i].apPat, arrB[i+1].apPat);
                                            swap(arrB[i].apMat, arrB[i+1].apMat);
                                            swap(arrB[i].dir, arrB[i+1].dir);
                                            swap(arrB[i].email, arrB[i+1].email);
                                            swap(arrB[i].tel, arrB[i+1].tel);
                                            swap(arrB[i].rfc, arrB[i+1].rfc);
                                        }
                                        clNum--;
                                    }
                                }
                                break;
                            case 4: //consulta
                                printArrB(clNum, arrB);
                                break;
                            default:
                                cout<<"Por favor, seleccione una opcion valida!"<<endl;
                                submenuCli = false;
                        }
                    }
                    break;
                case 3: //VENTA
                    contadorCarr = 0;
                    for(int i = 0; i < arrSize; i++){
                    	for(int j = 0; j < 2; j++){
                    		carrito[i][j] = 0;	
						}
                    }
                    selArts = false;
                    while(selArts == false){
                        cout<<"Que articulo desea comprar?"<<endl;
                        for(int i = 0; i < arrSize; i++){
                            cout<<i+1<<". "<<arrA[i].art<<": "<<arrA[i].desc<<". ($"<<arrA[i].cost<<" c/u)"<<endl;
                        }
                        cin>>carrito[contadorCarr][0];
                        exstCheckVenta = false;
                        while(exstCheckVenta == false){
                            cout<<"Unidades disponibles: "<<arrA[carrito[contadorCarr][0]-1].exst<<endl;
                            cout<<"Cuantas unidades desea adquirir? ";
                            cin>>carrito[contadorCarr][1];
                            if(carrito[contadorCarr][1] > arrA[carrito[contadorCarr][0]-1].exst){
                                cout<<"Por favor, introduce una cantidad dentro de las disponibles! ("<<arrA[carrito[contadorCarr][0]-1].exst<<")"<<endl<<endl;
                            }
                            else{
                                exstCheckVenta = true;
                                arrA[carrito[contadorCarr][0]-1].exst = arrA[carrito[contadorCarr][0]-1].exst - carrito[contadorCarr][1];
                                if(arrA[carrito[contadorCarr][0]-1].exst < arrA[carrito[contadorCarr][0]-1].min){
                                    cout<<"Las unidades disponibles estan por debajo del minimo! ("<<arrA[carrito[contadorCarr][0]-1].min<<") Se recomienda realizar un pedido."<<endl;
                                }
                            }
                        }
                        selArtsCheck = false;
                        while(selArtsCheck == false){
                            cout<<"Desea agregar otro articulo a su carrito? (S/n)";
                            cin>>selArtsChar;
                            if(selArtsChar == 'S' || selArtsChar == 's'){
                                selArtsCheck = true;
                                contadorCarr++;
                            }
                            else if(selArtsChar == 'N' || selArtsChar == 'n'){
                                selArts = true;
                                selArtsCheck = true;
                            }
                            else{
                                cout<<"Por favor, introduzca una opcion valida!"<<endl;
                            }
                        }
                    }
                    subtotal = 0;
                    for(int i = 0; i < arrSize; i++){ 
                    	int indexArt = carrito[i][0] - 1;
                    	int unidades = carrito[i][1];
                    	if(indexArt >= 0 && indexArt < arrSize){
                    		int precioUnidad = arrA[indexArt].cost;
                    		int sumaPrecios = precioUnidad * unidades;
                    		subtotal += sumaPrecios;
						}
					}
                    cout<<"Procesando pedido..."<<endl;
                    Sleep(1000);
                    cout<<"Subtotal: $"<<subtotal<<endl;
                    cliCharCheck = false;
                    while(cliCharCheck == false){
                        cout<<"Ya es cliente? S/n"<<endl;
                        cin>>cliChar;
                        if(cliChar == 'S' || cliChar == 's'){
                        	if(clNum == 0){
                        		cout<<"No hay ningun cliente registrado!"<<endl;
							}
							else{
								cliCharCheck = true;
                            	cliSelCheck = false;
                            	while(cliSelCheck == false){
                                	for(int i = 0; i < clNum; i++){
                                   		cout<<i+1<<". "<<arrB[i].nombre<<" "<<arrB[i].apPat<<endl;
                               		}
                                	cin>>cliSel;
                                	if(cliSel < 1 || cliSel > 10){
                                    	cout<<"Por favor, seleccione una opcion valida!"<<endl;
                                	}
                                	else{
                                    	cliSelCheck = true;
                                    	cout<<"Bienvenido, cliente: "<<arrB[cliSel-1].nombre<<" "<<arrB[cliSel-1].apPat<<endl;
                                    	nuevoCli = false;
                                	}
                            	}	
							}
                            
                        }
                        else if(cliChar == 'N' || cliChar == 'n'){
                            cliCharCheck = true;
                            if(clNum == arrSize){
                                cout<<"Lista de clientes llena! Por favor, da de baja un cliente si deseas agregar uno nuevo."<<endl;
                                arrBfull = true;
								break;
                            }
                            else{
                                arrB[clNum].idCli = (clNum+1);
                                cout<<"ID del cliente: "<<arrB[clNum].idCli<<endl;
                                cout<<"Nombre: ";
                                cin>>arrB[clNum].nombre;
                                fflush(stdin);
                                cout<<"Apellido paterno: ";
                                cin>>arrB[clNum].apPat;
                                fflush(stdin);
                                cout<<"Apellido materno: ";
                                cin>>arrB[clNum].apMat;
                                fflush(stdin);
                                cout<<"Direccion: ";
                                getline(cin, arrB[clNum].dir);
                                fflush(stdin);
                                cout<<"Correo electronico: ";
                                cin>>arrB[clNum].email;
                                fflush(stdin);
                                cout<<"Numero de telefono: ";
                                cin>>arrB[clNum].tel;
                                fflush(stdin);
                                cout<<"RFC: ";
                                cin>>arrB[clNum].rfc;
                                fflush(stdin);
                                clNum++;
                                nuevoCli = true;
                            }
                        }
                        else{
                            cout<<"Por favor, introduce una opcion valida!"<<endl;
                        }
                    }
                    facTicCheck = false;
                    if(arrBfull == true){
                    	facTicCheck = true;
					}
                    while(facTicCheck == false){
                        cout<<"Requiere factura o solo ticket?"<<endl;
                        cout<<"1. Factura"<<endl;
                        cout<<"2. Ticket"<<endl;
                        cin>>facTic;
                        facTicCheck = true;
                        switch(facTic){
                            case 1:
                                facSoli = true;
                                if(nuevoCli == true){
                                    arrD[facturas].idCli = arrB[clNum-1].idCli;
                                    cout<<"ID del cliente: "<<arrD[facturas].idCli<<endl;
                                    arrD[facturas].rfc = arrB[clNum-1].rfc;
                                    cout<<"RFC: "<<arrD[facturas].rfc<<endl;
                                    cout<<"Fecha: ";
                                    cin>>arrD[facturas].fecha;
                                    fflush(stdin);
                                    cout<<"Razon social: ";
                                    cin>>arrD[facturas].razSoc;
                                    fflush(stdin);
                                    cout<<"Uso CFDI: "<<endl;
                                    printArrC(arrC);
                                    cin>>cfdiSel;
                                    arrD[facturas].usoCFDI = arrC[cfdiSel-1].idCFDI;
                                    facturas++;
                                    cout<<"La siguiente informacion sera enviada a: "<<arrB[clNum-1].email<<endl;
                                }
                                else{
                                    arrD[facturas].idCli = arrB[cliSel-1].idCli;
                                    cout<<"ID del cliente: "<<arrD[facturas].idCli<<endl;
                                    arrD[facturas].rfc = arrB[cliSel-1].rfc;
                                    cout<<"RFC: "<<arrD[facturas].rfc<<endl;
                                    cout<<"Fecha: ";
                                    cin>>arrD[facturas].fecha;
                                    fflush(stdin);
                                    cout<<"Razon social: ";
                                    cin>>arrD[facturas].razSoc;
                                    fflush(stdin);
                                    cout<<"Uso CFDI: "<<endl;
                                    printArrC(arrC);
                                    cin>>cfdiSel;
                                    arrD[facturas].usoCFDI = arrC[cfdiSel-1].idCFDI;
                                    facturas++;
                                    cout<<"La siguiente informacion sera enviada a: "<<arrB[cliSel-1].email<<endl;
                                }
                                total = 0;
                                total = subtotal + (subtotal * 0.16);
                                cout<<"Total = $"<<subtotal<<" (subtotal) + $"<<(subtotal*0.16)<<" (IVA) = "<<total<<endl;
                                cout<<"Razon social: "<<arrD[facturas-1].razSoc<<endl;
                                cout<<"Uso CFDI: "<<arrD[facturas-1].usoCFDI<<endl;
                                cout<<"Fecha: "<<arrD[facturas-1].fecha<<endl;
                                cout<<"RFC: "<<arrD[facturas-1].rfc<<endl;
                                break;
                            case 2:
                            	facSoli = false;
                                {
	                                time_t now = time(0);
	                                char* dt = ctime(&now);
	                                if(nuevoCli == true){
	                                	cout<<"__________________________________________________"<<endl;
	                                	cout<<"|                                                |"<<endl;
	                                	cout<<"|                                                |"<<endl;
	                                	cout<<"|          "<<dt<<"|"<<endl;
	                                	cout<<"|                                                |"<<endl;
	                                	cout<<"|          Cliente: "<<arrB[clNum-1].nombre<<" "<<arrB[clNum-1].apPat<<endl;
	    	                            cout<<"|                                                |"<<endl;
	        	                        cout<<"|          Total: $"<<subtotal<<endl;
	            	                    cout<<"|                                                |"<<endl;
	                	                cout<<"__________________________________________________"<<endl;
	                                }
									else{
										cout<<"__________________________________________________"<<endl;
	                                	cout<<"|                                                |"<<endl;
	                                	cout<<"|                                                |"<<endl;
	                                	cout<<"|          "<<dt<<"|"<<endl;
	                                	cout<<"|                                                |"<<endl;
	                                	cout<<"|          Cliente: "<<arrB[cliSel-1].nombre<<" "<<arrB[cliSel-1].apPat<<endl;
	    	                            cout<<"|                                                |"<<endl;
	        	                        cout<<"|          Total: $"<<subtotal<<endl;
	            	                    cout<<"|                                                |"<<endl;
	                	                cout<<"__________________________________________________"<<endl;
									}
								}
                                break;
                            default:
                                cout<<"Por favor, seleccione una opcion valida!"<<endl;
                                facTicCheck = false;
                        }
                    }
                    pagoCheck = false;
                    if(arrBfull == true){
                    	pagoCheck = true;
					}
                    while(pagoCheck == false){
                        cout<<"Seleccione su metodo de pago: "<<endl;
                        cout<<"1. Tarjeta"<<endl;
                        cout<<"2. Efectivo"<<endl;
                        cin>>pago;
                        pagoCheck = true;
                        switch(pago){
                            case 1:
                                cout<<"Ingrese los datos de su tarjeta a continuacion:"<<endl;
                                cout<<"Numero de tarjeta (XXXX-XXXX-XXXX-XXXX): ";
                                cin>>numTar;
                                fflush(stdin);
                                cout<<"CVV: ";
                                cin>>cvv;
                                fflush(stdin);
                                if(facSoli == true){
                                    cout<<"Usted esta por pagar $"<<total<<endl;
                                    Sleep(1000);
                                    cout<<"Compra realizada con exito!"<<endl<<endl;
                                }
                                else{
                                    cout<<"Usted esta por pagar "<<subtotal<<endl;
                                    Sleep(1000);
                                    cout<<"Compra realizada con exito!"<<endl<<endl;
                                }
                                break;
                            case 2:
                                for(int i = 0; i < 6; i++){
                                    for(int j = 0; j < 2; j++){
                                        billetes[i][j] = 0;
                                    }
                                }
                                billCheck = false;
                                while(billCheck == false){
                                    cout<<"Utilizara billetes para pagar? (S/n)";
                                    cin>>usaBill;
                                    if(usaBill == 'S' || usaBill == 's'){
                                        billCheck = true;
                                        billetesRpt = false;
                                        for(int i = 0; billetesRpt == false && i < 6; i++){
                                            denoBillCheck = false;
                                            while(denoBillCheck == false){
                                                cout<<"Denominacion del billete: (20, 50, 100, 200, 500 o 1000 pesos) ";
                                                cin>>billetes[i][0];

                                                if(billetes[i][0] == 20){
                                                    cantBillCheck = false;
                                                    while(cantBillCheck == false){
                                                        cout<<"Cuantos billetes de $20 utilizara? ";
                                                        cin>>billetes[i][1];
                                                        if(billetes[i][1] < 0){
                                                            cout<<"Por favor, introduce una cantidad valida!"<<endl;
                                                        }
                                                        else{
                                                            cantBillCheck = true;
                                                            otroBillCheck = false;
                                                            while(otroBillCheck == false){
                                                                cout<<"Pagara con algun otro billete de diferente denominacion? (S/n)";
                                                                cin>>otroBill;
                                                                if(otroBill == 'S' || otroBill == 's'){
                                                                    otroBillCheck = true;
                                                                    denoBillCheck = true;
                                                                }
                                                                else if(otroBill == 'N' || otroBill == 'n'){
                                                                    otroBillCheck = true;
                                                                    denoBillCheck = true;
                                                                    billetesRpt = true;
                                                                }
                                                                else{
                                                                    cout<<"Por favor, introduce una opcion valida!"<<endl;
                                                                }
                                                            }
                                                        }
                                                    }
                                                }
                                                else if(billetes[i][0] == 50){
                                                    cantBillCheck = false;
                                                    while(cantBillCheck == false){
                                                        cout<<"Cuantos billetes de $50 utilizara? ";
                                                        cin>>billetes[i][1];
                                                        if(billetes[i][1] < 0){
                                                            cout<<"Por favor, introduce una cantidad valida!"<<endl;
                                                        }
                                                        else{
                                                            cantBillCheck = true;
                                                            otroBillCheck = false;
                                                            while(otroBillCheck == false){
                                                                cout<<"Pagara con algun otro billete de diferente denominacion? (S/n)";
                                                                cin>>otroBill;
                                                                if(otroBill == 'S' || otroBill == 's'){
                                                                    otroBillCheck = true;
                                                                    denoBillCheck = true;
                                                                }
                                                                else if(otroBill == 'N' || otroBill == 'n'){
                                                                    otroBillCheck = true;
                                                                    denoBillCheck = true;
                                                                    billetesRpt = true;
                                                                }
                                                                else{
                                                                    cout<<"Por favor, introduce una opcion valida!"<<endl;
                                                                }
                                                            }
                                                        }
                                                    }
                                                }
                                                else if(billetes[i][0] == 100){
                                                    cantBillCheck = false;
                                                    while(cantBillCheck == false){
                                                        cout<<"Cuantos billetes de $100 utilizara? ";
                                                        cin>>billetes[i][1];
                                                        if(billetes[i][1] < 0){
                                                            cout<<"Por favor, introduce una cantidad valida!"<<endl;
                                                        }
                                                        else{
                                                            cantBillCheck = true;
                                                            otroBillCheck = false;
                                                            while(otroBillCheck == false){
                                                                cout<<"Pagara con algun otro billete de diferente denominacion? (S/n)";
                                                                cin>>otroBill;
                                                                if(otroBill == 'S' || otroBill == 's'){
                                                                    otroBillCheck = true;
                                                                    denoBillCheck = true;
                                                                }
                                                                else if(otroBill == 'N' || otroBill == 'n'){
                                                                    otroBillCheck = true;
                                                                    denoBillCheck = true;
                                                                    billetesRpt = true;
                                                                }
                                                                else{
                                                                    cout<<"Por favor, introduce una opcion valida!"<<endl;
                                                                }
                                                            }
                                                        }
                                                    }
                                                }
                                                else if(billetes[i][0] == 200){
                                                    cantBillCheck = false;
                                                    while(cantBillCheck == false){
                                                        cout<<"Cuantos billetes de $200 utilizara? ";
                                                        cin>>billetes[i][1];
                                                        if(billetes[i][1] < 0){
                                                            cout<<"Por favor, introduce una cantidad valida!"<<endl;
                                                        }
                                                        else{
                                                            cantBillCheck = true;
                                                            otroBillCheck = false;
                                                            while(otroBillCheck == false){
                                                                cout<<"Pagara con algun otro billete de diferente denominacion? (S/n)";
                                                                cin>>otroBill;
                                                                if(otroBill == 'S' || otroBill == 's'){
                                                                    otroBillCheck = true;
                                                                    denoBillCheck = true;
                                                                }
                                                                else if(otroBill == 'N' || otroBill == 'n'){
                                                                    otroBillCheck = true;
                                                                    denoBillCheck = true;
                                                                    billetesRpt = true;
                                                                }
                                                                else{
                                                                    cout<<"Por favor, introduce una opcion valida!"<<endl;
                                                                }
                                                            }
                                                        }
                                                    }
                                                }
                                                else if(billetes[i][0] == 500){
                                                    cantBillCheck = false;
                                                    while(cantBillCheck == false){
                                                        cout<<"Cuantos billetes de $500 utilizara? ";
                                                        cin>>billetes[i][1];
                                                        if(billetes[i][1] < 0){
                                                            cout<<"Por favor, introduce una cantidad valida!"<<endl;
                                                        }
                                                        else{
                                                            cantBillCheck = true;
                                                            otroBillCheck = false;
                                                            while(otroBillCheck == false){
                                                                cout<<"Pagara con algun otro billete de diferente denominacion? (S/n)";
                                                                cin>>otroBill;
                                                                if(otroBill == 'S' || otroBill == 's'){
                                                                    otroBillCheck = true;
                                                                    denoBillCheck = true;
                                                                }
                                                                else if(otroBill == 'N' || otroBill == 'n'){
                                                                    otroBillCheck = true;
                                                                    denoBillCheck = true;
                                                                    billetesRpt = true;
                                                                }
                                                                else{
                                                                    cout<<"Por favor, introduce una opcion valida!"<<endl;
                                                                }
                                                            }
                                                        }
                                                    }
                                                }
                                                else if(billetes[i][0] == 1000){
                                                    cantBillCheck = false;
                                                    while(cantBillCheck == false){
                                                        cout<<"Cuantos billetes de $1000 utilizara? ";
                                                        cin>>billetes[i][1];
                                                        if(billetes[i][1] < 0){
                                                            cout<<"Por favor, introduce una cantidad valida!"<<endl;
                                                        }
                                                        else{
                                                            cantBillCheck = true;
                                                            otroBillCheck = false;
                                                            while(otroBillCheck == false){
                                                                cout<<"Pagara con algun otro billete de diferente denominacion? (S/n)";
                                                                cin>>otroBill;
                                                                if(otroBill == 'S' || otroBill == 's'){
                                                                    otroBillCheck = true;
                                                                    denoBillCheck = true;
                                                                }
                                                                else if(otroBill == 'N' || otroBill == 'n'){
                                                                    otroBillCheck = true;
                                                                    denoBillCheck = true;
                                                                    billetesRpt = true;
                                                                }
                                                                else{
                                                                    cout<<"Por favor, introduce una opcion valida!"<<endl;
                                                                }
                                                            }
                                                        }
                                                    }
                                                }
                                                else{
                                                    cout<<"Por favor, introduzca una opcion valida!"<<endl;
                                                }
                                            }
                                        }
                                    }
                                    else if(usaBill == 'N' || usaBill == 'n'){
                                        billCheck = true;
                                    }
                                    else{
                                        cout<<"Por favor, introduzca una opcion valida!"<<endl;
                                    }
                                }

                                for(int i = 0; i < 4; i++){
                                    for(int j = 0; j < 2; j++){
                                        monedas[i][j] = 0;
                                    }
                                }
                                monCheck = false;
                                while(monCheck == false){
                                    cout<<"Utilizara monedas para pagar? (S/n)";
                                    cin>>usaMon;
                                    if(usaMon == 'S' || usaMon == 's'){
                                        monCheck = true;
                                        monedasRpt = false;
                                        for(int i = 0; monedasRpt == false && i < 4; i++){
                                            denoMonCheck = false;
                                            while(denoMonCheck == false){
                                                cout<<"Denominacion de la moneda: (1, 2, 5 o 10 pesos) ";
                                                cin>>monedas[i][0];

                                                if(monedas[i][0] == 1){
                                                    cantMonCheck = false;
                                                    while(cantMonCheck == false){
                                                        cout<<"Cuantas monedas de $1 utilizara? ";
                                                        cin>>monedas[i][1];
                                                        if(monedas[i][1] < 0){
                                                            cout<<"Por favor, introduce una cantidad valida!"<<endl;
                                                        }
                                                        else{
                                                            cantMonCheck = true;
                                                            otraMonCheck = false;
                                                            while(otraMonCheck == false){
                                                                cout<<"Pagara con alguna otra moneda de diferente denominacion? (S/n)";
                                                                cin>>otraMon;
                                                                if(otraMon == 'S' || otraMon == 's'){
                                                                    otraMonCheck = true;
                                                                    denoMonCheck = true;
                                                                }
                                                                else if(otraMon == 'N' || otraMon == 'n'){
                                                                    otraMonCheck = true;
                                                                    denoMonCheck = true;
                                                                    monedasRpt = true;
                                                                }
                                                                else{
                                                                    cout<<"Por favor, introduce una opcion valida!"<<endl;
                                                                }
                                                            }
                                                        }
                                                    }
                                                }
                                                else if(monedas[i][0] == 2){
                                                    cantMonCheck = false;
                                                    while(cantMonCheck == false){
                                                        cout<<"Cuantas monedas de $2 utilizara? ";
                                                        cin>>monedas[i][1];
                                                        if(monedas[i][1] < 0){
                                                            cout<<"Por favor, introduce una cantidad valida!"<<endl;
                                                        }
                                                        else{
                                                            cantMonCheck = true;
                                                            otraMonCheck = false;
                                                            while(otraMonCheck == false){
                                                                cout<<"Pagara con alguna otra moneda de diferente denominacion? (S/n)";
                                                                cin>>otraMon;
                                                                if(otraMon == 'S' || otraMon == 's'){
                                                                    otraMonCheck = true;
                                                                    denoMonCheck = true;
                                                                }
                                                                else if(otraMon == 'N' || otraMon == 'n'){
                                                                    otraMonCheck = true;
                                                                    denoMonCheck = true;
                                                                    monedasRpt = true;
                                                                }
                                                                else{
                                                                    cout<<"Por favor, introduce una opcion valida!"<<endl;
                                                                }
                                                            }
                                                        }
                                                    }
                                                }
                                                else if(monedas[i][0] == 5){
                                                    cantMonCheck = false;
                                                    while(cantMonCheck == false){
                                                        cout<<"Cuantas monedas de $5 utilizara? ";
                                                        cin>>monedas[i][1];
                                                        if(monedas[i][1] < 0){
                                                            cout<<"Por favor, introduce una cantidad valida!"<<endl;
                                                        }
                                                        else{
                                                            cantMonCheck = true;
                                                            otraMonCheck = false;
                                                            while(otraMonCheck == false){
                                                                cout<<"Pagara con alguna otra moneda de diferente denominacion? (S/n)";
                                                                cin>>otraMon;
                                                                if(otraMon == 'S' || otraMon == 's'){
                                                                    otraMonCheck = true;
                                                                    denoMonCheck = true;
                                                                }
                                                                else if(otraMon == 'N' || otraMon == 'n'){
                                                                    otraMonCheck = true;
                                                                    denoMonCheck = true;
                                                                    monedasRpt = true;
                                                                }
                                                                else{
                                                                    cout<<"Por favor, introduce una opcion valida!"<<endl;
                                                                }
                                                            }
                                                        }
                                                    }
                                                }
                                                else if(monedas[i][0] == 10){
                                                    cantMonCheck = false;
                                                    while(cantMonCheck == false){
                                                        cout<<"Cuantas monedas de $10 utilizara? ";
                                                        cin>>monedas[i][1];
                                                        if(monedas[i][1] < 0){
                                                            cout<<"Por favor, introduce una cantidad valida!"<<endl;
                                                        }
                                                        else{
                                                            cantMonCheck = true;
                                                            otraMonCheck = false;
                                                            while(otraMonCheck == false){
                                                                cout<<"Pagara con alguna otra moneda de diferente denominacion? (S/n)";
                                                                cin>>otraMon;
                                                                if(otraMon == 'S' || otraMon == 's'){
                                                                    otraMonCheck = true;
                                                                    denoMonCheck = true;
                                                                }
                                                                else if(otraMon == 'N' || otraMon == 'n'){
                                                                    otraMonCheck = true;
                                                                    denoMonCheck = true;
                                                                    monedasRpt = true;
                                                                }
                                                                else{
                                                                    cout<<"Por favor, introduce una opcion valida!"<<endl;
                                                                }
                                                            }
                                                        }
                                                    }
                                                }

                                                else{
                                                    cout<<"Por favor, introduzca una opcion valida!"<<endl;
                                                }
                                            }
                                        }
                                    }
                                    else if(usaMon == 'N' || usaMon == 'n'){
                                        monCheck = true;
                                    }
                                    else{
                                        cout<<"Por favor, introduzca una opcion valida!"<<endl;
                                    }
                                }
								totalBill = 0;
								totalMon = 0;
                                for(int i = 0; i < 6; i++){
                                    totalBill = totalBill + (billetes[i][0] * billetes[i][1]);
                                }
                                for(int i = 0; i < 4; i++){
                                    totalMon = totalMon + (monedas[i][0] * monedas[i][1]);
                                }

                                sumaBillMon = totalBill + totalMon;

                                if(facSoli == true){
                                    if(sumaBillMon < total){
                                        cout<<"Sus billetes y monedas no cubren la cuenta! Por favor, vuelve a ingresar la cantidad de billetes y monedas que utilizaras y su denominacion."<<endl;
                                    }
                                    else{
                                        cambio = sumaBillMon - total;
                                        cout<<"Su cambio es de: $"<<cambio<<endl;
                                        cout<<"Compra realizada con exito!"<<endl<<endl;
                                    }
                                }
                                else{
                                    if(sumaBillMon < subtotal){
                                        cout<<"Sus billetes y monedas no cubren la cuenta! Por favor, vuelve a ingresar la cantidad de billetes y monedas que utilizaras y su denominacion."<<endl;
                                    }
                                    else{
                                        cambio = sumaBillMon - subtotal;
                                        cout<<"Su cambio es de: $"<<cambio<<endl;
                                        cout<<"Compra realizada con exito!"<<endl<<endl;
                                    }
                                }

                                break;
                            default:
                                cout<<"Por favor, seleccione una opcion valida!"<<endl;
                                pagoCheck = false;
                        }
                    }
                    break;
                case 4: //SALIR
                    rpt = true;
                    break;
                default:
                    cout<<"Por favor, seleccione una opcion valida!"<<endl;
                    menu = false;
            }
        }
    }
}

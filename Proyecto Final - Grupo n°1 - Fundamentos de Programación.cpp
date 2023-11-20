#include <iostream>
#include <vector>
#include <string>
#include <conio.h>
#include <windows.h>

using namespace std;

struct Usuario
{
	int     codUsu;
	string  IDUsu;
	string 	passUsu;
	int     tipUsu;
	string  nomUsu;
	string  apeUsu;
	string  telUsu;
};
vector<Usuario> vecUsuario;

struct Producto
{
	int         codProducto;
	string      nomProducto;
	float 		preProducto;
	int         stkProducto;
};
vector<Producto> vecProducto;

struct Venta
{
	int 		codVenta;
	string 		nomVenta;
	int 		cantVenta;
	float       costoVenta;
	float		totalVenta;
};
vector<Venta> vecVenta;

void  	add();
void  	gotoxy(int,int);
void  	validarUsuario();
void  	opcionesVendedor();
void  	addVector();
int  	fin();
int   	getCorrelativo();
void  	buscarPorCodigo();
void  	removeVector();
void  	modifyVector();
int   	obtenerPosArreglo(int);
void  	listOfItems();
void 	opcionesComprador();
void    comprarProducto();
int 	ventCorrelativo();
void 	buscarProducto();
void 	modifyCompra();
void 	listCompra();
float   ventaProducto();
float   ventaTotal();
void    finCompra();



int main(int argc, char *argv[])
{
	add();
	validarUsuario();
	return 0;
}
void add()
{
	vecUsuario.push_back({1,"ddiaz","canon",1,"Daniel","Diaz","934812934"});
	vecUsuario.push_back({2,"svega","678",1,"Sergio","Vega","959415942"});
	vecUsuario.push_back({3,"mramon","rondon",2,"Marco","Ramon","922626987"});
	vecUsuario.push_back({4,"rescuadra","dota",2,"Renso","Escuadra","970689201"});
	vecUsuario.push_back({5,"jtavara","lol",1,"Julio","Tavara","981290963"});
	vecUsuario.push_back({6,"ssaldias","ga",2,"Sebastian","Saldias","942397861"});
	vecProducto.push_back({1,"MemoriaRAM",100,50});
	vecProducto.push_back({2,"SSD",150,40});
	vecProducto.push_back({3,"DiscoDuro",125,45});
	vecProducto.push_back({4,"USB",30,35});
	vecProducto.push_back({5,"Mouse",100,60});
	vecProducto.push_back({6,"Teclado",200,20});
}
void validarUsuario()
{
	int intentosMaximos = 3;
	for (int intento = 1; intento <= intentosMaximos; ++intento)
	{
		system("cls");
		string input_username = "";
		string input_password = "";
		bool loginExitoso = false;
		gotoxy(48,1);cout << "ACCESO AL SISTEMA\n";
		gotoxy(40,2);cout << "INTENTO: " << intento << "/" << intentosMaximos << endl;	
		gotoxy(40,3);cout << "USUARIO: ";
		cin >> input_username;
		gotoxy(40,4);cout << "CONTRASEÑA: ";
		char ch;
		while (true)
		{
			ch = getch();
			if (ch == 13)
			{
				break;
				input_password += ch;
				cout << '*';
			}
			else if (ch == 8)
			{  
			if (!input_password.empty())
				{
					input_password.pop_back();
					cout << "\b \b";
				}
			}
			else
			{
				input_password += ch;
				cout << '*';
			}
		}
	for(int i=0;i<vecUsuario.size();i++)
	{
		if(vecUsuario[i].IDUsu == input_username && vecUsuario[i].passUsu == input_password)
		{
			cout << "\n\nInicio de sesion exitoso. Bienvenido, " << vecUsuario[i].nomUsu << " " << vecUsuario[i].apeUsu<<endl;
			loginExitoso = true;
			system("pause");
			system("cls");
			if(vecUsuario[i].tipUsu == 1)
			{
			opcionesComprador();
			cout<<"Gracias por su compra "<<vecUsuario[i].nomUsu<<" "<<vecUsuario[i].apeUsu<<"!!"<<endl;
			cout<<"Le enviaremos el voucher electronico al numero " <<vecUsuario[i].telUsu<<endl;
			}
			if(vecUsuario[i].tipUsu == 2)
			{
			opcionesVendedor();
			}
			break;
		}		
	}
	if (loginExitoso)
	{
		break;
	}
	else
	{
		cout << "\nNombre de usuario y/o contraseña incorrecta. Inicio de sesion fallido." << endl;
		if (intento < intentosMaximos)
		{
			cout << "Intentos restantes: " << intentosMaximos - intento<<endl;
		}
		else
		{
			cout << "Ha alcanzado el número máximo de intentos. El programa se cerrará." << endl;
			return;
		}
	}
	}
}	

void  gotoxy(int x, int y)
{
	HANDLE hcon = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD dwPos;
	dwPos.X = x;
	dwPos.Y = y;
	SetConsoleCursorPosition(hcon,dwPos);
}

void opcionesVendedor()
{
	int opcion;
	do
	{
		gotoxy(52,0);cout << "MENU DE OPCIONES\n";
		gotoxy(45,1);cout << "Agregar Productos__________[1]\n";
		gotoxy(45,2);cout << "Buscar Producto____________[2]\n";
		gotoxy(45,3);cout << "Eliminar Producto__________[3]\n";
		gotoxy(45,4);cout << "Modificar Producto_________[4]\n";
		gotoxy(45,5);cout << "Listar Producto____________[5]\n";
		gotoxy(45,6);cout << "Salir______________________[6]\n";
		gotoxy(45,7);cout << "Ingrese una opcion[1-6]: ";
		cin >> opcion;
		switch (opcion)
		{
		case 1: system("cls");
				addVector();
				break;
		case 2: system("cls");
				buscarPorCodigo();
				system("pause");
				system("cls");
				break;
		case 3: system("cls");
				removeVector();
				system("pause");
				system("cls");
				break;
		case 4: system("cls");
				modifyVector();
				system("pause");
				system("cls");
				break;
		case 5: system("cls");
				listOfItems();
				system("pause");
				system("cls");
				break;
		case 6: fin();
				break;
		default:cout << "Ingrese una opcion correcta[1-6]\n";
		}
		
	} while (opcion!=6);
}
int fin()
{
	cout<<"Hasta la proxima!!";
	return 1;
}
void addVector()
{

	string      rpta,
				nomPro;
	int         cod,
				stkPro;
	float 		prePro;
	
	do
	{
		cod = getCorrelativo();
		cout << "Codigo: "<<cod<<endl;
		cin.ignore();
		cout << "Nombre: ";
		getline(cin,nomPro);
		cout << "Precio: "; cin >> prePro;
		cout << "Stock: "; cin >> stkPro;
		
		Producto producto;
		producto.codProducto = cod; 
		producto.nomProducto = nomPro;
		producto.preProducto = prePro;
		producto.stkProducto = stkPro;
		
		/*Agregar el registro al arreglo*/
		vecProducto.push_back(producto);
		
		cout << "Deseas continuar registrando productos...(S/s):";
		cin >> rpta;
		
		system("cls");
	} while (rpta == "S" || rpta == "s");
	
}
int getCorrelativo()
{
	if (vecProducto.size() == 0)
	{
		return 1;
	}
	else
	{
		return vecProducto[vecProducto.size()-1].codProducto + 1;
	}
}
void  buscarPorCodigo()
{
	int codigo;
	bool flag = false;
	cout << "Ingrese el codigo a buscar:";
	cin >> codigo;
	for (int i = 0; i < vecProducto.size(); i++)
	{
		if (codigo == vecProducto[i].codProducto)
		{
			cout << "Codigo: " << vecProducto[i].codProducto << endl;
			cout << "Nombre: " << vecProducto[i].nomProducto << endl;
			cout << "Precio: " << vecProducto[i].preProducto << endl;
			cout << "Stock :" << vecProducto[i].stkProducto << endl;
			flag = true;
			break;//Salir del ciclo
		}
	}
	if(flag == false)
	{
		cout<<"El codigo ingresado no existe!!!\n";
	}
}
void removeVector()
{
	int  cod;
	bool flag = false;
	cout<<"Ingrese el codigo del producto a eliminar:";
	cin>>cod;
	for(int i=0;i<vecProducto.size();i++)
	{
		if(cod == vecProducto[i].codProducto)     
		{
			vecProducto.erase(vecProducto.begin() + i);
			flag = true;
			break;
		}
	}
	if(flag == true)
	{
		cout<<"Registro eliminado satisfactoriamente!!!\n";
	}
	else
	{
		cout<<"Codigo ingresado no existe!!!\n";
	}
}
void modifyVector()
{
	int cod,
		posArray,
		opcion;
	string	_nombre;
	float 	_precio;
	int     _stock;
	
	cout<<"Ingrese el codigo del producto a modificar:";              
	cin>>cod;
	posArray = obtenerPosArreglo(cod);
	if(posArray == -1)
	{
		cout<<"El codigo ingreado no existe!!!\n";
	}
	else
	{
		cout<<"--------------------\n";
		cout<<"Registro encontrado\n";
		cout<<"--------------------\n";
		cout<<"Codigo:"<<vecProducto[posArray].codProducto<<endl;                     
		cout<<"Nombre:"<<vecProducto[posArray].nomProducto<<endl;                     
		cout<<"Precio:"<<vecProducto[posArray].preProducto<<endl;                     
		cout<<"Stock:"<<vecProducto[posArray].stkProducto<<endl;                      
		cout<<"--------------------\n";
		cout<<"MINI MENU\n";
		cout<<"Nombre\t\t[1]\n";
		cout<<"Precio\t\t[2]\n";
		cout<<"Stock\t\t[3]\n";
		cout<<"Salir\t\t[4]\n";
		cout<<"Seleccionar una opcion[1-4]:";
		cin>>opcion;
		cin.ignore();
		switch(opcion)
		{
		case 1: cout<<"Cambiar nombre:";
				getline(cin,_nombre);
				vecProducto[posArray].nomProducto = _nombre;
				break;
		case 2: cout<<"Cambiar precio:";
				cin>>_precio;     
				vecProducto[posArray].preProducto = _precio;
				break;
		case 3: cout<<"Cambiar stock:";
				cin>>_stock;      
				vecProducto[posArray].stkProducto = _stock;
				break;
		case 4:	break;
		default:cout<<"Ingrese una opcion correcta[1-4]\n";
		}
	}
}
int   obtenerPosArreglo(int codigo)
{
	for(int i=0;i<vecProducto.size();i++)
	{
		if(codigo == vecProducto[i].codProducto)
		{
			return i;   
		}
	}     
	return -1;
}
void listOfItems()
{
	for (int i = 0; i < vecProducto.size(); i++)
	{
		cout << "-----------------------------------\n";
		cout << "Codigo: " << vecProducto[i].codProducto << endl;
		cout << "Nombre: " << vecProducto[i].nomProducto << endl;
		cout << "Precio: " << vecProducto[i].preProducto << endl;
		cout << "Stock: " << vecProducto[i].stkProducto << endl;
		cout << "-----------------------------------\n";
	}
}
void opcionesComprador()
{
	int opc;
	do
	{
		gotoxy(51,0);cout << "MENU DE OPCIONES\n";
		gotoxy(45,1);cout << "Productos en venta_______[1]\n";
		gotoxy(45,2);cout << "Comprar Producto_________[2]\n";
		gotoxy(45,3);cout << "Modificar Compra_________[3]\n";
		gotoxy(45,4);cout << "Listar Compra____________[4]\n";
		gotoxy(45,5);cout << "Finalizar Compra_________[5]\n";
		gotoxy(45,6);cout << "Anular compra____________[6]\n";
		gotoxy(45,7);cout << "Ingrese una opcion[1-6]: ";
		cin >> opc;
		switch (opc)
		{
		case 1: system("cls");
				listOfItems();
				system("pause");
				system("cls");
				break;
		case 2: system("cls");
				comprarProducto();
				break;
		case 3: system("cls");
				modifyCompra();
				system("pause");
				system("cls");
				break;
		case 4: system("cls");
				listCompra();
				system("pause");
				system("cls");
				break;
		case 5: system("cls");
				listCompra();
				cout << "El coste total a pagar sería: " << ventaTotal() << endl;
				return;
		case 6: cout<<"Su compra ha sido anulada"<<endl;
				fin();
				break;
		default:cout << "Ingrese una opcion correcta[1-6]\n";
		}
		
	} while (opc!=6);
}
void comprarProducto()
{
	int 		cd;
	string		rpta;
	string      nmPro;
	int         cant;
	do
	{
		cd = ventCorrelativo();
		cout << "Codigo de compra: "<<cd<<endl;
		cin.ignore();
		bool nombreValido = false;
		do
		{
			cout << "Producto que desea comprar: ";
			cin >> nmPro;
			
			for (int i = 0; i < vecProducto.size(); i++)
			{
				if (nmPro == vecProducto[i].nomProducto)
				{
					nombreValido = true;
					break;
				}
			}
			
			if (!nombreValido)
			{
				cout << "Nombre de producto no válido. Por favor, ingrese un nombre válido." << endl;
			}
			
		} while (!nombreValido);
		cout <<"Cantidad la cual comprara: ";
		cin >> cant;
		Venta venta;
		venta.codVenta = cd;
		venta.nomVenta = nmPro;
		venta.cantVenta = cant;
		vecVenta.push_back(venta);
		
		float costoProducto = ventaProducto();
		
		cout <<"El costo de esto sería: "<<costoProducto<<endl;
		
		cout << "Deseas continuar comprando más productos..(S/s): ";
		cin >> rpta;
		system("cls");
	} while (rpta == "S" || rpta == "s");
}
int ventCorrelativo()
{
	if (vecVenta.size() == 0)
	{
		return 1;
	}
	else
	{
		return vecVenta[vecVenta.size()-1].codVenta + 1;
	}
}

void modifyCompra()
{
	int cod,
		posArray,
		opcion;
	int _cantidad;
	cout<<"Ingrese el codigo de la compra a modificar:";              
	cin>>cod;
	posArray = obtenerPosArreglo(cod);
	if(posArray == -1)
	{
		cout<<"El codigo ingresado no existe!!!\n";
	}
	else
	{
		cout<<"--------------------\n";
		cout<<"Registro encontrado\n";
		cout<<"--------------------\n";
		cout<<"Codigo: "<<vecVenta[posArray].codVenta<<endl;                     
		cout<<"Nombre: "<<vecVenta[posArray].nomVenta<<endl;                     
		cout<<"Cantidad: "<<vecVenta[posArray].cantVenta<<endl;                                      
		cout<<"--------------------\n";
		cout<<"MINI MENU\n";
		cout<<"Cantidad\t\t[1]\n";
		cout<<"Salir\t\t\t[2]\n";
		cout<<"Seleccionar una opcion[1-2]: ";
		cin>>opcion;
		cin.ignore();
		switch(opcion)
		{
		case 1: cout<<"Cambiar cantidad comprada: ";
				cin>>_cantidad;     
				vecVenta[posArray].cantVenta = _cantidad;
				break;
		case 2:	break;
		default:cout<<"Ingrese una opcion correcta[1-2]\n";
		}
	}
	
}
void listCompra()
{
	for (int i = 0; i < vecVenta.size(); i++)
	{
		cout << "-----------------------------------\n";
		cout << "Codigo: " << vecVenta[i].codVenta << endl;
		cout << "Nombre: " << vecVenta[i].nomVenta << endl;
		cout << "Cantidad: " << vecVenta[i].cantVenta << endl;
		cout << "Costo: " << vecVenta[i].costoVenta << endl;
		cout << "-----------------------------------\n";
	}
}
float ventaProducto()
{
	float costoProducto = 0.0;
	for (int i = 0; i < vecVenta.size(); i++)
	{
		for (int j = 0; j < vecProducto.size(); j++)
		{
			if (vecVenta[i].nomVenta == vecProducto[j].nomProducto)
			{	
				costoProducto = vecProducto[j].preProducto * vecVenta[i].cantVenta;
				vecVenta[i].costoVenta = costoProducto;
				break;
			}
		}
	}
	return costoProducto;
}

float ventaTotal()
{
	float ventaTotal = 0.0;
	for (int i = 0 ; i < vecVenta.size() ; i++)
	{
		for (int j = 0; j < vecProducto.size(); j++)
		{
			if (vecVenta[i].nomVenta == vecProducto[j].nomProducto)
			{	
				ventaTotal += vecProducto[j].preProducto * vecVenta[i].cantVenta;
				vecVenta[i].totalVenta = ventaTotal;
				break;
			}
		}
	}
	return ventaTotal;
}



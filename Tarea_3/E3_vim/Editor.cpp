#include "Editor.h"
#define opcionSwitch 9

vector<string> &separa (const string &s, char d, vector<string> &elementos)
{
    stringstream kuz(s);
    string este;
    while(getline(kuz, este, d))
        elementos.push_back(elementos);
    
    return elementos;
}

vector<string> separa (const string &s, char d)
{
    vector<string> elementos;
    separa(s, d, elementos);
    
    return elementos;
}

vector<string> insertaEnPosicion(vector<string> vector, vector<string> nuevo, int pos)
{
    LinkedList<string> *kuzemac = new LinkedList<string>();
    vector<string> regresa;
    
    for(int i = 0; i < vector.size(); ++i)
        kuzemac->insertBack(vector[i]);
    for(int j = 0; j < nuevo.size(); ++j)
        kuzemac->insert(nuevo[j], pos+1);
    for(int k = 0; k < kuzemac->size(); ++k)
        regresa.push_back(kuzemac->at(k)->getInfo());
    
    delete kuzemac;
    return regresa;
}

void Editor::cargaApp()
{
    int choice;
    cout << "Bienvenido a VIM" << endl;
    cout << "0) Exit \n1) Abrir Documento \n2) Guarda el Documento\n3) Muestra el documento\n4) Editar\n5) Inserta Lineas\n6) Elimina lineas\n7) Inserta palabras\n8) Elimina palabras\n";
    cin >> choice;
    
    bool sigueApp = true;
    
    while (sigueApp)
    {
        switch(choice)
        {
            case 0: 
                sigueApp = false;
                break;
                
            case 1:
                this->abreDocumento();
                break;
                
            case 2:
                this->guarda();
                break;
                
            case 3:
                this->ensenaDocumento();
                break;
                
            case 4:
                this->modificaDocumento();
                break;
                
            case 5:
                this->nuevaLinea();
                break;
                
            case 6:
                this->quitaLinea();
                break;
                
            case 7:
                this->agregaPalabra();
                break;
                
            case 8:
                this->quitaPalabra();
                break;
                
            default: 
                cout << "QUE?";
                break;
        }
    }
}

void Editor::muestraDocumento()
{
    for(int i = 0; i < lineas->size(); ++i)
    {
        vector<string> linea = lineas->at(i)->getInfo();
        for(int j = 0; j < linea.size(); ++j)
        {
            if(j == linea->size()-1)
                cout << linea[j];
            else
                cout << linea[j] << " ";
        }
        cout << "\n";
    }
}

void Editor::cargaDocumento()
{
    lineas->clear(); //aseguramos que este vacio antes de cargar
    document.seekg(0);
    string linea;
    
    if(document.is_open())
    {
        while(getline(document, linea))
        {
            vector<string> lineaSeparada = separa(linea, ' ');
            lineas->insertBack(lineaSeparada);
        }
        document.close();
    }
}

void Editor::abreDocumento()
{
    cout << "Abriendo documento, lo que no haya sido guardado se ha perdido\n";
    document.close(); //para asegurar que no hay otro documento abierto
    nombreDocumento = cin.get();
    
    document.open(nombreDocumento, fstream::in | fstream::out | fstream::app);
    
    cargaDocumento();
    
    cout << "Lo logramos \n";
}

void Editor::guarda()
{
    if(nombreDocumento == "No hay documento")
    {
        cout << "No hay nombre del documento aun. Hora de crear uno nuevo!\n";
        abreDocumento();
    }
    
    document.close();
    
    char arreglo[nombreDocumento.size()+1];
    strcpy(arreglo,nombreDocumento.c_str());
    remove(arreglo);
    
    cout << "Se esta guardando, Dale 2\n";
    
    document.open(nombreDocumento, fstream::in | fstream::out | fstream::app);
    
    document.seekp(0);
    
    for(int i = 0; i < lineas->size(); ++i)
    {
        vector<string> linea = lineas->at(i)->getInfo();
        for(int j = 0; j < linea.size(); ++j)
        {
            if(j == linea.size()-1)
                document << linea[j];
            else
                document << linea[j] << " ";
        }
        if(i != lineas->size()-1)
            document << endl;
    }
    
    document.flush();
    
    cout << "Operacion lograda!";
}

void Editor::ensenaDocumento()
{
    string mensaje = "Viendo documento\n";
    mensaje.append(nombreDocumento);
    cout << mensaje;
    cout << "-----------------------------\n";
    muestraDocumento();
    cout << "-----------------------------\n";
    cout << "Listo\n";
}

void Editor::modificaDocumento()
{
    string mensaje = "Modificando documento\n";
    mensaje.append(nombreDocumento);
    mensaje.append("Para salir de aqui escribe: SACAME!");
    cout << mensaje;
    
    string linea = cin.get();
    
    while(linea != "SACAME!")
    {
        vector<string> lineaDividida = separa(linea, ' ');
        lineas->insertBack(lineaDividida);
        linea = cin.get();
    }
    cout << "Lo logramos!\n";
}

void Editor::nuevaLinea()
{
    string mensaje = "Agregando linea\n";
    mensaje.append(nombreDocumento);
    cout << mensaje;
    
    string linea = cin.get("Que quieres agregar?\n");
    int pos = cin.get("En que numero de linea?\n");
    
    while(pos < 1 || pos > lineas->size())
        pos = cin.get("No existe esa linea\n");
    
    vector<string> lineaSeparada = separa(linea, ' ');
    lineas->insert(lineaSeparada, pos);
    
    cout << "Lo logramos\n";
}

void Editor::agregaPalabra()
{
    string mensaje = "Agregando palabras \n";
    mensaje.append(nombreDocumento);
    cout << mensaje;
    
    string palabras = cin.get("Palabras a agregar\n");
    int posl = cin.get("En donde lo vamos a agregar?\n");
    
    while(posl < 1 || posl > lineas->size())
        posl = cin.get("No existe esa lineas\n");
    
    vector<string> linea = lineas->at(posl-1)->getInfo();
    
    int posw = cin.get("Despues de cuantas palabras?\n");
    
    while(posw < 1 || posw > lineas->size())
        posw = cin.get("No hay tantas palabras\n");
    
    if(palabras != "")
    {
        vector<string> palabrasasi = separa(linea, ' ');
        if(palabrasasi.size() == 0)
            palabrasasi[0] = palabras;
        lineas->at(posl - 1)->setInfo(insertaEnPosicion(linea, palabrasasi, posw-1));
    }
}

void Editor::quitaLinea()
{
    string mensaje = "Quitando linea\n";
    mensaje.append(nombreDocumento);
    cout << mensaje;
    
    int pos = cin.get("Donde borro?\n");
    while(pos < 1 || pos > lineas->size())
        pos = cin.get("No existe esa linea\n");
    
    delete lineas->remove(pos-1);
    cout << "YA!\n";
}

void Editor::quitaPalabra()
{
    string mensaje = "Quitando palabras\n";
    cout << mensaje;
    
    int posl = cin.get("En donde lo vamos a agregar?\n");
    
    while(posl < 1 || posl > lineas->size())
        posl = cin.get("No existe esa lineas\n");
    
    vector<string> linea = lineas->at(posl-1)->getInfo();
    
    int posw = cin.get("Despues de cuantas palabras?\n");
    
    while(posw < 1 || posw > lineas->size())
        posw = cin.get("No hay tantas palabras\n");
    
    int posw2 = cin.get("Hasta cual?\n");
    
    while(posw2 < posw || posw2 > lineas->size())
        posw2 = cin.get("Que no!\n");
    
    vector<string> modishness;
    
    for(int i = 0; i < lineas->size(); ++i)
    {
        if(!(i >= posw-1 && i <= posw2 - 1))
            modishness.push_back(lineas[i]);
    }
    
    lineas->at(posl-1)->setInfo(modishness);
    
    cout << "YEIII!!!\n";
}
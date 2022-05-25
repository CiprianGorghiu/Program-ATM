#include <iostream>
#include <fstream>
using namespace std;

int logare(int money, int cardid);
int meniu(int money, int carid);
int retragere(int money, int cardid);
int depune(int money, int cardid);
int interogare(int money, int cardid);
int logat = 0;
int intrebare;
int money=0;
int money2=0;
int incercare =0;

ifstream citire_id("id_b.in");
ifstream citire_pin("pin_b.in");
ofstream inregistrareid("id_b.in");
ofstream inregistrarepin("pin_b.in");

int logare()
{
    cout<<"========================================================="<<endl;
    cout<<"Bine ati venit la banca X,\nPentru inceput este nevoie sa introduceti datele cardului.\nNu uita: numarul cardului trebuie sa contina 6 cifre, iar pinul 4. "<<endl;
    cout<<"========================================================="<<endl;
    cout<<"                                Incercari ramase:"<<3-incercare<<endl;
    int cardid, pin, pin_b, id_b;
    citire_id>>id_b;
    citire_pin>>pin_b;

     if(incercare == 3)
    {
        cout<<"[SYSTEM]Ai introdus datele gresite de 3 ori, programul se va inchide!";
        return 1;
    }

    cout<<"Introduceti id-ul cardului: "<<endl;
    cin>>cardid;
    if(cardid>999999 || cardid<=100000)
    {
        system("CLS");
        cout<<"[EROARE]Id-ul cardului tau trebuie sa contina 6 cifre!"<<endl;
        incercare++;
        return logare();
    }

    cout<<"Introduceti pin-ul cardului: "<<endl;
    cin>>pin;
    if(pin>9999 || pin<=1000)
    {
        system("CLS");
        cout<<"[EROARE]Codul pin trebuie sa contina 4 cifre!"<<endl;
        incercare++;
        return logare();
    }
    if(id_b == cardid && pin_b == pin)
    {
        system("CLS");
        logat = 1;
        cout<<"[SYSTEM]Te-ai autentificat cu succes!"<<endl;
        cout<<"[SYSTEM]Bine ai venit in contul tau!"<<endl;

    }
    else
    {
        cout<<"[Eroare]: Ai introdus un id sau un pin gresit!";
        incercare++;

    }
    if(logat == 1)
    {
        meniu(money, cardid);
    }
    return 1;

}

int inregistrare()
{
    cout<<"Pentru a te inregistra este nevoie sa introduci un pin format din 6 cifre\n";
    int register_id, register_pin;
    cout<<"Card id:";
     cin>>register_id;
    if(register_id < 100000 || register_id > 999999)
    {
        system("CLS");
        cout<<"[Eroare]Id-ul trebuie sa contina 6 cifre!";
        return inregistrare();
    }
    inregistrareid<<register_id;
    cout<<"[Register]Acum trebuie sa-ti alegi un pin format din 4 cifre!\n";
    cout<<"Card pin: ";
     cin>>register_pin;
    if(register_pin < 1000 || register_pin > 9999)
    {
        system("CLS");
        cout<<"[Eroare]Pinul Trebuie sa contina 4 cifre!";
        return inregistrare();
    }
    inregistrarepin<<register_pin;
    system("CLS");
    cout<<"=========================================================================================================="<<endl;
    cout<<"[Atentie]: Pentru ca datele tale sa fie inregistrare este nevoie sa repornesti programul si sa te loghezi!"<<endl;
    cout<<"=========================================================================================================="<<endl;
    cout<<endl;
    cout<<endl;
    cout<<"~Banca x card~"<<endl;
    cout<<"=================="<<endl;
    cout<<"= Card Number:   ="<<endl;
    cout<<"= "<<register_id<<"         ="<<endl;
    cout<<"=                ="<<endl;
    cout<<"=                ="<<endl;
    cout<<"= Pin:           ="<<endl;
    cout<<"= "<<register_pin<<"           ="<<endl;
    cout<<"=                ="<<endl;
    cout<<"=================="<<endl;

    return 0;
}
int depune(int money, int cardid)
{
    cout<<"Introduceti suma pe care doriti s-o introduceti in contul -"<<cardid<<"-\n"<<endl;
    cin>>money2;
    if(money2 <=0 )
    {
        cout<<"Ai introdus o suma gresita!"<<endl;
        return depune(money, cardid);
    }
    money = money+money2;
    cout<<"Ati introdus "<<money2<<" lei"<<endl;
    cout<<"Doresti sa mai faci vreo operatie? (0)DA/(1)NU \n"<<endl;
    cin>>intrebare;
    switch(intrebare)
    {
        case 0: system("CLS");
            meniu(money,cardid);
            break;

        case 1: return 1;
        default: system("CLS");
            cout<<"[Eroare]: Ai tastat gresit. Meniul a fost inchis."<<endl;
    }
return 0;
}
int retragere(int money, int cardid)
{
    int retrage=0;

    if(money == 0)
    {
        cout<<"Ai 0 lei in cont, nu poti face o retragere!"<<endl;
        cout<<"Doresti sa mai faci vreo operatie? (0)DA/(1)NU \n"<<endl;
        cin>>intrebare;
        switch(intrebare)
        {
            case 0: system("CLS");
                meniu(money,cardid);
                break;

            case 1: return 1;
            default:system("CLS");
                cout<<"[Eroare]: Ai tastat gresit. Meniul a fost inchis."<<endl;

        }
    }

    cout<<"Introduceti suma pe care doriti s-o retrageti: \n"<<endl;
    cin>>retrage;
    if(retrage<=0)
    {
        system("CLS");
        cout<<"Ai introdus o suma incorecta, te rog sa introduci iar."<<endl;
        return retragere(money, cardid);
    }
    if(retrage>money)
    {
        system("CLS");
        cout<<"Fonduri insuficiente"<<endl;
    }
    else
    {
    system("CLS");
    money = money-retrage;
    cout<<"Ai retras "<<retrage<<"lei din contul "<<cardid<<endl;
    }
    cout<<"Doresti sa mai faci vreo operatie? (0)DA/(1)NU \n"<<endl;
    cin>>intrebare;
    switch(intrebare)
    {
        case 0:system("CLS");
            meniu(money,cardid);
                break;

        case 1: return 1;
        default: system("CLS");
            cout<<"[Eroare]: Ai tastat gresit. Meniul a fost inchis."<<endl;

    }
    return 0;

}
int interogare(int money, int cardid)
{
    cout<<"Soldul curent este: "<<money<<"lei"<<endl;
    cout<<"Doresti sa mai faci vreo operatie? (0)DA/(1)NU \n"<<endl;
    cin>>intrebare;
    switch(intrebare)
    {
        case 0:system("CLS");
            meniu(money,cardid);
            break;

        case 1: return 1;

        default:system("CLS");
            cout<<"[Eroare]: Ai tastat gresit. Meniul a fost inchis."<<endl;

    }

    return 0;
}
int meniu(int money, int cardid)
{
    int meniul=0;
    cout<<"~ATM MENU~"<<endl;
    cout<<"(1)Depozitare\n"<<"(2)Retragere numerar\n"<<"(3)Interogare sold\n"<<"(4)Iesi din meniu"<<endl;
    cin>>meniul;
    switch(meniul)
    {
        case 1:  depune(money, cardid);
            break;
        case 2: retragere(money, cardid);
            break;
        case 3: interogare(money, cardid);
            break;
        case 4: cout<<"Ati iesit din meniu!"<<endl;
            return 0;

        default: cout<<"Apasa o tasta intre 1 si 4"<<endl;
    }
    return 1;

}
void meniu_principal()
{
     cout<<"========================================================="<<endl;
    cout<<"               Bine ati venit la banca X"<<endl;
    cout<<"========================================================="<<endl;
    cout<<"(0)Register\n(1)Login"<<endl;
    int cont;
    cin>>cont;
    switch(cont)
    {
        case 0:system("CLS");
            inregistrare();
        break;
        case 1: system("CLS");
            logare();
        break;
        case 2:system("CLS");
            system("pause");
        default: cout<<"[Eroare]: Nu ai ales o optiune din meniu!";
    }

}

int main()
{
    system("CLS");
    meniu_principal();
    return 0;
}

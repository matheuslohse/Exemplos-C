class Lampada
{
private:
        int estado; // -1=queimada, 0=desligada, 1=ligada
public:
    Lampada() { estado=0; }
    int getEstado() { return estado; }
    string pegaEstado() {
        if (estado==-1) return "queimada";
        else if (estado==0) return "desligada";
        else if (estado==1) return "ligada";
        else return "estado desconhecido";
    }
    bool ligar()
    {
        if (estado!=-1)
        { estado=1; return true; }
        return false;
    }
    bool desligar()
    {
        if (estado!=-1)
        { estado=0; return true; }
        return false;
    }
    void queimar() { estado=-1; }
};

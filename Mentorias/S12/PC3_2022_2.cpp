#include <iostream>
#include <vector>

using namespace std;

class entry {
protected:
    string name;
    string path;
    int read;
    int write;
    int execute;
public:
    entry(string n, string p, int r, int w, int x){
        name = n;
        path = p;
        read = r;
        write = w;
        execute = x;
    }

    char get_read(){
        if (read == 1)
            return 'R';
        else
            return '-';

        // return read == 1 ? 'R' : '-';
    }

    char get_write(){
        if (write == 1)
            return 'W';
        else
            return '-';
    }

    char get_execute(){
        if (execute == 1)
            return 'X';
        else
            return '-';
    }

    string get_name(){
        return name;
    }

    virtual string list() = 0;

    virtual string text(){};

    virtual ~entry(){}
};

class folder: public entry {
private:
    vector<entry*> entries;
public:
    folder(string n, string p, int r, int w, int x): entry(n,p,r,w,x){}

    void add_entry(entry* e){
        entries.push_back(e);
    }

    string list() override {
        return path + "/" + name + " ";
    }

    string text() override {
        return "";
    }

    friend ostream& operator<<(ostream& out, folder f){
        out << f.get_read() << f.get_write() << f.get_execute() << " " << f.get_name() << endl;

        for (auto i : f.entries) {
            out << i->get_read() << i->get_write() << i->get_execute() << " ";

            out << i->list() << i->text();

            out << endl;
        }

        return out;
    }

    virtual ~folder(){}
};

class file: public entry {
private:
    string content;
public:
    file(string n, string p, int r, int w, int x, string cont): entry(n,p,r,w,x), content(cont){}

    string list() override {
        return path + "/" + name + " ";
    }

    string text() override {
        return content;
    }

    virtual ~file(){}
};

int main(){
    char type;
    string name, content;
    int r, w, x, n;

    cin >> type >> name >> r >> w >> x;
    folder raiz(name, "root", r, w, x);

    cin >> n;

    for (int i = 0; i < n; ++i) {
        cin >> type >> name >> r >> w >> x;

        if (type == 'D'){
            auto carpeta = new folder(name, "root", r, w, x);
            raiz.add_entry(carpeta);
        } else if (type == 'F'){
            cin >> content;
            auto archivo = new file(name, "root", r, w,  x, content);
            raiz.add_entry(archivo);
        }
    }

    cout << endl;

    cout << raiz;

    return 0;
}
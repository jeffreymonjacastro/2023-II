#include <iostream>
#include <vector>

using namespace std;

class entry {
protected:
    string name, path;
    int read, write, execute;
public:
    entry(string n, string p, int r, int w, int e): name(n), path(p), read(r), write(w), execute(e) {}

    char get_read(){ return read; };

    char get_write(){ return write; };

    char get_excute(){ return execute; };

    string get_name(){ return name; };

    virtual string list() = 0;

    virtual int get_size() = 0;

    virtual ~entry(){}
};

class folder : public entry {
private:
    vector<entry*> entries;
public:
    folder(string n, string p, int r, int w, int e): entry(n, p, r, w, e){}

    void add_entry(entry* e) {
        entries.push_back(e);
    }

    string list(){ return path + "/" + name + " "; }

    int get_size(){ return 0; }

    friend ostream& operator <<(ostream& out, folder f);

    virtual ~folder(){}
};

class file : public entry {
private:
    string content;
public:
    file(string n, string p, int r, int w, int e, string c): entry(n, p, r, w, e), content(c){}

    string list(){ return path + "/" + name + " "; }

    int get_size(){ return content.length(); }

    virtual ~file(){}
};

ostream& operator <<( ostream& out, folder f){
    f.get_read() == 1 ? out << "R" : out << "-";
    f.get_write() == 1 ? out << "W" : out << "-";
    f.get_excute() == 1 ? out << "X " : out << "- ";
    out << f.get_name() << endl;

    for(int i = 0; i < f.entries.size(); i++){
        f.entries[i]->get_read() == 1 ? out << "R" : out << "-";
        f.entries[i]->get_write() == 1 ? out << "W" : out << "-";
        f.entries[i]->get_excute() == 1 ? out << "X " : out << "- ";

        out << f.entries[i]->list();
        out << f.entries[i]->get_size() << endl;
    }

    return out;
};

int main(){
    folder f1("root", "root", 1, 1, 1);
    folder f2("home", "root", 1, 0, 0);
    file f3("file1", "root", 1, 1, 0, "contenido");

    f1.add_entry(&f2);
    f1.add_entry(&f3);

    cout << f1 << endl;

    return 0;
}

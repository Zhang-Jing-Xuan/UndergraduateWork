#ifndef FileSys_h
#define FileSys_h

#define MAINFILE "main.dat"

#include "Base.h"
#include "File.h"
#include "User.h"
#include "InodeTable.h"
#include "DictionaryTree.h"

static int user_num;

class FileSys{
public:
    FileSys();
    void run();
private:
    string prefix;
    User user;
    File file;
    vector<FileEntry> fileEntrys;
    FileEntry* nowFileEntry;
    InodeTable inodeTable;
    Inode rootDir;
    string fileName;
    string tmp;

    int current;
    int total;
    int h[200],e[2*200],ne[2*200],id,depth[200];
    unordered_map <int,string> hash;
    unordered_map <string,int> rhash;
    void add(int a,int b);

    void pln(const string& s);
    void p(const string& s);

    void mkdir();
    void cddir(string dst);
    void cdback();
    void backup();
    void resume();
    void writeBack();
    
    void printDir();
    void enterFileName();
    void createFile();
    void copyFile();
    void copyRead();
    void copyWrite();
    void deleteFile();
    int openFile();
    void closeFile();
    void readFile();
    void writeFile();
    void appendFile();
    void boot();
    string pcToBinary(int n);
    bool login();
    void adduser();
    void init();
    void info();
    void readnum();
};


#endif /* FileSys_hpp */

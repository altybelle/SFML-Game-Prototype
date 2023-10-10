#ifndef FILE_READER_HPP
#define FILE_READER_HPP

#include <iostream>
#include <fstream>
using namespace std;

class File_Reader
{
    private:
        ifstream file;
    public:
        ifstream& get_file();
        string get_content();
        bool open_file(const string& filename);
        bool close_file();
};

#endif /* FILE_READER_HPP */
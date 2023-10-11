#include "File_Reader.hpp"

ifstream &File_Reader::get_file() {
    return file;
}

string File_Reader::get_content() {
    string content((istreambuf_iterator<char>(file)),
                   istreambuf_iterator<char>());
    return content;
}

bool File_Reader::open_file(const string &filename) {
    file.open(filename);

    if (file.is_open())
        return true;

    return false;
}

bool File_Reader::close_file() {
    if (file.is_open()) {
        file.close();
        return true;
    }

    return false;
}
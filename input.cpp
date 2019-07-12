//
// Created by A30611 on 7/11/2019.
//

#include "input.h"
#include <string>
#include <iostream>
#include <malloc.h>
#include <cstring>


using namespace std;

string _read_input(void)
{
    string tmp;

    try {
        std::getline(cin, tmp);
    }
    catch (exception e){
        cout << "no input";
    }

    return tmp;
}


const char* read_input(void)
{
    char* buf;
    string tmp = _read_input();

    buf = (char*)malloc(tmp.length() + 1);
    memcpy(buf, tmp.c_str(), tmp.length());

    buf[tmp.length()] = '\0';

    return buf;
}
#pragma once
#ifndef __SED_H__
#define __SED_H__

#include <iostream>
#include <string>
#include <cstring>
#include <fstream>
#include <cerrno>

class Sed
{

private:
    std::string m_file_name;
    std::string m_s1;
    std::string m_s2;

public:
    Sed(const std::string& file_name, const std::string& s1, const std::string& s2);
    ~Sed();
    int Replace(void );
};


#endif
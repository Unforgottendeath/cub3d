#include "Sed.hpp"

Sed::Sed(const std::string& file_name, const std::string& s1, const std::string& s2)
{
    m_file_name = file_name;
    m_s1        = s1;
    m_s2        = s2;
}

Sed::~Sed()
{
    std::cout << "Destructing Sed members ... \n";
}

int Sed::Replace()
{
    std::ifstream   infile;
    std::string     line = "";
    std::string     replace;
    std::string     outfile_name = m_file_name + ".replace";
    size_t          index;
    char             c;

    infile.open(m_file_name.data());
    if (!infile.is_open()){
        std::cerr << "Unable to open " << m_file_name << " : " << strerror(errno) << "\n";
        return (1);
    }
    std::ofstream outfile(outfile_name.data() );
    if (!outfile.is_open()){
        std::cerr << "Unable to create " << outfile_name<< " : " << strerror(errno) << "\n";
        infile.close();
        return (1);
    }
    while (!infile.eof() && infile >> std::noskipws >> c)
        line += c;
    index = line.find(m_s1, 0);
    while (index != std::string::npos)
    {
        replace = line.substr(0, index);
        line = line.substr(index+ m_s1.size(), line.size() - index + m_s1.size());
        replace.insert(replace.size(), m_s2);
        outfile.write(replace.data(), replace.size());
        index = line.find(m_s1, 0);
    }
    if (!line.empty())
        outfile.write(line.data(), line.size());
    infile.close();
    outfile.close();
    return (0);
}
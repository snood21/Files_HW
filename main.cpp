#include <iostream>
#include <fstream>
#include <string>

using namespace std;

//#define SWAP_STRINGS
#define CONVERSION

int main()
{
    setlocale(LC_ALL, "Russian");

#ifdef SWAP_STRINGS
    std::ifstream fin("201 RAW.txt");

    int count_of_strings = {0};

    if (fin.is_open())
    {
        string str;
        while (!fin.eof())
        {
            getline(fin, str);
            count_of_strings++;
        }
        fin.clear();
        fin.seekg(0);

        string* array_of_strings = new string[count_of_strings];

        int i = 0;

        string first_value = {};
        string second_value = {};

        while (!fin.eof())
        {
            fin >> first_value >> second_value;
            array_of_strings[i].append(second_value);
            array_of_strings[i].append("\t");
            array_of_strings[i].append(first_value);
            i++;
        }
        fin.close();

        std::ofstream fout("201 RAW.txt");

        for (int j = 0; j < count_of_strings; ++j)
            fout << array_of_strings[j] << endl;
        fout.close();
    }
    else
        std::cerr << "Error: file not found" << endl;
#endif

#ifdef CONVERSION
    std::ifstream fin("201 RAW.txt");
    std::ofstream fout("201.dhcpd");

    if (fin.is_open()&&(fout.is_open()))
    {
        int i = 1;

        while (!fin.eof())
        {
            string ip_adress = {};
            string mac_adress = {};
            fin >> ip_adress >> mac_adress;

            if ((ip_adress!="")&&(mac_adress!=""))
            {
                fout << "host 201-" << i << endl;
                fout << "{" << endl;
                fout << "\thardware ethernet\t" << mac_adress << ";" << endl;
                fout << "\tfixed-address\t\t" << mac_adress << ";" << endl;
                fout << "}" << endl << endl;
                i++;
            }
        }
        fin.close();
        fout.close();
    }
    else
        std::cerr << "Error: file not found" << endl;
#endif


    return 0;
}

// Mikołaj Bień
// pon 11:15
// 24.10.2022 / 25.10.2022
// numer albumu: 272950

#include <iostream>




namespace cppNewDelete {
    struct NameDict {
        const char** pNames;
        int len;
    };

    //tworzenie pustego słownika
    NameDict createNameDict() {
        NameDict out;
        out.len = 0;
        out.pNames = new const char* [0];
        return out;
    }

    //tworzenie słownika o podanej długości
    NameDict createNameDict(int base_len) {
        NameDict out;
        out.len = base_len;
        out.pNames = new const char* [out.len];
        return out;
    }


    //dodawanie do słownika nowego imienia wprowadzanego z klawiatury
    void addName(NameDict& dict, const char* name) {
        NameDict new_dict = createNameDict(dict.len + 1);

        for (int i = 0; i < dict.len; i++) {
            new_dict.pNames[i] = dict.pNames[i];
        }

        new_dict.pNames[dict.len] = name;

        delete[] dict.pNames;
        dict = new_dict;
    }

    //drukowanie słownika
    void printNameDict(NameDict dict) {
        for (int i = 0; i < dict.len; i++) {
            std::cout << dict.pNames[i] << std::endl;
        }

        std::cout << std::endl;
    }

    //drukowanie słownika z podanym indeksem
    void printNameDict(NameDict dict, int idx) {
        std::cout << dict.pNames[idx] << std::endl;

        std::cout << std::endl;
    }

    //drukowanie słownika z podaną literą
    void printNameDict(NameDict dict, char chr) {
        for (int i = 0; i < dict.len; i++) {
            if (dict.pNames[i][0] == chr) {
                std::cout << dict.pNames[i] << std::endl;
            }
        }

        std::cout << std::endl;
    }

    void removeName(NameDict& dict, int idx) {
        NameDict new_dict = createNameDict(dict.len - 1);

        for (int i = 0; i < idx; i++) {
            new_dict.pNames[i] = dict.pNames[i];
        }

        for (int i = idx + 1; i < dict.len; i++) {
            new_dict.pNames[i - 1] = dict.pNames[i];
        }

        delete[] dict.pNames;
        dict = new_dict;
    }

    void removeName(NameDict& dict, const char* name) {
        for (int i = 0; i < dict.len; i++) {
            for (int j = 0; dict.pNames[i][j] != 0; j++) {
                if (dict.pNames[i][j] != name[j]) break;
                if (dict.pNames[i][j + 1] == 0 && name[j + 1] == 0) {
                    removeName(dict, i);
                    return;
                }
            }
        }
    }

    void sortDict(NameDict& dict) {
        for (int i = 0; i < dict.len; i++) {
            for (int j = 0; j < dict.len - 1; j++) {
                if (dict.pNames[j][0] > dict.pNames[j + 1][0]) {
                    const char* tmp = dict.pNames[j];
                    dict.pNames[j] = dict.pNames[j + 1];
                    dict.pNames[j + 1] = tmp;
                }
            }
        }
    }

    void sortDictByLength(NameDict& dict) {
        for (int i = 0; i < dict.len; i++) {
            for (int j = 0; j < dict.len - 1; j++) {
                int len1 = 0;
                int len2 = 0;
                for (int k = 0; dict.pNames[j][k] != 0; k++) {
                    len1++;
                }
                for (int k = 0; dict.pNames[j + 1][k] != 0; k++) {
                    len2++;
                }
                if (len1 > len2) {
                    const char* tmp = dict.pNames[j];
                    dict.pNames[j] = dict.pNames[j + 1];
                    dict.pNames[j + 1] = tmp;
                }
            }
        }
    }

    void clearDict(NameDict& dict) {
        // for (int i = 0; i < dict.len; i++) {
        //     delete[] dict.pNames[i];
        // }
        delete[] dict.pNames;
        dict = createNameDict();
    }
}

namespace cMallocFree {
    struct NameDict {
        const char** pNames;
        int len;
    };

    //tworzenie pustego słownika
    NameDict createNameDict() {
        NameDict out;
        out.len = 0;
        out.pNames = (const char**)malloc(sizeof(const char*) * out.len);
        return out;
    }

    //tworzenie słownika o podanej długości
    NameDict createNameDict(int base_len) {
        NameDict out;
        out.len = base_len;
        out.pNames = (const char**)malloc(sizeof(const char*) * out.len);
        return out;
    }

    //dodawanie do słownika nowego imienia wprowadzanego z klawiatury
    void addName(NameDict& dict, const char* name) {
        NameDict new_dict = createNameDict(dict.len + 1);

        for (int i = 0; i < dict.len; i++) {
            new_dict.pNames[i] = dict.pNames[i];
        }

        new_dict.pNames[dict.len] = name;

        free(dict.pNames);
        dict = new_dict;
    }

    //drukowanie słownika
    void printNameDict(NameDict dict) {
        for (int i = 0; i < dict.len; i++) {
            std::cout << dict.pNames[i] << std::endl;
        }

        std::cout << std::endl;
    }

    //drukowanie słownika z podanym indeksem
    void printNameDict(NameDict dict, int idx) {
        std::cout << dict.pNames[idx] << std::endl;

        std::cout << std::endl;
    }

    //drukowanie słownika z podaną literą
    void printNameDict(NameDict dict, char chr) {
        for (int i = 0; i < dict.len; i++) {
            if (dict.pNames[i][0] == chr) {
                std::cout << dict.pNames[i] << std::endl;
            }
        }

        std::cout << std::endl;
    }

    void removeName(NameDict& dict, int idx) {
        NameDict new_dict = createNameDict(dict.len - 1);

        for (int i = 0; i < idx; i++) {
            new_dict.pNames[i] = dict.pNames[i];
        }

        for (int i = idx + 1; i < dict.len; i++) {
            new_dict.pNames[i - 1] = dict.pNames[i];
        }

        free(dict.pNames);
        dict = new_dict;
    }

    void removeName(NameDict& dict, const char* name) {
        for (int i = 0; i < dict.len; i++) {
            for (int j = 0; dict.pNames[i][j] != 0; j++) {
                if (dict.pNames[i][j] != name[j]) break;
                if (dict.pNames[i][j + 1] == 0 && name[j + 1] == 0) {
                    removeName(dict, i);
                    return;
                }
            }
        }
    }

    void sortDict(NameDict& dict) {
        for (int i = 0; i < dict.len; i++) {
            for (int j = 0; j < dict.len - 1; j++) {
                if (dict.pNames[j][0] > dict.pNames[j + 1][0]) {
                    const char* tmp = dict.pNames[j];
                    dict.pNames[j] = dict.pNames[j + 1];
                    dict.pNames[j + 1] = tmp;
                }
            }
        }
    }

    void sortDictByLength(NameDict& dict) {
        for (int i = 0; i < dict.len; i++) {
            for (int j = 0; j < dict.len - 1; j++) {
                int len1 = 0;
                int len2 = 0;
                for (int k = 0; dict.pNames[j][k] != 0; k++) {
                    len1++;
                }
                for (int k = 0; dict.pNames[j + 1][k] != 0; k++) {
                    len2++;
                }
                if (len1 > len2) {
                    const char* tmp = dict.pNames[j];
                    dict.pNames[j] = dict.pNames[j + 1];
                    dict.pNames[j + 1] = tmp;
                }
            }
        }
    }

    void clearDict(NameDict& dict) {
        // for (int i = 0; i < dict.len; i++) {
        //     free((void*)dict.pNames[i]);
        // }
        free(dict.pNames);
        dict = createNameDict();
    }

}

int main() {
    std::cout << "Mikolaj Bien\npon 11:15\n24.10.2022 / 25.10.2022\nnumer albumu: 272950\n\n";

    cppNewDelete::NameDict dict = cppNewDelete::createNameDict();

    cppNewDelete::addName(dict, "Mikolaj");
    cppNewDelete::addName(dict, "Kamil");
    cppNewDelete::addName(dict, "Kacper");
    cppNewDelete::addName(dict, "Krzysztof");
    cppNewDelete::addName(dict, "Kuba");

    cppNewDelete::printNameDict(dict);

    cppNewDelete::sortDict(dict);

    cppNewDelete::printNameDict(dict);

    cppNewDelete::sortDictByLength(dict);

    cppNewDelete::printNameDict(dict);

    cppNewDelete::removeName(dict, "Krzysztof");

    cppNewDelete::printNameDict(dict);

    cppNewDelete::clearDict(dict);
}
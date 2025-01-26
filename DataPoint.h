#pragma once
#include <string>

class DataPoint {
public:
    std::string timestamp;   // Data i godzina
    double autokonsumpcja;   // Autokonsumpcja
    double eksport;          // Eksport
    double import;           // Import
    double pobor;            // Pobór
    double produkcja;        // Produkcja

    DataPoint(std::string ts, double autok, double exp, double imp, double pob, double prod)
        : timestamp(ts), autokonsumpcja(autok), eksport(exp), import(imp), pobor(pob), produkcja(prod) {
    }
};

#pragma once
#include <string>

class Student
{
private:
    std::string imie;
    std::string nazwisko;
    int nrAlbumu = 0;

protected:
    std::string dataUrodzenia;
    std::string identyfikator;

public:
    int setImie(std::string imie);
    int setNazwisko(std::string nazwisko);
    virtual int setDataUrodzenia(std::string dataUrodzenia);
    int setNrAlbumu(int nrAlbumu);
    virtual int setIdentyfikator(std::string identyfikator) = 0;

    std::string getImie();
    std::string getNazwisko();
    std::string getDataUrodzenia();
    int getNrAlbumu();
    std::string getIdentyfikator();
};

class Polak :public Student
{
public:
    int setIdentyfikator(std::string identyfikator);
    int setDataUrodzenia(std::string dataUrodzenia);
};

class Portugalczyk :public Student
{
public:
    int setIdentyfikator(std::string identyfikator);

};
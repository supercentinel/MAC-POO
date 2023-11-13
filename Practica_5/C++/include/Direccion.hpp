//{{_user_}} a374377@proton.me 2019-01-01
#ifndef DIRECCION_HPP
#define DIRECCION_HPP

#include <iostream>

class Direccion {
private:
    int id;
    std::string calle;
    int numero;
    std::string colonia;
    std::string municipio;
    std::string estado;
    std::string pais;
    short int codigoPostal;
public:
    // Contructors
    Direccion();
    Direccion(std::string calle,
        int numero,
        std::string colonia,
        std::string municipio,
        std::string estado,
        std::string pais,
        int codigoPostal);
    /* Direccion(int id); */
    // Getters
    int getId();
    std::string getCalle();
    int getNumero();
    std::string getColonia();
    std::string getMunicipio();
    std::string getEstado();
    std::string getPais();
    int getCodigoPostal();
    // Setters
    void setCalle(std::string calle);
    void setNumero(int numero);
    void setColonia(std::string colonia);
    void setMunicipio(std::string municipio);
    void setEstado(std::string estado);
    void setPais(std::string pais);
    void setCodigoPostal(int codigoPostal);
    // Methods
    // I/O
    friend std::ostream& operator << (std::ostream &os, const Direccion &direccion);
    friend std::istream& operator >> (std::istream &is, Direccion &direccion);
    /* // SQL */
    /* int createTable(); */
    /* int create(); */
    /* int read(int id); */
    /* int update(); */
    /* int delet(); */
};

#endif // DIRECCION_HPP

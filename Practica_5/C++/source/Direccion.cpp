#include "Direccion.hpp"

#include <iostream>
#include <istream>
#include <sqlite3.h>
#include <string>

// Contructors
Direccion::Direccion() {
    this->id = 0;
    this->calle = "";
    this->numero = 0;
    this->colonia = "";
    this->municipio = "";
    this->estado = "";
    this->pais = "";
    this->codigoPostal = 0;
}

Direccion::Direccion(std::string calle,
        int numero,
        std::string colonia,
        std::string municipio,
        std::string estado,
        std::string pais,
        short int codigoPostal) {
    this->id = 0;
    this->calle = calle;
    this->numero = numero;
    this->colonia = colonia;
    this->municipio = municipio;
    this->estado = estado;
    this->pais = pais;
    this->codigoPostal = codigoPostal;
}

/* Direccion::Direccion(int id) { */
/*     this->read(id); */
/* } */

// Getters
int Direccion::getId() {
    return this->id;
}

std::string Direccion::getCalle() {
    return this->calle;
}

int Direccion::getNumero() {
    return this->numero;
}

std::string Direccion::getColonia() {
    return this->colonia;
}

std::string Direccion::getMunicipio() {
    return this->municipio;
}

std::string Direccion::getEstado() {
    return this->estado;
}

std::string Direccion::getPais() {
    return this->pais;
}

short int Direccion::getCodigoPostal() {
    return this->codigoPostal;
}

// Setters
void Direccion::setCalle(std::string calle) {
    this->calle = calle;
}

void Direccion::setNumero(int numero) {
    this->numero = numero;
}

void Direccion::setColonia(std::string colonia) {
    this->colonia = colonia;
}

void Direccion::setMunicipio(std::string municipio) {
    this->municipio = municipio;
}

void Direccion::setEstado(std::string estado) {
    this->estado = estado;
}

void Direccion::setPais(std::string pais) {
    this->pais = pais;
}

void Direccion::setCodigoPostal(short int codigoPostal) {
    this->codigoPostal = codigoPostal;
}

// Methods
// I/O
std::ostream& operator << (std::ostream& os, const Direccion& direccion) {
    os << "Calle: " << direccion.calle << std::endl;
    os << "Numero: " << direccion.numero << std::endl;
    os << "Colonia: " << direccion.colonia << std::endl;
    os << "Municipio: " << direccion.municipio << std::endl;
    os << "Estado: " << direccion.estado << std::endl;
    os << "Pais: " << direccion.pais << std::endl;
    os << "Codigo Postal: " << direccion.codigoPostal << std::endl;

    return os;
}

std::istream& operator >> (std::istream& is, Direccion& direccion) {
    std::cout << "Calle: ";
    is >> direccion.calle;
    std::cout << "Numero: ";
    is >> direccion.numero;
    std::cout << "Colonia: ";
    is >> direccion.colonia;
    std::cout << "Municipio: ";
    is >> direccion.municipio;
    std::cout << "Estado: ";
    is >> direccion.estado;
    std::cout << "Pais: ";
    is >> direccion.pais;
    std::cout << "Codigo Postal: ";
    is >> direccion.codigoPostal;

    return is;
}
/* //SQL */
/* int Direccion::createTable() { */
/*     sqlite3 *db; */
/*     int rc = sqlite3_open("Practica_5.db", &db); */

/*     if (rc != SQLITE_OK) { */
/*         std::cerr << "Error opening database" << std::endl; */
/*         sqlite3_close(db); */

/*         return rc; */
/*     } */

/*     std::string sql = "CREATE TABLE IF NOT EXISTS Direccion (" */
/*         "id INTEGER PRIMARY KEY AUTOINCREMENT, " */
/*         "calle TEXT NOT NULL, " */
/*         "numero INTEGER NOT NULL, " */
/*         "colonia TEXT NOT NULL, " */
/*         "municipio TEXT NOT NULL, " */
/*         "estado TEXT NOT NULL, " */
/*         "pais TEXT NOT NULL, " */
/*         "codigoPostal INTEGER NOT NULL);"; */

/*     rc = sqlite3_exec(db, sql.c_str(), NULL, NULL, NULL); */

/*     if (rc != SQLITE_OK) { */
/*         std::cerr << "Error creating table" << std::endl; */
/*         sqlite3_close(db); */

/*         return rc; */
/*     } */

/*     rc = sqlite3_close(db); */

/*     return rc; */
/* } */

/* int Direccion::create() { */
/*     sqlite3 *db; */
/*     sqlite3_stmt *stmt; */

/*     int rc = sqlite3_open("Practica_5.db", &db); */
/*     char *errorMessage = nullptr; */

/*     int assignedId = 0; */

/*     if (rc != SQLITE_OK) { */
/*         std::cerr << "Error opening database" << std::endl; */
/*         sqlite3_close(db); */

/*         return rc; */
/*     } */

/*     std::string check = "SELECT * FROM Direccion WHERE "\ */
/*         "calle = '" + this->calle + */
/*         "' AND numero = " + std::to_string(this->numero) + */
/*         " AND colonia = '" + this->colonia + */
/*         "' AND municipio = '" + this->municipio + */
/*         "' AND estado = '" + this->estado + */
/*         "' AND pais = '" + this->pais + */
/*         "' AND codigoPostal = " + std::to_string(this->codigoPostal) + ";"; */

/*     rc = sqlite3_prepare_v2(db, check.c_str(), -1, &stmt, NULL); */

/*     if (rc != SQLITE_OK) { */
/*         std::cerr << "Error preparing statement" << std::endl; */
/*         sqlite3_close(db); */

/*         return rc; */
/*     } */

/*     rc = sqlite3_step(stmt); */

/*     if (rc == SQLITE_ROW) { */
/*         std::cerr << "Direccion already exists" << std::endl; */
/*         this->id = sqlite3_column_int(stmt, 0); */
/*         sqlite3_close(db); */

/*         return rc; */
/*     } */

/*     std::string insert = "INSERT INTO Direccion \ */
/*         (calle, numero, colonia, municipio, estado, pais, codigoPostal) \ */
/*         VALUES ('" + this->calle + */
/*         "', " + std::to_string(this->numero) + */
/*         ", '" + this->colonia + */
/*         "', '" + this->municipio + */
/*         "', '" + this->estado + */
/*         "', '" + this->pais + */
/*         "', " + std::to_string(this->codigoPostal) + ");"; */

/*     rc = sqlite3_exec(db, insert.c_str(), NULL, NULL, &errorMessage); */

/*     if (rc != SQLITE_OK) { */
/*         std::cerr << "Error " << errorMessage << std::endl; */
/*         sqlite3_free(errorMessage); */
/*         sqlite3_close(db); */

/*         return rc; */
/*     } */

/*     assignedId = sqlite3_last_insert_rowid(db); */

/*     this->id = assignedId; */

/*     rc = sqlite3_close(db); */

/*     return rc; */
/* } */

/* int Direccion::read(int id) { */
/*     sqlite3 *db; */
/*     sqlite3_stmt *stmt; */

/*     int rc = sqlite3_open("Practica_5.db", &db); */

/*     if (rc != SQLITE_OK) { */
/*         std::cerr << "Error opening database" << std::endl; */
/*         sqlite3_close(db); */

/*         return rc; */
/*     } */

/*     std::string sql = std::string("SELECT * FROM Direccion WHERE id = ") + std::to_string(id) + std::string(";"); */

/*     rc = sqlite3_prepare_v2(db, sql.c_str(), -1, &stmt, NULL); */

/*     if (rc != SQLITE_OK) { */
/*         std::cerr << "Error preparing statement" << std::endl; */
/*         sqlite3_close(db); */

/*         return rc; */
/*     } */

/*     while(sqlite3_step(stmt) == SQLITE_ROW) { */
/*         this->id = sqlite3_column_int(stmt, 0); */
/*         this->calle = reinterpret_cast<const char *>(sqlite3_column_text(stmt, 1)); */
/*         this->numero = sqlite3_column_int(stmt, 2); */
/*         this->colonia = reinterpret_cast<const char *>(sqlite3_column_text(stmt, 3)); */
/*         this->municipio = reinterpret_cast<const char *>(sqlite3_column_text(stmt, 4)); */
/*         this->estado = reinterpret_cast<const char *>(sqlite3_column_text(stmt, 5)); */
/*         this->pais = reinterpret_cast<const char *>(sqlite3_column_text(stmt, 6)); */
/*         this->codigoPostal = static_cast<short int>(sqlite3_column_int(stmt, 7)); */
/*     } */

/*     rc = sqlite3_close(db); */

/*     return rc; */
/* } */

/* int Direccion::update() { */
/*     sqlite3 *db; */
/*     sqlite3_stmt *stmt; */

/*     int rc = sqlite3_open("Practica_5.db", &db); */

/*     if (rc != SQLITE_OK) { */
/*         std::cerr << "Error opening database" << std::endl; */
/*         sqlite3_close(db); */

/*         return rc; */
/*     } */

/*     std::string sql = "UPDATE Direccion SET \ */
/*         calle = '" + this->calle + */
/*         "', numero = " + std::to_string(this->numero) + */
/*         ", colonia = '" + this->colonia + */
/*         "', municipio = '" + this->municipio + */
/*         "', estado = '" + this->estado + */
/*         "', pais = '" + this->pais + */
/*         "', codigoPostal = " + std::to_string(this->codigoPostal) + */
/*         " WHERE id = " + std::to_string(this->id) + ";"; */

/*     rc = sqlite3_prepare_v2(db, sql.c_str(), -1, &stmt, NULL); */

/*     if (rc != SQLITE_OK) { */
/*         std::cerr << "Error preparing statement" << std::endl; */
/*         sqlite3_close(db); */

/*         return rc; */
/*     } */

/*     rc = sqlite3_step(stmt); */

/*     if (rc != SQLITE_DONE) { */
/*         std::cerr << "Error updating data" << std::endl; */
/*         sqlite3_close(db); */

/*         return rc; */
/*     } */

/*     rc = sqlite3_close(db); */

/*     return rc; */
/* } */

/* int Direccion::delet() { */
/*     sqlite3 *db; */
/*     sqlite3_stmt *stmt; */

/*     int rc = sqlite3_open("Practica_5.db", &db); */

/*     if (rc != SQLITE_OK) { */
/*         std::cerr << "Error opening database" << std::endl; */
/*         sqlite3_close(db); */

/*         return rc; */
/*     } */

/*     std::string sql = "DELETE FROM Direccion WHERE id = " + std::to_string(this->id) + ";"; */

/*     rc = sqlite3_prepare_v2(db, sql.c_str(), -1, &stmt, NULL); */

/*     if (rc != SQLITE_OK) { */
/*         std::cerr << "Error preparing statement" << std::endl; */
/*         sqlite3_close(db); */

/*         return rc; */
/*     } */

/*     rc = sqlite3_step(stmt); */

/*     if (rc != SQLITE_DONE) { */
/*         std::cerr << "Error deleting data" << std::endl; */
/*         sqlite3_close(db); */

/*         return rc; */
/*     } */

/*     rc = sqlite3_close(db); */

/*     return rc; */
/* } */

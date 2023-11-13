#include "Persona.hpp"

#include <iostream>
//#include <sqlite3.h>

#include "Direccion.hpp"

//Contructors
Persona::Persona() {
    this->id = 0;
    this->nombre = "";
    this->apellido = "";
    this->edad = 0;
    this->direccion = Direccion();
    this->telefono = "";
    this->email = "";
}

Persona::Persona(std::string nombre,
                 std::string apellido,
                 int edad,
                 Direccion direccion,
                 std::string telefono,
                 std::string email) {
    this->id = 0;
    this->nombre = nombre;
    this->apellido = apellido;
    this->edad = edad;
    this->direccion = direccion;
    this->telefono = telefono;
    this->email = email;
}

//Query constructor
/* Persona::Persona(int id) { */
/*     this->read(id); */
/* } */

//Getters
int Persona::getId() {
    return this->id;
}

std::string Persona::getNombre() {
    return this->nombre;
}

std::string Persona::getApellido() {
    return this->apellido;
}

int Persona::getEdad() {
    return this->edad;
}

Direccion Persona::getDireccion() {
    return this->direccion;
}

std::string Persona::getTelefono() {
    return this->telefono;
}

std::string Persona::getEmail() {
    return this->email;
}

//Setters
void Persona::setNombre(std::string nombre) {
    this->nombre = nombre;
}

void Persona::setApellido(std::string apellido) {
    this->apellido = apellido;
}

void Persona::setEdad(int edad) {
    this->edad = edad;
}

void Persona::setDireccion(Direccion direccion) {
    this->direccion = direccion;
}

void Persona::setTelefono(std::string telefono) {
    this->telefono = telefono;
}

void Persona::setEmail(std::string email) {
    this->email = email;
}

//Methods
//I/O
std::ostream& operator << (std::ostream &out, const Persona &persona) {
    out << "ID: " << persona.id << std::endl;
    out << "Nombre: " << persona.nombre << std::endl;
    out << "Apellido: " << persona.apellido << std::endl;
    out << "Edad: " << persona.edad << std::endl;
    out << "Direccion: " << persona.direccion << std::endl;
    out << "Telefono: " << persona.telefono << std::endl;
    out << "Email: " << persona.email << std::endl;


    return out;
}

std::istream& operator >> (std::istream &is, Persona &persona) {
    std::cout << "Nombre: ";
    is >> persona.nombre;
    std::cout << "Apellido: ";
    is >> persona.apellido;
    std::cout << "Edad: ";
    is >> persona.edad;
    std::cout << "Direccion: ";
    is >> persona.direccion;
    std::cout << "Telefono: ";
    is >> persona.telefono;
    std::cout << "Email: ";
    is >> persona.email;

    return is;
}
//SQL Methods
/* int Persona::createTable() { */
/*     sqlite3 *db; */
/*     int rc = sqlite3_open("Practica_5.db", &db); */

/*     if (rc != SQLITE_OK) { */
/*         std::cerr << "Error opening database" << sqlite3_errmsg(db) << std::endl; */
/*         return rc; */
/*     } */

/*     std::string sql = "CREATE TABLE IF NOT EXISTS Persona ( \ */
/*         id INTEGER PRIMARY KEY AUTOINCREMENT, \ */
/*         nombre TEXT NOT NULL, \ */
/*         apellido TEXT NOT NULL, \ */
/*         edad INTEGER NOT NULL, \ */
/*         dirKey INTEGER NOT NULL, \ */
/*         telefono TEXT NOT NULL, \ */
/*         email TEXT NOT NULL, \ */
/*         FOREIGN KEY(dirKey) REFERENCES Direccion(id) \ */
/*         );"; */

/*     rc = sqlite3_exec(db, sql.c_str(), NULL, NULL, NULL); */

/*     if (rc != SQLITE_OK) { */
/*         std::cerr << "Error creating table" << sqlite3_errmsg(db) << std::endl; */
/*         sqlite3_close(db); */

/*         return rc; */
/*     } */

/*     rc = sqlite3_close(db); */

/*     if (rc != SQLITE_OK) { */
/*         std::cerr << "Error closing database: " << sqlite3_errmsg(db) << std::endl; */
/*         return rc; */
/*     } */

/*     return rc; */
/* } */

/* int Persona::create() { */
/*     sqlite3 *db; */
/*     sqlite3_stmt *stmt; */

/*     int rc = sqlite3_open("Practica_5.db", &db); */
/*     char *errorMessage = nullptr; */

/*     int assignedId = 0; */

/*     if (rc != SQLITE_OK) { */
/*         std::cerr << "Error opening database: " << sqlite3_errmsg(db) << std::endl; */
/*         return rc; */
/*     } */

/*     std::string check = "SELECT * FROM Persona WHERE " \ */
/*         "nombre = '" + this->nombre + */
/*         "' AND apellido = '" + this->apellido + */
/*         "' AND edad = " + std::to_string(this->edad) + */
/*         " AND dirKey = " + std::to_string(this->getDireccion().getId()) + */
/*         " AND telefono = '" + this->telefono + */
/*         "' AND email = '" + this->email + "';"; */

/*     rc = sqlite3_prepare_v2(db, check.c_str(), -1, &stmt, NULL); */

/*     if (rc != SQLITE_OK) { */
/*         std::cerr << "Error preparing statement: " << sqlite3_errmsg(db) << std::endl; */
/*         sqlite3_close(db); */
/*         return rc; */
/*     } */

/*     rc = sqlite3_step(stmt); */

/*     if (rc == SQLITE_ROW) { */
/*         std::cerr << "Persona already exists: " << std::endl; */
/*         this->id = sqlite3_column_int(stmt, 0); */

/*         sqlite3_finalize(stmt); */
/*         sqlite3_close(db); */

/*         return rc; */
/*     } */

/*     std::string sql = "INSERT INTO Persona " */
/*         "(nombre, apellido, edad, dirKey, telefono, email) " */
/*         "VALUES ('" + this->nombre + */
/*         "', '" + this->apellido + */
/*         "', " + std::to_string(this->edad) + */
/*         ", " + std::to_string(this->direccion.getId()) + */
/*         ", '" + this->telefono + */
/*         "', '" + this->email + "');"; */

/*     rc = sqlite3_exec(db, sql.c_str(), NULL, NULL, NULL); */

/*     if (rc != SQLITE_OK) { */
/*         std::cerr << "Error inserting data: " << errorMessage << std::endl; */

/*         std::cout << sql << std::endl << rc << std::endl; */

/*         sqlite3_finalize(stmt); */
/*         sqlite3_free(errorMessage); */
/*         sqlite3_close(db); */

/*         return rc; */
/*     } */

/*     this->id = assignedId; */

/*     sqlite3_finalize(stmt); */
/*     rc = sqlite3_close(db); */

/*     return rc; */
/* } */

/* int Persona::read(int id) { */
/*     sqlite3 *db; */
/*     sqlite3_stmt *stmt; */

/*     int rc = sqlite3_open("Practica_5.db", &db); */

/*     if (rc != SQLITE_OK) { */
/*         std::cerr << "Error opening database" << std::endl; */
/*         sqlite3_close(db); */

/*         return rc; */
/*     } */

/*     std::string sql = "SELECT * FROM Persona WHERE id = " + std::to_string(id) + ";"; */

/*     rc = sqlite3_prepare_v3(db, sql.c_str(), -1, 0, &stmt, NULL); */

/*     if (rc != SQLITE_OK) { */
/*         std::cerr << "Error preparing statement" << std::endl; */
/*         sqlite3_close(db); */

/*         return rc; */
/*     } */

/*     while(sqlite3_step(stmt) == SQLITE_ROW) { */
/*         this->id = sqlite3_column_int(stmt, 0); */
/*         this->nombre = std::string(reinterpret_cast<const char*>(sqlite3_column_text(stmt, 1))); */
/*         this->apellido = std::string(reinterpret_cast<const char*>(sqlite3_column_text(stmt, 2))); */
/*         this->edad = sqlite3_column_int(stmt, 3); */
/*         this->direccion.read(sqlite3_column_int(stmt, 4)); */
/*         this->telefono = std::string(reinterpret_cast<const char*>(sqlite3_column_text(stmt, 5))); */
/*         this->email = std::string(reinterpret_cast<const char*>(sqlite3_column_text(stmt, 6))); */
/*     } */

/*     rc = sqlite3_close(db); */

/*     return rc; */
/* } */

/* int Persona::update() { */
/*     sqlite3 *db; */
/*     sqlite3_stmt *stmt; */

/*     int rc = sqlite3_open("Practica_5.db", &db); */

/*     if (rc != SQLITE_OK) { */
/*         std::cerr << "Error opening database" << std::endl; */
/*         sqlite3_close(db); */

/*         return rc; */
/*     } */

/*     std::string sql = "UPDATE Persona SET \ */
/*         nombre = '" + this->nombre + */
/*         "', apellido = '" + this->apellido + */
/*         "', edad = " + std::to_string(this->edad) + */
/*         ", dirKey = " + std::to_string(this->direccion.getId()) + */
/*         ", telefono = '" + this->telefono + */
/*         "', email = '" + this->email + */
/*         "' WHERE id = " + std::to_string(this->id) + ";"; */

/*     rc = sqlite3_exec(db, sql.c_str(), NULL, NULL, NULL); */

/*     if (rc != SQLITE_OK) { */
/*         std::cerr << "Error updating data" << std::endl; */
/*         sqlite3_close(db); */

/*         return rc; */
/*     } */

/*     rc = sqlite3_close(db); */

/*     return rc; */
/* } */

/* int Persona::delet() { */
/*     sqlite3 *db; */

/*     int rc = sqlite3_open("Practica_5.db", &db); */

/*     if (rc != SQLITE_OK) { */
/*         std::cerr << "Error opening database" << std::endl; */
/*         sqlite3_close(db); */

/*         return rc; */
/*     } */

/*     std::string sql = "DELETE FROM Persona WHERE id = " + std::to_string(this->id) + ";"; */

/*     rc = sqlite3_exec(db, sql.c_str(), NULL, NULL, NULL); */

/*     if (rc != SQLITE_OK) { */
/*         std::cerr << "Error deleting data" << std::endl; */
/*         sqlite3_close(db); */

/*         return rc; */
/*     } */

/*     rc = sqlite3_close(db); */

/*     return rc; */
/* } */

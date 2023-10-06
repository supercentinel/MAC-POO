#include "matriz.hpp"

#include <cstdlib>
#include <functional>
#include <iostream>
#include <istream>
#include <ostream>

//Constructors
Matriz::Matriz() {
    this->rows = 0;
    this->cols = 0;
    this->data = NULL;
}

Matriz::Matriz(unsigned int rows, unsigned int cols) {
    this->rows = rows;
    this->cols = cols;

    this->data = (double**) calloc(rows, sizeof(double*));

    for (int i = 0; i < rows; i++) {
        this->data[i] = (double*) calloc(cols, sizeof(double));
    }
}

Matriz::Matriz(const Matriz &otro) {
    int i = 0;
    int j = 0;

    this->rows = otro.rows;
    this->cols = otro.cols;

    this->data = (double**) calloc(rows, sizeof(double*));

    for (i = 0; i < rows; i++) {
        this->data[i] = (double*) calloc(cols, sizeof(double));
        for (j = 0; j < cols; j++) {
            this->data[i][j] = otro.data[i][j];
        }
    }
}

Matriz::Matriz(std::string filename) {

}
//Destructor
Matriz::~Matriz() {
    int i = 0;

    for (i = 0; i < rows; i++) {
        free(this->data[i]);
    }

    free(this->data);
}
// Getters
unsigned int Matriz::getRows() {
    return this->rows;
}

unsigned int Matriz::getCols() {
    return this->cols;
}
//Setters
void Matriz::setData(unsigned int i, unsigned int j, double value) {
    if(i < this->rows && j < this->cols) {
        this->data[i][j] = value;
    }
}
// Methods
std::string Matriz::toTeX(char brackets, unsigned int decimals) {
    std::string TeX = "";
    std::string type = "";
    std::string number = "";
    int i = 0;
    int j = 0;

    // Choose the type of output matrix
    switch (brackets) {
        case ' ':
            type = "matrix";
        case '(':
            type = "pmatrix";
        break;
        case '[':
            type = "bmatrix";
        break;
        case '{':
            type = "Bmatrix";
        break;
        case '|':
            type = "vmatrix";
        break;
        case '\\':
            type = "Vmatrix";
        break;
        case 's':
            type = "smallmatrix";
        break;
        default:
            type = "matrix";
        break;
    }
    //Starts the matrix enviroment
    TeX += "\\begin{" + type + "}\n";

    //Fills the matrix
    for (i = 0; i < this->rows; i++) {
        //Adds a tab for indenting for styling
        TeX += "\t";

        for (j = 0; j < this->cols; j++) {
            //Turns the value a_ij to a sting
            number = std::to_string(this->data[i][j]);
            //Turn it into a substring defined by number of arg 2
            number = number.substr(0, number.find(".") + decimals + 1);
            //cats to the output string
            TeX += number;

            //Adds the separator for each matrix row value
            if(j < this->cols-1) {
                TeX += " & ";
            }
        }
        //Ends the line of the matrix
        TeX += "\\\\\n";
    }
    //Close the enviroment
    TeX += "\\end{" + type + "}\n";

    return TeX;
}

double Matriz::det() {
    int i = 0;
    double determinant = 0.00;

    if(this->rows != this->cols) {
        std::cout << "La matriz no es cuadrada" << std::endl;
    }

    switch(this->rows) {
        case 1:
            determinant = this->data[0][0];
        break;
        case 2:
            determinant = (this->data[0][0] * this->data[1][1]) - (this->data[0][1] * this->data[1][0]);
        break;
        default:
            for(i=0; i<this->rows; i++) {
                determinant += this->data[0][i] * this->cofactor(1, i+1);
            }
        break;
    }

    return determinant;
}

Matriz Matriz::transpose() {
    Matriz transpuesta(this->cols, this->rows);
    int i = 0;
    int j = 0;

    for(i=0; i<this->rows; i++) {
        for(j=0; j<this->cols; j++) {
            transpuesta.data[j][i] = this->data[i][j];
        }
    }

    return transpuesta;
}

Matriz Matriz::minor(unsigned int _i, unsigned int _j) {

    if(this->rows != this->cols) {
        std::cout << "La matriz no es cuadrada" << std::endl;
    }

    if(this->rows == 1 && this->cols == 1) {
        return Matriz();
    }

    Matriz minor(this->rows-1, this->cols-1);

    int i = 0;
    int j = 0;

    for(i=0; i<this->rows; i++) {
        if(i == _i-1) continue;
        for(j=0; j<this->cols; j++) {
            if(j == _j-1) continue;

            if(i < _i-1 && j < _j-1) {
                minor.data[i][j] = this->data[i][j];
            } else if(i < _i-1 && j > _j-1) {
                minor.data[i][j-1] = this->data[i][j];
            } else if(i > _i-1 && j < _j-1) {
                minor.data[i-1][j] = this->data[i][j];
            } else {
                minor.data[i-1][j-1] = this->data[i][j];
            }
        }
    }

    return minor;
}

double Matriz::cofactor(unsigned int _i, unsigned int _j) {
    double cofactor = 0.00;

    if(this->rows != this->cols) {
        std::cout << "La matriz no es cuadrada" << std::endl;
        return 0.00;
    }

    if(_i + _j % 2 == 0) {
        cofactor = this->minor(_i, _j).det();
    } else {
        cofactor = -1 * this->minor(_i, _j).det();
    }

    return cofactor;
}

Matriz Matriz::cofactorMatrix() {
    Matriz cofactorMatrix(this->rows, this->cols);
    int i = 0;
    int j = 0;

    for(i=0; i<this->rows; i++) {
        for(j=0; j<this->cols; j++) {
            cofactorMatrix.data[i][j] = this->cofactor(i+1, j+1);
        }
    }

    return cofactorMatrix;
}

Matriz Matriz::adj() {

    Matriz adj = this->cofactorMatrix().transpose();

    return adj;
}

Matriz Matriz::inverse() {

    Matriz inverse = this->adj() * (1/this->det());

    return inverse;
}
//Operator overloading
// =
Matriz Matriz::operator = (const Matriz &otro) {
    int i = 0;
    int j = 0;

    //free the memory
    for(i=0; i<this->rows; i++) {
        free(this->data[i]);
    }

    free(this->data);

    this->rows = otro.rows;
    this->cols = otro.cols;

    //allocate the memory
    this->data = (double **) calloc(this->rows, sizeof(double *));
    for(i=0; i<this->rows; i++) {
        this->data[i] = (double *) calloc(this->cols, sizeof(double));
    }

    //copy the data
    for(i=0; i<this->rows; i++) {
        for(j=0; j<this->cols; j++) {
            this->data[i][j] = otro.data[i][j];
        }
    }

    return *this;
}
// +
Matriz Matriz::operator + (const Matriz &otro) {
    Matriz suma(this->rows, this->cols);
    int i = 0;
    int j = 0;

    if(this->rows != otro.rows || this->cols != otro.cols) {
        std::cout << "Las matrices no son del mismo tamaño" << std::endl;
        return Matriz();
    }

    for(i=0; i<this->rows; i++) {
        for(j=0; j<this->cols; j++) {
            suma.data[i][j] = this->data[i][j] + otro.data[i][j];
        }
    }

    return suma;
}

Matriz Matriz::operator += (const Matriz &otro) {
    *this = *this + otro;

    return *this;
}
// -
// *
Matriz Matriz::operator * (const Matriz &otro) {
    Matriz producto(this->rows, otro.cols);

    int i = 0;
    int j = 0;
    int k = 0;

    if(this->cols != otro.rows) {
        std::cout << "Las matrices no son compatibles" << std::endl;
        return Matriz();
    }

    for(i=0; i<this->rows; i++) {
        for(j=0; j<otro.cols; j++) {
            for(k=0; k<this->cols; k++) {
                producto.data[i][j] += this->data[i][k] * otro.data[k][j];
            }
        }
    }

    return producto;
}

Matriz Matriz::operator * (const double &escalar) {
    Matriz producto(this->rows, this->cols);

    int i = 0;
    int j = 0;

    for(i=0; i<this->rows; i++) {
        for(j=0; j<this->cols; j++) {
            producto.data[i][j] = this->data[i][j] * escalar;
        }
    }

    return producto;
}

Matriz Matriz::operator *= (const Matriz &otro) {
    *this = *this * otro;

    return *this;
}

Matriz Matriz::operator *= (const double &escalar) {
    *this = *this * escalar;

    return *this;
}

//I/O
std::ostream & operator << (std::ostream &out, const Matriz &m) {
    int i = 0;
    int j = 0;

    for(i=0; i<m.rows; i++) {
        for(j=0; j<m.cols; j++) {
            out << m.data[i][j] << " ";
        }
        out << std::endl;
    }

    return out;
}

std::istream & operator >> (std::istream &in, Matriz &m) {
    int i = 0;
    int j = 0;

    std::cout << "Filas: ";
    in >> m.rows;
    std::cout << "Columnas: ";
    in >> m.cols;

    m.data = (double**) realloc(m.data, m.rows * sizeof(double*));

    for(i=0; i<m.rows; i++) {
        m.data[i] = (double*) realloc(m.data[i], m.cols * sizeof(double));
        for(j=0; j<m.cols; j++) {
            std::cout << "[" << i << "][" << j << "]: ";
            in >> m.data[i][j];
        }
    }

    return in;
}

#include "matriz.hpp"

#include <iostream>

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

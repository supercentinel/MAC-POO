#ifndef FRACCION_HPP
#define FRACCION_HPP

#include <iostream>
#include <istream>

class Fraccion{
    private:
        int a;
        int b;
    public:
        Fraccion();
        Fraccion(int a, int b);
        //Getters
        int getA();
        int getB();
        //Setters
        void setA(int a);
        void setB(int b);
        //Methods
        std::string toLatex();
        void normalize();
        void reduce();
        //Convert to other types
        int toInt();
        float toFloat();
        double toDouble();
        //Operator Overload
        // +
        Fraccion operator + (const Fraccion &otro);
        Fraccion operator + (int otro);
        Fraccion operator += (const Fraccion &otro);
        Fraccion operator += (int otro);
        Fraccion operator ++ (int);
        // -
        Fraccion operator - (const Fraccion &otro);
        Fraccion operator - (int otro);
        Fraccion operator -= (const Fraccion &otro);
        Fraccion operator -= (int otro);
        Fraccion operator -- (int);
        // *
        Fraccion operator * (const Fraccion &otro);
        Fraccion operator * (int otro);
        Fraccion operator *= (const Fraccion &otro);
        Fraccion operator *= (int otro);
        // /
        Fraccion operator / (const Fraccion &otro);
        Fraccion operator / (int otro);
        Fraccion operator /= (const Fraccion &otro);
        Fraccion operator /= (int otro);
        // order
        bool operator == (const Fraccion &otro);
        bool operator == (int otro);
        bool operator != (const Fraccion &otro);
        bool operator != (int otro);
        bool operator < (const Fraccion &otro);
        bool operator < (int otro);
        bool operator > (const Fraccion &otro);
        bool operator > (int otro);
        bool operator <= (const Fraccion &otro);
        bool operator <= (int otro);
        bool operator >= (const Fraccion &otro);
        bool operator >= (int otro);

        // I/O
        friend std::ostream & operator << (std::ostream &out, const Fraccion &f);
        friend std::istream & operator >> (std::istream &in, Fraccion &f);
};
#endif

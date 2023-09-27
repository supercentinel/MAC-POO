#ifndef FRACCION_HPP
#define FRACCION_HPP

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
        //Operator Overload
        // +
        Fraccion operator + (const Fraccion &otro);
        Fraccion operator + (int otro);
        Fraccion operator += (const Fraccion &otro);
        Fraccion operator += (int otro);
        Fraccion operator ++ ();
        // -
        Fraccion operator - (const Fraccion &otro);
        Fraccion operator - (int otro);
        Fraccion operator -= (const Fraccion &otro);
        Fraccion operator -= (int otro);
        Fraccion operator -- ();
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
};

#endif

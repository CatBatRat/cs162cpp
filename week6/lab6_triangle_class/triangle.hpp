#ifndef __LAB6__
#define __LAB6__

class Triangle
{
    int sideA;
    int sideB;
    int sideC;
public:
    Triangle(): sideA(3), sideB(4), sideC(5) {}
    Triangle( int A, int B, int C )
        { setA( A ); setB( B ); setC( C ); }
    void setA( int A );
    void setB( int B );
    void setC( int C );
    int getA();
    int getB();
    int getC();
    bool isEquilateral();
    bool isScalene();
    bool isIsosceles();
    bool isRight();

};

#endif // __LAB6__

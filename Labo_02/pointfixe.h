#ifndef POINTFIXE_H
#define POINTFIXE_H


class PointFixe
{
    public:
        /** Default constructor */
        PointFixe(double ptDepart, double ptFin, double lam);
        /** Default destructor */
        virtual ~PointFixe();
    protected:

//        Manque les fonction de traitement

    private:
        double pointDepart;
        double pointFin;
        double lambda;
};

#endif // POINTFIXE_H

#ifndef SQUAREMATRIX_H
#define SQUAREMATRIX_H


class SquareMatrix
{
    public:
        SquareMatrix(int n);
        virtual ~SquareMatrix();

        void add();
        void sub();

    protected:
    private:
        int** matrix;
};

#endif // SQUAREMATRIX_H

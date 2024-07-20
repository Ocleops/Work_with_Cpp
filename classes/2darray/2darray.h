#ifndef 2DARRAY_H
#define 2DARRAY_H

template <typename T>
class 2darray
{
    public:
        2darray<T>(int a, int b):
            lines(a),
            columns(b)
        {
            ptr = new T[lines*columns];

            for(auto i=0; i<lines; i++){
                for(auto j=0; j<columns; j++){
                    ptr[i*columns + j] = i*columns+j;
                }
            }

        }

        void print();

    private:
        int columns;
        int lines;
        T *ptr;

};

#endif // 2DARRAY_H

#ifndef ARRAY2D_H
#define ARRAY2D_H

template<typename T>
class Array2d
{
    public:
        Array2d(int a, int b):
            lines(a),
            columns(b)
        {
            ptr = new T[(lines+1)*(columns+1)];

            for(auto i=0; i<lines; i++){
                for(auto j=0; j<columns; j++){
                    ptr[(i+1)*columns + (j+1)] = i*columns+j + 1;
                }
            }

        }

        Array2d(const Array2d<T>& other)
        {
            lines = other.lines;
            columns = other.columns;
            ptr = other.ptr;
        }

        Array2d(){}

    void print();
    T& operator()(int, int);
    Array2d<T>& operator=(Array2d<T> &);
    int size();
    int dim(int);


    ~Array2d<T>()
        {
            //std::cout<<"\n\n"<<"I am the DESTRUCTOR!!\n"<<"I will DESTROYYY!!\n";
            delete [] ptr;
        }


    private:
        int columns;
        int lines;
        T *ptr;


};

#endif // ARRAY2D_H

#ifndef ARRAY_H
#define ARRAY_H


template <typename T>
class Array
{
    public:
        Array<T>(int a):
            length(a)
        {
            pa = new T[a];
            for(auto i=0; i<a; i++){
                pa[i] = 1;
            }
        }

        Array<T>(const Array<T> & other)
        {
           length = other.length;
           T *new_ptr;
           new_ptr = new T[length];
           for(auto i=0; i<length; i++){
                new_ptr[i] = other.pa[i];
           }
           pa=new_ptr;
        }


        ~Array<T>()
        {
            delete [] pa;
        }

        void print();

        T& operator[](int);
        Array<T>& operator=(Array<T>);
        Array<T>& operator=(T x[]);
        Array<T>& my_fill(T);
        int Get_size();


    private:
        T *pa;
        int length;

};

#endif // ARRAY_H

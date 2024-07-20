#ifndef DATE_H
#define DATE_H


class Date
{
    public:
        Date();
        Date(int, int, int);
        ~Date();

        void print();
        int get_n_days(int, int);

        Date operator+(Date);
        Date operator-(Date);
        bool operator>(Date);
        bool operator==(Date);
        //Date operator=(Date);

    private:
        int day, month, year, number_of_days;
};

#endif // DATE_H

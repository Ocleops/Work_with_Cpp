#ifndef PPGM_H
#define PPGM_H


class ppgm
{
    public:
        ppgm(std::string);
        ppgm(ppgm &);
        ~ppgm();
        int Width();
        int Height();
        void write(std::string);
        void blur(int );
        void rotate(int);
        void crop(int, int, int, int);


    private:
        int height;
        int weidth;
        int K;
        std::vector<int> image;
};

#endif // PPGM_H

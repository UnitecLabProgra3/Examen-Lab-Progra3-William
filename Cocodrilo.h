#ifndef COCODRILO_H
#define COCODRILO_H

#include "Enemigo.h"
class Cocodrilo : public Enemigo
{
    public:
        Cocodrilo(Personaje*personaje);

        void patron_Mov();
        virtual ~Cocodrilo();
    protected:
    private:
};

#endif // COCODRILO_H

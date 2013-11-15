#ifndef LLAMA_H
#define LLAMA_H


#include "Enemigo.h"

class LLama : public Enemigo
{
    public:
        LLama(Personaje *personaje);

        void patron_Mov();
        virtual ~LLama();
    protected:
    private:
};

#endif // LLAMA_H

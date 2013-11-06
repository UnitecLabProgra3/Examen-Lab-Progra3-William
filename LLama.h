#ifndef LLAMA_H
#define LLAMA_H


#include "Enemigo.h"

class LLama : public Enemigo
{
    public:
        LLama(Personaje *personaje);
        void logica(Personaje *personaje);
        virtual ~LLama();
    protected:
    private:
};

#endif // LLAMA_H

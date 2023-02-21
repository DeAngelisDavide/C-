//
// Created by 39331 on 30/09/2021.
//

#include "anfora.h"

anfora::anfora(int cp) { capacita = cp;}

void anfora::riempi() { versa(capacita - getQt());}

void anfora::svuota() { togli( getQt());}

bool anfora::isPiena() { return getQt() == capacita;}

bool anfora::isVuota() { return getQt() == 0;}

void anfora::spostaContenutoAnfora(anfora &a)
{

    int lt = a.capacita - a.getQt(); //Quanto l'anfora può ancora contenere

    if (lt > getQt())         //Se è maggiore della quantità nell'anfora corrente
    {
        a.versa(getQt());      //Versa tutto il contenuto nell'antra anfora e svuota qualla corrente
        svuota();
    }else  //Se minore
        {
        a.versa(lt);    //Versa la quantità che può contenere e togli lo stesso contenuto dall'anfora corrente
        togli(lt);
        }
}
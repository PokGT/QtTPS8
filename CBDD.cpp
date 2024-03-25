#include "CBBD.h"

CBDD* CBDD::CBDD_singleton;

CBDD::CBDD(){

}
CBDD* CBDD::GetInstance()
{
    if(CBDD_singleton==nullptr){
        CBDD_singleton = new CBDD();
    }
    return CBDD_singleton;
}

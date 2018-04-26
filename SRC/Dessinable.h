#pragma once
#include "SupportADessin.h"

class Dessinable {
  public:
    Dessinable(SupportADessin* sup);
    virtual ~Dessinable() {}
    virtual void dessine() = 0;
  protected:
    SupportADessin* support;
};

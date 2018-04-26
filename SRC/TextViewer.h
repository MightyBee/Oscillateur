#pragma once
#include "SupportADessin.h"
#include "Oscillateur.h"

class TextViewer : public SupportADessin {
  public:
    TextViewer(std::ostream& flot);
    virtual void dessine(Pendule const&) override;
    virtual void dessine(Ressort const&) override;
  private:
    std::ostream& flot;
};

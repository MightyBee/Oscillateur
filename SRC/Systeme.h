#pragma once
#include <memory>
#include <vector>


class Systeme : public Dessinable {
  public:
    Systeme(SupportADessin* sup, Integrateur const& integrat, double t=0);
    ~Systeme();
    void add(Oscillateur const& osc);
    void evolue(double dt);
    virtual void dessine override;

  private:
    std::unique_ptr<Integrateur> integrateur;
    double temps;
    std::vector<std::unique_ptr<Oscillateur>> collection;
};

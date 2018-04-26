#pragma once

class Pendule;
class Ressort;

class SupportADessin
{
 public:

  virtual ~SupportADessin() {}

  virtual void dessine(Pendule const&) = 0;
  virtual void dessine(Ressort const&) = 0;
  //virtual void dessine(Systeme const&) = 0;
  // ... autres choses que vous voudriez dessiner...
};

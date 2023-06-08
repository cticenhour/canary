#pragma once

#include "ADMaterial.h"

/**
 * Material used to compute properties for the Laplace Young example problem.
 */
class LaplaceYoungMaterial : public ADMaterial
{
public:
  LaplaceYoungMaterial(const InputParameters & parameters);

  static InputParameters validParams();

protected:
  virtual void computeQpProperties() override;

private:
  const ADVariableGradient & _grad_var;

  ADMaterialProperty<Real> & _k;
};

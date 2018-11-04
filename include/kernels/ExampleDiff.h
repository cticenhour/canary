#ifndef EXAMPLEDIFF_H
#define EXAMPLEDIFF_H

#include "Diffusion.h"

class ExampleDiff;

template<>
InputParameters validParams<ExampleDiff>();

/**
 *
 */
class ExampleDiff : public Diffusion
{
public:
  ExampleDiff(const InputParameters & parameters);

protected:
  virtual Real computeQpResidual() override;
  virtual Real computeQpJacobian() override;
};

#endif // EXAMPLEDIFF_H

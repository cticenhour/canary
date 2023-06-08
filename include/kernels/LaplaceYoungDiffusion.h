//* This file is part of the Canary application, which is based on MOOSE
//* https://www.mooseframework.inl.gov
//*
//* Licensed under LGPL 2.1, please see LICENSE for details
//* https://www.gnu.org/licenses/lgpl-2.1.html

#pragma once

#include "ADDiffusion.h"

/**
 *
 */
class LaplaceYoungDiffusion : public ADDiffusion
{
public:
  LaplaceYoungDiffusion(const InputParameters & parameters);

  static InputParameters validParams();

protected:
  virtual ADRealVectorValue precomputeQpResidual() override;
};

//* This file is part of the Canary application, which is based on MOOSE
//* https://www.mooseframework.inl.gov
//*
//* Licensed under LGPL 2.1, please see LICENSE for details
//* https://www.gnu.org/licenses/lgpl-2.1.html

#include "LaplaceYoungMaterial.h"

registerMooseObject("CanaryApp", LaplaceYoungMaterial);

InputParameters
LaplaceYoungMaterial::validParams()
{
  InputParameters params = ADMaterial::validParams();
  params.addClassDescription("Material used to compute properties for the Laplace Young example problem.");
  params.addRequiredCoupledVar("coupled_variable", "Variable used to calculate properties for the Laplace Young example problem.");
  return params;
}

LaplaceYoungMaterial::LaplaceYoungMaterial(const InputParameters & parameters)
  : Material(parameters),
    _grad_var(adCoupledGradient("coupled_variable")),
    _k(declareADProperty<Real>("laplace_k"))
{
}

void
LaplaceYoungMaterial::computeQpProperties()
{
  _k[_qp] = 1 / std::sqrt(1 + (_grad_var[_qp](0) * _grad_var[_qp](0) + _grad_var[_qp](1) * _grad_var[_qp](1) +
                             _grad_var[_qp](2) * _grad_var[_qp](2)));
}

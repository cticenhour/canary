//* This file is part of the Canary application, which is based on MOOSE
//* https://www.mooseframework.inl.gov
//*
//* Licensed under LGPL 2.1, please see LICENSE for details
//* https://www.gnu.org/licenses/lgpl-2.1.html

#include "LaplaceYoungDiffusion.h"

registerMooseObject("CanaryApp", LaplaceYoungDiffusion);

InputParameters
LaplaceYoungDiffusion::validParams()
{
  InputParameters params = Diffusion::validParams();
  params.addClassDescription("");
  return params;
}

LaplaceYoungDiffusion::LaplaceYoungDiffusion(const InputParameters & parameters) : Diffusion(parameters) {}

Real
LaplaceYoungDiffusion::computeQpResidual()
{
  return (1 / std::sqrt(1 + (_grad_u[_qp](0) * _grad_u[_qp](0) + _grad_u[_qp](1) * _grad_u[_qp](1) +
                             _grad_u[_qp](2) * _grad_u[_qp](2)))) *
         Diffusion::computeQpResidual();
}

Real
LaplaceYoungDiffusion::computeQpJacobian()
{
  return (1 / std::sqrt(1 + (_grad_u[_qp](0) * _grad_u[_qp](0) + _grad_u[_qp](1) * _grad_u[_qp](1) +
                             _grad_u[_qp](2) * _grad_u[_qp](2)))) *
         Diffusion::computeQpJacobian();
}

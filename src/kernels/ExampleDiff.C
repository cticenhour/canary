#include "ExampleDiff.h"

registerMooseObject("canaryApp", ExampleDiff);

template <>
InputParameters
validParams<ExampleDiff>()
{
  InputParameters params = validParams<Diffusion>();
  params.addClassDescription("");
  return params;
}

ExampleDiff::ExampleDiff(const InputParameters & parameters) : Diffusion(parameters) {}

Real
ExampleDiff::computeQpResidual()
{
  return (1 / std::sqrt(1 + (_grad_u[_qp](0) * _grad_u[_qp](0) + _grad_u[_qp](1) * _grad_u[_qp](1) +
                             _grad_u[_qp](2) * _grad_u[_qp](2)))) *
         Diffusion::computeQpResidual();
}

Real
ExampleDiff::computeQpJacobian()
{
  return (1 / std::sqrt(1 + (_grad_u[_qp](0) * _grad_u[_qp](0) + _grad_u[_qp](1) * _grad_u[_qp](1) +
                             _grad_u[_qp](2) * _grad_u[_qp](2)))) *
         Diffusion::computeQpJacobian();
}

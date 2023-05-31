//* This file is part of the Canary application, which is based on MOOSE
//* https://www.mooseframework.inl.gov
//*
//* Licensed under LGPL 2.1, please see LICENSE for details
//* https://www.gnu.org/licenses/lgpl-2.1.html
#ifndef CANARYAPP_H
#define CANARYAPP_H

#include "MooseApp.h"

class CanaryApp;

template <>
InputParameters validParams<CanaryApp>();

class CanaryApp : public MooseApp
{
public:
  CanaryApp(InputParameters parameters);
  virtual ~CanaryApp();

  static void registerApps();
  static void registerAll(Factory & f, ActionFactory & af, Syntax & s);
};

#endif /* CANARYAPP_H */

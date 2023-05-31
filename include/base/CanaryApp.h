//* This file is part of the MOOSE framework
//* https://www.mooseframework.org
//*
//* All rights reserved, see COPYRIGHT for full restrictions
//* https://github.com/idaholab/moose/blob/master/COPYRIGHT
//*
//* Licensed under LGPL 2.1, please see LICENSE for details
//* https://www.gnu.org/licenses/lgpl-2.1.html
#ifndef CANARYAPP_H
#define CANARYAPP_H

#include "MooseApp.h"

class canaryApp;

template <>
InputParameters validParams<canaryApp>();

class canaryApp : public MooseApp
{
public:
  canaryApp(InputParameters parameters);
  virtual ~canaryApp();

  static void registerApps();
  static void registerAll(Factory & f, ActionFactory & af, Syntax & s);
};

#endif /* CANARYAPP_H */

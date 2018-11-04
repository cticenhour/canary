//* This file is part of the MOOSE framework
//* https://www.mooseframework.org
//*
//* All rights reserved, see COPYRIGHT for full restrictions
//* https://github.com/idaholab/moose/blob/master/COPYRIGHT
//*
//* Licensed under LGPL 2.1, please see LICENSE for details
//* https://www.gnu.org/licenses/lgpl-2.1.html
#ifndef CANARYTESTAPP_H
#define CANARYTESTAPP_H

#include "MooseApp.h"

class canaryTestApp;

template <>
InputParameters validParams<canaryTestApp>();

class canaryTestApp : public MooseApp
{
public:
  canaryTestApp(InputParameters parameters);
  virtual ~canaryTestApp();

  static void registerApps();
  static void registerAll(Factory & f, ActionFactory & af, Syntax & s, bool use_test_objs = false);
};

#endif /* CANARYTESTAPP_H */

//* This file is part of the Canary application, which is based on MOOSE
//* https://www.mooseframework.inl.gov
//*
//* Licensed under LGPL 2.1, please see LICENSE for details
//* https://www.gnu.org/licenses/lgpl-2.1.html
#ifndef CanaryTestApp_H
#define CanaryTestApp_H

#include "MooseApp.h"

class CanaryTestApp;

template <>
InputParameters validParams<CanaryTestApp>();

class CanaryTestApp : public MooseApp
{
public:
  CanaryTestApp(InputParameters parameters);
  virtual ~CanaryTestApp();

  static void registerApps();
  static void registerAll(Factory & f, ActionFactory & af, Syntax & s, bool use_test_objs = false);
};

#endif /* CanaryTestApp_H */

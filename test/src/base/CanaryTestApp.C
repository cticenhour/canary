//* This file is part of the MOOSE framework
//* https://www.mooseframework.org
//*
//* All rights reserved, see COPYRIGHT for full restrictions
//* https://github.com/idaholab/moose/blob/master/COPYRIGHT
//*
//* Licensed under LGPL 2.1, please see LICENSE for details
//* https://www.gnu.org/licenses/lgpl-2.1.html
#include "canaryTestApp.h"
#include "canaryApp.h"
#include "Moose.h"
#include "AppFactory.h"
#include "MooseSyntax.h"
#include "ModulesApp.h"

template <>
InputParameters
validParams<canaryTestApp>()
{
  InputParameters params = validParams<canaryApp>();
  return params;
}

canaryTestApp::canaryTestApp(InputParameters parameters) : MooseApp(parameters)
{
  canaryTestApp::registerAll(
      _factory, _action_factory, _syntax, getParam<bool>("allow_test_objects"));
}

canaryTestApp::~canaryTestApp() {}

void
canaryTestApp::registerAll(Factory & f, ActionFactory & af, Syntax & s, bool use_test_objs)
{
  canaryApp::registerAll(f, af, s);
  if (use_test_objs)
  {
    Registry::registerObjectsTo(f, {"canaryTestApp"});
    Registry::registerActionsTo(af, {"canaryTestApp"});
  }
}

void
canaryTestApp::registerApps()
{
  registerApp(canaryApp);
  registerApp(canaryTestApp);
}

/***************************************************************************************************
 *********************** Dynamic Library Entry Points - DO NOT MODIFY ******************************
 **************************************************************************************************/
// External entry point for dynamic application loading
extern "C" void
canaryTestApp__registerAll(Factory & f, ActionFactory & af, Syntax & s)
{
  canaryTestApp::registerAll(f, af, s);
}
extern "C" void
canaryTestApp__registerApps()
{
  canaryTestApp::registerApps();
}

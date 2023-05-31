//* This file is part of the Canary application, which is based on MOOSE
//* https://www.mooseframework.inl.gov
//*
//* Licensed under LGPL 2.1, please see LICENSE for details
//* https://www.gnu.org/licenses/lgpl-2.1.html
#include "CanaryTestApp.h"
#include "CanaryApp.h"
#include "Moose.h"
#include "AppFactory.h"
#include "MooseSyntax.h"
#include "ModulesApp.h"

template <>
InputParameters
validParams<CanaryTestApp>()
{
  InputParameters params = validParams<CanaryApp>();
  return params;
}

CanaryTestApp::CanaryTestApp(InputParameters parameters) : MooseApp(parameters)
{
  CanaryTestApp::registerAll(
      _factory, _action_factory, _syntax, getParam<bool>("allow_test_objects"));
}

CanaryTestApp::~CanaryTestApp() {}

void
CanaryTestApp::registerAll(Factory & f, ActionFactory & af, Syntax & s, bool use_test_objs)
{
  CanaryApp::registerAll(f, af, s);
  if (use_test_objs)
  {
    Registry::registerObjectsTo(f, {"CanaryTestApp"});
    Registry::registerActionsTo(af, {"CanaryTestApp"});
  }
}

void
CanaryTestApp::registerApps()
{
  registerApp(CanaryApp);
  registerApp(CanaryTestApp);
}

/***************************************************************************************************
 *********************** Dynamic Library Entry Points - DO NOT MODIFY ******************************
 **************************************************************************************************/
// External entry point for dynamic application loading
extern "C" void
CanaryTestApp__registerAll(Factory & f, ActionFactory & af, Syntax & s)
{
  CanaryTestApp::registerAll(f, af, s);
}
extern "C" void
CanaryTestApp__registerApps()
{
  CanaryTestApp::registerApps();
}

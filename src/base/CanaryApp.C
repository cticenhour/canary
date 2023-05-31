//* This file is part of the Canary application, which is based on MOOSE
//* https://www.mooseframework.inl.gov
//*
//* Licensed under LGPL 2.1, please see LICENSE for details
//* https://www.gnu.org/licenses/lgpl-2.1.html

#include "CanaryApp.h"
#include "Moose.h"
#include "AppFactory.h"
#include "ModulesApp.h"
#include "MooseSyntax.h"

InputParameters
CanaryApp::validParams()
{
  InputParameters params = MooseApp::validParams();
  return params;
}

CanaryApp::CanaryApp(InputParameters parameters) : MooseApp(parameters)
{
  CanaryApp::registerAll(_factory, _action_factory, _syntax);
}

CanaryApp::~CanaryApp() {}

void
CanaryApp::registerAll(Factory & f, ActionFactory & af, Syntax & s)
{
  ModulesApp::registerAll(f, af, s);
  Registry::registerObjectsTo(f, {"CanaryApp"});
  Registry::registerActionsTo(af, {"CanaryApp"});

  /* register custom execute flags, action syntax, etc. here */
}

void
CanaryApp::registerApps()
{
  registerApp(CanaryApp);
}

/***************************************************************************************************
 *********************** Dynamic Library Entry Points - DO NOT MODIFY ******************************
 **************************************************************************************************/
extern "C" void
CanaryApp__registerAll(Factory & f, ActionFactory & af, Syntax & s)
{
  CanaryApp::registerAll(f, af, s);
}
extern "C" void
CanaryApp__registerApps()
{
  CanaryApp::registerApps();
}

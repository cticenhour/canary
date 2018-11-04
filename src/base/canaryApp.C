#include "canaryApp.h"
#include "Moose.h"
#include "AppFactory.h"
#include "ModulesApp.h"
#include "MooseSyntax.h"

template <>
InputParameters
validParams<canaryApp>()
{
  InputParameters params = validParams<MooseApp>();
  return params;
}

canaryApp::canaryApp(InputParameters parameters) : MooseApp(parameters)
{
  canaryApp::registerAll(_factory, _action_factory, _syntax);
}

canaryApp::~canaryApp() {}

void
canaryApp::registerAll(Factory & f, ActionFactory & af, Syntax & s)
{
  ModulesApp::registerAll(f, af, s);
  Registry::registerObjectsTo(f, {"canaryApp"});
  Registry::registerActionsTo(af, {"canaryApp"});

  /* register custom execute flags, action syntax, etc. here */
}

void
canaryApp::registerApps()
{
  registerApp(canaryApp);
}

/***************************************************************************************************
 *********************** Dynamic Library Entry Points - DO NOT MODIFY ******************************
 **************************************************************************************************/
extern "C" void
canaryApp__registerAll(Factory & f, ActionFactory & af, Syntax & s)
{
  canaryApp::registerAll(f, af, s);
}
extern "C" void
canaryApp__registerApps()
{
  canaryApp::registerApps();
}

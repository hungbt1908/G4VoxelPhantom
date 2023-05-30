#include "ActionInitialization.hh"

ActionInitialization::ActionInitialization()
{}

ActionInitialization::~ActionInitialization()
{}

void ActionInitialization::Build() const
{
	PrimaryGeneratorAction *generator = new PrimaryGeneratorAction();
	SetUserAction(generator);
	
}  


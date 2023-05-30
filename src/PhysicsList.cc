#include "PhysicsList.hh"

PhysicsList::PhysicsList() 
: G4VModularPhysicsList(){
  SetVerboseLevel(1);

  // Default physics
  RegisterPhysics(new G4DecayPhysics());

  // EM physics
  RegisterPhysics(new G4EmStandardPhysics());

  // Radioactive decay
  RegisterPhysics(new G4RadioactiveDecayPhysics());
}

PhysicsList::~PhysicsList()
{ 
}

void PhysicsList::SetCuts()
{
  G4VUserPhysicsList::SetCuts();
}  

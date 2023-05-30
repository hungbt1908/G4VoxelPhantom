#include "PhantomMessenger.hh"
#include "DetectorConstruction.hh"
#include "G4UIdirectory.hh"
#include "G4UIcmdWithAString.hh"

PhantomMessenger::PhantomMessenger(DetectorConstruction* myUsrPhtm)
    : fUserPhantom(myUsrPhtm)
{ 
    fPhantomDir = new G4UIdirectory("/phantom/");
    fPhantomDir -> SetGuidance("Set Your Phantom.");
    
    fSexCmd = new G4UIcmdWithAString("/phantom/setPhantomSex",this);
    fSexCmd -> SetGuidance("Set sex of Phantom: Male or Female.");
    fSexCmd -> SetParameterName("phantomSex",true);
    fSexCmd -> SetDefaultValue("female");
    fSexCmd -> SetCandidates("male female");
    fSexCmd -> AvailableForStates(G4State_PreInit,G4State_Idle); 
    
    fSectionCmd = new G4UIcmdWithAString("/phantom/setPhantomSection",this);
    fSectionCmd -> SetGuidance("Set section of Phantom: head, trunk or full");
    fSectionCmd -> SetParameterName("phantomSection",true);
    fSectionCmd -> SetDefaultValue("head");
    fSectionCmd -> SetCandidates("head trunk full");
    fSectionCmd -> AvailableForStates(G4State_PreInit,G4State_Idle);  
}

PhantomMessenger::~PhantomMessenger()
{
    delete  fSexCmd;
    delete  fSectionCmd;
    delete  fPhantomDir;
}

void PhantomMessenger::SetNewValue(G4UIcommand* command,G4String newValue)
{ 
     
    if(command == fSexCmd)
    { 
        fUserPhantom -> SetPhantomSex(newValue);
        //G4cout << "Phantom Messenger calls upon SetPhantomSex in Detector Construction. " << G4endl; 
    }
    if(command == fSectionCmd)
    {
        fUserPhantom -> SetPhantomSection(newValue);
        //G4cout << "Phantom Messenger calls upon SetPhantomSection in Detector Construction. " << G4endl;
    }
}




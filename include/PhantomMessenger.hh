#ifndef PhantomMessenger_h
#define PhantomMessenger_h 1

#include "G4UImessenger.hh"
#include "globals.hh"

class DetectorConstruction;
class G4UIcommand;
class G4UIdirectory;
class G4UIcmdWithAString;

class PhantomMessenger: public G4UImessenger
{
public:
    PhantomMessenger(DetectorConstruction* myUsrPhtm);
    ~PhantomMessenger();    
    void SetNewValue(G4UIcommand* command, G4String newValue);

private:
    DetectorConstruction* fUserPhantom;
    G4UIdirectory* fPhantomDir;
    G4UIcmdWithAString* fSexCmd; 
    G4UIcmdWithAString* fSectionCmd;
};
#endif


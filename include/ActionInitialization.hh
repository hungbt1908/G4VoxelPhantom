#ifndef ActionInitialization_h
#define ActionInitialization_h 1

#include "G4VUserActionInitialization.hh"
#include "PrimaryGeneratorAction.hh"

class ActionInitialization : public G4VUserActionInitialization
{
public:
	ActionInitialization();
	virtual ~ActionInitialization();

    	virtual void Build() const;
};
#endif

    

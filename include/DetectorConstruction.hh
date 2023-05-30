#ifndef DetectorConstruction_h
#define DetectorConstruction_h 1

#include "G4VUserDetectorConstruction.hh"
#include "globals.hh"
#include <map>

class PhantomMaterialFemale;
class PhantomMaterialMale;
class PhantomMessenger;

class DetectorConstruction : public G4VUserDetectorConstruction
{

public:
	DetectorConstruction();
	~DetectorConstruction();
	
	virtual G4VPhysicalVolume* Construct();

	inline G4int GetNumberVoxelX(){return fNVoxelX;};
	inline G4int GetNumberVoxelY() {return fNVoxelY;};
	inline G4int GetNumberVoxelZ() {return fNVoxelZ;};

	void SetPhantomSex(G4String);
	void SetPhantomSection(G4String);

private:
	void ReadPhantomData(const G4String& sex, const G4String& section);
	void ReadPhantomDataFile(const G4String& sex, const G4String& fname, G4int);
	PhantomMaterialFemale* fPhantomMaterialFemale;
	PhantomMaterialMale* fPhantomMaterialMale;
	PhantomMessenger* fMessenger;

	G4int fNVoxelX;
  	G4int fNVoxelY; 
  	G4int fNVoxelZ;

	G4double fVoxelHalfDimX;
  	G4double fVoxelHalfDimY;
  	G4double fVoxelHalfDimZ;

	G4double fMinX;
  	G4double fMaxX;
  	G4double fMinY;
  	G4double fMaxY;
  	G4double fMinZ;
  	G4double fMaxZ;

	G4int fNoFiles;
  	G4int fNVoxels;
  	size_t* fMateIDs; // index of material of each voxel
 	G4String fSex;
 	G4String fSection;
};

#endif

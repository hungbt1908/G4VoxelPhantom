#include "PrimaryGeneratorAction.hh"

#include "G4ParticleGun.hh"
#include "G4ParticleTable.hh"
#include "G4ParticleDefinition.hh"
#include "G4SystemOfUnits.hh"
#include "G4ios.hh"
#include "G4Event.hh"
#include "Randomize.hh"

PrimaryGeneratorAction::PrimaryGeneratorAction()
{
    fParticleGun  = new G4ParticleGun(1);

    // default particle kinematic
    G4ParticleTable* particleTable = G4ParticleTable::GetParticleTable();
    G4String particleName;
    G4ParticleDefinition* particle = particleTable->FindParticle(particleName="gamma");
    fParticleGun->SetParticleDefinition(particle);
    fParticleGun->SetParticleEnergy(6.*MeV);
}

PrimaryGeneratorAction::~PrimaryGeneratorAction()
{
  	delete fParticleGun;
}

void PrimaryGeneratorAction::GeneratePrimaries(G4Event* anEvent)
{
    //vertex position fixed
    //
    G4double x0 = 0.*cm, y0 = 0.*cm, z0 = -200. *cm;
    fParticleGun->SetParticlePosition(G4ThreeVector(x0,y0,z0));

    //direction uniform in solid angle
    //
    //solid angle
    //
    G4double alphaMin =  0*deg;      //alpha in [0,pi]
    G4double alphaMax = 15*deg;
    G4double fCosAlphaMin, fCosAlphaMax;      //solid angle
	G4double fPsiMin, fPsiMax;
    fCosAlphaMin = std::cos(alphaMin);
    fCosAlphaMax = std::cos(alphaMax);
    
    fPsiMin = 0*deg;       //psi in [0, 2*pi]
    fPsiMax = 360*deg;

    G4double cosAlpha = fCosAlphaMin-G4UniformRand()*(fCosAlphaMin-fCosAlphaMax);
    G4double sinAlpha = std::sqrt(1. - cosAlpha*cosAlpha);
    G4double psi = fPsiMin + G4UniformRand()*(fPsiMax - fPsiMin);

    G4double ux = sinAlpha*std::cos(psi),
             uy = sinAlpha*std::sin(psi),
             uz = cosAlpha;

    fParticleGun->SetParticleMomentumDirection(G4ThreeVector(ux,uy,uz));

    fParticleGun->GeneratePrimaryVertex(anEvent);
}


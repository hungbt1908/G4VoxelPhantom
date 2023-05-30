#ifndef PhantomMaterialFemale_h
#define PhantomMaterialFemale_h 1

#include "globals.hh"

class G4Material;

class PhantomMaterialFemale
{
public:
    PhantomMaterialFemale();
    ~PhantomMaterialFemale();

public:
    void DefineMaterials();
    G4Material* GetMaterial(G4String); //returns the material

private:
    G4Material* fLung;
    G4Material* fTeeth;
    G4Material* fBone;
    G4Material* fHumeri_upper;
    G4Material* fHumeri_lower;
    G4Material* fArm_lower;
    G4Material* fHand;
    G4Material* fClavicle;
    G4Material* fCranium;
    G4Material* fFemora_upper;
    G4Material* fFemora_lower;
    G4Material* fLeg_lower;
    G4Material* fFoot;
    G4Material* fMandible;
    G4Material* fPelvis;
    G4Material* fRibs;
    G4Material* fScapulae;
    G4Material* fSpine_cervical;
    G4Material* fSpine_lumbar;
    G4Material* fSpine_thoratic;
    G4Material* fSacrum;
    G4Material* fSternum;
    G4Material* fHf_upper;
    G4Material* fHf_lower;
    G4Material* fMed_lowerleg;
    G4Material* fMed_lowerarm;
    G4Material* fCartilage;
    G4Material* fSkin;
    G4Material* fBlood;
    G4Material* fMuscle;
    G4Material* fLiver;
    G4Material* fPancreas;
    G4Material* fBrain;
    G4Material* fHeart;
    G4Material* fEye;
    G4Material* fKidney;
    G4Material* fStomach;
    G4Material* fIntestine_sml;
    G4Material* fIntestine_lrg;
    G4Material* fSpleen;
    G4Material* fThyroid;
    G4Material* fBladder;
    G4Material* fOvaries_testes;
    G4Material* fAdrenals;
    G4Material* fOesophagus;
    G4Material* fMisc;
    G4Material* fUterus_prostate;
    G4Material* fLymph;
    G4Material* fBreast_glandular;
    G4Material* fBreast_adipose;
    G4Material* fGastro_content;
    G4Material* fUrine;
};
#endif
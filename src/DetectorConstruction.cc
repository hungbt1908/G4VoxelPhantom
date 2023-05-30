#include "DetectorConstruction.hh"
#include "PhantomMaterialFemale.hh"
#include "PhantomMaterialMale.hh"
#include "PhantomNestedParameterisation.hh"
#include "PhantomMessenger.hh"

#include "G4NistManager.hh"
#include "G4Material.hh"
#include "G4UIcommand.hh"
#include "G4Box.hh"
#include "G4LogicalVolume.hh"
#include "G4VPhysicalVolume.hh"
#include "G4SystemOfUnits.hh"
#include "G4PVPlacement.hh"
#include "G4PVParameterised.hh"
#include "G4VisAttributes.hh"
#include "G4Colour.hh"

DetectorConstruction::DetectorConstruction()
	: G4VUserDetectorConstruction(),
	  	fNVoxelX(0), fNVoxelY(0), fNVoxelZ(0), 
		fVoxelHalfDimX(0), fVoxelHalfDimY(0), fVoxelHalfDimZ(0),
		fMinX(0),fMaxX(0), fMinY(0), fMaxY(0),
		fMinZ(0), fMaxZ(0), fNoFiles(0), fNVoxels(0), fMateIDs(0)
{
	fMessenger = new PhantomMessenger(this);

	fPhantomMaterialFemale = new PhantomMaterialFemale();
	fPhantomMaterialMale = new PhantomMaterialMale();

	fSex = "female"; // Female phantom is the default option
  	fSection = "head"; // Head partial phantom is the default option


}

DetectorConstruction::~DetectorConstruction()
{
	delete fPhantomMaterialFemale;
	delete fPhantomMaterialMale;
	delete fMessenger;
}

G4VPhysicalVolume *DetectorConstruction :: Construct()
{
	// * 
	// * ĐỊNH NGHĨA VẬT LIỆU
	// *

	/*
		* Vật liệu được tạo ra theo hai trường hợp:
			* Nếu là phantom Female, sử dụng lớp PhantomMaterialFemale tạo ra đối tượng fPhantomMaterialFemale
			* Nếu là phantom Male, sử dụng lớp PhantomMaterialMale tạo ra đối tượng fPhantomMaterialMale
		* Vật liệu sau đó được lưu vào vector pMaterials
	*/

	G4NistManager* nist = G4NistManager::Instance();
	G4Material *matAir = nist->FindOrBuildMaterial("G4_AIR");
	
	std::vector<G4Material*> pMaterials;


	if(fSex == "female")
	{
		fPhantomMaterialFemale->DefineMaterials();
		pMaterials.push_back(matAir); 
		pMaterials.push_back(fPhantomMaterialFemale->GetMaterial("teeth")); 
		pMaterials.push_back(fPhantomMaterialFemale->GetMaterial("bone"));
		pMaterials.push_back(fPhantomMaterialFemale->GetMaterial("humeri_upper")); 
		pMaterials.push_back(fPhantomMaterialFemale->GetMaterial("humeri_lower")); 
		pMaterials.push_back(fPhantomMaterialFemale->GetMaterial("arm_lower")); 
		pMaterials.push_back(fPhantomMaterialFemale->GetMaterial("hand")); 
		pMaterials.push_back(fPhantomMaterialFemale->GetMaterial("clavicle")); 
		pMaterials.push_back(fPhantomMaterialFemale->GetMaterial("cranium")); 
		pMaterials.push_back(fPhantomMaterialFemale->GetMaterial("femora_upper")); 
		pMaterials.push_back(fPhantomMaterialFemale->GetMaterial("femora_lower")); 
		pMaterials.push_back(fPhantomMaterialFemale->GetMaterial("leg_lower")); 
		pMaterials.push_back(fPhantomMaterialFemale->GetMaterial("foot")); 
		pMaterials.push_back(fPhantomMaterialFemale->GetMaterial("mandible")); 
		pMaterials.push_back(fPhantomMaterialFemale->GetMaterial("pelvis")); 
		pMaterials.push_back(fPhantomMaterialFemale->GetMaterial("ribs")); 
		pMaterials.push_back(fPhantomMaterialFemale->GetMaterial("scapulae")); 
		pMaterials.push_back(fPhantomMaterialFemale->GetMaterial("spine_cervical")); 
		pMaterials.push_back(fPhantomMaterialFemale->GetMaterial("spine_thoratic")); 
		pMaterials.push_back(fPhantomMaterialFemale->GetMaterial("spine_lumbar")); 
		pMaterials.push_back(fPhantomMaterialFemale->GetMaterial("sacrum")); 
		pMaterials.push_back(fPhantomMaterialFemale->GetMaterial("sternum")); 
		pMaterials.push_back(fPhantomMaterialFemale->GetMaterial("hf_upper")); 
		pMaterials.push_back(fPhantomMaterialFemale->GetMaterial("hf_lower")); 
		pMaterials.push_back(fPhantomMaterialFemale->GetMaterial("med_lowerarm")); 
		pMaterials.push_back(fPhantomMaterialFemale->GetMaterial("med_lowerleg")); 
		pMaterials.push_back(fPhantomMaterialFemale->GetMaterial("cartilage")); 
		pMaterials.push_back(fPhantomMaterialFemale->GetMaterial("skin")); 
		pMaterials.push_back(fPhantomMaterialFemale->GetMaterial("blood")); 
		pMaterials.push_back(fPhantomMaterialFemale->GetMaterial("muscle")); 
		pMaterials.push_back(fPhantomMaterialFemale->GetMaterial("liver")); 
		pMaterials.push_back(fPhantomMaterialFemale->GetMaterial("pancreas")); 
		pMaterials.push_back(fPhantomMaterialFemale->GetMaterial("brain"));
		pMaterials.push_back(fPhantomMaterialFemale->GetMaterial("heart")); 
		pMaterials.push_back(fPhantomMaterialFemale->GetMaterial("eye")); 
		pMaterials.push_back(fPhantomMaterialFemale->GetMaterial("kidney")); 
		pMaterials.push_back(fPhantomMaterialFemale->GetMaterial("stomach")); 
		pMaterials.push_back(fPhantomMaterialFemale->GetMaterial("intestine_sml")); 
		pMaterials.push_back(fPhantomMaterialFemale->GetMaterial("intestine_lrg")); 
		pMaterials.push_back(fPhantomMaterialFemale->GetMaterial("spleen")); 
		pMaterials.push_back(fPhantomMaterialFemale->GetMaterial("thyroid")); 
		pMaterials.push_back(fPhantomMaterialFemale->GetMaterial("bladder")); 
		pMaterials.push_back(fPhantomMaterialFemale->GetMaterial("ovaries_testes")); 
		pMaterials.push_back(fPhantomMaterialFemale->GetMaterial("adrenals")); 
		pMaterials.push_back(fPhantomMaterialFemale->GetMaterial("oesophagus")); 
		pMaterials.push_back(fPhantomMaterialFemale->GetMaterial("misc")); 
		pMaterials.push_back(fPhantomMaterialFemale->GetMaterial("uterus_prostate"));
		pMaterials.push_back(fPhantomMaterialFemale->GetMaterial("lymph")); 
		pMaterials.push_back(fPhantomMaterialFemale->GetMaterial("breast_glandular")); 
		pMaterials.push_back(fPhantomMaterialFemale->GetMaterial("breast_adipose")); 
		pMaterials.push_back(fPhantomMaterialFemale->GetMaterial("lung")); 
		pMaterials.push_back(fPhantomMaterialFemale->GetMaterial("gastro_content")); 
		pMaterials.push_back(fPhantomMaterialFemale->GetMaterial("urine"));
	}
	else if(fSex == "male")
	{
		fPhantomMaterialMale->DefineMaterials();

		pMaterials.push_back(matAir); 
		pMaterials.push_back(fPhantomMaterialMale->GetMaterial("teeth")); 
		pMaterials.push_back(fPhantomMaterialMale->GetMaterial("bone"));
		pMaterials.push_back(fPhantomMaterialMale->GetMaterial("humeri_upper")); 
		pMaterials.push_back(fPhantomMaterialMale->GetMaterial("humeri_lower")); 
		pMaterials.push_back(fPhantomMaterialMale->GetMaterial("arm_lower")); 
		pMaterials.push_back(fPhantomMaterialMale->GetMaterial("hand")); 
		pMaterials.push_back(fPhantomMaterialMale->GetMaterial("clavicle")); 
		pMaterials.push_back(fPhantomMaterialMale->GetMaterial("cranium")); 
		pMaterials.push_back(fPhantomMaterialMale->GetMaterial("femora_upper")); 
		pMaterials.push_back(fPhantomMaterialMale->GetMaterial("femora_lower")); 
		pMaterials.push_back(fPhantomMaterialMale->GetMaterial("leg_lower")); 
		pMaterials.push_back(fPhantomMaterialMale->GetMaterial("foot")); 
		pMaterials.push_back(fPhantomMaterialMale->GetMaterial("mandible")); 
		pMaterials.push_back(fPhantomMaterialMale->GetMaterial("pelvis")); 
		pMaterials.push_back(fPhantomMaterialMale->GetMaterial("ribs")); 
		pMaterials.push_back(fPhantomMaterialMale->GetMaterial("scapulae")); 
		pMaterials.push_back(fPhantomMaterialMale->GetMaterial("spine_cervical")); 
		pMaterials.push_back(fPhantomMaterialMale->GetMaterial("spine_thoratic")); 
		pMaterials.push_back(fPhantomMaterialMale->GetMaterial("spine_lumbar")); 
		pMaterials.push_back(fPhantomMaterialMale->GetMaterial("sacrum")); 
		pMaterials.push_back(fPhantomMaterialMale->GetMaterial("sternum")); 
		pMaterials.push_back(fPhantomMaterialMale->GetMaterial("hf_upper")); 
		pMaterials.push_back(fPhantomMaterialMale->GetMaterial("hf_lower")); 
		pMaterials.push_back(fPhantomMaterialMale->GetMaterial("med_lowerarm")); 
		pMaterials.push_back(fPhantomMaterialMale->GetMaterial("med_lowerleg")); 
		pMaterials.push_back(fPhantomMaterialMale->GetMaterial("cartilage")); 
		pMaterials.push_back(fPhantomMaterialMale->GetMaterial("skin")); 
		pMaterials.push_back(fPhantomMaterialMale->GetMaterial("blood")); 
		pMaterials.push_back(fPhantomMaterialMale->GetMaterial("muscle")); 
		pMaterials.push_back(fPhantomMaterialMale->GetMaterial("liver")); 
		pMaterials.push_back(fPhantomMaterialMale->GetMaterial("pancreas")); 
		pMaterials.push_back(fPhantomMaterialMale->GetMaterial("brain"));
		pMaterials.push_back(fPhantomMaterialMale->GetMaterial("heart")); 
		pMaterials.push_back(fPhantomMaterialMale->GetMaterial("eye")); 
		pMaterials.push_back(fPhantomMaterialMale->GetMaterial("kidney")); 
		pMaterials.push_back(fPhantomMaterialMale->GetMaterial("stomach")); 
		pMaterials.push_back(fPhantomMaterialMale->GetMaterial("intestine_sml")); 
		pMaterials.push_back(fPhantomMaterialMale->GetMaterial("intestine_lrg")); 
		pMaterials.push_back(fPhantomMaterialMale->GetMaterial("spleen")); 
		pMaterials.push_back(fPhantomMaterialMale->GetMaterial("thyroid")); 
		pMaterials.push_back(fPhantomMaterialMale->GetMaterial("bladder")); 
		pMaterials.push_back(fPhantomMaterialMale->GetMaterial("ovaries_testes")); 
		pMaterials.push_back(fPhantomMaterialMale->GetMaterial("adrenals")); 
		pMaterials.push_back(fPhantomMaterialMale->GetMaterial("oesophagus")); 
		pMaterials.push_back(fPhantomMaterialMale->GetMaterial("misc")); 
		pMaterials.push_back(fPhantomMaterialMale->GetMaterial("uterus_prostate"));
		pMaterials.push_back(fPhantomMaterialMale->GetMaterial("lymph")); 
		pMaterials.push_back(fPhantomMaterialMale->GetMaterial("breast_glandular")); 
		pMaterials.push_back(fPhantomMaterialMale->GetMaterial("breast_adipose")); 
		pMaterials.push_back(fPhantomMaterialMale->GetMaterial("lung")); 
		pMaterials.push_back(fPhantomMaterialMale->GetMaterial("gastro_content")); 
		pMaterials.push_back(fPhantomMaterialMale->GetMaterial("urine")); 
	
	}

	// * 
	// * ĐỊNH NGHĨA HÌNH HỌC
	// *

	// World volume
	G4Box* solidWorld = new G4Box("solidWorld", 500*cm, 500*cm, 500*cm);
	G4LogicalVolume *logicWorld = new G4LogicalVolume(solidWorld, matAir, "logicWorld");
	G4VPhysicalVolume *physWorld = new G4PVPlacement(0,
										G4ThreeVector(0., 0., 0.), 
										logicWorld, 
										"physWorld", 
										0, false, 0, true);
	logicWorld->SetVisAttributes(G4VisAttributes::GetInvisible());

	// Read phantoms
	ReadPhantomData(fSex, fSection); 

	// Define container
	 
	G4Box* solidContainer = new G4Box("solidContainer", fNVoxelX*fVoxelHalfDimX*mm,
                               fNVoxelY*fVoxelHalfDimY*mm,
                               fNVoxelZ*fVoxelHalfDimZ*mm);

	G4LogicalVolume*  logicContainer = new G4LogicalVolume(solidContainer,
                                                            matAir,
                                                            "logicContainer",
                                                             0, 0, 0 );  

	fMaxX = fNVoxelX*fVoxelHalfDimX*mm; // Max X along X axis of the voxelised geometry 
	fMaxY = fNVoxelY*fVoxelHalfDimY*mm; // Max Y
	fMaxZ = fNVoxelZ*fVoxelHalfDimZ*mm; // Max Z

	fMinX = -fNVoxelX*fVoxelHalfDimX*mm;// Min X 
	fMinY = -fNVoxelY*fVoxelHalfDimY*mm;// Min Y
	fMinZ = -fNVoxelZ*fVoxelHalfDimZ*mm;// Min Z

	G4ThreeVector posCentreVoxels((fMinX+fMaxX)/2.,(fMinY+fMaxY)/2.,(fMinZ+fMaxZ)/2.);

	new G4PVPlacement(0,                     // rotation
						posCentreVoxels,
						logicContainer,     // The logic volume
						"solidContainer",  // Name
						logicWorld,         // Mother
						false,            // No op. bool.
						1);              // Copy number
	logicContainer->SetVisAttributes(new G4VisAttributes(G4Colour(1.,0.,0.,0.)));
	// Slice the phantom along Y axis
	G4String yRepName("RepY");
   	G4VSolid* solYRep = new G4Box(yRepName, fNVoxelX*fVoxelHalfDimX,
                                  fVoxelHalfDimY, fNVoxelZ*fVoxelHalfDimZ);
   	G4LogicalVolume* logYRep = new G4LogicalVolume(solYRep ,matAir, yRepName);
   	new G4PVReplica(yRepName, logYRep, logicContainer, kYAxis, fNVoxelY, fVoxelHalfDimY*2.);
	logYRep->SetVisAttributes(new G4VisAttributes(G4VisAttributes::GetInvisible())); 

	// Slice the phantom along X axis 
	G4String xRepName("RepX");
   	G4VSolid* solXRep = new G4Box(xRepName, fVoxelHalfDimX, fVoxelHalfDimY,
                                  fNVoxelZ*fVoxelHalfDimZ);
   	G4LogicalVolume* logXRep = new G4LogicalVolume(solXRep, matAir, xRepName);
   	new G4PVReplica(xRepName, logXRep, logYRep, kXAxis, fNVoxelX, fVoxelHalfDimX*2.);
	logXRep->SetVisAttributes(new G4VisAttributes(G4VisAttributes::GetInvisible()));

	// Slice along Z axis 
	G4VSolid* solidVoxel = new G4Box("phantom", fVoxelHalfDimX, fVoxelHalfDimY, fVoxelHalfDimZ);
	G4LogicalVolume* logicVoxel = new G4LogicalVolume(solidVoxel, matAir, "phantom");
	logicVoxel->SetVisAttributes(new G4VisAttributes(G4VisAttributes::GetInvisible()));

    // Parameterisation to define the material of each voxel
    G4ThreeVector halfVoxelSize(fVoxelHalfDimX, fVoxelHalfDimY, fVoxelHalfDimZ);

	PhantomNestedParameterisation* param = new PhantomNestedParameterisation(halfVoxelSize, pMaterials);

	new G4PVParameterised("phantom",    // their name
						logicVoxel, 	// their logical volume
						logXRep,      // Mother logical volume
						kZAxis,       // Are placed along this axis
						fNVoxelZ,      // Number of cells
						param);       // Parameterisation

	param->SetMaterialIndices(fMateIDs); // fMateIDs is  the vector with Material ID associated to each voxel, from ASCII input data files.
    param->SetNoVoxel(fNVoxelX, fNVoxelY, fNVoxelZ);

	return physWorld;
}


void DetectorConstruction::ReadPhantomData(const G4String& sex, const G4String& section)
{
	fSex = sex;
	fSection = section;
	G4String dataFile;

	// Check conditions to find files
	if(fSex == "female")
	{
		if(fSection == "head")
		{
			dataFile == "ICRPdata/FemaleHead.dat";
		}
		else if(fSection == "trunk")
		{
			dataFile = "ICRPdata/FemaleTrunk.dat";
		}
		else if(fSection == "full");
		{
			dataFile = dataFile = "ICRPdata/FemaleData.dat";
		}
	}

	if(fSex == "male")
	{
		if(fSection == "head")
		{
			dataFile = "ICRPdata/MaleHead.dat";
		}
		else if(fSection == "trunk")
		{
			dataFile = "ICRPdata/MaleTrunk.dat";
		}
		else if(fSection == "full")
		{
			dataFile = "ICRPdata/MaleData.dat";
		}

	}

	std::ifstream finDF(dataFile.c_str()); 
	G4String fname;

	if(finDF.good() != 1 ) //check that the file is good and working
	{ 
		G4String descript = "Problem reading data file: " + dataFile;
		G4Exception(" HumanPhantomConstruction::ReadPhantomData", " ", FatalException,descript);
	}

	finDF >> fNoFiles;      // Dòng 1 của tệp (ghi số lượng slice)
	finDF >> fNVoxelX;      // Dòng 2 của tệp (số pixel theo trục X)
  	finDF >> fNVoxelY;      // Dòng 3 của tệp (số pixel theo trục Y)
	fNVoxelZ = fNoFiles;    // Tương đương với số slice

	finDF >> fVoxelHalfDimX; // Dòng 4 của tệp (1/2 kích thước pixel theo trục X)
  	finDF >> fVoxelHalfDimY; // Dòng 5 của tệp (1/2 kích thước pixel theo trục Y)
  	finDF >> fVoxelHalfDimZ; // Dòng 6 của tệp (1/2 kích thước pixel theo trục Z)

	fNVoxels = fNVoxelX*fNVoxelY*fNVoxelZ; 

	G4int nMaterials;
	finDF >> nMaterials; // Dòng 7 của tệp (Số lượng vật liệu, 53)

	G4String mateName;
	G4int nmate;

	// Read materials and associate with material ID number
	// Đọc dòng 8 - 60 trong tệp, cột 1 là ID vật liệu, cột 2 là tên vật liệu
	for( G4int ii = 0; ii < nMaterials; ii++ )
	{
		finDF >> nmate;
		finDF >> mateName;
    
    	// This allows to skip empty spaces and tabs in the string 
		if( mateName[0] == '"' && mateName[mateName.length()-1] == '"' ) 
		{
			mateName = mateName.substr(1, mateName.length()-2); 
		}
 
		// To uncomment for eventual debugging
		/* G4cout << "GmReadPhantomG4Geometry::ReadPhantomData reading nmate " 
			<< ii << " = " << nmate 
			<< " mate " << mateName << G4endl;*/
 
		if( ii != nmate ) 
		{
			G4Exception("GmReadPhantomG4Geometry::ReadPhantomData",
						"Wrong argument",
						FatalErrorInArgument,
						"Material number should be in increasing order:wrong material number");
		}
    }

	fMateIDs = new size_t[fNVoxels]; //Array with Material ID for each voxel
	for(G4int i = 0; i < fNoFiles; i++)
	{
		// Đọc tên tệp (tên slice)
		finDF >> fname;
		ReadPhantomDataFile(fSex, fname, i); 
	}

	finDF.close();
}

void DetectorConstruction::ReadPhantomDataFile(const G4String& sex, const G4String& fileName, G4int numberFile)
{
	G4cout << fileName << G4endl;
	fSex = sex;
	G4String slice;

	if(fSex == "female")
    {
      slice = "ICRPdata/ICRP110_g4dat/AF/" + fileName;
    }
    if(fSex == "male")
    {
      slice = "ICRPdata/ICRP110_g4dat/AM/" + fileName;
    }

	std::ifstream fin(slice.c_str(), std::ios_base::in);

	if( !fin.is_open() )
	{
		G4Exception("HumanPhantomConstruction::ReadPhantomDataFile",
					"",
					FatalErrorInArgument,
					G4String("File not found " + fileName ).c_str());
  	}

	
	for( G4int iy = 0; iy < fNVoxelY; iy++ ) 
	{
      	for( G4int ix = 0; ix < fNVoxelX; ix++ ) 
		{
      		if (ix == 0 && iy == 0)
        	{
				G4int dudX,dudY,dudZ;      
				fin >> dudX >> dudY >> dudZ ;
				// Dummy method to skip the first three lines of the files
				// which are not used here
        	}
        	else
			{      
        		G4int nnew = ix + (iy)*fNVoxelX + numberFile*fNVoxelX*fNVoxelY; // Quy đổi từ ix, iy và iz sang voxel id lưu trong array 1D
				G4int OrgID;
				fin >> OrgID; 
        		G4int mateID_out;

				// The code below associates organ ID numbers (called here mateID) from ASCII slice
				// files with material ID numbers (called here mateID_out) as defined in ICRP110PhantomMaterials
				// Material and Organ IDs are associated as stated in AM_organs.dat and FM_organs.dat depending on
				// the sex of the phantom (male and female, respctively)

				if (OrgID==128)
				{
					mateID_out=1;
				}
				else if (OrgID==13 || OrgID==16 || OrgID==19 || OrgID==22 || OrgID==24 || OrgID==26 || OrgID==28 || OrgID==31 || OrgID==34 || OrgID==37 || OrgID==39 || OrgID==41 || OrgID==43 || OrgID==45 || OrgID==47 || OrgID==49 || OrgID==51 || OrgID==53 || OrgID==55)
				{
					mateID_out=2;
				}
				else if (OrgID==14)
				{
					mateID_out=3;
				}
				else if (OrgID==17)
				{
					mateID_out=4;
				}
				else if (OrgID==20)
				{
					mateID_out=5;
				}
				else if (OrgID==23)
				{
					mateID_out=6;
				}
				else if (OrgID==25)
				{
					mateID_out=7;
				}
				else if (OrgID==27)
				{
					mateID_out=8;
				}
				else if (OrgID==29)
				{
					mateID_out=9;
				}
				else if (OrgID==32)
				{
					mateID_out=10;
				}
				else if (OrgID==35)
				{
					mateID_out=11;
				}
				else if (OrgID==38)
				{
					mateID_out=12;
				}
				else if (OrgID==40)
				{
					mateID_out=13;
				}
				else if (OrgID==42)
				{
					mateID_out=14;
				}
				else if (OrgID==44)
				{	
					mateID_out=15;
				}
				else if (OrgID==46)
				{
					mateID_out=16;
				}
				else if (OrgID==48)
				{
					mateID_out=17;
				}
				else if (OrgID==50)
				{
					mateID_out=18;
				}
				else if (OrgID==52)
				{
					mateID_out=19;
				}
				else if (OrgID==54)
				{
					mateID_out=20;
				}
				else if (OrgID==56)
				{
					mateID_out=21;
				}
				else if (OrgID==15 || OrgID==30)
				{
					mateID_out=22;
				}
				else if (OrgID==18 || OrgID==33)
				{
					mateID_out=23;
				}
				else if (OrgID==21)
				{
					mateID_out=24;
				}
				else if (OrgID==36)
				{
					mateID_out=25;
				}
				else if (OrgID==57 || OrgID==58 || OrgID==59 || OrgID==60)	
				{
					mateID_out=26;
				}
				else if (OrgID==122 || OrgID==123 || OrgID==124 || OrgID==125 || OrgID==141 )		
				{
					mateID_out=27;
				}
				else if (OrgID==9 || OrgID==10 || OrgID==11 || OrgID==12 || OrgID==88 || OrgID==96 || OrgID==98)
				{
					mateID_out=28;
				}
				else if (OrgID==5 || OrgID==6 || OrgID==106 || OrgID==107 || OrgID==108 || OrgID==109 || OrgID==133)
				{
					mateID_out=29;
				}
				else if (OrgID==95)
				{
					mateID_out=30;
				}
				else if (OrgID==113)
				{
					mateID_out=31;
				}
				else if (OrgID==61)
				{
					mateID_out=32;
				}
				else if (OrgID==87)
				{
					mateID_out=33;
				}
				else if (OrgID==66 || OrgID==67 || OrgID==68 || OrgID==69)
				{
					mateID_out=34;
				}
				else if (OrgID==89 || OrgID==90 || OrgID==91 || OrgID==92 || OrgID==93 || OrgID==94)
				{
					mateID_out=35;
				}
				else if (OrgID==72)
				{
					mateID_out=36;
				}
				else if (OrgID==74)
				{
					mateID_out=37;
				}
				else if (OrgID==76 || OrgID==78 || OrgID==80 || OrgID==82 || OrgID==84 || OrgID==86)
				{
					mateID_out=38;
				}
				else if (OrgID==127)
				{
					mateID_out=39;
				}
				else if (OrgID==132)
				{
					mateID_out=40;
				}
				else if (OrgID==137)
				{
					mateID_out=41;
				}
				else if (OrgID==111 || OrgID==112 || OrgID==129 || OrgID==130)
				{
					mateID_out=42;
				}
				else if (OrgID==1 || OrgID==2)
				{
					mateID_out=43;
				}
				else if (OrgID==110)
				{
					mateID_out=44;
				}
				else if (OrgID==3 || OrgID==4 || OrgID==7 || OrgID==8 || OrgID==70 || OrgID==71 || OrgID==114 || OrgID==120 || OrgID==121 || OrgID==126 || OrgID==131 || OrgID==134 || OrgID==135 || OrgID == 136)
				{
					mateID_out=45;
				}
				else if (OrgID==115 || OrgID==139)
				{
					mateID_out=46;
				}
				else if (OrgID==100 || OrgID==101 || OrgID==102 || OrgID==103 || OrgID==104 || OrgID==105)
				{
					mateID_out=47;
				}
				else if (OrgID==63 || OrgID==65)
				{
					mateID_out=48;
				}
				else if (OrgID==62 || OrgID==64 || OrgID==116 || OrgID==117 || OrgID==118 || OrgID==119)
				{
					mateID_out=49;
				}
				else if (OrgID==97 || OrgID==99)
				{
					mateID_out=50;
				}
				else if (OrgID==73 || OrgID==75 || OrgID==77 || OrgID==79 || OrgID==81 || OrgID==83 || OrgID==85)
				{
					mateID_out=51;
				}
				else if (OrgID==138)
				{
					mateID_out=52;
				}
				else if (OrgID==0 || OrgID==140)
				{
					mateID_out=0;
				}
				else 
				{
					mateID_out=OrgID;
				}
        
       	 		G4int nMaterials = 53;
        		if( mateID_out < 0 || mateID_out >= nMaterials )
				{
					G4Exception("GmReadPhantomG4Geometry::ReadPhantomData",
								"Wrong index in phantom file",
								FatalException,
								G4String("It should be between 0 and "
										+ G4UIcommand::ConvertToString(nMaterials-1) 
										+ ", while it is " 
										+ G4UIcommand::ConvertToString(OrgID)).c_str());
        
					// Store Material IDs and position/reference number within phantom in vector
	 			}
	
          		fMateIDs[nnew] = mateID_out; 
         	}
      	}
   	}
}

void DetectorConstruction::SetPhantomSex(G4String newSex)
{
	fSex = newSex;

	if(fSex == "male")
    {
      	G4cout << ">> Male Phantom will be built." << G4endl;
    }
  	if(fSex == "female")
    {
      	G4cout << ">> Female Phantom will be built." << G4endl;
    }
  	if((fSex != "female") && (fSex != "male"))
    	G4cout << fSex << " is not defined!" << G4endl;
}

void DetectorConstruction::SetPhantomSection(G4String newSection)
{
	fSection = newSection;
	if (fSection == "head")
	{
		G4cout << ">> Partial Head Phantom will be built." << G4endl;
	}
	if (fSection == "trunk")
	{
		G4cout << ">> Partial Trunk Phantom will be built." << G4endl;
	}
	if (fSection == "full")
	{
		G4cout << ">> Full/Custom Phantom will be built." << G4endl;
	}
	if ((fSection != "head") && (fSection != "trunk") && (fSection != "full"))
	{
		G4cout << fSection << " is not defined!" << G4endl;  
	}
}
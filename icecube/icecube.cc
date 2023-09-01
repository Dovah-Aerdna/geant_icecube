#include "G4MRunManager.hh"
#include "G4UImanager.hh"
#include "QBBC.hh"

#include "G4VisExecutive.hh"
#include "G4UIExecutive.hh"

#include "Randomize.hh"

//#include "DetectorConstructionIceCube.hh"
//#include "ExG4PhysicsList00.hh"
//#include "ExG4ActionInitialization01.hh"



//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......
//geometry
/*
#include "G4RunManager.hh"
#include "G4NistManager.hh"
#include "G4Tubs.hh"
#include "G4LogicalVolume.hh"
#include "G4PVPlacement.hh"
#include "G4SystemOfUnits.hh"



DetectorConstruction::DetectorConstruction()
: G4VUserDetectorConstruction(),
  fScoringVolume(0)
{ }

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

DetectorConstruction::~DetectorConstruction()
{ }

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

G4VPhysicalVolume* DetectorConstruction::Construct()
{  

   G4double innerRadius = 0.*m;
   G4double outerRadius = 600.*m;
   G4double hz = 2500.*m;
   G4double startAngle = 0.*deg;
   G4double spanningAngle = 360.*deg;

   G4Tubs* worldCylinder
     = new G4Tubs("World",
                  innerRadius,
                  outerRadius,
                  0.5*hz,
                  startAngle,
                  spanningAngle);


  // Get nist material manager
  G4NistManager* nist = G4NistManager::Instance();
  G4double density;
  density = 923.5 kg/m3; //density of ice at -50 °C
  G4Material* world_mat = nist->BuildMaterialWithNewDensity("Ice","G4_WATER",density);
  
  
    
  G4LogicalVolume* logicWorld =                         
    new G4LogicalVolume(worldCylinder,          //its solid
                        world_mat,           //its material
                        "World");            //its name
                                   
                                   
                                   
  G4VPhysicalVolume* physWorld = 
    new G4PVPlacement(0,                     //no rotation
                      G4ThreeVector(),       //at (0,0,0)
                      logicWorld,            //its logical volume
                      "World",               //its name
                      0,                     //its mother  volume
                      false,                 //no boolean operation
                      0,                     //copy number
                      false);        //overlaps checking
                     
  
  //
  //always return the physical World
  //
  return physWorld;
}*/

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......




/*
void ExN05PhysicsList::ConstructLeptons()
 {
   // Construct all leptons
   G4LeptonConstructor pConstructor;
   pConstructor.ConstructParticle();
 }
*/






int main()
{
  // construct the default run manager
  G4RunManager* runManager = new G4RunManager;

  // set mandatory initialization classes
  runManager->SetUserInitialization(new DetectorConstructionIceCube);
  
  //runManager->SetUserInitialization(new ExN05PhysicsList);
  
  //runManager->SetUserInitialization(new ExG4ActionInitialization01);

  // initialize G4 kernel
  runManager->Initialize();

  // get the pointer to the UI manager and set verbosities
  G4UImanager* UI = G4UImanager::GetUIpointer();
  UI->ApplyCommand("/run/verbose 1");
  UI->ApplyCommand("/event/verbose 1");
  UI->ApplyCommand("/tracking/verbose 1");

  // start a run
  int numberOfEvent = 3;
  runManager->BeamOn(numberOfEvent);

  // job termination
  delete runManager;
  return 0;
}

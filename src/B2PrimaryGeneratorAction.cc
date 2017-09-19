//
// ********************************************************************
// * License and Disclaimer                                           *
// *                                                                  *
// * The  Geant4 software  is  copyright of the Copyright Holders  of *
// * the Geant4 Collaboration.  It is provided  under  the terms  and *
// * conditions of the Geant4 Software License,  included in the file *
// * LICENSE and available at  http://cern.ch/geant4/license .  These *
// * include a list of copyright holders.                             *
// *                                                                  *
// * Neither the authors of this software system, nor their employing *
// * institutes,nor the agencies providing financial support for this *
// * work  make  any representation or  warranty, express or implied, *
// * regarding  this  software system or assume any liability for its *
// * use.  Please see the license in the file  LICENSE  and URL above *
// * for the full disclaimer and the limitation of liability.         *
// *                                                                  *
// * This  code  implementation is the result of  the  scientific and *
// * technical work of the GEANT4 collaboration.                      *
// * By using,  copying,  modifying or  distributing the software (or *
// * any work based  on the software)  you  agree  to acknowledge its *
// * use  in  resulting  scientific  publications,  and indicate your *
// * acceptance of all terms of the Geant4 Software license.          *
// ********************************************************************
//
// $Id: B2PrimaryGeneratorAction.cc 68058 2013-03-13 14:47:43Z gcosmo $
//
/// \file B2PrimaryGeneratorAction.cc
/// \brief Implementation of the B2PrimaryGeneratorAction class

#include "B2PrimaryGeneratorAction.hh"

#include "G4LogicalVolumeStore.hh"
#include "G4LogicalVolume.hh"
#include "G4Box.hh"
#include "G4Event.hh"
#include "G4ParticleGun.hh"
#include "G4ParticleTable.hh"
#include "G4ParticleDefinition.hh"
#include "G4SystemOfUnits.hh"
#include "G4GenericMessenger.hh"

#include "Randomize.hh"

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

B2PrimaryGeneratorAction::B2PrimaryGeneratorAction()
 : G4VUserPrimaryGeneratorAction(),
   fMessenger(0),
   fParticleGun(0),
   fRandom(false)
{
  G4int nofParticles = 1;
  fParticleGun = new G4ParticleGun(nofParticles);

  // default particle kinematic

  G4ParticleDefinition* particleDefinition 
    = G4ParticleTable::GetParticleTable()->FindParticle("e-");

  fParticleGun->SetParticleDefinition(particleDefinition);
  fParticleGun->SetParticleMomentumDirection(G4ThreeVector(0.,0.,1.));
  fParticleGun->SetParticleEnergy(1.0*MeV);
  fParticleGun->SetParticlePosition(G4ThreeVector(0.,0.,0.));

  // Generic messenger
  // Define /JUNO/primary commands using generic messenger class
  fMessenger
    = new G4GenericMessenger(this, "/JUNO/primary/", "Primary generator control");

  // Define /JUNO/primary/setRandom command
  fMessenger
    ->DeclareProperty("setRandom",
                      fRandom,
                      "Activate/Inactivate random option");

}

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

B2PrimaryGeneratorAction::~B2PrimaryGeneratorAction()
{
  delete fParticleGun;
}

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

void B2PrimaryGeneratorAction::GeneratePrimaries(G4Event* anEvent)
{
    //  // This function is called at the begining of event

    //  // In order to avoid dependence of PrimaryGeneratorAction
    //  // on DetectorConstruction class we get world volume
    //  // from G4LogicalVolumeStore.

    //  G4double worldZHalfLength = 0;
    //  G4LogicalVolume* worldLV
    //    = G4LogicalVolumeStore::GetInstance()->GetVolume("world");
    //  G4Box* worldBox = NULL;
    //  if ( worldLV ) worldBox = dynamic_cast<G4Box*>(worldLV->GetSolid());
    //  if ( worldBox ) worldZHalfLength = worldBox->GetZHalfLength();
    //  else  {
    //    G4cerr << "World volume of box not found." << G4endl;
    //    G4cerr << "Perhaps you have changed geometry." << G4endl;
    //    G4cerr << "The gun will be place in the center." << G4endl;
    //  }

    //  fParticleGun->SetParticlePosition(G4ThreeVector(0., 0., 0.));
    //this function is called at the begining of ecah event
    //

    if ( fRandom ) {
        // randomized direction
        G4double dtheta = 180.*deg;
        G4double dphi = 360*deg;
        G4double theta = G4UniformRand()*dtheta;
        G4double phi = G4UniformRand()*dphi;
        fParticleGun->SetParticleMomentumDirection(
                    G4ThreeVector(sin(theta)*sin(phi), sin(theta)*cos(phi), cos(theta)));
        G4double theta_pol = G4UniformRand()*dtheta;
        G4double phi_pol = G4UniformRand()*dphi;
        fParticleGun->SetParticlePolarization(
                    G4ThreeVector(sin(theta_pol)*sin(phi_pol), sin(theta_pol)*cos(phi_pol), cos(theta_pol)));
    }
    fParticleGun->GeneratePrimaryVertex(anEvent);
}

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

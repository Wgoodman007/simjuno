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
// $Id: B2PrimaryGeneratorAction.hh 68058 2013-03-13 14:47:43Z gcosmo $
//
/// \file B2PrimaryGeneratorAction.hh
/// \brief Definition of the B2PrimaryGeneratorAction class

#ifndef B2PrimaryGeneratorAction_h
#define B2PrimaryGeneratorAction_h 1

#include "G4VUserPrimaryGeneratorAction.hh"
#include "globals.hh"

class G4ParticleGun;
class G4Event;
class G4GenericMessenger;

/// The primary generator action class with particle gum.
///
/// It defines a single particle which hits the Tracker 
/// perpendicular to the input face. The type of the particle
/// can be changed via the G4 build-in commands of G4ParticleGun class 
/// (see the macros provided with this example).

class B2PrimaryGeneratorAction : public G4VUserPrimaryGeneratorAction
{
  public:
    B2PrimaryGeneratorAction();    
    virtual ~B2PrimaryGeneratorAction();

    virtual void GeneratePrimaries(G4Event* );

    G4ParticleGun* GetParticleGun() {return fParticleGun;}
  
    // Set methods
    void SetRandomFlag(G4bool );

  private:
    G4ParticleGun*          fParticleGun; // G4 particle gun
    G4GenericMessenger*     fMessenger;
    G4bool                  fRandom;
};

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

#endif

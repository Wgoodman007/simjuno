#ifndef ANALYSISMANAGER_HH
#define ANALYSISMANAGER_HH

#include "globals.hh"
#include <G4Event.hh>
#include <TFile.h>
#include <TTree.h>

class AnalysisManager {
    public:
        AnalysisManager();
        ~AnalysisManager();
        static AnalysisManager* GetInstance();
        void bookEvtTree();
        void BeginOfRun();
        void EndOfRun();
        void BeginOfEvent(const G4Event *event);
        void EndOfEvent(const G4Event* event);
        
//    public:
//        void SetNScintillation(G4int i) { nScintillation= i; }
//        void SetNCerenkov(G4int i) { nCerenkov= i; }

    private:
        static AnalysisManager* instance;

        TFile* thefile;
        TTree* evt;
        G4int evtID;
        G4int nPhotons;
        G4int nScintillation;
        G4int nCerenkov;
        G4int nStraight;
        G4double TimeStraight[200000];
        G4int nDetected;
        G4int nRayleigh[200000];
        G4int TID_Det[200000];
        G4double Time_Det[200000];
        G4double X_Det[200000];
        G4double Y_Det[200000];
        G4double Z_Det[200000];
        G4int isCerenkov[200000];
        G4double X_Init[200000];
        G4double Y_Init[200000];
        G4double Z_Init[200000];
        G4double Px_Init[200000];
        G4double Py_Init[200000];
        G4double Pz_Init[200000];
        G4double E_Init[200000];


    private:
        G4int fLSETId {-1};
        G4int fAcrylicETId { -1 };
        G4int fWaterETId { -1 };
        G4int fDetectorETId { -1 };
};

#endif

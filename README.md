# simjuno

# Output root file
TTree   evt  
Branch  evtID  
        nPhotons  
        detX  
        detY  
        detZ  
        hitTime  
        isScintillation  
        isCerenkov  
        isReemission  
        nRayScattering  

# G4StepStatus
0   fWorldBoundary
1   fGeomBoundary
2   fAtRestDoItProc
3   fAlongStepDoItProc
4   fPostStepDoItProc
5   fUserDefinedLimit
6   fExclusivelyForcedProc
7   fUndefined

# G4OpBoundaryProcessStatus
0   Undefined
1   Transmission
2   FresnelRefraction
3   FresnelReflection
4   TotalInternalReflection
5   LambertianReflection
6   LobeReflection
7   SpikeReflection
8   BackScattering
9   Absorption
10   Detection
11   NotAtBoundary
12   SameMaterial
13   StepTooSmall
14   NoRINDEX
15   PolishedLumirrorAirReflection
16   PolishedLumirrorGlueReflection
17   PolishedAirReflection
18   PolishedTeflonAirReflection
19   PolishedTiOAirReflection
20   PolishedTyvekAirReflection
21   PolishedVM2000AirReflection
22   PolishedVM2000GlueReflection
23   EtchedLumirrorAirReflection
24   EtchedLumirrorGlueReflection
25   EtchedAirReflection
26   EtchedTeflonAirReflection
27   EtchedTiOAirReflection
28   EtchedTyvekAirReflection
29   EtchedVM2000AirReflection
30   EtchedVM2000GlueReflection
31   GroundLumirrorAirReflection
32   GroundLumirrorGlueReflection
33   GroundAirReflection

#ifndef __PARTICLEMC_HH
#define __PARTICLEMC_HH

#include <iostream>
#include <vector>
#include "TObject.h"
#include "math.h"

class ParticleMC : public TObject {
public:
  ParticleMC(){
    ClearParticleMC();
  }

  ~ParticleMC(){
    //this->Clear();
  };
  
  void ClearParticleMC(){
    fID = -1;
    fMult = -1;
    fRear = -1;
    fEdet = -1;
    fStopped = -1;
    fA = -9;
    fZ = -9;

    fStripNr.clear();
    fStripEnergy.clear();
    fStripA.clear();
    fStripZ.clear();
    fStripTrackID.clear();
    fStripTime.clear();
    fStripStopped.clear();

    fRingNr.clear();
    fRingEnergy.clear();
    fRingA.clear();
    fRingZ.clear();
    fRingTrackID.clear();
    fRingTime.clear();
    fRingStopped.clear();
  }
  //set
  void ID(int id){
	 fID = id;
  }

  void SetA(int a) {
	  fA = a;
  }

  void SetZ(int z) {
	  fZ = z;
  }

  void SetTrackID(int trackID) {
    fTrackID = trackID;
  }

  void SetTime(double time)  {
    fTime = time;
  }

  void SetStopped(int stopped)  {
    fStopped = stopped;
  }

  void SetResKinEnergy(double resKinEnergy)  {
    fResKinEnergy = resKinEnergy;
  }

  void SetRear(double rear)  {
    fRear = rear;
  }

  void SetEdet(double edet)    {
      fEdet = edet;
  }

  void SetStrip(int strip, double energy, int a, int z, int trackID, double time, int stopped)  {
    fStripNr.push_back(strip);
    fStripEnergy.push_back(energy);
    fStripA.push_back(a);
    fStripZ.push_back(z);
    fStripTrackID.push_back(trackID);
    fStripTime.push_back(time);
    fStripStopped.push_back(stopped);
  }

  void Set2Strips(int firststrip, double firstenergy, int firstA, int firstZ, 
		  int firstTrackID, double firstTime, int firstStopped,
		  int secondstrip, double secondenergy, int secondA, int secondZ, 
		  int secondTrackID, double secondTime, int secondStopped){
    fStripNr.push_back(firststrip);
    fStripEnergy.push_back(firstenergy);
    fStripA.push_back(firstA);
    fStripZ.push_back(firstZ);
    fStripTrackID.push_back(firstTrackID);
    fStripTime.push_back(firstTime);
    fStripStopped.push_back(firstStopped);

    fStripNr.push_back(secondstrip);
    fStripEnergy.push_back(secondenergy);
    fStripA.push_back(secondA);
    fStripZ.push_back(secondZ);
    fStripTrackID.push_back(secondTrackID);
    fStripTime.push_back(secondTime);
    fStripStopped.push_back(secondStopped);
  }

  void SetRing(int strip, double energy, int a, int z, int trackID, double time, int stopped)  {
    fRingNr.push_back(strip);
    fRingEnergy.push_back(energy);
    fRingA.push_back(a);
    fRingZ.push_back(z);
    fRingTrackID.push_back(trackID);
    fRingTime.push_back(time);
    fRingStopped.push_back(stopped);
  }

  void Set2Rings(int firststrip, double firstenergy, int firstA, int firstZ, 
		 int firstTrackID, double firstTime, int firstStopped, 
		 int secondstrip, double secondenergy, int secondA, int secondZ, 
		 int secondTrackID, double secondTime, int secondStopped)  {
    fRingNr.push_back(firststrip);
    fRingEnergy.push_back(firstenergy);
    fRingA.push_back(firstA);
    fRingZ.push_back(firstZ);
    fRingTrackID.push_back(firstTrackID);
    fRingTime.push_back(firstTime);
    fRingStopped.push_back(firstStopped);

    fRingNr.push_back(secondstrip);
    fRingEnergy.push_back(secondenergy);
    fRingA.push_back(secondA);
    fRingZ.push_back(secondZ);
    fRingTrackID.push_back(secondTrackID);
    fRingTime.push_back(secondTime);
    fRingStopped.push_back(secondStopped);
  }

  void SetMult(int mult){
    fMult = mult;
  }

  //get
  int GetID(){
    return fID;
  }
  int GetA(){
    return fA;
  }
  int GetZ(){
    return fZ;
  }
  int GetTrackID(){
    return fTrackID;
  }
  double GetTime(){
    return fTime;
  }
  int IsStopped(){
    return fStopped;
  }
  double GetResKinEnergy(){
    return fResKinEnergy;
  }
  double GetRear(){
    return fRear;
  }
  double GetEdet(){
      return fEdet;
  }
  int GetMult(){
    return fMult;
  }
  std::vector<int> GetStripNr(){
    return fStripNr;
  }
  bool GetNeighbor(){
	  if(fStripNr.size() == 2 && fabs(fStripNr[0] - fStripNr[1]) == 1){
		  return true;
	  }
	  else{
		  return false;
	  }
  }
  std::vector<double> GetStripEnergy(){ // for CD
    return fStripEnergy;
  }
  std::vector<double> GetStripPos(){ // for Barrel
     return fStripEnergy;
  }
  std::vector<int> GetStripA(){
    return fStripA;
  }
  std::vector<int> GetStripZ(){
    return fStripZ;
  }
  std::vector<int> GetStripTrackID(){
    return fStripTrackID;
  }
  std::vector<double> GetStripTime(){
    return fStripTime;
  }
  std::vector<int> IsStripStopped(){
    return fStripStopped;
  }
  std::vector<int> GetRingNr(){
    return fRingNr;
  }
  std::vector<double> GetRingEnergy(){
    return fRingEnergy;
  }
  std::vector<int> GetRingA(){
    return fRingA;
  }
  std::vector<int> GetRingZ(){
    return fRingZ;
  }
  std::vector<int> GetRingTrackID(){
    return fRingTrackID;
  }
  std::vector<double> GetRingTime(){
    return fRingTime;
  }
  std::vector<int> IsRingStopped(){
    return fRingStopped;
  }

  long long SizeOf(){
    long long result = 0;
    result += sizeof(fA);
    result += sizeof(fZ);
    result += sizeof(fTrackID);
    result += sizeof(fTime);
    result += sizeof(fResKinEnergy);
    result += sizeof(fRear);
    result += sizeof(fEdet);
    result += fStripNr.size()*sizeof(int);
    result += fStripEnergy.size()*sizeof(double);
    result += fStripA.size()*sizeof(int);
    result += fStripZ.size()*sizeof(int);
    result += fStripTrackID.size()*sizeof(int);
    result += fStripTime.size()*sizeof(double);
    result += fRingNr.size()*sizeof(int);
    result += fRingEnergy.size()*sizeof(double);
    result += fRingA.size()*sizeof(int);
    result += fRingZ.size()*sizeof(int);
    result += fRingTrackID.size()*sizeof(int);
    result += fRingTime.size()*sizeof(double);
    return result;
  }

protected:
  int fID;
  std::vector<int> fStripNr;
  std::vector<double> fStripEnergy;
  std::vector<int> fStripA;
  std::vector<int> fStripZ;
  std::vector<int> fStripTrackID;
  std::vector<double> fStripTime;
  std::vector<int> fStripStopped;
  std::vector<int> fRingNr;
  std::vector<double> fRingEnergy;
  std::vector<int> fRingA;
  std::vector<int> fRingZ;
  std::vector<int> fRingTrackID;
  std::vector<double> fRingTime;
  std::vector<int> fRingStopped;
  int fA;
  int fZ;
  int fTrackID;
  double fTime;
  int fStopped;
  double fResKinEnergy;
  int fMult;
  double fRear;
  double fEdet;

  ClassDef(ParticleMC, 1);
};

#endif

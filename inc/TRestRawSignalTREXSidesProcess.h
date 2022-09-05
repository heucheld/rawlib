/*************************************************************************
 * This file is part of the REST software framework.                     *
 *                                                                       *
 * Copyright (C) 2016 GIFNA/TREX (University of Zaragoza)                *
 * For more information see http://gifna.unizar.es/trex                  *
 *                                                                       *
 * REST is free software: you can redistribute it and/or modify          *
 * it under the terms of the GNU General Public License as published by  *
 * the Free Software Foundation, either version 3 of the License, or     *
 * (at your option) any later version.                                   *
 *                                                                       *
 * REST is distributed in the hope that it will be useful,               *
 * but WITHOUT ANY WARRANTY; without even the implied warranty of        *
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the          *
 * GNU General Public License for more details.                          *
 *                                                                       *
 * You should have a copy of the GNU General Public License along with   *
 * REST in $REST_PATH/LICENSE.                                           *
 * If not, see http://www.gnu.org/licenses/.                             *
 * For the list of contributors see $REST_PATH/CREDITS.                  *
 *************************************************************************/

#ifndef RestCore_TRestRawSignalTREXSidesProcess
#define RestCore_TRestRawSignalTREXSidesProcess

#include <TRestRawSignalEvent.h>

#include "TRestEventProcess.h"

//! An analysis process to extract valuable information from a TRestRawSignalEvent.
class TRestRawSignalTREXSidesProcess : public TRestEventProcess {
   private:
    /// A pointer to the specific TRestRawSignalEvent input
    TRestRawSignalEvent* fSignalEvent;  //!
    
    /// AGET IDs in TREX-DM from 0 to 1151, half range is 576 (first ID from second detector)
    /// From 0 to 575 south side, from 576 to 1151 north side.
    TVector2 fSouthIDs = TVector2(0, 575);
    TVector2 fNorthIDs = TVector2(576, 1151); 

    void Initialize() override;

   protected:
    // add here the members of your event process

   public:
    any GetInputEvent() const override { return fSignalEvent; }
    any GetOutputEvent() const override { return fSignalEvent; }

    void InitProcess() override;
    TRestEvent* ProcessEvent(TRestEvent* inputEvent) override;

    void PrintMetadata() override {
        BeginPrintProcess();

         RESTMetadata << "South IDs : ( " << fSouthIDs.X() << ", " << fSouthIDs.Y() << " )" << RESTendl;
         RESTMetadata << "North IDs : ( " << fNorthIDs.X() << ", " << fNorthIDs.Y() << " )" << RESTendl;
        

        EndPrintProcess();
    }

    const char* GetProcessName() const override { return "RawSignalTREXSides"; }

    TRestRawSignalTREXSidesProcess();   // Constructor
    ~TRestRawSignalTREXSidesProcess();  // Destructor

    ClassDefOverride(TRestRawSignalTREXSidesProcess, 2);
};
#endif

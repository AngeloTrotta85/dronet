//
// This program is free software: you can redistribute it and/or modify
// it under the terms of the GNU Lesser General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.
// 
// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU Lesser General Public License for more details.
// 
// You should have received a copy of the GNU Lesser General Public License
// along with this program.  If not, see http://www.gnu.org/licenses/.
// 

#ifndef INET_PILOT_ARDUPILOT_H_
#define INET_PILOT_ARDUPILOT_H_

//#define TRY_ARDUCOPTER

#include "inet/common/INETDefs.h"

#ifdef TRY_ARDUCOPTER
#define CONFIG_HAL_BOARD HAL_BOARD_SITL
#define CONFIG_HAL_BOARD_SUBTYPE HAL_BOARD_SUBTYPE_NONE

#include <ArduCopter/Copter.h>
#endif


namespace inet {

class INET_API ArduPilot : public cSimpleModule {

protected:
  virtual int numInitStages() const override { return NUM_INIT_STAGES; }
  virtual void initialize(int stage) override;
  virtual void finish(void) override;

  virtual void handleMessage(cMessage *msg) override;
  virtual void handleSelfMessage(cMessage *message);

  virtual void mainLoop(void);
  virtual void mainInit(void);

protected:
  // The loop timer.
  cMessage *loopTimer = nullptr;

#ifdef TRY_ARDUCOPTER
  Copter copter;
#endif
};


} /* namespace inet */

#endif /* INET_PILOT_ARDUPILOT_H_ */

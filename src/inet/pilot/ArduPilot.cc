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

#include <pilot/ArduPilot.h>

namespace inet {

Define_Module(ArduPilot);

void ArduPilot::initialize(int stage) {
    if (stage == INITSTAGE_LOCAL) {
        loopTimer = new cMessage("loop");
        scheduleAt(simTime() + 1, loopTimer);
    }
    else if (stage == INITSTAGE_APPLICATION_LAYER) {
        mainInit();
    }
}

void ArduPilot::finish() {

}

void ArduPilot::handleMessage(cMessage *msg) {
    if (msg->isSelfMessage()) {
        handleSelfMessage(msg);
    }
    else {
        throw cRuntimeError("Unknown message '%s' received in %s", msg->getName(), getComponentType()->getName());
    }
}

void ArduPilot::handleSelfMessage(cMessage *message) {
    if (message == loopTimer) {
        mainLoop();
        scheduleAt(simTime() + 1, loopTimer);
    }
}

void ArduPilot::mainInit(void) {
#ifdef TRY_ARDUCOPTER
    copter.setup();
#endif
}

void ArduPilot::mainLoop(void) {
#ifdef TRY_ARDUCOPTER
    copter.loop();
#endif
}

} /* namespace inet */

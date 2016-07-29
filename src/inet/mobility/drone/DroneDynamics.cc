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

#include <drone/DroneDynamics.h>
#include "inet/common/INETMath.h"


namespace inet {

Define_Module(DroneDynamics);

DroneDynamics::DroneDynamics() : lastAngularSpeed(EulerAngles::ZERO){ }

void DroneDynamics::initialize(int stage)
{
    MovingMobilityBase::initialize(stage);

    EV_TRACE << "initializing DroneDynamics stage " << stage << endl;
    if (stage == INITSTAGE_LOCAL) {

    }
}

void DroneDynamics::move()
{
    calcNextPos(lastPosition, lastSpeed, lastOrientation, lastAngularSpeed);

    bool checkOut = checkIfOutside(lastPosition);       // If outside "lastPosition" is modified
    bool checkObs = checkIfObstacle(lastPosition);      // If into the obstacle "lastPosition" is modified

    // after checking if outside the scenario (or inside the obstacles) tell the drone-simulator the new position
    if (checkOut || checkObs) {
        lastSpeed = Coord::ZERO;
        lastAngularSpeed = EulerAngles::ZERO;

        updateFromWrongPos(lastPosition, lastSpeed);
    }
}

bool DroneDynamics::checkIfOutside(Coord &pos) {
    bool ris = false;
    Coord oldVal = Coord(pos);

    //TODO update! this is not good for 3D...
    Coord dummy;
    double angle = 0;
    handleIfOutside(REFLECT, dummy, dummy, angle);
    if(lastPosition != oldVal) {
        ris = true;
    }

    return ris;
}

bool DroneDynamics::checkIfObstacle(Coord &pos) {
    //TODO
    return false;
}

void DroneDynamics::updateFromWrongPos(Coord lastPosition, Coord lastVelocity) {
    // something was wrong (maybe outside the scenario or obstacles
    //TODO
}

} /* namespace inet */

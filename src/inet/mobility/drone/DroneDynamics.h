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

#ifndef INET_MOBILITY_DRONE_DRONEDYNAMICS_H_
#define INET_MOBILITY_DRONE_DRONEDYNAMICS_H_

#include "inet/common/INETDefs.h"

#include "inet/mobility/base/MovingMobilityBase.h"

namespace inet {

class INET_API DroneDynamics : public MovingMobilityBase {

protected:
    virtual int numInitStages() const override { return NUM_INIT_STAGES; }

    /** @brief Initializes mobility model parameters.*/
    virtual void initialize(int stage) override;

    /** @brief Move the host*/
    virtual void move() override;

    /** @brief Check if the drone is outside the border of the map - it changes directly the value pos*/
    virtual bool checkIfOutside(Coord &pos);

    /** @brief Check if the drone is colliding with an obstacle - it changes directly the value pos */
    virtual bool checkIfObstacle(Coord &pos);

    /** @brief Set directly the position */
    virtual void updateFromWrongPos(Coord lastPosition, Coord lastVelocity);

    /**
     * @name Calculate the position - to be defined for each drone model
     */
    //@{
    virtual void calcNextPos(Coord &new_pos, Coord &new_vel, EulerAngles &new_angle, EulerAngles &new_angle_vel) {};
    //@}

  public:
    DroneDynamics();

  protected:

    /** @brief The last angular speed that was reported at lastUpdate. */
    EulerAngles lastAngularSpeed;

};

} /* namespace inet */

#endif /* INET_MOBILITY_DRONE_DRONEDYNAMICS_H_ */

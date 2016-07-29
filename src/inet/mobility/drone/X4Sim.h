/*
 * X4Sim.h
 *
 *  Created on: Nov 18, 2015
 *      Author: angelo
 */

#ifndef X4SIM_H_
#define X4SIM_H_

#include <drone/DroneDynamics.h>
#include "inet/common/INETDefs.h"


#define K_MOT 0.4f //blade animation
#define G (float)9.81 //gravity ( N/(m/s²) )

#ifndef PI
#define PI ((float)3.14159265358979323846)
#endif

namespace inet {

class INET_API X4Sim : public DroneDynamics {
public:
    X4Sim();
    virtual ~X4Sim();

protected:
    virtual int numInitStages() const override { return NUM_INIT_STAGES; }
    virtual void initialize(int stage) override;
    virtual void finish(void) override;

    /**
     * @name Calculate the position - to be defined for each drone model
     */
    //@{
    void calcNextPos(Coord &new_pos, Coord &new_vel, EulerAngles &new_angle, EulerAngles &new_angle_vel);
    //@}

public:
    double k_mot;
    double c_mot;

    double m;
    double arm_length;

    double f_air_lat;
    double f_air_vert;

    double j_roll;
    double j_yaw;
    double j_pitch;

private:

    float motor_speed[4];

};

} /* namespace inet */

#endif /* X4SIM_H_ */

/*
 * X4Sim.cpp
 *
 *  Created on: Nov 18, 2015
 *      Author: angelo
 */

#include <drone/X4Sim.h>

namespace inet {

Define_Module(X4Sim);

X4Sim::X4Sim() {
    //Rot = cvCreateMat(3,3,CV_32FC1);
    //DRot = cvCreateMat(3,3,CV_32FC1);
    //Vect = cvCreateMat(3,1,CV_32FC1);
}

X4Sim::~X4Sim() {
    //les objets irrlicht seront automatiquement detruits (moteurs, helices, pales) par parenté
    //cvReleaseMat(&Rot);
    //cvReleaseMat(&DRot);
    //cvReleaseMat(&Vect);
}

void X4Sim::initialize(int stage) {

    DroneDynamics::initialize(stage);

    if (stage == INITSTAGE_LOCAL) {
        /* Initialization of the drone simulator */
        //TODO - drone = new [{DroneSim() -} X4Sim() - X8Sim() - ... ]

        m = par("m");
        arm_length = par("arm_length");
        k_mot = par("k_mot");           // vitesse rotation² (unité arbitraire) -> force (N)
        c_mot = par("c_mot");           // vitesse rotation moteur -> couple (N.m/unité arbitraire)
        f_air_vert = par("f_air_vert"); //frottements air depl. vertical, aussi utilisé pour les rotations ( N/(m/s) ) (du aux helices en rotation)
        f_air_lat = par("f_air_lat");   //frottements air deplacements lateraux ( N/(m/s) )
        j_roll = par("j_roll");         //moment d'inertie d'un axe (N.m.s²/rad)
        j_pitch = par("j_pitch");       //moment d'inertie d'un axe (N.m.s²/rad)
        j_yaw = par("j_yaw");           //moment d'inertie d'un axe (N.m.s²/rad)

        // set the motors to 0 (stopped)
        for (int i = 0; i < 4; i++) {
            motor_speed[i] = 0;
        }
        //TODO remove, only for debug
//        motor_speed[0] = 56;
//        motor_speed[1] = 56;
//        motor_speed[2] = 56;
//        motor_speed[3] = 56;

    }
}

void X4Sim::finish() {

}

void X4Sim::calcNextPos(Coord &new_pos, Coord &new_vel, EulerAngles &new_angle, EulerAngles &new_angle_vel) {
//    float fl_speed,fr_speed,rl_speed,rr_speed;
//    float u_roll,u_pitch,u_yaw,u_thrust;
//
//    fl_speed=motor_speed[0];
//    fr_speed=motor_speed[1];
//    rl_speed=motor_speed[2];
//    rr_speed=motor_speed[3];
//
//    /// Calculation of the thrust from the reference speed of motors
//    u_thrust=k_mot*(fl_speed*fl_speed+fr_speed*fr_speed+rl_speed*rl_speed+rr_speed*rr_speed);
//
//    cvmSet(Vect,0,0,0);
//    cvmSet(Vect,1,0,0);
//    cvmSet(Vect,2,0,-u_thrust);
//
//    /*
//    ** ===================================================================
//    **    u roll: roll torque
//    **
//    ** ===================================================================
//    */
//    u_roll=arm_length*k_mot*(fl_speed*fl_speed+rl_speed*rl_speed-fr_speed*fr_speed-rr_speed*rr_speed)*sqrtf(2)/2;
//
//    /// Classical Nonlinear model of a quadrotor ( This is the w_x angular speed of the quadri in the body frame). It is a discrete integrator
//    state[0].W.x=(dT()/j_roll)*((j_yaw-j_pitch)*state[-1].W.y*state[-1].W.z + u_roll) +state[-1].W.x;
//
//    //u_roll=arm_length->Value()*k_mot->Value()*(fl_speed*fl_speed+rl_speed*rl_speed-fr_speed*fr_speed-rr_speed*rr_speed)*sqrtf(2)/2;
//    //state[0].W.x=(dT()/j_roll->Value())*(u_roll-m->Value()*G*l_cg->Value()*sinf(state[-2].W.x)-f_air_vert->Value()*arm_length->Value()*arm_length->Value()*state[-1].W.x)+state[-1].W.x;
//
//    /*
//    ** ===================================================================
//    **   u pitch : pitch torque
//    **
//    ** ===================================================================
//    */
//    u_pitch=arm_length*k_mot*(fl_speed*fl_speed+fr_speed*fr_speed-rl_speed*rl_speed-rr_speed*rr_speed)*sqrtf(2)/2;
//
//    /// Classical Nonlinear model of a quadrotor ( This is the w_y angular speed of the quadri in the body frame). It is a discrete integrator
//    state[0].W.y=(dT()/j_pitch)*((j_roll-j_yaw)*state[-1].W.x*state[-1].W.z + u_pitch)+state[-1].W.y;
//
//    //u_pitch=arm_length->Value()*k_mot->Value()*(fl_speed*fl_speed+fr_speed*fr_speed-rl_speed*rl_speed-rr_speed*rr_speed)*sqrtf(2)/2;
//    //state[0].W.y=(dT()/j_pitch->Value())*(u_pitch-m->Value()*G*l_cg->Value()*sinf(state[-2].W.y)-f_air_vert->Value()*arm_length->Value()*arm_length->Value()*state[-1].W.y)+state[-1].W.y;
//
//    /*
//    ** ===================================================================
//    **    u yaw : yaw torque
//    **
//    ** ===================================================================
//    */
//    u_yaw=c_mot*(fl_speed*fl_speed+rr_speed*rr_speed-fr_speed*fr_speed-rl_speed*rl_speed);
//
//    /// Classical Nonlinear model of a quadrotor ( This is the w_z angular speed of the quadri in the body frame). It is a discrete integrator
//    state[0].W.z=(dT()/j_yaw)* u_yaw +state[-1].W.z;
//
//    //u_yaw=c_mot->Value()*(fl_speed*fl_speed+rr_speed*rr_speed-fr_speed*fr_speed-rl_speed*rl_speed);
//    //state[0].W.z=(dT()/j_yaw->Value())*(u_yaw-f_air_lat->Value()*state[-1].W.z)+state[-1].W.z;
//
//
//    ///*** Calculate the Euler angles from the anguler speeds in the body frame **********///
//
//    state[0].Angle.roll= dT()*(state[0].W.x + sinf(state[-1].Angle.roll)*tanf(state[-1].Angle.pitch)*state[0].W.y + cosf(state[-1].Angle.roll)*tanf(state[-1].Angle.pitch)*state[0].W.z) + state[-1].Angle.roll;
//
//    state[0].Angle.pitch= dT()*(cosf(state[-1].Angle.roll)*state[0].W.y - sinf(state[-1].Angle.roll)*state[0].W.z) + state[-1].Angle.pitch;
//
//    state[0].Angle.yaw= dT()*(sinf(state[-1].Angle.roll)*(1/cosf(state[-1].Angle.pitch))*state[0].W.y + cosf(state[-1].Angle.roll)*(1/cosf(state[-1].Angle.pitch))*state[0].W.z) + state[-1].Angle.yaw;
//
//    /* The Yaw angle is normaly limited between -2p an 2pi */
//    if(state[0].Angle.yaw>PI) state[0].Angle.yaw-=2*PI;
//    if(state[0].Angle.yaw<-PI) state[0].Angle.yaw+=2*PI;
//
//    /* Calculation of "Rot" the rotation matrix from the body frame to the world frame */
//    ComputeRotationMatrix(state[0].Angle.roll,state[0].Angle.pitch,state[0].Angle.yaw,Rot);
//
//    /* Multiplication of the rotation matrix by the thrust vector Vect */
//    // cvMatMul(Rot, Vect, Vect); //TODO
//
//    /*
//    ** ===================================================================
//    **     x double inegrator
//    **
//    ** ===================================================================
//    */
//    state[0].Pos.x=(dT()*dT()/m)*((float)cvmGet(Vect,0,0)-f_air_lat*(state[-1].Pos.x-state[-2].Pos.x)/dT())+2*state[-1].Pos.x-state[-2].Pos.x;
//
//    /*
//    ** ===================================================================
//    **     y double inegrator
//    **
//    ** ===================================================================
//    */
//    state[0].Pos.y=(dT()*dT()/m)*((float)cvmGet(Vect,1,0)-f_air_lat*(state[-1].Pos.y-state[-2].Pos.y)/dT())+2*state[-1].Pos.y-state[-2].Pos.y;
//
//
//    /*
//    ** ===================================================================
//    **     z double inegrator
//    **
//    ** ===================================================================
//    */
//    state[0].Pos.z=(dT()*dT()/m)*((float)cvmGet(Vect,2,0)+f_air_vert*(state[-1].Pos.z-state[-2].Pos.z)/dT()+m*G)+2*state[-1].Pos.z-state[-2].Pos.z;
//
//    //if(state[0].Pos.z<0) state[0].Pos.z=0;
//    //if(state[0].Pos.z>0) state[0].Pos.z=0;
}

} /* namespace inet */

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

package inet.mobility.drone;

//
// UTC - Simulator written by @see Guillaume Sanahuja at UTC
//
// @author Angelo Trotta
//

simple X4Sim extends DroneDynamics
{
    parameters:
        double m @unit("kg") = default(1.2kg);
        double arm_length @unit("m") = default(0.2m);
        double k_mot = default(0.001);           // vitesse rotation² (unité arbitraire) -> force (N)
        double c_mot = default(0.001);           // vitesse rotation moteur -> couple (N.m/unité arbitraire)
        double f_air_vert = default(0.01); 		//frottements air depl. vertical, aussi utilisé pour les rotations ( N/(m/s) ) (du aux helices en rotation)
        double f_air_lat = default(0.4);   		//frottements air deplacements lateraux ( N/(m/s) )
        double j_roll = default(0.006);         //moment d'inertie d'un axe (N.m.s²/rad)
        double j_pitch = default(0.006);       	//moment d'inertie d'un axe (N.m.s²/rad)
        double j_yaw = default(0.1);           	//moment d'inertie d'un axe (N.m.s²/rad)
        
        //@display("i=personal/quadcopter");
        @class(X4Sim);
}
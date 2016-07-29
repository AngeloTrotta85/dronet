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

import inet.mobility.base.MovingMobilityBase;

simple DroneDynamics extends MovingMobilityBase
{
    parameters:

        double initialX @unit(m) = default(uniform(this.constraintAreaMinX, this.constraintAreaMaxX));
        double initialY @unit(m) = default(uniform(this.constraintAreaMinY, this.constraintAreaMaxY));
        double initialZ @unit(m) = default(uniform(this.constraintAreaMinZ, this.constraintAreaMaxZ));

        double initialVelX @unit(mps) = default(0mps);
        double initialVelY @unit(mps) = default(0mps);
        double initialVelZ @unit(mps) = default(0mps);
        double W_X = default(0);
        double W_Y = default(0);
        double W_Z = default(0);
        double initialRoll @unit(rad) = default(0rad);
        double initialPitch @unit(rad) = default(0rad);
        double initialYaw @unit(rad) = default(0rad);

        bool initFromDisplayString = default(true);
        @class(DroneDynamics);

        @display("bgb=128,304;i=personal/quadmodel");
}

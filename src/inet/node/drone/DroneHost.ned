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

package inet.node.drone;

import inet.node.inet.AdhocHost;
import inet.sensors.Sensors;
import inet.actuators.Actuators;
import inet.pilot.IPilot;

//
// A host for demonstrating mobility models only -- it contains
// no protocol layers at all.
//
module DroneHost extends AdhocHost
{
    parameters:
        string pilotType = default("ArduPilot");
        
        @networkNode();
        @display("i=personal/quadcopter");
        @statistic[coordX](title="coord X"; source="xCoord(mobilityPos(mobilityStateChanged))"; record=vector; interpolationmode=linear);
        @statistic[coordY](title="coord Y"; source="yCoord(mobilityPos(mobilityStateChanged))"; record=vector; interpolationmode=linear);
        @statistic[coordZ](title="coord Z"; source="zCoord(mobilityPos(mobilityStateChanged))"; record=vector; interpolationmode=linear);

    submodules:
        sensors: Sensors {
            parameters:
                @display("i=personal/sensor;p=594,312");
        }

        actuators: Actuators {
            parameters:
                @display("i=personal/actuator;p=744,312");
        }

        pilot: <pilotType> like IPilot {
            parameters:
                @display("p=680,230");
        }
}

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

package inet.sensors;

module Sensors
{
    parameters:
        int numSensors = default(0);  // no of sensors. Specify the sensor types in INI file with sensor[0..1].typename="xxx" syntax
        bool hasSensors = default(numSensors > 0);        
        
        @class(Sensors);
        @display("i=personal/sensor");
        
    submodules:
        sensor[numSensors]: <> like ISensor {
            parameters:
                @display("i=personal/sensor");
        }
}
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

package dronet.simulations.test;

import inet.networklayer.configurator.ipv4.IPv4NetworkConfigurator;
import inet.node.drone.DroneHost;
import inet.physicallayer.ieee80211.packetlevel.Ieee80211ScalarRadioMedium;


network Net80211test
{
    parameters:
        int numHosts;
    submodules:
        host[numHosts]: DroneHost {
            parameters:
                @display("r=,,#707070;p=250,58");
        }
        radioMedium: Ieee80211ScalarRadioMedium {
            parameters:
                @display("p=60,50");
        }
        configurator: IPv4NetworkConfigurator {
            config = xml("<config><interface hosts='*' address='192.168.x.x' netmask='255.255.0.0'/></config>");
            @display("p=140,50");
        }
}

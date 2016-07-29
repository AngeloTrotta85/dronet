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

#include <Sensors.h>

namespace inet {

Define_Module(Sensors);

Sensors::Sensors() {
    // TODO Auto-generated constructor stub

}

Sensors::~Sensors() {
    // TODO Auto-generated destructor stub
}


void Sensors::initialize(int stage) {
    if (stage == INITSTAGE_LOCAL) {
    }
}


void Sensors::registerSensor(std::string sensorType, ISensor *sens) {
    if (sensorPool.count(sensorType) == 0) {
        sensorPool[sensorType] = std::vector<ISensor *>();
    }
    sensorPool[sensorType].push_back(sens);
}

ISensor *Sensors::getSensor(std::string sensorType, unsigned int index) {
    if (sensorPool.count(sensorType) == 0) {
        return nullptr;
    }
    else if (index >= sensorPool[sensorType].size()){
        return nullptr;
    }
    else {
        return sensorPool[sensorType].at(index);
    }
}

int Sensors::getSensorsNumber(std::string sensorType) {
    if (sensorPool.count(sensorType) == 0) {
        return 0;
    }
    else {
        return sensorPool[sensorType].size();
    }
}

} /* namespace inet */

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

#include <Actuators.h>

namespace inet {

Define_Module(Actuators);

Actuators::Actuators() {
    // TODO Auto-generated constructor stub

}

Actuators::~Actuators() {
    // TODO Auto-generated destructor stub
}

void Actuators::initialize(int stage) {
    if (stage == INITSTAGE_LOCAL) {
    }
}

void Actuators::registerActuator(std::string actuatorType, IActuator *act) {
    if (actuatorPool.count(actuatorType) == 0) {
        actuatorPool[actuatorType] = std::vector<IActuator *>();
    }
    actuatorPool[actuatorType].push_back(act);
}

IActuator *Actuators::getActuator(std::string actuatorType, unsigned int index) {
    if (actuatorPool.count(actuatorType) == 0) {
        return nullptr;
    }
    else if (index >= actuatorPool[actuatorType].size()){
        return nullptr;
    }
    else {
        return actuatorPool[actuatorType].at(index);
    }
}

int Actuators::getActuatorsNumber(std::string actuatorType) {
    if (actuatorPool.count(actuatorType) == 0) {
        return 0;
    }
    else {
        return actuatorPool[actuatorType].size();
    }
}

} /* namespace inet */

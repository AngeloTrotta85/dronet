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

#include <ISensor.h>
#include <Sensors.h>

namespace inet {

Define_Module(ISensor);

ISensor::ISensor() {
    // TODO Auto-generated constructor stub

}

ISensor::~ISensor() {
    // TODO Auto-generated destructor stub
}

void ISensor::initialize(int stage) {
    if (stage == INITSTAGE_LOCAL) {
        sensorType = par("sensorType").stdstringValue();
    }
    else if (stage == INITSTAGE_PHYSICAL_ENVIRONMENT) {
        registerModule();
    }
}

void ISensor::registerModule(void) {
    Sensors *sensorPool = check_and_cast<Sensors *>(this->getParentModule());

    EV << "Registering sensor " << sensorType << endl;

    sensorPool->registerSensor(sensorType, this);
}

} /* namespace inet */

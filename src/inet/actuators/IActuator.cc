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

#include <IActuator.h>
#include <Actuators.h>

namespace inet {

Define_Module(IActuator);

IActuator::IActuator() {
    // TODO Auto-generated constructor stub

}

IActuator::~IActuator() {
    // TODO Auto-generated destructor stub
}

void IActuator::initialize(int stage) {
    if (stage == INITSTAGE_LOCAL) {
        actuatorType = par("actuatorType").stdstringValue();
    }
    else if (stage == INITSTAGE_PHYSICAL_ENVIRONMENT) {
        registerModule();
    }
}

void IActuator::registerModule(void) {
    Actuators *actuatorPool = check_and_cast<Actuators *>(this->getParentModule());

    EV << "Registering actuator " << actuatorType << endl;

    actuatorPool->registerActuator(actuatorType, this);
}

} /* namespace inet */

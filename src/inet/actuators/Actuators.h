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

#ifndef ACTUATORS_H_
#define ACTUATORS_H_

#include "inet/common/INETDefs.h"
#include "IActuator.h"
#include  <string>
#include  <map>
#include  <vector>

namespace inet {

class INET_API Actuators : public cSimpleModule {

protected:
  virtual int numInitStages() const override { return NUM_INIT_STAGES; }
  virtual void initialize(int stage) override;

public:
    Actuators();
    virtual ~Actuators();

    void registerActuator(std::string actuatorType, IActuator *act);
    IActuator *getActuator(std::string actuatorType, unsigned int index = 0);
    int getActuatorsNumber(std::string actuatorType);

protected:
   std::map<std::string, std::vector<IActuator *>> actuatorPool;
};

} /* namespace inet */

#endif /* ACTUATORS_H_ */

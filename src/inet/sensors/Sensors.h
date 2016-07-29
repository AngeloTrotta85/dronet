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

#ifndef SENSORS_H_
#define SENSORS_H_

#include "inet/common/INETDefs.h"
#include "ISensor.h"
#include  <string>
#include  <map>
#include  <vector>

namespace inet {

class INET_API Sensors : public cSimpleModule {

protected:
  virtual int numInitStages() const override { return NUM_INIT_STAGES; }
  virtual void initialize(int stage) override;

public:
    Sensors();
    virtual ~Sensors();

    void registerSensor(std::string sensorType, ISensor *sens);
    ISensor *getSensor(std::string sensorType, unsigned int index = 0);
    int getSensorsNumber(std::string sensorType);

protected:
   std::map<std::string, std::vector<ISensor *>> sensorPool;
};

} /* namespace inet */

#endif /* SENSORS_H_ */

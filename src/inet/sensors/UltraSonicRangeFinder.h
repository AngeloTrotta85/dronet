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

#ifndef ULTRASONICRANGEFINDER_H_
#define ULTRASONICRANGEFINDER_H_

#include "inet/common/INETDefs.h"
#include "ISensor.h"

namespace inet {

class INET_API UltraSonicRangeFinder : public ISensor {
public:
    UltraSonicRangeFinder();
    virtual ~UltraSonicRangeFinder();

    double z(void);
    double Vz(void);

protected:

    /** @brief Returns the required number of initialize stages. */
    virtual int numInitStages() const override { return NUM_INIT_STAGES; }

    /** @brief Initializes mobility model parameters. */
    virtual void initialize(int stage) override;
};

} /* namespace inet */

#endif /* ULTRASONICRANGEFINDER_H_ */

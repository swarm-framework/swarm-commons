/*
 * Copyright 2017 Dami <contact@damiengiron.me>
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 *
 */

#ifndef SWARM_NETWORK_IPADDRESS_HXX
#define SWARM_NETWORK_IPADDRESS_HXX

#include "../exception/SwarmException.hxx"
#include <string>

namespace swarm {
    namespace network {

        /// \brief Define an IP address
        class IPAddress {

          private:
            /// \brief String representing an IP address
            std::string address_;

            /// \brief Construct an object with a string containing the IP address
            /// \param address String containing IP address
            IPAddress(const std::string &address) : address_(address) {}

          public:
            /// \brief Define copy constructor
            /// \param address Other IP address
            IPAddress(const IPAddress &address) : address_(address.address_) {}

            /// \brief Define move constructor
            /// \param address Other IP address
            IPAddress(IPAddress &&address) : address_(std::move(address.address_)) {}

          public:
            /// \brief Retrieve IP address representation
            /// \return String containing IP address
            const std::string &str() const { return address_; }

          public:
            /// \brief Construct an IP address from a string
            /// \param address String containing IP address
            /// \return IP address object
            static IPAddress get(const std::string &address) {
                if (address.empty()) {
                    throw SwarmException{"Empty IP address"};
                }

                return IPAddress{address};
            }
        };
    }
}

#endif // SWARM_NETWORK_IPADDRESS_HXX

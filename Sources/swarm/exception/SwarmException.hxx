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

#ifndef SWARMEXCEPTION_HXX
#define SWARMEXCEPTION_HXX

#include <cxxlog/Formatter.hxx>
#include <exception>
#include <string>

namespace swarm {

    /// \brief Class SwarmException
    class SwarmException : public std::exception {

      private:
        /// \brief Message
        std::string message_;

      public:
        /// \brief Default exception creation
        SwarmException() : message_("Unkown error") {}

        /// \brief Constructor with string message
        /// \param msg String containing message
        SwarmException(const std::string &msg) : message_(msg) {}

        /// \brief Constructor with formatted message
        /// \tparam T Variadic arguments types
        /// \param msg String containing format
        /// \param args All format arguments
        template <typename... T>
        SwarmException(const std::string &msg, T... args) : message_(cxxlog::format(msg, args...)) {}

        virtual const char *what() const noexcept override { return message_.c_str(); }
    };
}

#endif // SWARMEXCEPTION_HXX

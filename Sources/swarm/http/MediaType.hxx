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

#ifndef SWARM_HTTP_MEDIATYPE_HXX
#define SWARM_HTTP_MEDIATYPE_HXX

#include <sstream>
#include <string>
#include <vector>

namespace swarm {
    namespace http {

        /// \brief Define an Internet Media Type
        class MediaType {

          private:
            /// \brief General media type
            std::string type_;

            /// \brief Sub media type
            std::string subType_;

            /// \brief Parameters
            std::vector<std::string> parameters_;

          public:
            /// \brief Construct media type from type and sub type
            /// \param type General type
            /// \param subType Sub type
            MediaType(const std::string &type, const std::string &subType) : type_(type), subType_(subType) {}

            /// \brief Construct media type from type, sub type and parameters
            /// \param type General type
            /// \param subType Sub type
            /// \param parameters List of parameters
            MediaType(const std::string &type, const std::string &subType, const std::vector<std::string> &parameters)
                : type_(type), subType_(subType), parameters_(parameters) {}

            /// \brief Copy constructor
            /// \param mediaType Other media type
            MediaType(const MediaType &mediaType)
                : type_(mediaType.type_), subType_(mediaType.subType_), parameters_(mediaType.parameters_) {}

          public:
            /// \brief Retrieve general media type
            /// \return String containing media type
            const std::string &type() const { return type_; }

            /// \brief Retrieve sub media type
            /// \return String containing sub media type
            const std::string &subType() const { return subType_; }

            /// \brief Retrieve parameters
            /// \return Vector containing parameters
            const std::vector<std::string> &parameters() const { return parameters_; }

            /// \brief Create string definition for this format type
            /// \return String containing media type definition
            std::string str() const;

            bool operator==(const MediaType &other) const;

          public:
            // --- Application data ---

            /// \brief Media-type for JSON
            static const MediaType APPLICATION_JSON;

            /// \brief Media-type for XML
            static const MediaType APPLICATION_XML;

            // --- Text files ---

            /// \brief Media-type for Text Plain
            static const MediaType TEXT_PLAIN;

            /// \brief Media-type for HTML
            static const MediaType TEXT_HTML;

            /// \brief Media-type for CSS
            static const MediaType TEXT_CSS;

            // --- Images ---

            /// \brief Media-type for PNG
            static const MediaType IMAGE_PNG;

            /// \brief Media-type for JPEG
            static const MediaType IMAGE_JPEG;

            /// \brief Media-type for Gif
            static const MediaType IMAGE_GIF;
        };
    }
}

#endif // SWARM_HTTP_MEDIATYPE_HXX

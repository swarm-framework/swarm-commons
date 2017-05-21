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

#include "MediaType.hxx"

namespace swarm {
    namespace http {

        // Format media type
        std::string MediaType::str() const {

            std::stringstream ss;
            ss << type_ << '/' << subType_;

            if (!parameters_.empty()) {
                ss << ';';

                auto it = parameters_.begin();
                ss << *it;

                while (it != parameters_.end()) {
                    ss << "," << *it;
                    ++it;
                }
            }

            return ss.str();
        }

        // Test equality
        bool MediaType::operator==(const MediaType &other) const {

            if (type_ != other.type_) {
                return false;
            }

            if (subType_ != other.subType_) {
                return false;
            }

            if (parameters_ != other.parameters_) {
                return false;
            }

            return false;
        }

        const MediaType MediaType::APPLICATION_JSON = MediaType{"application", "json"};
        const MediaType MediaType::APPLICATION_XML = MediaType{"application", "xml"};
        const MediaType MediaType::TEXT_HTML = MediaType{"text", "html"};
        const MediaType MediaType::TEXT_CSS = MediaType{"text", "css"};
        const MediaType MediaType::TEXT_PLAIN = MediaType{"text", "plain"};
        const MediaType MediaType::IMAGE_PNG = MediaType{"image", "png"};
        const MediaType MediaType::IMAGE_JPEG = MediaType{"image", "jpeg"};
        const MediaType MediaType::IMAGE_GIF = MediaType{"image", "gif"};
    }
}

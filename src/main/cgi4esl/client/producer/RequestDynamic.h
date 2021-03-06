/*
 * This file is part of Jerry application server.
 * Copyright (C) 2020 Sven Lukas
 *
 * Jerry is free software: you can redistribute it and/or modify
 * it under the terms of the GNU Affero General Public License as
 * published by the Free Software Foundation, either version 3 of
 * the License, or (at your option) any later version.
 *
 * Jerry is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU Affero General Public License for more details.
 *
 * You should have received a copy of the GNU Affero General Public
 * License along with Jerry.  If not, see <https://www.gnu.org/licenses/>.
 */

#ifndef CGI4ESL_CLIENT_PRODUCER_REQUESTDYNAMIC_H_
#define CGI4ESL_CLIENT_PRODUCER_REQUESTDYNAMIC_H_

#include <cgi4esl/client/RequestInfo.h>

#include <esl/http/client/RequestDynamic.h>
#include <esl/system/process/ProducerDynamic.h>

#include <string>

namespace cgi4esl {
namespace client {
namespace producer {

class RequestDynamic : public esl::system::process::ProducerDynamic {
public:
	RequestDynamic(esl::http::client::RequestDynamic& request);

	const RequestInfo& getRequestInfo() const noexcept;

private:
	esl::http::client::RequestDynamic& request;
	RequestInfo requestInfo;
};

} /* namespace producer */
} /* namespace client */
} /* namespace cgi4esl */

#endif /* CGI4ESL_CLIENT_PRODUCER_REQUESTDYNAMIC_H_ */

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

#ifndef CGI4ESL_CLIENT_CONNECTION_H_
#define CGI4ESL_CLIENT_CONNECTION_H_

#include <cgi4esl/client/RequestInfo.h>

#include <esl/http/client/Interface.h>
#include <esl/http/client/Request.h>
#include <esl/http/client/RequestDynamic.h>
#include <esl/http/client/RequestStatic.h>
#include <esl/http/client/RequestFile.h>
#include <esl/http/client/Response.h>
#include <esl/http/client/ResponseHandler.h>
#include <esl/object/Values.h>
#include <esl/system/Interface.h>
#include <esl/system/process/Arguments.h>
#include <esl/system/process/Environment.h>
#include <esl/utility/URL.h>

#include <string>
#include <vector>
#include <utility>
#include <memory>

namespace cgi4esl {
namespace client {

class Connection : public esl::http::client::Interface::Connection {
public:
	static inline const char* getImplementation() {
		return "cgi4esl";
	}

	static std::unique_ptr<esl::http::client::Interface::Connection> create(const esl::utility::URL& hostUrl, const esl::object::Values<std::string>& values);

	Connection(const esl::utility::URL& hostUrl, esl::system::process::Arguments arguments, const esl::object::Values<std::string>& values);

	esl::http::client::Response send(esl::http::client::RequestDynamic& request, esl::http::client::ResponseHandler* responseHandler) const override;
	esl::http::client::Response send(const esl::http::client::RequestStatic& request, esl::http::client::ResponseHandler* responseHandler) const override;
	esl::http::client::Response send(const esl::http::client::RequestFile& request, esl::http::client::ResponseHandler* responseHandler) const override;

private:
	esl::http::client::Response send(const esl::http::client::Request& request, esl::http::client::ResponseHandler* responseHandler, const RequestInfo& requestInfo, esl::system::Interface::Producer& processProducer) const;

	void prepareRequest(esl::http::client::Response& response, const esl::http::client::Request& request, const std::string& method) const;

	esl::utility::URL hostUrl;
	std::string path;
	esl::system::process::Arguments arguments;
	std::string workingDir;

	/* e.g. jerry 1.0 */
	std::string serverSoftware;

	/* e.g. admin@jerry.org */
	std::string serverAdmin;

	std::string serverProtocol = "HTTP/1.1";

	std::string remoteHost;
	std::string remoteAddr;
	std::string remoteUser;
};

} /* namespace client */
} /* namespace cgi4esl */

#endif /* CGI4ESL_CLIENT_CONNECTION_H_ */

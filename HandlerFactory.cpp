#include "HandlerFactory.hpp"
#include "handler/Home.hpp"
#include "handler/SignUp.hpp"
#include "handler/Login.hpp"
#include "handler/RegisterTrader.hpp"
#include "handler/StaticContent.hpp"
#include <boost/algorithm/string/predicate.hpp>

namespace trading {

using Poco::Net::HTTPRequestHandler;
using Poco::Net::HTTPRequestHandlerFactory;
using Poco::Net::HTTPServerRequest;

HTTPRequestHandler* HandlerFactory::createRequestHandler(
    const HTTPServerRequest& request)
{
    if (request.getURI() == "/")
        return new trading::handler::Home();
    else if (request.getURI() == "/login")
        return new trading::handler::Login();
    else if (request.getURI() == "/signup")
        return new trading::handler::SignUp();
    else if (request.getURI() == "/registerTrader")
        return new trading::handler::RegisterTrader();
    else if (boost::starts_with(request.getURI(), "/static"))
        return new trading::handler::StaticContent();
    else
        return 0;
}

} // namespace trading
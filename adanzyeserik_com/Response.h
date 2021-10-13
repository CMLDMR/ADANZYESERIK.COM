#ifndef RESPONSE_H
#define RESPONSE_H


#include <Wt/Http/Request.h>
#include <Wt/Http/Response.h>
#include <Wt/WResource.h>
#include <Wt/WServer.h>
#include <iostream>
#include "BaseClass/containerwiget.h"

class Resource : public Wt::WResource {
public:

    Signal<std::string> testSignal;


  virtual void handleRequest(const Wt::Http::Request &request,
                             Wt::Http::Response &response) override
  {
//    response.setMimeType("text/plain");

    LOG << "Responsed" << LOGEND;

//    response.out() << "Request path:\n"
//                   << request.path() << "\n\n";

    auto pathInfo = request.pathInfo();
    if (pathInfo.empty())
      pathInfo = "(empty)";
//    response.out() << "Request path info:\n"
//                   << pathInfo << "\n\n";

//    response.out() << "Request URL parameters\n"
//                      "----------------------\n";

    auto params = request.urlParams();

    if (params.empty())
      response.out() << "(empty)\n";

    for (const auto &param : params) {
      const auto &name = param.first;
      const auto &value = param.second;
      if( name == "value" ){
          if( value == "test" ){
              testSignal.emit("Test Signali: " + value);
              LOG << "Signal Emitted" << LOGEND;
          }
      }
//      response.out() << name << ": " << value << '\n';
    }


//    response.out() << "\nRequest parameters\n"
//                      "----------------------\n";
    auto parameterMap = request.getParameterMap();

    for( const auto &item : parameterMap ){
        for( auto sItem : item.second ){
//            response.out() << item.first << ": " << sItem << '\n';
        }
    }


    auto headers = request.headers();

//    response.out() << "\nRequest Headers\n"
                      "----------------------\n";

    for( const auto &item : headers ){
//        response.out() << item.name() << " " << item.value() << "\n";
    }

    LOG << "END RESPONSE" << LOGEND;
  }
};

#endif // RESPONSE_H

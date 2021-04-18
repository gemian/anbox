
/*
 * This file was automatically generated by sdbus-c++-xml2cpp; DO NOT EDIT!
 */

#ifndef __sdbuscpp__concatenator_adaptor_h__adaptor__H__
#define __sdbuscpp__concatenator_adaptor_h__adaptor__H__

#include <sdbus-c++/sdbus-c++.h>
#include <string>
#include <tuple>

namespace org {
namespace sdbuscpp {
namespace stresstests {

class concatenator_adaptor
{
public:
    static constexpr const char* INTERFACE_NAME = "org.sdbuscpp.stresstests.concatenator";

protected:
    concatenator_adaptor(sdbus::IObject& object)
        : object_(object)
    {
        object_.registerMethod("concatenate").onInterface(INTERFACE_NAME).withInputParamNames("params").withOutputParamNames("result").implementedAs([this](sdbus::Result<std::string>&& result, std::map<std::string, sdbus::Variant> params){ this->concatenate(std::move(result), std::move(params)); });
        object_.registerSignal("concatenatedSignal").onInterface(INTERFACE_NAME).withParameters<std::string>("concatenatedString");
    }

    ~concatenator_adaptor() = default;

public:
    void emitConcatenatedSignal(const std::string& concatenatedString)
    {
        object_.emitSignal("concatenatedSignal").onInterface(INTERFACE_NAME).withArguments(concatenatedString);
    }

private:
    virtual void concatenate(sdbus::Result<std::string>&& result, std::map<std::string, sdbus::Variant> params) = 0;

private:
    sdbus::IObject& object_;
};

}}} // namespaces

#endif

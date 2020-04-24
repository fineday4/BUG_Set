/*
 * @Author: xuhuanhuan(hhxu@robvision) 
 * @Date: 2020-04-24 22:22:07 
 * @Last Modified by: xuhuanhuan(hhxu@robvision.cn)
 * @Last Modified time: 2020-04-25 00:03:25
 */
#include <typeinfo>
#include <iostream>
#include "../headers/PLCProtocol.h"

CPLCProtocol* CPLCProtocol::instance()
{
    static CPLCProtocol* _instance = NULL;
    if(_instance == NULL){
        _instance = new CPLCProtocol();
    }

    return _instance;
}

void CPLCProtocol::OnConfig()
{
    while(true)
    {
        std::string msg;
        std::cout << "OnConfig" << std::endl;
        std::cin >> msg;
        std::string old_protocol(typeid(*m_plcProtocol).name());
        if(msg == "SieMenS"){
            if(old_protocol.find("SieMenS") == std::string::npos){
                delete m_plcProtocol;
                m_plcProtocol = CPLCSieMenS::instance();
            }
        }else if(msg == "MitSubShi"){
            if(old_protocol.find("MitSubShi") == std::string::npos){
                delete m_plcProtocol;
                m_plcProtocol = CPLCSieMenS::instance();
            }
        }
    }
}

CPLCProtocol::CPLCProtocol():m_plcProtocol(CPLCMitSubShi::instance()) ,t(&CPLCProtocol::OnConfig, this)
{
    t.join();
}

CPLCProtocol::~CPLCProtocol()
{}
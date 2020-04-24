/*
 * @Author: xuhuanhuan(hhxu@robvision) 
 * @Date: 2020-04-24 22:03:17 
 * @Last Modified by: xuhuanhuan(hhxu@robvision.cn)
 * @Last Modified time: 2020-04-24 23:35:59
 */

#ifndef _PLCPROTOCOL_H__
#define _PLCPROTOCOL_H__

#include "PLCMitSubShi.h"
#include "PLCSieMenS.h"

class CPLCProtocol{

    public:
        static CPLCProtocol* instance();
        void OnConfig();   //单独线程监听输入，创建即运行

    private:
        CPLCProtocol();
        ~CPLCProtocol();
    
    private:
        CPLCManager *m_plcProtocol;
        std::thread t;
};

#endif
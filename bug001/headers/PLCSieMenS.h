/*
 * @Author: xuhuanhuan(hhxu@robvision) 
 * @Date: 2020-04-24 21:56:12 
 * @Last Modified by: xuhuanhuan(hhxu@robvision.cn)
 * @Last Modified time: 2020-04-24 23:30:51
 */

#ifndef __PLCSIEMENS_H__
#define __PLCSIEMENS_H__

#include "PLCManager.h"

class CPLCSieMenS:public CPLCManager{
    public:
        static CPLCSieMenS* instance();   
        bool sendEnv();
        bool getEnv();
        void control(std::string action, std::vector<int> power);

    private:

        ~CPLCSieMenS(); 
        CPLCSieMenS();   
        void run();
    
    private:
        int m_data[MAX_DATA];
        std::mutex m_dataMutex[MAX_DATA];
        std::thread t;
};

#endif
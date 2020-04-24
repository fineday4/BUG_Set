/*
 * @Author: xuhuanhuan(hhxu@robvision) 
 * @Date: 2020-04-24 21:48:16 
 * @Last Modified by: xuhuanhuan(hhxu@robvision.cn)
 * @Last Modified time: 2020-04-24 23:30:22
 */

#ifndef PLCMITSUBSHI_H__
#define PLCMITSUBSHI_H__

#include "PLCManager.h"

class CPLCMitSubShi:public CPLCManager{
    public:

        static CPLCMitSubShi* instance();
        bool sendEnv();
        bool getEnv();
        void control(std::string action, std::vector<int> power);
        void start(); //创建后立即运行run函数

    private:

        ~CPLCMitSubShi(); 
        CPLCMitSubShi();
        void run();
    
    private:
        int m_data[MAX_DATA];
        std::mutex m_dataMutex[MAX_DATA];
        std::thread t;

};

#endif
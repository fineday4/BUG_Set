/*
 * @Author: xuhuanhuan(hhxu@robvision) 
 * @Date: 2020-04-22 00:07:52 
 * @Last Modified by: xuhuanhuan(hhxu@robvision.cn)
 * @Last Modified time: 2020-04-24 06:34:16
 */
#ifndef __PLCMANAGER_H__
#define __PLCMANAGER_H__

//#include "headers/RPCFunc.h"

#include <string>
#include <thread>
#include <mutex>
#include <vector>

#define MAX_DATA 121

class PLCManager{
    public:
        static PLCManager* instance();

        bool sendEnv();
        bool getEnv();
        void control(std::string action, std::vector<int> power);
        void onCfgPowerParams(/*const Json::value config*/ std::vector<std::string> config);
        ~PLCManager();

    private:
        PLCManager();
        void run();
        void onData();

    private:
        std::thread t;
        std::mutex m_dataMutex[MAX_DATA];
        int m_data[MAX_DATA];
};
#endif
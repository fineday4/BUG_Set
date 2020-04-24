/*
 * @Author: xuhuanhuan(hhxu@robvision) 
 * @Date: 2020-04-22 00:07:52 
 * @Last Modified by: xuhuanhuan(hhxu@robvision.cn)
 * @Last Modified time: 2020-04-24 23:45:09
 */
#pragma once

//#ifndef __PLCMANAGER_H__
//#define __PLCMANAGER_H__

#include <string>
#include <thread>
#include <mutex>
#include <vector>
//#include "../headers/sendComm.h"
#include <iostream>
#include <chrono>

#define MAX_DATA 121

class CPLCManager{
    public:
        virtual bool sendEnv()=0;
        virtual bool getEnv()=0;
        virtual void control(std::string action, std::vector<int> power)=0;
        virtual ~CPLCManager(){}
        void sendComm(const std::string protocol, const int* buf, size_t size)
        {
            //*向串口写入数据
            
        }

};

//#endif
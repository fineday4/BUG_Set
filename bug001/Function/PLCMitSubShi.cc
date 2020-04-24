/*
 * @Author: xuhuanhuan(hhxu@robvision) 
 * @Date: 2020-04-22 00:06:44 
 * @Last Modified by: xuhuanhuan(hhxu@robvision.cn)
 * @Last Modified time: 2020-04-25 00:02:19
 */

#include "../headers/PLCMitSubShi.h"

const int bufM0On[6] = {0x01, 0x00, 0x00, 0x00, 0x09, 0xA1};
const int bufM0Off[6] = {0x01, 0x00, 0x00, 0x00, 0x09, 0xA1};
const int bufM1On[6] = {0x01, 0x00, 0x00, 0x00, 0x09, 0xA1};
const int bufM1Off[6] = {0x01, 0x00, 0x00, 0x00, 0x09, 0xA1};
const int bufM2On[6] = {0x01, 0x00, 0x00, 0x00, 0x09, 0xA1};
const int bufM2Off[6] = {0x01, 0x00, 0x00, 0x00, 0x09, 0xA1};
const int bufM3On[6] = {0x01, 0x00, 0x00, 0x00, 0x09, 0xA1};
const int bufM3Off[6] = {0x01, 0x00, 0x00, 0x00, 0x09, 0xA1};

const int bufSendEvn[10] = {0x01, 0x00, 0x00, 0x00, 0x09, 0xA1, 0x04, 0x01};
const int bufGetEvn[10] = {0x01, 0x00, 0x00, 0x00, 0x09, 0xA1, 0x04, 0x02};


bool CPLCMitSubShi::sendEnv()
{
    return true;
}

bool CPLCMitSubShi::getEnv()
{
    return true;
}

//控制电路开关,一共有四路开关
void CPLCMitSubShi::control(std::string action, std::vector<int> power)
{
    for(int i = 0; i < power.size(); ++i)
    {
        switch (power[i])
        {
        case 0:
            /* code */
            action == "On"?    sendComm("PLC", bufM0On, 6): sendComm("PLC", bufM0Off, 6);
            break;
        case 1:
            /* code */
            action == "On"?    sendComm("PLC", bufM1On, 6): sendComm("PLC", bufM1Off, 6);
            break;
        case 2:
            /* code */
            action == "On"?    sendComm("PLC", bufM2On, 6): sendComm("PLC", bufM2Off, 6);
            break;
        case 3:
            /* code */
            action == "On"?    sendComm("PLC", bufM3On, 6): sendComm("PLC", bufM3Off, 6);
            break;    
        default:
            break;
        }
    }
}

CPLCMitSubShi* CPLCMitSubShi::instance()
{
    static CPLCMitSubShi* _instance = NULL;
    if(_instance == NULL){
        _instance = new CPLCMitSubShi();
    }

    return _instance;
}

void CPLCMitSubShi::run()
{
    while(true){
       // std::cout << "getEnv" << std::endl; 
        getEnv();
        for(int i = 0; i < MAX_DATA; ++i){
            std::lock_guard<std::mutex> lk(m_dataMutex[i]);
            ++m_data[i];
        }
        //std::cout << "sendEnv: " << std::endl;
        sendEnv();
    }
}


CPLCMitSubShi::CPLCMitSubShi():t(&CPLCMitSubShi::run, this)
{
    //t.detach(); //t.detach的实现效果是main线程退出时，t线程也会退出
   // t.join();  //t.join的实现效果是 main线程退出前一直等待run线程运行完再退出。   
    std::cout << "PLCManager create . . ." << std::endl;
}

CPLCMitSubShi::~CPLCMitSubShi()
{
    std::this_thread::sleep_for(std::chrono::seconds(2));
    std::cout << "~PLCManager destroy . . ." << std::endl;
}

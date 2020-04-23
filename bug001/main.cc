/*
 * @Author: xuhuanhuan(hhxu@robvision) 
 * @Date: 2020-04-22 22:50:50 
 * @Last Modified by: xuhuanhuan(hhxu@robvision.cn)
 * @Last Modified time: 2020-04-24 06:34:33
 */

#include "headers/PLCManager.h"

void foo()
{
    while(true);
}

int main()
{
    PLCManager* plc = PLCManager::instance();
    delete plc;

    return 0;
}
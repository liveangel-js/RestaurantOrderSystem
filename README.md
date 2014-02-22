# RestaurantOrderSystem

## Overview
It is the homework of C++ Programming in Nanjing University Software Institute(南京大学软件学院C++作业)
It is written in C++ and using QT development


### Requirments
+ 编写一个程序，实现餐厅桌号预订系统。
+ 基本功能：
    1. 餐厅提供小，中，大三种餐位，分别对应0~4人，5~8人，9人以上；
    
    2. 每种餐位若干，每个餐位都有相应的编号；
    
    3. 每种餐位使用收取的费用不同；
    
    4. 每位客人根据就餐人数选择不同类型的餐位，系统则根据等待人数给用户生成一个等待号码，显示客人当前排号以及在他之前有多       少位客人在等待。
    
    5. 不同类型餐位都有自己的一个等待列，为客人生成的号码互不影响；
    
    6. 支持查询指定号码所在的餐位；
    
    7. 实现日志功能（记录每天所有餐位的使用状况，收入）；
    
    8. 客人可以动态查看当前餐位使用情况（每种餐位当前排到多少号等）
 


+ 要求：   
         1. 重载new, delete操作符；
         2. 程序结构良好，有图形界面；
         3. 建议分两种角色：系统普通用户（客人），系统管理员（餐厅管理员）；
         4. 保证数据的持久性（例如采用稳健或者数据库方式实现）；
         5. 编程环境为vs2005/vs2008/vs2010/QT;
         6. 基本功能必须保证，鼓励同学自由发挥；
         7. 简单的说明文档（设计思路，模块定义）
+ 提示： 参照辛香汇的排队叫号系统。


### Run
main is in "mainlogic.cpp"
see more details in Design.doc


### UI
![image](https://github.com/liveangel-js/RestaurantOrderSystem/UI1.jpg)
![image](https://github.com/liveangel-js/RestaurantOrderSystem/UI2.jpg)


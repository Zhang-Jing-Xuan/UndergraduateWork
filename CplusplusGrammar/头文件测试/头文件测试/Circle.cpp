//
//  Circle.cpp
//  头文件测试
//
//  Created by admin on 2019/9/26.
//  Copyright © 2019年 admin. All rights reserved.
//

#include "Circle.hpp"
Circle::Circle()
{
    this->r=5.0;
}

Circle::Circle(double R)
{
    this->r=R;
}

double Circle:: Area()
{
    return 3.14*r*r;
}

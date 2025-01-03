#include "mygui.h"


#define practice1 0
#define practice2 0
#define practice3 0
#define practice4 1
#define practice5 0
#define practice6 0
#define practice7 0

void mygui()
{

#if practice1
    //创建一个开关
    lv_obj_t *switch1 = lv_switch_create(lv_scr_act()); //以活动屏幕(lv_scr_act())为父对象，创建一个开关，函数返回一个指向开关的指针
    lv_obj_set_size(switch1, 200, 100); //设置开关的大小

    //创建另一个部件
    //lv_obj_t *switch2 = lv_switch_create(lv_scr_act());
    lv_obj_t *switch2 = lv_switch_create(switch1); //可以以其他部件为父对象，创建一个开关，两者为父子关系
    lv_obj_set_size(switch2, 100, 50); //设置开关的大小

    //父对象相当于子对象的容器，子对象的位置是相对于父对象的，默认在父对象的左上角
    //活动屏幕本身也是一个对象，可以作为其他对象的父对象，同时也是一个lv_obj_t类型的指针（部件）

#elif practice2
    //基础对象也是一个对象，可以作为其他对象的父对象
    lv_obj_t *obj_base = lv_obj_create(lv_scr_act()); //以活动屏幕为父对象创建一个基础对象
    lv_obj_set_size(obj_base, 300, 400); //设置基础对象的大小
    lv_obj_set_pos(obj_base, 50, 50); //设置基础对象的位置

    //子对象会随着父对象移动，子对象的位置超过父对象，不会显示
    lv_obj_t *obj_child = lv_obj_create(obj_base); //以基础对象为父对象创建一个基础对象
    lv_obj_set_size(obj_child, 50, 60); //设置基础对象的大小
    lv_obj_set_pos(obj_child, 500, 50); //设置基础对象的位置 超出的位置不会显示，但可以拖拽父对象，找到子对象

#elif practice3
    //部件的基本属性与管理
    /*
    部件的基本属性：
    1.大小：lv_obj_set_size(obj, width, height); 设置部件的大小
    2.位置：lv_obj_set_pos(obj, x, y); 设置部件的位置
    3.对齐：lv_obj_align(obj, base, align, x_ofs, y_ofs); 设置部件相对于基础对象的对齐方式
    4.样式：
    5.事件：
    */
    lv_obj_t *obj_base = lv_obj_create(lv_scr_act()); //以活动屏幕为父对象创建一个基础对象
    lv_obj_set_size(obj_base, 800, 480); //设置基础对象的大小
    //也可以单独设置宽度和高度
    //lv_obj_set_width(obj_base, 200); //设置基础对象的宽度
    //lv_obj_set_height(obj_base, 300); //设置基础对象的高度

    //lvgl的坐标系以左上角为原点(0,0)，向右为x轴正方向，向下为y轴正方向，最右下角的坐标为(屏幕宽度-1, 屏幕高度-1)

    //设置基础对象的位置
    lv_obj_set_pos(obj_base, 50, 50); //设置基础对象的位置，坐标以父对象的左上角为原点
    //也可以单独设置x和y坐标
    //lv_obj_set_x(obj_base, 50); //设置基础对象的x坐标
    //lv_obj_set_y(obj_base, 50); //设置基础对象的y坐标

    //对齐方式(alignment)：子对象相对于父对象的对齐方式

    //基本的对齐方式有三种：参照父对象对齐、参照父对象对齐再偏移、参照其他对象对齐（无父子关系）再偏移

    //创建一个子对象
    lv_obj_t *obj_child1 = lv_obj_create(obj_base);
    lv_obj_set_size(obj_child1, 50, 60); //设置子对象的大小

    //第一种：相对于父对象对齐
    //lv_obj_set_align(obj_child, LV_ALIGN_CENTER);//居中对齐
    //lv_obj_set_align(obj_child, LV_ALIGN_TOP_MID);//顶部中间对齐
    lv_obj_set_align(obj_child1, LV_ALIGN_BOTTOM_LEFT);//底部左侧对齐 依次类推
    /*
    对齐方式一共有21种，但子对象相对于父对象的对齐只能使用内部的9种
    所有对齐方式的宏的前缀都是LV_ALIGN_，后面跟着对齐方式的名称，例如LV_ALIGN_CENTER
    */

    //再创建一个子对象
    lv_obj_t *obj_child2 = lv_obj_create(obj_base);
    lv_obj_set_size(obj_child2, 50, 60); //设置子对象的大小

    //第二种：相对于父对象对齐再进行偏移
    lv_obj_align(obj_child2, LV_ALIGN_CENTER, 80, 80); //居中对齐再向右下各偏移80个像素


    //再创建一个子对象
    lv_obj_t *obj_child3 = lv_obj_create(obj_base);
    lv_obj_set_size(obj_child3, 50, 60); //设置子对象的大小

    //第三种：相对于其他对象对齐再进行偏移
    lv_obj_align_to(obj_child3, obj_child2, LV_ALIGN_OUT_BOTTOM_LEFT, 0, 10); //相对于obj_child2的底部左侧对齐再向下偏移10个像素，child3和child2没有父子关系


#elif practice4
    //部件的样式(style)
    //样式用于设置部件的外观，包括颜色、边框、阴影、圆角等

    /*
    主要内容：
    1. 如何给部件添加样式
    2. 什么时候样式会生效
    3. 有哪些样式属性可以设置
    4. 如何单独设置部件中某个部分的样式
    */





#else

#endif


}

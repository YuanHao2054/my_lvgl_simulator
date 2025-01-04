#include "mygui.h"


#define practice1 0
#define practice2 0
#define practice3 0
#define practice4 0
#define practice5 0
#define practice6 6
#define practice7 0



//定义部件
static lv_obj_t *obj1;


static void event_cb(lv_event_t *event)
{

    // //先获取事件类型
    // lv_event_code_t code = lv_event_get_code(event);
    // //在if里判断事件类型
    // if (code == LV_EVENT_CLICKED)
    // {
    //     lv_obj_t *label = lv_label_create(lv_scr_act());
    //     lv_label_set_text(label, "Hello World!");
    //     lv_obj_align(label, LV_ALIGN_CENTER, 0, 0);
    // }

    // else if (code == LV_EVENT_PRESSED)
    // {
    //     lv_obj_t *label = lv_label_create(lv_scr_act());
    //     lv_label_set_text(label, "Pressed!");
    //     lv_obj_align(label, LV_ALIGN_CENTER, 0, 0);
    // }
    // else
    // {
    //     //其他事件
    // }


    //通过嵌套if，判断不同部件的不同事件
    //判断不同部件的事件
    lv_obj_t *target = lv_event_get_target(event); //获取事件的目标部件

    if (target == obj1) //在回调函数中调用部件，需要定义为全局变量
    {
        lv_event_code_t code = lv_event_get_code(event);
        if (code == LV_EVENT_CLICKED)
        {
            lv_obj_t *label = lv_label_create(obj1);
            lv_label_set_text(label, "Hello World!");
            lv_obj_align(label, LV_ALIGN_CENTER, 0, 0);
        }
        else if (code == LV_EVENT_PRESSED)
        {
            lv_obj_t *label = lv_label_create(obj1);
            lv_label_set_text(label, "Pressed!");
            lv_obj_align(label, LV_ALIGN_CENTER, 100, 0);
        }
        else
        {
            //其他事件
        }
    }
    else
    {
        //其他部件的事件
    }
}


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

    //添加样式的两种方式：1. 使用预定义的样式 2. 部件单独配置本地样式

    //使用预定义的样式 需要定义全局变量 或用static关键字 static lv_style_t style; 以便在其他函数中使用
    //相当于创建一个style对象，可以讲style对象应用到其他部件上
    //相比起来麻烦，但好处是可以统一管理样式，方便修改


    static lv_style_t style; //存储样式

    lv_style_init(&style); //初始化样式
    lv_style_set_bg_color(&style, lv_color_hex(0xf4b183)); //设置背景颜色

    lv_obj_t* obj = lv_obj_create(lv_scr_act()); //创建一个基础对象
    lv_obj_set_size(obj, 200, 100); //设置基础对象的大小
    lv_obj_add_style(obj, &style, LV_STATE_DEFAULT); //将样式应用到这个对象上 第三个参数表示状态，LV_STATE_DEFAULT表示默认状态
    //第三个参数还可以是其他状态，例如按下状态LV_STATE_PRESSED，悬停状态LV_STATE_HOVERED等，可以决定什么时候样式生效
    //这个参数是一个枚举变量，具体如下
    /*
    enum _lv_state_t {
    LV_STATE_DEFAULT     =  0x0000,  //默认状态
    LV_STATE_CHECKED     =  0x0001,  //选中状态
    LV_STATE_FOCUSED     =  0x0002,  //焦点状态
    LV_STATE_FOCUS_KEY   =  0x0004,  //键盘焦点状态
    LV_STATE_EDITED      =  0x0008,  //由编码器编辑状态
    LV_STATE_HOVERED     =  0x0010,  //鼠标悬停
    LV_STATE_PRESSED     =  0x0020,  //按下状态
    LV_STATE_SCROLLED    =  0x0040,  //滚动状态
    LV_STATE_DISABLED    =  0x0080,  //禁用状态
    LV_STATE_USER_1      =  0x1000,
    LV_STATE_USER_2      =  0x2000,
    LV_STATE_USER_3      =  0x4000,
    LV_STATE_USER_4      =  0x8000,

    LV_STATE_ANY = 0xFFFF,
    };
    */
    //部件单独配置本地样式
    //好处是配置方便，缺点是不方便统一管理样式，不容易修改
    //不需要定义全局变量，直接在创建部件时配置样式
    lv_obj_t* obj2 = lv_obj_create(lv_scr_act()); //创建一个基础对象
    lv_obj_set_size(obj2, 200, 100); //设置基础对象的大小
    lv_obj_align(obj2, LV_ALIGN_OUT_BOTTOM_LEFT, 300, 0); //相对于obj的底部左侧对齐再向下偏移10个像素
    lv_obj_set_style_bg_color(obj2, lv_color_hex(0xf4b183), LV_STATE_PRESSED); //设置背景颜色 当按下时生效


#elif practice5
    //其他常用的部件属性：大小、位置、背景、轮廓、边框、阴影、其他

    //设置边框颜色
    lv_obj_t *obj1 = lv_obj_create(lv_scr_act()); //创建一个基础对象
    lv_obj_set_size(obj1, 200, 100); //设置基础对象的大小
    lv_obj_set_align(obj1, LV_ALIGN_CENTER); //居中对齐

    static lv_style_t style1;
    lv_style_init(&style1); //初始化样式
    lv_style_set_border_color(&style1, lv_color_hex(0x367A83)); //设置边框颜色

    lv_obj_add_style(obj1, &style1, LV_STATE_DEFAULT); //将样式应用到这个对象上

    //设置边框宽度
    lv_style_set_border_width(&style1, 10); //设置边框宽度
    lv_obj_add_style(obj1, &style1, LV_STATE_DEFAULT);

    //设置边框透明度0为完全透明，255为完全不透明
    lv_style_set_border_opa(&style1, 200); //设置边框透明度
    lv_obj_add_style(obj1, &style1, LV_STATE_DEFAULT);

    //设置边框轮廓
    static lv_style_t style2;
    lv_style_init(&style2); //初始化样式
    lv_style_set_outline_color(&style2, lv_color_hex(0x367A83)); //设置轮廓颜色
    lv_style_set_outline_width(&style2, 10); //设置轮廓宽度
    lv_style_set_outline_opa(&style2, 200); //设置轮廓透明度
    lv_obj_add_style(obj1, &style2, LV_STATE_PRESSED);


    //如何单独设置部件中某个部分的样式

    /*
    1、把部件拆分成几个部分，每个部分都可以设置样式
    */

    //创建一个滑块
    lv_obj_t *slider = lv_slider_create(lv_scr_act()); //创建一个滑块
    lv_obj_set_size(slider, 300, 20); //设置滑块的大小
    lv_obj_align(slider, LV_ALIGN_CENTER, 0, 100); //居中对齐

    //修改整体的颜色 不同部位需要单独去设置
    //lv_obj_set_style_bg_color(slider, lv_color_hex(0x121356), LV_STATE_DEFAULT); //设置背景颜色 只会修改滑块槽的颜色
    lv_obj_set_style_bg_color(slider, lv_color_hex(0x561218), LV_STATE_DEFAULT | LV_PART_INDICATOR); //在选择指示器这部分按位或上表示部件部位的宏
    lv_obj_set_style_bg_color(slider, lv_color_hex(0x3a5612), LV_STATE_DEFAULT | LV_PART_KNOB); //设置手柄的颜色


#elif practice6
    //事件
    //触发逻辑：当发生用户感兴趣的事情，触发回调事件，执行相关操作
    //添加事件：lv_obj_add_event_cb(obj, event_cb, event_type, user_data); 参数为部件、回调函数、事件类型、用户数据
    //常见的事件类型：点击、按下、释放、悬停、拖拽、滚动、键盘、编码器等
    //删除事件：lv_obj_remove_event_cb(obj, event_cb); 参数为部件、回调函数

    obj1 = lv_obj_create(lv_scr_act());
    lv_obj_set_size(obj1, 200, 100);
    lv_obj_set_align(obj1, LV_ALIGN_CENTER);

    //添加事件
    lv_obj_add_event_cb(obj1, event_cb, LV_EVENT_CLICKED, NULL); //点击事件
    lv_obj_add_event_cb(obj1, event_cb, LV_EVENT_PRESSED, NULL); //按下事件

    //回调函数：static void event_cb1(lv_event_t *event) ，参数可以用于处理不同事件共用一个回调函数，可以在函数内判断event的类型

    //不同的部件也可以共用一个回调函数




#else

#endif


}

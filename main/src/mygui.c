#include "mygui.h"


/*这个分支主要存放控件学习中的 标签、按钮、开关、复选框*/

#define practice1 0
#define practice2 0
#define practice3 1
#define practice4 0
#define practice5 0
#define practice6 0
#define practice7 0

// lv_obj_t *btn_plus;
// lv_obj_t *btn_minus;
// lv_obj_t *btn_stop;
// lv_obj_t *label_speed;

lv_obj_t *sw;
lv_obj_t *sw_cool;
lv_obj_t *sw_heat;
lv_obj_t *sw_dry;

static void obj_create_sw_cool();
static void obj_create_sw_heat();
static void obj_create_sw_dry();
static void obj_create_label();

// int speed_val;

// 标签部件：显示文本，例如标题、提示等
/*
组成部分：
主体：lv_part_main
滚动条：lv_part_scrollbar
选中的文本：lv_part_selected

标签学习：
1、如何创建标签部件并设置文本
2、如何改变文本的样式
3、当文本长度超过标签的宽度时，怎么显示
*/

//按钮部件 lv_btn 和基础对象相比，没有任何新增功能，只是创建出来时的样式不一样
/*
组成部分：只有主体 lv_part_main 按钮部件本身不能显示文本，需要在按钮部件上添加标签部件

*/

//开关部件 lv_switch 用于控制某个功能的开启和关闭，可以直接显示被控对象的状态
/*
开关部件组成部分:
主体：lv_part_main
滑块：lv_part_knob
指示器：lv_part_indicator
*/

static void event_cb(lv_event_t *e)
{


}

// static void event_btn_cb(lv_event_t *e)
// {
//     lv_obj_t *target = lv_event_get_target(e);  //获取触发源
//     lv_event_code_t code = lv_event_get_code(e);

//     if (target == btn_plus)
//     {
//         printf("plus\n");
//         speed_val += 30;

//     }
//     else if (target == btn_minus)
//     {
//         printf("minus\n");
//         speed_val -= 30;
//     }
//     else if (target == btn_stop)
//     {
//         printf("stop\n");
//         speed_val = 0;
//     }

//     //更新速度值
//     lv_label_set_text_fmt(label_speed, "Speed: %d", speed_val);


// }

static void event_smart_control_cb(lv_event_t *e)
{
    bool state_cool;
    bool state_heat;
    bool state_dry;

    lv_obj_t *target = lv_event_get_target(e);  //获取触发源

    if (target == sw_cool) //cool和heat互斥
    {
        state_cool = lv_obj_has_state(sw_cool, LV_STATE_CHECKED); //获取开关的状态  判断当前状态是否为已打开 返回值为bool类型
        state_heat = lv_obj_has_state(sw_heat, LV_STATE_CHECKED);
        printf("cool state: %d\n", state_cool);
        if (state_cool == 1)
        {
            lv_obj_clear_state(sw_heat, LV_STATE_CHECKED); //设置为关闭状态 清除状态

        }

    }
    else if (target == sw_heat)
    {
        state_heat = lv_obj_has_state(sw_heat, LV_STATE_CHECKED); //获取开关的状态  判断当前状态是否为已打开 返回值为bool类型
        state_cool = lv_obj_has_state(sw_cool, LV_STATE_CHECKED);
        printf("heat state: %d\n", state_heat);
        if (state_heat == 1)
        {
            lv_obj_clear_state(sw_cool, LV_STATE_CHECKED); //设置为关闭状态 清除状态

        }
    }
    else if (target == sw_dry)
    {
        state_dry = lv_obj_has_state(sw_dry, LV_STATE_CHECKED); //获取开关的状态  判断当前状态是否为已打开 返回值为bool类型
        printf("dry state: %d\n", state_dry);
    }
}

void mygui()
{

#if practice1

    // 创建一个标签部件
    lv_obj_t *label = lv_label_create(lv_scr_act());
    lv_obj_align(label, LV_ALIGN_CENTER, 0, 0);

    // 设置文本的三种方式

    // 直接设置文本： lvgl进行动态内存分配，一般使用这种方式
    lv_label_set_text(label, "Hello world!Hello world!Hello world!Hello world!\nHello world!Hello world!Hello world!");

    // 静态存贮文本，存在指定的缓冲区
    // lv_label_set_text_static(label, "Hello world!");

    // 格式化地显示文本，类似于printf
    // lv_label_set_text_fmt(label, "Hello %s!", "world");

    // 设置文本的样式

    // 1、设置文本样式

    // 背景颜色
    lv_obj_set_style_bg_color(label, lv_color_hex(0xECD664), LV_STATE_DEFAULT);
    // 背景透明度默认完全透明
    lv_obj_set_style_bg_opa(label, 100, LV_STATE_DEFAULT);

    // 设置字体大小
    lv_obj_set_style_text_font(label, &lv_font_montserrat_24, LV_STATE_DEFAULT);
    // 使用什么大小的字体，就要到lv_conf.h给对应的宏置1

    // 设置字体的颜色
    lv_obj_set_style_text_color(label, lv_color_hex(0x258EEA), LV_STATE_DEFAULT);

    // 2、单独设置个别文本的颜色

    // lv_label_set_recolor(label, true); //启用重新着色
    // lv_label_set_text(label, "Hello #00ff00 world#");


    // !! v9版本的API变动，删除了lv_label_set_recolor函数
    //参考 https://github.com/lvgl/lvgl/issues/5352

    // 设置标签部件的大小 默认情况下，如果没有配置，标签部件的大小是根据文本的大小来自动调整的

    // 设置标签部件的大小

    lv_obj_set_size(label, 200, 60);

    // 设置长文本模式
    lv_label_set_long_mode(label, LV_LABEL_LONG_SCROLL_CIRCULAR);

    /*
    enum _lv_label_long_mode_t
    {
        LV_LABEL_LONG_WRAP, //默认模式，超出的文本会被裁剪
        LV_LABEL_LONG_DOT,  //超出的文本会被替换为...
        LV_LABEL_LONG_SCROLL, //来回滚动
        LV_LABEL_LONG_SCROLL_CIRCULAR, //循环滚动
        LV_LABEL_LONG_CLIP,  //超出的文本会被裁剪
    };
    */

    //文本对齐
    lv_obj_set_style_text_align(label, LV_TEXT_ALIGN_CENTER, 0);

    //文本对齐和标签部件对齐的区别
    /*标签部件对齐是指标签部件相对于其父对象的对齐方式，文本对齐是指文本内容在标签部件内部的对齐方式*/



    //特殊效果

    //阴影：创建另一个一模一样内容的标签部件，但是颜色不同，然后偏移一定的距离

    //从另一个标签部件中获取文本
    // char *text = lv_label_get_text(label); 可以作为另一个标签部件的文本参数
    //例如：lv_label_set_text(label2, text);

#elif practice2

    // // 创建一个按钮部件
    // lv_obj_t *btn = lv_btn_create(lv_scr_act());
    // lv_obj_set_size(btn, 100, 50);
    // lv_obj_align(btn, LV_ALIGN_CENTER, 0, 0);
    // lv_obj_set_style_bg_color(btn, lv_color_hex(0x258EEA), LV_STATE_PRESSED);


    // lv_obj_add_flag(btn, LV_OBJ_FLAG_CHECKABLE); //添加标志：可选中

    // //添加事件
    // //lv_obj_add_event_cb(btn, event_cb, LV_EVENT_CLICKED, NULL);
    // lv_obj_add_event_cb(btn, event_cb, LV_EVENT_VALUE_CHANGED, NULL); //当按钮的值发生改变时触发事件


    //例程：电机速度控制面板

    //speed+按钮，在活动屏幕内部左边
    btn_plus = lv_btn_create(lv_scr_act());
    lv_obj_set_size(btn_plus, 200, 100);
    lv_obj_align(btn_plus, LV_ALIGN_LEFT_MID, 50, 0);
    lv_obj_set_style_bg_color(btn_plus, lv_color_hex(0x0099FF), LV_STATE_DEFAULT);

    lv_obj_t *label_plus = lv_label_create(btn_plus);
    lv_label_set_text(label_plus, "Speed+");
    lv_obj_set_style_text_font(label_plus, &lv_font_montserrat_24, LV_STATE_DEFAULT);
    lv_obj_align(label_plus, LV_ALIGN_CENTER, 0, 0);

    lv_obj_add_event_cb(btn_plus, event_btn_cb, LV_EVENT_CLICKED, NULL); //被点击时触发事件

    //speed-按钮，在活动屏幕内部中间
    btn_minus = lv_btn_create(lv_scr_act());
    lv_obj_set_size(btn_minus, 200, 100);
    lv_obj_align(btn_minus, LV_ALIGN_CENTER, 0, 0);
    lv_obj_set_style_bg_color(btn_minus, lv_color_hex(0x0099FF), LV_STATE_DEFAULT);

    lv_obj_t *label_minus = lv_label_create(btn_minus);
    lv_label_set_text(label_minus, "Speed-");
    lv_obj_set_style_text_font(label_minus, &lv_font_montserrat_24, LV_STATE_DEFAULT);
    lv_obj_align(label_minus, LV_ALIGN_CENTER, 0, 0);

    lv_obj_add_event_cb(btn_minus, event_btn_cb, LV_EVENT_CLICKED, NULL); //被点击时触发事件


    //stop按钮，在活动屏幕内部右边
    btn_stop = lv_btn_create(lv_scr_act());
    lv_obj_set_size(btn_stop, 200, 100);
    lv_obj_align(btn_stop, LV_ALIGN_RIGHT_MID, -50, 0);
    lv_obj_set_style_bg_color(btn_stop, lv_color_hex(0xEF5F60), LV_STATE_DEFAULT); //默认颜色
    lv_obj_set_style_bg_color(btn_stop, lv_color_hex(0x05215F), LV_STATE_PRESSED); //按下后显示颜色
    lv_obj_add_flag(btn_stop, LV_OBJ_FLAG_CHECKABLE); //添加标志：可选中

    lv_obj_t *label_stop = lv_label_create(btn_stop);
    lv_label_set_text(label_stop, "Stop");
    lv_obj_set_style_text_font(label_stop, &lv_font_montserrat_24, LV_STATE_DEFAULT);
    lv_obj_align(label_stop, LV_ALIGN_CENTER, 0, 0);

    lv_obj_add_event_cb(btn_stop, event_btn_cb, LV_EVENT_CLICKED, NULL); //被点击时触发事件


    //创建显示当前速度的标签部件，在活动屏幕顶部
    label_speed = lv_label_create(lv_scr_act());
    lv_obj_set_style_text_font(label_speed, &lv_font_montserrat_24, LV_STATE_DEFAULT);
    lv_obj_align(label_speed, LV_ALIGN_TOP_MID, 0, 50);
    lv_label_set_text_fmt(label_speed, "Speed: %d", speed_val);

#elif practice3
    // //创建一个开关部件
    // sw = lv_switch_create(lv_scr_act()); //名称不能直接用switch，因为是关键字
    // lv_obj_align(sw, LV_ALIGN_CENTER, 0, 0);
    // lv_obj_set_size(sw, 100, 50);
    // lv_obj_set_style_bg_color(sw, lv_color_hex(0xFBF200), LV_PART_KNOB); //设置手柄为黄色 默认状态 只放部件时，LV_STATE_DEFAULT | LV_PART_KNOB
    // lv_obj_set_style_bg_color(sw, lv_color_hex(0x020CFF), LV_STATE_CHECKED | LV_PART_INDICATOR); //设置指示器为深蓝色 开启状态
    // lv_obj_set_style_bg_color(sw, lv_color_hex(0x00DF01), LV_PART_MAIN); //设置主体为绿色 默认状态 当开关状态为开时，指示器会覆盖掉主体的颜色

    // //添加、清除开关的状态
    // //默认是通过触摸的方式来改变开关的状态，也可以通过代码来改变
    // lv_obj_add_state(sw, LV_STATE_CHECKED); //设置为打开状态
    // lv_obj_clear_state(sw, LV_STATE_CHECKED); //设置为关闭状态 清除状态


    // lv_obj_add_state(sw, LV_STATE_DISABLED | LV_STATE_CHECKED); //设置为禁用状态 打开，且不可修改
    // lv_obj_remove_state(sw, LV_STATE_DISABLED | LV_STATE_CHECKED); //移除禁用状态

    // lv_obj_add_event_cb(sw, event_cb, LV_EVENT_VALUE_CHANGED, NULL); //添加事件

    // //获取、判断开关的状态
    // //bool state = lv_obj_has_state(sw, LV_STATE_CHECKED); //获取开关的状态  判断当前状态是否为已打开 返回值为bool类型

    //例程：智能家居控制系统
    obj_create_sw_cool();
    obj_create_sw_heat();
    obj_create_sw_dry();
    obj_create_label();



#elif practice4

#elif practice5

#elif practice6

#else

#endif
}



//智能家居控制系统的布局函数声明，一个打开制冷，一个打开制热，一个打开干燥。还有一个标签
static void obj_create_sw_cool()
{
    //基于活动屏幕创建一个基础部件，作为开关部件的父对象
    lv_obj_t *sw_cool_parent = lv_obj_create(lv_scr_act());
    lv_obj_set_size(sw_cool_parent, 160, 160);
    lv_obj_align(sw_cool_parent, LV_ALIGN_CENTER, -230, 0);
    lv_obj_set_style_border_opa(sw_cool_parent, 70, 0); //设置边框透明度

    //创建一个标签，显示Cool
    lv_obj_t *label_cool = lv_label_create(sw_cool_parent);
    lv_label_set_text(label_cool, "Cool");
    lv_obj_align(label_cool, LV_ALIGN_CENTER, 0, -30);
    lv_obj_set_style_text_font(label_cool, &lv_font_montserrat_24, LV_STATE_DEFAULT);

    //创建一个开关部件
    sw_cool = lv_switch_create(sw_cool_parent);
    lv_obj_align(sw_cool, LV_ALIGN_CENTER, 0, 20);
    lv_obj_set_size(sw_cool, 80, 40);

    //添加事件
    lv_obj_add_event_cb(sw_cool, event_smart_control_cb, LV_EVENT_VALUE_CHANGED, NULL); //当开关的值发生改变时触发事件


}

static void obj_create_sw_heat()
{
    lv_obj_t *sw_heat_parent = lv_obj_create(lv_scr_act());
    lv_obj_set_size(sw_heat_parent, 160, 160);
    lv_obj_align(sw_heat_parent, LV_ALIGN_CENTER, 0, 0);
    lv_obj_set_style_border_opa(sw_heat_parent, 70, 0); //设置边框透明度

    //创建一个标签，显示Heat
    lv_obj_t *label_heat = lv_label_create(sw_heat_parent);
    lv_label_set_text(label_heat, "Heat");
    lv_obj_align(label_heat, LV_ALIGN_CENTER, 0, -30);
    lv_obj_set_style_text_font(label_heat, &lv_font_montserrat_24, LV_STATE_DEFAULT);

    //创建一个开关部件
    sw_heat = lv_switch_create(sw_heat_parent);
    lv_obj_align(sw_heat, LV_ALIGN_CENTER, 0, 20);
    lv_obj_set_size(sw_heat, 80, 40);

    lv_obj_add_event_cb(sw_heat, event_smart_control_cb, LV_EVENT_VALUE_CHANGED, NULL); //当开关的值发生改变时触发事件

}

static void obj_create_sw_dry()
{
    lv_obj_t *sw_dry_parent = lv_obj_create(lv_scr_act());
    lv_obj_set_size(sw_dry_parent, 160, 160);
    lv_obj_align(sw_dry_parent, LV_ALIGN_CENTER, 230, 0);
    lv_obj_set_style_border_opa(sw_dry_parent, 70, 0); //设置边框透明度

    //创建一个标签，显示Dry
    lv_obj_t *label_dry = lv_label_create(sw_dry_parent);
    lv_label_set_text(label_dry, "Dry");
    lv_obj_align(label_dry, LV_ALIGN_CENTER, 0, -30);
    lv_obj_set_style_text_font(label_dry, &lv_font_montserrat_24, LV_STATE_DEFAULT);

    //创建一个开关部件
    sw_dry = lv_switch_create(sw_dry_parent);
    lv_obj_align(sw_dry, LV_ALIGN_CENTER, 0, 20);
    lv_obj_set_size(sw_dry, 80, 40);
    lv_obj_add_state(sw_dry, LV_STATE_CHECKED | LV_STATE_DISABLED); //设置为打开状态,且不可修改

    lv_obj_add_event_cb(sw_dry, event_smart_control_cb, LV_EVENT_VALUE_CHANGED, NULL); //当开关的值发生改变时触发事件

}

static void obj_create_label()
{
    //以活动屏幕为父对象，创建一个标签部件，显示Control Center
    lv_obj_t *label_control = lv_label_create(lv_scr_act());
    lv_label_set_text(label_control, "Control Center");
    lv_obj_align(label_control, LV_ALIGN_TOP_MID, 0, 40);
    lv_obj_set_style_text_font(label_control, &lv_font_montserrat_30, LV_STATE_DEFAULT);

}

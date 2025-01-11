#include "mygui.h"

/*这个分支主要存放控件学习中的 进度条、加载器、LED部件、列表部件*/

#define practice1 0
#define practice2 0
#define practice3 0
#define practice4 1
#define practice5 0
#define practice6 0
#define practice7 0

lv_obj_t *btn1;
lv_obj_t *btn2;
lv_obj_t *btn3;
lv_obj_t *btn4;
lv_obj_t *btn5;
lv_obj_t *btn6;

// 进度条部件lv_bar    用于显示当前任务的进度，可以是水平的或者垂直的
/*
组成部分：
主体：进度条的背景 lv_part_main
指示器：进度条的进度 lv_part_indicator

*/


//加载器部件lv_spinner  常用于提示当前任务正在加载
/*
组成部分：
主体：加载器的背景 lv_part_main
指示器：加载器的指示器 lv_part_indicator 是一个圆弧，后续设置加载器样式基本都是设置圆弧的样式
手柄：加载器的手柄 lv_part_knob

*/

//LED部件 lv_led  用于显示设备的状态
/*只有一个主体部分lv_part_main */

//列表部件lv_list 常用于多选一，默认会显示多个选项
/*
组成部分：
主体：列表的背景 lv_part_main
滚动条：列表的滚动条 lv_part_scrollbar
*/

static void event_list_cb(lv_event_t *e)
{
    lv_event_code_t code = lv_event_get_code(e);
    lv_obj_t *target = lv_event_get_target(e);
    if (target == btn1)
    {
        //获取列表按钮的文本，并打印出来
        const char *text = lv_list_get_btn_text(lv_obj_get_parent(target), target); //直接通过target获取父对象
        printf("btn1:%s\n", text);
    }

}

void mygui()
{

#if practice1
    // 创建进度条部件
    lv_obj_t *bar1 = lv_bar_create(lv_scr_act());
    lv_obj_set_size(bar1, 200, 20); //横向大于纵向，就是横向进度条，反之就是纵向进度条
    lv_obj_align(bar1, LV_ALIGN_CENTER, 0, 0);

    // 设置进度条的值
    lv_bar_set_range(bar1, 0, 100);  // 设置进度条的范围
    //lv_bar_set_value(bar1, 70, LV_ANIM_ON); // 设置进度条的值
    //第三个参数是动画的开关，LV_ANIM_ON表示开启动画，LV_ANIM_OFF表示关闭动画

    // 设置动画时间  必须在设置当前值之前设置
    lv_obj_set_style_anim_time(bar1, 1000, LV_STATE_DEFAULT); // 设置动画时间为1000ms
    lv_bar_set_value(bar1, 70, LV_ANIM_ON); // 设置进度条的值

    //设置模式
    lv_bar_set_mode(bar1, LV_BAR_MODE_RANGE); // 设置进度条的模式
    /*
    枚举型变量：
    LV_BAR_MODE_NORMAL：默认模式 从设定的范围的最小值绘制到当前值
    LV_BAR_MODE_SYMMETRICAL：从零绘制到指定值，指定值可以小于零
    LV_BAR_MODE_RANGE： 允许设定起始值，起始值必须小于当前值
    */

    //设置起始值 只有在LV_BAR_MODE_RANGE模式下才有效
    lv_bar_set_start_value(bar1, 20, LV_ANIM_ON); // 设置起始值
    //lv_bar_set_value(bar1, 70, LV_ANIM_ON); // 设置当前值，从20加载到70

    //例程 用lv_timer定时器来改变进度条的值
    //lv_timer_create(回调函数，定时时间，参数) ，在回调函数里面调用lv_bar_set_value(bar1, 70, LV_ANIM_ON);来改变进度条的值

#elif practice2
    // 创建一个加载器
    lv_obj_t *spinner1 = lv_spinner_create(lv_scr_act());
    lv_obj_align(spinner1, LV_ALIGN_CENTER, 0, 0);
    lv_obj_set_size(spinner1, 100, 100);

    //设置样式
    //圆弧颜色 第三个参数表示设置那一部分的颜色，以及什么时候设置
    lv_obj_set_style_arc_color(spinner1, lv_color_hex(0x072062), LV_PART_INDICATOR); //加载器部分的颜色
    lv_obj_set_style_arc_color(spinner1, lv_color_hex(0xF2F2F2), LV_PART_MAIN); //主体部分的颜色

    //圆弧宽度
    lv_obj_set_style_arc_width(spinner1, 20, LV_PART_INDICATOR); //加载器部分的宽度
    lv_obj_set_style_arc_width(spinner1, 20, LV_PART_MAIN); //主体部分的宽度

#elif practice3
    // 创建一个LED
    lv_obj_t *led1 = lv_led_create(lv_scr_act());
    lv_obj_align(led1, LV_ALIGN_CENTER, 0, 0);
    lv_obj_set_size(led1, 100, 100);

    //设置颜色 默认颜色是蓝色
    lv_led_set_color(led1, lv_color_hex(0xFBD801)); // 设置LED的颜色

    //设置亮度 亮度范围0-255
    lv_led_set_brightness(led1, 150); // 设置LED的亮度

    //设置led灯的状态：一般在事件回调函数里面设置
    lv_led_on(led1); // 设置LED为亮
    //lv_led_off(led1); // 设置LED为灭
    //lv_led_toggle(led1); // 切换LED的状态

#elif practice4
    // 创建一个列表
    lv_obj_t *list1 = lv_list_create(lv_scr_act());
    lv_obj_align(list1, LV_ALIGN_CENTER, 0, 0);
    lv_obj_set_size(list1, 200, 200);

    //设置列表文本，即列表的标题，一般显示在列表的左上方
    lv_list_add_text(list1, "Setting");

    //设置字体大小
    lv_obj_set_style_text_font(list1, &lv_font_montserrat_14, LV_PART_MAIN); // 设置主体部分的字体

    //添加列表按钮，同时接收返回值，可以用来设置按钮的样式
    //相当于是以列表为父对象，添加按钮
    btn1 = lv_list_add_btn(list1, LV_SYMBOL_OK, "Ok"); //三个参数，第二个是图标，第三个是文本，lvgl内置了图标枚举
    btn2 = lv_list_add_btn(list1, LV_SYMBOL_WIFI, "WLAN");
    btn3 = lv_list_add_btn(list1, LV_SYMBOL_VOLUME_MAX, "Volume");
    btn4 = lv_list_add_btn(list1, LV_SYMBOL_BELL, "Ring");
    btn5 = lv_list_add_btn(list1, LV_SYMBOL_HOME, "Home");
    btn6 = lv_list_add_btn(list1, LV_SYMBOL_CLOSE, "Close");

    //获取列表的文本，可以在回调函数中用触发源判断是哪个按钮被按下
    const char *text = lv_list_get_btn_text(list1, btn1); // 获取btn1的文本

    //添加事件 添加列表中按钮的事件，而不是列表的事件，在回调函数中获取按钮的文本
    lv_obj_add_event_cb(btn1, event_list_cb, LV_EVENT_CLICKED, NULL); // 设置事件回调函数

#elif practice5

#elif practice6

#else

#endif
}

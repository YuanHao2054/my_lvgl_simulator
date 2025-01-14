#include "mygui.h"

// 这部分主要存下拉列表、滚轮、滑块、圆弧 线条部分的代码

#define practice1 0
#define practice2 0
#define practice3 0
#define practice4 0
#define practice5 1
#define practice6 6
#define practice7 0

static lv_obj_t *dropdown;
static lv_obj_t *roller;

/*下拉列表lv_dropdown 常用于多选一的场景，点击后可以展示多个选项*/
/*
组成部分：
按钮 button
列表 list
*/

/*滚轮部件lv_roller 常用于多选一的场景，以滚轮的形式来展现多个选项*/
/*
组成部分：
主体 lv_part_main
选项框 lv_part_selected
*/

/*滑块部件lv_slider 常用于调节某个参数的值，以直线滑动的方式来修改数值*/
/*
组成部分：
主体 lv_part_main
指示器 lv_part_indicator
把手 lv_part_knob
*/

// 圆弧部件：lv_arc 用圆弧的方式来调节或展示某个参数的值
/*
组成部分：
背景弧 lv_part_main
前景弧 lv_part_indicator
把手 lv_part_knob
*/

// 线条部件：lv_line 在指定的坐标直接画直线，可以交叉也可以闭合
/*
组成部分：
主体 lv_part_main
*/

static void event_dropdown_cb(lv_event_t *e)
{
    char buf[32];
    lv_dropdown_get_selected_str(dropdown, buf, sizeof(buf));
    printf("选中的选项是：%s\n", buf);
    printf("选中的选项是：%d\n", lv_dropdown_get_selected(dropdown));
}

static void event_roller_cb(lv_event_t *e)
{
    char buf[32];
    lv_roller_get_selected_str(roller, buf, sizeof(buf));
    printf("选中的选项是：%s\n", buf);
    printf("选中的选项是：%d\n", lv_roller_get_selected(roller));
}

static void event_slider_cb(lv_event_t *e)
{
    lv_obj_t *slider = lv_event_get_target(e);
    printf("当前值是：%d\n", lv_slider_get_value(slider));
}

static void event_arc_cb(lv_event_t *e)
{
    lv_obj_t *arc = lv_event_get_target(e);
    printf("当前值是：%d\n", lv_arc_get_value(arc));
}

void mygui()
{

#if practice1
    // 创建一个下拉列表
    dropdown = lv_dropdown_create(lv_scr_act());
    lv_obj_set_size(dropdown, 200, 50);
    lv_obj_align(dropdown, LV_ALIGN_CENTER, 0, 0);
    lv_obj_set_style_text_font(dropdown, &lv_font_montserrat_24, 0); // 只是设置选择框里的字体大小，选项里的字体大小没有配置

    // lv_dropdown_set_selected_highlight(dropdown, true); //设置选中的选项高亮显示

    // 设置选项内容
    //  lv_dropdown_set_options(dropdown, "Apple\n"
    //                                    "Banana\n"
    //                                    "Orange\n"
    //                                    "Melon\n"
    //                                    "Grape\n"
    //                                    "Raspberry");

    lv_dropdown_set_options(dropdown, "Apple\nBanana\nOrange\nMelon\nGrape\nRaspberry");
    // 设置选项（静态）可以节约内存
    // lv_dropdown_set_options_static(dropdown, "a\nb\nc\nd");

    // 单独添加选项到下拉列表 索引从0开始
    // lv_dropdown_add_option(dropdown, "Kiwi", LV_DROPDOWN_POS_LAST); //添加到最后，也有对应的宏
    lv_dropdown_add_option(dropdown, "Kiwi", 2);

    // 设置当前选中的选项  使用索引
    lv_dropdown_set_selected(dropdown, 2);

    // 获取当前选中的选项 一般用于回调函数

    lv_dropdown_get_selected(dropdown); // 获取当前选中的选项的索引
    char buf[32];
    lv_dropdown_get_selected_str(dropdown, buf, sizeof(buf));

    // 设置方向和图标
    lv_dropdown_set_dir(dropdown, LV_DIR_BOTTOM);     // 设置下拉列表的方向
    lv_dropdown_set_symbol(dropdown, LV_SYMBOL_DOWN); // 设置下拉列表的图标，可以使用系统自带的图标

    // 设置回调函数
    lv_obj_add_event_cb(dropdown, event_dropdown_cb, LV_EVENT_VALUE_CHANGED, NULL);

#elif practice2
    // 创建滚轮部件
    roller = lv_roller_create(lv_scr_act());
    lv_obj_set_size(roller, 100, 100);
    lv_obj_align(roller, LV_ALIGN_CENTER, 0, 0);

    // 设置选项间隔
    lv_obj_set_style_text_line_space(roller, 5, LV_STATE_DEFAULT);

    // 设置选项内容，和它们的滚动模式
    //  lv_roller_set_options(roller, "Apple\n"
    //                                "Banana\n"
    //                                "Orange\n"
    //                                "Melon\n"
    //                                "Grape\n"
    //                                "Raspberry\n"
    //                                "Cherry\n"
    //                                "Pear\n"
    //                                "Kiwi\n", LV_ROLLER_MODE_INFINITE);

    lv_roller_set_options(roller, "Apple\nBanana\nOrange\nMelon\nGrape\nRaspberry\nCherry\nPear\nKiwi", LV_ROLLER_MODE_NORMAL);
    // 模式只有两种，一种是无限滚动，一种是正常滚动

    // 设置当前选项 根据索引 从0开始 选择是否有动画
    lv_roller_set_selected(roller, 2, LV_ANIM_OFF);

    // 设置可见行数
    lv_roller_set_visible_row_count(roller, 6);

    // 获取选项内容
    lv_roller_get_selected(roller); // 获取当前选中的选项的索引
    char buf[32];
    lv_roller_get_selected_str(roller, buf, sizeof(buf));

    // 设置回调函数
    lv_obj_add_event_cb(roller, event_roller_cb, LV_EVENT_VALUE_CHANGED, NULL);
#elif practice3
    // 创建一个滑块
    lv_obj_t *slider = lv_slider_create(lv_scr_act());
    lv_obj_set_size(slider, 200, 20);
    lv_obj_align(slider, LV_ALIGN_CENTER, 0, 0);

    // 设置范围
    lv_slider_set_range(slider, 0, 100);
    // 设置当前值
    lv_slider_set_value(slider, 50, LV_ANIM_OFF);

    // 获取当前值
    lv_slider_get_value(slider);

    // 设置回调函数
    lv_obj_add_event_cb(slider, event_slider_cb, LV_EVENT_VALUE_CHANGED, NULL);

    // 模式设置
    lv_slider_set_mode(slider, LV_SLIDER_MODE_RANGE); // 正常模式
    /*
    LV_SLIDER_MODE_NORMAL //正常模式：滑块在最小值和最大值之间移动
    LV_SLIDER_MODE_SYMMETRICAL //对称模式：滑块在中间点对称地移动
    LV_SLIDER_MODE_RANGE //范围模式：滑块可以选择一个范围
    */

    // 设置、获取左值 在范围模式下使用 左值不能大于右值，右值是用户调节的值
    lv_slider_set_left_value(slider, 20, LV_ANIM_OFF);
    lv_slider_get_left_value(slider); // 获取左值

#elif practice4
    // 创建一个圆弧
    lv_obj_t *arc = lv_arc_create(lv_scr_act());
    lv_obj_set_size(arc, 200, 200);
    lv_obj_align(arc, LV_ALIGN_CENTER, 0, 0);

    // 设定范围值、当前值
    lv_arc_set_range(arc, 0, 100);
    lv_arc_set_value(arc, 80);

    // 设定前景弧角度  参数是从135度到45度。以x轴正方向为0度，逆时针为正方向
    lv_arc_set_bg_angles(arc, 135, 45); // 设置背景弧的角度
    // lv_arc_set_angles(arc, 0, 270); //设置前景弧的角度

    // 设定旋转角度 圆弧部件整体顺时针旋转设定的角度
    lv_arc_set_rotation(arc, 0);

    // 获取当前值
    lv_arc_get_value(arc);

    // 设定模式
    lv_arc_set_mode(arc, LV_ARC_MODE_SYMMETRICAL); // 正常模式
    /*
    LV_ARC_MODE_NORMAL 正常模式：圆弧按正常方向显示
    LV_ARC_MODE_SYMMETRICAL 对称模式：圆弧在中间点对称显示 指示器的起始值在中间
    LV_ARC_MODE_REVERSE 反向模式：圆弧按反方向显示 起始值0在最右边 逆时针调整参数值
    */

    // 设定圆弧绘制速率 更改圆弧的值时，圆弧的变化速率
    lv_arc_set_change_rate(arc, 90); // 单位：度/秒

    // 添加回调函数
    lv_obj_add_event_cb(arc, event_arc_cb, LV_EVENT_VALUE_CHANGED, NULL);

#elif practice5
    // 创建一个基础部件来承接线条
    lv_obj_t *obj = lv_obj_create(lv_scr_act());
    lv_obj_set_size(obj, 200, 200);
    lv_obj_align(obj, LV_ALIGN_CENTER, 0, 0);

    // 创建一个线条
    lv_obj_t *line = lv_line_create(obj);

    // 设置线条坐标点 坐标点的参考系依托于线条部件本身，(0,0)在线条部件的左上角
    // 注意：lvgl v9后坐标数组的类型是lv_point_precise_t，v8时是lv_point_t
    static lv_point_precise_t line_point[] = {
        {0, 0},
        {100, 100},
        {100, 0},
        {0, 100},
        {0, 0}};
    lv_line_set_points(line, line_point, sizeof(line_point) / sizeof(line_point[0])); // 参数2是坐标点数组，参数3是坐标点个数

    // 设置线条的样式
    lv_obj_set_style_line_width(line, 8, LV_PART_MAIN);                      // 设置线条的宽度
    lv_obj_set_style_line_color(line, lv_color_hex(0x0093F5), LV_PART_MAIN); // 设置线条的颜色
    lv_obj_set_style_line_rounded(line, true, LV_PART_MAIN);                 // 设置线条的圆角

    // 设置y轴翻转
    lv_line_set_y_invert(line, true); // 设置y轴翻转

#elif practice6

#else

#endif
}

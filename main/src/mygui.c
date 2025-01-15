#include "mygui.h"

// 这部分主要存放图片、色环、按钮矩阵、文本区域、键盘部分的代码

#define practice1 0
#define practice2 0
#define practice3 0
#define practice4 0
#define practice5 1
#define practice6 0
#define practice7 0

// 图片lv_img
/*
组成部分
主体：lv_part_main
*/

// 色环部件lv_colorwheel  一般用做颜色选择器
/*
组成部分：
主体：lv_part_main
把手：lv_part_knob
*/

// 按钮矩阵  lv_btnmatrix  可以在不同的行和列中显示多个轻量级按钮
/*
组成部分：
主体：lv_part_main
按钮：lv_part_items
*/

//文本区域部件 lv_textarea  用于显示和编辑文本，即文本输入框，用户可以在其中输入文本内容
/*
组成部分：
主体：lv_part_main
滚动条：lv_part_scrollbar
所选文本：lv_part_selected
光标：lv_part_cursor
占位符：textarea_placeholder
*/

//键盘部件 lv_keyboard  用于输入文本


LV_IMG_DECLARE(img_test); // 声明一个图片

static void event_btnmatrix_cb(lv_event_t *e)
{
    lv_obj_t *target = lv_event_get_target(e);
    uint32_t id;
    id = lv_btnmatrix_get_selected_btn(target);
    //获取按钮的文本
    const char *text = lv_btnmatrix_get_btn_text(target, id);
    printf("Button %d is pressed, text is %s\n", id, text);
    //当传递一个字符串指针给printf函数时，printf函数会打印字符串的内容，直到遇到字符串的结束符'\0'为止，因此不需要解引用
}

void mygui()
{

#if practice1
    // 创建一个图片对象
    lv_obj_t *img1 = lv_img_create(lv_scr_act());

    // 设置图片对象的源
    // 图片来源有三个：1、c语言的数组 2、bin文件 3、lvgl内置的图标

    // c语言数组，可以用lvgl官网提供的工具，将图片生成为一个c文件，添加进工程，并且用LV_IMG_DECLARE函数外声明
    // LV_IMG_DECLARE(gImage_yingwu);  //声明一个图片
    lv_img_set_src(img1, &img_test); // 设置图片源

    // 设置图片偏移  偏移超出图片的部分，会从另一端显示
    lv_img_set_offset_x(img1, 10); // x轴偏移10
    lv_img_set_offset_y(img1, 10); // y轴偏移10

    // 图片重新着色
    lv_obj_set_style_img_recolor(img1, lv_color_hex(0x00ff00), LV_PART_MAIN); // 将图片着色为绿色
    lv_obj_set_style_img_recolor_opa(img1, LV_OPA_50, LV_PART_MAIN);          // 设置图片着色透明度

    // 图片旋转 顺时针旋转 参数为角度乘以10
    lv_img_set_angle(img1, 900); // 设置图片旋转90度

    // 图片缩放 128(1/2)50%  256(1/1)100%  512(2/1)缩放200%
    lv_img_set_zoom(img1, 128); // 设置图片缩放50%

    // 设置中心点 默认情况下图片的旋转和缩放都是以图片的几何中心为中心点，可以通过设置中心点来改变
    lv_obj_update_layout(img1); // 先要更新布局
    lv_img_set_pivot(img1, 400, 0);

#elif practice2
    lv_obj_t *colorwheel = lv_colorwheel_create(lv_scr_act(), true); // 创建一个色环对象 第二个参数表示把手的颜色是否为当前选择的颜色（色环选择的颜色）
    lv_obj_set_size(colorwheel, 200, 200);                           // 设置色环的大小
    lv_obj_align(colorwheel, LV_ALIGN_CENTER, 0, 0);                 // 设置色环的位置

#elif practice3
    // 创建一个按钮矩阵
    lv_obj_t *btnmatrix = lv_btnmatrix_create(lv_scr_act());
    lv_obj_set_size(btnmatrix, 200, 200);           // 设置按钮矩阵的大小
    lv_obj_align(btnmatrix, LV_ALIGN_CENTER, 0, 0); // 设置按钮矩阵的位置

    // 设置按钮数量、文本 定义按钮数组，最后一个元素必须为空 如果要换行，则\n占用一个数组元素
    static const char *btnm_map[] = {"1", "2", "3", "4", "5", "\n", "6", "7", "8", "9", ""};
    lv_btnmatrix_set_map(btnmatrix, btnm_map); // 设置按钮矩阵的按钮

    // 设置按钮的相对宽度，第二个参数为按钮的索引，从0开始，第三个参数为宽度
    lv_btnmatrix_set_btn_width(btnmatrix, 0, 20); // 设置第一个按钮的宽度为20

    // 按钮的长度由按钮的行数和按钮部件的高度决定，可以通过设置按钮部件的高度来改变按钮的长度

    // 获取按钮索引、文本 一般在回调函数中被调用
    uint32_t id = lv_btnmatrix_get_selected_btn(btnmatrix); // 获取被按下的按钮的索引
    lv_btnmatrix_get_btn_text(btnmatrix, id);               // 通过按钮索引获取按钮的文本

    // 为按钮添加属性
    lv_btnmatrix_set_btn_ctrl(btnmatrix, 0, LV_BTNMATRIX_CTRL_HIDDEN);    // 第二个参数是按钮索引，第三个参数是按钮的属性
    lv_btnmatrix_set_btn_ctrl(btnmatrix, 1, LV_BTNMATRIX_CTRL_DISABLED);  // 禁用按钮
    lv_btnmatrix_set_btn_ctrl(btnmatrix, 2, LV_BTNMATRIX_CTRL_CHECKABLE); // 启用按钮状态切换
    lv_btnmatrix_set_btn_ctrl(btnmatrix, 3, LV_BTNMATRIX_CTRL_CHECKED);   // 选中按钮
    lv_btnmatrix_set_btn_ctrl(btnmatrix, 4, LV_BTNMATRIX_CTRL_POPOVER);   // 按下此按钮时在弹出窗口中显示按钮标签
    lv_btnmatrix_set_btn_ctrl(btnmatrix, 5, LV_BTNMATRIX_CTRL_NO_REPEAT);   // 启用按钮文本的重新着色功能

    // 清除按钮的属性
    lv_btnmatrix_clear_btn_ctrl(btnmatrix, 0, LV_BTNMATRIX_CTRL_HIDDEN);
    // 属性为枚举型，有以下几种：
    // LV_BUTTONMATRIX_CTRL_HIDDEN：将按钮隐藏
    // LV_BUTTONMATRIX_CTRL_NO_REPEAT： 禁用长按
    // LV_BUTTONMATRIX_CTRL_DISABLED：禁用按钮
    // LV_BUTTONMATRIX_CTRL_CHECKABLE：启用按钮状态切换
    // LV_BUTTONMATRIX_CTRL_CHECKED： 选中按钮
    // LV_BUTTONMATRIX_CTRL_CLICK_TRIG： 1: 点击时发送 LV_EVENT_VALUE_CHANGE，0: 按下时发送 LV_EVENT_VALUE_CHANGE
    // LV_BUTTONMATRIX_CTRL_POPOVER： 按下此按钮时在弹出窗口中显示按钮标签
    // _LV_BUTTONMATRIX_CTRL_RESERVED_1： 保留供以后使用
    // _LV_BUTTONMATRIX_CTRL_RESERVED_2： 保留供以后使用
    // _LV_BUTTONMATRIX_CTRL_RESERVED_3： 保留供以后使用
    // LV_BUTTONMATRIX_CTRL_CUSTOM_1： 自定义可用标志
    // LV_BUTTONMATRIX_CTRL_CUSTOM_2： 自定义可用标志

    //设置按钮互斥 某一时刻， 只允许有一个按钮处于按下不弹起状态（被选中） ， 当我们选中一个按钮之后，其他的按钮将会自动清除选中属性
    lv_btnmatrix_set_one_checked(btnmatrix, true);

    // 添加回调函数
    //lv_obj_add_event_cb(btnmatrix, event_btnmatrix_cb, LV_STATE_CHECKED, NULL);
    lv_obj_add_event_cb(btnmatrix, event_btnmatrix_cb, LV_STATE_CHECKED, NULL);

#elif practice4
    //创建一个文本区域
    lv_obj_t *ta = lv_textarea_create(lv_scr_act());
    lv_obj_set_size(ta, 500, 200);           //设置文本区域的大小
    lv_obj_align(ta, LV_ALIGN_TOP_MID, 0, 0); //设置文本区域的位置
    lv_obj_set_style_text_font(ta, &lv_font_montserrat_24, LV_PART_MAIN); //设置文本区域的字体

    //添加一个字符到当前光标处
    //lv_textarea_add_char(ta, 'a');

    //添加一个字符串到当前光标处
    //lv_textarea_add_text(ta, "Hello");

    //创建键盘部件
    lv_obj_t *kb = lv_keyboard_create(lv_scr_act());
    lv_obj_set_size(kb, 500, 200);           //设置键盘的大小
    lv_obj_align(kb, LV_ALIGN_BOTTOM_MID, 0, 0); //设置键盘的位置
    lv_obj_set_style_text_font(kb, &lv_font_montserrat_24, LV_PART_MAIN); //设置键盘的字体

    //关联文本区域和键盘
    lv_keyboard_set_textarea(kb, ta);
    //可以添加回调函数，当文本框被聚焦时，关联键盘。这样可以让键盘为不同的文本框输入

    //设置光标位置 测试好像只有0和LV_TEXTAREA_CURSOR_LAST有效
    lv_textarea_set_cursor_pos(ta, 0); //LV_TEXTAREA_CURSOR_LAST为最右侧

    //删除文本
    lv_textarea_delete_char(ta); //删除光标左侧的字符
    lv_textarea_delete_char_forward(ta); //删除光标前的字符


    //设置模式
    lv_textarea_set_one_line(ta, true); //设置文本区域为单行模式 整个文本框只有1行的高度
    lv_textarea_set_password_mode(ta, false); //设置文本区域为密码模式 显示为*
    lv_textarea_set_password_show_time(ta, 1000); //设置密码显示时间

    //限制字符shuru
    lv_textarea_set_accepted_chars(ta, "1234567890"); //只允许输入数字
    lv_textarea_set_max_length(ta, 10); //设置最大输入长度

    //设置占位符 隐式显示，当文本区域为空时显示
    lv_textarea_set_placeholder_text(ta, "password:"); //设置占位符文本

    //获取文本框文本 一般在回调函数中被调用
    const char *text = lv_textarea_get_text(ta); //获取文本区域的文本

    //对比文本内容， 当text1 = text2 时，返回0
    lv_strcmp(text, "1234567890");

    //添加事件回调函数 任何事件都会触发回调函数，在回调函数里可以根据事件类型进行相应的操作
    lv_obj_add_event_cb(ta, event_btnmatrix_cb, LV_EVENT_ALL, NULL);


#elif practice5
    //创建一个键盘部件
    lv_obj_t *kb = lv_keyboard_create(lv_scr_act());
    lv_obj_set_size(kb, 500, 200);           //设置键盘的大小
    lv_obj_align(kb, LV_ALIGN_CENTER, 0, 0); //设置键盘的位置
    lv_obj_set_style_text_font(kb, &lv_font_montserrat_24, LV_PART_MAIN); //设置键盘的字体

    //关联文本框
    //参考文本区域部件

    //设置按键弹窗：按下按键时，弹出一个小窗口显示按键的标签
    lv_keyboard_set_popovers(kb, true); //设置按键弹窗

    //设置按钮模式
    lv_keyboard_set_mode(kb, LV_KEYBOARD_MODE_SPECIAL); //设置键盘模式
    //键盘模式有以下几种：
    //LV_KEYBOARD_MODE_TEXT_LOWER：小写字母
    //LV_KEYBOARD_MODE_TEXT_UPPER：大写字母
    //LV_KEYBOARD_MODE_SPECIAL：特殊字符
    //LV_KEYBOARD_MODE_NUMBER：数字

#elif practice6

#else

#endif
}

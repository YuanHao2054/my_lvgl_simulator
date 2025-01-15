#include "mygui.h"
#include <string.h>

// 创建两个文本区域，分别输入用户名和密码
// 创建一个键盘、提示标签
// 当用户名和密码正确时，全屏显示图片

// 函数声明
static void create_textarea_username();
static void create_textarea_password();
static void create_keyboard();
static void create_label();
static void create_image();
static void event_textarea_cb(lv_event_t *e);
static void event_keyboard_cb(lv_event_t *e);

// 图片声明
LV_IMG_DECLARE(img_test);

lv_obj_t *textarea_username;
lv_obj_t *textarea_password;
lv_obj_t *kb;

void mygui()
{
    create_textarea_username();
    create_textarea_password();
    create_keyboard();
    create_label();
    // 默认将键盘绑定到用户名
    lv_keyboard_set_textarea(kb, textarea_username);
}

static void create_textarea_username()
{
    // 创建单行显示文本部件，对齐在活动屏幕顶层
    textarea_username = lv_textarea_create(lv_scr_act());
    lv_obj_set_size(textarea_username, 500, 200);
    lv_obj_align(textarea_username, LV_ALIGN_TOP_MID, 0, 0);
    lv_obj_set_style_text_font(textarea_username, &lv_font_montserrat_24, LV_PART_MAIN);
    lv_textarea_set_one_line(textarea_username, true);
    lv_textarea_set_max_length(textarea_username, 10);
    lv_textarea_set_placeholder_text(textarea_username, "username");

    // 添加回调函数
    lv_obj_add_event_cb(textarea_username, event_textarea_cb, LV_EVENT_FOCUSED, NULL);
    lv_obj_add_event_cb(textarea_username, event_textarea_cb, LV_EVENT_VALUE_CHANGED, NULL);
}

static void create_textarea_password()
{
    textarea_password = lv_textarea_create(lv_scr_act());
    lv_obj_set_size(textarea_password, 500, 200);
    lv_obj_align(textarea_password, LV_ALIGN_TOP_MID, 0, 60);
    lv_obj_set_style_text_font(textarea_password, &lv_font_montserrat_24, LV_PART_MAIN);
    lv_textarea_set_one_line(textarea_password, true);
    lv_textarea_set_max_length(textarea_password, 10);
    lv_textarea_set_placeholder_text(textarea_password, "password");
    lv_textarea_set_password_mode(textarea_password, true);      // 设置文本区域为密码模式 显示为*
    lv_textarea_set_password_show_time(textarea_password, 2000); // 设置密码显示时间



    lv_obj_add_event_cb(textarea_password, event_textarea_cb, LV_EVENT_FOCUSED, NULL);
    lv_obj_add_event_cb(textarea_password, event_textarea_cb, LV_EVENT_VALUE_CHANGED, NULL);
}

static void create_keyboard()
{
    // 创建一个键盘
    kb = lv_keyboard_create(lv_scr_act());
    lv_obj_set_size(kb, 800, 300);
    lv_obj_align(kb, LV_ALIGN_BOTTOM_MID, 0, 0);
    lv_obj_set_style_text_font(kb, &lv_font_montserrat_24, LV_PART_MAIN);
}

static void create_label()
{
}

// 创建图像部件，在回调函数中调用
static void create_image()
{
    lv_obj_t *img1 = lv_img_create(lv_scr_act());
    lv_img_set_src(img1, &img_test);
}

static void event_textarea_cb(lv_event_t *e)
{
    lv_obj_t *target = lv_event_get_target(e);
    lv_event_code_t code = lv_event_get_code(e);

    // 判断用户名和密码是否正确的标志位
    static int is_username_right = 0;
    static int is_password_right = 0;

    if (target == textarea_username)
    {
        if (code == LV_EVENT_FOCUSED) /*文本框被聚焦*/
        {
            // 绑定键盘和文本框
            lv_keyboard_set_textarea(kb, target);

            //键盘设置为全文本
            lv_obj_set_size(kb, 800, 300);
            lv_keyboard_set_mode(kb, LV_KEYBOARD_MODE_TEXT_LOWER);
        }

        else if (code == LV_EVENT_VALUE_CHANGED) /*文本框内容发生改变*/
        {
            const char *text = lv_textarea_get_text(target);
            printf("%s\n", text);
            if (strcmp(text, "shushu") == 0)
            {
                is_username_right = 1;
            }
            else
            {
                is_username_right = 0;
            }
        }
    }

    else if (target == textarea_password)
    {
        if (code == LV_EVENT_FOCUSED)
        {
            // 绑定键盘和文本框
            lv_keyboard_set_textarea(kb, target);

            //键盘设置为数字小键盘
            lv_obj_set_size(kb, 400, 300);
            lv_keyboard_set_mode(kb, LV_KEYBOARD_MODE_NUMBER);
        }

        else if (code == LV_EVENT_VALUE_CHANGED) /*文本框内容发生改变*/
        {
            const char *text = lv_textarea_get_text(target);
            printf("%s\n", text);
            if (strcmp(text, "503503503") == 0)
            {
                is_password_right = 1;
            }
            else
            {
                is_password_right = 0;
            }
        }
    }

    if (is_password_right == 1 && is_username_right == 1)
    {
        printf("hello, world!\n");

        // 将两个标志位置0
        is_password_right = 0;
        is_username_right = 0;

        create_image();
    }
}

static void event_keyboard_cb(lv_event_t *e)
{

}

#include "mygui.h"

// 声明列表中的10个按钮
// static lv_obj_t *btn1;
// static lv_obj_t *btn2;
// static lv_obj_t *btn3;
// static lv_obj_t *btn4;
// static lv_obj_t *btn5;
// static lv_obj_t *btn6;
// static lv_obj_t *btn7;
// static lv_obj_t *btn8;
// static lv_obj_t *btn9;
// static lv_obj_t *btn10;

static lv_obj_t *btn; // 选中的按钮

lv_obj_t *label; // 右半部分显示列表按钮选择内容的标签

static void obj_left();
static void obj_right();

static void event_list_cb(lv_event_t *e)
{
    lv_obj_t *target = lv_event_get_target(e);

    const char *text = lv_list_get_btn_text(lv_obj_get_parent(target), target); // 获取按钮的文本内容

    // 根据按钮的文本内容，设置右半部分的标签内容
    lv_label_set_text_fmt(label, "%s", text);
    printf("Button %s is clicked\n", text);

    // 给按钮添加聚焦状态
    lv_obj_add_state(target, LV_STATE_FOCUS_KEY);
}

void mygui(void)
{
    // 左部件，放置列表
    obj_left();
    // 右部件，放置显示选择的内容的标签
    obj_right();
}

static void obj_left()
{
    // 创建一个基础对象，作为列表的父对象
    lv_obj_t *obj = lv_obj_create(lv_scr_act());
    lv_obj_set_size(obj, 300, 400);
    // 居中对齐，但往左偏移200
    lv_obj_align(obj, LV_ALIGN_CENTER, -200, 0);

    // 创建一个列表对象
    lv_obj_t *list = lv_list_create(obj);
    lv_obj_align(list, LV_ALIGN_CENTER, 0, 0);
    lv_obj_set_size(list, 250, 300);
    lv_obj_set_style_text_font(list, &lv_font_montserrat_14, LV_PART_MAIN);

    lv_list_add_text(list, "File");
    // btn1 = lv_list_add_btn(list, LV_SYMBOL_FILE, "File");           // File
    // btn2 = lv_list_add_btn(list, LV_SYMBOL_DIRECTORY, "Directory"); // Directory
    // btn3 = lv_list_add_btn(list, LV_SYMBOL_CLOSE, "Close");         // Close
    // btn4 = lv_list_add_btn(list, LV_SYMBOL_EDIT, "Edit");           // Edit
    // btn5 = lv_list_add_btn(list, LV_SYMBOL_SAVE, "Save");           // Save

    // 先设置按钮文本，再添加事件
    btn = lv_list_add_btn(list, LV_SYMBOL_FILE, "File"); // File
    lv_obj_add_event_cb(btn, event_list_cb, LV_EVENT_CLICKED, NULL);

    btn = lv_list_add_btn(list, LV_SYMBOL_DIRECTORY, "Directory"); // Directory
    lv_obj_add_event_cb(btn, event_list_cb, LV_EVENT_CLICKED, NULL);

    btn = lv_list_add_btn(list, LV_SYMBOL_CLOSE, "Close"); // Close
    lv_obj_add_event_cb(btn, event_list_cb, LV_EVENT_CLICKED, NULL);

    btn = lv_list_add_btn(list, LV_SYMBOL_EDIT, "Edit"); // Edit
    lv_obj_add_event_cb(btn, event_list_cb, LV_EVENT_CLICKED, NULL);

    btn = lv_list_add_btn(list, LV_SYMBOL_SAVE, "Save"); // Save
    lv_obj_add_event_cb(btn, event_list_cb, LV_EVENT_CLICKED, NULL);

    lv_list_add_text(list, "Connectitvity");

    btn = lv_list_add_btn(list, LV_SYMBOL_WIFI, "WiFi"); // WiFi
    lv_obj_add_event_cb(btn, event_list_cb, LV_EVENT_CLICKED, NULL);

    btn = lv_list_add_btn(list, LV_SYMBOL_BLUETOOTH, "Bluetooth"); // Bluetooth
    lv_obj_add_event_cb(btn, event_list_cb, LV_EVENT_CLICKED, NULL);

    btn = lv_list_add_btn(list, LV_SYMBOL_GPS, "GPS"); // GPS
    lv_obj_add_event_cb(btn, event_list_cb, LV_EVENT_CLICKED, NULL);

    btn = lv_list_add_btn(list, LV_SYMBOL_USB, "USB"); // USB
    lv_obj_add_event_cb(btn, event_list_cb, LV_EVENT_CLICKED, NULL);

    btn = lv_list_add_btn(list, LV_SYMBOL_SD_CARD, "SD Card"); // SD Card
    lv_obj_add_event_cb(btn, event_list_cb, LV_EVENT_CLICKED, NULL);
    // btn6 = lv_list_add_btn(list, LV_SYMBOL_WIFI, "WiFi");           // WiFi
    // btn7 = lv_list_add_btn(list, LV_SYMBOL_BLUETOOTH, "Bluetooth"); // Bluetooth
    // btn8 = lv_list_add_btn(list, LV_SYMBOL_GPS, "GPS");             // GPS
    // btn9 = lv_list_add_btn(list, LV_SYMBOL_USB, "USB");             // USB
    // btn10 = lv_list_add_btn(list, LV_SYMBOL_SD_CARD, "SD Card");    // SD Card

    // 为每个按钮添加事件
    // lv_obj_add_event_cb(btn1, event_list_cb, LV_EVENT_CLICKED, NULL);
    // lv_obj_add_event_cb(btn2, event_list_cb, LV_EVENT_CLICKED, NULL);
    // lv_obj_add_event_cb(btn3, event_list_cb, LV_EVENT_CLICKED, NULL);
    // lv_obj_add_event_cb(btn4, event_list_cb, LV_EVENT_CLICKED, NULL);
    // lv_obj_add_event_cb(btn5, event_list_cb, LV_EVENT_CLICKED, NULL);
    // lv_obj_add_event_cb(btn6, event_list_cb, LV_EVENT_CLICKED, NULL);
    // lv_obj_add_event_cb(btn7, event_list_cb, LV_EVENT_CLICKED, NULL);
    // lv_obj_add_event_cb(btn8, event_list_cb, LV_EVENT_CLICKED, NULL);
    // lv_obj_add_event_cb(btn9, event_list_cb, LV_EVENT_CLICKED, NULL);
    // lv_obj_add_event_cb(btn10, event_list_cb, LV_EVENT_CLICKED, NULL);
}

static void obj_right()
{
    // 创建一个基础对象，作为标签的父对象
    lv_obj_t *obj = lv_obj_create(lv_scr_act());
    lv_obj_set_size(obj, 300, 400);
    lv_obj_align(obj, LV_ALIGN_CENTER, 200, 0);

    label = lv_label_create(obj);
    lv_obj_align(label, LV_ALIGN_CENTER, 0, 0);
    lv_label_set_text_fmt(label, "Hello World");
    lv_obj_set_style_text_font(label, &lv_font_montserrat_30, 0);
}

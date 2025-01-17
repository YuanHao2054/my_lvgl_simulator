#include "mygui.h"
#include <string.h>

void mygui();

// 这个分支存放图片按钮、选择卡、平铺视图、窗口、消息框、微调器、表格

// 图片按钮 lv_imgbtn 类似于按钮部件，不同的是，用户可以在其中设置图片
/*
组成部分：
主体：lv_part_main
*/

// 选择卡 lv_tabview 可以实现多页面切换，用户可以在不同的页面中添加内容
/*
组成部分
主体：lv_part_main
按钮：lv_part_btnmatrix
*/

//平铺视图 lv_tileview 可以实现不同方向的多页面切换，每个页面就是一个容器，用户可以在不同的页面中添加内容
//正常情况下只有一个页面可见，其他页面处于隐藏状态
/*
组成部分：
主体：lv_part_main
滚动条：lv_part_scrollbar
*/

//窗口部件 lv_win 可以实现一个窗口，作为一个容器，用户可以在窗口中添加标题栏、内容、按钮等
/*
组成部分：
头部：lv_part_header 头部里面可以再放置标签、按钮
主体：lv_part_content
*/

//消息框部件 lv_msgbox 可以实现一个消息框，作为一个容器，用户可以在消息框中添加标题、内容、按钮等
/*
组成部分：
主体：lv_part_main
标题：lv_part_title
关闭按钮：close_btn
内容：content
按钮矩阵：btnmatrix
*/

//微调器 lv_spinbox 可以实现一个微调器，用户可以通过点击按钮或者拖动来改变数值 本质上就是一个数字文本
/*
组成部分：
主体：lv_part_main
光标：lv_part_cursor
*/

#define practice1 0
#define practice2 0
#define practice3 0
#define practice4 0
#define practice5 0
#define practice6 0
#define practice7 1

// 声明图片
LV_IMG_DECLARE(img_test);
LV_IMG_DECLARE(imgbtn9);


static void event_msgbox_cb(lv_event_t *e)
{
    lv_obj_t *target = lv_event_get_current_target(e); //获取当前目标
    lv_obj_t *btn = lv_msgbox_get_active_btn(target); //获取当前激活的按钮
    char *btn_text = lv_msgbox_get_active_btn_text(target); //获取当前激活的按钮的文本

    if (strcmp(btn_text, "Ok") == 0)
    {
        printf("Ok button is pressed\n");
    }
    else if (strcmp(btn_text, "Cancel") == 0)
    {
        printf("Cancel button is pressed\n");
    }
    else
    {
        printf("Unknown button is pressed\n");
    }
}

//表格部件 lv_table 可以实现一个表格，只能存放文本形式的内容
/*
组成部分：
主体：lv_part_main
单元格：lv_part_items
*/

void mygui()
{

#if practice1
    // 创建一个图片按钮
    lv_obj_t *imgbtn = lv_imagebutton_create(lv_scr_act());

    // 设置图片源 第二个参数表示什么时候显示这个图片
    lv_imagebutton_set_src(imgbtn, LV_IMAGEBUTTON_STATE_RELEASED, NULL, &imgbtn9, NULL);
    //三个图片源，分别是左边、中间、右边的图片

    // 按钮状态
    /*
    LV_IMGBTN_STATE_RELEASED：释放状态；
    LV_IMGBTN_STATE_PRESSED：按下状态；
    LV_IMGBTN_STATE_DISABLED：禁用状态；
    LV_IMGBTN_STATE_CHECKED_RELEASED：点击释放状态；
    LV_IMGBTN_STATE_CHECKED_PRESSED：点击按下状态；
    LV_IMGBTN_STATE_CHECKED_DISABLED：点击禁用状态；
    */

    // 设置大小
    lv_obj_set_size(imgbtn, 100, 100);
    lv_obj_align(imgbtn, LV_ALIGN_CENTER, 0, 0);

    //设置当按钮被按下时，按钮的状态
    lv_obj_set_style_img_recolor_opa(imgbtn, LV_OPA_30, LV_STATE_PRESSED); //当图片按下时，透明度为30
    lv_obj_set_style_img_recolor(imgbtn, lv_color_black(), LV_STATE_PRESSED); //当图片按下时，颜色为黑色
    lv_obj_set_style_translate_y(imgbtn, 5, LV_STATE_PRESSED); //当图片按下时，向下移动5个像素

    //添加/清除按钮的状态 lv_obj_add/clear_state

#elif practice2
    //创建一个选项卡
    lv_obj_t *tabview = lv_tabview_create(lv_scr_act(), LV_DIR_TOP, 60); //第二个参数表示选项卡的位置，第三个参数表示选项卡的大小
    lv_obj_set_size(tabview, 400, 400);
    lv_obj_align(tabview, LV_ALIGN_CENTER, 0, 0);

    //添加选项卡 该函数的返回值指针指向选项卡容器，可以用作其他部件的父对象
    lv_obj_t* tab1 = lv_tabview_add_tab(tabview, "Tab 1");
    lv_obj_t* tab2 = lv_tabview_add_tab(tabview, "Tab 2");
    lv_obj_t* tab3 = lv_tabview_add_tab(tabview, "Tab 3");

    //切换选择卡 除了触摸屏上手动切换，还可以用代码切换
    lv_tabview_set_act(tabview, 1, LV_ANIM_ON);  //第二个参数为选项卡索引，从0开始，第三个参数表示是否有动画

    //在tab1中添加一个标签
    lv_obj_t* label = lv_label_create(tab1);
    lv_label_set_text(label, "This is a label in tab 1");

    //在tab2中添加一个按钮
    lv_obj_t* btn = lv_btn_create(tab2);
    lv_obj_align(btn, LV_ALIGN_CENTER, 0, 0);

    //在tab3中添加一个开关
    lv_obj_t* sw = lv_switch_create(tab3);
    lv_obj_align(sw, LV_ALIGN_CENTER, 0, 0);

    //获取按钮矩阵部件 按钮矩阵就是tab1、tab2、tab3
    lv_tabview_get_tab_btns(tabview);

    //获取主体容器
    lv_tabview_get_content(tabview);



#elif practice3
    //创建一个平铺视图
    lv_obj_t *tileview = lv_tileview_create(lv_scr_act());

    //添加页面  给这个页面设置坐标和滑动方向，比如添加向右滑动它就只能向右滑动，如果要添加多个方向可以按位或
    lv_obj_t *tile1 = lv_tileview_add_tile(tileview, 0, 0, LV_DIR_RIGHT | LV_DIR_BOTTOM);
    lv_obj_t *tile2 = lv_tileview_add_tile(tileview, 1, 0, LV_DIR_ALL);
    lv_obj_t *tile3 = lv_tileview_add_tile(tileview, 0, 1, LV_DIR_ALL);


    //方向枚举：
    /*
    LV_DIR_LEFT：往左滑动
    LV_DIR_RIGHT：往右滑动
    LV_DIR_TOP：往上滑动
    LV_DIR_BOTTOM：往下滑动
    LV_DIR_HOR：水平滑动
    LV_DIR_VER： 垂直滑动
    LV_DIR_ALL ： 全部方向
    */


    //给页面里添加内容
    //在tile1里添加一个标签
    lv_obj_t* label = lv_label_create(tile1);
    lv_label_set_text(label, "This is a label in tile 1");
    lv_obj_align(label, LV_ALIGN_CENTER, 0, 0);

    //给tile2里添加一个开关
    lv_obj_t* sw = lv_switch_create(tile2);
    lv_obj_align(sw, LV_ALIGN_CENTER, 0, 0);
    lv_obj_set_size(sw, 50, 20);

    //给tile3里添加一个标签
    lv_obj_t* label2 = lv_label_create(tile3);
    lv_label_set_text(label2, "This is a label in tile 3");
    lv_obj_align(label2, LV_ALIGN_CENTER, 0, 0);

    //切换页面
    lv_obj_update_layout(tileview); //更新布局
    //lv_obj_set_tile(tileview, tile3, LV_ANIM_ON); //直接通过页面指针切换
    lv_obj_set_tile_id(tileview, 0, 1, LV_ANIM_ON); //通过页面索引切换



#elif practice4
    //创建一个窗口部件
    lv_obj_t *win = lv_win_create(lv_scr_act(), 40); //第二个参数为头部的高度
    lv_obj_set_size(win, 400, 400);
    lv_obj_align(win, LV_ALIGN_CENTER, 0, 0);

    //添加标题、按钮
    lv_obj_t *title = lv_win_add_title(win, "Setting");
    lv_obj_t *btn = lv_win_add_btn(win, LV_SYMBOL_CLOSE, 20); //第三个参数为按钮的宽度 按钮一般在标题栏右侧

    //添加主体内容，先获取窗口的主体content，再以这个content为父类创建其他部件
    lv_obj_t *content = lv_win_get_content(win);
    lv_obj_t *label = lv_label_create(content);
    lv_label_set_text(label, "This is a label in the content");
    lv_obj_align(label, LV_ALIGN_CENTER, 0, 0);

    lv_obj_set_style_border_color(win, lv_color_hex(0x1F1F1F), LV_STATE_DEFAULT); //设置边框颜色
    lv_obj_set_style_border_opa(win, LV_OPA_70, LV_STATE_DEFAULT); //设置边框透明度
    lv_obj_set_style_border_width(win, 2, LV_STATE_DEFAULT); //设置边框宽度

    lv_obj_update_layout(win); //更新布局

#elif practice5
    //创建一个消息框
    //先创建按钮矩阵
    static const char * btns[] = {"Ok", "Cancel", ""}; //最后一个字符串为空，表示结束
    lv_obj_t* msgbox = lv_msgbox_create(lv_scr_act(), "Notice", "This is a message box", btns, true); //第五个参数表示是否有关闭按钮
    lv_obj_align(msgbox, LV_ALIGN_CENTER, 0, 0);
    lv_obj_set_size(msgbox, 200, 150);

    //关闭消息框
    //lv_msgbox_close(msgbox);


    //添加回调函数，常用事件类型：LV_EVENT_VALUE_CHANGED
    lv_obj_add_event_cb(msgbox, event_msgbox_cb, LV_EVENT_VALUE_CHANGED, NULL);

#elif practice6
    //创建一个微调器
    lv_obj_t *spinbox = lv_spinbox_create(lv_scr_act());
    lv_obj_set_size(spinbox, 100, 50);
    lv_obj_align(spinbox, LV_ALIGN_CENTER, 0, 0);

    //数值增减
    lv_spinbox_increment(spinbox); //数值增加
    lv_spinbox_decrement(spinbox); //数值减少

    //设置步进值、范围
    lv_spinbox_set_range(spinbox, 0, 10000); //设置范围
    lv_spinbox_set_step(spinbox, 5); //设置步进值

    lv_obj_set_style_text_font(spinbox, &lv_font_montserrat_24, LV_PART_MAIN); //设置字体

    //设置当前值
    lv_spinbox_set_value(spinbox, 1000);

    //设置数字格式
    lv_spinbox_set_digit_format(spinbox, 5, 2); //第一个参数表示数值的位数，第二个参数表示小数点的位数

    //获取当前值
    int32_t val = lv_spinbox_get_value(spinbox);
    printf("Current value is %d\n", val);

#else
    //创建一个表格
    lv_obj_t *table = lv_table_create(lv_scr_act());
    lv_obj_set_size(table, 300, 200);
    lv_obj_align(table, LV_ALIGN_CENTER, 0, 0);

    //设置行列数
    lv_table_set_col_cnt(table, 3); //设置列数
    lv_table_set_row_cnt(table, 3); //设置行数
    //v_table_set_col_width(table, 0, 50); //设置第0列的宽度

    //设置单元格的内容
    lv_table_set_cell_value(table, 0, 0, "0,0"); //通过行列的索引
    lv_table_set_cell_value_fmt(table, 1, 1, "%d,%d", 1, 1); //通过格式化字符串

#endif
}

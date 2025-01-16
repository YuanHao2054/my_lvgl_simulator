#include "mygui.h"
#include <string.h>

// 这个分支存放图片按钮、选择卡、平铺视图、窗口

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

#define practice1 0
#define practice2 1
#define practice3 0
#define practice4 0
#define practice5 0
#define practice6 0
#define practice7 0

// 声明图片
LV_IMG_DECLARE(img_test);
LV_IMG_DECLARE(imgbtn9);

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
    lv_obj_t *tabview = lv_tabview_create(lv_scr_act());
    lv_obj_set_size(tabview, 400, 400);
    lv_obj_align(tabview, LV_ALIGN_CENTER, 0, 0);



#elif practice3

#elif practice4

#elif practice5

#elif practice6

#else

#endif
}

#include "mygui.h"
#include <string.h>

//部件声明
lv_obj_t *tabview; /*整体屏幕的容器*/
lv_obj_t* tab1; /*时钟*/
lv_obj_t* tab2; /*计数器*/
lv_obj_t* tab3; /*3D动画*/
lv_obj_t* tab4; /*开关*/
lv_obj_t* tab5; /*帮助*/

//声明字库
LV_FONT_DECLARE(Chinese_30);

static void create_clock();
static void create_counter();
static void create_3d();
static void create_switch();
static void create_help();


void mygui()
{
    //创建一个选项卡，占据整个屏幕
    tabview = lv_tabview_create(lv_scr_act(), LV_DIR_TOP, 80);
    lv_obj_set_size(tabview, 800, 480);
    lv_obj_align(tabview, LV_ALIGN_CENTER, 0, 0);

    //创建选项卡
    tab1 = lv_tabview_add_tab(tabview, "表");
    tab2 = lv_tabview_add_tab(tabview, "计数器");
    tab3 = lv_tabview_add_tab(tabview, "3D动画");
    tab4 = lv_tabview_add_tab(tabview, "开关");
    tab5 = lv_tabview_add_tab(tabview, "帮助");

    lv_obj_set_style_text_font(tabview, &Chinese_30, LV_STATE_DEFAULT);


    //设置选项卡的背景颜色
    lv_obj_set_style_bg_color(tabview, lv_color_hex(0x181818), LV_PART_MAIN | LV_STATE_DEFAULT);

    //设置选项卡按钮的背景色
    lv_obj_t* tab_btns = lv_tabview_get_tab_btns(tabview);
    lv_obj_set_style_bg_color(tab_btns, lv_color_hex(0xC1C1C0), LV_PART_ITEMS);
    lv_obj_set_style_bg_color(tab_btns, lv_color_hex(0xC09553), LV_PART_ITEMS | LV_STATE_CHECKED);
    lv_obj_set_style_bg_opa(tab_btns, 255, LV_PART_ITEMS | LV_STATE_DEFAULT);
    //lv_obj_set_style_text_color(tab_btns, lv_color_hex(0x99DCAA), 0); //设置选项卡按钮的字体颜色



}

static void create_clock()
{
    
}

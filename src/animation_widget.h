#pragma once

#include <lvgl.h>
#include <zephyr/kernel.h>

struct animation_widget {
    sys_snode_t node;
    lv_obj_t *obj;
    lv_obj_t *anim_img;
};

int animation_widget_init(struct animation_widget *widget, lv_obj_t *parent);

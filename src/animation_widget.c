#include "animation_widget.h"
#include "images/frames.h"

#include <zephyr/logging/log.h>
LOG_MODULE_DECLARE(zmk, CONFIG_ZMK_LOG_LEVEL);

int animation_widget_init(struct animation_widget *widget, lv_obj_t *parent) {
    widget->obj = lv_obj_create(parent);
    lv_obj_set_size(widget->obj, LV_PCT(100), LV_PCT(100));
    lv_obj_set_style_pad_all(widget->obj, 0, LV_PART_MAIN);
    lv_obj_set_style_border_width(widget->obj, 0, LV_PART_MAIN);
    lv_obj_set_style_bg_opa(widget->obj, LV_OPA_TRANSP, LV_PART_MAIN);

    widget->anim_img = lv_animimg_create(widget->obj);
    lv_obj_center(widget->anim_img);

    lv_animimg_set_src(widget->anim_img,
                       (const void **)animation_frames,
                       ANIMATION_FRAME_COUNT);
    lv_animimg_set_duration(widget->anim_img, ANIMATION_DURATION_MS);
    lv_animimg_set_repeat_count(widget->anim_img, LV_ANIM_REPEAT_INFINITE);
    lv_animimg_start(widget->anim_img);

    return 0;
}

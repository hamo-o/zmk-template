#include "animation_widget.h"
#include "images/frames.h"

#include <zephyr/logging/log.h>
LOG_MODULE_DECLARE(zmk, CONFIG_ZMK_LOG_LEVEL);

static void animation_timer_cb(lv_timer_t *timer) {
    struct animation_widget *widget = timer->user_data;

    widget->current_frame = (widget->current_frame + 1) % ANIMATION_FRAME_COUNT;
    lv_img_set_src(widget->img, animation_frames[widget->current_frame]);
}

int animation_widget_init(struct animation_widget *widget, lv_obj_t *parent) {
    widget->obj = lv_obj_create(parent);
    lv_obj_set_size(widget->obj, LV_PCT(100), LV_PCT(100));
    lv_obj_set_style_pad_all(widget->obj, 0, LV_PART_MAIN);
    lv_obj_set_style_border_width(widget->obj, 0, LV_PART_MAIN);
    lv_obj_set_style_bg_opa(widget->obj, LV_OPA_TRANSP, LV_PART_MAIN);

    widget->current_frame = 0;
    widget->img = lv_img_create(widget->obj);
    lv_obj_center(widget->img);
    lv_img_set_src(widget->img, animation_frames[0]);

    widget->timer = lv_timer_create(animation_timer_cb,
                                     ANIMATION_DURATION_MS / ANIMATION_FRAME_COUNT,
                                     widget);

    return 0;
}

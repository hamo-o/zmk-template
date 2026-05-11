#pragma once
#include <lvgl.h>

extern const lv_img_dsc_t frame_0;
extern const lv_img_dsc_t frame_1;
extern const lv_img_dsc_t frame_2;
extern const lv_img_dsc_t frame_3;
extern const lv_img_dsc_t frame_4;
extern const lv_img_dsc_t frame_5;
extern const lv_img_dsc_t frame_6;
extern const lv_img_dsc_t frame_7;

#define ANIMATION_FRAME_COUNT 8
#define ANIMATION_DURATION_MS 1720

static const lv_img_dsc_t *animation_frames[ANIMATION_FRAME_COUNT] = {
    &frame_0,
    &frame_1,
    &frame_2,
    &frame_3,
    &frame_4,
    &frame_5,
    &frame_6,
    &frame_7,
};

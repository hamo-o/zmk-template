if(CONFIG_ZMK_DISPLAY)
    target_sources(app PRIVATE
        custom_status_screen.c
        animation_widget.c
        images/frame_0.c
        images/frame_1.c
        images/frame_2.c
        images/frame_3.c
        images/frame_4.c
        images/frame_5.c
        images/frame_6.c
        images/frame_7.c
    )

    target_include_directories(app PRIVATE ${CMAKE_CURRENT_SOURCE_DIR})
endif()

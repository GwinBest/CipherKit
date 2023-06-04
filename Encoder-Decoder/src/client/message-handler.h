#pragma once

#include"gui/window-controls.h"
#include"gui/main-window.h"
#include"../bool.h"
#include"../chipers/morse/morse.h"
#include"../resource/resource.h"
#include"../chipers/gronsfeld/gronsfeld.h"
#include"../chipers/caesar/caesar.h"
#include"../language/language.h"
#include"../chipers/atbash/atbash.h"
#include"../chipers/railfence/railfence.h"



#define BUTTON_WIDTH_RATE                             3.9
#define BUTTON_MIN_WIDTH                              70
#define BUTTON_HEIGHT_RATE                            21.6
#define BUTTON_MIN_HEIGHT                             20
#define TEXT_BOX_WIDTH_RATE                           2.18
#define TEXT_BOX_HEIGHT_RATE                          1.6
#define TEXT_BOX_X_POSITION_RATE                      117.8
#define TEXT_BOX_Y_POSITION_RATE				      4.62
#define STATIC_BOX_X_POSITION_RATE                    1.96
#define COMBO_BOX_WIDTH_RATE                          7.85
#define COMBO_BOX_HEIGHT_RATE                         4.31
#define COMBO_BOX_MODE_SELECT_X_POSITION_RATE         1.57
#define COMBO_BOX_CIPHER_SELECT_X_POSITION_RATE       1.24
#define COMBO_BOX_POSITION_Y_RATE                     12.94
#define CHECK_BOX_WIDTH_RATE                          7.13
#define CHECK_BOX_HEIGHT_RATE                         32.35
#define CHECK_BOX_POSITION_X_RATE                     1.24
#define CHECK_BOX_POSITION_Y_RATE                     7.18
#define TEXT_BOX_FOR_KEY_MAX_HEIGHT                   30
#define TEXT_BOX_FOR_KEY_WIDTH_RATE                   5.55
#define TEXT_BOX_FOR_KEY_HEIGHT_RATE                  21.56
#define TEXT_BOX_FOR_KEY_X_POSITION_RATE              29.45
#define TEXT_BOX_FOR_KEY_Y_POSITION_RATE              12.94


LRESULT CALLBACK fnMessageProcessor(HWND hWnd, UINT	 iMsg, WPARAM wParam, LPARAM lParam);




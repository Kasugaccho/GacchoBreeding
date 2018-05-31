#pragma once
#define DX_NON_USING_NAMESPACE_DXLIB
#include "DxLib.h"

#define AS_USING_GAME_PAD_MAX
constexpr size_t ASLIB_GAME_PAD_MAX = 16;
#include "AsLib.hpp"

using MC = AsLib::MainControl;

#include <ctime>

//シーン系
#include "Option_Scene.hpp"
//画像系
#include "Option_Texture.hpp"
//UI系
#include "Option_UI.hpp"
//基本データ系
#include "Option_Data.hpp"
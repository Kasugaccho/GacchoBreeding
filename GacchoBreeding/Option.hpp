#pragma once
#define DX_NON_USING_NAMESPACE_DXLIB
#include "DxLib.h"

#define AS_USING_GAME_PAD_MAX
constexpr size_t ASLIB_GAME_PAD_MAX = 16;
#include "AsLib.hpp"

using MC = AsLib::MainControl;

#include "Option_Scene.hpp"
#include "Option_Texture.hpp"
#include "Option_UI.hpp"
#include "Option_Data.hpp"
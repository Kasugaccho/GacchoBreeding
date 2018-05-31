#pragma once
#define DX_NON_USING_NAMESPACE_DXLIB
#include "DxLib.h"

#define AS_USING_GAME_PAD_MAX
constexpr size_t ASLIB_GAME_PAD_MAX = 16;
#include "AsLib.hpp"

using MC = AsLib::MainControl;

#include <ctime>

//�V�[���n
#include "Option_Scene.hpp"
//�摜�n
#include "Option_Texture.hpp"
//UI�n
#include "Option_UI.hpp"
//��{�f�[�^�n
#include "Option_Data.hpp"
#pragma once

#include "../headers/backend/LotusGL.h"
#include "../headers/core/lotus_types.h"
#include "../headers/core/LotusCamera.h"
#include "../headers/core/LotusInput.h"
#include "../headers/core/LotusProc.h"
#include "../headers/core/LotusECS.h"
#include "version.h"

typedef struct Lotus {
    char version[512];
    LotusClock clock;
    GLFWwindow* window;
    LotusCamera* camera;
    LotusRenderer renderer;
} Lotus;
static Lotus LOTUS;

LOTUS_API char* lotusGetVersion(void);

// External Engine API
LOTUS_API void lotusInit(void);
LOTUS_API void lotusExit(void);
LOTUS_API void lotusCleanup(void);
LOTUS_API void lotusCamMovUp(void);
LOTUS_API void lotusCamMovIn(void);
LOTUS_API void lotusCamMovOut(void);
LOTUS_API void lotusCamMovLeft(void);
LOTUS_API void lotusCamMovDown(void);
LOTUS_API void lotusCamMovRight(void);
LOTUS_API float lotusGetDeltaTime(void);
LOTUS_API void lotusInitCamera(unsigned int mode);

// External Event/Input API
LOTUS_API bool lotusRunning(void);
LOTUS_API void lotusPollEvents(void);
LOTUS_API unsigned char lotusIsKeyPressed(LotusKeyboardKey key);
LOTUS_API unsigned char lotusIsKeyTriggered(LotusKeyboardKey key);
LOTUS_API unsigned char lotusIsKeyReleased(LotusKeyboardKey key);
LOTUS_API unsigned char lotusIsMouseButtonPressed(LotusMouseButton button);
LOTUS_API unsigned char lotusIsMouseButtonTriggered(LotusMouseButton button);
LOTUS_API unsigned char lotusIsMouseButtonReleased(LotusMouseButton button);

// External Rendering API
LOTUS_API void lotusPreProcess(void);
LOTUS_API void lotusPosProcess(void);
LOTUS_API void lotusProcess(void);

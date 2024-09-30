#pragma once

#include "atds.h"
#include "atmath.h"
#include "attypes.h"
#include "athelpers.h"
#include "atprocess.h"

#include "resource/atwindow.h"

#include "resource/atmesh.h"
#include "resource/atshader.h"
#include "resource/attexture.h"

#ifdef _ATWIN_WINDOWS_
#endif

#ifdef _ATWIN_EMSCRIPTEN_
#endif

#include "processes/atevent.h"
#include "processes/atrender.h"

#include "../backend/headers/atGLAPI.h"
#ifdef _ATWIN_GL_
    #include "../backend/headers/atGLAPI.h"
#endif

typedef struct Anntwinetta {
    struct state {
        int init;
    } state;
    
    struct internal {
        int errors;
        
        ATprocess* event_proc;
        ATeventData event_data;
        
        ATprocess* render_proc;
        ATrenderData render_data;
        
        // Clock for managing frame timing and FPS
        struct clock {
            float FPS;           // Current frames per second
            float TPF;           // Time per frame in milliseconds
            int maxFPS;          // Target maximum frames per second
            int lastTime;        // Last update time in milliseconds
            int currentTime;     // Current time in milliseconds
            float deltaTime;     // Time since last frame in seconds
            float frameCount;    // Frames since last update
        } clock;

    } internal;

    struct resource {
        int total;
        ATwindow* window;
        ATGLcontext* context;

        ATmeshData mesh_data;
        ATshaderData shader_data;

        struct texture_data {
            int count;
            char** src;
            char** title;
            int* n_channels;
            int** dimensions;
        } texture_data;
        
        struct entity_data {
            int count;
            int* state;
            int* components;
        } entity_data;
    } resource;

    struct component_data {
        struct model_data {
            int count;
        } model_data;

        struct material_data {
            int count;
        } material_data;

        struct transform_data {
            int count;
        } transform_data;

        struct physics2D_data {
            int count;
        } physics2D_data;

        struct physics3D_data {
            int count;
        } physics3D_data;

    } component_data;
} Anntwinetta;


// initialize the internal engine structure
atErrorType _atInitEngine(void);
atErrorType _atExitEngine(void);

// internal getters/setters
Anntwinetta* _atGetEngine(void);
ATeventData* _atGetEventData(void);
ATrenderData* _atGetRenderData(void);

ATmeshData* _atGetMeshData(void);
ATshaderData* _atGetShaderData(void);

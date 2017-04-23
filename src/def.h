#pragma once

typedef enum {
    CROP_OP,
    ZOOM_OP,
    ROTATE_OP,
    SHOWEXIF_OP,
    INVALID_OP
} ImageOperationType;

typedef struct
{
    ImageOperationType opType;
    const char *    srcImagePath;
    uint32_t        srcImageSize;
    uint32_t        destImageWidth;
    uint32_t        destImageHeight;
} ImageOperation;

// log definition
#define error_log(...) printf( __VA_ARGS__)  
#define debug_log(...) printf( __VA_ARGS__) 
#define print_info(...) printf( __VA_ARGS__) 
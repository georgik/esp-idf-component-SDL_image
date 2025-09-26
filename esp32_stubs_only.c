/*
  ESP32 SDL_image Stubs - Minimal Edition
  
  This provides only the stub functions needed by the original SDL_image IMG.c
  for formats we don't support on ESP32. This allows us to use the full
  upstream SDL_image code without modification.
  
  Supported formats (via STB): BMP, PNG, JPEG, GIF
  Stubbed formats: TGA, AVIF, JXL, LBM, PCX, PNM, SVG, TIF, XCF, XPM, XV, WEBP, QOI, CUR, ICO
*/

#include <SDL3_image/SDL_image.h>

/* Forward declaration for STB loader */
extern SDL_Surface *IMG_LoadSTB_IO(SDL_IOStream *src);

/* Detection functions for unsupported formats */
bool IMG_isTGA(SDL_IOStream *src) { (void)src; return false; }
bool IMG_isAVIF(SDL_IOStream *src) { (void)src; return false; }
bool IMG_isJXL(SDL_IOStream *src) { (void)src; return false; }
bool IMG_isLBM(SDL_IOStream *src) { (void)src; return false; }
bool IMG_isPCX(SDL_IOStream *src) { (void)src; return false; }
bool IMG_isPNM(SDL_IOStream *src) { (void)src; return false; }
bool IMG_isSVG(SDL_IOStream *src) { (void)src; return false; }
bool IMG_isTIF(SDL_IOStream *src) { (void)src; return false; }
bool IMG_isXCF(SDL_IOStream *src) { (void)src; return false; }
bool IMG_isXPM(SDL_IOStream *src) { (void)src; return false; }
bool IMG_isXV(SDL_IOStream *src) { (void)src; return false; }
bool IMG_isWEBP(SDL_IOStream *src) { (void)src; return false; }
bool IMG_isQOI(SDL_IOStream *src) { (void)src; return false; }

/* Loader functions for unsupported formats */
SDL_Surface *IMG_LoadTGA_IO(SDL_IOStream *src) { 
    (void)src; 
    SDL_SetError("TGA format not supported on ESP32"); 
    return NULL; 
}

SDL_Surface *IMG_LoadAVIF_IO(SDL_IOStream *src) { 
    (void)src; 
    SDL_SetError("AVIF format not supported on ESP32"); 
    return NULL; 
}

SDL_Surface *IMG_LoadJXL_IO(SDL_IOStream *src) { 
    (void)src; 
    SDL_SetError("JXL format not supported on ESP32"); 
    return NULL; 
}

SDL_Surface *IMG_LoadLBM_IO(SDL_IOStream *src) { 
    (void)src; 
    SDL_SetError("LBM format not supported on ESP32"); 
    return NULL; 
}

SDL_Surface *IMG_LoadPCX_IO(SDL_IOStream *src) { 
    (void)src; 
    SDL_SetError("PCX format not supported on ESP32"); 
    return NULL; 
}

SDL_Surface *IMG_LoadPNM_IO(SDL_IOStream *src) { 
    (void)src; 
    SDL_SetError("PNM format not supported on ESP32"); 
    return NULL; 
}

SDL_Surface *IMG_LoadSVG_IO(SDL_IOStream *src) { 
    (void)src; 
    SDL_SetError("SVG format not supported on ESP32"); 
    return NULL; 
}

SDL_Surface *IMG_LoadTIF_IO(SDL_IOStream *src) { 
    (void)src; 
    SDL_SetError("TIF format not supported on ESP32"); 
    return NULL; 
}

SDL_Surface *IMG_LoadXCF_IO(SDL_IOStream *src) { 
    (void)src; 
    SDL_SetError("XCF format not supported on ESP32"); 
    return NULL; 
}

SDL_Surface *IMG_LoadXPM_IO(SDL_IOStream *src) { 
    (void)src; 
    SDL_SetError("XPM format not supported on ESP32"); 
    return NULL; 
}

SDL_Surface *IMG_LoadXV_IO(SDL_IOStream *src) { 
    (void)src; 
    SDL_SetError("XV format not supported on ESP32"); 
    return NULL; 
}

SDL_Surface *IMG_LoadWEBP_IO(SDL_IOStream *src) { 
    (void)src; 
    SDL_SetError("WEBP format not supported on ESP32"); 
    return NULL; 
}

SDL_Surface *IMG_LoadQOI_IO(SDL_IOStream *src) { 
    (void)src; 
    SDL_SetError("QOI format not supported on ESP32"); 
    return NULL; 
}


/* Animation support stubs (not supported on ESP32) */

IMG_Animation *IMG_LoadWEBPAnimation_IO(SDL_IOStream *src) { 
    (void)src; 
    SDL_SetError("WEBP animation not supported on ESP32"); 
    return NULL; 
}

/* 
 * Supported formats (BMP, PNG, JPEG, GIF) are handled by their respective
 * format files (IMG_png.c, IMG_jpg.c, etc.) which route to IMG_LoadSTB_IO
 * when USE_STBIMAGE is defined.
 */

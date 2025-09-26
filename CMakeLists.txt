idf_component_register(
    SRCS
        "SDL_image/src/IMG.c"
        "SDL_image/src/IMG_stb.c"
        "SDL_image/src/IMG_png.c"
        "SDL_image/src/IMG_jpg.c"
        "SDL_image/src/IMG_bmp.c"
        "SDL_image/src/IMG_gif.c"
        "esp32_stubs_only.c"
    INCLUDE_DIRS 
        "SDL_image/include"
    REQUIRES
        georgik__sdl
)

# Enable support for STB image backend with ESP32-appropriate formats
# Override the restrictive STB configuration to enable BMP and GIF
target_compile_definitions(${COMPONENT_LIB} PRIVATE
    USE_STBIMAGE
    LOAD_BMP
    LOAD_PNG
    LOAD_JPG
    LOAD_GIF
    # Override restrictive STB defines
    STBI_ONLY_PNG=0
    STBI_ONLY_JPEG=0
    STBI_NO_GIF=0
    # Keep these disabled for ESP32 resource constraints
    STBI_NO_HDR=1
    STBI_NO_LINEAR=1
    STBI_NO_STDIO=1
    STBI_NO_THREAD_LOCALS=1
)

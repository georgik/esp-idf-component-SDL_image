# SDL_image for ESP-IDF

A comprehensive image loading library for ESP32 microcontrollers, providing SDL_image 3.2.4 functionality optimized for embedded systems.

## Overview

SDL_image is an image loading library that extends SDL3 with support for various image formats. This ESP-IDF component wrapper provides essential image loading capabilities for ESP32-based projects, including games, UI applications, and multimedia projects.

## Supported Image Formats

This component includes support for the most commonly used image formats in embedded applications:

- **BMP** - Windows Bitmap format (uncompressed)
- **PNG** - Portable Network Graphics (with transparency support)
- **JPEG/JPG** - JPEG compressed images
- **GIF** - Graphics Interchange Format (including animations)
- **STB** - STB-based fallback for various formats

## Features

✅ **SDL3 Compatible** - Works seamlessly with SDL3 for ESP32  
✅ **Memory Optimized** - Designed for microcontroller memory constraints  
✅ **Transparency Support** - Full alpha channel support for PNG images  
✅ **Hardware Acceleration** - Leverages ESP32 capabilities where possible  
✅ **Easy Integration** - Simple API compatible with desktop SDL_image  

## Installation

Add this component to your ESP-IDF project:

```bash
idf.py add-dependency "georgik/sdl_image^3.2.4"
```

Or add to your `idf_component.yml`:

```yaml
dependencies:
  georgik/sdl_image: "^3.2.4"
  georgik/sdl: "^3.3.0"
```

## Requirements

- **ESP-IDF**: 5.5.0 or higher
- **SDL3**: 3.3.0 or higher (georgik/sdl component)
- **ESP32 variant**: ESP32, ESP32-S3, ESP32-C3, ESP32-S2 or newer
- **Memory**: Minimum 2MB PSRAM recommended for larger images

## Quick Start

```c
#include "SDL3/SDL.h"
#include "SDL3_image/SDL_image.h"

void app_main(void) {
    // Initialize SDL
    SDL_Init(SDL_INIT_VIDEO);
    
    // Initialize SDL_image
    int img_flags = IMG_INIT_PNG | IMG_INIT_JPG;
    if (!(IMG_Init(img_flags) & img_flags)) {
        printf("SDL_image could not initialize! Error: %s\n", IMG_GetError());
        return;
    }
    
    // Create renderer (assuming you have a window/renderer setup)
    SDL_Renderer *renderer = /* your renderer */;
    
    // Load image from filesystem
    SDL_Surface *image = IMG_Load("/assets/sprite.png");
    if (!image) {
        printf("Unable to load image: %s\n", IMG_GetError());
        return;
    }
    
    // Create texture from surface
    SDL_Texture *texture = SDL_CreateTextureFromSurface(renderer, image);
    SDL_DestroySurface(image);
    
    // Render texture
    SDL_RenderTexture(renderer, texture, NULL, NULL);
    SDL_RenderPresent(renderer);
    
    // Cleanup
    SDL_DestroyTexture(texture);
    IMG_Quit();
    SDL_Quit();
}
```

## API Usage

### Loading Images

```c
// Load from file
SDL_Surface *surface = IMG_Load("/assets/image.png");

// Load from memory
SDL_Surface *surface = IMG_Load_RW(rw_ops, 1);

// Load directly as texture
SDL_Texture *texture = IMG_LoadTexture(renderer, "/assets/image.png");
```

### Format Detection

```c
// Check if file is specific format
if (IMG_isPNG(rw_ops)) {
    printf("This is a PNG file\n");
}
```

### Error Handling

```c
if (!surface) {
    printf("Image loading failed: %s\n", IMG_GetError());
}
```

## Memory Considerations

### PSRAM Usage

For loading larger images, enable PSRAM in your ESP32 configuration:

```
CONFIG_SPIRAM_SUPPORT=y
CONFIG_SPIRAM_USE_MALLOC=y
```

### Image Size Recommendations

- **Without PSRAM**: Images up to 320x240 pixels
- **With PSRAM**: Images up to 640x480 pixels or larger
- **Optimal**: Power-of-2 dimensions (128x128, 256x256, etc.)

## Integration with ESP32 Projects

### Game Development

```c
// Load sprite sheets
SDL_Texture *spriteSheet = IMG_LoadTexture(renderer, "/assets/sprites.png");

// Load UI elements
SDL_Texture *button = IMG_LoadTexture(renderer, "/assets/button.png");
```

### File System Setup

Mount your assets partition:

```c
// Mount littlefs or spiffs partition
esp_vfs_littlefs_conf_t conf = {
    .base_path = "/assets",
    .partition_label = "assets",
    .format_if_mount_failed = false,
};
esp_vfs_littlefs_register(&conf);
```

## Supported ESP32 Boards

- ESP32-S3-BOX-3
- ESP32-S3 DevKit
- ESP32 DevKit
- M5Stack series
- Custom ESP32 boards with displays

## Performance Tips

1. **Use appropriate formats**: PNG for sprites with transparency, JPEG for photos
2. **Pre-scale images**: Resize images to target display size
3. **Cache textures**: Load once, use multiple times
4. **Use PSRAM**: Enable for better performance with larger images

## Troubleshooting

### Common Issues

**"IMG_Init failed"**
- Ensure SDL is initialized first
- Check that required image formats are supported

**"Out of memory"**
- Enable PSRAM
- Reduce image sizes
- Check available heap memory

**"File not found"**
- Verify file system mounting
- Check file path and case sensitivity

## Links

- [SDL_image Documentation](https://wiki.libsdl.org/SDL3_image)
- [SDL3 for ESP32](https://github.com/georgik/esp-idf-component-SDL)
- [ESP32 SDL Examples](https://github.com/georgik/esp32-sdl-examples)
- [Component Homepage](https://github.com/georgik/esp-idf-component-SDL_image)

## License

This component is released under the Zlib license, same as SDL_image.

---

*Part of the SDL3 ecosystem for ESP32 microcontrollers.*


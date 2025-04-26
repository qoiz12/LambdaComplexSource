#if defined(__EMSCRIPTEN__)
// Browsers have very little memory limits!
#define BSP_USE_LESS_MEMORY 1
#endif

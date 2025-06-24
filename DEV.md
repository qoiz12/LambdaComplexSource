# Developer Guide
## Getting started
This guide focuses on working with the **Emscripten** port, but additional non-Emscripten related things will be mentioned.

Firstly you will need the following packages:
```
base-devel \
gcc-multilib \
dpkg \
sdl2 \
clang \
python3 \
python
```
If you plan on building or compiling for the Web or Emscripten platform, make sure to install the [`emsdk`](https://github.com/emscripten-core/emsdk) or compile [Our modified Emscripten](https://github.com/OrbitaStudios/emscripten/) which has support for Waf

## Architecture
### Supported compilers
Lambda Complex: Source supports a numerous amount of compilers, but the default is GNU C Compiler, better known as GCC.

| Compiler | Compatibility | Supported |
|----------|---------------|-----------|
| gcc      | Android, Linux| Yes |
| clang    | Android, Linux, WASM| Yes, but WASM is not fully supported, unless using Emscripten |
| icc      | Linux, Windows | Yes |
| emcc     | WASM, Web platform | Yes |

### Supported architectures
| ARCH | Supported |
|------|-----------|
| x64  | Yes |
| x86  | yes |
| WASM | yes |

## Build
Firstly, clone this repository with the following command:
```bash
git clone https://github.com/OrbitaStudios/LambdaComplexSource.git
```
Then, enter the directory
```bash
cd LambdaComplexSource/src/
```
Then run the command (if you plan on compiling on your PC without Emscripten)
```bash
./waf configure -T BUILDMODE
```
If you want Emscripten, run:
```bash
CC=emcc CXX=em++ ./waf configure -T BUILDMODE -8
```
The Emscripten process is simplified with our modified Emscripten, with the emwaf command.

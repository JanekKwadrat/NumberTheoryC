#ifndef RUSTLIKE
#define RUSTLIKE

typedef unsigned long long u64;
typedef signed long long   i64;
typedef unsigned int       u32;
typedef signed int         i32;
typedef unsigned short     u16;
typedef signed short       i16;
typedef unsigned char       u8;
typedef signed char         i8;

const u64 u64_max = (u64)0xffffffffffffffff;
const i64 i64_max = (i64)0x7fffffffffffffff;
const i64 i64_min = (i64)0x8000000000000000;
const u32 u32_max = (u32)0xffffffff;
const i32 i32_max = (i32)0x7fffffff;
const i32 i32_min = (i32)0x80000000;
const u16 u16_max = (u16)0xffff;
const i16 i16_max = (i16)0x7fff;
const i16 i16_min = (i16)0x8000;
const u8 u8_max = (u8)0xff;
const i8 i8_max = (i8)0x7f;
const i8 i8_min = (i8)0x80;

#ifdef __SIZEOF_INT128__
typedef unsigned __int128   u128;
typedef          __int128   i128;
//note: no min or max here
#define RUSTLIKE128
#else
#warning "cannot define 128-bit types"
#endif

typedef float              f32;
typedef double             f64;
typedef long double        f80;

#endif
#if LV_BUILD_TEST
#include "../../lvgl.h"

/*******************************************************************************
 * Size: 8 px
 * Bpp: 4
 * Opts: --bpp 4 --size 8 --font ../Montserrat-Medium.ttf -r
 *0x20-0x7F,0xB0,0x2022 --font ../FontAwesome5-Solid+Brands+Regular.woff -r
 *61441,61448,61451,61452,61452,61453,61457,61459,61461,61465,61468,61473,61478,61479,61480,61502,61512,61515,61516,61517,61521,61522,61523,61524,61543,61544,61550,61552,61553,61556,61559,61560,61561,61563,61587,61589,61636,61637,61639,61671,61674,61683,61724,61732,61787,61931,62016,62017,62018,62019,62020,62087,62099,62212,62189,62810,63426,63650
 *--no-compress --no-prefilter --force-fast-kern-format --format lvgl -o
 *..\generated_fonts/font_2.c
 ******************************************************************************/

#ifndef FONT_2
#define FONT_2 1
#endif

#if FONT_2

/*-----------------
 *    BITMAPS
 *----------------*/

/*Store the image of the glyphs*/
static LV_ATTRIBUTE_LARGE_CONST const uint8_t gylph_bitmap[] = {
    /* U+20 " " */

    /* U+21 "!" */
    0x58, 0x57, 0x46, 0x23, 0x46,

    /* U+22 "\"" */
    0x73, 0x97, 0x29, 0x0, 0x0,

    /* U+23 "#" */
    0x4, 0x52, 0x60, 0x4b, 0x9b, 0xa3, 0x8, 0x7, 0x20, 0x6c, 0x8c, 0x81, 0x9,
    0x9, 0x0,

    /* U+24 "$" */
    0x0, 0x80, 0x2, 0xbd, 0xa2, 0x76, 0x80, 0x0, 0x8d, 0x81, 0x0, 0x84, 0x95,
    0xad, 0xb3, 0x0, 0x80, 0x0,

    /* U+25 "%" */
    0x58, 0x70, 0x63, 0x8, 0x8, 0x36, 0x0, 0x27, 0x58, 0x67, 0x10, 0x8, 0x27,
    0x26, 0x6, 0x20, 0x88, 0x20,

    /* U+26 "&" */
    0x9, 0x99, 0x0, 0xb, 0x3a, 0x0, 0x19, 0xc2, 0x20, 0x83, 0x1a, 0xa0, 0x3a,
    0x99, 0x92, 0x0, 0x0, 0x0,

    /* U+27 "'" */
    0x72, 0x72, 0x0,

    /* U+28 "(" */
    0x8, 0x20, 0xb0, 0x1a, 0x3, 0x80, 0x1a, 0x0, 0xb0, 0x8, 0x20,

    /* U+29 ")" */
    0x73, 0x19, 0xb, 0xc, 0xb, 0x19, 0x73,

    /* U+2A "*" */
    0x48, 0x40, 0x6e, 0x80, 0x15, 0x10,

    /* U+2B "+" */
    0x0, 0x20, 0x0, 0xa, 0x0, 0x49, 0xd9, 0x10, 0xa, 0x0,

    /* U+2C "," */
    0x0, 0x75, 0x71,

    /* U+2D "-" */
    0x5a, 0x60,

    /* U+2E "." */
    0x0, 0x74,

    /* U+2F "/" */
    0x0, 0xa, 0x0, 0x2, 0x80, 0x0, 0x82, 0x0, 0xa, 0x0, 0x4, 0x60, 0x0, 0x91,
    0x0, 0x19, 0x0, 0x0,

    /* U+30 "0" */
    0xa, 0xbb, 0x26, 0x60, 0x1b, 0x93, 0x0, 0xc6, 0x60, 0x1b, 0xa, 0xbb, 0x20,

    /* U+31 "1" */
    0x9e, 0x20, 0xa2, 0xa, 0x20, 0xa2, 0xa, 0x20,

    /* U+32 "2" */
    0x6a, 0xb9, 0x0, 0x0, 0xc0, 0x0, 0x58, 0x0, 0x87, 0x0, 0x9e, 0xaa, 0x30,

    /* U+33 "3" */
    0x7a, 0xbe, 0x0, 0xa, 0x20, 0x4, 0xa9, 0x0, 0x0, 0xa2, 0x8a, 0xa9, 0x0,

    /* U+34 "4" */
    0x0, 0x49, 0x0, 0x3, 0xa0, 0x0, 0x1b, 0x8, 0x20, 0x8b, 0xad, 0xb2, 0x0, 0x9,
    0x30,

    /* U+35 "5" */
    0x3d, 0xaa, 0x5, 0x60, 0x0, 0x5b, 0xa8, 0x0, 0x0, 0x93, 0x7a, 0xaa, 0x0,

    /* U+36 "6" */
    0x9, 0xaa, 0x36, 0x70, 0x0, 0x98, 0x9a, 0x26, 0x80, 0x2a, 0x9, 0x9a, 0x40,

    /* U+37 "7" */
    0xca, 0xad, 0x67, 0x0, 0xc0, 0x0, 0x67, 0x0, 0xc, 0x0, 0x6, 0x70, 0x0,

    /* U+38 "8" */
    0x1a, 0xab, 0x25, 0x60, 0x48, 0x1d, 0xad, 0x38, 0x40, 0x1b, 0x3a, 0x9a,
    0x40,

    /* U+39 "9" */
    0x4a, 0x99, 0xb, 0x10, 0x95, 0x3a, 0x99, 0x80, 0x0, 0x95, 0x3a, 0xb8, 0x0,

    /* U+3A ":" */
    0x74, 0x0, 0x0, 0x74,

    /* U+3B ";" */
    0x74, 0x0, 0x0, 0x75, 0x62, 0x0,

    /* U+3C "<" */
    0x0, 0x1, 0x0, 0x49, 0x80, 0x5c, 0x30, 0x0, 0x16, 0x91, 0x0, 0x0, 0x0,

    /* U+3D "=" */
    0x49, 0x99, 0x10, 0x0, 0x0, 0x49, 0x99, 0x10,

    /* U+3E ">" */
    0x10, 0x0, 0x3, 0x98, 0x20, 0x0, 0x6d, 0x14, 0x94, 0x0, 0x0, 0x0, 0x0,

    /* U+3F "?" */
    0x6a, 0xb9, 0x0, 0x0, 0xc0, 0x0, 0xa4, 0x0, 0x3, 0x0, 0x2, 0x80, 0x0,

    /* U+40 "@" */
    0x3, 0x87, 0x78, 0x50, 0x28, 0x4a, 0x9c, 0x75, 0x80, 0xb0, 0xa, 0x28, 0x80,
    0xb0, 0xa, 0x28, 0x28, 0x49, 0x99, 0xa6, 0x3, 0x88, 0x75, 0x0,

    /* U+41 "A" */
    0x0, 0xb, 0x90, 0x0, 0x3, 0x8a, 0x10, 0x0, 0xb1, 0x39, 0x0, 0x4d, 0x99,
    0xd1, 0xb, 0x10, 0x3, 0x90,

    /* U+42 "B" */
    0x2d, 0x99, 0xb1, 0x2a, 0x0, 0x84, 0x2d, 0x9a, 0xd1, 0x2a, 0x0, 0x39, 0x2d,
    0x99, 0xb4,

    /* U+43 "C" */
    0x7, 0xba, 0xa2, 0x59, 0x0, 0x0, 0x93, 0x0, 0x0, 0x59, 0x0, 0x0, 0x7, 0xba,
    0xa2,

    /* U+44 "D" */
    0x2e, 0xab, 0xb3, 0x2, 0xa0, 0x1, 0xc0, 0x2a, 0x0, 0x9, 0x22, 0xa0, 0x1,
    0xc0, 0x2e, 0xab, 0xb3, 0x0,

    /* U+45 "E" */
    0x2e, 0xaa, 0x82, 0xa0, 0x0, 0x2d, 0xaa, 0x42, 0xa0, 0x0, 0x2e, 0xaa, 0x90,

    /* U+46 "F" */
    0x2e, 0xaa, 0x82, 0xa0, 0x0, 0x2e, 0xaa, 0x42, 0xa0, 0x0, 0x2a, 0x0, 0x0,

    /* U+47 "G" */
    0x7, 0xba, 0xa2, 0x59, 0x0, 0x0, 0x93, 0x0, 0x23, 0x59, 0x0, 0x47, 0x7,
    0xba, 0xa3,

    /* U+48 "H" */
    0x2a, 0x0, 0x2a, 0x2a, 0x0, 0x2a, 0x2e, 0xaa, 0xba, 0x2a, 0x0, 0x2a, 0x2a,
    0x0, 0x2a,

    /* U+49 "I" */
    0x2a, 0x2a, 0x2a, 0x2a, 0x2a,

    /* U+4A "J" */
    0x5, 0xad, 0x50, 0x0, 0x75, 0x0, 0x7, 0x50, 0x0, 0x84, 0x9, 0xab, 0x0,

    /* U+4B "K" */
    0x2a, 0x1, 0xa2, 0x2a, 0x1b, 0x20, 0x2c, 0xc7, 0x0, 0x2d, 0x19, 0x50, 0x2a,
    0x0, 0xa4,

    /* U+4C "L" */
    0x2a, 0x0, 0x2, 0xa0, 0x0, 0x2a, 0x0, 0x2, 0xa0, 0x0, 0x2e, 0xaa, 0x70,

    /* U+4D "M" */
    0x2c, 0x0, 0x3, 0xc2, 0xd7, 0x0, 0xbc, 0x29, 0x92, 0x84, 0xc2, 0x91, 0xb9,
    0xc, 0x29, 0x3, 0x0, 0xc0,

    /* U+4E "N" */
    0x2d, 0x10, 0x2a, 0x2c, 0xb0, 0x2a, 0x2a, 0x4b, 0x2a, 0x2a, 0x5, 0xca, 0x2a,
    0x0, 0x7a,

    /* U+4F "O" */
    0x7, 0xbb, 0xb3, 0x5, 0x90, 0x1, 0xc1, 0x93, 0x0, 0x8, 0x45, 0x90, 0x1,
    0xc1, 0x7, 0xbb, 0xb3, 0x0,

    /* U+50 "P" */
    0x2e, 0xaa, 0x90, 0x2a, 0x0, 0x84, 0x2a, 0x0, 0xa3, 0x2e, 0xaa, 0x60, 0x2a,
    0x0, 0x0,

    /* U+51 "Q" */
    0x7, 0xbb, 0xb3, 0x5, 0x90, 0x1, 0xc1, 0x93, 0x0, 0x8, 0x45, 0x90, 0x0,
    0xc1, 0x7, 0xbb, 0xb3, 0x0, 0x0, 0x39, 0x93,

    /* U+52 "R" */
    0x2e, 0xaa, 0x90, 0x2a, 0x0, 0x84, 0x2a, 0x0, 0xa3, 0x2d, 0xac, 0x80, 0x2a,
    0x1, 0xa1,

    /* U+53 "S" */
    0x2a, 0xaa, 0x27, 0x60, 0x0, 0x8, 0x98, 0x10, 0x0, 0x49, 0x5a, 0xaa, 0x30,

    /* U+54 "T" */
    0xaa, 0xea, 0x60, 0xc, 0x0, 0x0, 0xc0, 0x0, 0xc, 0x0, 0x0, 0xc0, 0x0,

    /* U+55 "U" */
    0x39, 0x0, 0x48, 0x39, 0x0, 0x48, 0x39, 0x0, 0x48, 0x1c, 0x0, 0x66, 0x6,
    0xba, 0xa0,

    /* U+56 "V" */
    0xb, 0x10, 0x5, 0x70, 0x49, 0x0, 0xb0, 0x0, 0xc1, 0x57, 0x0, 0x4, 0x9c, 0x0,
    0x0, 0xc, 0x70, 0x0,

    /* U+57 "W" */
    0x94, 0x0, 0xf1, 0x3, 0x93, 0xa0, 0x69, 0x70, 0x93, 0xc, 0xb, 0xb, 0xb, 0x0,
    0x79, 0x80, 0x89, 0x70, 0x1, 0xf2, 0x2, 0xf1, 0x0,

    /* U+58 "X" */
    0x58, 0x2, 0xa0, 0x8, 0x7b, 0x10, 0x0, 0xf5, 0x0, 0xa, 0x4b, 0x10, 0x76,
    0x2, 0xb0,

    /* U+59 "Y" */
    0xa, 0x20, 0xb, 0x0, 0x1b, 0x9, 0x30, 0x0, 0x5b, 0x80, 0x0, 0x0, 0xd0, 0x0,
    0x0, 0xc, 0x0, 0x0,

    /* U+5A "Z" */
    0x6a, 0xac, 0xd0, 0x0, 0x1b, 0x10, 0x0, 0xb2, 0x0, 0xb, 0x30, 0x0, 0x8d,
    0xaa, 0xa0,

    /* U+5B "[" */
    0x2d, 0x42, 0x90, 0x29, 0x2, 0x90, 0x29, 0x2, 0x90, 0x2d, 0x40,

    /* U+5C "\\" */
    0x19, 0x0, 0x0, 0xa0, 0x0, 0x5, 0x50, 0x0, 0xa, 0x0, 0x0, 0x91, 0x0, 0x3,
    0x70, 0x0, 0xa, 0x0,

    /* U+5D "]" */
    0x8c, 0xc, 0xc, 0xc, 0xc, 0xc, 0x8c,

    /* U+5E "^" */
    0x3, 0xc0, 0x0, 0x94, 0x50, 0x27, 0x9, 0x0,

    /* U+5F "_" */
    0x77, 0x77,

    /* U+60 "`" */
    0x6, 0x60,

    /* U+61 "a" */
    0x29, 0x98, 0x2, 0x98, 0xd0, 0x84, 0xc, 0x13, 0xb9, 0xd1,

    /* U+62 "b" */
    0x48, 0x0, 0x0, 0x48, 0x0, 0x0, 0x4c, 0xab, 0x50, 0x4a, 0x0, 0xc0, 0x4a,
    0x0, 0xc0, 0x4c, 0xaa, 0x50,

    /* U+63 "c" */
    0x1a, 0xaa, 0x18, 0x40, 0x0, 0x84, 0x0, 0x1, 0xaa, 0xa1,

    /* U+64 "d" */
    0x0, 0x0, 0xb0, 0x0, 0xb, 0x1a, 0xaa, 0xb9, 0x40, 0x3b, 0x94, 0x2, 0xb1,
    0xa9, 0x9b,

    /* U+65 "e" */
    0x19, 0x99, 0x19, 0x98, 0x86, 0x85, 0x1, 0x1, 0xaa, 0xb1,

    /* U+66 "f" */
    0xa, 0xa0, 0x2a, 0x0, 0x9d, 0x70, 0x29, 0x0, 0x29, 0x0, 0x29, 0x0,

    /* U+67 "g" */
    0x1a, 0x99, 0xb9, 0x40, 0x1c, 0x94, 0x2, 0xc1, 0xaa, 0xab, 0x18, 0x9a, 0x30,

    /* U+68 "h" */
    0x48, 0x0, 0x4, 0x80, 0x0, 0x4c, 0x9b, 0x44, 0x90, 0x1b, 0x48, 0x0, 0xc4,
    0x80, 0xc,

    /* U+69 "i" */
    0x37, 0x0, 0x48, 0x48, 0x48, 0x48,

    /* U+6A "j" */
    0x3, 0x70, 0x0, 0x3, 0x80, 0x38, 0x3, 0x80, 0x38, 0x6b, 0x40,

    /* U+6B "k" */
    0x48, 0x0, 0x4, 0x80, 0x0, 0x48, 0xa, 0x44, 0x9c, 0x30, 0x4d, 0x6a, 0x4,
    0x80, 0x77,

    /* U+6C "l" */
    0x48, 0x48, 0x48, 0x48, 0x48, 0x48,

    /* U+6D "m" */
    0x4c, 0x9b, 0x89, 0xb4, 0x49, 0x3, 0xb0, 0xb, 0x48, 0x2, 0xa0, 0xc, 0x48,
    0x2, 0xa0, 0xc,

    /* U+6E "n" */
    0x4c, 0x9b, 0x44, 0x90, 0x1b, 0x48, 0x0, 0xc4, 0x80, 0xc,

    /* U+6F "o" */
    0x1a, 0xaa, 0x18, 0x40, 0x3a, 0x84, 0x3, 0xa1, 0xaa, 0xa1,

    /* U+70 "p" */
    0x4c, 0xab, 0x50, 0x4a, 0x0, 0xc0, 0x4a, 0x0, 0xc0, 0x4c, 0xaa, 0x50, 0x48,
    0x0, 0x0,

    /* U+71 "q" */
    0x1a, 0xa9, 0xb9, 0x40, 0x3b, 0x94, 0x3, 0xb1, 0xaa, 0x9b, 0x0, 0x0, 0xb0,

    /* U+72 "r" */
    0x4b, 0xa0, 0x4a, 0x0, 0x48, 0x0, 0x48, 0x0,

    /* U+73 "s" */
    0x5b, 0x95, 0x87, 0x30, 0x3, 0x79, 0x7a, 0xa6,

    /* U+74 "t" */
    0x29, 0x0, 0x9d, 0x70, 0x29, 0x0, 0x29, 0x0, 0xb, 0x90,

    /* U+75 "u" */
    0x57, 0x1, 0xb5, 0x70, 0x1b, 0x48, 0x3, 0xb0, 0xa9, 0x9b,

    /* U+76 "v" */
    0xb, 0x0, 0x84, 0x5, 0x70, 0xb0, 0x0, 0xb7, 0x50, 0x0, 0x6d, 0x0,

    /* U+77 "w" */
    0xb0, 0xe, 0x20, 0xa0, 0x55, 0x59, 0x82, 0x80, 0xa, 0xa0, 0xa8, 0x20, 0x9,
    0x80, 0x6b, 0x0,

    /* U+78 "x" */
    0x67, 0x1b, 0x0, 0x9b, 0x10, 0xa, 0xb2, 0x7, 0x51, 0xb0,

    /* U+79 "y" */
    0xb, 0x10, 0x83, 0x3, 0x81, 0xa0, 0x0, 0xaa, 0x30, 0x0, 0x4a, 0x0, 0xa,
    0xb2, 0x0,

    /* U+7A "z" */
    0x59, 0xbb, 0x1, 0xb1, 0xb, 0x20, 0x9c, 0x98,

    /* U+7B "{" */
    0xa, 0x60, 0xc0, 0xc, 0x5, 0xb0, 0xc, 0x0, 0xc0, 0xa, 0x60,

    /* U+7C "|" */
    0x28, 0x28, 0x28, 0x28, 0x28, 0x28, 0x28,

    /* U+7D "}" */
    0x97, 0x0, 0xb0, 0xb, 0x0, 0xd3, 0xb, 0x0, 0xb0, 0x97, 0x0,

    /* U+7E "~" */
    0x29, 0x35, 0x15, 0x6, 0x80,

    /* U+B0 "°" */
    0x26, 0x47, 0x7, 0x27, 0x50,

    /* U+2022 "•" */
    0x0, 0x5d, 0x2,

    /* U+F001 "" */
    0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x26, 0xbe, 0x0, 0x8d, 0xff, 0xff, 0x0, 0xff,
    0xe9, 0x5f, 0x0, 0xf3, 0x0, 0xf, 0x0, 0xf0, 0x0, 0xf, 0x0, 0xf0, 0xa, 0xff,
    0xaf, 0xf0, 0xa, 0xfa, 0xaf, 0xa0, 0x0, 0x0,

    /* U+F008 "" */
    0xbd, 0xcc, 0xce, 0xab, 0x8b, 0x0, 0x7, 0x58, 0xcd, 0x66, 0x6a, 0xac, 0xcd,
    0x66, 0x6a, 0xac, 0x8b, 0x0, 0x7, 0x58, 0xbd, 0xcc, 0xce, 0xab,

    /* U+F00B "" */
    0x34, 0x14, 0x44, 0x43, 0xff, 0x7f, 0xff, 0xff, 0xab, 0x4b, 0xbb, 0xba,
    0xbc, 0x5c, 0xcc, 0xcb, 0xff, 0x7f, 0xff, 0xff, 0x67, 0x17, 0x88, 0x86,
    0xff, 0x7f, 0xff, 0xff, 0xab, 0x4b, 0xbb, 0xba,

    /* U+F00C "" */
    0x0, 0x0, 0x0, 0x9a, 0x0, 0x0, 0x9, 0xfa, 0xa9, 0x0, 0x9f, 0xa0, 0xaf, 0x99,
    0xfa, 0x0, 0xa, 0xff, 0xa0, 0x0, 0x0, 0x99, 0x0, 0x0,

    /* U+F00D "" */
    0x63, 0x0, 0x82, 0xcf, 0x4a, 0xf4, 0x1d, 0xff, 0x60, 0xa, 0xff, 0x30, 0xaf,
    0x7d, 0xf3, 0xa6, 0x1, 0xb3,

    /* U+F011 "" */
    0x0, 0xc, 0x51, 0x0, 0x1d, 0x7d, 0x6e, 0x70, 0x8d, 0xd, 0x65, 0xf1, 0xc7,
    0xd, 0x60, 0xe6, 0xd7, 0x6, 0x20, 0xe6, 0x9d, 0x0, 0x4, 0xf2, 0x1e, 0xc7,
    0x8f, 0x80, 0x1, 0x9d, 0xc6, 0x0,

    /* U+F013 "" */
    0x0, 0xc, 0xc0, 0x0, 0x18, 0x8f, 0xf8, 0x81, 0x8f, 0xfe, 0xef, 0xf8, 0x2f,
    0xe0, 0xe, 0xf2, 0x2f, 0xe0, 0xe, 0xf2, 0x8f, 0xfe, 0xef, 0xf8, 0x18, 0x8f,
    0xf8, 0x81, 0x0, 0xc, 0xc0, 0x0,

    /* U+F015 "" */
    0x0, 0x0, 0x30, 0x22, 0x0, 0x0, 0xaf, 0xaa, 0xa0, 0x1, 0xda, 0x6a, 0xfa,
    0x3, 0xe8, 0xbf, 0xb8, 0xe3, 0xb6, 0xdf, 0xff, 0xd6, 0xb0, 0x8f, 0xfb, 0xff,
    0x80, 0x8, 0xfc, 0xc, 0xf8, 0x0, 0x5b, 0x80, 0x8b, 0x50,

    /* U+F019 "" */
    0x0, 0xf, 0xf0, 0x0, 0x0, 0xf, 0xf0, 0x0, 0x0, 0xf, 0xf0, 0x0, 0x7, 0xff,
    0xff, 0x70, 0x0, 0x9f, 0xf9, 0x0, 0x78, 0x7a, 0xa7, 0x87, 0xff, 0xfb, 0xbf,
    0xff, 0xff, 0xff, 0xfb, 0xbf,

    /* U+F01C "" */
    0x5, 0xff, 0xff, 0xf5, 0x1, 0xe3, 0x0, 0x3, 0xe1, 0xa8, 0x0, 0x0, 0x8, 0xaf,
    0xff, 0x60, 0x6f, 0xff, 0xff, 0xff, 0xff, 0xff, 0xfd, 0xff, 0xff, 0xff,
    0xfd,

    /* U+F021 "" */
    0x0, 0x0, 0x0, 0x3, 0x2, 0xbf, 0xfb, 0x3f, 0x2e, 0x91, 0x18, 0xff, 0x9a,
    0x0, 0x6c, 0xff, 0x31, 0x0, 0x24, 0x44, 0x44, 0x42, 0x0, 0x13, 0xff, 0xc6,
    0x0, 0xb9, 0xfe, 0xa5, 0x5b, 0xd1, 0xf2, 0x8c, 0xc8, 0x10, 0x30, 0x0, 0x0,
    0x0,

    /* U+F026 "" */
    0x0, 0x9, 0x34, 0xcf, 0xff, 0xff, 0xff, 0xff, 0xab, 0xff, 0x0, 0x4f, 0x0,
    0x1,

    /* U+F027 "" */
    0x0, 0x9, 0x0, 0x34, 0xcf, 0x1, 0xff, 0xff, 0x1b, 0xff, 0xff, 0x1b, 0xbb,
    0xff, 0x1, 0x0, 0x4f, 0x0, 0x0, 0x1, 0x0,

    /* U+F028 "" */
    0x0, 0x0, 0x0, 0x54, 0x0, 0x0, 0x90, 0x23, 0xb3, 0x34, 0xcf, 0x2, 0xc3,
    0xbf, 0xff, 0xf1, 0xb5, 0x6c, 0xff, 0xff, 0x1b, 0x56, 0xca, 0xbf, 0xf0,
    0x2c, 0x3a, 0x0, 0x4f, 0x2, 0x3b, 0x30, 0x0, 0x10, 0x5, 0x40,

    /* U+F03E "" */
    0xdf, 0xff, 0xff, 0xfd, 0xf0, 0x7f, 0xff, 0xff, 0xf8, 0xcf, 0xb1, 0xbf,
    0xfb, 0x5b, 0x0, 0xf, 0xf0, 0x0, 0x0, 0xf, 0xdf, 0xff, 0xff, 0xfd,

    /* U+F048 "" */
    0x40, 0x0, 0x2f, 0x20, 0x8f, 0xf2, 0x9f, 0xff, 0xcf, 0xff, 0xff, 0xff, 0xff,
    0x5e, 0xff, 0xf2, 0x2e, 0xfb, 0x10, 0x19,

    /* U+F04B "" */
    0x0, 0x0, 0x0, 0xd, 0xa1, 0x0, 0x0, 0xff, 0xf7, 0x0, 0xf, 0xff, 0xfd, 0x40,
    0xff, 0xff, 0xff, 0xaf, 0xff, 0xff, 0xfa, 0xff, 0xff, 0xd4, 0xf, 0xff, 0x70,
    0x0, 0xda, 0x10, 0x0, 0x0, 0x0, 0x0, 0x0,

    /* U+F04C "" */
    0x9b, 0x90, 0x9b, 0x9f, 0xff, 0xf, 0xff, 0xff, 0xf0, 0xff, 0xff, 0xff, 0xf,
    0xff, 0xff, 0xf0, 0xff, 0xff, 0xff, 0xf, 0xff, 0xff, 0xf0, 0xff, 0xf2, 0x42,
    0x2, 0x42,

    /* U+F04D "" */
    0x24, 0x44, 0x44, 0x2f, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
    0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
    0xf8, 0xbb, 0xbb, 0xb8,

    /* U+F051 "" */
    0x20, 0x0, 0x4f, 0x80, 0x2f, 0xff, 0x92, 0xff, 0xff, 0xcf, 0xff, 0xff, 0xff,
    0xfe, 0x5f, 0xfd, 0x22, 0xf9, 0x10, 0x1b,

    /* U+F052 "" */
    0x0, 0x0, 0x20, 0x0, 0x0, 0x0, 0x8f, 0x80, 0x0, 0x0, 0x7f, 0xff, 0x70, 0x0,
    0x5f, 0xff, 0xff, 0x50, 0xe, 0xff, 0xff, 0xfe, 0x0, 0x58, 0x88, 0x88, 0x50,
    0xf, 0xff, 0xff, 0xff, 0x0, 0xab, 0xbb, 0xbb, 0xa0,

    /* U+F053 "" */
    0x0, 0x6, 0x20, 0x7, 0xf4, 0x7, 0xf5, 0x5, 0xf6, 0x0, 0x1e, 0xb0, 0x0, 0x2e,
    0xb0, 0x0, 0x2e, 0x60, 0x0, 0x10,

    /* U+F054 "" */
    0x26, 0x0, 0x4, 0xf7, 0x0, 0x5, 0xf7, 0x0, 0x6, 0xf5, 0x0, 0xbe, 0x10, 0xbe,
    0x20, 0x6e, 0x20, 0x0, 0x10, 0x0,

    /* U+F067 "" */
    0x0, 0x4, 0x0, 0x0, 0x3, 0xf3, 0x0, 0x0, 0x4f, 0x40, 0x7, 0x8a, 0xfa, 0x87,
    0xef, 0xff, 0xff, 0xe0, 0x4, 0xf4, 0x0, 0x0, 0x4f, 0x40, 0x0, 0x1, 0xb1,
    0x0,

    /* U+F068 "" */
    0x78, 0x88, 0x88, 0x7e, 0xff, 0xff, 0xfe,

    /* U+F06E "" */
    0x0, 0x8c, 0xcc, 0x80, 0x1, 0xdd, 0x16, 0x3d, 0xd1, 0xcf, 0x55, 0xed, 0x5f,
    0xcb, 0xf5, 0xdf, 0xd5, 0xfc, 0x1d, 0xd3, 0x73, 0xdd, 0x10, 0x8, 0xdc, 0xc8,
    0x10,

    /* U+F070 "" */
    0x1d, 0x30, 0x0, 0x0, 0x0, 0x0, 0x5e, 0x8c, 0xcc, 0xa2, 0x0, 0x0, 0x2d,
    0xb4, 0x49, 0xf4, 0x0, 0x7a, 0x1a, 0xff, 0x3f, 0xe1, 0x7, 0xfa, 0x6, 0xf7,
    0xff, 0x10, 0xa, 0xf3, 0x3, 0xef, 0x40, 0x0, 0x6, 0xcc, 0x71, 0xbb, 0x10,
    0x0, 0x0, 0x0, 0x0, 0x89,

    /* U+F071 "" */
    0x0, 0x0, 0x3e, 0x30, 0x0, 0x0, 0x0, 0xc, 0xfc, 0x0, 0x0, 0x0, 0x6, 0xfc,
    0xf6, 0x0, 0x0, 0x0, 0xed, 0xd, 0xe0, 0x0, 0x0, 0x8f, 0xe0, 0xef, 0x80, 0x0,
    0x2f, 0xff, 0x6f, 0xff, 0x20, 0xb, 0xff, 0xe2, 0xef, 0xfa, 0x0, 0xdf, 0xff,
    0xff, 0xff, 0xd0,

    /* U+F074 "" */
    0x0, 0x0, 0x0, 0x20, 0x44, 0x0, 0x4, 0xf5, 0xef, 0xb1, 0xcf, 0xfd, 0x1,
    0x8c, 0xd1, 0xc1, 0x1, 0xdc, 0x81, 0xc1, 0xef, 0xc1, 0xbf, 0xfd, 0x44, 0x0,
    0x4, 0xf5, 0x0, 0x0, 0x0, 0x20,

    /* U+F077 "" */
    0x0, 0x0, 0x0, 0x0, 0x4, 0xe4, 0x0, 0x4, 0xfc, 0xf4, 0x4, 0xf8, 0x8, 0xf4,
    0xb8, 0x0, 0x8, 0xb0, 0x0, 0x0, 0x0,

    /* U+F078 "" */
    0x0, 0x0, 0x0, 0xb, 0x80, 0x0, 0x8b, 0x4f, 0x80, 0x8f, 0x40, 0x4f, 0xcf,
    0x40, 0x0, 0x4e, 0x40, 0x0, 0x0, 0x0, 0x0,

    /* U+F079 "" */
    0x0, 0x94, 0x14, 0x44, 0x40, 0x0, 0xbf, 0xf8, 0xbb, 0xbf, 0x10, 0x8, 0xb7,
    0x60, 0x0, 0xe1, 0x0, 0xb, 0x40, 0x0, 0x1e, 0x20, 0x0, 0xb7, 0x44, 0x5e,
    0xfd, 0x50, 0x7, 0xbb, 0xb8, 0x5f, 0x80, 0x0, 0x0, 0x0, 0x0, 0x20, 0x0,

    /* U+F07B "" */
    0xdf, 0xfb, 0x0, 0x0, 0xff, 0xff, 0xff, 0xfd, 0xff, 0xff, 0xff, 0xff, 0xff,
    0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xdf, 0xff, 0xff, 0xfd,

    /* U+F093 "" */
    0x0, 0x9, 0x90, 0x0, 0x0, 0x9f, 0xf9, 0x0, 0x7, 0xff, 0xff, 0x70, 0x0, 0xf,
    0xf0, 0x0, 0x0, 0xf, 0xf0, 0x0, 0x78, 0x4f, 0xf4, 0x87, 0xff, 0xe8, 0x8e,
    0xff, 0xff, 0xff, 0xfb, 0xbf,

    /* U+F095 "" */
    0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x7, 0xea, 0x0, 0x0, 0x0, 0xef, 0xe0,
    0x0, 0x0, 0xc, 0xfc, 0x0, 0x0, 0x0, 0x4f, 0x70, 0x0, 0x0, 0x1d, 0xe0, 0x7,
    0xdc, 0x4d, 0xf3, 0x0, 0xef, 0xff, 0xe3, 0x0, 0xa, 0xec, 0x70, 0x0, 0x0,

    /* U+F0C4 "" */
    0x3, 0x0, 0x0, 0x0, 0xcd, 0xc0, 0x2d, 0xc0, 0xe7, 0xf2, 0xee, 0x20, 0x4b,
    0xff, 0xe2, 0x0, 0x4, 0xff, 0xa0, 0x0, 0xcd, 0xf9, 0xf9, 0x0, 0xe7, 0xe0,
    0x7f, 0x90, 0x4a, 0x40, 0x4, 0x50,

    /* U+F0C5 "" */
    0x0, 0xff, 0xf7, 0x47, 0x4f, 0xff, 0x47, 0xf8, 0xff, 0xff, 0xff, 0x8f, 0xff,
    0xff, 0xf8, 0xff, 0xff, 0xff, 0x8f, 0xff, 0xff, 0xfb, 0x78, 0x88, 0x7f,
    0xff, 0xff, 0x0,

    /* U+F0C7 "" */
    0x24, 0x44, 0x41, 0xf, 0xbb, 0xbb, 0xe2, 0xf0, 0x0, 0xf, 0xdf, 0x44, 0x44,
    0xff, 0xff, 0xfc, 0xff, 0xff, 0xf9, 0x9, 0xff, 0xff, 0xd5, 0xdf, 0xf8, 0xbb,
    0xbb, 0xb8,

    /* U+F0E7 "" */
    0x7, 0xff, 0x60, 0x0, 0xaf, 0xf2, 0x0, 0xc, 0xff, 0x87, 0x0, 0xef, 0xff,
    0xb0, 0x7, 0x8e, 0xf2, 0x0, 0x0, 0xf8, 0x0, 0x0, 0x3e, 0x0, 0x0, 0x6, 0x50,
    0x0,

    /* U+F0EA "" */
    0x79, 0xb9, 0x70, 0xf, 0xfc, 0xff, 0x0, 0xff, 0x68, 0x83, 0xf, 0xf8, 0xff,
    0x8b, 0xff, 0x8f, 0xf8, 0x8f, 0xf8, 0xff, 0xff, 0x78, 0x8f, 0xff, 0xf0, 0x7,
    0xff, 0xff,

    /* U+F0F3 "" */
    0x0, 0xd, 0x0, 0x0, 0x4e, 0xfe, 0x30, 0xd, 0xff, 0xfd, 0x0, 0xff, 0xff,
    0xf0, 0x3f, 0xff, 0xff, 0x3b, 0xff, 0xff, 0xfb, 0x78, 0x88, 0x88, 0x60, 0x4,
    0xf4, 0x0,

    /* U+F11C "" */
    0xdf, 0xff, 0xff, 0xff, 0xdf, 0x18, 0x81, 0x88, 0x1f, 0xfe, 0xaa, 0xca,
    0xae, 0xff, 0xea, 0xac, 0xaa, 0xef, 0xf1, 0x80, 0x0, 0x81, 0xfd, 0xff, 0xff,
    0xff, 0xfd,

    /* U+F124 "" */
    0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x4b, 0xc0, 0x0, 0x0, 0x5c, 0xff,
    0xb0, 0x0, 0x6e, 0xff, 0xff, 0x40, 0xd, 0xff, 0xff, 0xfc, 0x0, 0x6, 0x88,
    0xcf, 0xf5, 0x0, 0x0, 0x0, 0x8f, 0xe0, 0x0, 0x0, 0x0, 0x8f, 0x60, 0x0, 0x0,
    0x0, 0x5d, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0,

    /* U+F15B "" */
    0xff, 0xf8, 0xb0, 0xff, 0xf8, 0xfb, 0xff, 0xfc, 0x88, 0xff, 0xff, 0xff,
    0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,

    /* U+F1EB "" */
    0x0, 0x4, 0x77, 0x40, 0x0, 0x9, 0xff, 0xcc, 0xff, 0x90, 0xcd, 0x40, 0x0,
    0x4, 0xdc, 0x20, 0x4b, 0xff, 0xb4, 0x2, 0x1, 0xfa, 0x55, 0xaf, 0x10, 0x0,
    0x0, 0x21, 0x0, 0x0, 0x0, 0x0, 0xee, 0x0, 0x0, 0x0, 0x0, 0x87, 0x0, 0x0,

    /* U+F240 "" */
    0x24, 0x44, 0x44, 0x44, 0x40, 0xfb, 0xbb, 0xbb, 0xbb, 0xda, 0xf7, 0xee,
    0xee, 0xee, 0x5f, 0xf8, 0xff, 0xff, 0xff, 0x2f, 0xf5, 0x66, 0x66, 0x66,
    0xab, 0x8b, 0xbb, 0xbb, 0xbb, 0xb3,

    /* U+F241 "" */
    0x24, 0x44, 0x44, 0x44, 0x40, 0xfb, 0xbb, 0xbb, 0xbb, 0xda, 0xf7, 0xee,
    0xee, 0x70, 0x5f, 0xf8, 0xff, 0xff, 0x80, 0x2f, 0xf5, 0x66, 0x66, 0x54,
    0xab, 0x8b, 0xbb, 0xbb, 0xbb, 0xb3,

    /* U+F242 "" */
    0x24, 0x44, 0x44, 0x44, 0x40, 0xfb, 0xbb, 0xbb, 0xbb, 0xda, 0xf7, 0xee,
    0xe0, 0x0, 0x5f, 0xf8, 0xff, 0xf0, 0x0, 0x2f, 0xf5, 0x66, 0x64, 0x44, 0xab,
    0x8b, 0xbb, 0xbb, 0xbb, 0xb3,

    /* U+F243 "" */
    0x24, 0x44, 0x44, 0x44, 0x40, 0xfb, 0xbb, 0xbb, 0xbb, 0xda, 0xf7, 0xe7, 0x0,
    0x0, 0x5f, 0xf8, 0xf8, 0x0, 0x0, 0x2f, 0xf5, 0x65, 0x44, 0x44, 0xab, 0x8b,
    0xbb, 0xbb, 0xbb, 0xb3,

    /* U+F244 "" */
    0x24, 0x44, 0x44, 0x44, 0x40, 0xfb, 0xbb, 0xbb, 0xbb, 0xd8, 0xf0, 0x0, 0x0,
    0x0, 0x5f, 0xf0, 0x0, 0x0, 0x0, 0x2f, 0xf4, 0x44, 0x44, 0x44, 0xad, 0x8b,
    0xbb, 0xbb, 0xbb, 0xb3,

    /* U+F287 "" */
    0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x7, 0xd8, 0x0, 0x0, 0x0, 0x7, 0x36,
    0x40, 0x0, 0x9, 0xb1, 0x91, 0x11, 0x17, 0x20, 0xef, 0x88, 0xd8, 0x88, 0xd9,
    0x2, 0x20, 0x6, 0x48, 0x70, 0x0, 0x0, 0x0, 0x6, 0xec, 0x0, 0x0, 0x0, 0x0,
    0x0, 0x0, 0x0,

    /* U+F293 "" */
    0x6, 0xdd, 0xc3, 0x4, 0xff, 0x3e, 0xd0, 0x9c, 0xb5, 0x5f, 0x2b, 0xf7, 0x1a,
    0xf4, 0xbf, 0x81, 0xbf, 0x39, 0xc9, 0x64, 0xf2, 0x4f, 0xf3, 0xde, 0x0, 0x6d,
    0xed, 0x30,

    /* U+F2ED "" */
    0x78, 0xdf, 0xd8, 0x77, 0x88, 0x88, 0x87, 0x8f, 0xff, 0xff, 0x88, 0xcc,
    0x8c, 0xc8, 0x8c, 0xc8, 0xcc, 0x88, 0xcc, 0x8c, 0xc8, 0x8c, 0xc8, 0xcc,
    0x85, 0xff, 0xff, 0xf5,

    /* U+F304 "" */
    0x0, 0x0, 0x0, 0x7e, 0x30, 0x0, 0x0, 0x4b, 0xfe, 0x0, 0x0, 0x8f, 0x9b, 0x70,
    0x0, 0x8f, 0xff, 0x40, 0x0, 0x8f, 0xff, 0x80, 0x0, 0x7f, 0xff, 0x80, 0x0,
    0xe, 0xff, 0x80, 0x0, 0x0, 0xee, 0x70, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0,

    /* U+F55A "" */
    0x0, 0xaf, 0xff, 0xff, 0xfc, 0xb, 0xff, 0x9c, 0xc9, 0xff, 0xaf, 0xff, 0xc1,
    0x1c, 0xff, 0xaf, 0xff, 0xc1, 0x1c, 0xff, 0xb, 0xff, 0x9c, 0xc9, 0xff, 0x0,
    0xaf, 0xff, 0xff, 0xfc,

    /* U+F7C2 "" */
    0x7, 0xff, 0xfe, 0x17, 0xb6, 0x27, 0xc3, 0xfe, 0xb9, 0xbe, 0x3f, 0xff, 0xff,
    0xf3, 0xff, 0xff, 0xff, 0x3f, 0xff, 0xff, 0xf3, 0xff, 0xff, 0xff, 0x3c,
    0xff, 0xff, 0xe1,

    /* U+F8A2 "" */
    0x0, 0x0, 0x0, 0x3, 0x0, 0x23, 0x0, 0x2, 0xf0, 0x2e, 0x92, 0x22, 0x5f, 0xd,
    0xff, 0xff, 0xff, 0xf0, 0x2e, 0x92, 0x22, 0x21, 0x0, 0x23, 0x0, 0x0, 0x0};

/*---------------------
 *  GLYPH DESCRIPTION
 *--------------------*/

static const lv_font_fmt_txt_glyph_dsc_t glyph_dsc[] = {
    {.bitmap_index = 0,
     .adv_w = 0,
     .box_w = 0,
     .box_h = 0,
     .ofs_x = 0,
     .ofs_y = 0} /* id = 0 reserved */,
    {.bitmap_index = 0,
     .adv_w = 34,
     .box_w = 0,
     .box_h = 0,
     .ofs_x = 0,
     .ofs_y = 0},
    {.bitmap_index = 0,
     .adv_w = 34,
     .box_w = 2,
     .box_h = 5,
     .ofs_x = 0,
     .ofs_y = 0},
    {.bitmap_index = 5,
     .adv_w = 50,
     .box_w = 3,
     .box_h = 3,
     .ofs_x = 0,
     .ofs_y = 2},
    {.bitmap_index = 10,
     .adv_w = 90,
     .box_w = 6,
     .box_h = 5,
     .ofs_x = 0,
     .ofs_y = 0},
    {.bitmap_index = 25,
     .adv_w = 79,
     .box_w = 5,
     .box_h = 7,
     .ofs_x = 0,
     .ofs_y = -1},
    {.bitmap_index = 43,
     .adv_w = 108,
     .box_w = 7,
     .box_h = 5,
     .ofs_x = 0,
     .ofs_y = 0},
    {.bitmap_index = 61,
     .adv_w = 88,
     .box_w = 6,
     .box_h = 6,
     .ofs_x = 0,
     .ofs_y = -1},
    {.bitmap_index = 79,
     .adv_w = 27,
     .box_w = 2,
     .box_h = 3,
     .ofs_x = 0,
     .ofs_y = 2},
    {.bitmap_index = 82,
     .adv_w = 43,
     .box_w = 3,
     .box_h = 7,
     .ofs_x = 0,
     .ofs_y = -1},
    {.bitmap_index = 93,
     .adv_w = 43,
     .box_w = 2,
     .box_h = 7,
     .ofs_x = 0,
     .ofs_y = -1},
    {.bitmap_index = 100,
     .adv_w = 51,
     .box_w = 4,
     .box_h = 3,
     .ofs_x = 0,
     .ofs_y = 3},
    {.bitmap_index = 106,
     .adv_w = 74,
     .box_w = 5,
     .box_h = 4,
     .ofs_x = 0,
     .ofs_y = 1},
    {.bitmap_index = 116,
     .adv_w = 29,
     .box_w = 2,
     .box_h = 3,
     .ofs_x = 0,
     .ofs_y = -1},
    {.bitmap_index = 119,
     .adv_w = 49,
     .box_w = 3,
     .box_h = 1,
     .ofs_x = 0,
     .ofs_y = 2},
    {.bitmap_index = 121,
     .adv_w = 29,
     .box_w = 2,
     .box_h = 2,
     .ofs_x = 0,
     .ofs_y = 0},
    {.bitmap_index = 123,
     .adv_w = 45,
     .box_w = 5,
     .box_h = 7,
     .ofs_x = -1,
     .ofs_y = -1},
    {.bitmap_index = 141,
     .adv_w = 85,
     .box_w = 5,
     .box_h = 5,
     .ofs_x = 0,
     .ofs_y = 0},
    {.bitmap_index = 154,
     .adv_w = 47,
     .box_w = 3,
     .box_h = 5,
     .ofs_x = 0,
     .ofs_y = 0},
    {.bitmap_index = 162,
     .adv_w = 73,
     .box_w = 5,
     .box_h = 5,
     .ofs_x = 0,
     .ofs_y = 0},
    {.bitmap_index = 175,
     .adv_w = 73,
     .box_w = 5,
     .box_h = 5,
     .ofs_x = 0,
     .ofs_y = 0},
    {.bitmap_index = 188,
     .adv_w = 86,
     .box_w = 6,
     .box_h = 5,
     .ofs_x = 0,
     .ofs_y = 0},
    {.bitmap_index = 203,
     .adv_w = 73,
     .box_w = 5,
     .box_h = 5,
     .ofs_x = 0,
     .ofs_y = 0},
    {.bitmap_index = 216,
     .adv_w = 79,
     .box_w = 5,
     .box_h = 5,
     .ofs_x = 0,
     .ofs_y = 0},
    {.bitmap_index = 229,
     .adv_w = 77,
     .box_w = 5,
     .box_h = 5,
     .ofs_x = 0,
     .ofs_y = 0},
    {.bitmap_index = 242,
     .adv_w = 82,
     .box_w = 5,
     .box_h = 5,
     .ofs_x = 0,
     .ofs_y = 0},
    {.bitmap_index = 255,
     .adv_w = 79,
     .box_w = 5,
     .box_h = 5,
     .ofs_x = 0,
     .ofs_y = 0},
    {.bitmap_index = 268,
     .adv_w = 29,
     .box_w = 2,
     .box_h = 4,
     .ofs_x = 0,
     .ofs_y = 0},
    {.bitmap_index = 272,
     .adv_w = 29,
     .box_w = 2,
     .box_h = 6,
     .ofs_x = 0,
     .ofs_y = -2},
    {.bitmap_index = 278,
     .adv_w = 74,
     .box_w = 5,
     .box_h = 5,
     .ofs_x = 0,
     .ofs_y = 0},
    {.bitmap_index = 291,
     .adv_w = 74,
     .box_w = 5,
     .box_h = 3,
     .ofs_x = 0,
     .ofs_y = 1},
    {.bitmap_index = 299,
     .adv_w = 74,
     .box_w = 5,
     .box_h = 5,
     .ofs_x = 0,
     .ofs_y = 0},
    {.bitmap_index = 312,
     .adv_w = 73,
     .box_w = 5,
     .box_h = 5,
     .ofs_x = 0,
     .ofs_y = 0},
    {.bitmap_index = 325,
     .adv_w = 132,
     .box_w = 8,
     .box_h = 6,
     .ofs_x = 0,
     .ofs_y = -1},
    {.bitmap_index = 349,
     .adv_w = 94,
     .box_w = 7,
     .box_h = 5,
     .ofs_x = -1,
     .ofs_y = 0},
    {.bitmap_index = 367,
     .adv_w = 97,
     .box_w = 6,
     .box_h = 5,
     .ofs_x = 0,
     .ofs_y = 0},
    {.bitmap_index = 382,
     .adv_w = 93,
     .box_w = 6,
     .box_h = 5,
     .ofs_x = 0,
     .ofs_y = 0},
    {.bitmap_index = 397,
     .adv_w = 106,
     .box_w = 7,
     .box_h = 5,
     .ofs_x = 0,
     .ofs_y = 0},
    {.bitmap_index = 415,
     .adv_w = 86,
     .box_w = 5,
     .box_h = 5,
     .ofs_x = 0,
     .ofs_y = 0},
    {.bitmap_index = 428,
     .adv_w = 81,
     .box_w = 5,
     .box_h = 5,
     .ofs_x = 0,
     .ofs_y = 0},
    {.bitmap_index = 441,
     .adv_w = 99,
     .box_w = 6,
     .box_h = 5,
     .ofs_x = 0,
     .ofs_y = 0},
    {.bitmap_index = 456,
     .adv_w = 104,
     .box_w = 6,
     .box_h = 5,
     .ofs_x = 0,
     .ofs_y = 0},
    {.bitmap_index = 471,
     .adv_w = 40,
     .box_w = 2,
     .box_h = 5,
     .ofs_x = 0,
     .ofs_y = 0},
    {.bitmap_index = 476,
     .adv_w = 66,
     .box_w = 5,
     .box_h = 5,
     .ofs_x = -1,
     .ofs_y = 0},
    {.bitmap_index = 489,
     .adv_w = 92,
     .box_w = 6,
     .box_h = 5,
     .ofs_x = 0,
     .ofs_y = 0},
    {.bitmap_index = 504,
     .adv_w = 76,
     .box_w = 5,
     .box_h = 5,
     .ofs_x = 0,
     .ofs_y = 0},
    {.bitmap_index = 517,
     .adv_w = 122,
     .box_w = 7,
     .box_h = 5,
     .ofs_x = 0,
     .ofs_y = 0},
    {.bitmap_index = 535,
     .adv_w = 104,
     .box_w = 6,
     .box_h = 5,
     .ofs_x = 0,
     .ofs_y = 0},
    {.bitmap_index = 550,
     .adv_w = 108,
     .box_w = 7,
     .box_h = 5,
     .ofs_x = 0,
     .ofs_y = 0},
    {.bitmap_index = 568,
     .adv_w = 92,
     .box_w = 6,
     .box_h = 5,
     .ofs_x = 0,
     .ofs_y = 0},
    {.bitmap_index = 583,
     .adv_w = 108,
     .box_w = 7,
     .box_h = 6,
     .ofs_x = 0,
     .ofs_y = -1},
    {.bitmap_index = 604,
     .adv_w = 93,
     .box_w = 6,
     .box_h = 5,
     .ofs_x = 0,
     .ofs_y = 0},
    {.bitmap_index = 619,
     .adv_w = 79,
     .box_w = 5,
     .box_h = 5,
     .ofs_x = 0,
     .ofs_y = 0},
    {.bitmap_index = 632,
     .adv_w = 75,
     .box_w = 5,
     .box_h = 5,
     .ofs_x = 0,
     .ofs_y = 0},
    {.bitmap_index = 645,
     .adv_w = 101,
     .box_w = 6,
     .box_h = 5,
     .ofs_x = 0,
     .ofs_y = 0},
    {.bitmap_index = 660,
     .adv_w = 91,
     .box_w = 7,
     .box_h = 5,
     .ofs_x = -1,
     .ofs_y = 0},
    {.bitmap_index = 678,
     .adv_w = 144,
     .box_w = 9,
     .box_h = 5,
     .ofs_x = 0,
     .ofs_y = 0},
    {.bitmap_index = 701,
     .adv_w = 86,
     .box_w = 6,
     .box_h = 5,
     .ofs_x = 0,
     .ofs_y = 0},
    {.bitmap_index = 716,
     .adv_w = 83,
     .box_w = 7,
     .box_h = 5,
     .ofs_x = -1,
     .ofs_y = 0},
    {.bitmap_index = 734,
     .adv_w = 84,
     .box_w = 6,
     .box_h = 5,
     .ofs_x = 0,
     .ofs_y = 0},
    {.bitmap_index = 749,
     .adv_w = 43,
     .box_w = 3,
     .box_h = 7,
     .ofs_x = 0,
     .ofs_y = -1},
    {.bitmap_index = 760,
     .adv_w = 45,
     .box_w = 5,
     .box_h = 7,
     .ofs_x = -1,
     .ofs_y = -1},
    {.bitmap_index = 778,
     .adv_w = 43,
     .box_w = 2,
     .box_h = 7,
     .ofs_x = 0,
     .ofs_y = -1},
    {.bitmap_index = 785,
     .adv_w = 75,
     .box_w = 5,
     .box_h = 3,
     .ofs_x = 0,
     .ofs_y = 1},
    {.bitmap_index = 793,
     .adv_w = 64,
     .box_w = 4,
     .box_h = 1,
     .ofs_x = 0,
     .ofs_y = -1},
    {.bitmap_index = 795,
     .adv_w = 77,
     .box_w = 3,
     .box_h = 1,
     .ofs_x = 0,
     .ofs_y = 5},
    {.bitmap_index = 797,
     .adv_w = 77,
     .box_w = 5,
     .box_h = 4,
     .ofs_x = 0,
     .ofs_y = 0},
    {.bitmap_index = 807,
     .adv_w = 87,
     .box_w = 6,
     .box_h = 6,
     .ofs_x = 0,
     .ofs_y = 0},
    {.bitmap_index = 825,
     .adv_w = 73,
     .box_w = 5,
     .box_h = 4,
     .ofs_x = 0,
     .ofs_y = 0},
    {.bitmap_index = 835,
     .adv_w = 87,
     .box_w = 5,
     .box_h = 6,
     .ofs_x = 0,
     .ofs_y = 0},
    {.bitmap_index = 850,
     .adv_w = 78,
     .box_w = 5,
     .box_h = 4,
     .ofs_x = 0,
     .ofs_y = 0},
    {.bitmap_index = 860,
     .adv_w = 45,
     .box_w = 4,
     .box_h = 6,
     .ofs_x = 0,
     .ofs_y = 0},
    {.bitmap_index = 872,
     .adv_w = 88,
     .box_w = 5,
     .box_h = 5,
     .ofs_x = 0,
     .ofs_y = -1},
    {.bitmap_index = 885,
     .adv_w = 87,
     .box_w = 5,
     .box_h = 6,
     .ofs_x = 0,
     .ofs_y = 0},
    {.bitmap_index = 900,
     .adv_w = 36,
     .box_w = 2,
     .box_h = 6,
     .ofs_x = 0,
     .ofs_y = 0},
    {.bitmap_index = 906,
     .adv_w = 36,
     .box_w = 3,
     .box_h = 7,
     .ofs_x = -1,
     .ofs_y = -1},
    {.bitmap_index = 917,
     .adv_w = 79,
     .box_w = 5,
     .box_h = 6,
     .ofs_x = 0,
     .ofs_y = 0},
    {.bitmap_index = 932,
     .adv_w = 36,
     .box_w = 2,
     .box_h = 6,
     .ofs_x = 0,
     .ofs_y = 0},
    {.bitmap_index = 938,
     .adv_w = 135,
     .box_w = 8,
     .box_h = 4,
     .ofs_x = 0,
     .ofs_y = 0},
    {.bitmap_index = 954,
     .adv_w = 87,
     .box_w = 5,
     .box_h = 4,
     .ofs_x = 0,
     .ofs_y = 0},
    {.bitmap_index = 964,
     .adv_w = 81,
     .box_w = 5,
     .box_h = 4,
     .ofs_x = 0,
     .ofs_y = 0},
    {.bitmap_index = 974,
     .adv_w = 87,
     .box_w = 6,
     .box_h = 5,
     .ofs_x = 0,
     .ofs_y = -1},
    {.bitmap_index = 989,
     .adv_w = 87,
     .box_w = 5,
     .box_h = 5,
     .ofs_x = 0,
     .ofs_y = -1},
    {.bitmap_index = 1002,
     .adv_w = 52,
     .box_w = 4,
     .box_h = 4,
     .ofs_x = 0,
     .ofs_y = 0},
    {.bitmap_index = 1010,
     .adv_w = 64,
     .box_w = 4,
     .box_h = 4,
     .ofs_x = 0,
     .ofs_y = 0},
    {.bitmap_index = 1018,
     .adv_w = 53,
     .box_w = 4,
     .box_h = 5,
     .ofs_x = 0,
     .ofs_y = 0},
    {.bitmap_index = 1028,
     .adv_w = 87,
     .box_w = 5,
     .box_h = 4,
     .ofs_x = 0,
     .ofs_y = 0},
    {.bitmap_index = 1038,
     .adv_w = 72,
     .box_w = 6,
     .box_h = 4,
     .ofs_x = -1,
     .ofs_y = 0},
    {.bitmap_index = 1050,
     .adv_w = 115,
     .box_w = 8,
     .box_h = 4,
     .ofs_x = 0,
     .ofs_y = 0},
    {.bitmap_index = 1066,
     .adv_w = 71,
     .box_w = 5,
     .box_h = 4,
     .ofs_x = 0,
     .ofs_y = 0},
    {.bitmap_index = 1076,
     .adv_w = 72,
     .box_w = 6,
     .box_h = 5,
     .ofs_x = -1,
     .ofs_y = -1},
    {.bitmap_index = 1091,
     .adv_w = 67,
     .box_w = 4,
     .box_h = 4,
     .ofs_x = 0,
     .ofs_y = 0},
    {.bitmap_index = 1099,
     .adv_w = 45,
     .box_w = 3,
     .box_h = 7,
     .ofs_x = 0,
     .ofs_y = -1},
    {.bitmap_index = 1110,
     .adv_w = 38,
     .box_w = 2,
     .box_h = 7,
     .ofs_x = 0,
     .ofs_y = -1},
    {.bitmap_index = 1117,
     .adv_w = 45,
     .box_w = 3,
     .box_h = 7,
     .ofs_x = 0,
     .ofs_y = -1},
    {.bitmap_index = 1128,
     .adv_w = 74,
     .box_w = 5,
     .box_h = 2,
     .ofs_x = 0,
     .ofs_y = 2},
    {.bitmap_index = 1133,
     .adv_w = 54,
     .box_w = 3,
     .box_h = 3,
     .ofs_x = 0,
     .ofs_y = 3},
    {.bitmap_index = 1138,
     .adv_w = 40,
     .box_w = 2,
     .box_h = 3,
     .ofs_x = 0,
     .ofs_y = 1},
    {.bitmap_index = 1141,
     .adv_w = 128,
     .box_w = 8,
     .box_h = 9,
     .ofs_x = 0,
     .ofs_y = -1},
    {.bitmap_index = 1177,
     .adv_w = 128,
     .box_w = 8,
     .box_h = 6,
     .ofs_x = 0,
     .ofs_y = 0},
    {.bitmap_index = 1201,
     .adv_w = 128,
     .box_w = 8,
     .box_h = 8,
     .ofs_x = 0,
     .ofs_y = -1},
    {.bitmap_index = 1233,
     .adv_w = 128,
     .box_w = 8,
     .box_h = 6,
     .ofs_x = 0,
     .ofs_y = 0},
    {.bitmap_index = 1257,
     .adv_w = 88,
     .box_w = 6,
     .box_h = 6,
     .ofs_x = 0,
     .ofs_y = 0},
    {.bitmap_index = 1275,
     .adv_w = 128,
     .box_w = 8,
     .box_h = 8,
     .ofs_x = 0,
     .ofs_y = -1},
    {.bitmap_index = 1307,
     .adv_w = 128,
     .box_w = 8,
     .box_h = 8,
     .ofs_x = 0,
     .ofs_y = -1},
    {.bitmap_index = 1339,
     .adv_w = 144,
     .box_w = 9,
     .box_h = 8,
     .ofs_x = 0,
     .ofs_y = -1},
    {.bitmap_index = 1375,
     .adv_w = 128,
     .box_w = 8,
     .box_h = 8,
     .ofs_x = 0,
     .ofs_y = -1},
    {.bitmap_index = 1407,
     .adv_w = 144,
     .box_w = 9,
     .box_h = 6,
     .ofs_x = 0,
     .ofs_y = 0},
    {.bitmap_index = 1434,
     .adv_w = 128,
     .box_w = 8,
     .box_h = 10,
     .ofs_x = 0,
     .ofs_y = -2},
    {.bitmap_index = 1474,
     .adv_w = 64,
     .box_w = 4,
     .box_h = 7,
     .ofs_x = 0,
     .ofs_y = -1},
    {.bitmap_index = 1488,
     .adv_w = 96,
     .box_w = 6,
     .box_h = 7,
     .ofs_x = 0,
     .ofs_y = -1},
    {.bitmap_index = 1509,
     .adv_w = 144,
     .box_w = 9,
     .box_h = 8,
     .ofs_x = 0,
     .ofs_y = -1},
    {.bitmap_index = 1545,
     .adv_w = 128,
     .box_w = 8,
     .box_h = 6,
     .ofs_x = 0,
     .ofs_y = 0},
    {.bitmap_index = 1569,
     .adv_w = 112,
     .box_w = 5,
     .box_h = 8,
     .ofs_x = 1,
     .ofs_y = -1},
    {.bitmap_index = 1589,
     .adv_w = 112,
     .box_w = 7,
     .box_h = 10,
     .ofs_x = 0,
     .ofs_y = -2},
    {.bitmap_index = 1624,
     .adv_w = 112,
     .box_w = 7,
     .box_h = 8,
     .ofs_x = 0,
     .ofs_y = -1},
    {.bitmap_index = 1652,
     .adv_w = 112,
     .box_w = 7,
     .box_h = 8,
     .ofs_x = 0,
     .ofs_y = -1},
    {.bitmap_index = 1680,
     .adv_w = 112,
     .box_w = 5,
     .box_h = 8,
     .ofs_x = 1,
     .ofs_y = -1},
    {.bitmap_index = 1700,
     .adv_w = 112,
     .box_w = 9,
     .box_h = 8,
     .ofs_x = -1,
     .ofs_y = -1},
    {.bitmap_index = 1736,
     .adv_w = 80,
     .box_w = 5,
     .box_h = 8,
     .ofs_x = 0,
     .ofs_y = -1},
    {.bitmap_index = 1756,
     .adv_w = 80,
     .box_w = 5,
     .box_h = 8,
     .ofs_x = 0,
     .ofs_y = -1},
    {.bitmap_index = 1776,
     .adv_w = 112,
     .box_w = 7,
     .box_h = 8,
     .ofs_x = 0,
     .ofs_y = -1},
    {.bitmap_index = 1804,
     .adv_w = 112,
     .box_w = 7,
     .box_h = 2,
     .ofs_x = 0,
     .ofs_y = 2},
    {.bitmap_index = 1811,
     .adv_w = 144,
     .box_w = 9,
     .box_h = 6,
     .ofs_x = 0,
     .ofs_y = 0},
    {.bitmap_index = 1838,
     .adv_w = 160,
     .box_w = 11,
     .box_h = 8,
     .ofs_x = -1,
     .ofs_y = -1},
    {.bitmap_index = 1882,
     .adv_w = 144,
     .box_w = 11,
     .box_h = 8,
     .ofs_x = -1,
     .ofs_y = -1},
    {.bitmap_index = 1926,
     .adv_w = 128,
     .box_w = 8,
     .box_h = 8,
     .ofs_x = 0,
     .ofs_y = -1},
    {.bitmap_index = 1958,
     .adv_w = 112,
     .box_w = 7,
     .box_h = 6,
     .ofs_x = 0,
     .ofs_y = 0},
    {.bitmap_index = 1979,
     .adv_w = 112,
     .box_w = 7,
     .box_h = 6,
     .ofs_x = 0,
     .ofs_y = 0},
    {.bitmap_index = 2000,
     .adv_w = 160,
     .box_w = 11,
     .box_h = 7,
     .ofs_x = -1,
     .ofs_y = -1},
    {.bitmap_index = 2039,
     .adv_w = 128,
     .box_w = 8,
     .box_h = 6,
     .ofs_x = 0,
     .ofs_y = 0},
    {.bitmap_index = 2063,
     .adv_w = 128,
     .box_w = 8,
     .box_h = 8,
     .ofs_x = 0,
     .ofs_y = -1},
    {.bitmap_index = 2095,
     .adv_w = 128,
     .box_w = 9,
     .box_h = 9,
     .ofs_x = -1,
     .ofs_y = -1},
    {.bitmap_index = 2136,
     .adv_w = 112,
     .box_w = 8,
     .box_h = 8,
     .ofs_x = 0,
     .ofs_y = -1},
    {.bitmap_index = 2168,
     .adv_w = 112,
     .box_w = 7,
     .box_h = 8,
     .ofs_x = 0,
     .ofs_y = -1},
    {.bitmap_index = 2196,
     .adv_w = 112,
     .box_w = 7,
     .box_h = 8,
     .ofs_x = 0,
     .ofs_y = -1},
    {.bitmap_index = 2224,
     .adv_w = 80,
     .box_w = 7,
     .box_h = 8,
     .ofs_x = -1,
     .ofs_y = -1},
    {.bitmap_index = 2252,
     .adv_w = 112,
     .box_w = 7,
     .box_h = 8,
     .ofs_x = 0,
     .ofs_y = -1},
    {.bitmap_index = 2280,
     .adv_w = 112,
     .box_w = 7,
     .box_h = 8,
     .ofs_x = 0,
     .ofs_y = -1},
    {.bitmap_index = 2308,
     .adv_w = 144,
     .box_w = 9,
     .box_h = 6,
     .ofs_x = 0,
     .ofs_y = 0},
    {.bitmap_index = 2335,
     .adv_w = 128,
     .box_w = 10,
     .box_h = 10,
     .ofs_x = -1,
     .ofs_y = -2},
    {.bitmap_index = 2385,
     .adv_w = 96,
     .box_w = 6,
     .box_h = 8,
     .ofs_x = 0,
     .ofs_y = -1},
    {.bitmap_index = 2409,
     .adv_w = 160,
     .box_w = 10,
     .box_h = 8,
     .ofs_x = 0,
     .ofs_y = -1},
    {.bitmap_index = 2449,
     .adv_w = 160,
     .box_w = 10,
     .box_h = 6,
     .ofs_x = 0,
     .ofs_y = 0},
    {.bitmap_index = 2479,
     .adv_w = 160,
     .box_w = 10,
     .box_h = 6,
     .ofs_x = 0,
     .ofs_y = 0},
    {.bitmap_index = 2509,
     .adv_w = 160,
     .box_w = 10,
     .box_h = 6,
     .ofs_x = 0,
     .ofs_y = 0},
    {.bitmap_index = 2539,
     .adv_w = 160,
     .box_w = 10,
     .box_h = 6,
     .ofs_x = 0,
     .ofs_y = 0},
    {.bitmap_index = 2569,
     .adv_w = 160,
     .box_w = 10,
     .box_h = 6,
     .ofs_x = 0,
     .ofs_y = 0},
    {.bitmap_index = 2599,
     .adv_w = 160,
     .box_w = 11,
     .box_h = 8,
     .ofs_x = 0,
     .ofs_y = -1},
    {.bitmap_index = 2643,
     .adv_w = 112,
     .box_w = 7,
     .box_h = 8,
     .ofs_x = 0,
     .ofs_y = -1},
    {.bitmap_index = 2671,
     .adv_w = 112,
     .box_w = 7,
     .box_h = 8,
     .ofs_x = 0,
     .ofs_y = -1},
    {.bitmap_index = 2699,
     .adv_w = 128,
     .box_w = 9,
     .box_h = 9,
     .ofs_x = -1,
     .ofs_y = -2},
    {.bitmap_index = 2740,
     .adv_w = 160,
     .box_w = 10,
     .box_h = 6,
     .ofs_x = 0,
     .ofs_y = 0},
    {.bitmap_index = 2770,
     .adv_w = 96,
     .box_w = 7,
     .box_h = 8,
     .ofs_x = 0,
     .ofs_y = -1},
    {.bitmap_index = 2798,
     .adv_w = 129,
     .box_w = 9,
     .box_h = 6,
     .ofs_x = 0,
     .ofs_y = 0}};

/*---------------------
 *  CHARACTER MAPPING
 *--------------------*/

static const uint16_t unicode_list_1[] = {
    0x0,    0x1f72, 0xef51, 0xef58, 0xef5b, 0xef5c, 0xef5d, 0xef61, 0xef63,
    0xef65, 0xef69, 0xef6c, 0xef71, 0xef76, 0xef77, 0xef78, 0xef8e, 0xef98,
    0xef9b, 0xef9c, 0xef9d, 0xefa1, 0xefa2, 0xefa3, 0xefa4, 0xefb7, 0xefb8,
    0xefbe, 0xefc0, 0xefc1, 0xefc4, 0xefc7, 0xefc8, 0xefc9, 0xefcb, 0xefe3,
    0xefe5, 0xf014, 0xf015, 0xf017, 0xf037, 0xf03a, 0xf043, 0xf06c, 0xf074,
    0xf0ab, 0xf13b, 0xf190, 0xf191, 0xf192, 0xf193, 0xf194, 0xf1d7, 0xf1e3,
    0xf23d, 0xf254, 0xf4aa, 0xf712, 0xf7f2};

/*Collect the unicode lists and glyph_id offsets*/
static const lv_font_fmt_txt_cmap_t cmaps[] = {
    {.range_start = 32,
     .range_length = 95,
     .glyph_id_start = 1,
     .unicode_list = NULL,
     .glyph_id_ofs_list = NULL,
     .list_length = 0,
     .type = LV_FONT_FMT_TXT_CMAP_FORMAT0_TINY},
    {.range_start = 176,
     .range_length = 63475,
     .glyph_id_start = 96,
     .unicode_list = unicode_list_1,
     .glyph_id_ofs_list = NULL,
     .list_length = 59,
     .type = LV_FONT_FMT_TXT_CMAP_SPARSE_TINY}};

/*-----------------
 *    KERNING
 *----------------*/

/*Map glyph_ids to kern left classes*/
static const uint8_t kern_left_class_mapping[] = {
    0,  0,  1,  2,  0,  3,  4,  5,  2,  6,  7,  8,  9,  10, 9,  10, 11, 12,
    0,  13, 14, 15, 16, 17, 18, 19, 12, 20, 20, 0,  0,  0,  21, 22, 23, 24,
    25, 22, 26, 27, 28, 29, 29, 30, 31, 32, 29, 29, 22, 33, 34, 35, 3,  36,
    30, 37, 37, 38, 39, 40, 41, 42, 43, 0,  44, 0,  45, 46, 47, 48, 49, 50,
    51, 45, 52, 52, 53, 48, 45, 45, 46, 46, 54, 55, 56, 57, 51, 58, 58, 59,
    58, 60, 41, 0,  0,  9,  61, 9,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
    0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
    0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
    0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0};

/*Map glyph_ids to kern right classes*/
static const uint8_t kern_right_class_mapping[] = {
    0,  0,  1,  2,  0,  3,  4,  5,  2,  6,  7,  8,  9,  10, 9,  10, 11, 12,
    13, 14, 15, 16, 17, 12, 18, 19, 20, 21, 21, 0,  0,  0,  22, 23, 24, 25,
    23, 25, 25, 25, 23, 25, 25, 26, 25, 25, 25, 25, 23, 25, 23, 25, 3,  27,
    28, 29, 29, 30, 31, 32, 33, 34, 35, 0,  36, 0,  37, 38, 39, 39, 39, 0,
    39, 38, 40, 41, 38, 38, 42, 42, 39, 42, 39, 42, 43, 44, 45, 46, 46, 47,
    46, 48, 0,  0,  35, 9,  49, 9,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
    0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
    0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
    0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0};

/*Kern values between classes*/
static const int8_t kern_class_values[] = {
    0,  0,   0,   0,   0,   0,   0,   0,   0,   0,  0,   0,  1,   0,   0,   0,
    0,  1,   0,   0,   0,   0,   0,   0,   0,   0,  0,   0,  0,   0,   0,   0,
    0,  0,   0,   0,   0,   0,   0,   0,   0,   0,  0,   0,  0,   0,   0,   0,
    0,  0,   6,   0,   3,   -3,  0,   0,   0,   0,  -7,  -8, 1,   6,   3,   2,
    -5, 1,   6,   0,   5,   1,   4,   0,   0,   0,  0,   0,  0,   0,   0,   0,
    0,  0,   8,   1,   -1,  0,   0,   0,   0,   0,  0,   0,  0,   0,   0,   0,
    0,  3,   0,   -4,  0,   0,   0,   0,   0,   -3, 2,   3,  0,   0,   -1,  0,
    -1, 1,   0,   -1,  0,   -1,  -1,  -3,  0,   0,  0,   0,  -1,  0,   0,   -2,
    -2, 0,   0,   -1,  0,   -3,  0,   0,   0,   0,  0,   0,  0,   0,   0,   -1,
    -1, 0,   -2,  0,   -3,  0,   -15, 0,   0,   -3, 0,   3,  4,   0,   0,   -3,
    1,  1,   4,   3,   -2,  3,   0,   0,   -7,  0,  0,   0,  0,   0,   0,   0,
    0,  0,   0,   0,   -5,  0,   0,   0,   0,   0,  0,   0,  0,   0,   0,   0,
    0,  0,   0,   -3,  -2,  -6,  0,   -5,  -1,  0,  0,   0,  0,   0,   5,   0,
    -4, -1,  0,   0,   0,   -2,  0,   0,   -1,  -9, 0,   0,  0,   0,   0,   0,
    0,  0,   0,   0,   0,   -10, -1,  5,   0,   0,  0,   0,  0,   0,   0,   0,
    0,  0,   0,   0,   -5,  0,   0,   0,   0,   0,  0,   0,  0,   0,   0,   4,
    0,  1,   0,   0,   -3,  0,   0,   0,   0,   0,  0,   0,  0,   0,   0,   0,
    0,  0,   0,   0,   0,   0,   5,   1,   0,   0,  0,   0,  0,   0,   0,   0,
    0,  0,   0,   0,   0,   0,   0,   0,   0,   0,  0,   0,  0,   0,   0,   0,
    0,  0,   0,   0,   0,   0,   0,   0,   0,   0,  0,   0,  0,   0,   0,   0,
    -5, 0,   0,   0,   0,   0,   0,   0,   0,   0,  0,   0,  0,   0,   0,   0,
    0,  0,   0,   0,   0,   0,   0,   1,   3,   1,  4,   -1, 0,   0,   3,   -1,
    -4, -18, 1,   3,   3,   0,   -2,  0,   5,   0,  4,   0,  4,   0,   -12, 0,
    -2, 4,   0,   4,   -1,  3,   1,   0,   0,   0,  -1,  0,  0,   -2,  10,  0,
    10, 0,   4,   0,   5,   2,   2,   4,   0,   0,  0,   -5, 0,   0,   0,   0,
    0,  -1,  0,   1,   -2,  -2,  -3,  1,   0,   -1, 0,   0,  0,   -5,  0,   0,
    0,  0,   0,   0,   0,   0,   0,   0,   0,   -8, 0,   0,  0,   0,   0,   0,
    0,  0,   0,   0,   0,   0,   0,   0,   0,   0,  -7,  0,  -8,  0,   0,   0,
    0,  -1,  0,   13,  -2,  -2,  1,   1,   -1,  0,  -2,  1,  0,   0,   -7,  0,
    0,  0,   0,   0,   0,   0,   0,   0,   0,   0,  -12, 0,  1,   0,   0,   0,
    0,  0,   0,   0,   0,   0,   0,   0,   0,   -8, 0,   8,  0,   0,   -5,  0,
    4,  0,   -9,  -12, -9,  -3,  4,   0,   0,   -9, 0,   2,  -3,  0,   -2,  0,
    0,  0,   0,   0,   0,   0,   0,   0,   0,   0,  0,   3,  4,   -16, 0,   0,
    0,  0,   0,   0,   0,   0,   0,   0,   0,   0,  6,   0,  1,   0,   0,   0,
    0,  0,   1,   1,   -2,  -3,  0,   0,   0,   -1, 0,   0,  -1,  0,   0,   0,
    -3, 0,   -1,  0,   -3,  -3,  0,   -3,  -4,  -4, -2,  0,  -3,  0,   -3,  0,
    0,  0,   0,   -1,  0,   0,   1,   0,   1,   -1, 0,   0,  0,   0,   0,   1,
    -1, 0,   0,   0,   -1,  1,   1,   0,   0,   0,  0,   -2, 0,   0,   0,   0,
    0,  0,   0,   0,   0,   2,   -1,  0,   -2,  0,  -2,  0,  0,   -1,  0,   4,
    0,  0,   -1,  0,   0,   0,   0,   0,   0,   0,  -1,  -1, 0,   0,   -1,  0,
    -1, 0,   0,   0,   0,   0,   0,   0,   0,   0,  -1,  -1, 0,   -1,  -2,  0,
    0,  0,   0,   0,   0,   0,   0,   -1,  0,   -1, -1,  -1, 0,   0,   0,   0,
    0,  0,   0,   0,   0,   -1,  0,   0,   0,   0,  -1,  -2, 0,   -2,  0,   -4,
    -1, -4,  3,   0,   0,   -3,  1,   3,   3,   0,  -3,  0,  -2,  0,   0,   -6,
    1,  -1,  1,   -7,  1,   0,   0,   0,   -7,  0,  -7,  -1, -11, -1,  0,   -6,
    0,  3,   4,   0,   2,   0,   0,   0,   0,   0,  0,   -2, -2,  0,   -4,  0,
    0,  0,   -1,  0,   0,   0,   -1,  0,   0,   0,  0,   0,  -1,  -1,  0,   -1,
    -2, 0,   0,   0,   0,   0,   0,   0,   -1,  -1, 0,   -1, -2,  -1,  0,   0,
    -1, 0,   0,   0,   0,   0,   0,   0,   0,   0,  0,   0,  -1,  -1,  0,   -2,
    0,  -1,  0,   -3,  1,   0,   0,   -2,  1,   1,  1,   0,  0,   0,   0,   0,
    0,  -1,  0,   0,   0,   0,   0,   1,   0,   0,  -1,  0,  -1,  -1,  -2,  0,
    0,  0,   0,   0,   0,   0,   1,   0,   -1,  0,  0,   0,  0,   -1,  -2,  0,
    -2, 0,   4,   -1,  0,   -4,  0,   0,   3,   -6, -7,  -5, -3,  1,   0,   -1,
    -8, -2,  0,   -2,  0,   -3,  2,   -2,  -8,  0,  -3,  0,  0,   1,   0,   1,
    -1, 0,   1,   0,   -4,  -5,  0,   -6,  -3,  -3, -3,  -4, -2,  -3,  0,   -2,
    -3, 1,   0,   0,   0,   -1,  0,   0,   0,   1,  0,   1,  0,   0,   0,   0,
    0,  0,   0,   0,   0,   0,   0,   -1,  0,   -1, 0,   0,  -1,  0,   -2,  -3,
    -3, 0,   0,   -4,  0,   0,   0,   0,   0,   0,  -1,  0,  0,   0,   0,   1,
    -1, 0,   0,   0,   1,   0,   0,   0,   0,   0,  0,   0,  0,   6,   0,   0,
    0,  0,   0,   0,   1,   0,   0,   0,   -1,  0,  0,   0,  0,   0,   0,   0,
    0,  0,   0,   0,   -2,  0,   1,   0,   0,   0,  0,   0,  0,   0,   0,   0,
    0,  0,   0,   0,   -1,  0,   0,   0,   -2,  0,  0,   0,  0,   -6,  -4,  0,
    0,  0,   -2,  -6,  0,   0,   -1,  1,   0,   -3, 0,   0,  0,   0,   0,   0,
    0,  0,   0,   0,   -2,  0,   0,   -2,  0,   0,  0,   0,  0,   0,   0,   0,
    0,  0,   0,   0,   1,   0,   -2,  0,   0,   0,  0,   2,  0,   1,   -3,  -3,
    0,  -1,  -1,  -2,  0,   0,   0,   0,   0,   0,  -4,  0,  -1,  0,   -2,  -1,
    0,  -3,  -3,  -4,  -1,  0,   -3,  0,   -4,  0,  0,   0,  0,   10,  0,   0,
    1,  0,   0,   -2,  0,   1,   0,   -6,  0,   0,  0,   0,  0,   -12, -2,  4,
    4,  -1,  -5,  0,   1,   -2,  0,   -6,  -1,  -2, 1,   -9, -1,  2,   0,   2,
    -4, -2,  -5,  -4,  -5,  0,   0,   -8,  0,   7,  0,   0,  -1,  0,   0,   0,
    -1, -1,  -1,  -3,  -4,  0,   -12, 0,   0,   0,  0,   0,  0,   0,   0,   0,
    0,  0,   0,   0,   0,   0,   0,   0,   0,   0,  0,   0,  0,   0,   0,   0,
    0,  -1,  0,   -1,  -1,  -2,  0,   0,   -3,  0,  -1,  0,  0,   0,   0,   0,
    0,  0,   0,   0,   0,   0,   0,   0,   0,   0,  0,   0,  -3,  0,   0,   3,
    0,  2,   0,   -3,  1,   -1,  0,   -3,  -1,  0,  -2,  -1, -1,  0,   -2,  -2,
    0,  0,   -1,  0,   -1,  -2,  -2,  0,   0,   -1, 0,   1,  -1,  0,   -3,  0,
    0,  0,   -3,  0,   -2,  0,   -2,  -2,  1,   0,  0,   0,  0,   0,   0,   0,
    0,  -3,  1,   0,   -2,  0,   -1,  -2,  -4,  -1, -1,  -1, 0,   -1,  -2,  0,
    0,  0,   0,   0,   0,   -1,  -1,  -1,  0,   0,  0,   0,  2,   -1,  0,   -1,
    0,  0,   0,   -1,  -2,  -1,  -1,  -2,  -1,  0,  1,   5,  0,   0,   -3,  0,
    -1, 3,   0,   -1,  -5,  -2,  2,   0,   0,   -6, -2,  1,  -2,  1,   0,   -1,
    -1, -4,  0,   -2,  1,   0,   0,   -2,  0,   0,  0,   1,  1,   -3,  -2,  0,
    -2, -1,  -2,  -1,  -1,  0,   -2,  1,   -2,  -2, 4,   0,  0,   0,   0,   0,
    0,  0,   0,   0,   1,   0,   0,   0,   0,   0,  0,   0,  0,   0,   0,   0,
    0,  0,   0,   0,   0,   0,   0,   0,   0,   0,  0,   0,  -2,  0,   0,   0,
    0,  0,   0,   0,   0,   0,   0,   0,   0,   0,  0,   0,  0,   0,   0,   0,
    0,  0,   0,   0,   0,   0,   0,   0,   0,   0,  0,   0,  0,   0,   0,   0,
    0,  0,   0,   0,   0,   0,   0,   0,   -1,  0,  0,   0,  0,   0,   0,   0,
    0,  0,   0,   0,   0,   0,   0,   0,   0,   0,  0,   0,  0,   0,   0,   0,
    0,  0,   0,   0,   0,   0,   -1,  -1,  0,   0,  0,   0,  0,   0,   0,   0,
    0,  0,   0,   0,   -2,  0,   0,   -2,  0,   0,  -1,  -1, 0,   0,   0,   0,
    -1, 0,   0,   0,   0,   -1,  0,   0,   0,   0,  0,   -1, 0,   0,   0,   0,
    -2, 0,   -3,  0,   0,   0,   -4,  0,   1,   -3, 3,   0,  -1,  -6,  0,   0,
    -3, -1,  0,   -5,  -3,  -4,  0,   0,   -6,  -1, -5,  -5, -6,  0,   -3,  0,
    1,  9,   -2,  0,   -3,  -1,  0,   -1,  -2,  -3, -2,  -5, -5,  -3,  -1,  0,
    0,  -1,  0,   0,   0,   0,   -9,  -1,  4,   3,  -3,  -5, 0,   0,   -4,  0,
    -6, -1,  -1,  3,   -12, -2,  0,   0,   0,   -8, -2,  -7, -1,  -9,  0,   0,
    -9, 0,   8,   0,   0,   -1,  0,   0,   0,   0,  -1,  -1, -5,  -1,  0,   -8,
    0,  0,   0,   0,   -4,  0,   -1,  0,   0,   -4, -6,  0,  0,   -1,  -2,  -4,
    -1, 0,   -1,  0,   0,   0,   0,   -6,  -1,  -4, -4,  -1, -2,  -3,  -1,  -2,
    0,  -3,  -1,  -4,  -2,  0,   -2,  -2,  -1,  -2, 0,   1,  0,   -1,  -4,  0,
    3,  0,   -2,  0,   0,   0,   0,   2,   0,   1,  -3,  5,  0,   -1,  -1,  -2,
    0,  0,   0,   0,   0,   0,   -4,  0,   -1,  0,  -2,  -1, 0,   -3,  -3,  -4,
    -1, 0,   -3,  1,   5,   0,   0,   0,   0,   10, 0,   0,  1,   0,   0,   -2,
    0,  1,   0,   0,   0,   0,   0,   0,   0,   0,  0,   0,  0,   0,   0,   0,
    -1, -3,  0,   0,   0,   0,   0,   -1,  0,   0,  0,   -1, -1,  0,   0,   -3,
    -1, 0,   0,   -3,  0,   2,   -1,  0,   0,   0,  0,   0,  0,   1,   0,   0,
    0,  0,   2,   3,   1,   -1,  0,   -4,  -2,  0,  4,   -4, -4,  -3,  -3,  5,
    2,  1,   -11, -1,  3,   -1,  0,   -1,  1,   -1, -4,  0,  -1,  1,   -2,  -1,
    -4, -1,  0,   0,   4,   3,   0,   -4,  0,   -7, -2,  4,  -2,  -5,  0,   -2,
    -4, -4,  -1,  5,   1,   0,   -2,  0,   -3,  0,  1,   4,  -3,  -5,  -5,  -3,
    4,  0,   0,   -9,  -1,  1,   -2,  -1,  -3,  0,  -3,  -5, -2,  -2,  -1,  0,
    0,  -3,  -3,  -1,  0,   4,   3,   -1,  -7,  0,  -7,  -2, 0,   -4,  -7,  0,
    -4, -2,  -4,  -4,  3,   0,   0,   -2,  0,   -3, -1,  0,  -1,  -2,  0,   2,
    -4, 1,   0,   0,   -7,  0,   -1,  -3,  -2,  -1, -4,  -3, -4,  -3,  0,   -4,
    -1, -3,  -2,  -4,  -1,  0,   0,   0,   6,   -2, 0,   -4, -1,  0,   -1,  -3,
    -3, -3,  -4,  -5,  -2,  -3,  3,   0,   -2,  0,  -6,  -2, 1,   3,   -4,  -5,
    -3, -4,  4,   -1,  1,   -12, -2,  3,   -3,  -2, -5,  0,  -4,  -5,  -2,  -1,
    -1, -1,  -3,  -4,  0,   0,   0,   4,   4,   -1, -8,  0,  -8,  -3,  3,   -5,
    -9, -3,  -4,  -5,  -6,  -4,  3,   0,   0,   0,  0,   -2, 0,   0,   1,   -2,
    3,  1,   -2,  3,   0,   0,   -4,  0,   0,   0,  0,   0,  0,   -1,  0,   0,
    0,  0,   0,   0,   -1,  0,   0,   0,   0,   1,  4,   0,  0,   -2,  0,   0,
    0,  0,   -1,  -1,  -2,  0,   0,   0,   0,   1,  0,   0,  0,   0,   1,   0,
    -1, 0,   5,   0,   2,   0,   0,   -2,  0,   3,  0,   0,  0,   1,   0,   0,
    0,  0,   0,   0,   0,   0,   0,   0,   0,   4,  0,   4,  0,   0,   0,   0,
    0,  0,   0,   0,   0,   0,   0,   0,   0,   0,  -8,  0,  -1,  2,   0,   4,
    0,  0,   13,  2,   -3,  -3,  1,   1,   -1,  0,  -6,  0,  0,   6,   -8,  0,
    0,  0,   0,   0,   0,   0,   0,   0,   0,   0,  -9,  5,  18,  0,   0,   0,
    0,  0,   0,   0,   0,   0,   0,   0,   0,   -8, 0,   0,  0,   0,   0,   0,
    0,  0,   0,   0,   0,   0,   0,   0,   0,   0,  0,   0,  0,   0,   0,   0,
    0,  0,   0,   0,   -2,  0,   0,   -2,  -1,  0,  0,   0,  0,   0,   0,   0,
    0,  0,   0,   0,   0,   0,   0,   0,   0,   0,  0,   0,  -1,  0,   -3,  0,
    0,  0,   0,   0,   1,   17,  -3,  -1,  4,   3,  -3,  1,  0,   0,   1,   1,
    -2, 0,   0,   0,   0,   0,   0,   0,   0,   0,  0,   0,  -17, 4,   0,   0,
    0,  0,   0,   0,   0,   0,   0,   0,   0,   0,  0,   0,  0,   0,   0,   -4,
    0,  0,   0,   -3,  0,   0,   0,   0,   -3,  -1, 0,   0,  0,   -3,  0,   -2,
    0,  -6,  0,   0,   0,   0,   0,   0,   0,   0,  0,   0,  0,   -9,  0,   0,
    0,  0,   0,   0,   0,   0,   0,   0,   0,   -1, 0,   0,  -2,  0,   -2,  0,
    -3, 0,   0,   0,   -2,  1,   -2,  0,   0,   -3, -1,  -3, 0,   0,   -3,  0,
    -1, 0,   -6,  0,   -1,  0,   0,   -10, -2,  -5, -1,  -5, 0,   0,   -9,  0,
    -3, -1,  0,   0,   0,   0,   0,   0,   0,   0,  -2,  -2, -1,  -2,  0,   0,
    0,  0,   -3,  0,   -3,  2,   -1,  3,   0,   -1, -3,  -1, -2,  -2,  0,   -2,
    -1, -1,  1,   -3,  0,   0,   0,   0,   -11, -1, -2,  0,  -3,  0,   -1,  -6,
    -1, 0,   0,   -1,  -1,  0,   0,   0,   0,   1,  0,   -1, -2,  -1,  2,   0,
    0,  0,   0,   0,   0,   0,   0,   0,   0,   0,  0,   0,  0,   0,   0,   0,
    0,  0,   0,   0,   0,   0,   0,   0,   0,   0,  0,   0,  0,   0,   0,   0,
    0,  0,   0,   0,   0,   0,   0,   0,   0,   0,  2,   0,  0,   0,   0,   0,
    0,  -3,  0,   -1,  0,   0,   0,   -3,  1,   0,  0,   0,  -3,  -1,  -3,  0,
    0,  -4,  0,   -1,  0,   -6,  0,   0,   0,   0,  -12, 0,  -3,  -5,  -6,  0,
    0,  -9,  0,   -1,  -2,  0,   0,   0,   0,   0,  0,   0,  0,   -1,  -2,  -1,
    -2, 0,   0,   0,   2,   -2,  0,   4,   6,   -1, -1,  -4, 2,   6,   2,   3,
    -3, 2,   5,   2,   4,   3,   3,   0,   0,   0,  0,   0,  0,   0,   0,   0,
    0,  0,   8,   6,   -2,  -1,  0,   -1,  10,  6,  10,  0,  0,   0,   1,   0,
    0,  5,   0,   0,   -2,  0,   0,   0,   0,   0,  0,   0,  0,   0,   -1,  0,
    0,  0,   0,   0,   0,   0,   0,   2,   0,   0,  0,   0,  -11, -2,  -1,  -5,
    -6, 0,   0,   -9,  0,   0,   0,   0,   0,   0,  0,   0,  0,   0,   0,   0,
    0,  0,   0,   0,   0,   -2,  0,   0,   0,   0,  0,   0,  0,   0,   0,   -1,
    0,  0,   0,   0,   0,   0,   0,   0,   2,   0,  0,   0,  0,   -11, -2,  -1,
    -5, -6,  0,   0,   -5,  0,   0,   0,   0,   0,  0,   0,  0,   0,   0,   0,
    0,  0,   0,   0,   0,   0,   0,   0,   -1,  0,  0,   0,  -3,  1,   0,   -1,
    1,  2,   1,   -4,  0,   0,   -1,  1,   0,   1,  0,   0,  0,   0,   -3,  0,
    -1, -1,  -3,  0,   -1,  -5,  0,   8,   -1,  0,  -3,  -1, 0,   -1,  -2,  0,
    -1, -4,  -3,  -2,  0,   0,   0,   -2,  0,   0,  0,   0,  0,   0,   0,   0,
    0,  -1,  0,   0,   0,   0,   0,   0,   0,   0,  2,   0,  0,   0,   0,   -11,
    -2, -1,  -5,  -6,  0,   0,   -9,  0,   0,   0,  0,   0,  0,   6,   0,   0,
    0,  0,   0,   0,   0,   0,   0,   0,   -2,  0,  -4,  -2, -1,  4,   -1,  -1,
    -5, 0,   -1,  0,   -1,  -3,  0,   3,   0,   1,  0,   1,  -3,  -5,  -2,  0,
    -5, -2,  -3,  -5,  -5,  0,   -2,  -3,  -2,  -2, -1,  -1, -2,  -1,  0,   -1,
    0,  2,   0,   2,   -1,  0,   4,   0,   0,   0,  0,   0,  0,   0,   0,   0,
    0,  0,   0,   -1,  -1,  -1,  0,   0,   -3,  0,  -1,  0,  -2,  0,   0,   0,
    0,  0,   0,   0,   0,   0,   0,   0,   -8,  0,  0,   0,  0,   0,   0,   0,
    0,  0,   0,   0,   -1,  -1,  0,   -2,  0,   0,  0,   0,  -1,  0,   0,   -2,
    -1, 1,   0,   -2,  -2,  -1,  0,   -4,  -1,  -3, -1,  -2, 0,   -2,  0,   0,
    0,  0,   0,   0,   0,   0,   0,   0,   0,   -9, 0,   4,  0,   0,   -2,  0,
    0,  0,   0,   -2,  0,   -1,  0,   0,   -1,  0,  0,   -1, 0,   -3,  0,   0,
    5,  -2,  -4,  -4,  1,   1,   1,   0,   -4,  1,  2,   1,  4,   1,   4,   -1,
    -3, 0,   0,   -5,  0,   0,   -4,  -3,  0,   0,  -3,  0,  -2,  -2,  0,   -2,
    0,  -2,  0,   -1,  2,   0,   -1,  -4,  -1,  5,  0,   0,  -1,  0,   -3,  0,
    0,  2,   -3,  0,   1,   -1,  1,   0,   0,   -4, 0,   -1, 0,   0,   -1,  1,
    -1, 0,   0,   0,   -5,  -2,  -3,  0,   -4,  0,  0,   -6, 0,   5,   -1,  0,
    -2, 0,   1,   0,   -1,  0,   -1,  -4,  0,   -1, 1,   0,  0,   0,   0,   -1,
    0,  0,   1,   -2,  0,   0,   0,   -2,  -1,  0,  -2,  0,  0,   0,   0,   0,
    0,  0,   0,   0,   0,   0,   0,   0,   0,   0,  0,   0,  -8,  0,   3,   0,
    0,  -1,  0,   0,   0,   0,   0,   0,   -1,  -1, 0,   0,  0,   3,   0,   3,
    0,  0,   0,   0,   0,   -8,  -7,  0,   6,   4,  2,   -5, 1,   5,   0,   5,
    0,  3,   0,   0,   0,   0,   0,   0,   0,   0,  0,   0,  0,   7,   0,   0,
    0,  0,   0,   0,   0,   0,   0,   0,   0,   0,  0,   0,  0};

/*Collect the kern class' data in one place*/
static const lv_font_fmt_txt_kern_classes_t kern_classes = {
    .class_pair_values = kern_class_values,
    .left_class_mapping = kern_left_class_mapping,
    .right_class_mapping = kern_right_class_mapping,
    .left_class_cnt = 61,
    .right_class_cnt = 49,
};

/*--------------------
 *  ALL CUSTOM DATA
 *--------------------*/

/*Store all the custom data of the font*/
static lv_font_fmt_txt_dsc_t font_dsc = {.glyph_bitmap = gylph_bitmap,
                                         .glyph_dsc = glyph_dsc,
                                         .cmaps = cmaps,
                                         .kern_dsc = &kern_classes,
                                         .kern_scale = 16,
                                         .cmap_num = 2,
                                         .bpp = 4,
                                         .kern_classes = 1,
                                         .bitmap_format = 0};

/*-----------------
 *  PUBLIC FONT
 *----------------*/

/*Initialize a public general font descriptor*/
lv_font_t font_2 = {
    .get_glyph_dsc =
        lv_font_get_glyph_dsc_fmt_txt, /*Function pointer to get glyph's data*/
    .get_glyph_bitmap =
        lv_font_get_bitmap_fmt_txt, /*Function pointer to get glyph's bitmap*/
    .line_height = 10, /*The maximum line height required by the font*/
    .base_line = 2,    /*Baseline measured from the bottom of the line*/
#if !(LVGL_VERSION_MAJOR == 6 && LVGL_VERSION_MINOR == 0)
    .subpx = LV_FONT_SUBPX_NONE,
#endif
    .dsc = &font_dsc /*The custom font data. Will be accessed by
                        `get_glyph_bitmap/dsc` */
};

#endif /*#if FONT_2*/
#endif

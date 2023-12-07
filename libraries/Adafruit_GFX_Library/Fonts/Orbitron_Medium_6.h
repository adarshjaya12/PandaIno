// Created by http://oleddisplay.squix.ch/ Consider a donation
// In case of problems make sure that you are using the font file with the correct version!
const uint8_t Orbitron_Medium_6Bitmaps[] PROGMEM = {

	// Bitmap Data:
	0x00, // ' '
	0xF0, // '!'
	0xC0, // '"'
	0xFA,0xBD,0x40, // '#'
	0x27,0xFC,0x5F,0x10, // '$'
	0xE9,0x43,0xD6, // '%'
	0xFA,0x2F,0xF0, // '&'
	0x80, // '''
	0xF0, // '('
	0xF0, // ')'
	0xF8, // '*'
	0x5C, // '+'
	0xC0, // ','
	0xE0, // '-'
	0x80, // '.'
	0x29,0x40, // '/'
	0xFD,0xF3,0xF0, // '0'
	0xD5, // '1'
	0xFB,0xE1,0xF0, // '2'
	0xFB,0x83,0xF0, // '3'
	0x35,0xF1, // '4'
	0xFF,0x83,0xF0, // '5'
	0xF7,0xA3,0xF0, // '6'
	0xF1,0x11, // '7'
	0xFF,0xE3,0xF0, // '8'
	0xFF,0xC3,0xF0, // '9'
	0x90, // ':'
	0x98, // ';'
	0x2A,0x30, // '<'
	0xFC, // '='
	0x89,0xC0, // '>'
	0xF1,0x64, // '?'
	0xFF,0xEF,0xF0, // '@'
	0xFC,0x7F,0x10, // 'A'
	0xFF,0xA3,0xF0, // 'B'
	0xFC,0x21,0xF0, // 'C'
	0xFC,0x63,0xF0, // 'D'
	0xFF,0x8F, // 'E'
	0xFF,0x88, // 'F'
	0xFC,0xA3,0xF0, // 'G'
	0x8F,0xE3,0x10, // 'H'
	0xF0, // 'I'
	0x11,0x1F, // 'J'
	0x9F,0x29,0x30, // 'K'
	0x84,0x21,0xF0, // 'L'
	0xCD,0xEB,0x10, // 'M'
	0xCD,0x67,0x30, // 'N'
	0xFC,0x63,0xF0, // 'O'
	0xFC,0x7D,0x00, // 'P'
	0xFC,0x63,0xF0, // 'Q'
	0xFC,0x7D,0x30, // 'R'
	0xFF,0x83,0xF0, // 'S'
	0xF2,0x22, // 'T'
	0x8C,0x63,0xF0, // 'U'
	0xCD,0x23,0x0C, // 'V'
	0x92,0xD9,0xB1,0x20, // 'W'
	0xD9,0x19,0xB0, // 'X'
	0xDB,0x08,0x40, // 'Y'
	0xF9,0x11,0xF0, // 'Z'
	0xF0, // '['
	0x88,0x90, // '\'
	0xF0, // ']'
	0x00, // '^'
	0xF8, // '_'
	0x80, // '`'
	0xFF,0xF0, // 'a'
	0x8E,0x99,0xF0, // 'b'
	0xF8,0xF0, // 'c'
	0x17,0x99,0xF0, // 'd'
	0xFF,0xF0, // 'e'
	0x7A,0x80, // 'f'
	0xF9,0xF7, // 'g'
	0x8E,0x99,0x90, // 'h'
	0xB8, // 'i'
	0x45,0x70, // 'j'
	0x89,0xAE,0x90, // 'k'
	0xAA,0xC0, // 'l'
	0xFE,0x9A,0x40, // 'm'
	0xF9,0x90, // 'n'
	0xF9,0xF0, // 'o'
	0xF9,0xF8, // 'p'
	0xF9,0xF1, // 'q'
	0xF2,0x00, // 'r'
	0xF7,0xF0, // 's'
	0xBA,0xC0, // 't'
	0x99,0xF0, // 'u'
	0xDA,0x88, // 'v'
	0xB5,0xA4,0x80, // 'w'
	0xF6,0xD0, // 'x'
	0x99,0xF7, // 'y'
	0xF4,0xF0, // 'z'
	0xF0, // '{'
	0xFC, // '|'
	0xD6 // '}'
};
const GFXglyph Orbitron_Medium_6Glyphs[] PROGMEM = {
// bitmapOffset, width, height, xAdvance, xOffset, yOffset
	  {     0,   1,   1,   3,    0,   -1 }, // ' '
	  {     1,   1,   4,   2,    0,   -4 }, // '!'
	  {     2,   2,   1,   3,    0,   -4 }, // '"'
	  {     3,   5,   4,   6,    0,   -4 }, // '#'
	  {     6,   5,   6,   6,    0,   -5 }, // '$'
	  {    10,   6,   4,   7,    0,   -4 }, // '%'
	  {    13,   5,   4,   7,    0,   -4 }, // '&'
	  {    16,   1,   1,   2,    0,   -4 }, // '''
	  {    17,   1,   4,   3,    0,   -4 }, // '('
	  {    18,   1,   4,   3,    0,   -4 }, // ')'
	  {    19,   3,   2,   4,    0,   -4 }, // '*'
	  {    20,   3,   2,   4,    0,   -3 }, // '+'
	  {    21,   1,   2,   2,    0,   -1 }, // ','
	  {    22,   3,   1,   4,    0,   -2 }, // '-'
	  {    23,   1,   1,   2,    0,   -1 }, // '.'
	  {    24,   3,   4,   4,    0,   -4 }, // '/'
	  {    26,   5,   4,   6,    0,   -4 }, // '0'
	  {    29,   2,   4,   3,    0,   -4 }, // '1'
	  {    30,   5,   4,   6,    0,   -4 }, // '2'
	  {    33,   5,   4,   6,    0,   -4 }, // '3'
	  {    36,   4,   4,   5,    0,   -4 }, // '4'
	  {    38,   5,   4,   6,    0,   -4 }, // '5'
	  {    41,   5,   4,   6,    0,   -4 }, // '6'
	  {    44,   4,   4,   5,    0,   -4 }, // '7'
	  {    46,   5,   4,   6,    0,   -4 }, // '8'
	  {    49,   5,   4,   6,    0,   -4 }, // '9'
	  {    52,   1,   4,   2,    0,   -4 }, // ':'
	  {    53,   1,   5,   2,    0,   -4 }, // ';'
	  {    54,   3,   4,   4,    0,   -4 }, // '<'
	  {    56,   3,   2,   5,    0,   -3 }, // '='
	  {    57,   3,   4,   4,    0,   -4 }, // '>'
	  {    59,   4,   4,   5,    0,   -4 }, // '?'
	  {    61,   5,   4,   6,    0,   -4 }, // '@'
	  {    64,   5,   4,   6,    0,   -4 }, // 'A'
	  {    67,   5,   4,   6,    0,   -4 }, // 'B'
	  {    70,   5,   4,   6,    0,   -4 }, // 'C'
	  {    73,   5,   4,   6,    0,   -4 }, // 'D'
	  {    76,   4,   4,   6,    0,   -4 }, // 'E'
	  {    78,   4,   4,   5,    0,   -4 }, // 'F'
	  {    80,   5,   4,   6,    0,   -4 }, // 'G'
	  {    83,   5,   4,   6,    0,   -4 }, // 'H'
	  {    86,   1,   4,   2,    0,   -4 }, // 'I'
	  {    87,   4,   4,   6,    0,   -4 }, // 'J'
	  {    89,   5,   4,   6,    0,   -4 }, // 'K'
	  {    92,   5,   4,   6,    0,   -4 }, // 'L'
	  {    95,   5,   4,   7,    0,   -4 }, // 'M'
	  {    98,   5,   4,   6,    0,   -4 }, // 'N'
	  {   101,   5,   4,   6,    0,   -4 }, // 'O'
	  {   104,   5,   4,   6,    0,   -4 }, // 'P'
	  {   107,   5,   4,   6,    0,   -4 }, // 'Q'
	  {   110,   5,   4,   6,    0,   -4 }, // 'R'
	  {   113,   5,   4,   6,    0,   -4 }, // 'S'
	  {   116,   4,   4,   6,    0,   -4 }, // 'T'
	  {   118,   5,   4,   6,    0,   -4 }, // 'U'
	  {   121,   6,   4,   7,    0,   -4 }, // 'V'
	  {   124,   7,   4,   8,    0,   -4 }, // 'W'
	  {   128,   5,   4,   6,    0,   -4 }, // 'X'
	  {   131,   5,   4,   6,    0,   -4 }, // 'Y'
	  {   134,   5,   4,   6,    0,   -4 }, // 'Z'
	  {   137,   1,   4,   3,    0,   -4 }, // '['
	  {   138,   3,   4,   4,    0,   -4 }, // '\'
	  {   140,   1,   4,   3,    0,   -4 }, // ']'
	  {   141,   1,   1,   1,    0,   -1 }, // '^'
	  {   142,   5,   1,   6,    0,    0 }, // '_'
	  {   143,   1,   1,   2,    0,   -6 }, // '`'
	  {   144,   4,   3,   5,    0,   -3 }, // 'a'
	  {   146,   4,   5,   5,    0,   -5 }, // 'b'
	  {   149,   4,   3,   5,    0,   -3 }, // 'c'
	  {   151,   4,   5,   5,    0,   -5 }, // 'd'
	  {   154,   4,   3,   5,    0,   -3 }, // 'e'
	  {   156,   2,   5,   3,    0,   -5 }, // 'f'
	  {   158,   4,   4,   5,    0,   -3 }, // 'g'
	  {   160,   4,   5,   5,    0,   -5 }, // 'h'
	  {   163,   1,   5,   2,    0,   -5 }, // 'i'
	  {   164,   2,   6,   2,   -1,   -5 }, // 'j'
	  {   166,   4,   5,   5,    0,   -5 }, // 'k'
	  {   169,   2,   5,   3,    0,   -5 }, // 'l'
	  {   171,   6,   3,   7,    0,   -3 }, // 'm'
	  {   174,   4,   3,   5,    0,   -3 }, // 'n'
	  {   176,   4,   3,   5,    0,   -3 }, // 'o'
	  {   178,   4,   4,   5,    0,   -3 }, // 'p'
	  {   180,   4,   4,   5,    0,   -3 }, // 'q'
	  {   182,   3,   3,   4,    0,   -3 }, // 'r'
	  {   184,   4,   3,   5,    0,   -3 }, // 's'
	  {   186,   2,   5,   3,    0,   -5 }, // 't'
	  {   188,   4,   3,   5,    0,   -3 }, // 'u'
	  {   190,   5,   3,   6,    0,   -3 }, // 'v'
	  {   192,   6,   3,   7,    0,   -3 }, // 'w'
	  {   195,   4,   3,   5,    0,   -3 }, // 'x'
	  {   197,   4,   4,   5,    0,   -3 }, // 'y'
	  {   199,   4,   3,   5,    0,   -3 }, // 'z'
	  {   201,   1,   4,   3,    0,   -4 }, // '{'
	  {   202,   1,   6,   2,    0,   -5 }, // '|'
	  {   203,   2,   4,   3,    0,   -4 } // '}'
};
const GFXfont Orbitron_Medium_6 PROGMEM = {
(uint8_t  *)Orbitron_Medium_6Bitmaps,(GFXglyph *)Orbitron_Medium_6Glyphs,0x20, 0x7E, 7};
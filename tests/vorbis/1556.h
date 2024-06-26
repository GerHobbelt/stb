/* https://github.com/nothings/stb/pull/1556 */
/* build with UBSAN.

/src/stb/tests/../stb_vorbis.c:4107:10: runtime error: index 15 out of bounds for type 'uint8[15]' (aka 'unsigned char[15]')
SUMMARY: UndefinedBehaviorSanitizer: undefined-behavior /src/stb/tests/../stb_vorbis.c:4107:10 in
*/
#include "../../stb_vorbis.c"
#include <stdint.h>

int test_1556()
{
    const uint8_t data[] = {0x4f,0x67,0x67,0x53,0x00,0x02,0x01,0x5a,0x81,
                            0x15,0x9c,0x00,0x00,0xbe,0x21,0x68,0x00,0x00,
                            0x00,0x00,0x00,0x00,0xa2,0x64,0x89,0x6f,0x01,
                            0x1e,0x01,0x76,0x6f,0x72,0x62,0x69,0x73,0x00,
                            0x00,0x00,0x00,0x0e,0x31,0x1e,0x01,0x76,0x6f,
                            0x72,0xe3,0x12,0x02,0x62,0x69,0x20,0xd7,0x73,
                            0x06,0xd0,0x97,0x75,0x4f,0x67,0x67,0x53,0x00,
                            0x9c,0x00,0xfc,0x00,0x4b,0x02,0x2d,0x24,0x00,
                            0x21,0x68,0x00,0x00,0x01,0x00,0x00,0x00,0xff,
                            0xff,0xff,0x05,0x05,0x16,0x3e,0x16,0x01,0x01,
                            0x03,0x76,0x6f,0x72,0x62,0x69,0x73,0x00,0x00,
                            0x00,0x00,0x00,0x00,0x00,0x00,0x27,0x04,0x00,
                            0x7b,0x0b,0x12,0x0d,0x05,0x76,0x6f,0x72,0x62,
                            0x69,0x73,0x00,0x42,0x43,0x56,0x27,0x01,0x04,
                            0x00,0x00,0x04,0x20,0x04,0x00,0x00,0x00,0x40,
                            0x00,0x00,0x50,0x00,0x01,0x00,0x00,0x81,0x00,
                            0x00,0x08,0xd2,0x00,0x00,0x00,0x00,0x00,0x00,
                            0x00,0x80,0x0f,0x20,0x10,0x28,0x30,0x18,0x15,
                            0x15,0x15,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
                            0x00,0x00,0x00,0x00,0x8a,0x8a,0xff,0x00};
    int size = (int)sizeof(data);

    stb_vorbis* out = stb_vorbis_open_memory(data, size, NULL, NULL);
    stb_vorbis_close(out);
    return 0;
}

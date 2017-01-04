/****************************************************************************
 * Copyright (C) 2015 Dimok
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 ****************************************************************************/
#include <malloc.h>
#include <string.h>
#include "ShaderFractalColor.h"

static const u32 cpVertexShaderProgram[] =
{
    0x00000000,0x00008009,0x20000000,0x0000eca1,
    0x00c00000,0x88068093,0x01400200,0x9a048013,
    0x9c000000,0x000044a0,0x3c200000,0x88060094,
    0x02400000,0x88062014,0x00000000,0x00000000,
    0x00000000,0x00000000,0x00000000,0x00000000,
    0x00000000,0x00000000,0x00000000,0x00000000,
    0x00000000,0x00000000,0x00000000,0x00000000,
    0x00000000,0x00000000,0x00000000,0x00000000,
    0x00000000,0x00000000,0x00000000,0x00000000,
    0x00000000,0x00000000,0x00000000,0x00000000,
    0x00000000,0x00000000,0x00000000,0x00000000,
    0x00000000,0x00000000,0x00000000,0x00000000,
    0x00000000,0x00000000,0x00000000,0x00000000,
    0x00000000,0x00000000,0x00000000,0x00000000,
    0x00000000,0x00000000,0x00000000,0x00000000,
    0x00000000,0x00000000,0x00000000,0x00000000,
    0x0765a101,0x9000e00f,0x0761a101,0x9000e02f,
    0x03001f00,0x900c8040,0x03041f80,0x900c8060,
    0x076da101,0x9000e04f,0x0769a181,0x9000e06f,
    0x0745a101,0x9000c00f,0x0741a181,0x9000c02f,
    0x074da101,0x9000c04f,0x0749a181,0x9000c06f,
    0x0bc9a000,0x7f00e20f,0x0bc92080,0x7f04e22f,
    0x0bc9a001,0x7f08e24f,0x0bc92081,0x7f0ce26f,
    0x0725a101,0x9000a00f,0x0721a181,0x9000a02f,
    0x072da101,0x9000a04f,0x0729a181,0x9000a06f,
    0x0ac9a000,0x7e00c20f,0x0ac92080,0x7e04c22f,
    0x0ac9a001,0x7e08c24f,0x0ac92081,0x7e0cc26f,
    0x0ba5a000,0x7f00e20f,0x0ba52080,0x7f04e22f,
    0x0ba5a001,0x7f08e24f,0x0ba52081,0x7f0ce26f,
    0x08eda000,0x9000800f,0x08ed2080,0x9000802f,
    0x08eda001,0x9000804f,0x08ed2081,0x9000806f,
    0x09c9a000,0x7d00a20f,0x09c92080,0x7d04a22f,
    0x09c9a001,0x7d08a24f,0x09c92081,0x7d0ca26f,
    0x0aa5a000,0x7e00c20f,0x0aa52080,0x7e04c22f,
    0x0aa5a001,0x7e08c24f,0x0aa52081,0x7e0cc26f,
    0x0b81a000,0x7f006200,0x0b812080,0x7f046220,
    0x0b81a001,0x7f080240,0x0b812081,0x7f0c0260,
    0x08c9a000,0x7c00820f,0x08c92080,0x7c04822f,
    0x08c9a001,0x7c08824f,0x08c92081,0x7c0c826f,
    0x09a5a000,0x7d00a20f,0x09a52080,0x7d04a22f,
    0x09a5a001,0x7d08a24f,0x09a52081,0x7d0ca26f,
    0x0a81a000,0x7e008200,0x0a812080,0x7e048220,
    0x0a81a001,0x7e086240,0x0a812081,0x7e0c4260,
    0x0340a001,0x9000c00f,0x0344a001,0x9000c02f,
    0x0048a001,0x9000c04f,0x004ca001,0x9000c06f,
    0x0364a081,0x9000e02f,0x0360a001,0x9000e00f,
    0x0324a001,0x90000020,0x0068a001,0x9000e04f,
    0x006ca001,0x9000e06f,0x0320a081,0x90000000,
    0x08a5a000,0x7c00820f,0x08a52080,0x7c04822f,
    0x08a5a001,0x7c08824f,0x08a52081,0x7c0c826f,
    0x0981a000,0x7d00a200,0x09812080,0x7d04a220,
    0x0981a001,0x7d08a240,0x09812081,0x7d0c6260,
    0x02890000,0x7e00c20f,0x02898000,0x7e04c22f,
    0x0028a001,0x9000a04f,0x002ca001,0x9000c06f,
    0x02498081,0x7e0caa6f,0x03890000,0x7f00e20f,
    0x03898000,0x7f04e22f,0x02690001,0x7e08f64f,
    0x03498001,0x7f0ce26f,0x03690081,0x7f08ca4f,
    0x0881a000,0x7c00c200,0x08812080,0x7c04c220,
    0x0881a001,0x7c08e240,0x08812081,0x7c0ca260,
    0x0300a001,0x9000800f,0x0304a001,0x9000802f,
    0x0008a001,0x9000804f,0x000ca001,0x9000806f,
    0x01898080,0x0004aa2f,0x01890000,0x0000a20f,
    0x02a58000,0x7e04c22f,0x01690001,0x7d08a24f,
    0x01498081,0x7e0cc26f,0x02a50000,0x7e00f60f,
    0x03a58000,0x7f04622f,0x02a50001,0x7f08e24f,
    0x02658001,0x7d0ca26f,0x03a50080,0x7f00ca0f,
    0x00890000,0x7c00820f,0x00898000,0x7c049220,
    0x03a50001,0x7e08c24f,0x03658001,0x7f0ce26f,
    0x03c18080,0xfe04862f,0x01a50000,0x7d008200,
    0x01a58000,0x7d04622f,0x00690001,0x7c086240,
    0x00498081,0x7c0c4260,0x02c10000,0x7f00e20f,
    0x02c18000,0x7e04c62f,0x01a50001,0x7d080240,
    0x01658001,0x7e0c0260,0x01c18080,0xfe040620,
    0x03c10000,0x7e00620f,0x03a18001,0x7f0c622f,
    0x02e10001,0x7f08764f,0x02a18001,0x7d0c766f,
    0x03e10081,0x7e084a0f,0x02e80f00,0xfe000e00,
    0x02c88f00,0x7c046220,0x02c81f01,0xff00c240,
    0x02c89f01,0xfe04c260,0x00a50080,0x7c00aa00,
    0x01c10000,0x0400760f,0x00a58000,0x0404622f,
    0x00a50001,0x0308e24f,0x00658001,0x020c626f,
    0x00c10080,0x0500ea0f,0x02c41f00,0x0000620f,
    0x00c18000,0xfe04c22f,0x01e10001,0x0008624f,
    0x01a18001,0x000c666f,0x00a18081,0xfe0ce66f,
    0x00e10001,0x7f08620f,0x02048000,0x03046a2f,
    0x02c41f01,0x06086a4f,0x02c49f01,0x060c6a6f,
    0x02e00f80,0xfe000220,0x02c08f00,0xfe040200,
    0x02e08f01,0xfe0c0240,0x02c01f80,0xfe080260,
    0x8aa480ad,0x2bfc5ca6,0xb5e05b5b,0xd48dc71c
};

static const u32 cpVertexShaderRegs[] = {
    0x00000108,0x00000000,0x00000004,0x00000001,
    0xff000201,0xffffffff,0xffffffff,0xffffffff,
    0xffffffff,0xffffffff,0xffffffff,0xffffffff,
    0xffffffff,0xffffffff,0x00000000,0xfffffff8,
    0x00000003,0x00000001,0x00000000,0x00000002,
    0x000000ff,0x000000ff,0x000000ff,0x000000ff,
    0x000000ff,0x000000ff,0x000000ff,0x000000ff,
    0x000000ff,0x000000ff,0x000000ff,0x000000ff,
    0x000000ff,0x000000ff,0x000000ff,0x000000ff,
    0x000000ff,0x000000ff,0x000000ff,0x000000ff,
    0x000000ff,0x000000ff,0x000000ff,0x000000ff,
    0x000000ff,0x000000ff,0x000000ff,0x000000ff,
    0x000000ff,0x00000000,0x0000000e,0x00000010
};

static const u32 cpPixelShaderProgram[] =
{
    0x20000000,0x000008a4,0x04000000,0x01004085,
    0x23000000,0x0000eca1,0x9f000000,0x0000e0a8,
    0xd8000000,0x000000a4,0x07000000,0x01004085,
    0xd9000000,0x000048a8,0xec000000,0x000000a4,
    0x0a000000,0x01004085,0xed000000,0x000050a8,
    0x02010000,0x000030a0,0x00000000,0x88062094,
    0x00000000,0x00000000,0x00000000,0x00000000,
    0x00000000,0x00000000,0x00000000,0x00000000,
    0x00000000,0x00000000,0x00000000,0x00000000,
    0x00000000,0x00000000,0x00000000,0x00000000,
    0x00000000,0x00000000,0x00000000,0x00000000,
    0x00000000,0x00000000,0x00000000,0x00000000,
    0x00000000,0x00000000,0x00000000,0x00000000,
    0x00000000,0x00000000,0x00000000,0x00000000,
    0x00000000,0x00000000,0x00000000,0x00000000,
    0x00000000,0x00000000,0x00000000,0x00000000,
    0xfd001f80,0x900c0060,0x0000803f,0x00000000,
    0x03011f80,0x8c210000,0xfd001f00,0x900c0000,
    0xfd001f00,0x900ca02f,0x00000002,0x80020040,
    0x00048002,0x80020060,0xf8001f80,0x900cc04f,
    0x0000803f,0x00000000,0xfea81f00,0x9000e00f,
    0xfeac1f00,0x9000e02f,0xf8001f00,0x900c804f,
    0xf8001f80,0x900ca06f,0x00000040,0x00000000,
    0xfea01f00,0x00280000,0xfea41f00,0x00280020,
    0xfe041f00,0x00280040,0xfd041f80,0x00280060,
    0xaf67bb3e,0x00000080,0x7fc41f00,0x00000000,
    0x7fc01f80,0x00000020,0xfe041f00,0x100ac00f,
    0xfe001f80,0x100ac02f,0xfea01f00,0x00280000,
    0xfea41f00,0x00280020,0xfe041f00,0x00280040,
    0xfd041f00,0x1028e06f,0x7fc01f82,0x00000000,
    0x8c65583e,0x00000080,0x7ea41f00,0x80000000,
    0x7ea01f00,0x80000020,0xfee01f00,0x10006040,
    0x7fc48f82,0x00000860,0xa7c4623b,0x00000000,
    0xfea81f00,0x1000e00f,0x7fcc9f01,0x10006020,
    0xfe001f00,0x000a0040,0xfe041f00,0x000a0060,
    0xfea89f80,0x10008040,0x8c65583e,0x3acd13bf,
    0xfeb81f00,0x7e04c20f,0xfebc1f00,0x7e00822f,
    0x03c89f00,0x80060040,0xfea49f00,0x1000e06f,
    0xfea41f81,0x10006060,0x00809043,0x8c65583e,
    0x3acd13bf,0x00000000,0xfea81f00,0xf880a30f,
    0xfe001f00,0x900ca02f,0x7dc41f00,0x1000e04f,
    0xfe081f00,0xfd80636f,0x04081f80,0x900c800f,
    0x0000803f,0x00000000,0xfea81f00,0xf900620f,
    0xfea41f00,0xf900622f,0xfe0c1f00,0x900ca04f,
    0xfec00f00,0x1000c46f,0xfefc0f80,0x10006000,
    0x00000842,0x00000000,0xfeac1f00,0xf900620f,
    0x7fc81f00,0x9000c02f,0x7dc49f00,0x9000e04f,
    0x7df08f01,0x10008060,0x030c1f80,0x900ca02f,
    0x00000842,0x00000000,0xfea41f00,0x80000000,
    0x7ecc1f00,0x9000e02f,0x7e688000,0x80000040,
    0xfea81f00,0x80000060,0x7d6c8081,0x80000000,
    0xa7c4623b,0x00000000,0xfe001f00,0x000a0000,
    0xfe0c1f00,0x000a0020,0xfea41f00,0x80000040,
    0x03648000,0xfe08626f,0x7d648081,0xff00420f,
    0xa7c4623b,0x00000000,0xfeb01f00,0x7e04620f,
    0xfeb41f00,0x7f08662f,0x7c800001,0xff006e4f,
    0xfe081f00,0x000a0060,0x03680081,0xfe0c4e0f,
    0x00809043,0x00000000,0xfebc1f00,0x7f04620f,
    0x7cc41f00,0x00000020,0x7cc49f00,0x1000e04f,
    0xff901f00,0x00000060,0xfe981f80,0x00000000,
    0x00809043,0x00000000,0xfea81f00,0xf900620f,
    0x7cc41f00,0x00000020,0x00c09f00,0x1000c04f,
    0xfe0c1f00,0x80010060,0xff001f80,0x80010000,
    0x00000842,0x00000000,0xfea81f00,0xf900620f,
    0xfecc9f01,0x80000020,0x7fc81f00,0x9000e04f,
    0x7dc89f00,0x1000c86f,0xffe01f80,0x80000000,
    0x00000842,0x00000000,0xfeac1f00,0xf900620f,
    0x7ec81f00,0x9000802f,0xfec49f00,0x9000a040,
    0xfea89f00,0x80000060,0xffe01f80,0x9000a060,
    0x00000842,0xa7c4623b,0xfea41f00,0x80000000,
    0x7ecc1f00,0x9000e02f,0xfe0c1f00,0x000a0040,
    0x7c888081,0x80000000,0xa7c4623b,0x00000000,
    0xfe001f00,0x000a0000,0xfeb81f00,0x7f08622f,
    0xfea49f00,0x80000040,0x048c8081,0xff00420f,
    0x00809043,0xa7c4623b,0xfeb01f00,0x7c04620f,
    0x03600000,0xff00622f,0xfea49f00,0x80000040,
    0xfe081f80,0x000a0060,0x00809043,0x0ccec73c,
    0xfebc1f00,0x7f040200,0xfea09f00,0x90000020,
    0xfe941f00,0x10000040,0xfe081f80,0x30080060,
    0x00809043,0x0ccec73c,0x00041f00,0x20080000,
    0x00a01f00,0x80000020,0x002c1f02,0x1000e04f,
    0x00081f80,0x80010060,0x0ccec73c,0x00000000,
    0xfe201f02,0x1000800f,0xfec81f03,0x80020020,
    0xfe041f00,0x20080040,0xfe881f00,0x00000060,
    0xfecc9f81,0x9000a06f,0xfe0c1f00,0x000a0000,
    0xfe801f00,0x00000020,0xfec01f02,0x80020040,
    0xfe281f02,0x1000c06f,0xfe841f82,0x1000804f,
    0xfe041f00,0x000a0000,0x7fc81f02,0x00000020,
    0xfe8c1f00,0x00000040,0xfecc9f03,0x80020060,
    0xfe881f82,0x1000a00f,0x7cc01f02,0x00000000,
    0xfe8c1f02,0x1000e02f,0xfec49f00,0x80000040,
    0xfe081f00,0x000a0060,0x03c89f80,0x9000e04f,
    0x7ecc9f03,0x00000000,0xfec01f00,0x80000020,
    0x04c81f00,0x80000040,0x7c880f01,0xfe086a6f,
    0x7dac8f81,0x9000800f,0x7da00f00,0xfe04620f,
    0xfec01f00,0x80000020,0x03c01f00,0x80000840,
    0x03ac0f00,0xfe08c66f,0xfebc9f80,0xfd00420f,
    0xe07be53f,0x5c8e5a3f,0xfeb09f00,0xfd00620f,
    0x05e81f00,0x9000f02f,0x7fe48f00,0xfe04624f,
    0x04ec8f00,0xfe08626f,0x03840f81,0x7f08a20f,
    0xe07be53f,0x5c8e5a3f,0x7e0c1f00,0x900ce00f,
    0xfe0c1f00,0x900c802f,0x05cc1f00,0x9000e84f,
    0xfeb89f80,0xfd00626f,0xe07be53f,0x5c8e5a3f,
    0x7cc09f81,0x80000020,0x7fa40f00,0x00280000,
    0xfe848f00,0x00280020,0x7fe80f00,0x00280440,
    0xfd001f80,0x00280060,0x00000080,0x00000000,
    0xfdc01f80,0xf800620f,0x00000243,0x00000000,
    0xfea01f80,0x90000060,0x5555d53f,0x00000000,
    0x02011f80,0x8c110000,0x02448002,0x80020000,
    0xf8402000,0x9006a02f,0x02552081,0x00000040,
    0xfe301f00,0x1000e06f,0xfe081f80,0x1033c02f,
    0xfe4c2081,0x80060040,0xfee88f81,0x0289e32f,
    0x02c59f80,0x80060000,0xfee08f80,0x0285636f,
    0xfecc8f80,0x80000000,0xfe40a081,0x80000060,
    0x00cc9f81,0x9000e04f,0xfe281f00,0x80060000,
    0xf8c01f81,0x9006c02f,0xfee00f81,0xfd80636f,
    0x0000803f,0x00000000,0x7ec49f81,0xf880e34f,
    0xfe381f80,0x00000000,0x7de40f81,0xfe800360,
    0x00011f80,0x8c100000,0xf8001f00,0x900ce00f,
    0x00311f00,0x1000e02f,0x02a41f00,0xf910624f,
    0x02a01f00,0xf910626f,0x00011f80,0x1033e04f,
    0x00000040,0x00000000,0xfecc9f03,0x80020000,
    0xfec81f83,0x80020060,0x7fd49f01,0x00000020,
    0x7fd41f80,0x00000040,0xfe081f00,0x80010000,
    0xfe041f80,0x80010060,0xfee00f01,0x80000000,
    0xfeec0f81,0x80000020,0xfec01f00,0x00280000,
    0xfec49f00,0x00280020,0x7fe00f00,0x00280040,
    0xfd001f80,0x00280060,0x00000080,0x00000000,
    0xfe001f80,0x00350000,0x00ec1f82,0x000c0260,
    0x01011f00,0x800c0000,0x01051f00,0x800c0020,
    0x002c1f00,0x80060040,0xf8008001,0x9006e06f,
    0x01091f80,0x800c0000,0x01c01f00,0x90000000,
    0xfe088001,0xfd80632f,0x01e81f00,0x90000040,
    0x01c49f80,0x90000020,0x0000803f,0x00000000,
    0x7fcc9f80,0xf880630f,0xfe20a081,0x80000000,
    0x01cc1f80,0x90000060,0xc21e82a7,0x62ccc547,
    0x1708607c,0x73ea57a6
};
static const u32 cpPixelShaderRegs[] = {
    0x00000106,0x00000002,0x14000003,0x00000000,
    0x00000003,0x00000100,0x00000101,0x00000102,
    0x00000000,0x00000000,0x00000000,0x00000000,
    0x00000000,0x00000000,0x00000000,0x00000000,
    0x00000000,0x00000000,0x00000000,0x00000000,
    0x00000000,0x00000000,0x00000000,0x00000000,
    0x00000000,0x00000000,0x00000000,0x00000000,
    0x00000000,0x00000000,0x00000000,0x00000000,
    0x00000000,0x00000000,0x00000000,0x00000000,
    0x00000000,0x0000000f,0x00000001,0x00000010,
    0x00000000
};

ShaderFractalColor * ShaderFractalColor::shaderInstance = NULL;

ShaderFractalColor::ShaderFractalColor()
    : vertexShader(cuAttributeCount)
{
    //! create pixel shader
    pixelShader.setProgram(cpPixelShaderProgram, sizeof(cpPixelShaderProgram), cpPixelShaderRegs, sizeof(cpPixelShaderRegs));

    blurLocation = 0;
    colorIntensityLocation = 4;
    fadeOutLocation = 8;
    fractalLocation = 12;
    pixelShader.addUniformVar((GX2UniformVar){ "unf_blur_border", GX2_SHADER_VAR_TYPE_FLOAT, 1, blurLocation, 0xffffffff });
    pixelShader.addUniformVar((GX2UniformVar){ "unf_color_intensity", GX2_SHADER_VAR_TYPE_FLOAT4, 1, colorIntensityLocation, 0xffffffff });
    pixelShader.addUniformVar((GX2UniformVar){ "unf_fade_out_alpha", GX2_SHADER_VAR_TYPE_FLOAT4, 1, fadeOutLocation, 0xffffffff });
    pixelShader.addUniformVar((GX2UniformVar){ "unf_fract_alpha", GX2_SHADER_VAR_TYPE_INT, 1, fractalLocation, 0xffffffff });

    //! create vertex shader
    vertexShader.setProgram(cpVertexShaderProgram, sizeof(cpVertexShaderProgram), cpVertexShaderRegs, sizeof(cpVertexShaderRegs));

    modelMatrixLocation = 0;
    projectionMatrixLocation = 16;
    viewMatrixLocation = 32;
    vertexShader.addUniformVar((GX2UniformVar){ "modelMatrix", GX2_SHADER_VAR_TYPE_MATRIX4X4, 1, modelMatrixLocation, 0xffffffff });
    vertexShader.addUniformVar((GX2UniformVar){ "projectionMatrix", GX2_SHADER_VAR_TYPE_MATRIX4X4, 1, projectionMatrixLocation, 0xffffffff });
    vertexShader.addUniformVar((GX2UniformVar){ "viewMatrix", GX2_SHADER_VAR_TYPE_MATRIX4X4, 1, viewMatrixLocation, 0xffffffff });

    positionLocation = 0;
    colorLocation = 1;
    texCoordLocation = 2;
    vertexShader.addAttribVar((GX2AttribVar){ "attr_colors", GX2_SHADER_VAR_TYPE_FLOAT4, 0, colorLocation });
    vertexShader.addAttribVar((GX2AttribVar){ "attr_position", GX2_SHADER_VAR_TYPE_FLOAT3, 0, positionLocation });
    vertexShader.addAttribVar((GX2AttribVar){ "attr_texture_coord", GX2_SHADER_VAR_TYPE_FLOAT2, 0, texCoordLocation });

    //! setup attribute streams
    GX2InitAttribStream(vertexShader.getAttributeBuffer(0), positionLocation, 0, 0, GX2_ATTRIB_FORMAT_FLOAT_32_32_32);
    GX2InitAttribStream(vertexShader.getAttributeBuffer(1), texCoordLocation, 1, 0, GX2_ATTRIB_FORMAT_FLOAT_32_32);
    GX2InitAttribStream(vertexShader.getAttributeBuffer(2), colorLocation, 2, 0, GX2_ATTRIB_FORMAT_UNORM_8_8_8_8);

    //! create fetch shader
    fetchShader = new FetchShader(vertexShader.getAttributeBuffer(), vertexShader.getAttributesCount());

    //! initialize default quad texture vertexes as those are very commonly used
    //! model vertex has to be align and cannot be in unknown regions for GX2 like 0xBCAE1000
    posVtxs = (f32*)memalign(GX2_VERTEX_BUFFER_ALIGNMENT, ciPositionVtxsSize);
    texCoords = (f32*)memalign(GX2_VERTEX_BUFFER_ALIGNMENT, ciTexCoordsVtxsSize);
    colorVtxs = (u8*)memalign(GX2_VERTEX_BUFFER_ALIGNMENT, ciColorVtxsSize);

    //! position vertex structure and texture coordinate vertex structure
    int i = 0;
    posVtxs[i++] = -1.0f; posVtxs[i++] = -1.0f; posVtxs[i++] = 0.0f;
    posVtxs[i++] =  1.0f; posVtxs[i++] = -1.0f; posVtxs[i++] = 0.0f;
    posVtxs[i++] =  1.0f; posVtxs[i++] =  1.0f; posVtxs[i++] = 0.0f;
    posVtxs[i++] = -1.0f; posVtxs[i++] =  1.0f; posVtxs[i++] = 0.0f;
    GX2Invalidate(GX2_INVALIDATE_MODE_CPU_ATTRIBUTE_BUFFER, posVtxs, ciPositionVtxsSize);

    i = 0;
    texCoords[i++] = 0.0f; texCoords[i++] = 1.0f;
    texCoords[i++] = 1.0f; texCoords[i++] = 1.0f;
    texCoords[i++] = 1.0f; texCoords[i++] = 0.0f;
    texCoords[i++] = 0.0f; texCoords[i++] = 0.0f;
    GX2Invalidate(GX2_INVALIDATE_MODE_CPU_ATTRIBUTE_BUFFER, texCoords, ciTexCoordsVtxsSize);


    for(i = 0; i < (int)ciColorVtxsSize; i++)
        colorVtxs[i] = 0xff;

    GX2Invalidate(GX2_INVALIDATE_MODE_CPU_ATTRIBUTE_BUFFER, colorVtxs, ciColorVtxsSize);
}

ShaderFractalColor::~ShaderFractalColor()
{
    if(posVtxs)
    {
        free(posVtxs);
        posVtxs = NULL;
    }
    if(texCoords)
    {
        free(texCoords);
        texCoords = NULL;
    }
    if(colorVtxs)
    {
        free(colorVtxs);
        colorVtxs = NULL;
    }

    delete fetchShader;
    fetchShader = NULL;
}

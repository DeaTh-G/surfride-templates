enum <ushort> SRS_ANIMATION_TYPE
{
    XPosition,
    YPosition,
    ZPosition,
    XRotation,
    YRotation,
    ZRotation,
    XScale,
    YScale,
    ZScale,
    MaterialColor,
    IlluminationColor = 20,
    MaterialColorRed,
    MaterialColorGreen,
    MaterialColorBlue,
    MaterialColorAlpha,
    VertexColorRedClear,
    VertexColorGreenClear,
    VertexColorBlueClear,
    VertexColorAlphaClear,
    VertexColorRedClampHigh,
    VertexColorGreenClampHigh,
    VertexColorBlueClampHigh,
    VertexColorAlphaClampHigh,
    VertexColorRed,
    VertexColorGreen,
    VertexColorBlue,
    VertexColorAlpha,
    VertexColorRedClampLow,
    VertexColorGreenClampLow,
    VertexColorBlueClampLow,
    VertexColorAlphaClampLow,
    IlluminationColorRed,
    IlluminationColorGreen,
    IlluminationColorBlue,
    IlluminationColorAlpha,
};

typedef struct {
	local uint64 p<hidden=true>;

    SRS_ANIMATION_TYPE AnimationType;
    ushort KeyCount;
    uint Flags;
    uint StartFrame;
    uint EndFrame;
    uint KeyOffset; p = FTell();
    if (KeyCount && KeyOffset)
    {
        FSeek(KeyOffset);
        switch (Flags & 3)
        {
            case 0:
                SRS_KEYCONSTANT Keys(Flags)[KeyCount];
                break;
            case 1: 
                SRS_KEYLINEAR Keys(Flags)[KeyCount];
                break;
            case 2: 
                SRS_KEYHERMITE Keys(Flags)[KeyCount];
                break;
            case 3: 
                SRS_KEYINDIVIDUAL Keys(Flags)[KeyCount];
                break;
            default:
                break;
        }
    } FSeek(p);
} SRS_TRACK<optimize=false>;
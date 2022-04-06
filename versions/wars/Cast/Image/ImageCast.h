typedef struct {
	local uint64 p<hidden=true>;

    uint Flags;
    float Width;
    float Height;
    SRS_VECTOR2 AnchorPoint;
    SRS_COLOR GradientTopLeft;
    SRS_COLOR GradientBottomLeft;
    SRS_COLOR GradientTopRight;
    SRS_COLOR GradientBottomRight;
    short field_24;
    short field_26;
    ushort PatternInfoCount;
    ushort UnknownInfoCount;
    uint field_30;
    uint64 PatternInfoOffset;
    uint64 UnknownInfoOffset;
    uint64 FontInfoOffset;
    uint64 field_48;
    uint64 field_54; p = FTell();
    if (PatternInfoCount && PatternInfoOffset)
    {
        FSeek(PatternInfoOffset); SRS_PATTERN_INFO PatternInfo[PatternInfoCount];
    }
    if (UnknownInfoCount && UnknownInfoOffset)
    {
        FSeek(UnknownInfoOffset); SRS_UNKNOWN_INFO UnknownStruct[UnknownInfoCount];
    }
    if (FontInfoOffset)
    {
        FSeek(FontInfoOffset); SRS_FONT_INFO FontInfo;
    } FSeek(p);
} SRS_IMAGE_CAST<optimize=false>;
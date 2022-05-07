typedef struct {
	local uint64 p<hidden=true>;
	
    uint64 NameOffset;
	StringPtr Name(NameOffset);
	uint64 TextureCount;
	uint64 TextureOffset;
	uint64 field_18; p = FTell();
    if (TextureOffset && TextureCount)
    {
        FSeek(TextureOffset); SRS_TEXTURE Textures[TextureCount];
    } FSeek(p); 
} SRS_TEXTURE_LIST<optimize=false, read=Name.Name>;

typedef struct {
    local uint64 o<hidden=true> = FTell();
	if (o % 16 != 0)
	{
		FSkip(16 - (o % 16)); o = FTell();
	}
	local uint64 p<hidden=true>;
	
	SRS_CHUNK_HEADER Header;
	uint TextureListOffset;
	uint TextureListCount; p = FTell();
    if (TextureListOffset && TextureListCount)
    { 
        FSeek(o + TextureListOffset); SRS_TEXTURE_LIST TextureLists[TextureListCount];
    }
} SRS_TEXTURE_LIST_CHUNK<bgcolor=0x006AFF>;
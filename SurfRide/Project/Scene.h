typedef struct {
    local uint64 p<hidden=true>;

    size_t NameOffset;
    StringPtr Name(NameOffset.offset);
    uint ID;
    uint Flags;
    if (VERSION >= 4)
        uint field_10;
    uint LayerCount;
    size_t LayerOffset;
    short CameraCount;
    short CurrentCameraIndex;
    size_t CameraOffset;
    SRS_COLOR BackgroundColor;
    SRS_VECTOR2 Resolution;
    size_t UserDataOffset; p = FTell();
    if (LayerOffset.offset && LayerCount)
    {
        FSeek(LayerOffset.offset); SRS_LAYER Layers[LayerCount];
    }
    if (CameraOffset.offset && CameraCount);
    {
        FSeek(CameraOffset.offset); SRS_CAMERA Cameras[CameraCount];
    }
    if (UserDataOffset.offset)
    {
        FSeek(UserDataOffset.offset); SRS_USERDATA UserData;
    } FSeek(p);
} SRS_SCENE<optimize=false, read=Name.Name>;
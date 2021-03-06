#include "Math.hxx"

Vec3 Vec3::Cross(const Vec3 &v) const
{
    return Vec3((y * v.z) - (z * v.y), (z * v.x) - (x * v.z), (x * v.y) - (y * v.x));
}

float Vec3::Dot(const Vec3 &v) const
{
    return ((x * v.x) + (y * v.y) + (z * v.z));
}

Vec3 Vec3::Normalise() const
{
    int size = Magnitude();
    return Vec3(x / size, y / size, z / size);
}

int Vec3::Magnitude() const
{
    return sqrtf((x * x) + (y * y) + (z * z));
}

Vec3 Vec3::Scale(const float val) const
{
    return Vec3(x * val, y * val, z * val);
}

Vec3 Vec3::operator + (const Vec3 &v) const
{
    return Vec3(x + v.x, y + v.y, z + v.z);
}

Vec3 Vec3::operator - (const Vec3 &v) const
{
    return Vec3(x - v.x, y - v.y, z - v.z);
}

Vec3 Vec3::operator * (const float val) const
{
    return Vec3(x * val, y * val, z * val);
}

Vec3 Vec3::operator / (const float val) const
{
    return Vec3(x / val, y / val, z / val);
}

Vec3 Vec3::Transform(Mat4* mat) const
{
    Vec3 res;
    float normal = (*mat)[0][3] * x + (*mat)[1][3] * y + (*mat)[2][3] * z + (*mat)[3][3];
    if (normal)
    {
        res.x = ((*mat)[0][0] * x + (*mat)[1][0] * y + (*mat)[2][0] * z + (*mat)[3][0]) / normal;
        res.y = ((*mat)[0][1] * x + (*mat)[1][1] * y + (*mat)[2][1] * z + (*mat)[3][1]) / normal;
        res.z = ((*mat)[0][2] * x + (*mat)[1][2] * y + (*mat)[2][2] * z + (*mat)[3][2]) / normal;
    }
    return res;
}

Vec3 Vec3::Transform(const Mat4 &mat) const
{
    Vec3 res;
    float normal = mat[0][3] * x + mat[1][3] * y + mat[2][3] * z + mat[3][3];
    if (normal)
    {
        res.x = (mat[0][0] * x + mat[1][0] * y + mat[2][0] * z + mat[3][0]) / normal;
        res.y = (mat[0][1] * x + mat[1][1] * y + mat[2][1] * z + mat[3][1]) / normal;
        res.z = (mat[0][2] * x + mat[1][2] * y + mat[2][2] * z + mat[3][2]) / normal;
    }
    return res;
}

Vec3 Vec3::Project(D3DVIEWPORT9* viewport, Mat4* world, Mat4* view, Mat4* projection) const
{
    for (short i = 0; i < 4; ++i)
    {
        for (short j = 0; j < 4; ++j)
        {
            (*world)[i][j] = (*world)[i][0] * (*view)[0][j] + (*world)[i][1] * (*view)[1][j] + (*world)[i][2] * (*view)[2][j] + (*world)[i][3] * (*view)[3][j];
        }
    }

    for (short i = 0; i < 4; ++i)
    {
        for (short j = 0; j < 4; ++j)
        {
            (*world)[i][j] = (*world)[i][0] * (*projection)[0][j] + (*world)[i][1] * (*projection)[1][j] + (*world)[i][2] * (*projection)[2][j] + (*world)[i][3] * (*projection)[3][j];
        }
    }

    Vec3 res = this->Transform(world);
    res.x = viewport->X + (1.0f + res.x) * viewport->Width / 2.0f;
    res.y = viewport->Y + (1.0f - res.y) * viewport->Height / 2.0f;
    res.z = viewport->MinZ + res.z * (viewport->MaxZ - viewport->MinZ);
    return res;
}

Vec3 Vec3::Project(const D3DVIEWPORT9 &viewport, const Mat4 &world, const Mat4 &view, const Mat4 &projection) const
{
    Mat4 wv = world * view;
    Mat4 wvp = wv * projection;
    Vec3 res = this->Transform(wvp);
    res.x = viewport.X + (1.0f + res.x) * viewport.Width / 2.0f;
    res.y = viewport.Y + (1.0f - res.y) * viewport.Height / 2.0f;
    res.z = viewport.MinZ + res.z * (viewport.MaxZ - viewport.MinZ);
    return res;
}


Mat4 Mat4::operator * (const Mat4 &m) const
{
    Mat4 res;
    for (short i = 0; i < 4; ++i)
    {
        for (short j = 0; j < 4; ++j)
        {
            //#error come back..
            /*float sum = 0.0f;
            for (short k = 0; k < 4; ++k)
            {
                sum += mat[i][k] * res[k][j];
            }
            res[i][j] = sum;*/

            res[i][j] = mat[i][0] * m[0][j] + mat[i][1] * m[1][j] + mat[i][2] * m[2][j] + mat[i][3] * m[3][j];
        }
    }
    return res;
}

Mat4 Mat4::operator + (const Mat4 &m) const
{
    Mat4 res;
    for (short i = 0; i < 4; ++i)
    {
        for (short j = 0; j < 4; ++j)
        {
            res[i][j] = mat[i][j] + m[i][j];
        }
    }
    return res;
}

Mat4 Mat4::operator - (const Mat4 &m) const
{
    Mat4 res;
    for (short i = 0; i < 4; ++i)
    {
        for (short j = 0; j < 4; ++j)
        {
            res[i][j] = mat[i][j] - m[i][j];
        }
    }
    return res;
}

Mat4& Mat4::Transpose()
{
    for (int i = 0; i < 4; ++i)
    {
        for (int j = 0; j < 4; ++j)
        {
            mat[j][i] = mat[i][j];
        }
    }
    return *this;
}

Mat4 Mat4::Transpose() const
{
    Mat4 res;
    for (int i = 0; i < 4; ++i)
    {
        for (int j = 0; j < 4; ++j)
        {
            res[j][i] = mat[i][j];
        }
    }
    return res;
}

Mat4 Mat4::Identity()
{
    Mat4 res;
    res[0][0] = 1.0f;
    res[1][1] = 1.0f;
    res[2][2] = 1.0f;
    res[3][3] = 1.0f;
    return res;
}

Mat4 Mat4::Orthagonal(float w, float h, float zNear, float zFar)
{
    Mat4 res;
    res[0][0] = 2.0f / w;
    res[1][1] = 2.0f / h;
    res[2][2] = 1.0f / (zNear - zFar);
    res[3][2] = zNear / (zNear - zFar);
    res[3][3] = 1.0f;
    return res;
}

Mat4 Mat4::Perspective(float w, float h, float zNear, float zFar)
{
    Mat4 res;
    res[0][0] = 2.0f * zNear / w;
    res[1][1] = 2.0f * zNear / h;
    res[2][2] = zFar / (zNear - zFar);
    res[3][2] = zFar * zNear / (zNear - zFar);
    res[2][3] = -1.0f;
    return res;
}

Mat4 Mat4::FieldOfView(float fov, float aspect, float zNear, float zFar)
{
    Mat4 res;
    res[0][0] = 1.0f / tanf(fov / 2.0f);
    res[1][1] = aspect / tanf(fov / 2.0f);
    res[2][2] = zFar / (zFar - zNear);
    res[3][2] = (zFar * zNear) / (zNear - zFar);
    res[2][3] = -1.0f;
    res[3][3] = 0.0f;
    return res;
}

Mat4 Mat4::LookAt(const Vec3& Eye, const Vec3& At, const Vec3& Up)
{
    Vec3 XAxis, YAxis, ZAxis;
    ZAxis = (Eye - At).Normalise();
    XAxis = (Up.Cross(ZAxis)).Normalise();
    YAxis = (ZAxis.Cross(XAxis)).Normalise();

    Mat4 res;
    res[0][0] = XAxis.x;
    res[1][0] = XAxis.y;
    res[2][0] = XAxis.z;
    res[3][0] = -XAxis.Dot(Eye);
    res[0][1] = YAxis.x;
    res[1][1] = YAxis.y;
    res[2][1] = YAxis.z;
    res[3][1] = -YAxis.Dot(Eye);
    res[0][2] = ZAxis.x;
    res[1][2] = ZAxis.y;
    res[2][2] = ZAxis.z;
    res[3][2] = -ZAxis.Dot(Eye);
    res[3][3] = 1.0f;
    return res;
}

Mat4 Mat4::RotX(float rad)
{
    float ct = cosf(rad);
    float st = sinf(rad);
    Mat4 res = Identity();
    res[1][1] = ct;
    res[1][2] = st;
    res[2][1] = -st;
    res[2][2] = ct;
    return res;
}

Mat4 Mat4::RotY(float rad)
{
    float ct = cosf(rad);
    float st = sinf(rad);
    Mat4 res = Identity();
    res[0][0] = ct;
    res[0][2] = st;
    res[2][0] = -st;
    res[2][2] = ct;
    return res;
}

Mat4 Mat4::RotZ(float rad)
{
    float ct = cosf(rad);
    float st = sinf(rad);
    Mat4 res = Identity();
    res[0][0] = ct;
    res[0][1] = st;
    res[1][0] = -st;
    res[1][1] = ct;
    return res;
}

Mat4 Mat4::Rot(float pitch, float yaw, float roll)
{
    return RotY(yaw) * RotX(pitch) * RotZ(roll);
}

Mat4 Mat4::Scale(float val)
{
    return Scale(val, val, val);
}

Mat4 Mat4::Scale(float x, float y, float z)
{
    Mat4 res;
    res[0][0] = x;
    res[1][1] = y;
    res[2][2] = z;
    res[3][3] = 1.0f;
    return res;
}

Mat4 Mat4::Translate(float x, float y, float z)
{
    Mat4 res;
    res[3][0] = x;
    res[3][1] = y;
    res[3][2] = z;
    res[0][0] = 1.0f;
    res[1][1] = 1.0f;
    res[2][2] = 1.0f;
    res[3][3] = 1.0f;
    return res;
}

namespace DXMath
{
    unsigned int CalculateStride(unsigned int FVF)
    {
        return ((FVF | D3DFVF_XYZ) == FVF) * 12 +
               ((FVF | D3DFVF_XYZRHW) == FVF) * 12 +
               ((FVF | D3DFVF_XYZB1) == FVF) * 12 +
               ((FVF | D3DFVF_XYZB2) == FVF) * 12 +
               ((FVF | D3DFVF_XYZB3) == FVF) * 12 +
               ((FVF | D3DFVF_XYZB4) == FVF) * 12 +
               ((FVF | D3DFVF_XYZB5) == FVF) * 12 +
               ((FVF | D3DFVF_XYZW) == FVF) * 12 +
               ((FVF | D3DFVF_NORMAL) == FVF) * 12 +
               ((FVF | D3DFVF_DIFFUSE) == FVF) * 4  +
               ((FVF | D3DFVF_SPECULAR) == FVF) * 4  +
               ((FVF | D3DFVF_TEX1) == FVF) * 8  +
               ((FVF | D3DFVF_TEX2) == FVF) * 8  +
               ((FVF | D3DFVF_TEX3) == FVF) * 8  +
               ((FVF | D3DFVF_TEX4) == FVF) * 8  +
               ((FVF | D3DFVF_TEX5) == FVF) * 8  +
               ((FVF | D3DFVF_TEX6) == FVF) * 8  +
               ((FVF | D3DFVF_TEX7) == FVF) * 8  +
               ((FVF | D3DFVF_TEX8) == FVF) * 8;
    }

    unsigned int CalculateBitsPerPixel(D3DFORMAT format)
    {
        switch(format)
        {
            case D3DFMT_A16B16G16R16: return 64;
            case D3DFMT_A8R8G8B8: return 32;
            case D3DFMT_X8R8G8B8: return 32;
            case D3DFMT_A2B10G10R10: return 32;
            case D3DFMT_A8B8G8R8: return 32;
            case D3DFMT_X8B8G8R8: return 32;
            case D3DFMT_G16R16: return 32;
            case D3DFMT_A2R10G10B10: return 32;
            case D3DFMT_R8G8B8: return 24;
            case D3DFMT_R5G6B5: return 16;
            case D3DFMT_X1R5G5B5: return 16;
            case D3DFMT_A1R5G5B5: return 16;
            case D3DFMT_A4R4G4B4: return 16;
            case D3DFMT_A8R3G3B2: return 16;
            case D3DFMT_X4R4G4B4: return 16;
            case D3DFMT_A8P8: return 8;
            case D3DFMT_R3G3B2: return 8;
            case D3DFMT_A8: return 8;
            default: return 8;
        }
    }

    #ifdef D3DX_SUPPORT
    D3DXVECTOR3 WorldToScreen(D3DXMATRIX* WorldViewProjection, D3DVIEWPORT9* ViewPort, const D3DXVECTOR3 &in)
    {
        D3DXVECTOR3 out;
        D3DXMatrixTranspose(WorldViewProjection, WorldViewProjection);
        D3DXVec3TransformCoord(&out, &in, WorldViewProjection);
        return D3DXVECTOR3((out.x + 1.0f) * ViewPort->Width * 0.5f + ViewPort->X, (1.0f - out.y) * ViewPort->Height * 0.5f + ViewPort->Y, out.z);
    }

    D3DXVECTOR3 WorldToScreen2(D3DVIEWPORT9* ViewPort, D3DXMATRIX* World, D3DXMATRIX* View, D3DXMATRIX* Projection, const D3DXVECTOR3 &in)
    {
        D3DXVECTOR3 out;
        D3DXVec3Project(&out, &in, ViewPort, Projection, View, World);
        return out;
    }
    #else
    Vec3 WorldToScreen(Mat4* WorldViewProjection, D3DVIEWPORT9* ViewPort, const Vec3 &in)
    {
        Vec3 out = in.Transform(WorldViewProjection->Transpose());
        return Vec3{(out.x + 1.0f) * ViewPort->Width * 0.5f + ViewPort->X, (1.0f - out.y) * ViewPort->Height * 0.5f + ViewPort->Y, out.z};
    }

    Vec3 WorldToScreen2(D3DVIEWPORT9* ViewPort, Mat4* World, Mat4* View, Mat4* Projection, const Vec3 &in)
    {
        return in.Project(ViewPort, World, View, Projection);
    }
    #endif // D3DX_SUPPORT
}

namespace GVMath
{
    Vec3 GetEulerAngles(float (&mat)[16], bool rowmajor)
    {
        if (rowmajor)
        {
            float x = std::atan2(mat[6], mat[10])  * (180 / GVMath::PI);
            float y = std::atan2(-mat[8], std::sqrt(std::pow(mat[0], 2) + std::pow(mat[1], 2)))  * (180 / GVMath::PI);
            float z = std::atan2(mat[1], mat[0]) * (180 / GVMath::PI);
            return {x < 0 ? 360 - x : x, y < 0 ? 360 - y : y, z < 0 ? 360 - z : z};
        }
        else
        {
            float x = std::atan2(mat[9], mat[10])  * (180 / GVMath::PI);
            float y = std::atan2(-mat[8], std::sqrt(std::pow(mat[0], 2) + std::pow(mat[4], 2)))  * (180 / GVMath::PI);
            float z = std::atan2(mat[4], mat[0]) * (180 / GVMath::PI);
            return {x < 0 ? 360 - x : x, y < 0 ? 360 - y : y, z < 0 ? 360 - z : z};
        }
    }

    Vec3 GetEulerAngles(float (&mat)[4][4], bool rowmajor)
    {
        if (rowmajor)
        {
            float x = std::atan2(mat[1][2], mat[2][2])  * (180 / GVMath::PI);
            float y = std::atan2(-mat[0][2], std::sqrt(std::pow(mat[0][0], 2) + std::pow(mat[0][1], 2)))  * (180 / GVMath::PI);
            float z = std::atan2(mat[0][1], mat[0][0]) * (180 / GVMath::PI);
            return {x < 0 ? 360 - x : x, y < 0 ? 360 - y : y, z < 0 ? 360 - z : z};
        }
        else
        {
            float x = std::atan2(mat[2][1], mat[2][2])  * (180 / GVMath::PI);
            float y = std::atan2(-mat[2][0], std::sqrt(std::pow(mat[0][0], 2) + std::pow(mat[1][0], 2)))  * (180 / GVMath::PI);
            float z = std::atan2(mat[1][0], mat[0][0]) * (180 / GVMath::PI);
            return {x < 0 ? 360 - x : x, y < 0 ? 360 - y : y, z < 0 ? 360 - z : z};
        }
    }

    float Distance(float (&a)[2], float (&b)[2])
    {
        float x = a[0] - b[0];
        float y = a[1] - b[1];
        return sqrt((x * x) + (y * y));
    }

    float Distance(float (&a)[3], float (&b)[3])
    {
        float x = a[0] - b[0];
        float y = a[1] - b[1];
        float z = a[2] - b[2];
        return sqrt((x * x) + (y * y) + (z * z));
    }

    Box2D BoundingBox(float* x, float* y, std::size_t size)
    {
        auto xtreme = std::minmax_element(x, x + size, [](const float lhs, const float rhs) {return lhs < rhs;});
        auto ytreme = std::minmax_element(y, y + size, [](const float lhs, const float rhs) {return lhs < rhs;});
        return {*xtreme.first, *ytreme.first, *xtreme.second, *ytreme.second};
    }

    Box3D BoundingBox(float* x, float* y, float* z, std::size_t size)
    {
        auto xtreme = std::minmax_element(x, x + size, [](const float lhs, const float rhs) {return lhs < rhs;});
        auto ytreme = std::minmax_element(y, y + size, [](const float lhs, const float rhs) {return lhs < rhs;});
        auto ztreme = std::minmax_element(z, z + size, [](const float lhs, const float rhs) {return lhs < rhs;});
        return {*xtreme.first, *ytreme.first, *ztreme.first, *xtreme.second, *ytreme.second, *ztreme.second};
    }

    std::uint32_t ColourChecksum(const void* data, std::size_t width, std::size_t height)
    {
        return FullColourChecksum(data, width, height, height < 12 ? 0 : 12);
    }

    std::uint32_t FullColourChecksum(const void* data, std::size_t width, std::size_t height, std::size_t offset)
    {
        std::size_t k = 0;
        std::uint32_t RSum = 0, GSum = 0, BSum = 0, ASum = 0;
        const std::uint8_t* ptr = static_cast<const std::uint8_t*>(data);

        for (std::size_t i = offset; i < height; ++i)
        {
            for (std::size_t j = 0; j < width; ++j, ++k)
            {
                RSum += *ptr++;
                GSum += *ptr++;
                BSum += *ptr++;
                ASum += *ptr++;
            }
        }

        return k != 0 ? RGB(RSum / k, GSum / k, BSum / k) : RGB(RSum, GSum, BSum);
    }

    std::uint32_t Adler32(const std::uint8_t* data, std::size_t size)
    {
        std::uint32_t a = 1, b = 0;
        for (std::size_t i = 0; i < size; ++i)
        {
            a = (a + data[i]) % 0xFFF1;
            b = (b + a) % 0xFFF1;
        }
        return (b << 0x10) | a;
    }

    std::uint32_t CRC32(const void* data, std::size_t size, std::uint32_t InitialValue)
    {
        static const std::uint32_t LookUpTable[256] =
        {
            0x00000000, 0x77073096, 0xEE0E612C, 0x990951BA,
            0x076DC419, 0x706AF48F, 0xE963A535, 0x9E6495A3,
            0x0EDB8832, 0x79DCB8A4, 0xE0D5E91E, 0x97D2D988,
            0x09B64C2B, 0x7EB17CBD, 0xE7B82D07, 0x90BF1D91,
            0x1DB71064, 0x6AB020F2, 0xF3B97148, 0x84BE41DE,
            0x1ADAD47D, 0x6DDDE4EB, 0xF4D4B551, 0x83D385C7,
            0x136C9856, 0x646BA8C0, 0xFD62F97A, 0x8A65C9EC,
            0x14015C4F, 0x63066CD9, 0xFA0F3D63, 0x8D080DF5,
            0x3B6E20C8, 0x4C69105E, 0xD56041E4, 0xA2677172,
            0x3C03E4D1, 0x4B04D447, 0xD20D85FD, 0xA50AB56B,
            0x35B5A8FA, 0x42B2986C, 0xDBBBC9D6, 0xACBCF940,
            0x32D86CE3, 0x45DF5C75, 0xDCD60DCF, 0xABD13D59,
            0x26D930AC, 0x51DE003A, 0xC8D75180, 0xBFD06116,
            0x21B4F4B5, 0x56B3C423, 0xCFBA9599, 0xB8BDA50F,
            0x2802B89E, 0x5F058808, 0xC60CD9B2, 0xB10BE924,
            0x2F6F7C87, 0x58684C11, 0xC1611DAB, 0xB6662D3D,
            0x76DC4190, 0x01DB7106, 0x98D220BC, 0xEFD5102A,
            0x71B18589, 0x06B6B51F, 0x9FBFE4A5, 0xE8B8D433,
            0x7807C9A2, 0x0F00F934, 0x9609A88E, 0xE10E9818,
            0x7F6A0DBB, 0x086D3D2D, 0x91646C97, 0xE6635C01,
            0x6B6B51F4, 0x1C6C6162, 0x856530D8, 0xF262004E,
            0x6C0695ED, 0x1B01A57B, 0x8208F4C1, 0xF50FC457,
            0x65B0D9C6, 0x12B7E950, 0x8BBEB8EA, 0xFCB9887C,
            0x62DD1DDF, 0x15DA2D49, 0x8CD37CF3, 0xFBD44C65,
            0x4DB26158, 0x3AB551CE, 0xA3BC0074, 0xD4BB30E2,
            0x4ADFA541, 0x3DD895D7, 0xA4D1C46D, 0xD3D6F4FB,
            0x4369E96A, 0x346ED9FC, 0xAD678846, 0xDA60B8D0,
            0x44042D73, 0x33031DE5, 0xAA0A4C5F, 0xDD0D7CC9,
            0x5005713C, 0x270241AA, 0xBE0B1010, 0xC90C2086,
            0x5768B525, 0x206F85B3, 0xB966D409, 0xCE61E49F,
            0x5EDEF90E, 0x29D9C998, 0xB0D09822, 0xC7D7A8B4,
            0x59B33D17, 0x2EB40D81, 0xB7BD5C3B, 0xC0BA6CAD,
            0xEDB88320, 0x9ABFB3B6, 0x03B6E20C, 0x74B1D29A,
            0xEAD54739, 0x9DD277AF, 0x04DB2615, 0x73DC1683,
            0xE3630B12, 0x94643B84, 0x0D6D6A3E, 0x7A6A5AA8,
            0xE40ECF0B, 0x9309FF9D, 0x0A00AE27, 0x7D079EB1,
            0xF00F9344, 0x8708A3D2, 0x1E01F268, 0x6906C2FE,
            0xF762575D, 0x806567CB, 0x196C3671, 0x6E6B06E7,
            0xFED41B76, 0x89D32BE0, 0x10DA7A5A, 0x67DD4ACC,
            0xF9B9DF6F, 0x8EBEEFF9, 0x17B7BE43, 0x60B08ED5,
            0xD6D6A3E8, 0xA1D1937E, 0x38D8C2C4, 0x4FDFF252,
            0xD1BB67F1, 0xA6BC5767, 0x3FB506DD, 0x48B2364B,
            0xD80D2BDA, 0xAF0A1B4C, 0x36034AF6, 0x41047A60,
            0xDF60EFC3, 0xA867DF55, 0x316E8EEF, 0x4669BE79,
            0xCB61B38C, 0xBC66831A, 0x256FD2A0, 0x5268E236,
            0xCC0C7795, 0xBB0B4703, 0x220216B9, 0x5505262F,
            0xC5BA3BBE, 0xB2BD0B28, 0x2BB45A92, 0x5CB36A04,
            0xC2D7FFA7, 0xB5D0CF31, 0x2CD99E8B, 0x5BDEAE1D,
            0x9B64C2B0, 0xEC63F226, 0x756AA39C, 0x026D930A,
            0x9C0906A9, 0xEB0E363F, 0x72076785, 0x05005713,
            0x95BF4A82, 0xE2B87A14, 0x7BB12BAE, 0x0CB61B38,
            0x92D28E9B, 0xE5D5BE0D, 0x7CDCEFB7, 0x0BDBDF21,
            0x86D3D2D4, 0xF1D4E242, 0x68DDB3F8, 0x1FDA836E,
            0x81BE16CD, 0xF6B9265B, 0x6FB077E1, 0x18B74777,
            0x88085AE6, 0xFF0F6A70, 0x66063BCA, 0x11010B5C,
            0x8F659EFF, 0xF862AE69, 0x616BFFD3, 0x166CCF45,
            0xA00AE278, 0xD70DD2EE, 0x4E048354, 0x3903B3C2,
            0xA7672661, 0xD06016F7, 0x4969474D, 0x3E6E77DB,
            0xAED16A4A, 0xD9D65ADC, 0x40DF0B66, 0x37D83BF0,
            0xA9BCAE53, 0xDEBB9EC5, 0x47B2CF7F, 0x30B5FFE9,
            0xBDBDF21C, 0xCABAC28A, 0x53B39330, 0x24B4A3A6,
            0xBAD03605, 0xCDD70693, 0x54DE5729, 0x23D967BF,
            0xB3667A2E, 0xC4614AB8, 0x5D681B02, 0x2A6F2B94,
            0xB40BBE37, 0xC30C8EA1, 0x5A05DF1B, 0x2D02EF8D
        };

        std::uint32_t crc = ~InitialValue;
        const std::uint8_t* ptr = static_cast<const std::uint8_t*>(data);

        for(std::size_t i = 0; i < size; ++i)
        {
            crc = LookUpTable[(crc ^ *ptr++) & 0xFF] ^ (crc >> 8);
        }

        return ~crc;
    }
}

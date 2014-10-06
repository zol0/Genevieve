#include "IDirect3DDevice9Proxy.hxx"

IDirect3DDevice9Proxy::IDirect3DDevice9Proxy(IDirect3DDevice9* pOriginal)
{
    ptr_Direct3DDevice9 = pOriginal;
}

IDirect3DDevice9Proxy::~IDirect3DDevice9Proxy() {}

HRESULT IDirect3DDevice9Proxy::QueryInterface(REFIID riid, void** ppvObj)
{
    HRESULT hRes = ptr_Direct3DDevice9->QueryInterface(riid, ppvObj);
    *ppvObj = hRes == S_OK ? this : nullptr;
    return hRes;
}

ULONG IDirect3DDevice9Proxy::AddRef()
{
    return ptr_Direct3DDevice9->AddRef();
}

ULONG IDirect3DDevice9Proxy::Release()
{
    ULONG ReferenceCount = ptr_Direct3DDevice9->Release();
    if (ReferenceCount == 0)
    {
        delete this;
    }
    return ReferenceCount;
}

HRESULT IDirect3DDevice9Proxy::TestCooperativeLevel()
{
    return ptr_Direct3DDevice9->TestCooperativeLevel();
}

UINT IDirect3DDevice9Proxy::GetAvailableTextureMem()
{
    return ptr_Direct3DDevice9->GetAvailableTextureMem();
}

HRESULT IDirect3DDevice9Proxy::EvictManagedResources()
{
    return ptr_Direct3DDevice9->EvictManagedResources();
}

HRESULT IDirect3DDevice9Proxy::GetDirect3D(IDirect3D9** ppD3D9)
{
    return ptr_Direct3DDevice9->GetDirect3D(ppD3D9);
}

HRESULT IDirect3DDevice9Proxy::GetDeviceCaps(D3DCAPS9* pCaps)
{
    return ptr_Direct3DDevice9->GetDeviceCaps(pCaps);
}

HRESULT IDirect3DDevice9Proxy::GetDisplayMode(UINT iSwapChain, D3DDISPLAYMODE* pMode)
{
    return ptr_Direct3DDevice9->GetDisplayMode(iSwapChain, pMode);
}

HRESULT IDirect3DDevice9Proxy::GetCreationParameters(D3DDEVICE_CREATION_PARAMETERS *pParameters)
{
    return ptr_Direct3DDevice9->GetCreationParameters(pParameters);
}

HRESULT IDirect3DDevice9Proxy::SetCursorProperties(UINT XHotSpot, UINT YHotSpot, IDirect3DSurface9* pCursorBitmap)
{
    return ptr_Direct3DDevice9->SetCursorProperties(XHotSpot, YHotSpot, pCursorBitmap);
}

void IDirect3DDevice9Proxy::SetCursorPosition(int X, int Y, DWORD Flags)
{
    return ptr_Direct3DDevice9->SetCursorPosition(X, Y, Flags);
}

BOOL IDirect3DDevice9Proxy::ShowCursor(BOOL bShow)
{
    return ptr_Direct3DDevice9->ShowCursor(bShow);
}

HRESULT IDirect3DDevice9Proxy::CreateAdditionalSwapChain(D3DPRESENT_PARAMETERS* pPresentationParameters, IDirect3DSwapChain9** pSwapChain)
{
    return ptr_Direct3DDevice9->CreateAdditionalSwapChain(pPresentationParameters, pSwapChain);
}

HRESULT IDirect3DDevice9Proxy::GetSwapChain(UINT iSwapChain, IDirect3DSwapChain9** pSwapChain)
{
    return ptr_Direct3DDevice9->GetSwapChain(iSwapChain, pSwapChain);
}

UINT IDirect3DDevice9Proxy::GetNumberOfSwapChains()
{
    return ptr_Direct3DDevice9->GetNumberOfSwapChains();
}

HRESULT IDirect3DDevice9Proxy::Reset(D3DPRESENT_PARAMETERS* pPresentationParameters)
{
    return ptr_Direct3DDevice9->Reset(pPresentationParameters);
}

HRESULT IDirect3DDevice9Proxy::Present(CONST RECT* pSourceRect, CONST RECT* pDestRect, HWND hDestWindowOverride, CONST RGNDATA* pDirtyRegion)
{
    return ptr_Direct3DDevice9->Present(pSourceRect, pDestRect, hDestWindowOverride, pDirtyRegion);
}

HRESULT IDirect3DDevice9Proxy::GetBackBuffer(UINT iSwapChain, UINT iBackBuffer, D3DBACKBUFFER_TYPE Type, IDirect3DSurface9** ppBackBuffer)
{
    return ptr_Direct3DDevice9->GetBackBuffer(iSwapChain, iBackBuffer, Type, ppBackBuffer);
}

HRESULT IDirect3DDevice9Proxy::GetRasterStatus(UINT iSwapChain, D3DRASTER_STATUS* pRasterStatus)
{
    return ptr_Direct3DDevice9->GetRasterStatus(iSwapChain, pRasterStatus);
}

HRESULT IDirect3DDevice9Proxy::SetDialogBoxMode(BOOL bEnableDialogs)
{
    return ptr_Direct3DDevice9->SetDialogBoxMode(bEnableDialogs);
}

void IDirect3DDevice9Proxy::SetGammaRamp(UINT iSwapChain, DWORD Flags, CONST D3DGAMMARAMP* pRamp)
{
    return ptr_Direct3DDevice9->SetGammaRamp(iSwapChain, Flags, pRamp);
}

void IDirect3DDevice9Proxy::GetGammaRamp(UINT iSwapChain, D3DGAMMARAMP* pRamp)
{
    return ptr_Direct3DDevice9->GetGammaRamp(iSwapChain, pRamp);
}

HRESULT IDirect3DDevice9Proxy::CreateTexture(UINT Width, UINT Height, UINT Levels, DWORD Usage, D3DFORMAT Format, D3DPOOL Pool, IDirect3DTexture9** ppTexture, HANDLE* pSharedHandle)
{
    return ptr_Direct3DDevice9->CreateTexture(Width, Height, Levels, Usage, Format, Pool, ppTexture, pSharedHandle);
}

HRESULT IDirect3DDevice9Proxy::CreateVolumeTexture(UINT Width, UINT Height, UINT Depth, UINT Levels, DWORD Usage, D3DFORMAT Format, D3DPOOL Pool, IDirect3DVolumeTexture9** ppVolumeTexture, HANDLE* pSharedHandle)
{
    return ptr_Direct3DDevice9->CreateVolumeTexture(Width, Height, Depth, Levels, Usage, Format, Pool, ppVolumeTexture, pSharedHandle);
}

HRESULT IDirect3DDevice9Proxy::CreateCubeTexture(UINT EdgeLength, UINT Levels, DWORD Usage, D3DFORMAT Format, D3DPOOL Pool, IDirect3DCubeTexture9** ppCubeTexture, HANDLE* pSharedHandle)
{
    return ptr_Direct3DDevice9->CreateCubeTexture(EdgeLength, Levels, Usage, Format, Pool, ppCubeTexture, pSharedHandle);
}

HRESULT IDirect3DDevice9Proxy::CreateVertexBuffer(UINT Length, DWORD Usage, DWORD FVF, D3DPOOL Pool, IDirect3DVertexBuffer9** ppVertexBuffer, HANDLE* pSharedHandle)
{
    return ptr_Direct3DDevice9->CreateVertexBuffer(Length, Usage, FVF, Pool, ppVertexBuffer, pSharedHandle);
}

HRESULT IDirect3DDevice9Proxy::CreateIndexBuffer(UINT Length, DWORD Usage, D3DFORMAT Format, D3DPOOL Pool, IDirect3DIndexBuffer9** ppIndexBuffer, HANDLE* pSharedHandle)
{
    return ptr_Direct3DDevice9->CreateIndexBuffer(Length, Usage, Format, Pool, ppIndexBuffer, pSharedHandle);
}

HRESULT IDirect3DDevice9Proxy::CreateRenderTarget(UINT Width, UINT Height, D3DFORMAT Format, D3DMULTISAMPLE_TYPE MultiSample, DWORD MultisampleQuality, BOOL Lockable, IDirect3DSurface9** ppSurface, HANDLE* pSharedHandle)
{
    return ptr_Direct3DDevice9->CreateRenderTarget(Width, Height, Format, MultiSample, MultisampleQuality, Lockable, ppSurface, pSharedHandle);
}

HRESULT IDirect3DDevice9Proxy::CreateDepthStencilSurface(UINT Width, UINT Height, D3DFORMAT Format, D3DMULTISAMPLE_TYPE MultiSample, DWORD MultisampleQuality, BOOL Discard, IDirect3DSurface9** ppSurface, HANDLE* pSharedHandle)
{
    return ptr_Direct3DDevice9->CreateDepthStencilSurface(Width, Height, Format, MultiSample, MultisampleQuality, Discard, ppSurface, pSharedHandle);
}

HRESULT IDirect3DDevice9Proxy::UpdateSurface(IDirect3DSurface9* pSourceSurface, CONST RECT* pSourceRect, IDirect3DSurface9* pDestinationSurface, CONST POINT* pDestPoint)
{
    return ptr_Direct3DDevice9->UpdateSurface(pSourceSurface, pSourceRect, pDestinationSurface, pDestPoint);
}

HRESULT IDirect3DDevice9Proxy::UpdateTexture(IDirect3DBaseTexture9* pSourceTexture, IDirect3DBaseTexture9* pDestinationTexture)
{
    return ptr_Direct3DDevice9->UpdateTexture(pSourceTexture, pDestinationTexture);
}

HRESULT IDirect3DDevice9Proxy::GetRenderTargetData(IDirect3DSurface9* pRenderTarget, IDirect3DSurface9* pDestSurface)
{
    return ptr_Direct3DDevice9->GetRenderTargetData(pRenderTarget, pDestSurface);
}

HRESULT IDirect3DDevice9Proxy::GetFrontBufferData(UINT iSwapChain, IDirect3DSurface9* pDestSurface)
{
    return ptr_Direct3DDevice9->GetFrontBufferData(iSwapChain, pDestSurface);
}

HRESULT IDirect3DDevice9Proxy::StretchRect(IDirect3DSurface9* pSourceSurface, CONST RECT* pSourceRect, IDirect3DSurface9* pDestSurface, CONST RECT* pDestRect, D3DTEXTUREFILTERTYPE Filter)
{
    return ptr_Direct3DDevice9->StretchRect(pSourceSurface, pSourceRect, pDestSurface, pDestRect, Filter);
}

HRESULT IDirect3DDevice9Proxy::ColorFill(IDirect3DSurface9* pSurface, CONST RECT* pRect, D3DCOLOR color)
{
    return ptr_Direct3DDevice9->ColorFill(pSurface, pRect, color);
}

HRESULT IDirect3DDevice9Proxy::CreateOffscreenPlainSurface(UINT Width, UINT Height, D3DFORMAT Format, D3DPOOL Pool, IDirect3DSurface9** ppSurface, HANDLE* pSharedHandle)
{
    return ptr_Direct3DDevice9->CreateOffscreenPlainSurface(Width, Height, Format, Pool, ppSurface, pSharedHandle);
}

HRESULT IDirect3DDevice9Proxy::SetRenderTarget(DWORD RenderTargetIndex, IDirect3DSurface9* pRenderTarget)
{
    return ptr_Direct3DDevice9->SetRenderTarget(RenderTargetIndex, pRenderTarget);
}

HRESULT IDirect3DDevice9Proxy::GetRenderTarget(DWORD RenderTargetIndex, IDirect3DSurface9** ppRenderTarget)
{
    return ptr_Direct3DDevice9->GetRenderTarget(RenderTargetIndex, ppRenderTarget);
}

HRESULT IDirect3DDevice9Proxy::SetDepthStencilSurface(IDirect3DSurface9* pNewZStencil)
{
    return ptr_Direct3DDevice9->SetDepthStencilSurface(pNewZStencil);
}

HRESULT IDirect3DDevice9Proxy::GetDepthStencilSurface(IDirect3DSurface9** ppZStencilSurface)
{
    return ptr_Direct3DDevice9->GetDepthStencilSurface(ppZStencilSurface);
}

HRESULT IDirect3DDevice9Proxy::BeginScene()
{
    return ptr_Direct3DDevice9->BeginScene();
}

HRESULT IDirect3DDevice9Proxy::EndScene()
{
    return ptr_Direct3DDevice9->EndScene();
}

HRESULT IDirect3DDevice9Proxy::Clear(DWORD Count, CONST D3DRECT* pRects, DWORD Flags, D3DCOLOR Color, float Z, DWORD Stencil)
{
    return ptr_Direct3DDevice9->Clear(Count, pRects, Flags, Color, Z, Stencil);
}

HRESULT IDirect3DDevice9Proxy::SetTransform(D3DTRANSFORMSTATETYPE State, CONST D3DMATRIX* pMatrix)
{
    return ptr_Direct3DDevice9->SetTransform(State, pMatrix);
}

HRESULT IDirect3DDevice9Proxy::GetTransform(D3DTRANSFORMSTATETYPE State, D3DMATRIX* pMatrix)
{
    return ptr_Direct3DDevice9->GetTransform(State, pMatrix);
}

HRESULT IDirect3DDevice9Proxy::MultiplyTransform(D3DTRANSFORMSTATETYPE State, CONST D3DMATRIX* pMatrix)
{
    return ptr_Direct3DDevice9->MultiplyTransform(State, pMatrix);
}

HRESULT IDirect3DDevice9Proxy::SetViewport(CONST D3DVIEWPORT9* pViewport)
{
    return ptr_Direct3DDevice9->SetViewport(pViewport);
}

HRESULT IDirect3DDevice9Proxy::GetViewport(D3DVIEWPORT9* pViewport)
{
    return ptr_Direct3DDevice9->GetViewport(pViewport);
}

HRESULT IDirect3DDevice9Proxy::SetMaterial(CONST D3DMATERIAL9* pMaterial)
{
    return ptr_Direct3DDevice9->SetMaterial(pMaterial);
}

HRESULT IDirect3DDevice9Proxy::GetMaterial(D3DMATERIAL9* pMaterial)
{
    return ptr_Direct3DDevice9->GetMaterial(pMaterial);
}

HRESULT IDirect3DDevice9Proxy::SetLight(DWORD Index, CONST D3DLIGHT9* pLight)
{
    return ptr_Direct3DDevice9->SetLight(Index, pLight);
}

HRESULT IDirect3DDevice9Proxy::GetLight(DWORD Index, D3DLIGHT9* pLight)
{
    return ptr_Direct3DDevice9->GetLight(Index, pLight);
}

HRESULT IDirect3DDevice9Proxy::LightEnable(DWORD Index, BOOL Enable)
{
    return ptr_Direct3DDevice9->LightEnable(Index, Enable);
}

HRESULT IDirect3DDevice9Proxy::GetLightEnable(DWORD Index, BOOL* pEnable)
{
    return ptr_Direct3DDevice9->GetLightEnable(Index, pEnable);
}

HRESULT IDirect3DDevice9Proxy::SetClipPlane(DWORD Index, CONST float* pPlane)
{
    return ptr_Direct3DDevice9->SetClipPlane(Index, pPlane);
}

HRESULT IDirect3DDevice9Proxy::GetClipPlane(DWORD Index, float* pPlane)
{
    return ptr_Direct3DDevice9->GetClipPlane(Index, pPlane);
}

HRESULT IDirect3DDevice9Proxy::SetRenderState(D3DRENDERSTATETYPE State, DWORD Value)
{
    return ptr_Direct3DDevice9->SetRenderState(State, Value);
}

HRESULT IDirect3DDevice9Proxy::GetRenderState(D3DRENDERSTATETYPE State, DWORD* pValue)
{
    return ptr_Direct3DDevice9->GetRenderState(State, pValue);
}

HRESULT IDirect3DDevice9Proxy::CreateStateBlock(D3DSTATEBLOCKTYPE Type, IDirect3DStateBlock9** ppSB)
{
    return ptr_Direct3DDevice9->CreateStateBlock(Type, ppSB);
}

HRESULT IDirect3DDevice9Proxy::BeginStateBlock()
{
    return ptr_Direct3DDevice9->BeginStateBlock();
}

HRESULT IDirect3DDevice9Proxy::EndStateBlock(IDirect3DStateBlock9** ppSB)
{
    return ptr_Direct3DDevice9->EndStateBlock(ppSB);
}

HRESULT IDirect3DDevice9Proxy::SetClipStatus(CONST D3DCLIPSTATUS9* pClipStatus)
{
    return ptr_Direct3DDevice9->SetClipStatus(pClipStatus);
}

HRESULT IDirect3DDevice9Proxy::GetClipStatus(D3DCLIPSTATUS9* pClipStatus)
{
    return ptr_Direct3DDevice9->GetClipStatus(pClipStatus);
}

HRESULT IDirect3DDevice9Proxy::GetTexture(DWORD Stage, IDirect3DBaseTexture9** ppTexture)
{
    return ptr_Direct3DDevice9->GetTexture(Stage, ppTexture);
}

HRESULT IDirect3DDevice9Proxy::SetTexture(DWORD Stage, IDirect3DBaseTexture9* pTexture)
{
    return ptr_Direct3DDevice9->SetTexture(Stage, pTexture);
}

HRESULT IDirect3DDevice9Proxy::GetTextureStageState(DWORD Stage, D3DTEXTURESTAGESTATETYPE Type, DWORD* pValue)
{
    return ptr_Direct3DDevice9->GetTextureStageState(Stage, Type, pValue);
}

HRESULT IDirect3DDevice9Proxy::SetTextureStageState(DWORD Stage, D3DTEXTURESTAGESTATETYPE Type, DWORD Value)
{
    return ptr_Direct3DDevice9->SetTextureStageState(Stage, Type, Value);
}

HRESULT IDirect3DDevice9Proxy::GetSamplerState(DWORD Sampler, D3DSAMPLERSTATETYPE Type, DWORD* pValue)
{
    return ptr_Direct3DDevice9->GetSamplerState(Sampler, Type, pValue);
}

HRESULT IDirect3DDevice9Proxy::SetSamplerState(DWORD Sampler, D3DSAMPLERSTATETYPE Type, DWORD Value)
{
    return ptr_Direct3DDevice9->SetSamplerState(Sampler, Type, Value);
}

HRESULT IDirect3DDevice9Proxy::ValidateDevice(DWORD* pNumPasses)
{
    return ptr_Direct3DDevice9->ValidateDevice(pNumPasses);
}

HRESULT IDirect3DDevice9Proxy::SetPaletteEntries(UINT PaletteNumber, CONST PALETTEENTRY* pEntries)
{
    return ptr_Direct3DDevice9->SetPaletteEntries(PaletteNumber, pEntries);
}

HRESULT IDirect3DDevice9Proxy::GetPaletteEntries(UINT PaletteNumber, PALETTEENTRY* pEntries)
{
    return ptr_Direct3DDevice9->GetPaletteEntries(PaletteNumber, pEntries);
}

HRESULT IDirect3DDevice9Proxy::SetCurrentTexturePalette(UINT PaletteNumber)
{
    return ptr_Direct3DDevice9->SetCurrentTexturePalette(PaletteNumber);
}

HRESULT IDirect3DDevice9Proxy::GetCurrentTexturePalette(UINT *PaletteNumber)
{
    return ptr_Direct3DDevice9->GetCurrentTexturePalette(PaletteNumber);
}

HRESULT IDirect3DDevice9Proxy::SetScissorRect(CONST RECT* pRect)
{
    return ptr_Direct3DDevice9->SetScissorRect(pRect);
}

HRESULT IDirect3DDevice9Proxy::GetScissorRect(RECT* pRect)
{
    return ptr_Direct3DDevice9->GetScissorRect(pRect);
}

HRESULT IDirect3DDevice9Proxy::SetSoftwareVertexProcessing(BOOL bSoftware)
{
    return ptr_Direct3DDevice9->SetSoftwareVertexProcessing(bSoftware);
}

BOOL IDirect3DDevice9Proxy::GetSoftwareVertexProcessing()
{
    return ptr_Direct3DDevice9->GetSoftwareVertexProcessing();
}

HRESULT IDirect3DDevice9Proxy::SetNPatchMode(float nSegments)
{
    return ptr_Direct3DDevice9->SetNPatchMode(nSegments);
}

float IDirect3DDevice9Proxy::GetNPatchMode()
{
    return ptr_Direct3DDevice9->GetNPatchMode();
}

HRESULT IDirect3DDevice9Proxy::DrawPrimitive(D3DPRIMITIVETYPE PrimitiveType, UINT StartVertex, UINT PrimitiveCount)
{
    return ptr_Direct3DDevice9->DrawPrimitive(PrimitiveType, StartVertex, PrimitiveCount);
}

HRESULT IDirect3DDevice9Proxy::DrawIndexedPrimitive(D3DPRIMITIVETYPE PrimitiveType, INT BaseVertexIndex, UINT MinVertexIndex, UINT NumVertices, UINT startIndex, UINT primCount)
{
    return ptr_Direct3DDevice9->DrawIndexedPrimitive(PrimitiveType, BaseVertexIndex, MinVertexIndex, NumVertices, startIndex, primCount);
}

HRESULT IDirect3DDevice9Proxy::DrawPrimitiveUP(D3DPRIMITIVETYPE PrimitiveType, UINT PrimitiveCount, CONST void* pVertexStreamZeroData, UINT VertexStreamZeroStride)
{
    return ptr_Direct3DDevice9->DrawPrimitiveUP(PrimitiveType, PrimitiveCount, pVertexStreamZeroData, VertexStreamZeroStride);
}

HRESULT IDirect3DDevice9Proxy::DrawIndexedPrimitiveUP(D3DPRIMITIVETYPE PrimitiveType, UINT MinVertexIndex, UINT NumVertices, UINT PrimitiveCount, CONST void* pIndexData, D3DFORMAT IndexDataFormat, CONST void* pVertexStreamZeroData, UINT VertexStreamZeroStride)
{
    return ptr_Direct3DDevice9->DrawIndexedPrimitiveUP(PrimitiveType, MinVertexIndex, NumVertices, PrimitiveCount, pIndexData, IndexDataFormat, pVertexStreamZeroData, VertexStreamZeroStride);
}

HRESULT IDirect3DDevice9Proxy::ProcessVertices(UINT SrcStartIndex, UINT DestIndex, UINT VertexCount, IDirect3DVertexBuffer9* pDestBuffer, IDirect3DVertexDeclaration9* pVertexDecl, DWORD Flags)
{
    return ptr_Direct3DDevice9->ProcessVertices(SrcStartIndex, DestIndex, VertexCount, pDestBuffer, pVertexDecl, Flags);
}

HRESULT IDirect3DDevice9Proxy::CreateVertexDeclaration(CONST D3DVERTEXELEMENT9* pVertexElements, IDirect3DVertexDeclaration9** ppDecl)
{
    return ptr_Direct3DDevice9->CreateVertexDeclaration(pVertexElements, ppDecl);
}

HRESULT IDirect3DDevice9Proxy::SetVertexDeclaration(IDirect3DVertexDeclaration9* pDecl)
{
    return ptr_Direct3DDevice9->SetVertexDeclaration(pDecl);
}

HRESULT IDirect3DDevice9Proxy::GetVertexDeclaration(IDirect3DVertexDeclaration9** ppDecl)
{
    return ptr_Direct3DDevice9->GetVertexDeclaration(ppDecl);
}

HRESULT IDirect3DDevice9Proxy::SetFVF(DWORD FVF)
{
    return ptr_Direct3DDevice9->SetFVF(FVF);
}

HRESULT IDirect3DDevice9Proxy::GetFVF(DWORD* pFVF)
{
    return ptr_Direct3DDevice9->GetFVF(pFVF);
}

HRESULT IDirect3DDevice9Proxy::CreateVertexShader(CONST DWORD* pFunction, IDirect3DVertexShader9** ppShader)
{
    return ptr_Direct3DDevice9->CreateVertexShader(pFunction, ppShader);
}

HRESULT IDirect3DDevice9Proxy::SetVertexShader(IDirect3DVertexShader9* pShader)
{
    return ptr_Direct3DDevice9->SetVertexShader(pShader);
}

HRESULT IDirect3DDevice9Proxy::GetVertexShader(IDirect3DVertexShader9** ppShader)
{
    return ptr_Direct3DDevice9->GetVertexShader(ppShader);
}

HRESULT IDirect3DDevice9Proxy::SetVertexShaderConstantF(UINT StartRegister, CONST float* pconstantData, UINT Vector4fCount)
{
    return ptr_Direct3DDevice9->SetVertexShaderConstantF(StartRegister, pconstantData, Vector4fCount);
}

HRESULT IDirect3DDevice9Proxy::GetVertexShaderConstantF(UINT StartRegister, float* pconstantData, UINT Vector4fCount)
{
    return ptr_Direct3DDevice9->GetVertexShaderConstantF(StartRegister, pconstantData, Vector4fCount);
}

HRESULT IDirect3DDevice9Proxy::SetVertexShaderConstantI(UINT StartRegister, CONST int* pconstantData, UINT Vector4iCount)
{
    return ptr_Direct3DDevice9->SetVertexShaderConstantI(StartRegister, pconstantData, Vector4iCount);
}

HRESULT IDirect3DDevice9Proxy::GetVertexShaderConstantI(UINT StartRegister, int* pconstantData, UINT Vector4iCount)
{
    return ptr_Direct3DDevice9->GetVertexShaderConstantI(StartRegister, pconstantData, Vector4iCount);
}

HRESULT IDirect3DDevice9Proxy::SetVertexShaderConstantB(UINT StartRegister, CONST BOOL* pconstantData, UINT BoolCount)
{
    return ptr_Direct3DDevice9->SetVertexShaderConstantB(StartRegister, pconstantData, BoolCount);
}

HRESULT IDirect3DDevice9Proxy::GetVertexShaderConstantB(UINT StartRegister, BOOL* pconstantData, UINT BoolCount)
{
    return ptr_Direct3DDevice9->GetVertexShaderConstantB(StartRegister, pconstantData, BoolCount);
}

HRESULT IDirect3DDevice9Proxy::SetStreamSource(UINT StreamNumber, IDirect3DVertexBuffer9* pStreamData, UINT OffsetInBytes, UINT Stride)
{
    return ptr_Direct3DDevice9->SetStreamSource(StreamNumber, pStreamData, OffsetInBytes, Stride);
}

HRESULT IDirect3DDevice9Proxy::GetStreamSource(UINT StreamNumber, IDirect3DVertexBuffer9** ppStreamData, UINT* OffsetInBytes, UINT* pStride)
{
    return ptr_Direct3DDevice9->GetStreamSource(StreamNumber, ppStreamData, OffsetInBytes, pStride);
}

HRESULT IDirect3DDevice9Proxy::SetStreamSourceFreq(UINT StreamNumber, UINT Divider)
{
    return ptr_Direct3DDevice9->SetStreamSourceFreq(StreamNumber, Divider);
}

HRESULT IDirect3DDevice9Proxy::GetStreamSourceFreq(UINT StreamNumber, UINT* Divider)
{
    return ptr_Direct3DDevice9->GetStreamSourceFreq(StreamNumber, Divider);
}

HRESULT IDirect3DDevice9Proxy::SetIndices(IDirect3DIndexBuffer9* pIndexData)
{
    return ptr_Direct3DDevice9->SetIndices(pIndexData);
}

HRESULT IDirect3DDevice9Proxy::GetIndices(IDirect3DIndexBuffer9** ppIndexData)
{
    return ptr_Direct3DDevice9->GetIndices(ppIndexData);
}

HRESULT IDirect3DDevice9Proxy::CreatePixelShader(CONST DWORD* pFunction, IDirect3DPixelShader9** ppShader)
{
    return ptr_Direct3DDevice9->CreatePixelShader(pFunction, ppShader);
}

HRESULT IDirect3DDevice9Proxy::SetPixelShader(IDirect3DPixelShader9* pShader)
{
    return ptr_Direct3DDevice9->SetPixelShader(pShader);
}

HRESULT IDirect3DDevice9Proxy::GetPixelShader(IDirect3DPixelShader9** ppShader)
{
    return ptr_Direct3DDevice9->GetPixelShader(ppShader);
}

HRESULT IDirect3DDevice9Proxy::SetPixelShaderConstantF(UINT StartRegister, CONST float* pconstantData, UINT Vector4fCount)
{
    return ptr_Direct3DDevice9->SetPixelShaderConstantF(StartRegister, pconstantData, Vector4fCount);
}

HRESULT IDirect3DDevice9Proxy::GetPixelShaderConstantF(UINT StartRegister, float* pconstantData, UINT Vector4fCount)
{
    return ptr_Direct3DDevice9->GetPixelShaderConstantF(StartRegister, pconstantData, Vector4fCount);
}

HRESULT IDirect3DDevice9Proxy::SetPixelShaderConstantI(UINT StartRegister, CONST int* pconstantData, UINT Vector4iCount)
{
    return ptr_Direct3DDevice9->SetPixelShaderConstantI(StartRegister, pconstantData, Vector4iCount);
}

HRESULT IDirect3DDevice9Proxy::GetPixelShaderConstantI(UINT StartRegister, int* pconstantData, UINT Vector4iCount)
{
    return ptr_Direct3DDevice9->GetPixelShaderConstantI(StartRegister, pconstantData, Vector4iCount);
}

HRESULT IDirect3DDevice9Proxy::SetPixelShaderConstantB(UINT StartRegister, CONST BOOL* pconstantData, UINT BoolCount)
{
    return ptr_Direct3DDevice9->SetPixelShaderConstantB(StartRegister, pconstantData, BoolCount);
}

HRESULT IDirect3DDevice9Proxy::GetPixelShaderConstantB(UINT StartRegister, BOOL* pconstantData, UINT BoolCount)
{
    return ptr_Direct3DDevice9->GetPixelShaderConstantB(StartRegister, pconstantData, BoolCount);
}

HRESULT IDirect3DDevice9Proxy::DrawRectPatch(UINT Handle, CONST float* pNumSegs, CONST D3DRECTPATCH_INFO* pRectPatchInfo)
{
    return ptr_Direct3DDevice9->DrawRectPatch(Handle, pNumSegs, pRectPatchInfo);
}

HRESULT IDirect3DDevice9Proxy::DrawTriPatch(UINT Handle, CONST float* pNumSegs, CONST D3DTRIPATCH_INFO* pTriPatchInfo)
{
    return ptr_Direct3DDevice9->DrawTriPatch(Handle, pNumSegs, pTriPatchInfo);
}

HRESULT IDirect3DDevice9Proxy::DeletePatch(UINT Handle)
{
    return ptr_Direct3DDevice9->DeletePatch(Handle);
}

HRESULT IDirect3DDevice9Proxy::CreateQuery(D3DQUERYTYPE Type, IDirect3DQuery9** ppQuery)
{
    return ptr_Direct3DDevice9->CreateQuery(Type, ppQuery);
}

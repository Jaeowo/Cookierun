#include "yaTile.h"
#include "yaCamera.h"
#include "yaImage.h"

namespace ya
{



    Tile::Tile(Vector2 pos)
        : GameObject(pos)
        , mAtlas(nullptr)
        , mY(-1)
        , mX(-1)
    {
    }

    Tile::~Tile()
    {
    }

    void Tile::Initiailize(Image* atlas, int index)
    {
        mIndex = index;
        if (atlas == nullptr || index < 0)
            return;

        mAtlas = atlas;

        int maxColumn = mAtlas->GetWidth() / TILE_SIZE_X;
        int maxRow = mAtlas->GetHeight() / TILE_SIZE_Y;

        mY = index / maxColumn;
        mX = index % maxColumn;
    }

    void Tile::Tick()
    {
    }

    void Tile::Render(HDC hdc)
    {
        if (mAtlas == nullptr)
            return;

        Vector2 renderPos = Camera::CalculatePos(GetPos());
        
        int tileImgY = mY * TILE_SIZE_Y;
        int tileImgX = mX * TILE_SIZE_X;

        TransparentBlt(hdc, renderPos.x, renderPos.y
            , TILE_SIZE_X * TILE_SCALE, TILE_SIZE_Y * TILE_SCALE
            , mAtlas->GetDC(), tileImgX, tileImgY
            , TILE_SIZE_X , TILE_SIZE_Y
            , RGB(255, 0, 255));
    }

    void Tile::SetIndex(UINT index)
    {
        mIndex = index;

        int maxColumn = mAtlas->GetWidth() / TILE_SIZE_X;
        int maxRow = mAtlas->GetHeight() / TILE_SIZE_Y;

        mY = index / maxColumn;
        mX = index % maxColumn;
    }

}

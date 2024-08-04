#pragma once

class Color4
    : public Color3
{
public:
    // 생성자
    Color4() : Color3(), alpha(1.0f) {}
    Color4(UINT32 rgb, float alpha = 1.0f) : Color3(rgb), alpha(alpha) {}
    Color4(uint8_t r, uint8_t g, uint8_t b, float alpha = 1.0f)
        : Color3(r, g, b) { SetAlpha(alpha); }
    // Alpha 값을 설정하는 메서드
    void SetAlpha(float _alpha)
    {
        _alpha = Math::Clamp(_alpha, 0.0f, 1.0f);
    }
    float  alpha;
private:
   
};
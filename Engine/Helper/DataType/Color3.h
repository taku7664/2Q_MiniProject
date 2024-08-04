#pragma once

class Color3
{
public:
    // 생성자
    Color3() : rgb(0){}
    Color3(UINT32 rgb) : rgb(rgb) {}
    Color3(uint8_t r, uint8_t g, uint8_t b) { SetRGB(r, g, b); }

    // RGB 값을 설정하는 메서드
    void SetRGB(uint8_t r, uint8_t g, uint8_t b)
    {
        rgb = (r << 16) | (g << 8) | b;
    }

    uint8_t R() const { return (rgb >> 16) & 0xFF; }
    uint8_t G() const { return (rgb >> 8) & 0xFF; }
    uint8_t B() const { return rgb & 0xFF; }

    UINT32 rgb;

private:

};


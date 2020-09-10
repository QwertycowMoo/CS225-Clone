#include "StickerSheet.h"

namespace cs225{
    StickerSheet::StickerSheet(Image image, int numImage){}
    StickerSheet::~StickerSheet(){}
    StickerSheet::StickerSheet(const StickerSheet &other){}
    const StickerSheet & StickerSheet::operator= (const StickerSheet &other){return other;}
    void StickerSheet::changeMaxStickers(unsigned max){}
    int StickerSheet::addSticker(Image &sticker, unsigned x, unsigned y){return 0;}
    bool StickerSheet::translate(unsigned index, unsigned x, unsigned y){return true;}
    void StickerSheet::removeSticker(unsigned index){}
    Image* StickerSheet::getSticker(unsigned index){return new Image();}
    Image StickerSheet::render() const{return Image();}
}

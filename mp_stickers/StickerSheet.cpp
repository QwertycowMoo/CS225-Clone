#include "StickerSheet.h"
#include "cs225/HSLAPixel.h"
#include "Image.h"
namespace cs225{
    StickerSheet::StickerSheet(Image image, int numImage){
        numStickers_ = numImage - 1;
        imgArr_ = new Image[numImage];
        xyPos_ = new int[numImage*2];
        if (numStickers_ >= 0) {
            addSticker(image, 0, 0);
        }
    }
    StickerSheet::~StickerSheet(){
       _clear();
    }
    StickerSheet::StickerSheet(const StickerSheet &other){
        _clear();
        _copy(other);
    }
    const StickerSheet & StickerSheet::operator= (const StickerSheet &other){
        _copy(other);
        return other;
    }
    void StickerSheet::changeMaxStickers(unsigned max){
        /*
        Image* newImgArr = new Image[max];
        int* newXyPos = new int[max * 2];
        for (int i = 0; i < max; i++) {
            newImgArr[i] = imgArr_[i];
            newXyPos[i] = xyPos_[i];
        }
        _clear();
        imgArr_ = newImgArr
        xyPos_ = newXyPos;
        */
        //gotta check this for memory leakage
    }
    int StickerSheet::addSticker(Image &sticker, unsigned x, unsigned y){
        for (int i = 0; i < numStickers_; i++) {
            if (&imgArr_[i] == NULL) {
                imgArr_[i] = sticker;
                xyPos_[i * 1] = x;
                xyPos_[i * 2] = y;
                return 0;
            }
        }
        return -1;
    }
    bool StickerSheet::translate(unsigned index, unsigned x, unsigned y){return true;}
    void StickerSheet::removeSticker(unsigned index){}
    Image* StickerSheet::getSticker(unsigned index) const {return new Image();}
    Image StickerSheet::render() const{
        //finding the max x and y pixels for the image
        unsigned maxX = 0;
        unsigned maxY = 0;
        for (int i = 0; i < numStickers_; i++) {
            unsigned xPos = imgArr_[i].width() + xyPos_[i * 1];
            if (xPos > maxX) {
                maxX = xPos;
            }
            unsigned yPos = imgArr_[i].height() + xyPos_[i * 2];
            if (yPos > maxY) {
                maxY = yPos;
            }
        }
        Image render(maxX, maxY);
        //Now applying each sticker onto the stickersheet
        for (int i = 0; i < numStickers_; i++) {
            Image sticker = imgArr_[i];
            int xPos = xyPos_[i * 1];
            int yPos = xyPos_[i * 2];
            for (unsigned x = 0; x < sticker.width(); x++) {
                for (unsigned y = 0; y < sticker.height(); y++) {
                    HSLAPixel & renderPixel =  render.getPixel(x + xPos, y + yPos);
                    if (renderPixel.a != 0) {
                        renderPixel = sticker.getPixel(x,y);
                    }
                    

                }
            }
        }
        return render;
    }
    int StickerSheet::getNumStickers() const {
        return numStickers_;
    }
    void StickerSheet::_copy(StickerSheet const & other) {
        //need to make a deep copy of all the images
        numStickers_ = other.getNumStickers();
        for (int i = 0; i < numStickers_; i++) {
            if (other.getSticker(i) != NULL) {
                imgArr_[i] = *(other.getSticker(i));
            }
            
        }
    }
    void StickerSheet::_clear() {
        delete[] imgArr_;
        delete[] xyPos_;
    }
}

#include "StickerSheet.h"
#include "cs225/HSLAPixel.h"
#include "Image.h"
#include <iostream>


namespace cs225{
    StickerSheet::StickerSheet(Image image, int numImage){
        numStickers_ = numImage + 1; //since the first image is the background image, we need 1 more than then numImages defined
        imgArr_ = new Image[numImage + 1]; 
        xyPos_ = new unsigned[(numImage + 1)*2];
        
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
        unsigned trueMax = max + 1;
        Image* newImgArr = new Image[trueMax];
        unsigned* newXyPos = new unsigned[(trueMax) * 2];
        unsigned min;
        if (trueMax <= (unsigned) numStickers_) {
            min = trueMax;
        } else {
            min = numStickers_;
        }
        for (unsigned i = 0; i < min; i++) {
            newImgArr[i] = imgArr_[i];
            newXyPos[i * 2] = xyPos_[i * 2];
            newXyPos[i * 2 + 1] = xyPos_[i * 2 + 1];
        }
        _clear();
        numStickers_ = (int) trueMax;
        imgArr_ = newImgArr;
        xyPos_ = newXyPos;
        
        //gotta check this for memory leakage
    }
    int StickerSheet::addSticker(Image &sticker, unsigned x, unsigned y){
        for (int i = 0; i < numStickers_; i++) {
            if (imgArr_[i].width() == 0 and imgArr_[i].height() == 0) {
                std::cout << "adding sticker: " << sticker << std::endl;
                imgArr_[i] = sticker;
                xyPos_[i * 2] = x;
                xyPos_[(i * 2) + 1] = y;
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
            if (imgArr_[i].width() != 0 and imgArr_[i].height() != 0) {
                unsigned xPos = imgArr_[i].width() + xyPos_[i * 2];
                if (xPos > maxX) {
                    maxX = xPos;
                }
                unsigned yPos = imgArr_[i].height() + xyPos_[(i * 2) + 1];
                if (yPos > maxY) {
                    maxY = yPos;
                }
            }
            
        }
        Image renderImg(maxX, maxY);
        //Now applying each sticker onto the stickersheet
        
        for (int i = 0; i < numStickers_; i++) {
            Image sticker = imgArr_[i];
            if (sticker.width() != 0 and sticker.height() != 0) {
                int xPos = xyPos_[i * 2];
                int yPos = xyPos_[i * 2 + 1];
                for (unsigned x = 0; x < sticker.width(); x++) {
                    for (unsigned y = 0; y < sticker.height(); y++) {
                        HSLAPixel& renderPixel =  renderImg.getPixel(x + xPos, y + yPos);
                        HSLAPixel& stickerPixel = sticker.getPixel(x, y);
                        if (stickerPixel.a != 0) {
                            renderPixel = sticker.getPixel(x,y);
                        }
                    }
                }
            }
        }
        
        return renderImg;
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

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
        imgArr_ = nullptr;
        xyPos_ = nullptr;
        _copy(other);
    }
    const StickerSheet & StickerSheet::operator= (const StickerSheet &other){
        _clear();
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
                imgArr_[i] = sticker;
                xyPos_[i * 2] = x;
                xyPos_[(i * 2) + 1] = y;
                return 0;
            }
        }
        return -1;
    }
    bool StickerSheet::translate(unsigned index, unsigned x, unsigned y){
        int trueIndex = (int) index + 1;
        if (trueIndex < numStickers_) {
            
            if (imgArr_[trueIndex].width() != 0 && imgArr_[trueIndex].height() != 0) {
                xyPos_[(trueIndex) * 2] = x;
                xyPos_[(trueIndex) * 2 + 1] = y;
                return true;
            } else {
                return false;
            }
            
        }
        return false;
       
    }
    void StickerSheet::removeSticker(unsigned index){
        imgArr_[index + 1].resize(0,0);
    }
    Image* StickerSheet::getSticker(unsigned index) const {
        Image* toGet = &imgArr_[index + 1];
        if (toGet->width() != 0 && toGet->height() != 0){
            return toGet;
        } else {
            return NULL;
        }
        
        
    }
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

    int StickerSheet::getxPos(int i) const {
        return xyPos_[i * 2];
    }

    int StickerSheet::getyPos(int i) const {
        return xyPos_[i * 2 + 1];
    }

    void StickerSheet::_copy(StickerSheet const & other) {
        //need to make a deep copy of all the images
        numStickers_ = other.getNumStickers();
        Image* newImgArr = new Image[numStickers_];
        unsigned* newXyPos = new unsigned[(numStickers_) * 2];
        //get "background" sticker
        newImgArr[0] = *(other.getSticker(-1));

        for (int i = 0; i < numStickers_; i++) {
            if (other.getSticker(i - 1) != nullptr) {
                Image otherSticker = *(other.getSticker(i - 1));
                if (otherSticker.width() != 0 && otherSticker.height() != 0) {
                    newImgArr[i] = otherSticker;
                    newXyPos[i * 2] = other.getxPos(i);
                    newXyPos[i * 2 + 1] = other.getyPos(i);
                }   
            } else {
                newImgArr[i] = Image();
                newXyPos[i * 2] = 0;
                newXyPos[i * 2 + 1] = 0;
            }
        }
        imgArr_ = newImgArr;
        xyPos_ = newXyPos;
    }
    void StickerSheet::_clear() {
        if (imgArr_ != nullptr) {
            delete[] imgArr_;
        }
        if (xyPos_ != nullptr) {
            delete[] xyPos_;
        }
        
        
    }
    
}

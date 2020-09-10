#include "Image.h"
namespace cs225 {
    Image::Image(): PNG{}{
    }
    Image::Image(unsigned width, unsigned height): PNG{width, height}{
    }
    void Image::lighten() {
        for (unsigned x = 0; x < width(); x++) {
            for (unsigned y = 0; y < height(); y++) {
            HSLAPixel & pixel = getPixel(x, y);
                if (pixel.l + .1 <= 1) {
                    pixel.l += .1;
                } else {
                    pixel.l = 1.0;
                }
            }
        }   
    }
    void Image::lighten(double amt) {
        for (unsigned x = 0; x < width(); x++) {
            for (unsigned y = 0; y < height(); y++) {
            HSLAPixel & pixel = getPixel(x, y);
                if (pixel.l + amt <= 1) {
                    pixel.l += .1;
                } else {
                    pixel.l = 1.0;
                }
            }
        }  
    };
    void Image::darken() {
        for (unsigned x = 0; x < width(); x++) {
            for (unsigned y = 0; y < height(); y++) {
                HSLAPixel & pixel = getPixel(x, y);
                if (pixel.l - .1 >= 0) {
                    pixel.l -= .1;
                } else {
                    pixel.l = 0;
                }
            }
        } 
    }
    void Image::darken(double amt){
        for (unsigned x = 0; x < width(); x++) {
            for (unsigned y = 0; y < height(); y++) {
                HSLAPixel & pixel = getPixel(x, y);
                if (pixel.l - amt >= 0) {
                    pixel.l -= amt;
                } else {
                    pixel.l = 0;
                }
            }
        } 
    }
    void Image::saturate() {
        for (unsigned x = 0; x < width(); x++) {
            for (unsigned y = 0; y < height(); y++) {
                HSLAPixel & pixel = getPixel(x, y);
                if (pixel.s + .1 <= 1) {
                    pixel.s += .1;
                } else {
                    pixel.s = 1;
                }
            }
        } 
    }
    void Image::saturate(double amt) {
        for (unsigned x = 0; x < width(); x++) {
            for (unsigned y = 0; y < height(); y++) {
                HSLAPixel & pixel = getPixel(x, y);
                if (pixel.s + amt <= 1) {
                    pixel.s += amt;
                } else {
                    pixel.s = 1;
                }
            }
        }        
    }
    void Image::desaturate() {
        for (unsigned x = 0; x < width(); x++) {
            for (unsigned y = 0; y < height(); y++) {
                HSLAPixel & pixel = getPixel(x, y);
                if (pixel.s - .1 >= 0) {
                    pixel.s -= .1;
                } else {
                    pixel.s = 0;
                }
            }
        } 
    }
    
    void Image::desaturate(double amt) {
        for (unsigned x = 0; x < width(); x++) {
            for (unsigned y = 0; y < height(); y++) {
                HSLAPixel & pixel = getPixel(x, y);
                if (pixel.s - amt >= 0) {
                    pixel.s -= amt;
                } else {
                    pixel.s = 0;
                }
            }
        } 
    }
    
    void Image::rotateColor(double degrees){
        for (unsigned x = 0; x < width(); x++) {
            for (unsigned y = 0; y < height(); y++) {
                HSLAPixel & pixel = getPixel(x, y);
                pixel.h = pixel.h + degrees;
                while (pixel.h >= 360) {
                    pixel.h -= 360;
                }
                while (pixel.h <= 0) {
                    pixel.h += 360;
                }
            }
        } 
    }
    void Image::illinify(){
        for (unsigned x = 0; x < width(); x++) {
            for (unsigned y = 0; y < height(); y++) {
            HSLAPixel & pixel = getPixel(x, y);
                if (pixel.h > 113.5 and pixel.h < 293.5) {
                //turn into blue
                pixel.h = 216;
                } else {
                pixel.h = 11;
                }
            }
        }
    }
    void Image::scale(double factor){
        unsigned newWidth = width()*factor;
        unsigned newHeight = height()*factor;
        Image scaledImg(newWidth, newHeight);
        for (unsigned x = 0; x < newWidth; x++) {
            for (unsigned y = 0; y < newHeight; y++) {
                HSLAPixel & newPixel = scaledImg.getPixel(x,y);
                newPixel = getPixel(x/factor, y/factor); //integer division so it should just throw away the remainder
            }   
        }
        *this = scaledImg;

    }
    void Image::scale(unsigned w, unsigned h){
        writeToFile("oldPNGScale.png");
        double xScale = (double) w / width();
        double yScale = (double) h / height();
        Image scaledImg(w, h);
        for (unsigned x = 0; x < w; x++) {
            for (unsigned y = 0; y < h; y++) {
                HSLAPixel & newPixel = scaledImg.getPixel(x,y);
                newPixel = getPixel(x/xScale, y/yScale); //integer division so it should just throw away the remainder
            }   
        }
        *this = scaledImg;
        writeToFile("newPNGScale.png");
    }
}

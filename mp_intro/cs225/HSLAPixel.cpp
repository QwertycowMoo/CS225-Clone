/**
 * @file HSLAPixel.cpp
 * Implementation of the HSLAPixel class for use in with the PNG library.
 *
 * @author CS 225: Data Structures
 * @version 2018r1-lab1
 */

#include "HSLAPixel.h"
#include <cmath>
#include <iostream>
using namespace std;

namespace cs225 {
    HSLAPixel::HSLAPixel() {
        h = 0.0;
        s = 0.0;
        l = 1.0;
        a = 1.0;
    }
    HSLAPixel::HSLAPixel(double hue, double saturation, double luminance) {
        if (hue < 360 && hue >= 0) {
            h = hue;
        } else {
            h = 0.0;
        }
        if (saturation <= 1 && saturation >= 0) {
            s = saturation;
        } else {
            s = 0.0;
        }
        if (luminance <= 1 && luminance >= 0) {
            l = luminance;
        } else {
            l = 1.0;
        }
        a = 1.0;
    }
    HSLAPixel::HSLAPixel(double hue, double saturation, double luminance, double alpha){
        if (hue < 360 && hue >= 0) {
            h = hue;
        } else {
            h = 0.0;
        }
        if (saturation <= 1 && saturation >= 0) {
            s = saturation;
        } else {
            s = 0.0;
        }
        if (luminance <= 1 && luminance >= 0) {
            l = luminance;
        } else {
            l = 1.0;
        }
        if (alpha <= 1 && luminance >= 0) {
            a = alpha;
        } else {
            a = 1.0;
        }
        
    }
        
}

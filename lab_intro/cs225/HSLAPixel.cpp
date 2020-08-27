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
        h_ = 0.0
        s_ = 0.0
        l_ = 1.0
        a_ = 1.0
    }
    HSLAPixel::HSLAPixel(double hue, double saturation, double luminance) {
        h_ = hue;
        s_ = saturation;
        l_ = luminance;
        a_ = 1.0
    }
    HSLAPixel::HSLAPixel(double hue, double saturation, double luminance, double alpha){
        h_ = hue;
        s_ = saturation;
        l_ = luminance;
        a_ = alpha;
    }
        
}

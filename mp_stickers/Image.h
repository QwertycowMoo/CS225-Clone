/**
 * @file Image.h
 * Contains your declaration of the interface for the Image class.
 */
 #include "cs225/PNG.h"


#pragma once
namespace cs225 {
    class Image : public PNG {
        public:
            Image();
            Image(unsigned width, unsigned height);
            void lighten();
            void lighten(double amt);
            void darken();
            void darken(double amt);
            void saturate();
            void saturate(double amt);
            void desaturate();
            void desaturate(double amt);
            void rotateColor(double degrees);
            void illinify();
            void scale(double factor);
            void scale(unsigned w, unsigned h);
    };
}



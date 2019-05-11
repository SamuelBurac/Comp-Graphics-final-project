/*
    This file is part of Dirt, the Dartmouth introductory ray tracer, used in
    Dartmouth's COSC 77/177 Computer Graphics course.

    Copyright (c) 2018 by Wojciech Jarosz

    Dirt is free software; you can redistribute it and/or modify
    it under the terms of the GNU General Public License Version 3
    as published by the Free Software Foundation.

    Dirt is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program. If not, see <http://www.gnu.org/licenses/>.

    ------------------------------------------------------------------------

    A portion of the code is taken from the Nori Color3f class:

    Copyright (c) 2015 by Wenzel Jakob, Romain Prévost
*/

#pragma once

#include <Eigen/Core>    // for Array3f
#include <iosfwd>        // for string


//! Represents a linear RGB color value
class Color3f : public Eigen::Array3f
{
public:
    using Base = Eigen::Array3f;

    //! Initialize the color vector with a uniform value
    Color3f(float value = 0.f) : Base(value, value, value) {}

    //! Initialize the color vector with specific per-channel values
    Color3f(float r, float g, float b) : Base(r, g, b) {}

    //! Construct a color vector from ArrayBase (needed to play nice with Eigen)
    template <typename Derived>
    Color3f(const Eigen::ArrayBase<Derived>&p) : Base(p) {}

    //! Assign a color vector from ArrayBase (needed to play nice with Eigen)
    template <typename Derived>
    Color3f & operator=(const Eigen::ArrayBase<Derived>&p)
    {
        this->Base::operator=(p);
        return *this;
    }

    //! Return a reference to the red channel
    float & r() {return x();}
    //! Return a reference to the red channel (const version)
    const float & r() const {return x();}
    //! Return a reference to the green channel
    float & g() {return y();}
    //! Return a reference to the green channel (const version)
    const float & g() const {return y();}
    //! Return a reference to the blue channel
    float & b() {return z();}
    //! Return a reference to the blue channel (const version)
    const float & b() const {return z();}

    //! Clamp to the positive range
    Color3f clamp() const;

    //! Check if the color vector contains a NaN/Inf/negative value
    bool isValid() const;

    //! Convert from sRGB to linear RGB
    Color3f toLinearRGB() const;

    //! Convert from linear RGB to sRGB
    Color3f toSRGB() const;

    //! Return the associated luminance
    float getLuminance() const;
};

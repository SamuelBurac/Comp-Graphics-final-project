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
*/

#pragma once

#include "surface.h"


//! A collection of Surfaces grouped together.
/*!
    Provides an interface for treating a collection of Surfaces as a single 
    Surface. This base class implements a naive linear-time intersection 
    routine which simply intersects each ray with every child Surface.
    
    This class also serves as the superclass for acceleration structures (such 
    as BVHs, KD-Trees) which are responsible for performing ray-surface 
    intersection tests against a collection of Surfaces.
 */
class SurfaceGroup : public Surface
{
public:
    //! Create a new and empty naive accelerator
    SurfaceGroup(const Scene & scene, const json & j = json::object()) : Surface(scene, j) {}
    SurfaceGroup() {}

    //! Release all resources
    ~SurfaceGroup() override
    {
        clear();
    }

    //! Return the surface's local-space AABB.
    AABB3f localBBox() const override;

    //! Release all resources
    virtual void clear();

    void addChild(Surface *surface) override;

    //! Intersect a ray against all surfaces registered with the Accelerator.
    /*!
        Detailed information about the intersection, if any, will be stored
        in the provided @ref its data record.

        @return
            @c true If an intersection was found
    */
    bool intersect(const Ray3f &ray, HitInfo &hit) const override;

protected:

    std::vector<Surface *> m_surfaces;  //!< All children of the aggregate
    AABB3f m_localBBox;
};

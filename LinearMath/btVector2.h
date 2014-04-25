//
//  btVector2.h
//  GameAsteroids
//
//  Created by James Folk on 5/13/13.
//  Copyright (c) 2013 James Folk. All rights reserved.
//

#ifndef __GameAsteroids__btVector2__
#define __GameAsteroids__btVector2__

#include "btScalar.h"
#include "btVector3.h"

#ifdef BT_USE_DOUBLE_PRECISION
#define btVector2Data btVector2DoubleData
#define btVector2DataName "btVector2DoubleData"
#else
#define btVector2Data btVector2FloatData
#define btVector2DataName "btVector2FloatData"
#endif //BT_USE_DOUBLE_PRECISION

/** @name 2D points and vectors
 *
 * Available functions are similar to btVector3 ones.
 * Values are stored in public x and y attributes for convenience.
 */
//@{
ATTRIBUTE_ALIGNED16(class) btVector2
{
public:
    
	BT_DECLARE_ALIGNED_ALLOCATOR();
public:
    btScalar xy_[4];
    
public:
    SIMD_FORCE_INLINE btVector2() {}
    SIMD_FORCE_INLINE btVector2(const btScalar& x, const btScalar& y) { xy_[0] = x; xy_[1] = y; }
    SIMD_FORCE_INLINE btVector2(const btVector2& v)
    {
        xy_[0] = v.xy_[0];
        xy_[1] = v.xy_[1];
    }
    SIMD_FORCE_INLINE btVector2(const btVector3& v3)
    {
        xy_[0] = v3.x();
        xy_[1] = v3.y();
    }
    SIMD_FORCE_INLINE operator btVector3() const { return btVector3(xy_[0], xy_[1], 0); }
    
    SIMD_FORCE_INLINE operator const btScalar* () const { return xy_; }
    SIMD_FORCE_INLINE const btScalar& x() const { return xy_[0]; }
    SIMD_FORCE_INLINE const btScalar& y() const { return xy_[1]; }
    SIMD_FORCE_INLINE void setX(const btScalar& x) { xy_[0] = x; }
    SIMD_FORCE_INLINE void setY(const btScalar& y) { xy_[1] = y; }
    
    SIMD_FORCE_INLINE btVector2& operator=(const btVector2& v) { if(this != &v){xy_[0] = v.xy_[0]; xy_[1] = v.xy_[1];} return *this; }
    SIMD_FORCE_INLINE btVector2& operator+=(const btVector2& v) { xy_[0] += v.xy_[0]; xy_[1] += v.xy_[1]; return *this; }
    SIMD_FORCE_INLINE btVector2& operator-=(const btVector2& v) { xy_[0] -= v.xy_[0]; xy_[1] -= v.xy_[1]; return *this; }
    SIMD_FORCE_INLINE btVector2& operator*=(const btVector2& v) { xy_[0] *= v.xy_[0]; xy_[1] *= v.xy_[1]; return *this; }
    SIMD_FORCE_INLINE btVector2& operator*=(const btScalar& s) { xy_[0] *= s; xy_[1] *= s; return *this; }
    SIMD_FORCE_INLINE btVector2& operator/=(const btScalar& s) { btFullAssert(s != btScalar(0.0)); return *this *= btScalar(1.0) / s; }
    SIMD_FORCE_INLINE btScalar dot(const btVector2& v) const { return xy_[0] * v.xy_[0] + xy_[1] * v.xy_[1]; }
    SIMD_FORCE_INLINE btScalar length2() const { return dot(*this); }
    SIMD_FORCE_INLINE btScalar length () const { return btSqrt(length2()); }
    SIMD_FORCE_INLINE btScalar distance2(const btVector2& v) const;
    SIMD_FORCE_INLINE btScalar distance (const btVector2& v) const;
    SIMD_FORCE_INLINE btVector2& normalize() { return *this /= length(); }
    SIMD_FORCE_INLINE btVector2 normalized() const;
    
    SIMD_FORCE_INLINE btVector2& rotate(const btScalar angle);
    SIMD_FORCE_INLINE btVector2 rotated(const btScalar angle) const;
    SIMD_FORCE_INLINE btVector2 absolute() const { return btVector2( btFabs(xy_[0]), btFabs(xy_[1]) ); }
    SIMD_FORCE_INLINE btScalar angle() const { return btAtan2(xy_[1], xy_[0]); }
    SIMD_FORCE_INLINE	void	serializeFloat(struct	btVector2FloatData& dataOut) const;
    SIMD_FORCE_INLINE void	deSerializeFloat(const struct	btVector2FloatData& dataIn);
    SIMD_FORCE_INLINE	void	serializeDouble(struct	btVector2DoubleData& dataOut) const;
    SIMD_FORCE_INLINE void	deSerializeDouble(const struct	btVector2DoubleData& dataIn);
    SIMD_FORCE_INLINE	void	serialize(struct	btVector2Data& dataOut) const;
    SIMD_FORCE_INLINE void	deSerialize(const struct	btVector2Data& dataIn);


};

SIMD_FORCE_INLINE btVector2 operator+(const btVector2& v1, const btVector2& v2) { return btVector2(v1.xy_[0]+v2.xy_[0], v1.xy_[1]+v2.xy_[1]); }
SIMD_FORCE_INLINE btVector2 operator-(const btVector2& v1, const btVector2& v2) { return btVector2(v1.xy_[0]-v2.xy_[0], v1.xy_[1]-v2.xy_[1]); }
SIMD_FORCE_INLINE btVector2 operator*(const btVector2& v1, const btVector2& v2) { return btVector2(v1.xy_[0]*v2.xy_[0], v1.xy_[1]*v2.xy_[1]); }
SIMD_FORCE_INLINE btVector2 operator-(const btVector2& v) { return btVector2(-v.xy_[0], -v.xy_[1]); }
SIMD_FORCE_INLINE btVector2 operator*(const btScalar& s, const btVector2& v) { return btVector2(s*v.xy_[0], s*v.xy_[1]); }
SIMD_FORCE_INLINE btVector2 operator*(const btVector2& v, const btScalar& s) { return s*v; }
SIMD_FORCE_INLINE btVector2 operator/(const btVector2& v, const btScalar& s) { btFullAssert(s != btScalar(0.0)); return v * (btScalar(1.0)/s); }
SIMD_FORCE_INLINE bool operator==(const btVector2& v1, const btVector2& v2) { return v1.xy_[0] == v2.xy_[0] && v1.xy_[1] == v2.xy_[1]; }
SIMD_FORCE_INLINE bool operator!=(const btVector2& v1, const btVector2& v2) { return !(v1 == v2); }

SIMD_FORCE_INLINE btScalar btVector2::distance2(const btVector2& v) const { return (v - *this).length2(); }
SIMD_FORCE_INLINE btScalar btVector2::distance (const btVector2& v) const { return (v - *this).length(); }
SIMD_FORCE_INLINE btVector2 btVector2::normalized() const { return *this / length(); }
SIMD_FORCE_INLINE btVector2& btVector2::rotate(const btScalar angle)
{
    btVector2 v(-xy_[1], xy_[0]);
    return *this = ( *this * btCos(angle) + v * btSin(angle) );
}
SIMD_FORCE_INLINE btVector2 btVector2::rotated(const btScalar angle) const
{
    btVector2 v(-xy_[1], xy_[0]);
    return ( *this * btCos(angle) + v * btSin(angle) );
}

SIMD_FORCE_INLINE btScalar dot(const btVector2& v1, const btVector2& v2) { return v1.dot(v2); }
SIMD_FORCE_INLINE btScalar distance2(const btVector2& v1, const btVector2& v2) { return v1.distance2(v2); }
SIMD_FORCE_INLINE btScalar distance (const btVector2& v1, const btVector2& v2) { return v1.distance(v2); }
//@}

struct	btVector2FloatData
{
	float	xy_[4];
};

struct	btVector2DoubleData
{
	double	xy_[4];
    
};

SIMD_FORCE_INLINE	void	btVector2::serializeFloat(struct	btVector2FloatData& dataOut) const
{
	///could also do a memcpy, check if it is worth it
	for (int i=0;i<4;i++)
		dataOut.xy_[i] = float(xy_[i]);
}

SIMD_FORCE_INLINE void	btVector2::deSerializeFloat(const struct	btVector2FloatData& dataIn)
{
	for (int i=0;i<4;i++)
		xy_[i] = btScalar(dataIn.xy_[i]);
}


SIMD_FORCE_INLINE	void	btVector2::serializeDouble(struct	btVector2DoubleData& dataOut) const
{
	///could also do a memcpy, check if it is worth it
	for (int i=0;i<4;i++)
		dataOut.xy_[i] = double(xy_[i]);
}

SIMD_FORCE_INLINE void	btVector2::deSerializeDouble(const struct	btVector2DoubleData& dataIn)
{
	for (int i=0;i<4;i++)
		xy_[i] = btScalar(dataIn.xy_[i]);
}


SIMD_FORCE_INLINE	void	btVector2::serialize(struct	btVector2Data& dataOut) const
{
	///could also do a memcpy, check if it is worth it
	for (int i=0;i<4;i++)
		dataOut.xy_[i] = xy_[i];
}

SIMD_FORCE_INLINE void	btVector2::deSerialize(const struct	btVector2Data& dataIn)
{
	for (int i=0;i<4;i++)
		xy_[i] = dataIn.xy_[i];
}

#endif /* defined(__GameAsteroids__btVector2__) */

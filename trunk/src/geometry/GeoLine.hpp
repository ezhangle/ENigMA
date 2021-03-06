// *****************************************************************************
// <ProjectName> ENigMA </ProjectName>
// <Description> Extended Numerical Multiphysics Analysis </Description>
// <HeadURL> $HeadURL$ </HeadURL>
// <LastChangedDate> $LastChangedDate$ </LastChangedDate>
// <LastChangedRevision> $LastChangedRevision$ </LastChangedRevision>
// <Author> Billy Araujo </Author>
// *****************************************************************************

#pragma once

#include "GeoLength.hpp"
#include "GeoCoordinate.hpp"
#include "GeoVector.hpp"
#include "GeoPlane.hpp"

namespace ENigMA
{

    namespace geometry
    {

        enum EIntersectionType {
            IT_NONE = 0,
            IT_VERTEX,
            IT_EDGE,
            IT_COINCIDENT,
            IT_INTERNAL,
            IT_SWAP
        };

        class CGeoIntersectionType {
        private:
            EIntersectionType m_intersectionType;

        public:

            CGeoIntersectionType() : m_intersectionType(IT_NONE) {};
            CGeoIntersectionType(const EIntersectionType anIntersectionType) : m_intersectionType(anIntersectionType) {};

            CGeoIntersectionType operator=(const EIntersectionType& anIntersectionType)
            {

                this->m_intersectionType = anIntersectionType;
                return *this;

            }

            bool operator==(const EIntersectionType& anIntersectionType) const {

                return this->m_intersectionType == anIntersectionType;

            }

        };

        template <typename Real>
        class CGeoLine : public CGeoLength<Real>
        {
        protected:

            CGeoCoordinate<Real> m_startPoint;
            CGeoCoordinate<Real> m_endPoint;

            CGeoVector<Real> m_vector;

        public:
            CGeoLine();
            CGeoLine(CGeoCoordinate<Real>& aPoint1, CGeoCoordinate<Real>& aPoint2);
            ~CGeoLine();

            void reset();

            void setStartPoint(CGeoCoordinate<Real>& aPoint1);
            void setEndPoint(CGeoCoordinate<Real>& aPoint2);

            CGeoCoordinate<Real>& startPoint();
            CGeoCoordinate<Real>& endPoint();
            CGeoVector<Real>& vector();

            CGeoCoordinate<Real> midPoint(Real factor);

            inline void calculateLength(bool bReCalculate = false);
            inline void calculateBoundingBox(bool bReCalculate = false);

            inline CGeoLine<Real> clip(CGeoPlane<Real>& aPlane);

            inline bool intersects(CGeoPlane<Real>& aPlane, CGeoCoordinate<Real>& aPoint, CGeoIntersectionType& anIntersectionType, const Real aTolerance = 0.0);

            inline bool intersects(CGeoLine<Real>& aLine, CGeoIntersectionType& anIntersectionType, const Real aTolerance = 0.0);
            inline bool intersects(CGeoLine<Real>& aLine, CGeoCoordinate<Real>& aPoint, const Real aTolerance = 0.0);
            inline bool intersects(CGeoLine<Real>& aLine, CGeoCoordinate<Real>& aPoint, CGeoIntersectionType& anIntersectionType, const Real aTolerance = 0.0);

            inline bool contains(const CGeoCoordinate<Real>& aPoint, CGeoIntersectionType& anIntersectionType, const Real aTolerance = 0.0);

            inline bool distance(const CGeoCoordinate<Real>& aPoint, CGeoCoordinate<Real>& aNewPoint, Real& aDistance, const Real aTolerance = 0.0);
            inline bool distance(CGeoLine<Real>& aLine, CGeoCoordinate<Real>& aPoint1, CGeoCoordinate<Real>& aPoint2, Real& aDistance, const Real aTolerance = 0.0);

            void invert();

        };

    }

}

#include "GeoLine_Imp.hpp"


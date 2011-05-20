/**
 * \file AzimuthalEquidistant.cpp
 * \brief Implementation for GeographicLib::AzimuthalEquidistant class
 *
 * Copyright (c) Charles Karney (2009, 2010, 2011) <charles@karney.com> and
 * licensed under the LGPL.  For more information, see
 * http://geographiclib.sourceforge.net/
 **********************************************************************/

#include <GeographicLib/AzimuthalEquidistant.hpp>

#define GEOGRAPHICLIB_AZIMUTHALEQUIDISTANT_CPP "$Id: 3c3530a7a2e4795333231580ee3516541c9f198d $"

RCSID_DECL(GEOGRAPHICLIB_AZIMUTHALEQUIDISTANT_CPP)
RCSID_DECL(GEOGRAPHICLIB_AZIMUTHALEQUIDISTANT_HPP)

namespace GeographicLib {

  using namespace std;

  const Math::real AzimuthalEquidistant::eps_ =
    real(0.01) * sqrt(numeric_limits<real>::min());

  void AzimuthalEquidistant::Forward(real lat0, real lon0, real lat, real lon,
                                     real& x, real& y, real& azi, real& rk)
    const throw() {
    real sig, s, azi0, m;
    sig = _earth.Inverse(lat0, lon0, lat, lon, s, azi0, azi, m);
    azi0 *= Math::degree<real>();
    x = s * sin(azi0);
    y = s * cos(azi0);
    rk = !(sig <= eps_) ? m / s : 1;
  }

  void AzimuthalEquidistant::Reverse(real lat0, real lon0, real x, real y,
                                     real& lat, real& lon, real& azi, real& rk)
    const throw() {
    real
      azi0 = atan2(x, y) / Math::degree<real>(),
      s = Math::hypot(x, y);
    real sig, m;
    sig = _earth.Direct(lat0, lon0, azi0, s, lat, lon, azi, m);
    rk = !(sig <= eps_) ? m / s : 1;
  }

} // namespace GeographicLib

function utmups = utmupsforward(latlong, setzone)
%utmupsforward  Convert geographic coordinates to UTM/UPS
%
%   utmups = utmupsforward(latlong);
%   utmups = utmupsforward(latlong, setzone);
%
%   latlong is an M x 2 matrix
%       latitude = latlong(:,1) in degrees
%       longitude = latlong(:,2) in degrees
%
%   utmups is an M x 6 matrix
%       easting = utmups(:,1) in meters
%       northing = utmups(:,2) in meters
%       zone = utmups(:,3)
%       hemi = utmups(:,4)
%       gamma = utmups(:,5) meridian convergence in degrees
%       k = utmups(:,6) scale
%
%   zone = 0 for UPS, zone = [1,60] for UTM
%   hemi = 0 for southern hemisphere, hemi = 1 for northern hemisphere
%
%   setzone is an zone override flag with legal values
%        0, use UPS
%        [1,60], use the corresponding UTM zone
%       -1, use the standard assigment (the default)
%       -2, use closest UTM zone
%
%   This is an interface to the GeographicLib C++ routine
%       UTMUPS::Forward
%   See the documenation on this function for more information.
  error('Error: executing .m file instead of compiled routine');
end
% utmupsforward.m
% Matlab .m file for geographic to UTM/UPS conversions
%
% Copyright (c) Charles Karney (2010) <charles@karney.com> and licensed under
% the LGPL.  For more information, see http://geographiclib.sourceforge.net/
%
% $Id: b81cf582f574543d9510b1d7943b66d9ffab26d5 $

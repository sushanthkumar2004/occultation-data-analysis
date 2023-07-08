#include <stdio.h>
#include <math.h>
#include <sofa.h>
#include "sofam.h"

// Used to define the ellipsoid to use for coordinate system
double EARTH_EQUATORIAL_RADIUS = 6378.137e3;
double EARTH_FLATTENING = 0.003352810665;

int rotation(double vec[3], int axis, double phi, double rotated_vec[3]) {
    /*
    ** − − − − − − − − − −
    **  r o t a t i o n
    ** − − − − − − − − − −
    ** Rotates a given vector vec about axis by 
    ** angle phi in accordance with astronomical 
    ** convenvtions. 
    ** 
    ** Inputs:
    **    vec = vector in xyz coordinates to rotate
    **    axis = 0, 1, or 2, corresponding to x,y,z.
    **    phi = angle to rotate in degrees 
    ** Outputs:
    **    rotated_vec = the rotated vector in xyz coords
    ** Status:
    **    -1 (incorrect axis value)
    **    0 (no errors)
    */
    double rotation_matrix[3][3];
    iauIr(rotation_matrix);

    // Select the correct rotation matrix based on axis
    if (axis == 0) {
        iauRx(phi, rotation_matrix);
    } else if (axis == 1) {
        iauRy(phi, rotation_matrix);
    } else if (axis == 2) {
        iauRz(phi, rotation_matrix);
    } else {
        return -1; 
    }
    
    // Applies the rotation matrix to the vector vec. 
    iauRxp(rotation_matrix, vec, rotated_vec);
    return 0; 
}

int iau_gd2gce(double a, double f, double elong, double phi, double height, double xyz[3]) {
   return iauGd2gce(a, f, elong, phi, height, xyz);
}

int iau_gc2gde(double a, double f, double xyz[3], double *elong, double *phi, double *height) {
   return iauGc2gde(a, f, xyz, *&elong, *&phi, *&height);
}

// int main() {
//    double elong;
//    double phi; 
//    double xyz[3] = {-2699.047780, -3298.128205, 4729.416258}; 
//    double height; 
//    iau_gc2gde(EARTH_EQUATORIAL_RADIUS, EARTH_FLATTENING, xyz, &elong, &phi, &height);
//    printf("%f\n", elong);
//    printf("%f\n", phi);
//    printf("%f\n", height);


//    double cartesian_coords[3]; 
//    iauGd2gce(EARTH_EQUATORIAL_RADIUS, EARTH_FLATTENING, 70, 40, 0, cartesian_coords);

   

//    // printf("%f\n", cartesian_coords[0]);
//    // printf("%f\n", cartesian_coords[1]);
//    // printf("%f\n", cartesian_coords[2]);

//    iau_gd2gce(EARTH_EQUATORIAL_RADIUS, EARTH_FLATTENING, 70, 40, 0, cartesian_coords);

//    // printf("%f\n", cartesian_coords[0]);
//    // printf("%f\n", cartesian_coords[1]);
//    // printf("%f\n", cartesian_coords[2]);
//    return 0; 
// }
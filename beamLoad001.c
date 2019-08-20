/* P-2.10 */
/* BEAM.C */
/* Calculate deflection of supported beam under a central load
   from data supplied in an external text file. */

#include <stdio.h>
#include <stdlib.h>
#define FILE_NAME "beam.dat"

int main(void)
{
  FILE *infile;
  double length,force,elasticity,mom_of_inertia,len2;
  double nume, denom;

  infile = fopen(FILE_NAME,"r");

  fscanf(infile,"%lf %lf %lf %lf",&length,&force,&elasticity,&mom_of_inertia);
  fclose(infile);

  printf("Length of beam (feet): %lf \n\nCentral force (lb): %lf\n\n",length,force);
  len2 = length*12.0;
  nume = force*len2*len2*len2;
  denom = 48.0*elasticity*mom_of_inertia;

  printf("Elasticity (lb/in^2): %lf\n\nMoment of inertia (in^4): %lf\n\n", elasticity, mom_of_inertia);
  printf("deflection = %lf in\n\n", nume/denom);

  return (0);
}

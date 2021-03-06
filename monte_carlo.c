#include <assert.h>
#include <stdlib.h>
#include <stdio.h>
#include <math.h>
float frandom() {
  long int q = random();
  float ret = (float)q/(float)RAND_MAX;
  return ret;
}
float mc_pi(int n){
   int c1=0,c2=0;
    while(n--){
        float coordinate_a=frandom();
        float coordinate_b=frandom();
       float  distance=sqrt(coordinate_a*coordinate_a+coordinate_b*coordinate_b); //applying cartesian formula to find distance
        if(distance<=1){
            c1++; //Points inside the circle
        }
        c2++; // Total number of points


    }
    return 4*(float)c1/c2;
}



int main(void) {
  float pi0;
  float pi1;
  
  pi0 = mc_pi(25000);
  pi1 = mc_pi(25000);
  printf("%f %f\n", pi0, pi1);
  
  if (pi0 == pi1) {
      printf("Two separate estimates of pi are exactly the same. This is unlikely.\n");
      abort();
    }

  if (fabs(pi0 - pi1) > 0.05) {
      printf("Two separate estimates %f and %f are too different.\n", pi0, pi1);
      abort();
  }

    
  for (int i=2000; i<5000; i++) {
    pi0 = mc_pi(i);
    if (!(fabs(pi0 - M_PI) < 0.4)) {
      printf("Estimate with even %d iterations is %f which is not accurate enough.\n", i, pi0);
      abort();
    }
  }
}

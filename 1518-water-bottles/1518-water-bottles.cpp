class Solution {
public:
    int numWaterBottles(int nb, int ne) {
      int ans=0;
    //    while(nb>=ne){
    //    int d=nb/ne;
    //    ans+=(d*ne);
    //    nb-=(d*ne);
    //    nb+=d;
    //    }
       return nb+(nb-1)/(ne-1);
    }
};
// Last updated: 08/03/2026, 13:22:52
class Solution {
public:
    int findClosest(int x, int y, int z) {
  int d1=abs(x-z);
  int d2=abs(y-z);
  if(d1<d2){
    return 1;

  } else if(d2<d1){
    return 2;

  } else {
    return 0;
  }    
    }
};
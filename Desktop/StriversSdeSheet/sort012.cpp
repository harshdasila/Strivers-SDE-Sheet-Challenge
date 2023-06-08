#include <bits/stdc++.h> 
void sort012(int *nums, int n)
{
   //dutch national flag algo
   int low=0,mid=0,high=n-1;
   while(mid<=high){
      switch(nums[mid]){
         case 0:{
            swap(nums[low++],nums[mid++]);
            break;
         }
         case 1:{
            mid++;
            break;
         }
         case 2:{
            swap(nums[mid],nums[high--]);
            break;
         }
      }
   }
}
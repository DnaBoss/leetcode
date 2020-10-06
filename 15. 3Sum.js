Given an array nums of n integers, 
are there elements a, b, c in nums such that a + b + c = 0?
Find all unique triplets in the array which gives the sum of zero.

Notice that the solution set must not contain duplicate triplets.
/**
 * @param {number[]} nums
 * @return {number[][]}
 */
var threeSum = function(nums) {
    nums.sort(function(a,b){
        return a-b;
    })
    var target,result=[],len=nums.length;
    for(var i=0;i<len;i++){
        if (target===nums[i]){
            continue;
        }
        else{
            target=nums[i];
        }
        var low=i+1,high=len-1;
        while(low<high){
            if(nums[low]+nums[high]===-target){
                result.push([target,nums[low],nums[high]]);
                do{
                   low++; 
                }while(nums[low]===nums[low-1]);
            }
            else if(nums[low]+nums[high]<-target){
                low++;
            }
            else{
                high--;
            }
        }
    }
    return result;
};

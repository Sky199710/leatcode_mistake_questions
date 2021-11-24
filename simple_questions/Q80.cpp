/*问题描述：给你一个有序数组 nums ，请你 原地 删除重复出现的元素，使每个元素 最多出现两次 ，返回删除后数组的新长度。
不要使用额外的数组空间，你必须在 原地 修改输入数组 并在使用 O(1) 额外空间的条件下完成。

波波老师的方法，设置三个指针，指针i用于重新装填数组，指针j用于暂存要装填的元素，指针k寻找下一个不同的元素。核心在于每次装填的元素数目len = min(2,k-j)
可以更改最多重复元素数目n,只需将len = min(n,k-j)即可
*/
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int i = 0;
        int j = 0;//用于暂存要保存的元素
        while(j<nums.size()){
            int k = findNextIndex(nums,j);
            int len = min(2,k-j);
            for(int ii=0;ii<len;ii++){
                nums[i++] = nums[j];
            }
            j = k;
        }
        return i;
    }
    int findNextIndex(const vector<int>& nums, int i){
        for(int ii=i;ii<nums.size();ii++){
            if(nums[ii]!=nums[i])
                return ii;
        }
        return nums.size();
    }
};

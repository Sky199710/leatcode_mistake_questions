/*题目描述：给你一个有序数组 nums ，请你 原地 删除重复出现的元素，使每个元素 只出现一次 ，返回删除后数组的新长度。
不要使用额外的数组空间，你必须在 原地 修改输入数组 并在使用 O(1) 额外空间的条件下完成。

分析：本题的思路不难，但是需要注意边界问题，自己写的时候数组容易越界。设置两个指针，一个指针i用来从头开始将不同的数字一个个填入数组，一个指针index用来指示下一个不同的元素。
创建一个函数，返回下一个不同元素的索引。若原数组大小为0，则直接返回0，否则数组元素数目一定大于等于1，从第二个元素开始填即可,所以i初始化为1，index初始化为和下一个和nums[1]
不同的元素的索引。题解如下：*/

```cpp
class Solution {
public:
	int removeDuplicates(vector<int>& nums) {
		if (nums.size() == 0)
			return 0;
		int res = 1;
		int i = 1;
		int index = findDifferentIndex(nums,1);
		while (index<nums.size()) {
			res++;
			nums[i++] = nums[index];
			index = findDifferentIndex(nums, index + 1);
			
		}
		return res;
	}
private:
	int findDifferentIndex(vector<int>& nums, int p) {
		for (; p<nums.size(); p++)
		{
			if (nums[p] != nums[p - 1])
				break;
		}
		return p;
	}
};
```

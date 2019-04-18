int findPosition(vector<int> nums, int target)
{
	int len = nums.size();
	
	int left = 0;
	int mid;
	int right = len - 1;
	
	while(left <= right){
		mid = (right + left) / 2;

		if(nums[mid] == target)	return mid;

		if(nums[left] <= nums[mid]){
			if(nums[left] <= target && target < nums[mid])
				right = mid - 1;
			else
				left = mid + 1;
		}

		else{
			if(nums[left] > target && nums[mid] < target)
				left = mid + 1;
			else
				right = mid - 1;
		}
	}
	
	return -1;
}
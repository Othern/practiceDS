#include <vector>
using namespace std;

bool search(vector<int>& nums, int target) {
    int left = 0, right = nums.size() - 1;

    while (left <= right) {
        int mid = left + (right - left) / 2;

        if (nums[mid] == target) {
            return true;
        }

        // Handle duplicates: skip the duplicate elements
        while (left < mid && nums[left] == nums[mid] && nums[right] == nums[mid]) {
            left++;
            right--;
        }

        // Determine which side is sorted
        if (nums[left] <= nums[mid]) { // Left side is sorted
            if (nums[left] <= target && target < nums[mid]) {
                right = mid - 1; // Target is in the left sorted portion
            } else {
                left = mid + 1; // Target is in the right unsorted portion
            }
        } else { // Right side is sorted
            if (nums[mid] < target && target <= nums[right]) {
                left = mid + 1; // Target is in the right sorted portion
            } else {
                right = mid - 1; // Target is in the left unsorted portion
            }
        }
    }

    return false;
}

int main(){
    return;
}
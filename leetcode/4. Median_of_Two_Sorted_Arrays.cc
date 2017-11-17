// 4. Median of Two Sorted Arrays
// There are two sorted arrays nums1 and nums2 of size m and n respectively.

// Find the median of the two sorted arrays. The overall run time complexity should be O(log (m+n)).

// Example 1:
// nums1 = [1, 3]
// nums2 = [2]

// The median is 2.0
// Example 2:
// nums1 = [1, 2]
// nums2 = [3, 4]

// The median is (2 + 3)/2 = 2.5


// 求两个已排序数组的中位数，其实可以转换为，求两个数组的第k大的数
// 思路是这样以后，可以使用一个固定容量的最大堆，这种解法适用于未排序的，将输入的数据全部都扫描一遍。
// 同时之前的那些快排思路等并不是很适合在这里了.

// 但针对这个题，因为已经排序了，所以需要利用这个已排序的特点
// 分析一下,假设两个数组arr1,arr2,要求两个数组第k大的数

// 
#include <iostream>

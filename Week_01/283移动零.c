/*
注意：后续如此文一样只管理代码，运行端在 Leetcode
C的解法 C文件存储
其他语言同理

283 移动零
*/

/*
解法1 O(n)的时间复杂度 
1.首先要适应的是Google标准代码风格
2.该解法 遍历数组  当遇到数组成员为0时，m自增，当下一次非0则执行else if语句
功能是 交换 两成员的值；
3.这个解法 巧妙解决了 0 连续出现时的情况
4.但是欠缺了 边界考虑
*/
void moveZeroes(int* nums, int numsSize) {
    //(后续补充的边界考虑)
    if (nums == NULL || numsSize <= 0)
        return;
    

    int m = 0;
    for (int i = 0; i < numsSize; i++) {
        if (nums[i] == 0) {
            m++;
        }
        else if (m > 0) {
            nums[i - m] = nums[i];
            nums[i] = 0;
        }
    }
}

/*
解法2 O(n)的时间复杂度
1.边界考虑 很棒 但nums是指针，野指针判断少了
2.for循环  当成员非0 且 i != j 时，两成员交换，其他情况 j 自增

解题作者的思路：
1.定义两个变量用作数组下标，用其中一个去遍历整个数组，另外一个存储非 0 元素；
2.两个变量的值不相等的话，将用于遍历整个数组的变量作为下标的数组元素通过交换变为 0 。

*/

void moveZeroes(int* nums, int numsSize) {
    if (nums == NULL ||  numsSize <= 0) 
        return;
    

    for (int j = 0, i = 0; i < numsSize; i++) {
        if (nums[i] != 0) {
            if (i != j) {
                int temp = nums[i];
                nums[i] = nums[j];
                nums[j] = temp;
            }
            j++;
        }
    }
}

/*
解法3 O(n)的时间复杂度 双指针 ( 下标法 )
1.定义两个变量，其中一个变量遍历整个数组；
2.遇到非 0 元素，将其交换到左边；
3.遇到等于 0 的元素，交换到右边;
*/

void moveZeroes(int* nums, int numsSize) {
    if (nums == NULL || numsSize <= 0) {
        return;
    }

    int j = 0;
    for (int i = 0; i < numsSize; i++) {
        if (nums[i] != 0) {
            int tmp = nums[i];
            nums[i] = nums[j];
            nums[j++] = tmp;
        }
    }
}
// 解法3的优化版本：如果数组的第一个元素为非0的话，是不需要做一次交换处理，所以可以优化
void moveZeroes(int* nums, int numsSize) {
    if (numsSize <= 1) {
        return;
    }

    for (int j = 0, i = 0; i < numsSize; i++) {
        if (nums[i] != 0) {
            if (i != j) {
                int temp = nums[i];
                nums[i] = nums[j];
                nums[j] = temp;
            }
            j++;
        }
    }
}

/*
解法4 O(n)的时间复杂度
1.直接将非 0 元素保存在另一个数组中，下标小于数组尺寸的数组元素全部赋值为 0
*/


void moveZeroes(int* nums, int numsSize) {
    if (nums == NULL || numsSize <= 0) {
        return;
    }

    int j = 0;
    for (int i = 0; i < numsSize; ++i) {
        if (nums[i] != 0) {
            nums[j++] = nums[i];
        }
    }

    while (j < numsSize) {
        nums[j++] = 0;
    }
}
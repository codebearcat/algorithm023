/*
解法1 双指针法 配合 三目运算符 (容易理解版本)

1.没看到边界考虑
2.双指针 分为左右两个 i 左 j 右 (Array下标从0开始)


*/

int maxArea(int* height, int heightSize) {
    int i = 0;                  //左指针
    int j = heightSize - 1;     //右指针

    int Areamax = 0;            //最大面积

    while (i != j)              //
    {
        if (height[i] < height[j])//短板在左
        {
            Areamax = Areamax >= (j - i) * height[i] ? Areamax : (j - i) * height[i]; 
            // 更新最大面积
            i++;
        }
        else //短板在右
        {
            Areamax = Areamax >= (j - i) * height[j] ? Areamax : (j - i) * height[j];
            // 更新最大面积
            j--;
        }

    }
    return Areamax;
}

/*
解法2 双指针法 配合 三目运算符 (牛逼的写法)




*/
int maxArea(int* height, int heightSize) {
    int m = -1, * h = height, ht = heightSize;
    for (int i = 0, j = ht - 1, a = 0; i < j; m = m < a ? a : m, h[i] < h[j] ? i++ : j--)
        // m 如果小于 a 则 m = a；否则 m = h[i] < h[j] ? i++ : j--；这句代表  
        
        a = (h[i] < h[j] ? h[i] : h[j]) * (j - i);
    return m;
}
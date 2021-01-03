/*
ע�⣺���������һ��ֻ������룬���ж��� Leetcode
C�Ľⷨ C�ļ��洢
��������ͬ��

283 �ƶ���
*/

/*
�ⷨ1 O(n)��ʱ�临�Ӷ� 
1.����Ҫ��Ӧ����Google��׼������
2.�ýⷨ ��������  �����������ԱΪ0ʱ��m����������һ�η�0��ִ��else if���
������ ���� ����Ա��ֵ��
3.����ⷨ �������� 0 ��������ʱ�����
4.����Ƿȱ�� �߽翼��
*/
void moveZeroes(int* nums, int numsSize) {
    //(��������ı߽翼��)
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
�ⷨ2 O(n)��ʱ�临�Ӷ�
1.�߽翼�� �ܰ� ��nums��ָ�룬Ұָ���ж�����
2.forѭ��  ����Ա��0 �� i != j ʱ������Ա������������� j ����

�������ߵ�˼·��
1.���������������������±꣬������һ��ȥ�����������飬����һ���洢�� 0 Ԫ�أ�
2.����������ֵ����ȵĻ��������ڱ�����������ı�����Ϊ�±������Ԫ��ͨ��������Ϊ 0 ��

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
�ⷨ3 O(n)��ʱ�临�Ӷ� ˫ָ�� ( �±귨 )
1.������������������һ�����������������飻
2.������ 0 Ԫ�أ����佻������ߣ�
3.�������� 0 ��Ԫ�أ��������ұ�;
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
// �ⷨ3���Ż��汾���������ĵ�һ��Ԫ��Ϊ��0�Ļ����ǲ���Ҫ��һ�ν����������Կ����Ż�
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
�ⷨ4 O(n)��ʱ�临�Ӷ�
1.ֱ�ӽ��� 0 Ԫ�ر�������һ�������У��±�С������ߴ������Ԫ��ȫ����ֵΪ 0
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
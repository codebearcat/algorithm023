/*
�ⷨ1 ˫ָ�뷨 ��� ��Ŀ����� (�������汾)

1.û�����߽翼��
2.˫ָ�� ��Ϊ�������� i �� j �� (Array�±��0��ʼ)


*/

int maxArea(int* height, int heightSize) {
    int i = 0;                  //��ָ��
    int j = heightSize - 1;     //��ָ��

    int Areamax = 0;            //������

    while (i != j)              //
    {
        if (height[i] < height[j])//�̰�����
        {
            Areamax = Areamax >= (j - i) * height[i] ? Areamax : (j - i) * height[i]; 
            // ����������
            i++;
        }
        else //�̰�����
        {
            Areamax = Areamax >= (j - i) * height[j] ? Areamax : (j - i) * height[j];
            // ����������
            j--;
        }

    }
    return Areamax;
}

/*
�ⷨ2 ˫ָ�뷨 ��� ��Ŀ����� (ţ�Ƶ�д��)




*/
int maxArea(int* height, int heightSize) {
    int m = -1, * h = height, ht = heightSize;
    for (int i = 0, j = ht - 1, a = 0; i < j; m = m < a ? a : m, h[i] < h[j] ? i++ : j--)
        // m ���С�� a �� m = a������ m = h[i] < h[j] ? i++ : j--��������  
        
        a = (h[i] < h[j] ? h[i] : h[j]) * (j - i);
    return m;
}
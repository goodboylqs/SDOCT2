//------------------------����ͼ����ݶȾ��󣬲����ݾ�����Ȩ�ء�----------------------------
//���ܣ���ͼ�����ֱ�����ˮƽ������ݶȾ����ݶȼ���ֱ��������ֵ֮�
//ʱ�䣺2017.4.28  07��28
//˵����1)Ȩ�صļ��㷽��   Wab = 2 - Xab - Yab�����ز�Խ��Xab��Yab��Խ�󣬼��ϸ��ź��ԽС��
//		2��ʹ�þ���matlab���жԱȶȼ�ǿ���ͼƬ���м���
//		3)����type���д��������ʹӰ���������������ܱ�2�����ǵ�һ��
//		4)Ȩ�ؾ���ȡͼƬ�������귶Χ[500,700]�ڵ�ͼƬ���߶�Ϊ200�����ΪBMP_WIDTH
//״̬�����
//�޸ļ�¼��
//����޸�ʱ�䣺
#include"Bmp.h"
void Assign_Weight(IMAGEDATA **IMG_DATA,int **Weight,int type)
{
	for (int i = 0; i < 300; ++i)
	{
		for (int j = 0; j < BMP_WIDTH; ++j)
		{
			if (i - 1 >= 0)
			{
				if(type == 0)
					Weight[i][j] = IMG_DATA[i + (TOP_BORDER - 300)][j].blue - IMG_DATA[i + (TOP_BORDER - 300) - 1][j].blue;
				if(type == 1)
					Weight[i][j] = IMG_DATA[i + (TOP_BORDER - 300) - 1][j].blue - IMG_DATA[i + (TOP_BORDER - 300)][j].blue;
			}
		}
	}
}
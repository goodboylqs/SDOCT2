//------------------------����ֵ�˲�ȥ�롿----------------------------
//���ܣ���ͼƬ���о�ֵ�˲�ȥ�룬��ǿ�Աȶ�
//ʱ�䣺2017.4.28  07��28
//˵����
//״̬�����
//�޸ļ�¼��
//����޸�ʱ�䣺
#include"Bmp.h"

void LaborLowNoise(IMAGEDATA **IMG_DATA)
{
	int result,x,y,count;        //x,y��¼��ǰ��������ĵ����꣬result��¼�˲��������ֵ,count��¼��ǰ���������ص����
	
	for (int i = 0; i < BMP_WIDTH; i += 3)       //ͼƬ�Ĺ����512 * 1024�ģ����õĲ��ִ����������[500,700]��Χ��
	{
		for (int j = 0; j < BMP_HEIGHT; j += 3)
		{
			//ѡ3 * 19��������˲������ĵ�����(x,y)Ϊ(1,10)
			x = i + 10;
			y = j + 1;
			result = 0;
			count = 0;
			for (int a = -9; a <= 9; ++a)
			{
				for (int b = -1; b <= 1; ++b)
				{
					if (a + x >= 0 && a + x < BMP_WIDTH && b + y >= 0 && b + y < BMP_HEIGHT)
					{
						count++;
						result += IMG_DATA[b + y][a + x].blue;
					}
				}
			}
			result /= count;
			//��Ŀ����������ص���и�ֵ
			
			for (int a = -9; a <= 9; ++a)
			{
				for (int b = -1; b <= 1; ++b)
				{
					if (a + x >= 0 && a + x < BMP_WIDTH && b + y >= 0 && b + y < BMP_HEIGHT)
					{
						IMG_DATA[b + y][a + x].blue = result;
						IMG_DATA[b + y][a + x].green = result;
						IMG_DATA[b + y][a + x].red = result;
					}
				}
			}
			
		}
	}
}

//------------------------������Ȩ�ؾ�������СȨ�غ�·����----------------------------
//���ܣ�����СȨ�غ�·������ͼƬ�ϱ�ʾ
//ʱ�䣺2017.4.28  07��28
//˵����1���з����������Ե�ǰ��(i,j)Ϊ��㣬�����Ҳ�5 * 2������Ȩ����С�ĵ�
//		2��ѭ���������ҵ�һ��֮�󣬾Ͳ���������·����������Ѱ�����������ڵ�·��
//			2.1�������֮��Ҫ���¼���Ȩ��
//		3)ʹ�þ���matlab���жԱȶ���ǿ���ͼƬ��ʹ��֮ǰ�ȶ�ȡ��ͼƬ
//		4)����Ȩ�ص�ʱ��ֻ���������귶Χ[500,700]��Ȩ�أ����Ȩ������Ϊ200 * BMP_HEIGHT
//״̬�����
//�޸ļ�¼��
//����޸�ʱ�䣺
#include"Bmp.h"
void PathBeColor(IMAGEDATA **IMG_DATA,int **flag,int color);

void Find_Path(IMAGEDATA **IMG_DATA)
{
	//���裺��ʼ����㣬����Ȩ�أ�Ѱ��·������ɫ
	int **Weight = (int**)malloc(sizeof(int*) * 300);    //��¼Ȩ��
	int **flag = (int **)malloc(sizeof(int *) * 512);    //�����СȨ�غ�·������
	int **flag1 = (int **)malloc(sizeof(int *) * 512);
	for (int i = 0; i < 512; ++i)
	{
		flag[i] = (int*)malloc(sizeof(int) * 2);
		flag1[i] = (int*)malloc(sizeof(int) * 2);
	}

	for (int i = 0; i < 300; ++i) 
	{
		Weight[i] = (int*)malloc(sizeof(int) * BMP_WIDTH);
	}
	//���ݵõ���Ȩ�ؾ���Ѱ��·����ѭ��4������4��·����ÿ��ѡ��ͬ���������
	
	int min,cur_x,cur_y,next_x,next_y,count,count1;

	//����Ȩ��
	
	
	Assign_Weight(IMG_DATA, Weight,0);
	//��ʼ��flag����
	for (int i = 0; i < 512; ++i)
	{
		flag[i][0] = 0;
		flag[i][1] = 0;
	}
	cur_x = 0;
	cur_y = (TOP_BORDER - 300) + 105;
	count = 0;
	while (cur_x < BMP_WIDTH)
	{
		min = -1000;
		next_x = cur_x;
		next_y = cur_y;
		for (int i = cur_x + 1; i <= cur_x + 2; ++i)
		{
			for (int j = cur_y - 3; j <= cur_y + 7; ++j)
			{
				if (i >= 0 && i < BMP_WIDTH && j >= (TOP_BORDER - 300) && j < TOP_BORDER)
				{
					if (Weight[j - (TOP_BORDER - 300)][i] > min)
					{
						next_x = i;
						next_y = j;
						min = Weight[j - (TOP_BORDER - 300)][i];
					}
				}
			}
		}
		if (next_y >= TOP_BORDER)
			next_y = TOP_BORDER;
		if (next_y < TOP_BORDER - 300)
			next_y = TOP_BORDER - 300;
		cur_x = next_x;
		cur_y = next_y;
		flag[count][0] = cur_x;
		flag[count++][1] = cur_y;
		if (count >= 512)
			break;
	}

	PathBeColor(IMG_DATA, flag, 0);
	
	Assign_Weight(IMG_DATA, Weight,1);
	//��ʼ��flag����
	for (int i = 0; i < 512; ++i)
	{
		flag[i][0] = 0;
		flag[i][1] = 0;
		flag1[i][0] = 0;
		flag1[i][1] = 0;
	}
	cur_y = 200 + (TOP_BORDER - 300);
	cur_x = 0;
	count = 0;
	count1 = 0;
	//������������
	while (cur_x < BMP_WIDTH)
	{
		min = -1000;
		next_x = cur_x;
		next_y = cur_y;
		for (int i = cur_x + 1; i <= cur_x + 2; ++i)
		{
			for (int j = cur_y - 3; j <= cur_y + 3; ++j)
			{
				if (i >= 0 && i < BMP_WIDTH && j >= (TOP_BORDER - 300) && j < TOP_BORDER )
				{
					if (Weight[j - (TOP_BORDER - 300)][i] > min)
					{
						next_x = i;
						next_y = j;
						min = Weight[j - (TOP_BORDER - 300)][i];
					}
				}
			}
		}
		
		if (next_y >= TOP_BORDER)
			next_y = TOP_BORDER;
		if (next_y < TOP_BORDER - 300)
			next_y = TOP_BORDER - 300;
		cur_x = next_x;
		cur_y = next_y;

		flag[count][0] = cur_x;
		flag[count++][1] = cur_y;
		
		if (count >= 512)
			break;
	}

	cur_y = 235 + (TOP_BORDER - 300);
	cur_x = BMP_WIDTH - 1;
	count1 = 0;
	//������������
	while (cur_x < BMP_WIDTH)
	{
		min = -1000;
		next_x = cur_x;
		next_y = cur_y;
		for (int i = cur_x - 1; i >= cur_x - 2; --i)
		{
			for (int j = cur_y - 3; j <= cur_y + 13; ++j)
			{
				if (i >= 0 && i < BMP_WIDTH && j >= (TOP_BORDER - 300) && j < TOP_BORDER)
				{
					if (Weight[j - (TOP_BORDER - 300)][i] > min)
					{
						next_x = i;
						next_y = j;
						min = Weight[j - (TOP_BORDER - 300)][i];
					}
				}
			}
		}

		if (next_y >= TOP_BORDER)
			next_y = TOP_BORDER;
		if (next_y < (TOP_BORDER - 300))
			next_y = (TOP_BORDER - 300);
		cur_x = next_x;
		cur_y = next_y;

		flag1[count1][0] = cur_x;
		flag1[count1++][1] = cur_y;
		std::cout << flag1[count1 - 1][0] << "," << flag[count1 - 1][1] << " ";
		if (count1 >= 512)
			break;
	}
	//�Ƚ��������������ѡ����������к��ʵ�ֵ
//	for (int i = 0; i < count && i < count1; ++i)
//	{
//		if (flag1[i][1] - flag[i][1] > 8)
//			flag[i][1] = flag1[i][1];
//	}
	PathBeColor(IMG_DATA, flag1, 1);
	
	Assign_Weight(IMG_DATA, Weight, 0);
	//��ʼ��flag����
	for (int i = 0; i < 512; ++i)
	{
		flag[i][0] = 0;
		flag[i][1] = 0;
	}
	cur_y = (TOP_BORDER - 300) + 165;
	cur_x = 0;
	count = 0;
	while (cur_x < BMP_WIDTH)
	{
		min = -1000;
		next_x = cur_x;
		next_y = cur_y;
		for (int i = cur_x + 1; i <= cur_x + 4; ++i)
		{
			for (int j = cur_y - 5; j <= cur_y + 5; ++j)
			{
				if (i >= 0 && i < BMP_WIDTH && j >= (TOP_BORDER - 300) && j < TOP_BORDER)
				{
					if (Weight[j - (TOP_BORDER - 300)][i] > min)
					{
						next_x = i;
						next_y = j;
						min = Weight[j - (TOP_BORDER - 300)][i];
					}
				}
			}
		}
		if (next_y >= TOP_BORDER)
			next_y = TOP_BORDER;
		if (next_y < (TOP_BORDER - 300))
			next_y = (TOP_BORDER - 300);
		cur_x = next_x;
		cur_y = next_y;
		flag[count][0] = cur_x;
		flag[count++][1] = cur_y;
		if (count >= 512)
			break;
	}

	PathBeColor(IMG_DATA, flag, 2);

	
	//�ͷ�ͼƬ�����ڴ�
	for (int i = 0; i < 512; ++i)
	{
		free(flag[i]);
		free(flag1[i]);
	}
	for(int i = 0; i < 300; ++i) 
	{
		free(Weight[i]);
	}
	free(Weight);
	free(flag);
	free(flag1);
}
void PathBeColor(IMAGEDATA **IMG_DATA,int** flag,int color)
{  
	/*        �����Ƿ�����ɫ
	for (int i = 0; i < BMP_WIDTH; ++i)
	{
		for (int j = 0; j < BMP_HEIGHT; ++j)
		{
			if (j == 500)
			{
				IMG_DATA[j][i].blue = 255;
				IMG_DATA[j][i].green = 0;
				IMG_DATA[j][i].red = 0;
			}
		}
	}
	*/
	
	for (int i = 0; i < 512; ++i)
	{
		if (color == 0) 
		{
			IMG_DATA[flag[i][1]][flag[i][0]].blue = 255;
			IMG_DATA[flag[i][1]][flag[i][0]].green = 0;
			IMG_DATA[flag[i][1]][flag[i][0]].red = 0;
		}
		else if (color == 1)
		{
			IMG_DATA[flag[i][1]][flag[i][0]].blue = 0;
			IMG_DATA[flag[i][1]][flag[i][0]].green = 255;
			IMG_DATA[flag[i][1]][flag[i][0]].red = 0;
		}
		else if (color == 2)
		{
			IMG_DATA[flag[i][1]][flag[i][0]].blue = 0;
			IMG_DATA[flag[i][1]][flag[i][0]].green = 0;
			IMG_DATA[flag[i][1]][flag[i][0]].red = 255;
		}
	}
	
}


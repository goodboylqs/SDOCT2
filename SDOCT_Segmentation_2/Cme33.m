clear all;clc;close all;
ImgFile='D:\PROJECT\SDOCT_Segmentation_Code\SDOCT_Segmentation_2\AfterLabor.bmp';
ImgIn=imread(ImgFile);
ImgHistEq=histeq(ImgIn,256);
figure;subplot(121);imshow(uint8(ImgIn));title('ԭͼ');
subplot(122);imshow(ImgHistEq);title('ȫ�ֻҶ���ǿ - ֱ��ͼ����');
figure;subplot(121);imhist(ImgIn,256);
axis([0 255 0 1e5]);title('ԭͼ��ֱ��ͼ');
subplot(122);imhist(ImgHistEq,256);axis([0 255 0 1e5]);title('ֱ��ͼ���⻯���ֱ��ͼ');
% �Զ���ֱ��ͼ����
[counts,x]=imhist(ImgIn,256);
cum_counts=cumsum(counts);
cum_counts=uint8(cum_counts/max(cum_counts)*255);% ת������
figure;plot(x,cum_counts);axis([0 255 0 255]);
xlabel('ԭͼ�Ҷ�');ylabel('ת����Ҷ�');title('ԭͼCDFת���ĻҶ�ӳ�亯��');
ImgOut=nan(size(ImgIn));
for i=1:length(x)
    ImgOut(ImgIn==x(i))=cum_counts(i);
end
ImgOut=uint8(ImgOut);
figure;imshow(uint8(ImgOut));title('�Զ���ֱ��ͼ����')
figure;imhist(ImgOut,256);axis([0 255 0 1e5]);title('�Զ���ֱ��ͼ�����ֱ��ͼ')
n=input('please input n:');%����n�ȷ�
x0=linspace(-5,5,n+1);%������n+1������
for i=1:1000
    x(i)=-5+i*0.01;%ͨ���������ղ�ֵ����[-5,5]��������
    y(i)=piecewise_linear_interpolation(x0,1./(1+x0.^2),x(i),n);
end
plot(x,y);
n=input('please input n:');%输入n等分
x0=linspace(-5,5,n+1);%产生（n+1）个点
for i=1:1000
    x(i)=-5+i*0.01;%通过拉格朗日插值画出[-5,5]中其他点
    y(i)=piecewise_linear_interpolation(x0,1./(1+x0.^2),x(i),n);
end
plot(x,y);
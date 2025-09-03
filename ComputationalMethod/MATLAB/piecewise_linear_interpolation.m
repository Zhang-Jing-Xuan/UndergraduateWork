function [y]= piecewise_linear_interpolation(x0,y0,x,n)
%x0,y0为已知插值点，x是未知插值点
for i=1:length(x)%对于要画的每一个点（未知插值点）
    for j=1:n%对于每一段
        if(x>=x0(j))&&(x<=x0(j+1))%如果该点在这一段内
            %通过拉格朗日两点插值公式计算插值多项式在x处的值
            y=(x-x0(j+1))/(x0(j)-x0(j+1))*y0(j)+(x-x0(j))/(x0(j+1)-x0(j))*y0(j+1);
        end
    end
end


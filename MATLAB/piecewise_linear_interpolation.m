function [y]= piecewise_linear_interpolation(x0,y0,x,n)
%x0,y0Ϊ��֪��ֵ�㣬x��δ֪��ֵ��
for i=1:length(x)%����Ҫ����ÿһ���㣨δ֪��ֵ�㣩
    for j=1:n%����ÿһ��
        if(x>=x0(j))&&(x<=x0(j+1))%����õ�����һ����
            %ͨ���������������ֵ��ʽ�����ֵ����ʽ��x����ֵ
            y=(x-x0(j+1))/(x0(j)-x0(j+1))*y0(j)+(x-x0(j))/(x0(j+1)-x0(j))*y0(j+1);
        end
    end
end


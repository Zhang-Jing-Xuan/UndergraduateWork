function [x,k]=Fast_chord(x1,x2,eps)
    disp("ÕÅ¾°Ðù_3-3");
    k=1;
    y1=x1.*exp(x1)-1;
    y2=x2.*exp(x2)-1;
    x(k)=x2-(x2-x1)*y2/(y2-y1);
    y(k)=x(k)*exp(x(k))-1;
    k=k+1;
    x(k)=x(k-1)-(x(k-1)-x2)*y(k-1)/(y(k-1)-y2);
    while abs(x(k)-x(k-1))>eps
        y(k)=x(k)*exp(x(k))-1;
        x(k+1)=x(k)-(x(k)-x(k-1))*y(k)/(y(k)-y(k-1));
        k=k+1;
    end
end


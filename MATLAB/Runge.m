function Runge=Runge(n)
for i=1:1000
    x(i)=-5+i*0.01;
    y(i)=Lagrange(x(i),n);
end
plot(x,y)

function res=Lagrange(x,n)
h=10/n;
res=0;
k=1;
for i=1:(n+1)
    k=1;
    for j=1:(1+n)
       if i~=j
           k=k*(x-(-5+(j-1)*h))/((i-j)*h);
       end
    end
    res=res+k*1/(1+(-5+(i-1)*h)^2);
end
            
    



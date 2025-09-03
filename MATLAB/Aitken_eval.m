function y0=Aitken(X,Y,x0)
m=length(X);
P=zeros(m,1);
P1=zeros(m,1);
P=Y;
disp("ÕÅ¾°Ðù_3-2");
for i=1:m
    P1=P;
    %k=1;
    for j=i+1:m
        %k=k+1;
        %P(j)=P1(j-1)+(P1(j)-P1(j-1))*(x0-X(k-1))/(X(j)-X(k-1));
        P(j)=P1(i)+(P1(j)-P1(i))*(x0-X(i))/(X(j)-X(i));
    end
    if abs(P(m)-P(m-1))<10^-6
        y0=P(m);
        return ;
    end
end
y0=P(m);
 
 


 
 




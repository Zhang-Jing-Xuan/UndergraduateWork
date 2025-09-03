function E=MendEuler(f,a,b,N,ya)
disp("ÕÅ¾°Ðù_3-1");
h=(b-a)/N;
y=zeros(1,N+1);
x=zeros(1,N+1);
f=@(x,y)(2*x/(3*y.^2));
y(1)=ya;
x=a:h:b;
for i=1:N
    y1=y(i)+h*feval(f,x(i),y(i));
    y2=y(i)+h*feval(f,x(i+1),y1);
    y(i+1)=(y1+y2)/2;
end
E=[x',y'];
end



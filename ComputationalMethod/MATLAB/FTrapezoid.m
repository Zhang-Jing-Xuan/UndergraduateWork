function S=FTrapezoid(f,a,b,N)
h=(b-a)/N;
f=@(x)exp(-x)*2/sqrt(pi);
fa=feval(f,a);
S=fa;
x=a;
disp("ÕÅ¾°Ðù_3-1");
for i=1:N
      x=x+h;
      fx=feval(f,x);
      S=S+2*fx;
end
S=h*S/2;

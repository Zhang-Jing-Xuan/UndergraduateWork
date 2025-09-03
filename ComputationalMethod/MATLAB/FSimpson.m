function S=FSimpson(f,a,b,N)
h=(b-a)/N;
f=@(x)exp(-x)*2/sqrt(pi);
fa=feval(f,a);
fb=feval(f,b);
S=fa+fb;
x=a;
disp("ÕÅ¾°Ðù_3-1");
for i=1:N
    x=x+h/2;
    fx=feval(f,x);
    S=S+4*fx;
    x=x+h/2;
    fx=feval(f,x);
    S=S+2*fx;
end
S=h*S/6;


function x0=Aitken_Iteration(x)
disp("ÕÅ¾°Ðù_3-2");
x0=x;
a=3.021986709;
i=1;
while(abs(x0-a)>1e-5)
    x1=nthroot(3*x0+exp(x0)-2,3);
    x2=nthroot(3*x1+exp(x1)-2,3);
    x0=x2-(x2-x1)^2/(x2-2*x1+x0);
    m=[i,x1,x2,x0];
    disp(m);
    i=i+1;
end
end
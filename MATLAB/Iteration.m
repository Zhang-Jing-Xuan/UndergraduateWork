function x0=Iteration(x)
disp("ÕÅ¾°Ğù_3-2");
x0=x;
a=3.021986709;
i=1;
while(abs(x0-a)>1e-5)
    x0=nthroot(3*x0+exp(x0)-2,3);
    m=[i,x0];
    if i>60
        disp(m);
    end
    i=i+1;
end
end
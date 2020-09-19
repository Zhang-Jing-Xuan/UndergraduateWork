function x0=Newton(x)
disp("ÕÅ¾°Ğù_3-1");
x0=x;
a=1.87938524;
while(abs(x0-a)>1e-5)
    x0=x0-(x0*x0*x0-3*x0-1)/(3*x0*x0-3);
end
end
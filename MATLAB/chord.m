function x=chord(x0,eps)
    disp("ÕÅ¾°Ðù_3-3");
    y0=x0*exp(x0)-1;
    x1=0.6;
    y1=x1*exp(x1)-1;
    x=x1-y1*(x1-x0)/(y1-y0);
    i=1;
    m=[i,x,x1];
    disp(m);
    while abs(x-x1)>1e-6
        x1=x;
        y1=x1*exp(x1)-1;
        x=x1-y1*(x1-x0)/(y1-y0);
        i=i+1;
        m=[i,x,x1];
        disp(m);
    end
end

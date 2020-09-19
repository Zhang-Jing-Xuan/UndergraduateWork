%%
x1=-5:0.1:5;
y1=x1.^2;
plot(x1,y1);

hold on;

x2=-5:0.1:5;
y2=x2.^3;
plot(x2,y2);

grid on;
title('x^2 vs x^3');
xlabel('x-axis');
ylabel('y-axis');


%%
x=-4:0.1:4;
y1=sin(x);
y2=sin(2.*x);
y3=sin(3.*x);
y4=sin(4.*x);

subplot(2,2,1);
plot(x,y1);
title('y=sin(x)');
subplot(2,2,2);
plot(x,y2);
title('y=sin(2x)');
subplot(2,2,3);
plot(x,y3);
title('y=sin(3x)');
subplot(2,2,4);
plot(x,y4);
title('y=sin(4x)');
%%
x=-4:0.1:4;
y1=cos(x);
y2=cos(2.*x);
y3=cos(4.*x);
subplot(2,2,1);
plot(x,y1);
title('y=cos(x)');
subplot(2,2,2);
plot(x,y2);
title('y=cos(2x)');
subplot(2,2,[3,4]);
plot(x,y3);
title('y=cos(3x)');
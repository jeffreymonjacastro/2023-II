 syms t y

f = @(t,y)(y + 4*t);
y0 = -2;
y1 = -2.19;
h = 0.1;
a = 0;
b = 2;

[z] = AdamsBash(f,a,b,y0,y1,h);


y_aprox = z(end,2)

syms y(t) t

y(t) = dsolve( diff(y,t) == y + 4*t , y(0) == -2);

y = matlabFunction(y(t));

y_exac = y(2)

error = abs(y_exac - y_aprox)/abs(y_exac)



function [z] = AdamsBash(f,a,b,y0,y1,h)
    n = (b-a)/h;
    t = (a:h:b)';
    z = [t(1) y0];
    z = [z;t(2) y1];
    for i = 3:(n+1)
        yi = z(i-1,2) + (h/2)*( 3*f(t(i-1) , z(i-1,2))  - f(t(i-2) , z(i-2 , 2)) );
        z = [z;t(i) yi];
    end
end
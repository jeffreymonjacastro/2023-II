%Complete Aquí
Ta = 20;
syms k
syms T(t) t
T(t) = dsolve(diff(T,t) == k*(T-Ta) , T(0) ==800)

eq = T(t) == 500

kvalue = double(solve(subs(eq,t,30) , k))

syms t T
f = @(t,T)(kvalue*(T - Ta))

T0 = 800
a = 0
b = 4


[z] = RK2(f,a,b,T0,2)

TemValue1 = z(end,2)

[t,T] = ode45(f,[0 4],800);

TemValue2 = T(end)





function [z] = RK2(f,a,b,y0,h)
    n = (b-a)/h;
    t = (a:h:b)';
    z = [];
    for i = 1:(n+1)
        k1 = f(t(i),y0);
        k2 = f(t(i)+h,y0+k1*h);
        y1 = y0 + (k1/2 + k2/2)*h;
        z = [z;t(i) y0 k1 k2 y1];
        y0 = y1;    
    end
end
